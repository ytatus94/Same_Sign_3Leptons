#define YT_SKIM_MC_CXX
#include "ytCutflows/yt_skim_MC.h"

yt_skim_MC::yt_skim_MC()
{
    // Physics object variables
    El_ZTandP_mll                  = new vector<double>();
    El_DR_closest_Jet              = new vector<double>();
    El_DR_closest_truth_BJet       = new vector<double>();
    El_DR_closest_truth_CJet       = new vector<double>();
    El_DR_closest_truth_lightJet   = new vector<double>();
    El_isBaseline                  = new vector<bool>();
    El_isSignal                    = new vector<bool>();
    El_isZProbe                    = new vector<bool>();
    El_isZProbe_TriggerMatched     = new vector<bool>();
    El_isTTbarProbe                = new vector<bool>();
    El_tag_trigger_SF              = new vector<double>();

    Mu_ZTandP_mll                  = new vector<double>();
    Mu_DR_closest_Jet              = new vector<double>();
    Mu_DR_closest_truth_BJet       = new vector<double>();
    Mu_DR_closest_truth_CJet       = new vector<double>();
    Mu_DR_closest_truth_lightJet   = new vector<double>();
    Mu_isBaseline                  = new vector<bool>();
    Mu_isSignal                    = new vector<bool>();
    Mu_isZProbe                    = new vector<bool>();
    Mu_isZProbe_TriggerMatched     = new vector<bool>();
    Mu_isTTbarProbe                = new vector<bool>();
    Mu_tag_trigger_SF              = new vector<float>();

    Jet_Jet_isBaseline = new vector<bool>();
    Jet_Jet_isSignal   = new vector<bool>();
    Jet_bJet_isSignal  = new vector<bool>();

    // Events variables
    isSS2l_trigger = false;
    normalization = 0.;
    pileup_weight = 0.;
    baseline_mll = 0.;
    mll = 0.;
    mjj = 0.;
    meff = 0.;
    Ht = 0.;
    mT = 0.;
    nBaseLeps = 0;
    nSigLeps = 0;
    lep1Pt = 0.;
    lep2Pt = 0.;
    lep3Pt = 0.;
    lep1Eta = 0.;
    lep2Eta = 0.;
    lep3Eta = 0.;
    lep1Type = false;
    lep2Type = false;
    lep3Type = false;
    lep1Origin = false;
    lep2Origin = false;
    lep3Origin = false;
    nSigBJets = 0;
    nSigJets = 0;
    jet1Pt = 0.;
    jet2Pt = 0.;
    jet3Pt = 0.;
    isSS2l = false;
    baseline_channel = 0;
    channel = -1; // -1 for less than 2 leptons,  1 for ee,  2 for em ,  3 for mm

	run_number = 0;

    // Counters
    //n_duplicated_EventNumber = 0;
    n_tot_baseline_electrons = 0;
    n_tot_baseline_muons = 0;
    n_tot_2baseline_leptons = 0;
    n_tot_baseline_leptons_in_TTbarTandP_Events = 0;
    n_2Baseline_leptons_Events = 0;
    n_2Baseline_Bjets_Events = 0;
    n_tot_2baseline_leptons_pt30 = 0;
    n_TTbarEtmiss_Events = 0;
    n_TTbarMll_Events = 0;
    n_tot_ZTandP_electrons = 0;
    n_tot_ZTandP_muons = 0;
    n_tot_TTbarTandP_electrons = 0;
    n_tot_TTbarTandP_muons = 0;

    //sum_event_weight = 0;
    n_normalized_events = 0;
    n_normalized_tot_baseline_electrons = 0;
    n_normalized_tot_baseline_muons = 0;
    n_normalized_tot_2baseline_leptons = 0;
    n_normalized_2Baseline_leptons_Events = 0;
    n_normalized_2Baseline_Bjets_Events = 0;
    n_normalized_2Baseline_leptons_Events_pt30 = 0;
    n_normalized_TTbarEtmiss_Events = 0;
    n_normalized_TTbarMll_Events = 0;
    n_normalized_tot_ZTandP_electrons = 0;
    n_normalized_tot_ZTandP_muons = 0;
    n_normalized_tot_TTbarTandP_electrons = 0;
    n_normalized_tot_TTbarTandP_muons = 0;

	// Event weight
	event_weight_sum = 0;

    // Cross section
    crossSection = 1; // Inclusive crossSection * factor 1 * factor 2 * factor 3
    kFactor = 1;
    filterEfficiency = 1;

    // derivation efficiency
    analysis1LeptonFilter = 1;  // ttbar (non all had)
}

yt_skim_MC::~yt_skim_MC()
{
	//delete output_tree;
	//delete output_file;
}

