#define YT_CUTFLOWS_CXX
#include "ytCutflows/yt_cutflows.h"

const char* cut_name[] = {
	"Cut 0: All events before derivations (DerivationStat_Weights)",
	"Cut 1: All events in derivation/ntuple",
	"Cut 2: GRL (for data only)",
	"Cut 3: Primary vertex",
	"Cut 4: Trigger",
	"Cut 5: Global flags (data only) (+ MET cleaning in data & MC)",
	"Cut 6: Bad muon",
	"Cut 7: >= 1 jet passes jet OR",
	"Cut 8: Bad jet",
	"Cut 9: >= 1 signal jet",
	"Cut 10: Cosmic muons veto",
	"Cut 11: >= 2 baseline leptons > 10 GeV",
	"Cut 12: >= 2 signal leptons > 20 GeV",
	"Cut 13: Same sign",
	// El-El channel
	"Cut 14: Channel seperation, same-sign [20, 20]: (el-el)",
	"Cut 15: Trigger matching: (el-el)",
	"Cut 16: >= 1 bjet > 20 GeV: (el-el)",
	"Cut 17: 4 jets > 50 GeV: (el-el)",
	"Cut 18: MET > 125 GeV: (el-el)",
	// El-Mu channel
	"Cut 14: Channel seperation, same-sign [20, 20]: (el-mu)",
	"Cut 15: Trigger matching: (el-mu)",
	"Cut 16: >= 1 bjet > 20 GeV: (el-mu)",
	"Cut 17: 4 jets > 50 GeV: (el-mu)",
	"Cut 18: MET > 125 GeV: (el-mu)",
	// Mu-Mu channel
	"Cut 14: Channel seperation, same-sign [20, 20]: (mu-mu)",
	"Cut 15: Trigger matching: (mu-mu)",
	"Cut 16: >= 1 bjet > 20 GeV: (mu-mu)",
	"Cut 17: 4 jets > 50 GeV: (mu-mu)",
	"Cut 18: MET > 125 GeV: (mu-mu)",
};

yt_cutflows::yt_cutflows()
{
	// GRL
	// Using the information from  http://atlasdqm.web.cern.ch/atlasdqm/grlgen/All_Good/data15_13TeV.periodAllYear_DetStatus-v63-pro18-01_DQDefects-00-01-02_PHYS_StandardGRL_All_Good.xml
	m_GRL = new GoodRunsListSelectionTool("GoodRunsListSelectionTool");
	std::vector<std::string> vecStringGRL;
	vecStringGRL.push_back("/afs/cern.ch/work/y/yushen/private/Ximo/v39/ytCutflows/GRL/data15_13TeV.periodAllYear_DetStatus-v79-repro20-02_DQDefects-00-02-02_PHYS_StandardGRL_All_Good_25ns.xml");
	vecStringGRL.push_back("/afs/cern.ch/work/y/yushen/private/Ximo/v39/ytCutflows/GRL/data16_13TeV.periodAllYear_DetStatus-v78-pro20-04_DQDefects-00-02-02_PHYS_StandardGRL_All_Good_25ns.xml");
	//vecStringGRL.push_back("/afs/cern.ch/work/y/yushen/private/Ximo/v39/ytCutflows/GRL/data16_13TeV.periodAllYear_DetStatus-v79-pro20-05_DQDefects-00-02-02_PHYS_StandardGRL_All_Good_25ns.xml");
	m_GRL->setProperty("GoodRunsListVec", vecStringGRL);
	m_GRL->setProperty("PassThrough", false);
	if ( !m_GRL->initialize().isSuccess() ) {
		Error("In Begin()", "Fail to properly initialize the GRL. Exiting.");
	}

	// PRW files for mc15c
	m_Pileup  = new CP::PileupReweightingTool("Pileup");
	confFiles.push_back("/cvmfs/atlas.cern.ch/repo/sw/database/GroupData/dev/SUSYTools/merged_prw_mc15c.root");
	// iLumiCalc file can be obtained with the lates GRL in https://atlas-lumicalc.cern.ch/
	lcalcFiles.push_back("/afs/cern.ch/work/y/yushen/private/Ximo/v39/ytCutflows/PRW/ilumicalc_histograms_None_276262-284484.root");
	lcalcFiles.push_back("/afs/cern.ch/work/y/yushen/private/Ximo/v39/ytCutflows/PRW/ilumicalc_histograms_None_297730-300908.root");
	//lcalcFiles.push_back("/afs/cern.ch/work/y/yushen/private/Ximo/v39/ytCutflows/PRW/ilumicalc_histograms_None_297730-301973.root");
	// or alternatively use a merged file from 
	// https://svnweb.cern.ch/trac/atlasphys-susy/browser/Physics/SUSY/Analyses/SameSignLeptonsJets/tags/SameSignLeptonsJets-00-00-21/Ntuples_NoSyst/SS3LAnalysis/data/ds1_2015.root
	m_Pileup->setProperty("ConfigFiles", confFiles);
	m_Pileup->setProperty("DefaultChannel", 410000);
	m_Pileup->setProperty("LumiCalcFiles", lcalcFiles);
	// NEW: recommended mu re-scaling values 
	m_Pileup->setProperty("DataScaleFactor", 1.0 / 1.16);
	m_Pileup->setProperty("DataScaleFactorUP", 1.0 / 1.0);
	m_Pileup->setProperty("DataScaleFactorDOWN", 1.0 / 1.23);
	if ( !m_Pileup->initialize().isSuccess() ) {
		Error("In Begin()", "Fail to properly initialize the PRW. Exiting.");	
	}

	// Dummy EventInfo object to manipulate later
	eInfos = new xAOD::EventInfoContainer();
	eInfos->setStore(new xAOD::EventInfoAuxContainer());
	eInfos->push_back(new xAOD::EventInfo());
	eventInfo = eInfos->at(0);

	// initialize events_pass_cutflow to zero
	events_pass_cutflow = vector<int>(Ncuts, 0); // initialize Ncuts elements to zero.
}

