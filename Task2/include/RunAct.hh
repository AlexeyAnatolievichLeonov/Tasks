//#pragma once

#include <G4UserRunAction.hh>
#include <fstream>
#include <G4Run.hh>
#include "globals.hh"
#include <ctime>

class RunAct : public G4UserRunAction {
public:
	RunAct(std::ofstream& ofsa,std::ofstream& ofsa2);
	~RunAct();
	std::ofstream *f_act, *f_act2;
        G4double bins[1001];
        G4int Nbins;
        G4double E0;
        G4double counts[1000];
	
	void BeginOfRunAction(const G4Run*);
	void EndOfRunAction(const G4Run*);
};
