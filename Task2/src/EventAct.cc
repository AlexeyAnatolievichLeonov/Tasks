#include <EventAct.hh>

// Обработчик событий на уровне Event - от начала запуска частицы до ее поглощения

EventAct::EventAct(std::ofstream& ofsa, std::ofstream& ofsa2) 
{
 this->f_event=&ofsa;
 (*f_event) << "Hi from Event!" << std::endl;
 this->f_event2=&ofsa2;
 Esum=0.;
 flag_inside=0;
}
EventAct::~EventAct()
{
 (*f_event) << "Bye from Event!" << std::endl;
}

int SLcounter=0;

void EventAct::Coordinates(G4ThreeVector V1, G4ThreeVector V2)
{
 G4cout << "X1=" << V1[0] * mm << " Y1=" << V1[1] * mm << " Z1=" << V1[2] * mm << G4endl;
 G4cout << "X2=" << V2[0] * mm << " Y2=" << V2[1] * mm << " Z2=" << V2[2] * mm << G4endl;
}

void EventAct::StepLengthCounter(G4double count1) 
{
//описание функции приема значения из шага
 SLcounter ++;
 G4cout << "Step N= " << SLcounter << "\t, Length=" << count1 * mm << G4endl; //debug-инфо.
}
void EventAct::AddE(G4double edep)
{
 Esum+=edep;
}
void EventAct::setFlag()
{
 flag_inside=1;
}

void EventAct::BeginOfEventAction(const G4Event * EVE)
{
 this->EventID=EVE->GetEventID();
 G4cout << "BeginWorks\t" << EVE->GetEventID() << G4endl;
 SLcounter = 0; //обнуление счетчика каждый раз при запуске единичного события
}

void EventAct::EndOfEventAction(const G4Event *EVE)
{
 (*f_event) <<"Esum=" << std::setw(12) << Esum << std::endl;
 G4cout << "EndWorks\t" << EVE->GetEventID() << G4endl;
 if (flag_inside==1)
 {
  (*f_event2)<<std::setw(12)<<EVE->GetEventID()<<std::setw(12)<<Esum<<G4endl;
 }
 SLcounter=0;
 Esum=0.;
 flag_inside=0;
}