yt_cutflows::~yt_cutflows()
{
	delete m_GRL;
	delete m_Pileup;
	//delete eventInfo;
	delete eInfos;
}

void yt_cutflows::update(int cut, bool passed)
{
	if (passed)
		events_pass_cutflow[cut] += 1;
}

void yt_cutflows::print()
{
	cout << "**************************************************" << endl;
	for (int cuts = 0; cuts < Ncuts; cuts++) {
		//if (cuts == 14) {
		if (cuts == ee_channel_separation) {
			cout << "***** El-El channel *****" << endl;
			cout << setw(20) << left << cut_name[cuts]  << " = " << setw(10) << events_pass_cutflow[cuts] << endl;
		}
		//else if (cuts == 19) {
		else if (cuts == emu_channel_separation) {
			cout << "***** El-Mu channel *****" << endl;
			cout << setw(20) << left << cut_name[cuts]  << " = " << setw(10) << events_pass_cutflow[cuts] << endl;
		}
		//else if (cuts == 24) {
		else if (cuts == mumu_channel_separation) {
			cout << "***** Mu-Mu channel *****" << endl;
			cout << setw(20) << left << cut_name[cuts]  << " = " << setw(10) << events_pass_cutflow[cuts] << endl;
		}
		else {
			cout << setw(20) << left << cut_name[cuts]  << " = " << setw(10) << events_pass_cutflow[cuts] << endl;
		}
	}
/*
	cout << setw(20) << left << cut_name[0]  << " = " << setw(10) << events_pass_cutflow[0] << endl;
	cout << setw(20) << left << cut_name[1]  << " = " << setw(10) << events_pass_cutflow[1] << endl;
	cout << setw(20) << left << cut_name[2]  << " = " << setw(10) << events_pass_cutflow[2] << endl;
	cout << setw(20) << left << cut_name[3]  << " = " << setw(10) << events_pass_cutflow[3] << endl;
	cout << setw(20) << left << cut_name[4]  << " = " << setw(10) << events_pass_cutflow[4] << endl;
	cout << setw(20) << left << cut_name[5]  << " = " << setw(10) << events_pass_cutflow[5] << endl;
	cout << setw(20) << left << cut_name[6]  << " = " << setw(10) << events_pass_cutflow[6] << endl;
	cout << setw(20) << left << cut_name[7]  << " = " << setw(10) << events_pass_cutflow[7] << endl;
	cout << setw(20) << left << cut_name[8]  << " = " << setw(10) << events_pass_cutflow[8] << endl;
	cout << setw(20) << left << cut_name[9]  << " = " << setw(10) << events_pass_cutflow[9] << endl;
	cout << setw(20) << left << cut_name[10] << " = " << setw(10) << events_pass_cutflow[10] << endl;
	cout << setw(20) << left << cut_name[11] << " = " << setw(10) << events_pass_cutflow[11] << endl;
	cout << setw(20) << left << cut_name[12] << " = " << setw(10) << events_pass_cutflow[12] << endl;
	// El-El channel
	cout << "***** El-El channel *****" << endl;
	cout << setw(20) << left << cut_name[13] << " = " << setw(10) << events_pass_cutflow[13] << endl;
	cout << setw(20) << left << cut_name[14] << " = " << setw(10) << events_pass_cutflow[14] << endl;
	cout << setw(20) << left << cut_name[15] << " = " << setw(10) << events_pass_cutflow[15] << endl;
	cout << setw(20) << left << cut_name[16] << " = " << setw(10) << events_pass_cutflow[16] << endl;
	cout << setw(20) << left << cut_name[17] << " = " << setw(10) << events_pass_cutflow[17] << endl;
	// El-Mu channel
	cout << "***** El-Mu channel *****" << endl;
	cout << setw(20) << left << cut_name[18] << " = " << setw(10) << events_pass_cutflow[18] << endl;
	cout << setw(20) << left << cut_name[19] << " = " << setw(10) << events_pass_cutflow[19] << endl;
	cout << setw(20) << left << cut_name[20] << " = " << setw(10) << events_pass_cutflow[20] << endl;
	cout << setw(20) << left << cut_name[21] << " = " << setw(10) << events_pass_cutflow[21] << endl;
	cout << setw(20) << left << cut_name[22] << " = " << setw(10) << events_pass_cutflow[22] << endl;
	// Mu-Mu channel
	cout << "***** Mu-Mu channel *****" << endl;
	cout << setw(20) << left << cut_name[23] << " = " << setw(10) << events_pass_cutflow[23] << endl;
	cout << setw(20) << left << cut_name[24] << " = " << setw(10) << events_pass_cutflow[24] << endl;
	cout << setw(20) << left << cut_name[25] << " = " << setw(10) << events_pass_cutflow[25] << endl;
	cout << setw(20) << left << cut_name[26] << " = " << setw(10) << events_pass_cutflow[26] << endl;
	cout << setw(20) << left << cut_name[27] << " = " << setw(10) << events_pass_cutflow[27] << endl;
*/
	cout << "**************************************************" << endl;
}

