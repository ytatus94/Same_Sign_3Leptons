#include "TROOT.h"
#include "TChain.h"
#include "TInterpreter.h"
#include "TString.h"
#include "TFile.h"
#include "TH1.h"

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
		Error(APP_NAME, " Usage: %s [isData=1/0 isMC=1/0]", APP_NAME);
		exit(0);
	}

	bool isData = false;
	bool isMC   = false;
	TString process;
	for (int i = 1; i < argc; i++) {
		//const char* key = strtok(argv[i], "=");
		//const char* val = strtok(0, " ");
		const char* key = argv[i];
		if (strcmp(key, "isData") == 0 ) isData = true;
		if (strcmp(key, "isMC") == 0 ) isMC = true;
	}

	Info(APP_NAME, "isMC = %s, isData = %s", isMC ? "true" : "false", isData ? "true" : "false");

	TString path;
	TChain *fChain = new TChain("AnaNtup", "chain");

	// for data
	if (isData) {
		cout << "Add data files to TChain..." << endl;
		cout << "Currently, no data." << endl;
	}
	// for MC
	if (isMC) {
		cout << "Add MC files to TChain..." << endl;
		path = "/UserDisk2/yushen/Ximo_ntuples/v44/MC/user.jpoveda.t0789_v44.410080.MadGraphPythia8EvtGen_A14NNPDF23_4topSM.DAOD_SUSY2.s2608_r7725_p2666_output.root";
		fChain->Add(path + "/user.jpoveda.9048853._000001.output.root");
	}

	TFile *file = TFile::Open(path + "/user.jpoveda.9048853._000001.output.root");
	TH1D *DerivationStat_Weights = (TH1D *)file->Get("DerivationStat_Weights");
	double derivation_stat_weights = DerivationStat_Weights->GetBinContent(1);

	yt_selector *foo = new yt_selector;
	foo->isMC = isMC;
	foo->isData = isData;
	foo->derivation_stat_weights = derivation_stat_weights;
	fChain->Process(foo);
}
