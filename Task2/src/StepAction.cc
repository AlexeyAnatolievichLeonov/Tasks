#include <StepAction.hh>
#include <EventAct.hh>//подключаем библиотеку с используемым счетчиком
#include <RunAct.hh>
#include <PrimaryPart.hh>


// Обработчик событий на уровне Step - просчет отдельного шага/акта взаимодействия

void StepAct::UserSteppingAction(const G4Step* step) 
{
 G4StepPoint* point1 = step->GetPreStepPoint();
 G4StepPoint* point2 = step->GetPostStepPoint();
 G4ThreeVector vect1, vect2;
 G4double Ekin1, Ekin2;
 G4double cosTeta;
 
 Ekin1=point1->GetKineticEnergy();
 Ekin2=point2->GetKineticEnergy();

 G4double StepLength = step->GetStepLength(); //извлекаем инфу из шага
 G4double edep = step->GetTotalEnergyDeposit();

 if (strcmp("G4_SODIUM_IODIDE",step->GetPreStepPoint()->GetMaterial()->GetName())==0)
 {
  if (step->IsFirstStepInVolume()) {event->setFlag();}
//    (*f_step)<<step->GetTrack()->GetDynamicParticle()->GetDefinition()->GetParticleName()<<" "<<Ekin1 * MeV<<" "<<Ekin2 * MeV<<" "<< StepLength * mm <<G4endl;
  event->AddE(edep);
  event->StepLengthCounter(StepLength);     //передаем инфу в другой класс (на уровень выше)
//    event->Coordinates(point1->GetPosition(),point2->GetPosition());
 }
}

