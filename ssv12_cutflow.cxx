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
    fChain->Add("../user.jpoveda.t0609_v12.00266904.physics_Main.DAOD_SUSY9.f594_m1435_p2361_output.root/user.jpoveda.5632900._000001.output.root");

    MySelector *foo2 = new MySelector;
    fChain->Process(foo2);
}
