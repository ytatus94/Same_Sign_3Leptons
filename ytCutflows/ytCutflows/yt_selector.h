#ifndef YT_SELECTOR_H
#define YT_SELECTOR_H

#include <iostream>
#include <vector>
#include <iterator>
#include <typeinfo>
using namespace std;

#define Mu_Mass 105.6583715

#include "ytCutflows/AnaNtup_MC.h"
#include "ytCutflows/Leptons.h"
#include "ytCutflows/Jet.h"
#include "ytCutflows/yt_cutflows.h"

class yt_selector : public AnaNtup_MC {
public:
	// flag
	bool isMC;
	bool isData;
	// user defined variables
	double				derivation_stat_weights; // sum of EventWeight

	yt_cutflows			*m_cutflow;

	vector<Electron>	vec_elec;
	vector<Muon>		vec_muon;
	vector<Lepton>		vec_lept;
	vector<Jet>			vec_jets;

	vector<Electron>	vec_baseline_elec;
	vector<Muon>		vec_baseline_muon;
	vector<Lepton>		vec_baseline_lept;
	vector<Jet>			vec_baseline_jets;

	vector<Electron> 	vec_OR_elec;
	vector<Muon>     	vec_OR_muon;
	vector<Lepton>   	vec_OR_lept;
	vector<Jet>      	vec_OR_jets;

	vector<Jet>			vec_JVT_jets;

	vector<Electron> 	vec_signal_elec;
	vector<Muon>     	vec_signal_muon;
	vector<Lepton>   	vec_signal_lept;
	vector<Jet>      	vec_signal_jets;

	TH1 *hCutFlows;

public:
	TTree   *fChain; //!pointer to the analyzed TTree or TChain

