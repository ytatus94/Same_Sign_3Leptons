// Steering macro
#include "TROOT.h"
#include "TChain.h"
#include "TInterpreter.h"
 
void run() 
{
    gROOT->Reset();
    gInterpreter->EnableAutoLoading();
    //gROOT->ProcessLine(".L ");
    //gROOT->ProcessLine(".! rm -f result.root");
    gROOT->ProcessLine(".! rm -f AnaNtupSelector_C.* MySelector_C.*");
    TChain *fChain = new TChain("AnaNtup", "chain");
    // for testing
    fChain->Add("user.jpoveda.t0609_v12.00266904.physics_Main.DAOD_SUSY9.f594_m1435_p2361_output.root/user.jpoveda.5632900._000001.output.root");
    //fChain->Add("user.jpoveda.t0609_v12.00266919.physics_Main.DAOD_SUSY9.f594_m1435_p2361_output.root/user.jpoveda.5632916._000001.output.root");
    gROOT->LoadMacro("./AnaNtupSelector.cxx+");
    fChain->Process("./MySelector.cxx+");
}

// $ localSetupFAX
// use $fax-get-gLFNs user.jpoveda:user.jpoveda.t0609_v12.00266904.physics_Main.DAOD_SUSY9.f594_m1435_p2361_output.root
// fChain->Add("root://atlas-xrd-eos-rucio.cern.ch:1094//atlas/rucio/user.jpoveda:user.jpoveda.5632900._000001.output.root/user.jpoveda.5632900._000001.output.root")
