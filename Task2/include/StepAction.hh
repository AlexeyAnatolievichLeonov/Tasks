//#ifndef M_DGW_4_STEPACTION_HH
//#define M_DGW_4_STEPACTION_HH

#include <G4UserSteppingAction.hh>
#include <G4Step.hh>

class PrimaryPart;
class EventAct;
class RunAct;

class StepAct :public G4UserSteppingAction {
public:
        std::ofstream *f_step, *f_step2;
        G4ThreeVector v1, v2;

        StepAct(std::ofstream& ofsa, std::ofstream& ofsa2, EventAct* eventAct, PrimaryPart* primaryPart, RunAct* runAct):event(eventAct),pp(primaryPart),run(runAct)
        {
         this->f_step=&ofsa;
         this->f_step2=&ofsa2;
         (*f_step) << "Hi from Step!" << std::endl;
        };
        ~StepAct()
        {
         (*f_step) << "Bye from Step!" << std::endl;
        };	

	void UserSteppingAction(const G4Step*);
private:
        EventAct* event;
        PrimaryPart* pp;
        RunAct* run;
};

//#endif
