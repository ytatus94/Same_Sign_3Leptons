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
	for (int i = 1; i < argc; i++) {
		const char* key = strtok(argv[i], "=");
		const char* val = strtok(0, " ");
		if (strcmp(key, "isData") == 0 ) isData = atoi(val);
		if (strcmp(key, "isMC") == 0 ) isMC = atoi(val);
	}

	Info(APP_NAME, "isMC = %i, isData = %i", isMC, isData);

	TChain *fChain = new TChain("AnaNtup", "chain");

	// for data
	if (isData) {
		cout << "Add data files to TChain..." << endl;
		cout << "Currently, no data." << endl;
		//fChain->Add("../user.jpoveda.t0609_v12.00266904.physics_Main.DAOD_SUSY9.f594_m1435_p2361_output.root/user.jpoveda.5632900._000001.output.root");
	}
	// for MC
	if (isMC) {
		cout << "Add MC files to TChain..." << endl;
		TString path = "/afs/cern.ch/work/y/yushen/private/Ximo/v37/ytCutflows/data/user.jpoveda.t0756_v37.410080.MadGraphPythia8EvtGen_A14NNPDF23_4topSM.DAOD_SUSY2.s2608_r7725_p2613_output.root";
		fChain->Add(path + "/user.jpoveda.8482167._000001.output.root");
	}

	yt_selector *foo = new yt_selector;
	foo->isMC = isMC;
	foo->isData = isData;
	fChain->Process(foo);
}
