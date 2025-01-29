#include <PrimaryPart.hh>

PrimaryPart::PrimaryPart(std::ofstream& ofsa,std::ofstream& ofsa2)
{
 char string[1000];
 std::ifstream init;
 G4double E0;
 init.open("./in/input.dat");
 init.getline(string,1000);
 init>>E0; this->SetE0(E0);
 init.getline(string,1000); init.getline(string,1000);
 init.close();

 Ggamma = new G4ParticleGun(1);
 Ggamma->SetParticleDefinition(G4Gamma::Definition());

 this->f_prim=&ofsa;
 (*f_prim) << std::setw(12) << "Hi from PrimaryPart!" << std::endl;
 this->f_prim2=&ofsa2;
}

PrimaryPart::~PrimaryPart() 
{
 (*f_prim) << std::setw(12) << "Bye from PrimaryPart!" << std::endl;
}

//генерация излучения
void PrimaryPart::GeneratePrimaries(G4Event* anEvent) 
{
 this->x_position=(G4UniformRand()-0.5)*0.1*cm;
 this->y_position=(G4UniformRand()-0.5)*0.1*cm;
 this->z_position=-5.5*mm;
 Ggamma->SetParticlePosition(G4ThreeVector(this->x_position, this->y_position, this->z_position));
 Ggamma->SetParticleEnergy(this->GetE0() * MeV);
// Ggamma->SetParticleMomentumDirection(G4RandomDirection());
 Ggamma->SetParticleMomentumDirection(G4ThreeVector(0.,0.,1.));
 Ggamma->GeneratePrimaryVertex(anEvent); 
}
