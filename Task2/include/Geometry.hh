#ifndef CPROJECT_DETGEOMETRY_HH
#define CPROJECT_DETGEOMETRY_HH

#include <G4UserLimits.hh>
#include "G4SystemOfUnits.hh"
#include "G4SolidStore.hh"
#include "G4LogicalVolumeStore.hh"
#include "G4PhysicalVolumeStore.hh"
#include "G4NistManager.hh"
#include "G4PVPlacement.hh"
#include "G4PVParameterised.hh"
#include "G4Box.hh"
#include "G4Tubs.hh"
#include <G4RunManager.hh>
#include <G4GeometryManager.hh>
#include <G4UImanager.hh>
#include "G4VUserDetectorConstruction.hh"
//#include <G4Color.hh>
#include "G4VisAttributes.hh"
//#include <G4AssemblyVolume.hh>
#include "G4Cache.hh"
#include "G4AutoDelete.hh"

#include "G4UniformElectricField.hh"
#include "G4UniformMagField.hh"
#include "G4MagneticField.hh"
#include "G4FieldManager.hh"
#include "G4TransportationManager.hh"
#include "G4EquationOfMotion.hh"
#include "G4EqMagElectricField.hh"
#include "G4Mag_UsualEqRhs.hh"
#include "G4MagIntegratorStepper.hh"
#include "G4MagIntegratorDriver.hh"
#include "G4ChordFinder.hh"

#include "G4ClassicalRK4.hh"

#define SU *mm

class G4VPhysicalVolume;
class G4LogicalVolume;

//class GeomMes;

class Geometry  : public G4VUserDetectorConstruction
{
public:

    G4NistManager*              nist;
	virtual G4VPhysicalVolume *Construct();
    G4Material*                 world_mat;
    G4double                    world_size;
    G4Box*                      world_box;
    G4LogicalVolume*            world_log;    
    G4VPhysicalVolume*          world_pvpl;
	
    G4Box*			Al_box;
    G4LogicalVolume*            Al_log;
    G4VPhysicalVolume*          Al_pvpl;
    G4ThreeVector		Al_vect;
    
    G4VSolid*			Scin_cylinder;
    G4LogicalVolume*            Scin_log;
    G4VPhysicalVolume*          Scin_pvpl;
    G4ThreeVector		Scin_vect;
    
    G4Material* Al_mat;
    G4Material* Scin_mat;

    G4UserLimits* fStepLimit;

    std::ofstream *f_geom;
    Geometry(std::ofstream&);
    virtual ~Geometry();

};

#endif //CPROJECT_DETGEOMETRY_HH
