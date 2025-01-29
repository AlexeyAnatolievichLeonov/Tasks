#include <Action.hh>

Action::Action(std::ofstream& ofsa, std::ofstream& ofsa2) 
{
 this->f_act=&ofsa;
 this->f_act2=&ofsa2;
 (*f_act) << std::setw(12) << "Hi from Action!" << std::endl;	// debug info
}

Action::~Action() 
{
 (*f_act) << std::setw(12) << "Bye from Action!" << std::endl;	// debug info
}

//	подключение файлов, начало их выполнения
void Action::Build()const 
{
 RunAct* runAct = new RunAct(*this->f_act,*this->f_act2);
 SetUserAction(runAct);
 PrimaryPart* primaryPart  = new PrimaryPart(*this->f_act,*this->f_act2);
 SetUserAction(primaryPart);
 EventAct* eventAct = new EventAct(*this->f_act,*this->f_act2);
 SetUserAction(eventAct);
 SetUserAction(new StepAct(*this->f_act,*this->f_act2,eventAct,primaryPart,runAct));
}
