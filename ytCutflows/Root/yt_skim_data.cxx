#define YT_SKIM_DATA_CXX
#include "ytCutflows/yt_skim_data.h"

yt_skim_data::yt_skim_data()
{
    // Physics object variables
    El_ZTandP_mll              = new vector<double>();
    El_DR_closest_Jet          = new vector<double>();
    El_isBaseline              = new vector<bool>();
    El_isSignal                = new vector<bool>();
    El_isZProbe                = new vector<bool>();
    El_isZProbe_TriggMatched   = new vector<bool>();
    El_isTTbarProbe            = new vector<bool>();

    Mu_ZTandP_mll              = new vector<double>();
    Mu_DR_closest_Jet          = new vector<double>();
    Mu_isBaseline              = new vector<bool>();
    Mu_isSignal                = new vector<bool>();
    Mu_isZProbe                = new vector<bool>();
    Mu_isZProbe_TriggMatched   = new vector<bool>();
    Mu_isTTbarProbe            = new vector<bool>();

    Jet_Jet_isBaseline = new vector<bool>();
    Jet_Jet_isSignal   = new vector<bool>();
    Jet_bJet_isSignal  = new vector<bool>();

    // Events variables
    isSS2l_trigger = false;
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
    is3l = false;
    isSS2l = false;
    baseline_channel = 0;
    channel = -1; // -1 for less than 2 leptons,  1 for ee,  2 for em ,  3 for mm

    // Counters
    //n_duplicated_EventNumber = 0;
    n_tot_baseline_electrons = 0;
    n_tot_baseline_muons = 0;
    n_tot_2baseline_leptons = 0;
    n_tot_baseline_leptons_in_TTbarTandP_Events = 0;
    n_2Baseline_leptons_Events = 0;
    n_2Baseline_Bjets_Events = 0;
    n_TTbarEtmiss_Events = 0;
    n_TTbarMll_Events = 0;
    n_tot_ZTandP_electrons = 0;
    n_tot_ZTandP_muons = 0;
    n_tot_TTbarTandP_electrons = 0;
    n_tot_TTbarTandP_muons = 0;

    n_CutFlow_ee_ChanSep = 0;
    n_CutFlow_ee_AtLeast1Bjets_pT20 = 0;
    n_CutFlow_ee_AtLeast4Jets_pt50 = 0;
    n_CutFlow_emu_ChanSep = 0;
    n_CutFlow_emu_AtLeast1Bjets_pT20 = 0;
    n_CutFlow_emu_AtLeast4Jets_pt50 = 0;
    n_CutFlow_mumu_ChanSep = 0;
    n_CutFlow_mumu_AtLeast1Bjets_pT20 = 0;
    n_CutFlow_mumu_AtLeast4Jets_pt50 = 0;
}

yt_skim_data::~yt_skim_data()
{
    //delete output_tree;
    //delete output_file;
}

