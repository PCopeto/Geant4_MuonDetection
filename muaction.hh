#ifndef MUACTION_HH
#define MUACTION_HH

#include "G4VUserActionInitialization.hh"

#include "mugenerator.hh"
#include "murun.hh"

class MyActionInitialization : public G4VUserActionInitialization
{
public:
    MyActionInitialization();
    ~MyActionInitialization();

    virtual void Build() const;

};

#endif