	yt_selector(TTree * /*tree*/ =0) : fChain(0) {}
	virtual ~yt_selector() {}
	virtual Int_t   Version() const { return 2; }
	virtual void    Begin(TTree *tree);
	virtual void    SlaveBegin(TTree *tree);
	virtual void    Init(TTree *tree);
	virtual Bool_t  Notify();
	virtual Bool_t  Process(Long64_t entry);
	virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }	
	virtual void    SetOption(const char *option) { fOption = option; } 
	virtual void    SetObject(TObject *obj) { fObject = obj; }
	virtual void    SetInputList(TList *input) { fInput = input; }
	virtual TList  *GetOutputList() const { return fOutput; }
	virtual void    SlaveTerminate();
	virtual void    Terminate();
	// user defined functions
	void fill_electrons(Int_t           NEl,
						int             flavor,
						vector<double>  *El_eta,
						vector<double>  *El_etaclus,
						vector<double>  *El_phi,
						vector<double>  *El_pT,
						vector<double>  *El_E,
						vector<int>     *El_charge,
						vector<double>  *El_sigd0,
						vector<double>  *El_z0sinTheta,
						vector<double>  *El_d0pvtx,
						vector<bool>    *El_passOR,
						vector<double>  *El_SFwMediumLH,
						vector<float>   *El_IsoSFwMediumLH,
						vector<double>  *El_SFwTightLH,
						vector<double>  *El_SFwLooseAndBLayerLH,
						vector<double>  *El_SFwTrigMediumLH_e12_lhloose_L1EM10VH,
						vector<double>  *El_SFwTrigMediumLH_e17_lhloose,
						vector<double>  *El_SFwTrigMediumLH_single,
						vector<double>  *El_SFwTrigLooseAndBLayerLH_e12_lhloose_L1EM10VH,
						vector<bool>    *El_isLooseAndBLayerLH,
						vector<bool>    *El_isMediumLH,
						vector<bool>    *El_isTightLH,
						vector<int>     *El_nBLayerHits,
						vector<int>     *El_expectBLayerHit,
						vector<int>     *El_type,
						vector<int>     *El_origin,
						vector<int>     *El_bkgMotherPdgId,
						vector<int>     *El_bkgOrigin,
						vector<int>     *El_chFlip,
						vector<double>  *El_ptcone20,
						vector<double>  *El_ptcone30,
						vector<double>  *El_ptcone40,
						vector<double>  *El_ptvarcone20,
						vector<double>  *El_ptvarcone30,
						vector<double>  *El_ptvarcone40,
						vector<double>  *El_topoetcone20,
						vector<double>  *El_topoetcone30,
						vector<double>  *El_topoetcone40,
						vector<bool>    *El_passIsoLooseTO,
						vector<bool>    *El_passIsoLoose,
						vector<bool>    *El_passIsoTight,
						vector<bool>    *El_passIsoGrad,
						vector<bool>    *El_passIsoGradCustomTight,
						vector<bool>    *El_passIsoGradCustom,
						vector<bool>    *El_passIsoGradLoose,
						vector<bool>    *El_trigMatch_e12_lhloose_L1EM10VH,
						vector<bool>    *El_trigMatch_e17_lhloose,
						vector<bool>    *El_trigMatch_e60_lhmedium,
						vector<bool>    *El_trigMatch_e24_lhmedium_iloose_L1EM20VH,
						vector<bool>    *El_trigMatch_2e12_lhloose_L12EM10VH,
						vector<bool>    *El_trigMatch_2e15_lhloose_L12EM10VH,
						vector<bool>    *El_trigMatch_2e15_lhvloose_L12EM13VH,
						vector<bool>    *El_trigMatch_2e15_lhvloose_nod0_L12EM13VH,
						vector<bool>    *El_trigMatch_2e17_lhvloose_nod0,
						vector<bool>    *El_trigMatch_e17_lhloose_mu14,
						vector<bool>    *El_trigMatch_e17_lhloose_nod0_mu14,
						vector<bool>    *El_TrigMatch_e24_lhmedium_nod0_ivarloose,
						vector<bool>    *El_TrigMatch_e24_lhtight_nod0_ivarloose,
						vector<bool>    *El_TrigMatch_e60_lhmedium_nod0);

	void fill_muons(Int_t           NMu,
					int             flavor,
					vector<double>  *Mu_eta,
					vector<double>  *Mu_phi,
					vector<double>  *Mu_pT,
					vector<double>  *Mu_SFw,
					vector<float>   *Mu_IsoSFw,
					vector<int>     *Mu_charge,
					vector<double>  *Mu_d0pvtx,
					vector<double>  *Mu_sigd0,
					vector<double>  *Mu_z0sinTheta,
					vector<bool>    *Mu_isBad,
					vector<bool>    *Mu_passOR,
					vector<bool>    *Mu_isTight,
					vector<bool>    *Mu_isCosmic,
					vector<int>     *Mu_type,
					vector<int>     *Mu_origin,
					vector<double>  *Mu_ptcone20,
					vector<double>  *Mu_ptcone30,
					vector<double>  *Mu_ptcone40,
					vector<double>  *Mu_ptvarcone20,
					vector<double>  *Mu_ptvarcone30,
					vector<double>  *Mu_ptvarcone40,
					vector<double>  *Mu_topoetcone20,
					vector<double>  *Mu_topoetcone30,
					vector<double>  *Mu_topoetcone40,
					vector<bool>    *Mu_passIsoLooseTO,
					vector<bool>    *Mu_passIsoLoose,
					vector<bool>    *Mu_passIsoTight,
					vector<bool>    *Mu_passIsoGrad,
					vector<bool>    *Mu_passIsoGradCustomTight,
					vector<bool>    *Mu_passIsoGradCustom,
					vector<bool>    *Mu_passIsoGradLoose,
					Float_t         MuTrigSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50,
					vector<bool>    *Mu_trigMatch_mu26_imedium,
					vector<bool>    *Mu_trigMatch_mu50,
					vector<bool>    *Mu_trigMatch_mu8noL1,
					vector<bool>    *Mu_trigMatch_mu14,
					vector<bool>    *Mu_trigMatch_mu18,
					vector<bool>    *Mu_trigMatch_mu18_mu8noL1,
					vector<bool>    *Mu_trigMatch_e17_lhloose_mu14,
					vector<bool>    *Mu_trigMatch_e17_lhloose_nod0_mu14,
					vector<bool>    *Mu_trigMatch_mu20_mu8noL1,
					vector<bool>    *Mu_trigMatch_mu22_mu8noL1,
					vector<bool>    *Mu_TrigMatch_mu24_iloose,
					vector<bool>    *Mu_TrigMatch_mu24_ivarloose,
					vector<bool>    *Mu_TrigMatch_mu24_iloose_L1MU15,
					vector<bool>    *Mu_TrigMatch_mu24_ivarloose_L1MU15,
					vector<vector<bool> > *Mu_trigMatchPair_mu18_mu8noL1,
					vector<vector<bool> > *Mu_trigMatchPair_mu20_mu8noL1);

	void fill_jets(Int_t           NJet,
				   vector<double>  *Jet_eta,
				   vector<double>  *Jet_phi,
				   vector<double>  *Jet_pT,
				   vector<double>  *Jet_E,
				   vector<double>  *Jet_quality,
				   vector<double>  *Jet_JVT,
				   vector<double>  *Jet_JVTsf,
				   vector<double>  *Jet_MV2c20,
				   vector<double>  *Jet_MV2c10,
				   vector<double>  *Jet_SFw,
				   vector<int>     *Jet_ConeTruthLabel,
				   vector<int>     *Jet_PartonTruthLabel,
				   vector<int>     *Jet_HadronConeExclTruthLabel,
				   vector<double>  *Jet_deltaR,
				   vector<int>     *Jet_nTrk,
				   vector<bool>    *Jet_passOR);

	void fill_leptons(vector<Electron> elec, vector<Muon> muon);

	void fill_baseline_electrons(vector<Electron> elec);
	void fill_baseline_muons(vector<Muon> muon);
	void fill_baseline_leptons(vector<Electron> elec, vector<Muon> muon);
	void fill_baseline_jets(vector<Jet> jets);

	void fill_OR_electrons(vector<Electron> elec);
	void fill_OR_muons(vector<Muon> muon);
	void fill_OR_leptons(vector<Electron> elec, vector<Muon> muon);
	void fill_OR_jets(vector<Jet> jets);

	void fill_JVT_jets(vector<Jet> jets);

	void fill_signal_electrons(vector<Electron> elec);
	void fill_signal_muons(vector<Muon> muon);
	void fill_signal_leptons(vector<Electron> elec, vector<Muon> muon);
	void fill_signal_jets(vector<Jet> jets);

	void set_baseline_and_signal_electrons();
	void set_baseline_and_signal_muons();
	void set_jets_and_bjets();

	template<typename T>
	void debug_print(vector<T> vec);
	void debug_elec_print(vector<Electron> elec);
	void debug_muon_print(vector<Muon> muon);
	void debug_lept_print(vector<Lepton> lept);
	void debug_jets_print(vector<Jet> jets);

	ClassDef(yt_selector, 0);
};

