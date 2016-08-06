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
		if (strcmp(key, "4topSM") == 0) process = "4topSM";
		if (strcmp(key, "Zee") == 0) process = "Zee";
		if (strcmp(key, "Zmumu") == 0) process = "Zmumu";
		if (strcmp(key, "ttbar") == 0) process = "ttbar";
		if (strcmp(key, "GG_ttn1") == 0) process = "GG_ttn1";
	}

	Info(APP_NAME, "isMC = %s, isData = %s", isMC ? "true" : "false", isData ? "true" : "false");
	if (isMC == true && process.IsNull() == false)
		Info(APP_NAME, "process = %s", process.Data());

	TString path;
	TChain *fChain = new TChain("AnaNtup", "chain");

	// for data
	if (isData) {
		cout << "Add data files to TChain..." << endl;
		//cout << "Currently, no data." << endl;
		path = "/UserDisk2/yushen/Ximo_ntuples/v44/Data/";
		fChain->Add(path + "/merged_all_data.root");
		//fChain->Add(path + "/run303304.root");
/*
		path = "/UserDisk2/yushen/Ximo_ntuples/v44/Data/user.jpoveda.t0789_v44.00303304.physics_Main.DAOD_SUSY2.f716_m1620_p2689_output.root/";
		fChain->Add(path + "/user.jpoveda.9048831._000001.output.root");
		fChain->Add(path + "/user.jpoveda.9048831._000004.output.root");
		fChain->Add(path + "/user.jpoveda.9048831._000005.output.root");
		fChain->Add(path + "/user.jpoveda.9048831._000006.output.root");
		fChain->Add(path + "/user.jpoveda.9048831._000007.output.root");
		fChain->Add(path + "/user.jpoveda.9048831._000008.output.root");
		fChain->Add(path + "/user.jpoveda.9048831._000009.output.root");
		fChain->Add(path + "/user.jpoveda.9048831._000010.output.root");
		fChain->Add(path + "/user.jpoveda.9048831._000011.output.root");
		fChain->Add(path + "/user.jpoveda.9048831._000012.output.root");
		fChain->Add(path + "/user.jpoveda.9048831._000013.output.root");
*/
	}
	// for MC
	else if (isMC) {
		cout << "Add MC files to TChain..." << endl;
/*
		path = "/UserDisk2/yushen/Ximo_ntuples/v44/MC/user.jpoveda.t0789_v44.410080.MadGraphPythia8EvtGen_A14NNPDF23_4topSM.DAOD_SUSY2.s2608_r7725_p2666_output.root";
		fChain->Add(path + "/user.jpoveda.9048853._000001.output.root");
*/

		path = "/UserDisk2/yushen/Ximo_ntuples/v44/MC/";
		if (process == "4topSM") {
			fChain->Add(path + "/user.jpoveda.t0789_v44.410080.MadGraphPythia8EvtGen_A14NNPDF23_4topSM.DAOD_SUSY2.s2608_r7725_p2666_output.root/user.jpoveda.9048853._000001.output.root");
		}
		else if (process == "Zee")
			fChain->Add(path + "/Zee_merged.root");
		else if (process == "Zmumu")
			fChain->Add(path + "/Zmumu_merged.root");
		else if (process == "ttbar")
			fChain->Add(path + "/ttbar_merged.root");
		else if (process == "GG_ttn1")
			fChain->Add(path + "/GG_ttn1_merged.root");

	}

	//TFile *file = TFile::Open("/UserDisk2/yushen/Ximo_ntuples/v44/MC/user.jpoveda.t0789_v44.410080.MadGraphPythia8EvtGen_A14NNPDF23_4topSM.DAOD_SUSY2.s2608_r7725_p2666_output.root/user.jpoveda.9048853._000001.output.root");

	TFile *file;
	if (isData) {
		file = TFile::Open(path + "/merged_all_data.root");
		//file = TFile::Open(path + "/run303304.root");
	}
	if (isMC) {
		if (process == "4topSM")
			file = TFile::Open(path + "/user.jpoveda.t0789_v44.410080.MadGraphPythia8EvtGen_A14NNPDF23_4topSM.DAOD_SUSY2.s2608_r7725_p2666_output.root/user.jpoveda.9048853._000001.output.root");
		else if (process == "Zee")
			file = TFile::Open(path + "/Zee_merged.root");
		else if (process == "Zmumu")
			file = TFile::Open(path + "/Zmumu_merged.root");
		else if (process == "ttbar")
			file = TFile::Open(path + "/ttbar_merged.root");
		else if (process == "GG_ttn1")
			file = TFile::Open(path + "/GG_ttn1_merged.root");
	}

	TH1D *DerivationStat_Weights = (TH1D *)file->Get("DerivationStat_Weights");
	double derivation_stat_weights = DerivationStat_Weights->GetBinContent(1);
	cout << "derivation_stat_weights=" << derivation_stat_weights << endl;

    const double luminosity = 5.8; // unit: 1/fb, 3.2/fb (2015) + 2.6/fb (2016)
	//double luminosity = 475.796043 / 1000.; // for run 303304

	yt_selector *foo = new yt_selector;
	foo->set_isMC(isMC);
	foo->set_isData(isData);
	if (isMC == true && process.IsNull() == false)
		foo->set_process(process);
	foo->set_derivation_stat_weights(derivation_stat_weights);
	foo->set_luminosity(luminosity);
	fChain->Process(foo);

}