void yt_skim_MC::initialize(TTree *tree, TString process)
{
	// Declare the output
	TString output_path("/UserDisk2/yushen/Ximo_ntuples/v44/Skimmed/");
	output_file = TFile::Open(output_path + "/MC_probes_" + process + ".root", "RECREATE");
	output_tree = (TTree*)tree->CloneTree(0);

    // Building the new branches
    // Physics object variables
    output_tree->Branch("El_ZTandP_mll",                &El_ZTandP_mll);
    output_tree->Branch("El_DR_closest_Jet",            &El_DR_closest_Jet);
    output_tree->Branch("El_DR_closest_truth_BJet",     &El_DR_closest_truth_BJet);
    output_tree->Branch("El_DR_closest_truth_CJet",     &El_DR_closest_truth_CJet);
    output_tree->Branch("El_DR_closest_truth_lightJet", &El_DR_closest_truth_lightJet);
    output_tree->Branch("El_isBaseline",                &El_isBaseline);
    output_tree->Branch("El_isSignal",                  &El_isSignal);
    output_tree->Branch("El_isZProbe",                  &El_isZProbe);
    output_tree->Branch("El_isZProbe_TriggerMatched",   &El_isZProbe_TriggerMatched);
    output_tree->Branch("El_isTTbarProbe",              &El_isTTbarProbe);
    output_tree->Branch("El_tag_trigger_SF",            &El_tag_trigger_SF);

    output_tree->Branch("Mu_ZTandP_mll",                &Mu_ZTandP_mll);
    output_tree->Branch("Mu_DR_closest_Jet",            &Mu_DR_closest_Jet);
    output_tree->Branch("Mu_DR_closest_truth_BJet",     &Mu_DR_closest_truth_BJet);
    output_tree->Branch("Mu_DR_closest_truth_CJet",     &Mu_DR_closest_truth_CJet);
    output_tree->Branch("Mu_DR_closest_truth_lightJet", &Mu_DR_closest_truth_lightJet);
    output_tree->Branch("Mu_isBaseline",                &Mu_isBaseline);
    output_tree->Branch("Mu_isSignal",                  &Mu_isSignal);
    output_tree->Branch("Mu_isZProbe",                  &Mu_isZProbe);
    output_tree->Branch("Mu_isZProbe_TriggerMatched",   &Mu_isZProbe_TriggerMatched);
    output_tree->Branch("Mu_isTTbarProbe",              &Mu_isTTbarProbe);
    output_tree->Branch("Mu_tag_trigger_SF",            &Mu_tag_trigger_SF);

    output_tree->Branch("Jet_Jet_isSignal",     &Jet_Jet_isSignal);
    output_tree->Branch("Jet_bJet_isSignal",    &Jet_bJet_isSignal);

    // Events numbers variables
    output_tree->Branch("isSS2l_trigger",   &isSS2l_trigger);
    output_tree->Branch("normalization",    &normalization);
    output_tree->Branch("pileup_weight",    &pileup_weight);
    output_tree->Branch("baseline_mll",     &baseline_mll);
    output_tree->Branch("mll",              &mll);
    output_tree->Branch("mjj",              &mjj);
    output_tree->Branch("meff",             &meff);
    output_tree->Branch("Ht",               &Ht);
    output_tree->Branch("mT",               &mT);
    output_tree->Branch("nBaseLeps",        &nBaseLeps);
    output_tree->Branch("nSigLeps",         &nSigLeps);
    output_tree->Branch("lep1Pt",           &lep1Pt);
    output_tree->Branch("lep2Pt",           &lep2Pt);
    output_tree->Branch("lep3Pt",           &lep3Pt);
    output_tree->Branch("lep1Eta",          &lep1Eta);
    output_tree->Branch("lep2Eta",          &lep2Eta);
    output_tree->Branch("lep3Eta",          &lep3Eta);
    output_tree->Branch("lep1Type",         &lep1Type);
    output_tree->Branch("lep2Type",         &lep2Type);
    output_tree->Branch("lep3Type",         &lep3Type);
    output_tree->Branch("lep1Origin",       &lep1Origin);
    output_tree->Branch("lep2Origin",       &lep2Origin);
    output_tree->Branch("lep3Origin",       &lep3Origin);
    output_tree->Branch("nSigBJets",        &nSigBJets);
    output_tree->Branch("nSigJets",         &nSigJets);
    output_tree->Branch("jet1Pt",           &jet1Pt);
    output_tree->Branch("jet2Pt",           &jet2Pt);
    output_tree->Branch("jet3Pt",           &jet3Pt);
    output_tree->Branch("isSS2l",           &isSS2l);
    output_tree->Branch("baseline_channel", &baseline_channel);
    output_tree->Branch("channel",          &channel); // 1 for ee, 2 for em ,3 for mm
	output_tree->Branch("run_number",		&run_number);
}