#endif // #define YT_SELECTOR_H

#ifdef YT_SELECTOR_CXX
void yt_selector::Init(TTree *tree)
{
	// The Init() function is called when the selector needs to initialize
	// a new tree or chain. Typically here the branch addresses and branch
	// pointers of the tree will be set.
	// It is normally not necessary to make changes to the generated
	// code, but the routine can be extended by the user if needed.
	// Init() will be called many times when running on PROOF
	// (once per file to be processed).

	AnaNtup_MC::Init(tree);
}

Bool_t yt_selector::Notify()
{
	// The Notify() function is called when a new file is opened. This
	// can be either for a new TTree in a TChain or when when a new TTree
	// is started when using PROOF. It is normally not necessary to make cha    nges
	// to the generated code, but the routine can be extended by the
	// user if needed. The return value is currently not used.

	return kTRUE;
}

template<typename T>
void yt_selector::debug_print(vector<T> vec)
{
	cout << "*** Event Number=" << EventNumber << endl;
	string type = typeid(T).name();
	cout << type << endl;
// This template doesn't work...
/*
	if (type.compare("Lepton") == 0) {
		cout << "This is Lepton" << endl;
		debug_lept_print(vec);
	}
	else if (type.compare("Electron") == 0) {
		cout << "This is Electron" << endl;
		debug_elec_print(vec);
	}
	else if (type.compare("Muon") == 0) {
		cout << "This is Muon" << endl;
		debug_muon_print(vec);
	}
	else if (type.compare("Jet") == 0) {
		cout << "This is Jet" << endl;
		debug_jets_print(vec);
	}
	else {	
		cout << "Type " << type << " doesn't match" << endl;
	}
*/
}