void yt_skim_data::initialize(TTree *tree)
{
    // Declare the output
    TString output_path("/afs/cern.ch/user/y/yushen/afsWorkingArea/private/Ximo/v39/Skimmed/");
    output_file = TFile::Open(output_path + "/data_probes_all_periods.root", "RECREATE");
    output_tree = (TTree*)tree->CloneTree(0);

    // Building the new branches
    // Physics object variables
    output_tree->Branch("El_ZTandP_mll",            &El_ZTandP_mll);
    output_tree->Branch("El_DR_closest_Jet",        &El_DR_closest_Jet);
    output_tree->Branch("El_isBaseline",            &El_isBaseline);
    output_tree->Branch("El_isSignal",              &El_isSignal);
    output_tree->Branch("El_isZProbe",              &El_isZProbe);
    output_tree->Branch("El_isZProbe_TriggMatched", &El_isZProbe_TriggMatched);
    output_tree->Branch("El_isTTbarProbe",          &El_isTTbarProbe);

    output_tree->Branch("Mu_ZTandP_mll",            &Mu_ZTandP_mll);
    output_tree->Branch("Mu_DR_closest_Jet",        &Mu_DR_closest_Jet);
    output_tree->Branch("Mu_isBaseline",            &Mu_isBaseline);
    output_tree->Branch("Mu_isSignal",              &Mu_isSignal);
    output_tree->Branch("Mu_isZProbe",              &Mu_isZProbe);
    output_tree->Branch("Mu_isZProbe_TriggMatched", &Mu_isZProbe_TriggMatched);
    output_tree->Branch("Mu_isTTbarProbe",          &Mu_isTTbarProbe);

    output_tree->Branch("Jet_Jet_isSignal",     &Jet_Jet_isSignal);
    output_tree->Branch("Jet_bJet_isSignal",    &Jet_bJet_isSignal);

    // Events numbers variables
    output_tree->Branch("isSS2l_trigger",   &isSS2l_trigger);
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
    output_tree->Branch("nSigBJets",        &nSigBJets);
    output_tree->Branch("nSigJets",         &nSigJets);
    output_tree->Branch("jet1Pt",           &jet1Pt);
    output_tree->Branch("jet2Pt",           &jet2Pt);
    output_tree->Branch("jet3Pt",           &jet3Pt);
    output_tree->Branch("isSS2l",           &isSS2l);
    output_tree->Branch("baseline_channel", &baseline_channel);
    output_tree->Branch("channel",          &channel); // 1 for ee, 2 for em ,3 for mm
}

void yt_skim_data::execute(vector<Electron> elec, vector<Muon> muon, vector<Lepton> lept, vector<Jet> jets,
                           vector<Electron> baseline_elec, vector<Muon> baseline_muon, vector<Lepton> baseline_lept, vector<Jet> baseline_jets,
                           vector<Electron> signal_elec, vector<Muon> signal_muon, vector<Lepton> signal_lept, vector<Jet> signal_jets,
                           double Etmiss_TST_Et, int run_number)
{
    // clear all the vector members
    this->yt_skim::initialize();
    // fill all the vector members
    this->yt_skim::execute(elec, muon, lept, jets,
                           baseline_elec, baseline_muon, baseline_lept, baseline_jets,
                           signal_elec, signal_muon, signal_lept, signal_jets);

    if (baseline_lept.size() >= 2) {
        n_2Baseline_leptons_Events++;
/*
        int n_baseline_electrons = vec_baseline_elec.size();
        int n_baseline_muons = vec_baseline_muon.size();
        //n_tot_baseline_electrons += n_baseline_electrons;
        //n_tot_baseline_muons += n_baseline_muons;
        int n_signal_electrons = vec_signal_elec.size();
        int n_signal_muons = vec_signal_muon.size();
*/
        n_tot_baseline_electrons += vec_baseline_elec.size();
        n_tot_baseline_muons += vec_baseline_muon.size();

        reset_vectors();

        calculate_new_variables(Etmiss_TST_Et);

        tag_and_probe_Zee(run_number);
        tag_and_probe_ttbar(Etmiss_TST_Et);

        // fill all new branches
        output_tree->Fill();
    }
}