void yt_skim_MC::execute(vector<Electron> elec, vector<Muon> muon, vector<Lepton> lept, vector<Jet> jets,
						 vector<Electron> baseline_elec, vector<Muon> baseline_muon, vector<Lepton> baseline_lept, vector<Jet> baseline_jets,
						 vector<Electron> signal_elec, vector<Muon> signal_muon, vector<Lepton> signal_lept, vector<Jet> signal_jets,
						 double Etmiss_TST_Et, double event_weight, int run_number, float pileup_weight, TString process)
{
	// clear all the vector members
	this->yt_skim::initialize();
	// fill all the vector members
	this->yt_skim::execute(elec, muon, lept, jets,
                           baseline_elec, baseline_muon, baseline_lept, baseline_jets,
                           signal_elec, signal_muon, signal_lept, signal_jets);

    // Event normalization
    this->set_cross_section_by_process(process);
    this->set_derivation_efficiency("25ns", process);
    //normalization = lumi * (crossSection * kFactor) * (filterEfficiency * analysis1LeptonFilter) * (event_weight / event_weight_sum);
    normalization = lumi * (crossSection * kFactor) * (event_weight / event_weight_sum);

    n_normalized_events += normalization;

    // Counts some numbers ...
    if (baseline_lept.size() >= 2) {
        n_2Baseline_leptons_Events++;
        n_normalized_2Baseline_leptons_Events += normalization;
/*
        int n_baseline_electrons = vec_baseline_elec.size();
        int n_baseline_muons = vec_baseline_muon.size();

        int n_signal_electrons = vec_signal_elec.size();
        int n_signal_muons = vec_signal_muon.size();
*/
        n_tot_baseline_electrons += vec_baseline_elec.size();
        n_tot_baseline_muons += vec_baseline_muon.size();

        n_normalized_tot_baseline_electrons += vec_baseline_elec.size() * normalization;
        n_normalized_tot_baseline_muons += vec_baseline_muon.size() * normalization;

        reset_vectors();

        calculate_new_variables(Etmiss_TST_Et);
        set_run_number(run_number); 
        set_pileup_weight(pileup_weight);
        tag_and_probe_Zee(run_number);
        tag_and_probe_ttbar(Etmiss_TST_Et);

        // fill all new branches
        output_tree->Fill();
    }
}

void yt_skim_MC::finalize(TString process)
{
	cout << "Write into file" << endl;
	output_file->cd();
	output_tree->Write();
	output_file->Close();

    cout << endl;
    cout << "SUM OF THE EVENTS WEIGHTS = " << event_weight_sum << endl;
    cout << endl;
    cout << " SAMPLE : " << process << endl; 
    cout << "*******************************" << endl;
    cout << "*       EVENT NUMBER INFO     *" << endl;
    cout << "*******************************" << endl;
    //cout << "  Total number of events = " << n_events << " at 3 fb = " << n_normalized_events << endl;
    cout << "  n events with 2 baseline leptons = " << n_2Baseline_leptons_Events << " at " << lumi << "fb^{-1} = " << n_normalized_2Baseline_leptons_Events << endl;
    //cout << "  number of 2 baseline lepton duplicated events = " << n_duplicated_EventNumber << endl;
    cout << "-------------------" << endl;
    cout << "-------------------" << endl;
    cout << "  TTbar T&P cuts" << endl;
    cout << "  exactly 2 baseline leptons             = " << n_tot_2baseline_leptons        << " at " << lumi << "fb^{-1} = " << n_normalized_tot_2baseline_leptons << endl;  
    cout << "  exactly 2 signal BJets                 = " << n_2Baseline_Bjets_Events       << " at " << lumi << "fb^{-1} = " << n_normalized_2Baseline_Bjets_Events << endl;
    cout << "  ttbar Etmiss                           = " << n_TTbarEtmiss_Events           << " at " << lumi << "fb^{-1} = " << n_normalized_TTbarEtmiss_Events << endl;
    cout << "  exactly 2 baseline leptons pt > 30 GeV = " << n_tot_2baseline_leptons_pt30   << " at " << lumi << "fb^{-1} = " << n_normalized_2Baseline_leptons_Events_pt30 << endl;
    cout << "  ttbar mll                              = " << n_TTbarMll_Events              << " at " << lumi << "fb^{-1} = " << n_normalized_TTbarMll_Events << endl;
    cout << endl;
    cout << "*******************************" << endl;
    cout << "*     OBJECT NUMBER INFO      *" << endl;
    cout << "*******************************" << endl;
    cout << "LEPTONS" << endl;
    cout << "  n baseline leptons          = " << n_tot_baseline_electrons + n_tot_baseline_muons << endl;  
    cout << "  n baseline leptons in TTbar = " << n_tot_baseline_leptons_in_TTbarTandP_Events << endl;
    cout << endl;
    cout << "ELECTRONS" << endl;
    cout << "  n baseline electrons  = " << n_tot_baseline_electrons << endl;
    cout << "  n Z T&P electrons     = " << n_tot_ZTandP_electrons << endl; 
    cout << "  n ttbar T&P electrons = " << n_tot_TTbarTandP_electrons << " at " << lumi << "fb^{-1} = " << n_normalized_tot_TTbarTandP_electrons << endl;
    cout << endl;
    cout << "MUONS" << endl;
    cout << "  n baseline muons  = " << n_tot_baseline_muons << endl;
    cout << "  n Z T&P muons     = " << n_tot_ZTandP_muons << endl;
    cout << "  n ttbar T&P muons = " << n_tot_TTbarTandP_muons << " at " << lumi << "fb^{-1} = " << n_normalized_tot_TTbarTandP_muons << endl;
    cout << endl;
}