void yt_selector::debug_lept_print(vector<Lepton> vec_lept)
{
	cout << "*** Event Number=" << EventNumber << endl;
	cout << "NEl+NMu=" << vec_lept.size() << endl;
	int i = 0;
	for (auto & lep_itr : vec_lept) {
		//cout << "NEl+NMu=" << lep_itr.get_number() << endl;
		cout << i + 1
			<< ": pt=" << lep_itr.get_pt() 
			<< ", eta=" << lep_itr.get_eta()
			<< ", phi=" << lep_itr.get_phi() 
			<< ", baseline=" << lep_itr.get_baseline() 
			<< ", passOR=" << lep_itr.get_passOR() 
			<< ", isSignal=" << lep_itr.get_isSignal()
			<< ", flavor=" << lep_itr.get_flavor() 
			<< ", charge=" << lep_itr.get_charge()
			<< endl;
		i++;
	}
}

void yt_selector::debug_elec_print(vector<Electron> vec_elec)
{
	cout << "*** Event Number=" << EventNumber << endl;
	cout << "NEl=" << vec_elec.size() << endl;
	int i = 0;
	for (auto & el_itr : vec_elec) {
		//cout << "NEl=" << el_itr.get_number() << endl;
		cout << i + 1
			<< ": pt=" << el_itr.get_pt() 
			<< ", eta=" << el_itr.get_eta() << ", etaclus=" << el_itr.get_etaclus() 
			<< ", phi=" << el_itr.get_phi() 
			<< ", baseline=" << el_itr.get_baseline() 
			<< ", passOR=" << el_itr.get_passOR() 
			<< ", isSignal=" << el_itr.get_isSignal()
			<< ", flavor=" << el_itr.get_flavor() 
			<< ", charge=" << el_itr.get_charge()
			<< ", |d0sig|=" << fabs(el_itr.get_sigd0())
			<< ", |z0sinTheta|=" << fabs(el_itr.get_z0sinTheta())
			<< ", ptvarcone20/pt=" << el_itr.get_ptvarcone20() / el_itr.get_pt()
			<< ", topoetcone20/pt=" << el_itr.get_topoetcone20() / el_itr.get_pt()
			<< endl;
		i++;
	}
}

void yt_selector::debug_muon_print(vector<Muon> vec_muon)
{
	cout << "*** Event Number=" << EventNumber << endl;
	cout << "NMu=" << vec_muon.size() << endl;
	int i = 0;
	for (auto & mu_itr : vec_muon) {
		//cout << "NMu=" << mu_itr.get_number() << endl;
		cout << i + 1
			<< ": pt=" << mu_itr.get_pt()
			<< ", eta=" << mu_itr.get_eta()
			<< ", phi=" << mu_itr.get_phi()
			<< ", baseline=" << mu_itr.get_baseline()
			<< ", passOR=" << mu_itr.get_passOR()
			<< ", isSignal=" << mu_itr.get_isSignal()
			<< ", flavor=" << mu_itr.get_flavor()
			<< ", charge=" << mu_itr.get_charge()
			<< ", isBad=" << mu_itr.get_isBad()
			<< ", isCosmic=" << mu_itr.get_isCosmic()
			<< ", |d0sig|=" << fabs(mu_itr.get_sigd0())
			<< ", |z0sinTheta|=" << fabs(mu_itr.get_z0sinTheta())
			<< ", ptvarcone30/pt=" << mu_itr.get_ptvarcone30() / mu_itr.get_pt()
			<< endl;
		i++;
	}
}

void yt_selector::debug_jets_print(vector<Jet> vec_jets)
{
	cout << "*** Event Number=" << EventNumber << endl;
	cout << "NJet=" << vec_jets.size() << endl;
	int i = 0;
	for (auto & jet_itr : vec_jets) {
		//cout << "NJet=" << jet_itr.get_number() << endl;
		cout << i + 1
			<< ": pt=" << jet_itr.get_pt()
			<< ", eta=" << jet_itr.get_eta()
			<< ", phi=" << jet_itr.get_phi()
			<< ", baseline=" << jet_itr.get_baseline()
			<< ", passOR=" << jet_itr.get_passOR()
			<< ", isBjet=" << jet_itr.get_isBjet()
			<< ", quality=" << jet_itr.get_quality()
			<< ", JVT=" << jet_itr.get_JVT()
			<< ", MV2c10=" << jet_itr.get_MV2c10()
			<< endl;
		i++;
	}
}

#endif // #ifdef YT_SELECTOR_CXX
