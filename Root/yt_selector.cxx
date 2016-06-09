#define YT_SELECTOR_CXX
// The class definition in yt_selector.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.

// The following methods are defined in this file:
//    Begin():        called every time a loop on the tree starts,
//                    a convenient place to create your histograms.
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    SlaveTerminate: called at the end of the loop on the tree, when on PROOF
//                    called only on the slave servers.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// root> T->Process("yt_selector.C")
// root> T->Process("yt_selector.C","some options")
// root> T->Process("yt_selector.C+")
//

#include "ytCutflows/yt_selector.h"
#include "Root/Fill_and_Set.cxx"
#include "Root/useful_functions.cxx"

#include <TH2.h>
#include <TStyle.h>

void yt_selector::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

	m_cutflow = new yt_cutflows;
/*
	// GRL
	// Using the information from  http://atlasdqm.web.cern.ch/atlasdqm/grlgen/All_Good/data15_13TeV.periodAllYear_DetStatus-v63-pro18-01_DQDefects-00-01-02_PHYS_StandardGRL_All_Good.xml
	m_GRL = new GoodRunsListSelectionTool("GoodRunsListSelectionTool");
	std::vector<std::string> vecStringGRL;
	vecStringGRL.push_back("/afs/cern.ch/work/y/yushen/private/Ximo/v37/ytCutflows/GRL/data15_13TeV.periodAllYear_DetStatus-v63-pro18-01_DQDefects-00-01-02_PHYS_StandardGRL_All_Good.xml");
	m_GRL->setProperty("GoodRunsListVec", vecStringGRL);
	m_GRL->setProperty("PassThrough", false);
	if ( !m_GRL->initialize().isSuccess() ) {
		Error("In Begin()", "Fail to properly initialize the GRL. Exiting.");
	}
*/
}

void yt_selector::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

