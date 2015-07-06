// Steering macro
#include "TROOT.h"
#include "TChain.h"
#include "TInterpreter.h"
 
void run() 
{
    gROOT->Reset();
    gInterpreter->EnableAutoLoading();
    //gROOT->ProcessLine(".L ");
    gROOT->ProcessLine(".! rm -f result.root");
    gROOT->ProcessLine(".! rm -f AnaNtupSelector_C.* MySelector_C.*");
    TChain *fChain = new TChain("AnaNtup", "chain");
    
    // for data 266904 cutflow
    fChain->Add("user.jpoveda.t0609_v12.00266904.physics_Main.DAOD_SUSY9.f594_m1435_p2361_output.root/user.jpoveda.5632900._000001.output.root");
    //fChain->Add("user.jpoveda.t0609_v12.00266919.physics_Main.DAOD_SUSY9.f594_m1435_p2361_output.root/user.jpoveda.5632916._000001.output.root");
    
    // for MC ttbar cutflow
    //fChain->Add("user.jpoveda.t0609_v12.410000.PowhegPythiaEvtGen_P2012_ttbar_hdamp172p5_nonallhad.DAOD_SUSY1.s2608_r6633_p2353_output.root.31243678/user.jpoveda.5684539._000001.output.root");
    //fChain->Add("user.jpoveda.t0609_v12.410000.PowhegPythiaEvtGen_P2012_ttbar_hdamp172p5_nonallhad.DAOD_SUSY1.s2608_r6633_p2353_output.root.31251316/user.jpoveda.5684539._000002.output.root");
    //fChain->Add("user.jpoveda.t0609_v12.410000.PowhegPythiaEvtGen_P2012_ttbar_hdamp172p5_nonallhad.DAOD_SUSY1.s2608_r6633_p2353_output.root.31311442/user.jpoveda.5684539._000003.output.root");

    gROOT->LoadMacro("./AnaNtupSelector.cxx+");
    fChain->Process("./MySelector.cxx+");
}

// $ localSetupFAX
// use $fax-get-gLFNs user.jpoveda:user.jpoveda.t0609_v12.00266904.physics_Main.DAOD_SUSY9.f594_m1435_p2361_output.root
// fChain->Add("root://atlas-xrd-eos-rucio.cern.ch:1094//atlas/rucio/user.jpoveda:user.jpoveda.5632900._000001.output.root/user.jpoveda.5632900._000001.output.root")