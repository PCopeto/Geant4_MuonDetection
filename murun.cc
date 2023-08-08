#include "murun.hh"

MyRunAction::MyRunAction()
{}

MyRunAction::~MyRunAction()
{}

void MyRunAction::BeginOfRunAction(const G4Run*)
{
    G4AnalysisManager *man = G4AnalysisManager::Instance();


    man->OpenFile("output.root");

    man->SetVerboseLevel(1);
    man->SetNtupleMerging(1); 
    man->CreateNtuple("Hits", "Hits");
    man->CreateNtupleIColumn("fEvent");
    man->CreateNtupleDColumn("fX");
    man->CreateNtupleDColumn("fY");
    man->CreateNtupleDColumn("fZ");
    man->CreateNtupleDColumn("energy_deposited_step");
    man->CreateNtupleDColumn("TotalEnergyDeposited1");
    man->CreateNtupleDColumn("TotalEnergyDeposited2");
    
    man->FinishNtuple(0);


}

void MyRunAction::EndOfRunAction(const G4Run*)
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

        man->FillNtupleDColumn(5, totalEnergyScint1);
        man->FillNtupleDColumn(6, totalEnergyScint2);
        man->AddNtupleRow(0);

        mySensitiveDetector->ResetEnergy();
    }



    man->Write();
    man->CloseFile();

}