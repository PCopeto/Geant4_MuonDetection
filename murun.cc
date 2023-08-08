#include "murun.hh"

MyRunAction::MyRunAction()
{}

MyRunAction::~MyRunAction()
{
    delete eventAction;
}

void MyRunAction::BeginOfRunAction(const G4Run*)
{
    G4AnalysisManager *man = G4AnalysisManager::Instance();


    man->OpenFile("output.root");

    man->SetVerboseLevel(1);
    man->SetNtupleMerging(1); 
    man->CreateNtuple("Hits", "Hits");
    // man->CreateNtupleIColumn("fEvent");
    // man->CreateNtupleDColumn("fX");
    // man->CreateNtupleDColumn("fY");
    // man->CreateNtupleDColumn("fZ");
    // man->CreateNtupleDColumn("energy_deposited_step");
    man->CreateNtupleDColumn("TotalEnergyDeposited1");
    man->CreateNtupleDColumn("TotalEnergyDeposited2");
    
    man->FinishNtuple(0);

}

void MyRunAction::EndOfRunAction(const G4Run*)
{
   
    G4AnalysisManager* man = G4AnalysisManager::Instance();

    man->Write();
    man->CloseFile();

}