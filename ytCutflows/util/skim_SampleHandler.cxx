#include "TROOT.h"
#include "TChain.h"
#include "TInterpreter.h"
#include "TString.h"

#include "SampleHandler/SampleHandler.h"
#include "SampleHandler/ScanDir.h"
#include "SampleHandler/ToolsDiscovery.h"
#include "SampleHandler/DiskListLocal.h"

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
        Error(APP_NAME, " Usage: %s [isData isMC Zee Zmumu ttbar GG_ttn1]", APP_NAME);
        exit(0);
    }

    bool isData = false;
    bool isMC   = false;
    bool Zee    = false;
    bool Zmumu 	= false;
    bool ttbar  = false;
    bool GG_ttn1 = false;
    for (int i = 1; i < argc; i++) {
        const char* key = strtok(argv[i], "=");
        //const char* val = strtok(0, " ");
        if (strcmp(key, "isData") == 0) isData = true;
        if (strcmp(key, "isMC") == 0) isMC = true;
        if (strcmp(key, "Zee") == 0) Zee = true;
        if (strcmp(key, "Zmumu") == 0) Zmumu = true;
        if (strcmp(key, "ttbar") == 0) ttbar = true;
        if (strcmp(key, "GG_ttn1") == 0) GG_ttn1 = true;
    }

    //Info(APP_NAME, "isMC = %i, isData = %i", isMC, isData);
    printf("isData=%s, isMC=%s, Zee=%s, Zmumu=%s, ttbar=%s, GG_ttn1=%s\n", 
            isData ? "true" : "false", 
            isMC ? "true" : "false", 
            Zee ? "true" : "false", 
            Zmumu ? "true" : "false",
            ttbar ? "true" : "false",
            GG_ttn1 ? "true" : "false");

    // Create a new sample handler to describe the data files we use
    SH::SampleHandler sh;
    // use SampleHandler to scan all of the subdirectories of a directory for particular MC single file
    // for data
    if (isData) {
        //const char *input_file_path = "/UserDisk2/yushen/Ximo/v40/Data/";
        const char *input_file_path = "/UserDisk2/yushen/Ximo/v40/Data/test/";
        SH::ScanDir().scan(sh, input_file_path);
    }
    // for MC
    if (isMC) {
        const char *input_file_path = "/UserDisk2/yushen/Ximo/v39/MC";
        if (Zee) {
            SH::ScanDir().sampleDepth(0).samplePattern("user.jpoveda.t0769_v39*Zee*output.root").scan(sh, input_file_path);
        }
        if (Zmumu) {
            SH::ScanDir().sampleDepth(0).samplePattern("user.jpoveda.t0769_v39*Zmumu*output.root").scan(sh, input_file_path);
        }
        if (ttbar) {
            SH::ScanDir().sampleDepth(0).samplePattern("user.jpoveda.t0769_v39*ttbar*output.root").scan(sh, input_file_path);
        }
        if (GG_ttn1) {
            SH::ScanDir().sampleDepth(0).samplePattern("user.jpoveda.t0769_v39*GG_ttn1*output.root").scan(sh, input_file_path);
        }
    }
    // set the name of the tree in our files
    sh.setMetaString("nc_tree", "AnaNtup");

    // print out the samples we found
    sh.print();

    yt_selector *foo = new yt_selector;
    foo->isMC = isMC;
    foo->isData = isData;
    TChain *fChain;
    // Looping Over Samples
/*
    for (SH::SampleHandler::iterator iter = sh.begin(); iter != sh.end(); ++ iter) {
        SH::Sample *sample = *iter;
        fChain = sample->makeTChain();
        fChain->Process(foo);
    }
*/
/*
    TChain *fChain = new TChain("AnaNtup", "chain");

    // for data
    if (isData) {
        cout << "Add data files to TChain..." << endl;
        fChain->Add("root://eosatlas.cern.ch//eos/atlas/user/y/yushen/");
    }
    // for MC
    if (isMC) {
        cout << "Add MC files to TChain..." << endl;
        TString path = "root://eosatlas.cern.ch//eos/atlas/user/y/yushen/Ximo_ntuples/v39/MC/user.jpoveda.t0769_v39.410080.MadGraphPythia8EvtGen_A14NNPDF23_4topSM.DAOD_SUSY2.s2608_r7725_p2613_output.root";
        fChain->Add(path + "/user.jpoveda.8707424._000001.output.root");
    }

    yt_selector *foo = new yt_selector;
    foo->isMC = isMC;
    foo->isData = isData;
    fChain->Process(foo);
*/
}