void yt_skim_MC::reset_vectors()
{
    // reset vectors in event loop
    El_ZTandP_mll->clear();
    El_DR_closest_Jet->clear();
    El_DR_closest_truth_BJet->clear();
    El_DR_closest_truth_CJet->clear();
    El_DR_closest_truth_lightJet->clear();
    El_isBaseline->clear();
    El_isSignal->clear();
    El_isZProbe->clear();
    El_isZProbe_TriggerMatched->clear();
    El_isTTbarProbe->clear();
    El_tag_trigger_SF->clear();

    Mu_ZTandP_mll->clear();
    Mu_DR_closest_Jet->clear();
    Mu_DR_closest_truth_BJet->clear();
    Mu_DR_closest_truth_CJet->clear();
    Mu_DR_closest_truth_lightJet->clear();
    Mu_isBaseline->clear();
    Mu_isSignal->clear();
    Mu_isZProbe->clear();
    Mu_isZProbe_TriggerMatched->clear();
    Mu_isTTbarProbe->clear();
    Mu_tag_trigger_SF->clear();

    Jet_Jet_isBaseline->clear();
    Jet_Jet_isSignal->clear();
    Jet_bJet_isSignal->clear();

    for (unsigned int i = 0 ; i < vec_elec.size(); i++) {
        El_ZTandP_mll->push_back(0);
        El_DR_closest_Jet->push_back(100);
        El_DR_closest_truth_BJet->push_back(100);
        El_DR_closest_truth_CJet->push_back(100);
        El_DR_closest_truth_lightJet->push_back(100);
        El_isBaseline->push_back(false);
        El_isSignal->push_back(false);
        El_isZProbe->push_back(false);
        El_isZProbe_TriggerMatched->push_back(false);
        El_isTTbarProbe->push_back(false);
        El_tag_trigger_SF->push_back(1);
    }

    for (unsigned int i = 0 ; i < vec_muon.size(); i++) {
        Mu_ZTandP_mll->push_back(0);
        Mu_DR_closest_Jet->push_back(100);
        Mu_DR_closest_truth_BJet->push_back(100);
        Mu_DR_closest_truth_CJet->push_back(100);
        Mu_DR_closest_truth_lightJet->push_back(100);
        Mu_isBaseline->push_back(false);
        Mu_isSignal->push_back(false);
        Mu_isZProbe->push_back(false);
        Mu_isZProbe_TriggerMatched->push_back(false);
        Mu_isTTbarProbe->push_back(false);
        Mu_tag_trigger_SF->push_back(1);
    }

    for (unsigned int i = 0; i < vec_jets.size(); i++) {
        Jet_Jet_isBaseline->push_back(false);
        Jet_Jet_isSignal->push_back(false);
        Jet_bJet_isSignal->push_back(false);
    }
}

