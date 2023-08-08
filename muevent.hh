#ifndef MUEVENT_HH
#define MUEVENT_HH

#include "G4UserEventAction.hh"
#include "G4Event.hh"
#include "G4SDManager.hh"

#include "mudetector.hh"

class MyEventAction : public G4UserEventAction
{
public:
    MyEventAction();
    ~MyEventAction();
    
    virtual void BeginOfEventAction(const G4Event*);
    virtual void EndOfEventAction(const G4Event*);
    
};

#endif