int yt_cutflows::get_mc_random_event_number(int isData, int isMC,
											int event_number, int channel_number,
											double average_mu, double event_weight, double PRW_weight,
											int lumi_block, int run_number)
{
	// Put the ntuple variables into EventInfo
	eventInfo->setMCChannelNumber(channel_number);
	// Need to tell ifdata or MC is used!
	if (isMC) {
		// xAOD::EventInfo::IS_SIMULATION
		eventInfo->setEventTypeBitmask(xAOD::EventInfo::IS_SIMULATION);
	}
	else if (isData) {
		eventInfo->setEventTypeBitmask(0x0);
	}
	eventInfo->setAverageInteractionsPerCrossing(average_mu);
	eventInfo->setMCEventNumber(event_number);
	eventInfo->setEventNumber(event_number);
	eventInfo->setRunNumber(run_number);
	eventInfo->setLumiBlock(lumi_block);
	vector<float> weight;
	weight.clear();
	weight.push_back(event_weight);
	eventInfo->setMCEventWeights(weight);

	// NEW: nominal case
	CP::SystematicSet defaultSet;
	m_Pileup->applySystematicVariation(defaultSet);
	// produces a decoration in Eventinfo
	bool mu_dependent = true;
	m_Pileup->apply(*eventInfo, mu_dependent);
	// example to retrieve decoration:
	float pileupwgh = eventInfo->auxdata<float>("PileupWeight");
/*
	// NEW: Systematic Variations
	// DOWN
	CP::SystematicSet downSet;
	downSet.insert(CP::SystematicVariation ("PRW_DATASF", -1));
	m_Pileup->applySystematicVariation(downSet);
	m_Pileup->apply(*eventInfo);
	average_mu = eventInfo->auxdata<float>("corrected_averageInteractionsPerCrossing");
	double pileupwghDOWN = eventInfo->auxdata<double>("PileupWeight");

	// UP
	CP::SystematicSet upSet;
	upSet.insert(CP::SystematicVariation ("PRW_DATASF", 1));
	m_Pileup->applySystematicVariation(upSet);
	m_Pileup->apply(*eventInfo);
	average_mu = eventInfo->auxdata<float>("corrected_averageInteractionsPerCrossing");
	double pileupwghUP = eventInfo->auxdata<double>("PileupWeight");
*/
	unsigned int random_run_number = eventInfo->auxdata<unsigned int>("RandomRunNumber");
	//cout << "random_run_number=" << random_run_number << endl;

	return static_cast<int>(random_run_number);
}

bool yt_cutflows::pass_all_events()
{
	return true;
}

bool yt_cutflows::pass_GRL(int isData, int RunNb, int LB)
{
	bool pass = false;
	if (isData == 1) {// GRL for data only
		if (m_GRL->passRunLB(RunNb, LB)) pass = true;
	}
	else {// MC
		pass = true;
	}
	return pass;
}