void yt_skim_MC::calculate_new_variables(double Etmiss_TST_Et)
{
    baseline_mll	= calculate_mll(vec_baseline_lept);
    mll 			= calculate_mll(vec_signal_lept);
    mjj 			= calculate_mjj(vec_signal_jets);
    Ht				= calculate_Ht(vec_signal_lept, vec_signal_jets);
    meff 			= calculate_Meff(Ht, Etmiss_TST_Et);

    // leptons variables
    nBaseLeps	= vec_baseline_lept.size();
    nSigLeps	= vec_signal_lept.size();

    if (nSigLeps > 0) {
        lep1Pt		= vec_signal_lept.at(0).get_pt();
        lep1Eta		= vec_signal_lept.at(0).get_eta();
        lep1Type	= vec_signal_lept.at(0).get_type();
        lep1Origin	= vec_signal_lept.at(0).get_origin();
    }
    else {
        lep1Pt		= -5000000.;
        lep1Eta		= -5000.;
        lep1Type	= false;
        lep1Origin	= false;
    }
    if (nSigLeps > 1) {
        lep2Pt		= vec_signal_lept.at(1).get_pt();
        lep2Eta		= vec_signal_lept.at(1).get_eta();
        lep2Type	= vec_signal_lept.at(1).get_type();
        lep2Origin	= vec_signal_lept.at(1).get_origin();
    }
    else {
        lep2Pt		= -5000000.;
        lep2Eta		= -5000.;
        lep2Type	= false;
        lep2Origin	= false;
    }
    if (nSigLeps > 2) {
        lep3Pt		= vec_signal_lept.at(2).get_pt();
        lep3Eta		= vec_signal_lept.at(2).get_eta();
        lep3Type	= vec_signal_lept.at(2).get_type();
        lep3Origin	= vec_signal_lept.at(2).get_origin();
    }
    else {
        lep3Pt		= -5000000.;
        lep3Eta		= -5000.;
        lep3Type	= false;
        lep3Origin	= false;
    }

    // jets variables
    nSigJets = vec_signal_jets.size();
    if (nSigJets > 0) jet1Pt = vec_signal_jets.at(0).get_pt();
    if (nSigJets > 1) jet2Pt = vec_signal_jets.at(1).get_pt();
    if (nSigJets > 2) jet3Pt = vec_signal_jets.at(2).get_pt();

    nSigBJets = vec_signal_bjet.size();

    // Filling the baseline / signal objects indicators / DRjets

    for (auto & elec_itr : vec_baseline_elec) {
        int current_index = elec_itr.get_index();
        El_isBaseline->at(current_index) = true;
        vector<double> DR_out = calculate_DR_closestJet(elec_itr, vec_signal_jets_no_eta_cut);
        El_DR_closest_Jet->at(current_index) = DR_out.at(0);
        if (DR_out.at(1) == 1) El_DR_closest_truth_lightJet->at(current_index) = DR_out.at(0);
        if (DR_out.at(1) == 2) El_DR_closest_truth_CJet->at(current_index) = DR_out.at(0);
        if (DR_out.at(1) == 3) El_DR_closest_truth_BJet->at(current_index) = DR_out.at(0);
    }

    for (auto & muon_itr : vec_baseline_muon) {
        int current_index = muon_itr.get_index();
        Mu_isBaseline->at(current_index) = true;
        vector<double> DR_out = calculate_DR_closestJet(muon_itr, vec_signal_jets_no_eta_cut);
        Mu_DR_closest_Jet->at(current_index) = DR_out.at(0);
        if (DR_out.at(1) == 1) Mu_DR_closest_truth_lightJet->at(current_index) = DR_out.at(0);
        if (DR_out.at(1) == 2) Mu_DR_closest_truth_CJet->at(current_index) = DR_out.at(0);
        if (DR_out.at(1) == 3) Mu_DR_closest_truth_BJet->at(current_index) = DR_out.at(0);
    }

    for (auto & elec_itr : vec_signal_elec) {
        El_isSignal->at(elec_itr.get_index()) = true;
    }

    for (auto & muon_itr : vec_signal_muon) {
        Mu_isSignal->at(muon_itr.get_index()) = true;
    }

    for (auto & jet_itr : vec_baseline_jets) {
        Jet_Jet_isBaseline->at(jet_itr.get_index()) = true;
    }

    for (auto & jet_itr : vec_signal_jets) {
        Jet_Jet_isSignal->at(jet_itr.get_index()) = true;
    }

    for (auto & bjet_itr : vec_signal_bjet) {
        Jet_bJet_isSignal->at(bjet_itr.get_index()) = true;
    }

    baseline_channel = -1;
    if (vec_baseline_lept.size() > 1) {
        if (vec_baseline_lept.at(0).get_flavor() == 11 && vec_baseline_lept.at(1).get_flavor() == 11)
            baseline_channel = 1;
        else if (vec_baseline_lept.at(0).get_flavor() == 13 && vec_baseline_lept.at(1).get_flavor() == 13)
            baseline_channel = 3;
        else
            baseline_channel = 2;
    }
    
    // isSR event and associated channels
    isSS2l = false;
    channel = -1;
    if (mll > 12000. && // why?
        nSigBJets >= 1 &&
        nSigJets  >= 4 &&
        vec_signal_lept.at(0).get_charge() == vec_signal_lept.at(1).get_charge() &&
        Etmiss_TST_Et > 150000.) { // use 125 GeV?
        isSS2l = true;
        channel = Get_channel(vec_signal_lept);
    }
}

