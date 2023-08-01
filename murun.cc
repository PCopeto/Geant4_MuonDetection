#include "murun.hh"
#include "mudetector.hh"
#include "muconstruction.hh"
#include "G4SDManager.hh"

MyRunAction::MyRunAction()
{}

MyRunAction::~MyRunAction()
{}

void MyRunAction::BeginOfRunAction(const G4Run*)
{
    G4AnalysisManager *man = G4AnalysisManager::Instance();

    // MySensitiveDetector* mySensitiveDetector1 = new MySensitiveDetector("physScintillator1");
    // G4SDManager::GetSDMpointer()->AddNewDetector(mySensitiveDetector1);
    // MySensitiveDetector* mySensitiveDetector2 = new MySensitiveDetector("physScintillator2");
    // G4SDManager::GetSDMpointer()->AddNewDetector(mySensitiveDetector2);

    // G4SDManager* sdManager = G4SDManager::GetSDMpointer();
    // G4String sdName = "physScintillator1"; // The name of your sensitive detector
    // mySensitiveDetector = dynamic_cast<physScintillator1*>(sdManager->FindSensitiveDetector(sdName));

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
    // man->CreateNtupleDColumn("Energy Deposited");
    
    man->FinishNtuple(0);

    // // Get the sensitive detector manager
    // G4SDManager* sdManager = G4SDManager::GetSDMpointer();

    // // Create one instance of MySensitiveDetector for each scintillator
    // MySensitiveDetector* detector1 = new MySensitiveDetector("physScintillator1", man);
    // MySensitiveDetector* detector2 = new MySensitiveDetector("physScintillator2", man);

    // // Register the sensitive detectors with the SDManager
    // sdManager->AddNewDetector(detector1);
    // sdManager->AddNewDetector(detector2);


}

void MyRunAction::EndOfRunAction(const G4Run*)
{

    // MySensitiveDetector* mySensitiveDetector1 = new MySensitiveDetector("physScintillator1");
    // G4SDManager::GetSDMpointer()->AddNewDetector(mySensitiveDetector1);
    // MySensitiveDetector* mySensitiveDetector2 = new MySensitiveDetector("physScintillator2");
    // G4SDManager::GetSDMpointer()->AddNewDetector(mySensitiveDetector2);

    // G4cout << "teste" << G4endl;

    // G4double totalEnergy1 = mySensitiveDetector->getEnergy1();
    // G4double totalEnergy2 = mySensitiveDetector->getEnergy2();
   

    G4AnalysisManager *man = G4AnalysisManager::Instance();
    //G4double totalEnergyScint1 = mySensitiveDetector->getEnergy();
    // G4double edep = mySensitiveDetector1->energy1;
    // G4double totalEnergyScint1 = MySensitiveDetector::totalEnergyScint1;

    // man->CreateNtuple("Hits", "Energy Deposited");
    // man->CreateNtupleDColumn("Energy Deposited");
    // man->FinishNtuple(1);
    // man->FillNtupleDColumn(7, edep);
    // man->AddNtupleRow(0);


    // // Get the sensitive detector manager
    // G4SDManager* sdManager = G4SDManager::GetSDMpointer();

    // // // Get the sensitive detector for "physScintillator1"
    // // MySensitiveDetector* detector1 = dynamic_cast<MySensitiveDetector*>(sdManager->FindSensitiveDetector("physScintillator1"));

    // // // Get the sensitive detector for "physScintillator2"
    // // MySensitiveDetector* detector2 = dynamic_cast<MySensitiveDetector*>(sdManager->FindSensitiveDetector("physScintillator2"));

    // // Get the total energy deposited in each scintillator
    // G4double totalEnergyScint1 = detector1->totalEnergyScint1;
    // G4double totalEnergyScint2 = detector2->totalEnergyScint2;

    // // Output the values or store them in a tuple
    // G4cout << "Total Energy deposited in Scintillator 1: " << totalEnergyScint1 << G4endl;
    // G4cout << "Total Energy deposited in Scintillator 2: " << totalEnergyScint2 << G4endl;

    // // Store the values in the tuple
    // man->FillNtupleDColumn(5, totalEnergy1);
    // man->FillNtupleDColumn(6, totalEnergy2);
    // man->AddNtupleRow(0);




    man->Write();
    man->CloseFile();

}