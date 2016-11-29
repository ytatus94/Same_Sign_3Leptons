#include "TROOT.h"
#include "TChain.h"
#include "TInterpreter.h"

#include "MyPackages/MySelector.h"

#include <iostream>
using namespace std;
 
int main( int argc, char* argv[] )
{
    gROOT->Reset();
    gInterpreter->EnableAutoLoading();

    // The application's name:
    const char* APP_NAME = argv[0];
    
    if (argc < 2) {
        Error(APP_NAME, " Usage: %s [isData=0/1 isMC=0/1]", APP_NAME);
        exit(0);
    }
    
    int isData = 0;
    int isMC   = 0;
    for (int i = 1; i < argc; i++) {
        const char* key = strtok(argv[i], "=");
        const char* val = strtok(0, " ");
        if (strcmp(key, "isData") == 0 ) isData = atoi(val);
        if (strcmp(key, "isMC") == 0 ) isMC = atoi(val);
    }
   
    Info(APP_NAME, "isMC = %i, isData = %i", isMC, isData);
 
    TChain *fChain = new TChain("AnaNtup", "chain");
    
    // for data 266904 cutflow
    if (isData) {
        cout << "Add data files to TChain..." << endl;
        //fChain->Add("../user.jpoveda.t0609_v12.00266904.physics_Main.DAOD_SUSY9.f594_m1435_p2361_output.root/user.jpoveda.5632900._000001.output.root");
    }
    // for MC ttbar cutflow
    if (isMC) {
        cout << "Add MC files to TChain..." << endl;
        fChain->Add("/afs/cern.ch/work/y/yushen/private/Ximo/SS3LAnalysis/submit_dir/data-output/mc15_13TeV.370602.MGPy8EG_A14N23LO_NUHM2_m12_400_strong.merge.DAOD.e4209_a766_a777_r6282.root");
        //fChain->Add("../user.jpoveda.t0609_v12.410000.PowhegPythiaEvtGen_P2012_ttbar_hdamp172p5_nonallhad.DAOD_SUSY1.s2608_r6633_p2353_output.root.31243678/user.jpoveda.5684539._000001.output.root");
        //fChain->Add("../user.jpoveda.t0609_v12.410000.PowhegPythiaEvtGen_P2012_ttbar_hdamp172p5_nonallhad.DAOD_SUSY1.s2608_r6633_p2353_output.root.31251316/user.jpoveda.5684539._000002.output.root");
        //fChain->Add("../user.jpoveda.t0609_v12.410000.PowhegPythiaEvtGen_P2012_ttbar_hdamp172p5_nonallhad.DAOD_SUSY1.s2608_r6633_p2353_output.root.31311442/user.jpoveda.5684539._000003.output.root");
    }

    MySelector *foo = new MySelector;
    foo->isMC = isMC;
    foo->isData = isData;
    fChain->Process(foo);

}