bool yt_cutflows::pass_primary_vertex(float PV_z)
{
	bool pass = false;
	// In common ntuples: PV_z>-999 (-999 is the default value if no PV is found in the event).
	// In SUSYTools: GetPrimVtx() method
	if (PV_z > -999) pass = true; 
	return pass;
}

bool yt_cutflows::pass_2015_trigger(bool HLT_2e12_lhloose_L12EM10VH, bool HLT_e17_lhloose_mu14, bool HLT_mu18_mu8noL1, bool HLT_xe70, float Etmiss_TST_Et)
{
	bool pass = false;
	if (HLT_2e12_lhloose_L12EM10VH ||
		HLT_e17_lhloose_mu14 ||
		HLT_mu18_mu8noL1)
		pass = true;
	if (HLT_xe70 && Etmiss_TST_Et > 250000.) // only for MET > 250 GeV
		pass = true;
	return pass;
}

bool yt_cutflows::pass_2016_trigger(bool HLT_2e17_lhvloose_nod0, bool HLT_e17_lhloose_nod0_mu14, bool HLT_mu20_mu8noL1, bool HLT_xe80_tc_lcw_L1XE50, float Etmiss_TST_Et)
{
	bool pass = false;
	if (HLT_2e17_lhvloose_nod0 ||
		HLT_e17_lhloose_nod0_mu14 ||
		HLT_mu20_mu8noL1)
		pass = true;
	if (HLT_xe80_tc_lcw_L1XE50 && Etmiss_TST_Et > 250000.) // only for MET > 250 GeV
		pass = true;
	return pass;
}

bool yt_cutflows::pass_trigger(int isData, int isMC, int run_number, int random_run_number,
							   bool HLT_2e12_lhloose_L12EM10VH, bool HLT_e17_lhloose_mu14, bool HLT_mu18_mu8noL1, bool HLT_xe70,
					  		   bool HLT_2e17_lhvloose_nod0, bool HLT_e17_lhloose_nod0_mu14, bool HLT_mu20_mu8noL1, bool HLT_xe80_tc_lcw_L1XE50,
							   float Etmiss_TST_Et)
{
	bool pass = false;
	if (isData == 1) {
		if (run_number < 290000) pass = pass_2015_trigger(HLT_2e12_lhloose_L12EM10VH, HLT_e17_lhloose_mu14, HLT_mu18_mu8noL1, HLT_xe70, Etmiss_TST_Et);
		if (run_number > 290000) pass = pass_2016_trigger(HLT_2e17_lhvloose_nod0, HLT_e17_lhloose_nod0_mu14, HLT_mu20_mu8noL1, HLT_xe80_tc_lcw_L1XE50, Etmiss_TST_Et);
	}
	if (isMC == 1) {
		if (random_run_number < 290000) pass = pass_2015_trigger(HLT_2e12_lhloose_L12EM10VH, HLT_e17_lhloose_mu14, HLT_mu18_mu8noL1, HLT_xe70, Etmiss_TST_Et);
		if (random_run_number > 290000) pass = pass_2016_trigger(HLT_2e17_lhvloose_nod0, HLT_e17_lhloose_nod0_mu14, HLT_mu20_mu8noL1, HLT_xe80_tc_lcw_L1XE50, Etmiss_TST_Et);
	}
	return pass;
}
/*
bool yt_cutflows::pass_global_flags(int isData, int isMC, int DetError, 
									float Etmiss_TST_Et, float Etmiss_TST_Etx, float Etmiss_TST_Ety,
									float Etmiss_TSTterm_Et, float Etmiss_TSTterm_Etx, float Etmiss_TSTterm_Ety)
*/
bool yt_cutflows::pass_global_flags(int isData, int isMC, int DetError)
{
	//bool pass = false;
	bool pass_DetError = false;
	//bool pass_MET_cleaning = true;
	if (isData == 1) {
		if (DetError > 0) // global flags apply on data only
			pass_DetError = true;
	}
	else if (isMC == 1) {
		pass_DetError = true; // MC always true
	}

	return pass_DetError;
/*
	// atan(): Returns the principal value of the arc tangent of x, expressed in radians.
	// atan2(): Returns the principal value of the arc tangent of y/x, expressed in radians.
	double phi_TSTterm = atan2(Etmiss_TSTterm_Ety, Etmiss_TSTterm_Etx);
	double phi_TST = atan2(Etmiss_TST_Ety, Etmiss_TST_Etx);
	double delta_phi = fabs(phi_TSTterm - phi_TST);
	if(delta_phi > TMath::Pi()) delta_phi = fabs(2*TMath::Pi() - delta_phi);
	// Cleaning for MET TST bug (veto this kind of events)
	if (Etmiss_TSTterm_Et > 100000. && 
		Etmiss_TSTterm_Et / Etmiss_TST_Et > 0.4 &&
		delta_phi < 0.8)
		pass_MET_cleaning = false;

	if (pass_DetError && pass_MET_cleaning)
		pass = true;

	return pass;
*/
}

