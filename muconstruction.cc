#include "muconstruction.hh"

MyDetectorConstruction::MyDetectorConstruction()
{}

MyDetectorConstruction::~MyDetectorConstruction()
{}

G4VPhysicalVolume *MyDetectorConstruction::Construct()
{
    G4NistManager *nist = G4NistManager::Instance();

    G4double energy[3] = {1.239841939*eV/0.5, 1.239841939*eV/0.425, 1.239841939*eV/0.4};
    G4double scint[3] = {0.02, 1.0, 0.08};
    G4double rindexScintillator[3] = {1.58, 1.58, 1.58};
    G4double rindexWorld[3] = {1.0, 1.0, 1.0};
    G4double atnl[3] = {380.*cm, 380.*cm, 380.*cm};

//Definir Mundo


    G4Material *worldMat = nist->FindOrBuildMaterial("G4_AIR");

    G4MaterialPropertiesTable *mptWorld = new G4MaterialPropertiesTable();
    mptWorld->AddProperty("RINDEX", energy, rindexWorld, 3);

    worldMat->SetMaterialPropertiesTable(mptWorld);

    G4Box *solidWorld = new G4Box("solidWorld", 0.5*m, 0.5*m, 0.5*m);

    G4LogicalVolume *logicWorld = new G4LogicalVolume(solidWorld, worldMat, "logicWorld");

    G4VPhysicalVolume *physWorld = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.), logicWorld, "physWorld", 0, false, 0, true);

//Definir Material Cintilador

    G4Material *scintillator = nist->BuildMaterialWithNewDensity("scintillator","G4_PLASTIC_SC_VINYLTOLUENE", 1.023*g/cm3);

    G4MaterialPropertiesTable *mptScintillator = new G4MaterialPropertiesTable();

    //mptScintillator = scintillator->GetMaterialPropertiesTable();

    mptScintillator->AddProperty("SCINTILLATIONCOMPONENT1", energy, scint, 3);
    mptScintillator->AddProperty("RINDEX", energy, rindexScintillator, 3);
    mptScintillator->AddProperty("ABSLENGTH", energy, atnl, 3);
    mptScintillator->AddConstProperty("SCINTILLATIONYIELD", 100. / MeV);
    mptScintillator->AddConstProperty("RESOLUTIONSCALE", 1.0);
    mptScintillator->AddConstProperty("SCINTILLATIONTIMECONSTANT1", 2.1 * ns);
    mptScintillator->AddConstProperty("SCINTILLATIONRISETIME1", 0.9 * ns);
    mptScintillator->AddConstProperty("SCINTILLATIONYIELD1", 1.0);

    scintillator->SetMaterialPropertiesTable(mptScintillator);
    

//Definir Primeiro Cintilador

    G4Box *solidScintillator1 = new G4Box("solidScintillator1", 0.1265*m, 0.05*m, 0.0026*m);

    logicScintillator1 = new G4LogicalVolume(solidScintillator1, scintillator, "logicScintillator1");

    G4VPhysicalVolume *physScintillator1 = new G4PVPlacement(0, G4ThreeVector(0., 0., 0.25*m), logicScintillator1, "physScintillator1", logicWorld, false, 0, true);

//Definir Segundo Cintilador

    G4Box *solidScintillator2 = new G4Box("solidScintillator2", 0.1265*m, 0.05*m, 0.0026*m);

    logicScintillator2 = new G4LogicalVolume(solidScintillator2, scintillator, "logicScintillator2");

    G4VPhysicalVolume *physScintillator2 = new G4PVPlacement(0, G4ThreeVector(0., 0., -0.25*m), logicScintillator2, "physScintillator2", logicWorld, false, 0, true);  

    ConstructSDandField();

    return physWorld;
}


void MyDetectorConstruction::ConstructSDandField()
{
    // MySensitiveDetector *sensDet1 = new MySensitiveDetector("SensitiveDetector1");

    // logicScintillator1->SetSensitiveDetector(sensDet1);

    // MySensitiveDetector *sensDet2 = new MySensitiveDetector("SensitiveDetector2");

    // logicScintillator2->SetSensitiveDetector(sensDet2);  

    mySensitiveDetector = new MySensitiveDetector("SensitiveDetector");
    logicScintillator1->SetSensitiveDetector(mySensitiveDetector);
    logicScintillator2->SetSensitiveDetector(mySensitiveDetector);

    G4SDManager* sdManager = G4SDManager::GetSDMpointer();
    sdManager->AddNewDetector(mySensitiveDetector);


}