void yt_skim_data::finalize()
{
    cout << "Write into file" << endl;
    output_file->cd();
    output_tree->Write();
    output_file->Close();

    // cout
    cout << endl;
    cout << "*******************************" << endl;
    cout << "*       EVENT NUMBER INFO     *" << endl;
    cout << "*******************************" << endl;
    //cout << "  Total number of events = " << m_cutflow->events_pass_cutflow[All_event] << endl;
    cout << "  n events with 2 baseline leptons = " << n_2Baseline_leptons_Events << endl;
    cout << "-------------------" << endl;
    cout << "  TTbar T&P cuts" << endl;
    cout << "  exactly 2 baseline leptons = " << n_tot_2baseline_leptons << endl;
    cout << "  exactly 2 signal BJets     = " << n_2Baseline_Bjets_Events << endl;
    cout << "  ttbar Etmiss               = " << n_TTbarEtmiss_Events     << endl;
    cout << "  ttbar mll                  = " << n_TTbarMll_Events        << endl;
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
    cout << "  n ttbar T&P electrons = " << n_tot_TTbarTandP_electrons << endl;
    cout << endl;
    cout << "MUONS" << endl;
    cout << "  n baseline muons  = " << n_tot_baseline_muons << endl;
    cout << "  n Z T&P muons     = " << n_tot_ZTandP_muons << endl;
    cout << "  n ttbar T&P muons = " << n_tot_TTbarTandP_muons << endl;
    cout << endl;

    cout << "debug" << endl;
    cout << "******************************************" << endl;
    cout << " ee channel   : " << n_CutFlow_ee_ChanSep << endl;
    cout << " 1 bjet       : " << n_CutFlow_ee_AtLeast1Bjets_pT20 << endl;
    cout << " 4 jet        : " << n_CutFlow_ee_AtLeast4Jets_pt50 << endl;
    cout << "******************************************" << endl;
    cout << " emu channel  : " <<  n_CutFlow_emu_ChanSep << endl;
    cout << " 1 bjet       : " << n_CutFlow_emu_AtLeast1Bjets_pT20 << endl;
    cout << " 4 jet        : " << n_CutFlow_emu_AtLeast4Jets_pt50 << endl;
    cout << "******************************************" << endl;
    cout << " mumu channel : " <<  n_CutFlow_mumu_ChanSep << endl;
    cout << " 1 bjet       : " << n_CutFlow_mumu_AtLeast1Bjets_pT20 << endl;
    cout << " 4 jet        : " << n_CutFlow_mumu_AtLeast4Jets_pt50 << endl;
    cout << endl;

}

void yt_skim_data::reset_vectors()
{
    // reset vectors in event loop
    El_ZTandP_mll->clear();
    El_DR_closest_Jet->clear();
    El_isBaseline->clear();
    El_isSignal->clear();
    El_isZProbe->clear();
    El_isZProbe_TriggMatched->clear();
    El_isTTbarProbe->clear();

    Mu_ZTandP_mll->clear();
    Mu_DR_closest_Jet->clear();
    Mu_isBaseline->clear();
    Mu_isSignal->clear();
    Mu_isZProbe->clear();
    Mu_isZProbe_TriggMatched->clear();
    Mu_isTTbarProbe->clear();

    Jet_Jet_isBaseline->clear();
    Jet_Jet_isSignal->clear();
    Jet_bJet_isSignal->clear();

    for (unsigned int i = 0; i < vec_elec.size(); i++) {
        El_ZTandP_mll->push_back(0);
        El_DR_closest_Jet->push_back(100);
        El_isBaseline->push_back(false);
        El_isSignal->push_back(false);
        El_isZProbe->push_back(false);
        El_isZProbe_TriggMatched->push_back(false);
        El_isTTbarProbe->push_back(false);
    }

    for (unsigned int i = 0; i < vec_muon.size(); i++) {
        Mu_ZTandP_mll->push_back(0);
        Mu_DR_closest_Jet->push_back(100);
        Mu_isBaseline->push_back(false);
        Mu_isSignal->push_back(false);
        Mu_isZProbe->push_back(false);
        Mu_isZProbe_TriggMatched->push_back(false);
        Mu_isTTbarProbe->push_back(false);
    } 

    for (unsigned int i = 0; i < vec_jets.size(); i++) {
        Jet_Jet_isBaseline->push_back(false);
        Jet_Jet_isSignal->push_back(false);
        Jet_bJet_isSignal->push_back(false);
    } 
}

