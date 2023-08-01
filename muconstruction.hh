#ifndef MUCONSTRUCTION_HH
#define MUCONSTRUCTION_HH

#include "G4VUserDetectorConstruction.hh"
#include "G4VPhysicalVolume.hh"
#include "G4LogicalVolume.hh"
#include "G4Box.hh"
#include "G4PVPlacement.hh"
#include "G4NistManager.hh"
#include "G4SystemOfUnits.hh"

#include "mudetector.hh"

class MyDetectorConstruction : public G4VUserDetectorConstruction
{
public:
    MyDetectorConstruction();
    ~MyDetectorConstruction();

    virtual G4VPhysicalVolume *Construct();

private:
    G4LogicalVolume *logicScintillator1;
    G4LogicalVolume *logicScintillator2;
    MySensitiveDetector* mySensitiveDetector; // Single instance of MySensitiveDetector

    virtual void ConstructSDandField();
}; 

#endif