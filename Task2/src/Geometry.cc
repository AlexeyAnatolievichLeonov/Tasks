#include "Geometry.hh"

using namespace std;

//#define SU *mm

Geometry::Geometry(std::ofstream& ofsa)
{
 this->f_geom=&ofsa;
 (*f_geom) << "Hi from Geom!" << std::endl;
    //detMes = new GeomMes(this);
}

Geometry::~Geometry()
{(*f_geom) << "Bye from Geom!" << std::endl;}

G4VPhysicalVolume* Geometry::Construct()
{
        G4int ncomponents;
        G4double fraction;
	G4GeometryManager::GetInstance()->OpenGeometry();
	G4PhysicalVolumeStore::GetInstance()->Clean(); 
	G4LogicalVolumeStore::GetInstance()->Clean();
	G4SolidStore::GetInstance()->Clean();

	// Параметры мира
	world_size = 1 * m;
	nist = G4NistManager::Instance();
//	world_mat = nist->FindOrBuildMaterial("G4_AIR");
	world_mat = nist->FindOrBuildMaterial("G4_Galactic");
	world_box = new G4Box("world_box", world_size, world_size, world_size);
	world_log = new G4LogicalVolume(world_box, world_mat, "world_log");
	world_pvpl = new G4PVPlacement(0, G4ThreeVector(0,0,0), world_log, "world_pvpl", 0, false, 0);

        Al_mat=nist->FindOrBuildMaterial("G4_Al");
        Scin_mat=nist->FindOrBuildMaterial("G4_SODIUM_IODIDE");
        
        G4Element* H = nist->FindOrBuildElement(1);
        G4Element* C = nist->FindOrBuildElement(6);
        G4Material* det_mat = new G4Material("Stilben", 0.97*g/cm3,2);
        det_mat->AddElement(H, 12);
        det_mat->AddElement(C, 14);
        
	Al_box = new G4Box("Al_plate", 1.5 * cm, 1.5 * cm, 0.5 * mm);
	Al_log = new G4LogicalVolume(Al_box, Al_mat,"Al_plate_log");
	Al_vect = G4ThreeVector(0, 0, 0);
	G4RotationMatrix* ZERO_RM = new G4RotationMatrix(0, 0, 0);
	Al_pvpl = new G4PVPlacement(ZERO_RM, Al_vect, Al_log, "Al_plate_pvpl", world_log, 0, false, 0);
	
	Scin_cylinder = new G4Tubs("Scin_vol", 0. * cm, 1.5 * cm, 2. * cm, 0.*deg, 360.*deg);
	Scin_log = new G4LogicalVolume(Scin_cylinder, Scin_mat,"Scin_vol_log");	
	Scin_vect = G4ThreeVector(0, 0, 25.5*mm);
//	G4RotationMatrix* RM = new G4RotationMatrix;
//        RM->rotateX(90.*deg);
	Scin_pvpl = new G4PVPlacement(ZERO_RM, Scin_vect, Scin_log, "Scin_vol_pvpl", world_log, 0, false, 0);
	
        G4double maxStep  = 10.*mm;
        G4double maxTrack = 10.*m;
        G4double maxTime  = 1.*s;
        G4double minE     = 0.000001 * MeV;
        G4double minRange = 0.0001 * mm;

        fStepLimit = new G4UserLimits(maxStep,maxTrack,maxTime,minE,minRange);
        Al_log->SetUserLimits(fStepLimit);
        Scin_log->SetUserLimits(fStepLimit);

        G4VisAttributes* CWhite  = new G4VisAttributes(G4Colour(1.0, 1.0, 1.0));
        G4VisAttributes* CGreen  = new G4VisAttributes(G4Colour(0.0, 1.0, 0.0));
        G4VisAttributes* CMagenta= new G4VisAttributes(G4Colour(1.0, 0.0, 1.0));
        Al_log->SetVisAttributes(CGreen);
        Scin_log->SetVisAttributes(CWhite);

    return new G4PVPlacement(0, G4ThreeVector(), world_log, "world_pvpl", 0, false, 0);
}
