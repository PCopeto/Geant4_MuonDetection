#include "mudetector.hh"

#include "murun.hh"



MySensitiveDetector::MySensitiveDetector(G4String name) : G4VSensitiveDetector(name), totalEnergyScint1(0.0), totalEnergyScint2(0.0)
{}

MySensitiveDetector::~MySensitiveDetector()
{
    // UpdateTotalEnergyScint1(totalEnergyScint1);
    // UpdateTotalEnergyScint2(totalEnergyScint2);
}

// void MySensitiveDetector::UpdateTotalEnergyScint1(G4double energy1)
// {
//     totalEnergyScint1 = energy1;
//     G4cout << "dsccs "<< totalEnergyScint1  << G4endl;
// }

// void MySensitiveDetector::UpdateTotalEnergyScint2(G4double energy2)
// {
//     totalEnergyScint2 = energy2;
// }


// // Definition of SetTotalEnergyScint1 function
// void MySensitiveDetector::SetTotalEnergyScint1(G4double totalEnergyScint1) {
//     this->totalEnergyScint1 = totalEnergyScint1;
// }

G4bool MySensitiveDetector::ProcessHits(G4Step *aStep, G4TouchableHistory *ROhist)
{


    // UpdateTotalEnergyScint1(totalEnergyScint1);
    // UpdateTotalEnergyScint2(totalEnergyScint2);


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
        // energy1 = energy;
        totalEnergyScint1 += energy;
        // energy1 = totalEnergyScint1;
        
        G4cout<<"totenergy1: " <<  MySensitiveDetector::getEnergy1() << G4endl;
        G4cout << "totenergy2: " << MySensitiveDetector::getEnergy2() << G4endl;


    } 
    else if (volName == "physScintillator2") {
        // energy2 = energy;
       totalEnergyScint2 += energy;
    //    energy2 = totalEnergyScint2;
       G4cout<<"totenergy2: " <<  MySensitiveDetector::getEnergy2() << G4endl;
       G4cout << "totenergy1: " << MySensitiveDetector::getEnergy1() << G4endl;


    }


    // G4double edep1 = mySensitiveDetector1->energy1;
    // G4double edep2 = mySensitiveDetector2->energy2;

    //G4cout<<"totenergy1: " <<  totalEnergyScint1 << G4endl;
    //G4cout<<"totenergy2: " <<  totalEnergyScint2 << G4endl;

//void MySensitiveDetector::SetTotalEnergyScint1(G4double energy) {
//    totalEnergyScint1 += energy;
//}


    // MySensitiveDetector::setEnergy(totalEnergyScint1);
    // G4cout<<"totenergy1: " <<  edep1 << G4endl;
    // G4cout<<"totenergy2: " <<  edep2 << G4endl;
    // G4cout<<"totenergy1_setter: " <<  MySensitiveDetector::getEnergy1() << G4endl;
    // G4cout<<"totenergy2_setter: " <<  MySensitiveDetector::getEnergy2() << G4endl;

    // UpdateTotalEnergyScint1(totalEnergyScint1);
    // UpdateTotalEnergyScint2(totalEnergyScint2);


    // G4cout << "Step Lenght: " << aStep->GetTrack()->GetStepLength() << G4endl;

    // this->SetTotalEnergyScint1(totalEnergyScint1);

    
    
    G4AnalysisManager *man = G4AnalysisManager::Instance();

    man->FillNtupleIColumn(0, evt);
    man->FillNtupleDColumn(1, posDetector[0]);
    man->FillNtupleDColumn(2, posDetector[1]);
    man->FillNtupleDColumn(3, posDetector[2]);
    man->FillNtupleDColumn(4, energy);
    // man->FillNtupleDColumn(5, totalEnergyScint1);
    // man->FillNtupleDColumn(6, totalEnergyScint2);
    // man->AddNtupleRow(0);


    return true;

}


