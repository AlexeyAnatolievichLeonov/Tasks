//#pragma once

#include <G4SystemOfUnits.hh>
#include <G4UserEventAction.hh>
#include <G4Event.hh>
#include <fstream>

class EventAct : public G4UserEventAction 
{
 public:
        std::ofstream *f_event, *f_event2;

	EventAct(std::ofstream&, std::ofstream&);
	~EventAct();

        void Coordinates(G4ThreeVector V1, G4ThreeVector V2);
        void AddE(G4double dE);
        void StepLengthCounter(G4double SL); //функция приема значений (из шагов)
        void setFlag();

	void BeginOfEventAction(const G4Event*);
	void EndOfEventAction(const G4Event*);
        G4int EventID, flag_inside;
        G4double Esum;
};