void yt_skim_data::calculate_new_variables(double Etmiss_TST_Et)
{
    baseline_mll    = calculate_mll(vec_baseline_lept);
    mll             = calculate_mll(vec_signal_lept);
    mjj             = calculate_mjj(vec_signal_jets);
    Ht              = calculate_Ht(vec_signal_lept, vec_signal_jets);
    meff            = calculate_Meff(Ht, Etmiss_TST_Et);

    // leptons variables
    nBaseLeps   = vec_baseline_lept.size();
    nSigLeps    = vec_signal_lept.size();

    if (nSigLeps > 0) {
        lep1Pt      = vec_signal_lept.at(0).get_pt();
        lep1Eta     = vec_signal_lept.at(0).get_eta();
        lep1Type    = vec_signal_lept.at(0).get_type();
        lep1Origin  = vec_signal_lept.at(0).get_origin();
    }
    else {
        lep1Pt      = -5000000.;
        lep1Eta     = -5000.;
        lep1Type    = false;
        lep1Origin  = false;
    }
    if (nSigLeps > 1) {
        lep2Pt      = vec_signal_lept.at(1).get_pt();
        lep2Eta     = vec_signal_lept.at(1).get_eta();
        lep2Type    = vec_signal_lept.at(1).get_type();
        lep2Origin  = vec_signal_lept.at(1).get_origin();
    }
    else {
        lep2Pt      = -5000000.;
        lep2Eta     = -5000.;
        lep2Type    = false;
        lep2Origin  = false;
    }
    if (nSigLeps > 2) {
        lep3Pt      = vec_signal_lept.at(2).get_pt();
        lep3Eta     = vec_signal_lept.at(2).get_eta();
        lep3Type    = vec_signal_lept.at(2).get_type();
        lep3Origin  = vec_signal_lept.at(2).get_origin();
    }
    else {
        lep3Pt      = -5000000.;
        lep3Eta     = -5000.;
        lep3Type    = false;
        lep3Origin  = false;
    }

    // jets variables
    nSigJets = vec_signal_jets.size();
    if (nSigJets > 0) jet1Pt = vec_signal_jets.at(0).get_pt();
    if (nSigJets > 1) jet2Pt = vec_signal_jets.at(1).get_pt();
    if (nSigJets > 2) jet3Pt = vec_signal_jets.at(2).get_pt();

    nSigBJets = vec_signal_bjet.size();
    int nSigJet50 = 0, nSigJet40 = 0;
    for (auto & jet_itr : vec_signal_jets) {
        if (jet_itr.get_pt() >= 50000.)
            nSigJet50++;
    }
    for (auto & jet_itr : vec_signal_jets) {
        if (jet_itr.get_pt() >= 40000.)
            nSigJet40++;
    }

    // Filling the baseline / signal objects indicators / DRjets

    for (auto & elec_itr : vec_baseline_elec) {
        int current_index = elec_itr.get_index();
        El_isBaseline->at(current_index) = true;
        El_DR_closest_Jet->at(current_index) = calculate_DR_closestJet(elec_itr, vec_signal_jets_no_eta_cut).at(0);
    }

    for (auto & muon_itr : vec_baseline_muon) {
        int current_index = muon_itr.get_index();
        Mu_isBaseline->at(current_index) = true;
        Mu_DR_closest_Jet->at(current_index) = calculate_DR_closestJet(muon_itr, vec_signal_jets_no_eta_cut).at(0);
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

    // Channel separation
    channel = Get_channel(vec_signal_lept);
    if (channel == 1) {  // ee
        n_CutFlow_ee_ChanSep++;

        bool pass_ee = true;
        if (vec_signal_bjet.size() < 1) pass_ee = false;
        if (pass_ee) n_CutFlow_ee_AtLeast1Bjets_pT20++;

        if (nSigJet50 < 4) pass_ee = false;
        if (pass_ee) n_CutFlow_ee_AtLeast4Jets_pt50++;
    }
    if (channel == 2) {  // emu
        n_CutFlow_emu_ChanSep++;

        bool pass_emu = true;
        if (vec_signal_bjet.size() < 1) pass_emu = false;
        if (pass_emu) n_CutFlow_emu_AtLeast1Bjets_pT20++;

        if (nSigJet50 < 4) pass_emu = false;
        if (pass_emu) n_CutFlow_emu_AtLeast4Jets_pt50++;
    }
    if (channel == 3) {  // mumu
        n_CutFlow_mumu_ChanSep++;

        bool pass_mumu = true;
        if (vec_signal_bjet.size() < 1) pass_mumu = false;
        if (pass_mumu) n_CutFlow_mumu_AtLeast1Bjets_pT20++;

        if (nSigJet50 < 4) pass_mumu = false;
        if (pass_mumu) n_CutFlow_mumu_AtLeast4Jets_pt50++;
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

void yt_skim_data::tag_and_probe_Zee(int run_number)
{
    // Z T&P method

    // Electrons:
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
            // Ximo said let all lepton trigger matching
            isTriggerMatched = true;

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
                    El_isZProbe_TriggMatched->at(probe_elec_itr.get_index()) = true;
                n_tot_ZTandP_electrons++;
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
            // Ximo said let all lepton trigger matching
            isTriggerMatched = true;

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
                    Mu_isZProbe_TriggMatched->at(probe_muon_itr.get_index()) = true;
                n_tot_ZTandP_muons++;
            }
        }
        Mu_ZTandP_mll->at(probe_muon_itr.get_index()) = best_match_mll;
    }



/*
    // Electrons:
    for (auto & tag_elec_itr : vec_signal_elec) {
        if (tag_elec_itr.get_pt() < 25000.)
            continue;
        if (fabs(tag_elec_itr.get_eta()) > 2.0)
            continue;

        // Check does the tag trigger matched
        bool isTriggerMatched = false;
//
        //if (is_v23) { if ( El_trigMatch_e24_lhmedium_L1EM20VH->at(tag_electron.index) ) isTriggerMatched = true; }
        //else if ( "Data_v22" != process ) { if ( El_trigMatch_e24_lhmedium_iloose_L1EM20VH->at(tag_electron.index) ) isTriggerMatched = true; }
//
//
        if (run_number < 290000) {
            // use 2015 data trigger
            if (tag_elec_itr.get_trigMatch_2e12_lhloose_L12EM10VH())
                isTriggerMatched = true;
        }
        else if (run_number > 290000) {
            // use 2016 data trigger
            if (tag_elec_itr.get_trigMatch_2e17_lhvloose_nod0())
                isTriggerMatched = true;
        }
//
        // Ximo said let all lepton trigger matching
        isTriggerMatched = true;      

        // Set the tag TLorentzVector ( to compute mll )
        TLorentzVector tlv_tag;
        TLorentzVector tlv_probe;
        
        double best_match_mll = 1000000.;
        //int best_match_index = 99;

        // Probe loop
        for (auto & probe_elec_itr : vec_baseline_elec) {
            if (tag_elec_itr.get_index() == probe_elec_itr.get_index())
                continue;
            // Opposite Charge requirement
            if (probe_elec_itr.get_charge() == tag_elec_itr.get_charge())
                continue;
            tlv_tag.SetPtEtaPhiM(tag_elec_itr.get_pt(), tag_elec_itr.get_eta(), tag_elec_itr.get_phi(), tag_elec_itr.get_M());
            tlv_probe.SetPtEtaPhiM(probe_elec_itr.get_pt(), probe_elec_itr.get_eta(), probe_elec_itr.get_phi(), probe_elec_itr.get_M());
            double current_mll = (tlv_tag + tlv_probe).M();
//
            if (fabs(current_mll - 91.1876 * 1000.) < fabs(best_match_mll - 91.1876 * 1000.)) {
                best_match_mll = current_mll;
                best_match_index = probe_elec_itr.get_index();
            }
//
            // mll window cut
//
            double probe_mll = (tlv_tag + tlv_probe).M();           
            if (probe_mll < 80000. || probe_mll > 100000. )
                continue;
//
            if (current_mll > 80000. && current_mll < 100000.) {
                El_isZProbe->at(probe_elec_itr.get_index()) = true;
                if (isTriggerMatched)
                    El_isZProbe_TriggMatched->at(probe_elec_itr.get_index()) = true;
                n_tot_ZTandP_electrons++;
            }
        }
//      El_ZTandP_mll->at(best_match_index) = best_match_mll;
    }

    // Muons
    for (auto & tag_muon_itr : vec_signal_muon) {
        if (tag_muon_itr.get_pt() < 25000.) continue;

        // Check does the tag tragger matched
        bool isTriggerMatched = false;
//
        //if (is_v23) { if ( Mu_trigMatch_MU15 ->at(tag_muon.index) ) isTriggerMatched = true; }
        //else if ( "Data_v22" != process ) { if ( Mu_trigMatch_mu26_imedium->at(tag_muon.index) ) isTriggerMatched = true; }
//
//
        if (run_number < 290000) {
            // use 2015 data trigger
            if (tag_muon_itr.get_trigMatch_mu18_mu8noL1())
                isTriggerMatched = true;
        }
        else if (run_number > 290000) {
            // use 2016 data trigger
            if (tag_muon_itr.get_trigMatch_mu20_mu8noL1())
                isTriggerMatched = true;
        }
//
        // Ximo said let all lepton trigger matching
        isTriggerMatched = true;      

        // Set the tag TLorentzVector ( to compute mll )
        TLorentzVector tlv_tag;
        TLorentzVector tlv_probe;

        double best_match_mll = 1000000.;
        int best_match_index = 99;

        // Probe loop
        for (auto & probe_muon_itr : vec_baseline_muon) {
            if (tag_muon_itr.get_index() == probe_muon_itr.get_index())
                continue;
            // Opposite Charge requirement
            if (probe_muon_itr.get_charge() == tag_muon_itr.get_charge())
                continue;
            tlv_tag.SetPtEtaPhiM(tag_muon_itr.get_pt(), tag_muon_itr.get_eta(), tag_muon_itr.get_phi(), tag_muon_itr.get_M());
            tlv_probe.SetPtEtaPhiM( probe_muon_itr.get_pt(), probe_muon_itr.get_eta(), probe_muon_itr.get_phi(), probe_muon_itr.get_M());
            double current_mll = (tlv_tag + tlv_probe).M();
//
            if (fabs(current_mll - 91.1876 * 1000.) < fabs(best_match_mll - 91.1876 * 1000.)) {
                best_match_mll = current_mll;
                best_match_index = probe_muon_itr.get_index();
            }
//
            // mll window cut
//
            double probe_mll = (tlv_tag + tlv_probe).M();
            if (probe_mll < 80000. || probe_mll > 100000. )
                continue;
//
            if (current_mll > 80000. && current_mll < 100000.) {
                Mu_isZProbe->at(probe_muon_itr.get_index()) = true;
                if (isTriggerMatched)
                    Mu_isZProbe_TriggMatched->at(probe_muon_itr.get_index()) = true;
                n_tot_ZTandP_muons++;
            }
        }
//      Mu_ZTandP_mll->at(best_match_index) = best_match_mll;
    }

    // find the best Z mass match, baseline letpon loop (probes)
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
//
            if (run_number < 290000) {
                // use 2015 data trigger
                if (tag_elec_itr.get_trigMatch_2e12_lhloose_L12EM10VH() == false)
                    continue; 
            }
            else if (run_number > 290000) {
                // use 2016 data trigger
                if (tag_elec_itr.get_trigMatch_2e17_lhvloose_nod0() == false)
                    continue; 
            }
//
            // Opposite Charge requirement
            if (tag_elec_itr.get_charge() == probe_elec_itr.get_charge())
                continue;

            TLorentzVector tlv_tag;
            TLorentzVector tlv_probe;
            tlv_tag.SetPtEtaPhiM(tag_elec_itr.get_pt(), tag_elec_itr.get_eta(), tag_elec_itr.get_phi(), tag_elec_itr.get_M());
            tlv_probe.SetPtEtaPhiM(probe_elec_itr.get_pt(), probe_elec_itr.get_eta(), probe_elec_itr.get_phi(), probe_elec_itr.get_M());
            double current_mll = (tlv_tag + tlv_probe).M();
            if (fabs(current_mll - 91.1876 * 1000.) < fabs(best_match_mll - 91.1876 * 1000.))
                best_match_mll = current_mll;
        }
        El_ZTandP_mll->at(probe_elec_itr.get_index()) = best_match_mll;
    }   

    // Muon
    for (auto & probe_muon_itr : vec_baseline_muon) {
        double best_match_mll = 1000000.;
        for (auto & tag_muon_itr : vec_signal_muon) {
            if (tag_muon_itr.get_index() == probe_muon_itr.get_index())
                continue;
            if (tag_muon_itr.get_pt() < 25000)
                continue;
//
            if (run_number < 290000) {
                // use 2015 data trigger
                if (tag_muon_itr.get_trigMatch_mu18_mu8noL1() == false)
                    continue;
            }
            else if (run_number > 290000) {
                // use 2016 data trigger
                if (tag_muon_itr.get_trigMatch_mu20_mu8noL1() == false)
                    continue;
            }
//
            // Opposite Charge requirement
            if (tag_muon_itr.get_charge() == probe_muon_itr.get_charge())
                continue;
            TLorentzVector tlv_tag;
            TLorentzVector tlv_probe;
            tlv_tag.SetPtEtaPhiM(tag_muon_itr.get_pt(), tag_muon_itr.get_eta(), tag_muon_itr.get_phi(), tag_muon_itr.get_M());
            tlv_probe.SetPtEtaPhiM(probe_muon_itr.get_pt(), probe_muon_itr.get_eta(), probe_muon_itr.get_phi(), probe_muon_itr.get_M());
            double current_mll = (tlv_tag + tlv_probe).M();
            if (fabs(current_mll - 91.1876 * 1000.) < fabs(best_match_mll - 91.1876 * 1000.))
                best_match_mll = current_mll;
        }
        Mu_ZTandP_mll->at(probe_muon_itr.get_index()) = best_match_mll;
    }
*/
}

