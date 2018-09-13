#include "TROOT.h"
#include "TChain.h"
#include "TInterpreter.h"
#include "TString.h"

#include "ytCutflows/yt_selector.h"

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
    TString process;
    for (int i = 1; i < argc; i++) {
        const char* key = strtok(argv[i], "=");
        const char* val = strtok(0, " ");
        if (strcmp(key, "isData") == 0 ) isData = atoi(val);
        if (strcmp(key, "isMC") == 0 ) isMC = atoi(val);
        if (strcmp(key, "Zee") == 0) process = "Zee";
        if (strcmp(key, "Zmumu") == 0) process = "Zmumu";
        if (strcmp(key, "ttbar") == 0) process = "ttbar";
        if (strcmp(key, "GG_ttn1") == 0) process = "GG_ttn1";
    }

    //Info(APP_NAME, "isMC = %i, isData = %i", isMC, isData);
    Info(APP_NAME, "isMC = %i, isData = %i, process = %s", isMC, isData, process.Data());

    TChain *fChain = new TChain("AnaNtup", "chain");

    // for data
    if (isData) {
        cout << "Add data files to TChain..." << endl;
        //cout << "Currently, no data." << endl;

        TString path = "/afs/cern.ch/work/y/yushen/private/Ximo/v39/ytCutflows/data/user.jpoveda.t0769_v40retry.00278912.physics_Main.DAOD_SUSY2.r7562_p2521_p2667_output.root";
        fChain->Add(path + "/user.jpoveda.8791764._000001.output.root");
        fChain->Add(path + "/user.jpoveda.8791764._000002.output.root");
/*
        TString path = "/UserDisk2/yushen/Ximo/v40/Data";
        fChain->Add(path + "/merged_all_data.root");
*/
    }
    // for MC
    if (isMC) {
        cout << "Add MC files to TChain..." << endl;
/*
    TString path = "root://eosatlas.cern.ch//eos/atlas/user/y/yushen/Ximo_ntuples/v39/MC/user.jpoveda.t0769_v39.410080.MadGraphPythia8EvtGen_A14NNPDF23_4topSM.DAOD_SUSY2.s2608_r7725_p2613_output.root";
    fChain->Add(path + "/user.jpoveda.8707424._000001.output.root");
*/
        TString path = "/UserDisk2/yushen/Ximo/v39/MC";
        if (process == "Zee")
            fChain->Add(path + "/Zee_merged.root");
        else if (process == "Zmumu")
            fChain->Add(path + "/Zmumu_merged.root");
        else if (process == "ttbar")
            fChain->Add(path + "/ttbar_merged.root");
        else if (process == "GG_ttn1")
            fChain->Add(path + "/GG_ttn1_merged.root");
    }

    yt_selector *foo = new yt_selector;
    foo->isMC = isMC;
    foo->isData = isData;
    foo->process = process;
    fChain->Process(foo);
}
