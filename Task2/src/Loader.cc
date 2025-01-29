 #include <Loader.hh>
#include <Geometry.hh>
#include <Action.hh>
#include <G4Types.hh>
#include <globals.hh>

Loader::Loader(int argc, char **argv, std::ofstream& ofsa, std::ofstream& ofsa2) 
{
 this->ofs_sn=&ofsa;
 (*ofs_sn) << std::setw(12) << "Hi from Loader!" << std::endl;
 this->ofs_sn2=&ofsa2;

 CLHEP::HepRandom::setTheEngine(new CLHEP::RanecuEngine);
 CLHEP::HepRandom::setTheSeed(time(NULL));
 
 runManager = new G4RunManager;
 runManager->SetUserInitialization(new Geometry(*this->ofs_sn));

 G4VModularPhysicsList* physicsList = new QBBC;
 physicsList->RegisterPhysics(new G4StepLimiterPhysics());
 runManager->SetUserInitialization(physicsList);
 runManager->SetUserInitialization(new Action(*this->ofs_sn,*this->ofs_sn2));
 runManager->Initialize();
// Initialize visualization
 G4VisManager* visManager = new G4VisExecutive;
 visManager->Initialize();

 G4UImanager *UImanager = G4UImanager::GetUIpointer();

 if (argc != 1) 
 {
// batch mode
  G4String command = "/control/execute ";
  G4String fileName = argv[1];
  UImanager->ApplyCommand(command + fileName);
 }
 else
 {
  G4UIExecutive *ui = new G4UIExecutive(argc, argv, "qt"); //Here we can redefine win32/qt interface
  UImanager->ApplyCommand("/control/execute vis.mac");
  ui->SessionStart();//and this two
  delete ui;
  }
 }

 Loader::~Loader()
 {
  delete runManager;
  delete visManager;
  (*ofs_sn) << std::setw(12) << "Bye from Loader!" << std::endl; 
 }