void yt_skim_data::tag_and_probe_ttbar(double Etmiss_TST_Et)
{
    // ttbar T&P method
    // Event selection
    bool isTTbarTandP = true;

    // Requiering exactly 2 baseline leptons
    //if (n_baseline_electrons + n_baseline_muons != 2)
    if (vec_baseline_elec.size() + vec_baseline_muon.size() != 2)
        isTTbarTandP = false;
    if (isTTbarTandP)
        n_tot_2baseline_leptons++;

    // Requiering 2 bjets at 70 efficeincy
    if (vec_signal_bjet.size() != 2)
        isTTbarTandP = false;
    if (isTTbarTandP)
        n_2Baseline_Bjets_Events++;

    // Etmiss > 30 GeV  for ee and mumu
    if ((vec_baseline_lept.at(0).get_flavor() == 11 && vec_baseline_lept.at(1).get_flavor() == 11) ||
        (vec_baseline_lept.at(0).get_flavor() == 13 && vec_baseline_lept.at(1).get_flavor() == 13)) {
            if (Etmiss_TST_Et < 30000.)
                isTTbarTandP = false;
    }
    if (isTTbarTandP)
        n_TTbarEtmiss_Events++;

    // mll window cut
    if ((vec_baseline_lept.at(0).get_flavor() == 11 && vec_baseline_lept.at(1).get_flavor() == 11) ||
        (vec_baseline_lept.at(0).get_flavor() == 13 && vec_baseline_lept.at(1).get_flavor() == 13)) {
        if (baseline_mll > 70000. && baseline_mll < 100000.) // Z peak region
            isTTbarTandP = false;
    }
    if (isTTbarTandP)
        n_TTbarMll_Events++;

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
                }
                if (probe_lept_itr.get_flavor() == 13) {
                    Mu_isTTbarProbe->at(probe_lept_itr.get_index()) = true;
                    n_tot_TTbarTandP_muons++;
                }
            }
        }
    }
}