#ifndef MUDETECTOR_HH
#define MUDETECTOR_HH

#include "G4VSensitiveDetector.hh"
#include "G4AnalysisManager.hh"
#include "G4RunManager.hh"

//#include "murun.hh"

class MySensitiveDetector : public G4VSensitiveDetector
{
public:
    MySensitiveDetector(G4String);
    ~MySensitiveDetector();

    G4double getEnergy1() const {return totalEnergyScint1;}
    G4double getEnergy2() const {return totalEnergyScint2;}
    
    void ResetEnergy() { totalEnergyScint1 = 0.0; totalEnergyScint2 = 0.0; }

private:
    // Private attribute
    virtual G4bool ProcessHits(G4Step *, G4TouchableHistory *);



    // Add a member to store the analysis manager pointer
    G4AnalysisManager* analysisManager;
    

    G4double totalEnergyScint1;
    G4double totalEnergyScint2;
    G4double energy1;
    G4double energy2;
};

#endif