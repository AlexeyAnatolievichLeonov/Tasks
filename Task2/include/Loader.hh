#ifndef FINAL_LOADER_HH
#define FINAL_LOADER_HH

#include "G4GlobalConfig.hh"	
#include <G4StepLimiter.hh>
#include <G4UserLimits.hh>
#include "G4UImanager.hh"
#include <G4VisManager.hh>
#include "G4RunManager.hh"

#include "G4UImanager.hh"
#include "QBBC.hh"
#include "G4StepLimiterPhysics.hh"

#include <iostream>
#include <iomanip>
#include <stdio.h>

#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"

class Loader{
private:
  std::ofstream *ofs_sn, *ofs_sn2;

    G4RunManager* runManager;
    G4VisManager* visManager;

public:
    Loader(int argc, char** argv, std::ofstream&, std::ofstream&);
    ~Loader();
};

#endif //FINAL_LOADER_HH
