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
    fChain->Add("user.jpoveda.5286937._000001.output.root");
    fChain->Process("./AnaNtupV04Selector.C+");
}