void yt_skim_MC::tag_and_probe_Zee(int run_number)
{
    // Z T&P method

    // Electron
    for (auto & probe_elec_itr : vec_baseline_elec) {
        double best_match_mll = 1000000.;
        for (auto & tag_elec_itr : vec_signal_elec) {
            if (tag_elec_itr.get_index() == probe_elec_itr.get_index())
                continue;
            if (tag_elec_itr.get_pt() < 25000.)
                continue;
            if (fabs(tag_elec_itr.get_eta()) > 2.)
                continue;
            // Opposite Charge requirement
            if (tag_elec_itr.get_charge() == probe_elec_itr.get_charge())
                continue;
            // Check does the tag trigger matched
            bool isTriggerMatched = false;
			//if (tag_elec_itr.get_trigMatch_e24_lhmedium_iloose_L1EM20VH())
				//isTriggerMatched = true;
            // Ximo said let all lepton trigger matching
            isTriggerMatched = true;

            // Store the tag trigger SF associated to the probe
            El_tag_trigger_SF->at(probe_elec_itr.get_index()) = tag_elec_itr.get_SFwTrigMediumLH_single();

            TLorentzVector tlv_tag;
            TLorentzVector tlv_probe;
            tlv_tag.SetPtEtaPhiM(tag_elec_itr.get_pt(), tag_elec_itr.get_eta(), tag_elec_itr.get_phi(), tag_elec_itr.get_M());
            tlv_probe.SetPtEtaPhiM(probe_elec_itr.get_pt(), probe_elec_itr.get_eta(), probe_elec_itr.get_phi(), probe_elec_itr.get_M());
            double current_mll = (tlv_tag + tlv_probe).M();
            if (fabs(current_mll - 91.1876 * 1000.) < fabs(best_match_mll - 91.1876 * 1000.))
                best_match_mll = current_mll;
            // mll window cut
            if (current_mll > 80000. && current_mll < 100000.) {
                El_isZProbe->at(probe_elec_itr.get_index()) = true;
                if (isTriggerMatched)
                    El_isZProbe_TriggerMatched->at(probe_elec_itr.get_index()) = true;
                n_tot_ZTandP_electrons++;
                n_normalized_tot_ZTandP_electrons += normalization;
            }
        }
        El_ZTandP_mll->at(probe_elec_itr.get_index()) = best_match_mll;
    }

    // Muons
    for (auto & probe_muon_itr : vec_baseline_muon) {
        double best_match_mll = 1000000.;
        for (auto & tag_muon_itr : vec_signal_muon) {
            if (tag_muon_itr.get_index() == probe_muon_itr.get_index())
                continue;
            if (tag_muon_itr.get_pt() < 25000)
                continue;
            // Opposite Charge requirement
            if (tag_muon_itr.get_charge() == probe_muon_itr.get_charge())
                continue;
            // Check does the tag tragger matched
            bool isTriggerMatched = false;
			//if (tag_muon_itr.get_trigMatch_mu26_imedium())
				//isTriggerMatched = true;
            // Ximo said let all lepton trigger matching
            isTriggerMatched = true;

            // Store the tag trigger SF associated to the probe
            Mu_tag_trigger_SF->at(probe_muon_itr.get_index()) = tag_muon_itr.get_MuTrigSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50();

            TLorentzVector tlv_tag;
            TLorentzVector tlv_probe;
            tlv_tag.SetPtEtaPhiM(tag_muon_itr.get_pt(), tag_muon_itr.get_eta(), tag_muon_itr.get_phi(), tag_muon_itr.get_M());
            tlv_probe.SetPtEtaPhiM(probe_muon_itr.get_pt(), probe_muon_itr.get_eta(), probe_muon_itr.get_phi(), probe_muon_itr.get_M());
            double current_mll = (tlv_tag + tlv_probe).M();
            if (fabs(current_mll - 91.1876 * 1000.) < fabs(best_match_mll - 91.1876 * 1000.))
                best_match_mll = current_mll;
            // mll window cut
            if (current_mll > 80000. && current_mll < 100000.) {
                Mu_isZProbe->at(probe_muon_itr.get_index()) = true;
                if (isTriggerMatched)
                    Mu_isZProbe_TriggerMatched->at(probe_muon_itr.get_index()) = true;
                n_tot_ZTandP_muons++;
                n_normalized_tot_ZTandP_muons += normalization;
            }
        }
        Mu_ZTandP_mll->at(probe_muon_itr.get_index()) = best_match_mll;
    }
}

