#ifndef MUDETECTOR_HH
#define MUDETECTOR_HH

#include "G4VSensitiveDetector.hh"
#include "G4AnalysisManager.hh"
#include "G4RunManager.hh"

#include "murun.hh"

class MySensitiveDetector : public G4VSensitiveDetector
{
public:
    MySensitiveDetector(G4String);
    ~MySensitiveDetector();
    // G4double GetTotalEnergyScint1() const { return totalEnergyScint1; }
    // //G4double GetTotalEnergyScint2() const { return totalEnergyScint2; }
    // void SetTotalEnergyScint1(G4double totalEnergyScint1);
    //Setter
    void setEnergy1(G4double edep1) {totalEnergyScint1 = edep1;}
    // Getter
    G4double getEnergy1() {return totalEnergyScint1;}

    void setEnergy2(G4double edep2) {totalEnergyScint2 = edep2;}
    G4double getEnergy2() {return totalEnergyScint2;}
    
private:
    // Private attribute
    virtual G4bool ProcessHits(G4Step *, G4TouchableHistory *);

    

    // Add a member to store the analysis manager pointer
    G4AnalysisManager* analysisManager;
    // G4double totalEnergyScint1;
    // G4double totalEnergyScint1;
    //G4double totalEnergyScint2;
    
public:
    // void UpdateTotalEnergyScint1(G4double energy1);
    // void UpdateTotalEnergyScint2(G4double energy2);
    



    G4double totalEnergyScint1;
    G4double totalEnergyScint2;
    G4double energy1;
    G4double energy2;
};

#endif