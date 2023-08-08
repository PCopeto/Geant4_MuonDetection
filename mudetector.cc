#include "mudetector.hh"




MySensitiveDetector::MySensitiveDetector(G4String name) : G4VSensitiveDetector(name), totalEnergyScint1(0.0), totalEnergyScint2(0.0)
{}

MySensitiveDetector::~MySensitiveDetector()
{}



G4bool MySensitiveDetector::ProcessHits(G4Step *aStep, G4TouchableHistory *ROhist)
{


    G4Track *track = aStep->GetTrack();

    //track->SetTrackStatus(fStopAndKill);

    G4StepPoint *preStepPoint = aStep->GetPreStepPoint();
    G4StepPoint *postStepPoint = aStep->GetPostStepPoint();

    G4ThreeVector posPhoton = preStepPoint->GetPosition();

    //G4cout << "Photon position: " << posPhoton << G4endl;

    const G4VTouchable *touchable = aStep->GetPreStepPoint()->GetTouchable();

    G4int copyNo = touchable->GetCopyNumber();

    //G4cout << "Copy number: " << copyNo << G4endl;


    G4VPhysicalVolume *physVol = touchable->GetVolume();
    G4String volName = aStep->GetTrack()->GetTouchable()->GetVolume()->GetName();
    G4ThreeVector posDetector = physVol->GetTranslation();

    G4int evt = G4RunManager::GetRunManager()->GetCurrentEvent()->GetEventID();

    G4String particleName = track->GetParticleDefinition()->GetParticleName();
    G4double energy = aStep->GetTotalEnergyDeposit();


 
    G4cout << "Particle Name: " << particleName << G4endl;
    G4cout << "Volume name: " << volName << G4endl;
    G4cout << "Energy deposited: " << energy << G4endl;
    G4cout << "" << G4endl;




    if (volName == "physScintillator1") {
        totalEnergyScint1 += energy;
        G4cout<<"totenergy1: " <<  MySensitiveDetector::getEnergy1() << G4endl;
        G4cout << "totenergy2: " << MySensitiveDetector::getEnergy2() << G4endl;

    } 
    else if (volName == "physScintillator2") {
       totalEnergyScint2 += energy;
       G4cout<<"totenergy2: " <<  MySensitiveDetector::getEnergy2() << G4endl;
       G4cout << "totenergy1: " << MySensitiveDetector::getEnergy1() << G4endl;

    }
    
    
    // G4AnalysisManager *man = G4AnalysisManager::Instance();

    // man->FillNtupleIColumn(0, evt);
    // man->FillNtupleDColumn(1, posDetector[0]);
    // man->FillNtupleDColumn(2, posDetector[1]);
    // man->FillNtupleDColumn(3, posDetector[2]);
    // man->FillNtupleDColumn(4, energy);
    // man->FillNtupleDColumn(5, totalEnergyScint1);
    // man->FillNtupleDColumn(6, totalEnergyScint2);
    // man->AddNtupleRow(0);


    return true;

}


