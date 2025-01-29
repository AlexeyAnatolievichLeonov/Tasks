#ifndef FINAL_PRIMARYPART_HH
#define FINAL_PRIMARYPART_HH

#include <G4VUserPrimaryGeneratorAction.hh>
#include <G4ParticleGun.hh>
#include <G4ParticleTable.hh>
#include <G4Gamma.hh>
#include <G4Proton.hh>
#include <G4Neutron.hh>
#include <G4Alpha.hh>
#include <G4SystemOfUnits.hh>
#include <G4RandomDirection.hh>
#include "Randomize.hh"

#include <fstream>

class PrimaryPart: public G4VUserPrimaryGeneratorAction{
private:
 G4ParticleGun* GProton;
 G4ParticleGun* GNeutron;
 G4ParticleGun* Ggamma;

 G4double E0;
 void SetE0(G4double En){E0=En;}
 G4double GetE0() const {return E0;}
 
 G4double x_position;
 G4double y_position;
 G4double z_position;

public:
 PrimaryPart(std::ofstream&,std::ofstream&);
~PrimaryPart();

 std::ofstream *f_prim, *f_prim2;

 virtual void GeneratePrimaries(G4Event* anEvent);

 G4ParticleGun* GetParticleGun() {return Ggamma;} 
 
 G4double getX() const {return x_position;}
 G4double getY() const {return y_position;}
 G4double getZ() const {return z_position;}
};

#endif //FINAL_PRIMARYPART_HH
