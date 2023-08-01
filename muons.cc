#include <iostream>

#include "G4RunManager.hh"
#include "G4MTRunManager.hh"
#include "G4UImanager.hh"
#include "G4VisManager.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"
#include "QGSP_BERT.hh"

#include "muconstruction.hh"
#include "muphysics.hh"
#include "muaction.hh"
#include "G4SDManager.hh"

#include "mudetector.hh"

#include <iomanip>

int main(int argc, char** argv)
{

  // MySensitiveDetector detector("physScintillator1");
  MySensitiveDetector* mySensitiveDetector1 = new MySensitiveDetector("physScintillator1");
  G4SDManager::GetSDMpointer()->AddNewDetector(mySensitiveDetector1);
  MySensitiveDetector* mySensitiveDetector2 = new MySensitiveDetector("physScintillator2");
  G4SDManager::GetSDMpointer()->AddNewDetector(mySensitiveDetector2);

  G4RunManager *runManager = new G4RunManager();

  runManager->SetUserInitialization(new MyDetectorConstruction());
  runManager->SetUserInitialization(new MyPhysicsList());
  runManager->SetUserInitialization(new MyActionInitialization());


  runManager->Initialize();

  G4UIExecutive *ui = new G4UIExecutive(argc, argv);

  G4VisManager *visManager = new G4VisExecutive();
  visManager->Initialize();

  G4UImanager *UImanager = G4UImanager::GetUIpointer();

  UImanager->ApplyCommand("/vis/open OGL");
  UImanager->ApplyCommand("/vis/viewer/set/viewpointVector 1 1 1");
  UImanager->ApplyCommand("/vis/drawVolume");
  UImanager->ApplyCommand("/vis/viewer/set/autoRefresh true");
  UImanager->ApplyCommand("/vis/scene/add/trajectories smooth");
  UImanager->ApplyCommand("/vis/scene/endOfEventAction accumulate -1");


  ui->SessionStart();



  // G4double teste = 5.0;
  
  // std::cout<< teste <<std::endl;
  // std::cout<< teste <<std::endl;


  //G4double totalEnergyScint1 = mySensitiveDetector1->UpdateTotalEnergyScint1(G4double energy1);
  // G4double teste1 = mySensitiveDetector1->teste;
  //G4double totalEnergyScint2 = MySensitiveDetector::GetTotalEnergyScint2();

  // G4double edep1 = mySensitiveDetector1->energy1;

  // std::cout << "Energy Deposited 1: " << edep1 << std::endl;

  // std::cout << std::fixed << std::setprecision(2) << "teste = " << teste1 << std::endl;
  // std::cout << std::fixed << std::setprecision(2) << "teste = " << teste1 << std::endl;


  // G4double edep = detector.getEnergy();

  //std::cout << "Energy Deposited Scintillator 1: " << totalEnergyScint1 << std::endl;
  // std::cout << "Energy Deposited Scintillator 2: " << mySensitiveDetector2->getEnergy2() << std::endl;

  delete runManager;


  return 0;
}

