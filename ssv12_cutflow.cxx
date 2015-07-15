#include "TROOT.h"
#include "TChain.h"
#include "TInterpreter.h"

#include "MyPackages/MySelector.h"

#include <iostream>
using namespace std;
 
//int main( int argc, char* argv[] ) 
int main()
{
    gROOT->Reset();
    gInterpreter->EnableAutoLoading();

    TChain *fChain = new TChain("AnaNtup", "chain");
    
    // for data 266904 cutflow
    //fChain->Add("../user.jpoveda.t0609_v12.00266904.physics_Main.DAOD_SUSY9.f594_m1435_p2361_output.root/user.jpoveda.5632900._000001.output.root");

    // for MC ttbar cutflow
    fChain->Add("../user.jpoveda.t0609_v12.410000.PowhegPythiaEvtGen_P2012_ttbar_hdamp172p5_nonallhad.DAOD_SUSY1.s2608_r6633_p2353_output.root.31243678/user.jpoveda.5684539._000001.output.root");
    fChain->Add("../user.jpoveda.t0609_v12.410000.PowhegPythiaEvtGen_P2012_ttbar_hdamp172p5_nonallhad.DAOD_SUSY1.s2608_r6633_p2353_output.root.31251316/user.jpoveda.5684539._000002.output.root");
    fChain->Add("../user.jpoveda.t0609_v12.410000.PowhegPythiaEvtGen_P2012_ttbar_hdamp172p5_nonallhad.DAOD_SUSY1.s2608_r6633_p2353_output.root.31311442/user.jpoveda.5684539._000003.output.root");

    MySelector *foo2 = new MySelector;
    fChain->Process(foo2);
}