void yt_skim_MC::tag_and_probe_ttbar(double Etmiss_TST_Et)
{
    // ttbar T&P method
    // Event selection
    bool isTTbarTandP = true;
    
    // Requiering exactly 2 baseline leptons
    //if (n_baseline_electrons + n_baseline_muons != 2)
    if (vec_baseline_elec.size() + vec_baseline_muon.size() != 2)
        isTTbarTandP = false;
    if (isTTbarTandP) {
        n_tot_2baseline_leptons++;
        n_normalized_tot_2baseline_leptons += normalization;
    }

    // Requiering 2 bjets at 70 efficeincy
    if (vec_signal_bjet.size() < 2)
        isTTbarTandP = false;
    if (isTTbarTandP) {
        n_2Baseline_Bjets_Events++;
        n_normalized_2Baseline_Bjets_Events += normalization;
    }
    
    // Etmiss > 30 GeV  for ee and mumu
    if ((vec_baseline_lept.at(0).get_flavor() == 11 && vec_baseline_lept.at(1).get_flavor() == 11) ||
        (vec_baseline_lept.at(0).get_flavor() == 13 && vec_baseline_lept.at(1).get_flavor() == 13)) {
        if (Etmiss_TST_Et < 30000.)
            isTTbarTandP = false;
    }
    if (isTTbarTandP) {
        n_TTbarEtmiss_Events++;
        n_normalized_TTbarEtmiss_Events += normalization;
    }
    
    // Exactly 2 baseline leptons with pt > 30 / 50 GeV
    int n_baseline_lep_pt30 = 0;
    int n_baseline_lep_pt50 = 0;
    for (auto & lept_itr : vec_baseline_lept) {
        if (lept_itr.get_pt() < 30000.)
            continue;
        n_baseline_lep_pt30++;
        if (lept_itr.get_pt() < 50000.)
            continue;
        n_baseline_lep_pt50++;
    }
    if (n_baseline_lep_pt30 != 2)
        isTTbarTandP = false; // pt > 30 GeV
/*
    if (n_baseline_lep_pt50 != 2)
        isTTbarTandP = false; // pt > 50 GeV
*/
    if (isTTbarTandP) {
        n_tot_2baseline_leptons_pt30++;
        n_normalized_2Baseline_leptons_Events_pt30 += normalization;
    }

    // mll window cut
    if ((vec_baseline_lept.at(0).get_flavor() == 11 && vec_baseline_lept.at(1).get_flavor() == 11) ||
        (vec_baseline_lept.at(0).get_flavor() == 13 && vec_baseline_lept.at(1).get_flavor() == 13)) {
        if (baseline_mll > 70000. && baseline_mll < 100000.) // Z peak region
            isTTbarTandP = false;
    }
    if (isTTbarTandP) {
        n_TTbarMll_Events++;
        n_normalized_TTbarMll_Events += normalization;
    }

    // Tag & Probe loop
    if (isTTbarTandP) {
        n_tot_baseline_leptons_in_TTbarTandP_Events += vec_baseline_lept.size();
        for (auto & tag_lept_itr : vec_signal_lept) {
            for (auto & probe_lept_itr : vec_baseline_lept) {
                if (tag_lept_itr.get_index() == probe_lept_itr.get_index())
                    continue;
                
                if (probe_lept_itr.get_flavor() == 11) {
                    El_isTTbarProbe->at(probe_lept_itr.get_index()) = true;
                    n_tot_TTbarTandP_electrons++;
                    n_normalized_tot_TTbarTandP_electrons += normalization;
                }
                if (probe_lept_itr.get_flavor() == 13) {
                    Mu_isTTbarProbe->at(probe_lept_itr.get_index()) = true;
                    n_tot_TTbarTandP_muons++;
                    n_normalized_tot_TTbarTandP_muons += normalization;
                }
            }
        }
    }
}

