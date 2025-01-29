#include <RunAct.hh>

// Обработчик событий на уровне Run - Сумма событий-Event, общая статистика

RunAct::RunAct(std::ofstream& ofsa, std::ofstream& ofsa2) 
{
 char string[1000];
 std::ifstream init;
 init.open("./in/input.dat");
 init.getline(string,1000);
 init>>this->E0;
 init.getline(string,1000); init.getline(string,1000);
 init>>this->Nbins;
 init.getline(string,1000);
 init.close();

 this->f_act=&ofsa;
 (*f_act) << std::setw(12) << "Hi from RunAct!" << G4endl; 
 G4int i;
 for (i=0;i<=Nbins;i++)
 {
  this->bins[i]=i*this->E0/this->Nbins;
//  (*f_act)<<bins[i]<<G4endl;
 }

 this->f_act2=&ofsa2;
}

RunAct::~RunAct()
{
 (*f_act) << std::setw(12) << "Bye from RunAct!" << std::endl;  
}

time_t Start, End;
int RunNum = 0;

void RunAct::BeginOfRunAction(const G4Run* aRun) 
{
 G4cout << "\n---Start------ Run # "<<RunNum<<" --------\n" <<"RunId="<<aRun->GetRunID()<< G4endl;
 time(&Start);
}

void RunAct::EndOfRunAction(const G4Run* aRun) 
{
 char string[1000];
 G4double Energy;
 G4int inum=0, counter=0, i=0;

 std::ifstream hist;
 hist.open("./info2.txt"); 
 while (!(hist.eof()))
 {
  hist>>inum;
  if (!(hist.eof()))
  {
   hist>>Energy;
   hist.getline(string,1000);
   for (i=0; i<this->Nbins; i++)
   {
    if ((i<Nbins-1)&(Energy>=this->bins[i])&(Energy<this->bins[i+1]))
    {
     this->counts[i]+=1;
    }
    if ((i==Nbins-1)&(Energy>=this->bins[i])&(Energy<=this->bins[i+1]))
    {
     this->counts[i]+=1;
    }
   }
   counter+=1;
  }
 }
 hist.close();
 (*f_act2)<<"counter="<<counter<<" "<<this->Nbins<<G4endl;
 for (i=0; i<this->Nbins; i++)
 {
  (*f_act2)<<" "<<0.5*(bins[i]+bins[i+1])<<" "<<counts[i]<<G4endl;
 }

 time(&End);
 G4cout << " Time spent on this Run = " << difftime(End, Start)<<" seconds"<< G4endl;
 G4cout << "\n---Stop------ Run # "<<RunNum<<" --------\n" <<"RunId="<<aRun->GetRunID()<< G4endl;
 RunNum++;
}