bool yt_cutflows::pass_bad_muon(vector<Muon> vec_muon)
{
	// veto any event where a baseline muon BEFORE overlap removal
	bool pass = true; // Assume all of the muons are good.
	// Try to find bad muon. If there is a bad muon, then we don't want to keep this event.
    for (auto & mu_itr : vec_muon) {
        if (mu_itr.get_isBad())
			return false; // Bad muon is found.
    }
	return pass;
}

bool yt_cutflows::pass_at_least_one_jet_passes_jet_OR(vector<Jet> vec_jets)
{
	bool pass = false; // Assume all of the jets don't pass OR.
	int count = 0;
	// Is there at least one jet pass OR? If yes, then we want to keep this event.
	for (auto & jet_itr : vec_jets) {
		if (jet_itr.get_passOR())
			count++;
	}
	if (count >= 1)
		pass = true;
	return pass;
}

bool yt_cutflows::pass_bad_jet(vector<Jet> vec_jets)
{
	bool pass = true; // Assume all of the jets are good
	// Try to find bad jets. If there is a bad jet, then we don't want this event.
	for (auto & jet_itr : vec_jets) {
		// Any event which contains such a bad jet (no eta restriction) after the complete overlap removal procedure (e-jet, muon-jet) should be vetoed (Note: no JVT applied at this step!) 
		if (jet_itr.get_pt() > 20000. && // we use vec_jets at this step, so we have to apply pt cut on the jet objects but we don't apply eta cut.
			jet_itr.get_passOR() && 
			jet_itr.get_quality() > 0.5) {// 1=bad jet from SUSYTools IsGoodJet
			//jet_itr.set_baseline(0);
			return false; // Bad jet is found.
		}
	}
	return pass;
}

bool yt_cutflows::pass_at_least_one_signal_jet(vector<Jet> vec_jets)
{
	bool pass = false;
	int count = 0;
	for (auto & jet_itr : vec_jets) {
		if (jet_itr.get_baseline() &&
			jet_itr.get_passOR() &&
			jet_itr.get_quality() < 0.5) {
			count++;
		}
	}
	if (count >= 1)
		pass = true;

	return pass;
}

bool yt_cutflows::pass_cosmic_muon_veto(vector<Muon> vec_muon)
{
	// these cuts should be applied AFTER overlap removal
	bool pass = true; // Assume all of the muons are not cosmic muons
	for (auto & mu_itr : vec_muon) {
		if (mu_itr.get_baseline() &&
			mu_itr.get_passOR() &&
			mu_itr.get_isCosmic()) {
			return false; // Cosmic muon is found.
		}
	}
	return pass;
}

bool yt_cutflows::pass_at_least_two_baseline_leptons_greater_than_10GeV(vector<Lepton> vec_lept)
{
	bool pass = false;
	int count = 0;
	for (auto & lep_itr : vec_lept) {
		if (lep_itr.get_baseline() &&
			lep_itr.get_passOR() &&
			lep_itr.get_pt() > 10000)
			count++;
	}
	if (count >= 2)
		pass = true;

	return pass;
}

bool yt_cutflows::pass_at_least_two_signal_leptons_greater_than_20GeV(vector<Lepton> vec_lept)
{
	bool pass = false;
	int count = 0;
	for (auto & lep_itr : vec_lept) {
		if (lep_itr.get_baseline() &&
			lep_itr.get_passOR() &&
			lep_itr.get_isSignal() &&
			lep_itr.get_pt() > 20000)
			count++;
	}
	if (count >= 2)
		pass = true;

	return pass;
}

bool yt_cutflows::pass_same_sign(vector<Lepton> vec_lept)
{
	bool pass = false;

	if (vec_lept.size() >= 3) {
		pass = true;
	}
	else if (vec_lept.size() == 2) {
		int sign = vec_lept[0].get_charge() * vec_lept[1].get_charge(); 
		if (sign == 1)
			pass = true;
	}
/*
	vector<Lepton> signal_lepton; 
	for (auto & lep_itr : vec_lept) {
		if (lep_itr.get_baseline() &&
			lep_itr.get_passOR() &&
			lep_itr.get_isSignal()) { // all the leptons must satisfy these requirements.
			signal_lepton.push_back(lep_itr);
		}
	}
	if (signal_lepton.size() >= 3) {
		pass = true;
	}
	else if (signal_lepton.size() == 2) {
		int sign = signal_lepton[0].get_charge() * signal_lepton[1].get_charge();
		if (sign == 1)
			pass = true;
	}
*/
	return pass;
}