void yt_skim_MC::set_cross_section_by_process(TString process)
{
    // Get the values from SUSYTools

    // ttbar
    if (process == "ttbar") {
        crossSection = 696110; // in fb
        kFactor = 1.1949;
        filterEfficiency = 0.543;
    }

    // W+jets
    else if (process == "Wplusenu" || process == "Wplusmunu" || process == "Wplustaunu") {
        crossSection = 11306000. /* * 0.05 */;
        kFactor = 1.01724;
        filterEfficiency = 1;
    }
    else if (process == "Wminusenu" || process == "Wminusmunu" || process == "Wminustaunu") {
        crossSection = 8282600. /* * 0.05 */;
        kFactor = 1.035786;
        filterEfficiency = 1;
    }

    // Z+jets
    else if (process == "Zee" || process ==  "Zee_v22" || process ==  "Zee_v23" ||
             process == "Zmumu" || process ==  "Zmumu_v22" || process ==  "Zmumu_v23" ||
             process ==  "Ztautau") {
        crossSection = 1901200 /* * 0.05*/;
        kFactor = 1.026;
        filterEfficiency = 1;
    }

    // VV
    else if (process == "llll") {
        crossSection = 12583  /* * 1*/;
        kFactor = 1;
        filterEfficiency = 1;
    }
    else if (process == "lllvSFMinus") {
        crossSection = 1844.6  /* * 1*/;
        kFactor = 1;
        filterEfficiency = 1;
    }
    else if (process == "lllvOFMinus") {
        crossSection = 3623.5  /* * 1*/;
        kFactor = 1;
        filterEfficiency = 1;
    }
    else if (process == "lllvSFPlus") {
        crossSection = 2565.6  /* * 1*/;
        kFactor = 1;
        filterEfficiency = 1;
    }
    else if (process == "lllvOFPlus") {
        crossSection = 5016.9  /* * 1*/;
        kFactor = 1;
        filterEfficiency = 1;
    }
    else if (process == "llvv") {
        crossSection = 14022.  /* * 1*/;
        kFactor = 1;
        filterEfficiency = 1;
    }
    else if (process == "llvvjj_ss_EW4") {
        crossSection = 25.765  /* * 1*/;
        kFactor = 1;
        filterEfficiency = 1;
    }
    else if (process == "llvvjj_ss_EW6") {
        crossSection = 43.375  /* * 1*/;
        kFactor = 1;
        filterEfficiency = 1;
    }
    else if (process == "lllvjj_EW6") {
        crossSection = 42.017  /* * 1*/;
        kFactor = 1;
        filterEfficiency = 1;
    }
    else if (process == "lllljj_EW6") {
        crossSection = 127.9   /* * 1*/;
        kFactor = 1;
        filterEfficiency = 1;
    }
    else if (process == "ggllll") {
        crossSection = 20.95   /* * 1*/;
        kFactor = 1;
        filterEfficiency = 1;
    }
    else if (process == "ggllvv") {
        crossSection = 854.92  /* * 1*/;
        kFactor = 1;
        filterEfficiency = 1; 
    }
    else if (process == "Bkg") {
        cerr << "Hi dude! You have to assign the crossSection, kFactor and the filter efficiency before !" << endl;
    }
}

void yt_skim_MC::set_derivation_efficiency(TString bunch_spacing, TString process)
{
    if (bunch_spacing == "50ns") {
        if (process == "ttbar")         analysis1LeptonFilter = 0.30074;
        // Z+jets
        else if (process == "Zee")      analysis1LeptonFilter = 0.438038;
        else if (process == "Zmumu")    analysis1LeptonFilter = 0.491288;
        else if (process == "Ztautau")  analysis1LeptonFilter = 0.0226514;
        // W+jets
        else if (process == "Wplusenu")     analysis1LeptonFilter = 0.0286869;
        else if (process == "Wplusmunu")    analysis1LeptonFilter = 0.0197517;
        else if (process == "Wplustaunu")   analysis1LeptonFilter = 0.00225566;
        else if (process == "Wminusenu")    analysis1LeptonFilter = 0.0308312;
        else if (process == "Wminusmunu")   analysis1LeptonFilter = 0.0204428;
        else if (process == "Wminustaunu")  analysis1LeptonFilter = 0.00253816;
    }
    else if (bunch_spacing == "25ns") {
        // ttbar (non all had)
        if (process == "ttbar")             analysis1LeptonFilter = 0.711477;
        else if (process == "ttbar_v23")    analysis1LeptonFilter = 0.735005;
        // Z+jets
        else if (process == "Zee")          analysis1LeptonFilter = 0.43547;
        else if (process == "Zee_v22")      analysis1LeptonFilter = 0.436163;
        else if (process == "Zee_v23")      analysis1LeptonFilter = 0.436119;
        else if (process == "Zmumu")        analysis1LeptonFilter = 0.487455;
        else if (process == "Zmumu_v22")    analysis1LeptonFilter = 0.487497;
        else if (process == "Zmumu_v23")    analysis1LeptonFilter = 0.487497;
        else if (process == "Ztautau")      analysis1LeptonFilter = 0.022674;
        // W+jets
        else if (process == "Wplusenu")     analysis1LeptonFilter = 0.0307869;
        else if (process == "Wplusmunu")    analysis1LeptonFilter = 0.0217191;
        else if (process == "Wplustaunu")   analysis1LeptonFilter = 0.00243261;
        else if (process == "Wminusenu")    analysis1LeptonFilter = 0.0330051;
        else if (process == "Wminusmunu")   analysis1LeptonFilter = 0.0224359;
        else if (process == "Bkg") {
            cerr << "Hi dude! You have to assign the analysis filter efficiency before !!" << endl;
        }
        
    }
}

void yt_skim_MC::set_luminosity(double number)
{
	lumi = number;
}

void yt_skim_MC::set_event_weight_sum(double sum)
{
	event_weight_sum = sum;
}

void yt_skim_MC::set_run_number(int number)
{
	run_number = number;
}

void yt_skim_MC::set_pileup_weight(float number)
{
	pileup_weight = number;
}