Bool_t yt_selector::Process(Long64_t entry)
{
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // It can be passed to either yt_selector::GetEntry() or TBranch::GetEntry()
   // to read either all or the required parts of the data. When processing
   // keyed objects with PROOF, the object is already loaded and is available
   // via the fObject pointer.
   //
   // This function should contain the "body" of the analysis. It can contain
   // simple or elaborate selection criteria, run algorithms on the data
   // of the event and typically fill histograms.
   //
   // The processing can be stopped by calling Abort().
   //
   // Use fStatus to set the return value of TTree::Process().
   //
   // The return value is currently not used.

	if (isData) {
		cout << "This is data." << endl;
	}
	if (isMC) {
		//cout << "This is MC." << endl;
	}

	// Need to call the Process() method of the Parent class
	AnaNtup::Process(entry);

	//HLT_object = new HLT();

	// Reset vectors
	vec_elec.clear();
	vec_muon.clear();
	vec_jets.clear();
	vec_lept.clear();

	vec_OR_elec.clear();
	vec_OR_muon.clear();
	vec_OR_jets.clear();
	vec_OR_lept.clear();

	vec_signal_elec.clear();
	vec_signal_muon.clear();
	vec_signal_jets.clear();
	vec_signal_lept.clear();

/*
	fill_HLT(HLT_e24_lhmedium_nod0_ivarloose,
			 HLT_e24_lhtight_nod0_ivarloose,
			 HLT_e26_lhtight_iloose,
			 HLT_e26_lhtight_ivarloose,
			 HLT_e26_lhtight_nod0_iloose,
			 HLT_e26_lhtight_nod0_ivarloose,
			 HLT_e60_lhmedium,
			 HLT_e60_lhmedium_nod0,
			 HLT_e120_lhloose_nod0,
			 HLT_e140_lhloose_nod0,
			 HLT_2e17_lhvloose_nod0,
			 HLT_2e15_lhvloose_nod0_L12EM13VH,
			 HLT_e24_lhmedium_e9_lhmedium,
			 HLT_e24_lhmedium_L1EM20VH,
			 HLT_e12_lhvloose_L12EM10VH,
			 HLT_e17_lhloose_2e9_lhloose,
			 HLT_mu24_ivarmedium,
			 HLT_mu24_imedium,
			 HLT_mu24_ivarloose,
			 HLT_mu24_iloose,
			 HLT_mu26_ivarmedium,
			 HLT_mu26_imedium,
			 HLT_mu20_ivarmedium_L1MU15,
			 HLT_mu20_imedium_L1MU15,
			 HLT_mu20_ivarloose_L1MU15,
			 HLT_mu20_iloose_L1MU15,
			 HLT_mu20_L1MU15,
			 HLT_mu20_mu8noL1,
			 HLT_mu22_mu8noL1,
			 HLT_mu22_2mu4noL1,
			 HLT_mu40,
			 HLT_mu50,
			 HLT_2mu10,
			 HLT_2mu10_nomucomb,
			 HLT_2mu14,
			 HLT_2mu14_nomucomb,
			 HLT_3mu6,
			 HLT_3mu6_msonly,
			 HLT_xe100_L1XE50,
			 HLT_xe80_mht_L1XE50,
			 HLT_xe90_mht_L1XE50,
			 HLT_xe110_pueta_L1XE50,
			 HLT_xe110_pufit_L1XE50,
			 HLT_xe100_tc_em_L1XE50,
			 HLT_xe80_tc_lcw_L1XE50,
			 HLT_xe90_tc_lcw_L1XE50,
			 HLT_xe80_tc_lcw_wEFMu_L1XE50,
			 HLT_e7_lhmedium_mu24,
			 HLT_e17_lhloose_nod0_mu14,
			 HLT_e26_lhmedium_nod0_L1EM22VHI_mu8noL1,
			 HLT_e24_lhmedium_nod0_L1EM22VHI_mu8noL1,
			 HLT_2e12_lhloose_L12EM10VH,
			 HLT_e17_lhloose_mu14,
			 HLT_mu18_mu8noL1,
			 HLT_xe70);
*/

	fill_electrons(
				NEl,
				11, // particle id e- = 11
				El_eta,
				El_etaclus,
				El_phi,
				El_pT,
				El_E,
				El_charge,
				El_sigd0,
				El_z0sinTheta,
				El_d0pvtx,
				El_passOR,
				El_SFwMediumLH,
				El_IsoSFwTightLH,
				El_SFwTightLH,
				El_SFwLooseAndBLayerLH,
				El_SFwTrigMediumLH_e12_lhloose_L1EM10VH,
				El_SFwTrigTightLH_e12_lhloose_L1EM10VH,
				El_SFwTrigTightLH_e17_lhloose,
				El_SFwTrigTightLH_single,
				El_SFwTrigLooseAndBLayerLH_e12_lhloose_L1EM10VH,
				El_isLooseAndBLayerLH,
				El_isMediumLH,
				El_isTightLH,
				El_nBLayerHits,
				El_expectBLayerHit,
				El_type,
				El_origin,
				El_bkgMotherPdgId,
				El_bkgOrigin,
				El_chFlip,
				El_ptcone20,
				El_ptcone30,
				El_ptcone40,
				El_ptvarcone20,
				El_ptvarcone30,
				El_ptvarcone40,
				El_topoetcone20,
				El_topoetcone30,
				El_topoetcone40,
				El_passIsoLooseTO,
				El_passIsoLoose,
				El_passIsoTight,
				El_passIsoGrad,
				El_passIsoGradCustomTight,
				El_passIsoGradCustom,
				El_passIsoGradLoose,
				El_trigMatch_e12_lhloose_L1EM10VH,
				El_trigMatch_e17_lhloose,
				El_trigMatch_e60_lhmedium,
				El_trigMatch_e24_lhmedium_iloose_L1EM20VH);

	fill_muons(
			NMu,
			13, // particle id mu- = 13
			Mu_eta,
			Mu_phi,
			Mu_pT,
			Mu_SFw,
			Mu_IsoSFw,
			Mu_charge,
			Mu_d0pvtx,
			Mu_sigd0,
			Mu_z0sinTheta,
			Mu_isBad,
			Mu_passOR,
			Mu_isTight,
			Mu_isCosmic,
			Mu_type,
			Mu_origin,
			Mu_ptcone20,
			Mu_ptcone30,
			Mu_ptcone40,
			Mu_ptvarcone20,
			Mu_ptvarcone30,
			Mu_ptvarcone40,
			Mu_topoetcone20,
			Mu_topoetcone30,
			Mu_topoetcone40,
			Mu_passIsoLooseTO,
			Mu_passIsoLoose,
			Mu_passIsoTight,
			Mu_passIsoGrad,
			Mu_passIsoGradCustomTight,
			Mu_passIsoGradCustom,
			Mu_passIsoGradLoose,
			MuTrigSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50,
			Mu_trigMatch_mu26_imedium,
			Mu_trigMatch_mu50,
			Mu_trigMatch_mu18_mu8noL1,
			Mu_trigMatch_mu14,
			Mu_trigMatch_mu18);

	fill_jets(NJet,
			  Jet_eta,
			  Jet_phi,
			  Jet_pT,
			  Jet_E,
			  Jet_quality,
			  Jet_JVT,
			  Jet_JVTsf,
			  Jet_MV2c20,
			  Jet_MV2c10,
			  Jet_SFw,
			  Jet_ConeTruthLabel,
			  Jet_PartonTruthLabel,
			  Jet_HadronConeExclTruthLabel,
			  Jet_deltaR,
			  Jet_nTrk,
			  Jet_passOR);

	// sort by descending Pt
	sort(vec_elec.begin(), vec_elec.end(), sort_descending_Pt<Electron>);
	sort(vec_muon.begin(), vec_muon.end(), sort_descending_Pt<Muon>);
	sort(vec_jets.begin(), vec_jets.end(), sort_descending_Pt<Jet>);

	// Set the baseline for electrons, muons, and jets.
	// Set the isSignal property for electrons and muons and set the isBjet property for jets.
	set_baseline_and_signal_electrons();
	set_baseline_and_signal_muons();
	set_jets_and_bjets();

	// Fill leptons into vector. Put the fill_leptons() function at here then the lepton in the
	// vector has correct baseline, flavor, and isSignal information.
	fill_leptons(vec_elec, vec_muon);
	// Now sort leptons by descending Pt
	sort(vec_lept.begin(), vec_lept.end(), sort_descending_Pt<Lepton>);

	//----------------------------------//
	// Apply cuts
	//----------------------------------//

	// Apply cutflows
	m_cutflow->events_pass_cutflow[DerivationStat_Weights] = 1.988000e+05; // read the first bin from root file.

	bool cut1  = m_cutflow->pass_all_events();
	m_cutflow->update(All_events, cut1);
	if (!cut1) return kTRUE;

	bool cut2  = m_cutflow->pass_GRL(isData, RunNb, LB);
	m_cutflow->update(GRL, cut2);
	if (!cut2) return kTRUE;

	bool cut3  = m_cutflow->pass_primary_vertex(PV_z);
	m_cutflow->update(Primary_vertex, cut3);
	if (!cut3) return kTRUE;

	bool cut4  = m_cutflow->pass_trigger(HLT_2e12_lhloose_L12EM10VH, HLT_e17_lhloose_mu14, HLT_mu18_mu8noL1, HLT_xe70, Etmiss_TST_Et);
	m_cutflow->update(Trigger, cut4);
	if (!cut4) return kTRUE;

	bool cut5  = m_cutflow->pass_global_flags(isData, isMC, DetError, 
											  Etmiss_TST_Et, Etmiss_TST_Etx, Etmiss_TST_Ety, 
											  Etmiss_TSTterm_Et, Etmiss_TSTterm_Etx, Etmiss_TSTterm_Ety);
	m_cutflow->update(Global_flags, cut5);
	if (!cut5) return kTRUE;

	bool cut6  = m_cutflow->pass_bad_muon(vec_muon);
	m_cutflow->update(Bad_muon, cut6);
	if (!cut6) return kTRUE;

	bool cut7  = m_cutflow->pass_at_least_one_jet_passes_jet_OR(vec_jets);
	m_cutflow->update(At_least_one_jet_passes_jet_OR, cut7);
	if (!cut7) return kTRUE;

	bool cut8  = m_cutflow->pass_bad_jet(vec_jets);
	m_cutflow->update(Bad_jet, cut8);
	if (!cut8) return kTRUE;
/*
	if (EventNumber== 7068 || EventNumber== 14462 || EventNumber== 44226 || EventNumber== 46709) {
		cout << "*** Before OR ***" << endl;
		cout << "EvtNumber=" << EventNumber<< endl;
		for (auto & lep_itr : vec_lept) {
			cout << "flavor=" << lep_itr.get_flavor() << endl;
			cout << "pt=" << lep_itr.get_pt() << endl;
			cout << "eta=" << lep_itr.get_eta() << endl;
			cout << "phi=" << lep_itr.get_phi() << endl;
			cout << "baseline=" << lep_itr.get_baseline() << endl;
			cout << "isSignal=" << lep_itr.get_isSignal() << endl;
			cout << "passOR=" << lep_itr.get_passOR() << endl;
			cout << " " << endl;
		}
	}
*/

	// Fill OR electrons, OR muons, OR jets, and OR leptons into vectors.
	fill_baseline_electrons(vec_elec);
	fill_baseline_muons(vec_muon);
	fill_baseline_jets(vec_jets);
	fill_baseline_leptons(vec_elec, vec_muon);
	// Now sort leptons by descending Pt
	sort(vec_OR_lept.begin(), vec_OR_lept.end(), sort_descending_Pt<Lepton>);

/*
	if (EventNumber== 7068 || EventNumber== 14462 || EventNumber== 44226 || EventNumber== 46709) {
		cout << "*** After OR ***" << endl;
		cout << "EvtNumber=" << EventNumber<< endl;
		for (auto & lep_itr : vec_OR_lept) {
			cout << "flavor=" << lep_itr.get_flavor() << endl;
			cout << "pt=" << lep_itr.get_pt() << endl;
			cout << "eta=" << lep_itr.get_eta() << endl;
			cout << "phi=" << lep_itr.get_phi() << endl;
			cout << "baseline=" << lep_itr.get_baseline() << endl;
			cout << "isSignal=" << lep_itr.get_isSignal() << endl;
			cout << "passOR=" << lep_itr.get_passOR() << endl;
			cout << " " << endl;
		}
	}
*/

	// Fill signal electrons, signal muons, signal jets, and signal leptons into vectors.
	fill_signal_electrons(vec_OR_elec);
	fill_signal_muons(vec_OR_muon);
	fill_signal_jets(vec_OR_jets);
	fill_signal_leptons(vec_signal_elec, vec_signal_muon);
	// Now sort leptons by descending Pt
	sort(vec_signal_lept.begin(), vec_signal_lept.end(), sort_descending_Pt<Lepton>);

	bool cut9  = m_cutflow->pass_at_least_one_signal_jet(vec_signal_jets);
	//bool cut9  = m_cutflow->pass_at_least_one_signal_jet(vec_jets);
	m_cutflow->update(At_least_one_signal_jet, cut9);
	if (!cut9) return kTRUE;

	bool cut10 = m_cutflow->pass_cosmic_muon_veto(vec_OR_muon);
	//bool cut10 = m_cutflow->pass_cosmic_muon_veto(vec_muon);
	m_cutflow->update(Cosmic_muons_veto, cut10);
	if (!cut10) return kTRUE;

	bool cut11 = m_cutflow->pass_at_least_two_baseline_leptons_greater_than_10GeV(vec_OR_lept);
	//bool cut11 = m_cutflow->pass_at_least_two_baseline_leptons_greater_than_10GeV(vec_lept);
	m_cutflow->update(At_least_two_baseline_leptons_greater_than_10GeV, cut11);
	if (!cut11) return kTRUE;

	bool cut12 = m_cutflow->pass_at_least_two_signal_leptons_greater_than_20GeV(vec_signal_lept);
	//bool cut12 = m_cutflow->pass_at_least_two_signal_leptons_greater_than_20GeV(vec_lept);
	m_cutflow->update(At_least_two_signal_leptons_greater_than_20GeV, cut12);
	if (!cut12) return kTRUE;

	bool cut13 = m_cutflow->pass_same_sign(vec_signal_lept);
	//bool cut13 = m_cutflow->pass_same_sign(vec_lept);
	m_cutflow->update(Same_sign, cut13);
	if (!cut13) return kTRUE;

	// Save the event number of passed events (for debug)
	vec_event_number.push_back(EventNumber);
/*
	// Fill signal electrons, signal muons, signal jets, and signal leptons into vectors.
	fill_signal_electrons(vec_elec);
	fill_signal_muons(vec_muon);
	fill_signal_jets(vec_jets);
	fill_signal_leptons(vec_signal_elec, vec_signal_muon);
	// Now sort leptons by descending Pt
	sort(vec_signal_lept.begin(), vec_signal_lept.end(), sort_descending_Pt<Lepton>);
*/
	// same-sign
	// e-e
	int ee_cut1 = m_cutflow->pass_channel_separation(EventNumber, vec_event_number, vec_signal_lept);
	if (ee_cut1 == 1)
		m_cutflow->update(ee_channel_separation, true);

	bool ee_cut2 = m_cutflow->pass_trigger_matching();
	if (ee_cut1 == 1 && ee_cut2)
		m_cutflow->update(ee_trigger_matching, ee_cut2);

	bool ee_cut3 = m_cutflow->pass_at_least_one_bjet_greater_than_20GeV(EventNumber, vec_event_number, vec_signal_jets);
	if (ee_cut1 == 1 && ee_cut2 && ee_cut3)
		m_cutflow->update(ee_at_least_one_bjet_greater_than_20GeV, ee_cut3);

	bool ee_cut4 = m_cutflow->pass_four_jets_greater_than_50GeV(EventNumber, vec_event_number, vec_signal_jets);
	if (ee_cut1 == 1 && ee_cut2 && ee_cut3 && ee_cut4)
		m_cutflow->update(ee_four_jets_greater_than_50GeV, ee_cut4);

	bool ee_cut5 = m_cutflow->pass_MET_greater_than_125GeV(Etmiss_TST_Et);
	if (ee_cut1 == 1 && ee_cut2 && ee_cut3 && ee_cut4 && ee_cut5)
		m_cutflow->update(ee_MET_greater_than_125GeV, ee_cut5);
/*
	cout << "el-el channel" << endl;
	debug_lept_print(vec_signal_lept);
*/
	// e-mu
	int emu_cut1 = m_cutflow->pass_channel_separation(EventNumber, vec_event_number, vec_signal_lept);
	if (emu_cut1 == 2)
		m_cutflow->update(emu_channel_separation, emu_cut1);

	bool emu_cut2 = m_cutflow->pass_trigger_matching();
	if (emu_cut1 == 2 && emu_cut2)
		m_cutflow->update(emu_trigger_matching, emu_cut2);

	bool emu_cut3 = m_cutflow->pass_at_least_one_bjet_greater_than_20GeV(EventNumber, vec_event_number, vec_signal_jets);
	if (emu_cut1 == 2 && emu_cut2 && emu_cut3)
		m_cutflow->update(emu_at_least_one_bjet_greater_than_20GeV, emu_cut3);

	bool emu_cut4 = m_cutflow->pass_four_jets_greater_than_50GeV(EventNumber, vec_event_number, vec_signal_jets);
	if (emu_cut1 == 2 && emu_cut2 && emu_cut3 && emu_cut4)
		m_cutflow->update(emu_four_jets_greater_than_50GeV, emu_cut4);

	bool emu_cut5 = m_cutflow->pass_MET_greater_than_125GeV(Etmiss_TST_Et);
	if (emu_cut1 == 2 && emu_cut2 && emu_cut3 && emu_cut4 && emu_cut5)
		m_cutflow->update(emu_MET_greater_than_125GeV, emu_cut5);
/*
	cout << "el-mu channel" << endl;
	debug_lept_print(vec_signal_lept);
*/
	// mu-mu
	int mumu_cut1 = m_cutflow->pass_channel_separation(EventNumber, vec_event_number, vec_signal_lept);
	if (mumu_cut1 == 3)
		m_cutflow->update(mumu_channel_separation, mumu_cut1);

	bool mumu_cut2 = m_cutflow->pass_trigger_matching();
	if (mumu_cut1 == 3 && mumu_cut2)
		m_cutflow->update(mumu_trigger_matching, mumu_cut2);

	bool mumu_cut3 = m_cutflow->pass_at_least_one_bjet_greater_than_20GeV(EventNumber, vec_event_number, vec_signal_jets);
	if (mumu_cut1 == 3 && mumu_cut2 && mumu_cut3)
		m_cutflow->update(mumu_at_least_one_bjet_greater_than_20GeV, mumu_cut3);

	bool mumu_cut4 = m_cutflow->pass_four_jets_greater_than_50GeV(EventNumber, vec_event_number, vec_signal_jets);
	if (mumu_cut1 == 3 && mumu_cut2 && mumu_cut3 && mumu_cut4)
		m_cutflow->update(mumu_four_jets_greater_than_50GeV, mumu_cut4);

	bool mumu_cut5 = m_cutflow->pass_MET_greater_than_125GeV(Etmiss_TST_Et);
	if (mumu_cut1 == 3 && mumu_cut2 && mumu_cut3 && mumu_cut4 && mumu_cut5)
		m_cutflow->update(mumu_MET_greater_than_125GeV, mumu_cut5);
/*
	cout << "mu-mu channel" << endl;
	debug_lept_print(vec_signal_lept);
*/
   return kTRUE;
}

void yt_selector::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void yt_selector::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.
	//delete HLT_object;
	//delete m_GRL;
	m_cutflow->print();
	delete m_cutflow;
}