int yt_cutflows::pass_channel_separation(int event_number, vector<int> vec_event_number, vector<Lepton> vec_lept)
{
	int channel = 0;
	int number_of_lepton = vec_lept.size();
	//cout << "number of lepton=" << number_of_lepton << endl;
	// Because the signal lepton vector was filled earilier, we have to add a protection to make sure we don't use the rejected events.
	if (find(vec_event_number.begin(), vec_event_number.end(), event_number) != vec_event_number.end()) {
/*
		cout << "number of lepton=" << number_of_lepton << endl;
		cout << "*** EventNumber=" << event_number << endl;
		for (unsigned int i = 0; i < vec_lept.size(); i++) {
			cout << i << ": charge=" << vec_lept[i].get_charge() 
					  << ", flavor=" << vec_lept[i].get_flavor() 
					  << ", pt=" << vec_lept[i].get_pt() << endl;
		}
*/
		if (number_of_lepton == 2) {
			//cout << "number of lepton=" << number_of_lepton << endl;
			int charge_1 = vec_lept[0].get_charge();
			int charge_2 = vec_lept[1].get_charge();
			int flavor_1 = vec_lept[0].get_flavor();
			int flavor_2 = vec_lept[1].get_flavor();
			double pt_1 = vec_lept[0].get_pt();
			double pt_2 = vec_lept[1].get_pt();
			//if (charge_1 * charge_2 == 1 && pt_1 > 20000. && pt_2 > 20000.) {
			if (charge_1 * charge_2 == 1) {
				if (flavor_1 * flavor_2 == 121) { // El-El channel
					channel = 1;
					//cout << "channel=" << channel << endl;
					return channel;
				}
				else if (flavor_1 * flavor_2 == 143) { // El-Mu channel
					channel = 2;
					//cout << "channel=" << channel << endl;
					return channel;
				}
				else if (flavor_1 * flavor_2 == 169) { // Mu-Mu channel
					channel = 3;
					//cout << "channel=" << channel << endl;
					return channel;
				}
			}
			else {
				channel = 0;
				//cout << "channel=" << channel << endl;
				return channel;
			}
		}
		else if (number_of_lepton == 3) {
/*
			//cout << "number of lepton=" << number_of_lepton << endl;
			int charge_1 = vec_lept[0].get_charge();
			int charge_2 = vec_lept[1].get_charge();
			int charge_3 = vec_lept[2].get_charge();
			int flavor_1 = vec_lept[0].get_flavor();
			int flavor_2 = vec_lept[1].get_flavor();
			int flavor_3 = vec_lept[2].get_flavor();
			double pt_1 = vec_lept[0].get_pt();
			double pt_2 = vec_lept[1].get_pt();
			double pt_3 = vec_lept[2].get_pt();
			if (charge_1 * charge_2 == 1 && pt_1 > 20000. && pt_2 > 20000.) {
				//cout << "1: charge_1=" << charge_1 << ", flavor_1=" << flavor_1 << ", pt_1=" << pt_1 << endl;
				//cout << "2: charge_2=" << charge_2 << ", flavor_2=" << flavor_2 << ", pt_2=" << pt_2 << endl;
				if (flavor_1 * flavor_2 == 121) {
					//cout << "This is 121" << endl;
					channel = 1;
					//cout << "channel=" << channel << endl;
					return channel;
				}
				else if (flavor_1 * flavor_2 == 143) {
					//cout << "This is 143" << endl;
					channel = 2;
					//cout << "channel=" << channel << endl;
					return channel;
				}
				else if (flavor_1 * flavor_2 == 169) {
					//cout << "This is 169" << endl;
					channel = 3;
					//cout << "channel=" << channel << endl;
					return channel;
				}
			}
			else if (charge_1 * charge_3 == 1 && pt_1 > 20000. && pt_3 > 20000.) {
				//cout << "1: charge_1=" << charge_1 << ", flavor_1=" << flavor_1 << ", pt_1=" << pt_1 << endl;
				//cout << "3: charge_3=" << charge_3 << ", flavor_3=" << flavor_3 << ", pt_3=" << pt_3 << endl;
				if (flavor_1 * flavor_3 == 121) {
					//cout << "This is 121" << endl;
					channel = 1;
					//cout << "channel=" << channel << endl;
					return channel;
				}
				else if (flavor_1 * flavor_3 == 143) {
					//cout << "This is 143" << endl;
					channel = 2;
					//cout << "channel=" << channel << endl;
					return channel;
				}
				else if (flavor_1 * flavor_3 == 169) {
					//cout << "This is 169" << endl;
					channel = 3;
					//cout << "channel=" << channel << endl;
					return channel;
				}
			}
			else if (charge_2 * charge_3 == 1 && pt_2 > 20000. && pt_3 > 20000.) {
				//cout << "2: charge_2=" << charge_2 << ", flavor_2=" << flavor_2 << ", pt_2=" << pt_2 << endl;
				//cout << "3: charge_3=" << charge_3 << ", flavor_3=" << flavor_3 << ", pt_3=" << pt_3 << endl;
				if (flavor_2 * flavor_3 == 121) {
					//cout << "This is 121" << endl;
					channel = 1;
					//cout << "channel=" << channel << endl;
					return channel;
				}
				else if (flavor_2 * flavor_3 == 143) {
					//cout << "This is 143" << endl;
					channel = 2;
					//cout << "channel=" << channel << endl;
					return channel;
				}
				else if (flavor_2 * flavor_3 == 169) {
					//cout << "This is 169" << endl;
					channel = 3;
					//cout << "channel=" << channel << endl;
					return channel;
				}
			}
			else {
				channel = 4;
				//cout << "channel=" << channel << endl;
				return channel;
			}
*/
			for (unsigned int i = 0; i < vec_lept.size()-1; i++) {
				for (unsigned int j = i + 1; j < vec_lept.size(); j++) {
					int charge_i = vec_lept[i].get_charge();
					int charge_j = vec_lept[j].get_charge();
					int flavor_i = vec_lept[i].get_flavor();
					int flavor_j = vec_lept[j].get_flavor();
					double pt_i = vec_lept[i].get_pt();
					double pt_j = vec_lept[j].get_pt();
					//cout << "i: charge_i=" << charge_i << ", flavor_i=" << flavor_i << ", pt_i=" << pt_i << endl;
					//cout << "j: charge_j=" << charge_j << ", flavor_j=" << flavor_j << ", pt_j=" << pt_j << endl;
					//if (charge_i * charge_j == 1 && pt_i > 20000. && pt_j > 20000.) {
					if (charge_i * charge_j == 1) {
						if (flavor_i * flavor_j == 121) {
							//cout << "This is 121" << endl;
							channel = 1;
							//cout << "channel=" << channel << endl;
							return channel;
						}
						else if (flavor_i * flavor_j == 143) {
							//cout << "This is 143" << endl;
							channel = 2;
							//cout << "channel=" << channel << endl;
							return channel;
						}
						else if (flavor_i * flavor_j == 169) {
							//cout << "This is 169" << endl;
							channel = 3;
							//cout << "channel=" << channel << endl;
							return channel;
						}
						else {
							//cout << "The flavor_i * flavor_j=" << flavor_i * flavor_j << endl;
							channel = 4; // Set a number for debuging
							//cout << "channel=" << channel << endl;
							return channel;
						}
					}
					else {
						channel = 5; // Set a number for debuging
						//cout << "The charge_i * charge_j=" << charge_i * charge_j << endl;
						//cout << "The pt_i * pt_j=" << pt_i * pt_j << endl;
						//cout << "channel=" << channel << endl;
						//return channel; // Don't return here. Otherwise this causes errors.
					}
				}
			}
		}
		else if (number_of_lepton > 3) {
			//cout << "number of lepton=" << number_of_lepton << endl;
			//cout << "number of lepton>3, it is " << number_of_lepton << endl;
			for (unsigned int i = 0; i < vec_lept.size()-1; i++) {
				for (unsigned int j = i + 1; j < vec_lept.size(); j++) {
					int charge_i = vec_lept[i].get_charge();
					int charge_j = vec_lept[j].get_charge();
					int flavor_i = vec_lept[i].get_flavor();
					int flavor_j = vec_lept[j].get_flavor();
					double pt_i = vec_lept[i].get_pt();
					double pt_j = vec_lept[j].get_pt();
					//cout << "i: charge_i=" << charge_i << ", flavor_i=" << flavor_i << ", pt_i=" << pt_i << endl;
					//cout << "j: charge_j=" << charge_j << ", flavor_j=" << flavor_j << ", pt_j=" << pt_j << endl;
					//if (charge_i * charge_j == 1 && pt_i > 20000. && pt_j > 20000.) {
					if (charge_i * charge_j == 1) {
						if (flavor_i * flavor_j == 121) {
							//cout << "This is 121" << endl;
							channel = 1;
							//cout << "channel=" << channel << endl;
							return channel;
						}
						else if (flavor_i * flavor_j == 143) {
							//cout << "This is 143" << endl;
							channel = 2;
							//cout << "channel=" << channel << endl;
							return channel;
						}
						else if (flavor_i * flavor_j == 169) {
							//cout << "This is 169" << endl;
							channel = 3;
							//cout << "channel=" << channel << endl;
							return channel;
						}
						else {
							//cout << "The flavor_i * flavor_j=" << flavor_i * flavor_j << endl;
							channel = 4; // Set a number for debuging
							//cout << "channel=" << channel << endl;
							return channel;
						}
					}
					else {
						channel = 5; // Set a number for debuging
						//cout << "The charge_i * charge_j=" << charge_i * charge_j << endl;
						//cout << "The pt_i * pt_j=" << pt_i * pt_j << endl;
						//cout << "channel=" << channel << endl;
						//return channel; // Don't return here. Otherwise this causes errors.
					}
				}
			}
		}
	}
	else {
		cout << "Something wrong... Event Number=" << event_number << " has been rejected before this channel selection cut." << endl;
		return 0;
	}

	return 0; // Don't need this line. Adding this line to avoid compiler to complain.
}

