#ifndef FINAL_ACTION_HH
#define FINAL_ACTION_HH

#include <G4VUserActionInitialization.hh>
#include <fstream>
#include <StepAction.hh>
#include <PrimaryPart.hh>
#include <EventAct.hh>
#include <RunAct.hh>
#include <iomanip>

class Action: public G4VUserActionInitialization
{
 public:
  std::ofstream *f_act, *f_act2;
 public:Action(std::ofstream&,std::ofstream&);
~Action();
 virtual void Build() const;
};
#endif
