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
    TChain *fChain = new TChain("AnaNtup", "chain");
    fChain->Add("../user.jpoveda.t26_v04_p1872.204533.Herwigpp_UEEE4_CTEQ6L1_Gtt_G1000_T5000_L100_output.root.24717794/user.jpoveda.5286937._000001.output.root");
    //fChain->Process("./AnaNtupV04Selector.C+");
    fChain->Process("./AnaNtupBunchSapcing.C+");
}