bool yt_cutflows::pass_ee_2015_trigger_matching()
{
	bool pass = false;
	cout << "pass_ee_2015_trigger_matching" << endl;	
	return pass;
}

bool yt_cutflows::pass_ee_2016_trigger_matching()
{
	bool pass = false;
	cout << "pass_ee_2016_trigger_matching" << endl;	
	return pass;
}

bool yt_cutflows::pass_emu_2015_trigger_matching()
{
	bool pass = false;
	cout << "pass_emu_2015_trigger_matching" << endl;
	return pass;
}

bool yt_cutflows::pass_emu_2016_trigger_matching()
{
	bool pass = false;
	cout << "pass_emu_2016_trigger_matching" << endl;
	return pass;
}

bool yt_cutflows::pass_mumu_2015_trigger_matching()
{
	bool pass = false;
	cout << "pass_mumu_2015_trigger_matching" << endl;
	return pass;
}

bool yt_cutflows::pass_mumu_2016_trigger_matching()
{
	bool pass = false;
	cout << "pass_mumu_2016_trigger_matching" << endl;
	return pass;
}

bool yt_cutflows::pass_trigger_matching(string channel, int isData, int isMC, int run_number, int random_run_number)
{
	bool pass = false;
	if (channel == "ee") {
		if (isData == 1) {
			if (run_number < 290000) pass = pass_ee_2015_trigger_matching();
			if (run_number > 290000) pass = pass_ee_2016_trigger_matching();
		}
		else if (isMC == 1) {
			if (random_run_number < 290000) pass = pass_ee_2015_trigger_matching();
			if (random_run_number > 290000) pass = pass_ee_2016_trigger_matching();
		}
	}
	else if (channel = "emu") {
		if (isData == 1) {
			if (run_number < 290000) pass = pass_emu_2015_trigger_matching();
			if (run_number > 290000) pass = pass_emu_2016_trigger_matching();
		}
		else if (isMC == 1) {
			if (random_run_number < 290000) pass = pass_emu_2015_trigger_matching();
			if (random_run_number > 290000) pass = pass_emu_2016_trigger_matching();
		}
	}
	else if (channel = "mumu") {
		if (isData == 1) {
			if (run_number < 290000) pass = pass_mumu_2015_trigger_matching();
			if (run_number > 290000) pass = pass_mumu_2016_trigger_matching();
		}
		else if (isMC == 1) {
			if (random_run_number < 290000) pass = pass_mumu_2015_trigger_matching();
			if (random_run_number > 290000) pass = pass_mumu_2016_trigger_matching();
		}
	}
	return pass;
}

bool yt_cutflows::pass_at_least_one_bjet_greater_than_20GeV(int event_number, vector<int> vec_event_number, vector<Jet> vec_jets)
{
	bool pass = false;
	int count = 0;
	if (find(vec_event_number.begin(), vec_event_number.end(), event_number) != vec_event_number.end()) {
		for (auto & jet_itr : vec_jets) {
			if (jet_itr.get_isBjet() && jet_itr.get_pt() > 20000.)
				count++;
		}
		if (count >= 1) pass = true;
	}
	return pass;
}

bool yt_cutflows::pass_four_jets_greater_than_50GeV(int event_number, vector<int> vec_event_number, vector<Jet> vec_jets)
{
	bool pass = false;
	int count = 0;
	if (find(vec_event_number.begin(), vec_event_number.end(), event_number) != vec_event_number.end()) {
		for (auto & jet_itr : vec_jets) {
			if (jet_itr.get_pt() > 50000.)
				count++;
		}
		if (count >= 4) pass = true;
	}
	return pass;
}

bool yt_cutflows::pass_MET_greater_than_125GeV(float MET)
{
	bool pass = false;
	if (MET > 125000.) pass = true;
	return pass;
}
