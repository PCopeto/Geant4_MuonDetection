#include "muevent.hh"

MyEventAction::MyEventAction()
{}

MyEventAction::~MyEventAction()
{}

void MyEventAction::BeginOfEventAction(const G4Event*)
{}

void MyEventAction::EndOfEventAction(const G4Event*)
{

    G4AnalysisManager* man = G4AnalysisManager::Instance();

    // Get the MySensitiveDetector instance
    G4SDManager* sdManager = G4SDManager::GetSDMpointer();
    MySensitiveDetector* mySensitiveDetector = dynamic_cast<MySensitiveDetector*>(sdManager->FindSensitiveDetector("SensitiveDetector"));

    if (mySensitiveDetector) {
        G4double totalEnergyScint1 = mySensitiveDetector->getEnergy1();
        G4double totalEnergyScint2 = mySensitiveDetector->getEnergy2();

        G4cout << "Final Energy Deposited 1: " << totalEnergyScint1 << G4endl;
        G4cout << "Final Energy Deposited 2: " << totalEnergyScint2 << G4endl;

        man->FillNtupleDColumn(0, totalEnergyScint1);
        man->FillNtupleDColumn(1, totalEnergyScint2);
        man->AddNtupleRow(0);

        mySensitiveDetector->ResetEnergy();
    }
}
