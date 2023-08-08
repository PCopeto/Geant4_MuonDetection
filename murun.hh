#ifndef MURUN_HH
#define MURUN_HH

#include "G4UserRunAction.hh"
#include "G4Run.hh"
#include "G4VSensitiveDetector.hh"


#include "G4AnalysisManager.hh"
#include "G4SDManager.hh"

#include "muconstruction.hh"

#include "mudetector.hh"


class MyRunAction : public G4UserRunAction
{
public:
    MyRunAction();
    ~MyRunAction();
    
    virtual void BeginOfRunAction(const G4Run*);
    virtual void EndOfRunAction(const G4Run*);
    

};

#endif