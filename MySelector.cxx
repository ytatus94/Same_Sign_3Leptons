#define MYSELECTOR_CXX
// The class definition in AnaNtupSelector.h has been generated automatically
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
// Root > T->Process("AnaNtupSelector.C")
// Root > T->Process("AnaNtupSelector.C","some options")
// Root > T->Process("AnaNtupSelector.C+")
//

#include "MySelector.h"
#include <TH2.h>
#include <TStyle.h>

const char* cut_name[] = {
    "Cut 0: All events before derivations (DerivationStat_Weights)",
    "Cut 1: All events in derivation/ntuple",
    "Cut 2: GRL (for data only)",
    "Cut 3: Trigger",
    "Cut 4: Global flags (data only)",
    "Cut 5: Jet and muon cleaning",
    "Cut 6: Primary Vertex",
    "Cut 7: Cosmics veto",
    "Cut 8: ≥ 2 baseline leptons (>10 GeV)",
    "Cut 9: ≥ 2 signal leptons (>20 GeV)",
    // El-El channel
    "Cut 10: Channel selection (20, 20 GeV): el-el",
    "Cut 11: Trigger: el-el",
    "Cut 12: ml1l2 > 12 GeV: el-el",
    "Cut 13: ≥ 1 b jet (>20 GeV): el-el",
    "Cut 14: ≥ 4 jets (>50GeV): el-el",
    "Cut 15: Same sign leptons: el-el",
    "Cut 16: MET > 150 GeV: el-el",
    // El-Mu channel
    "Cut 10: Channel selection (20, 20 GeV): el-mu",
    "Cut 11: Trigger: el-mu",
    "Cut 12: ml1l2 > 12 GeV: el-mu",
    "Cut 13: ≥ 1 b jet (>20 GeV): el-mu",
    "Cut 14: ≥ 4 jets (>50GeV): el-mu",
    "Cut 15: Same sign leptons: el-mu",
    "Cut 16: MET > 150 GeV: el-mu",
    // Mu-Mu channel
    "Cut 10: Channel selection (20, 20 GeV): mu-mu",
    "Cut 11: Trigger: mu-mu",
    "Cut 12: ml1l2 > 12 GeV: mu-mu",
    "Cut 13: ≥ 1 b jet (>20 GeV): mu-mu",
    "Cut 14: ≥ 4 jets (>50GeV): mu-mu",
    "Cut 15: Same sign leptons: mu-mu",
    "Cut 16: MET > 150 GeV: mu-mu"
};

void MySelector::Fill_electrons(Int_t            NEl,
                                int              flavor,
                                vector<double>   *El_eta,
                                vector<double>   *El_phi,
                                vector<double>   *El_pT,
                                vector<double>   *El_E,
                                vector<int>      *El_charge,
                                vector<double>   *El_sigd0,
                                vector<double>   *El_z0pvtx,
                                vector<double>   *El_d0pvtx,
                                vector<double>   *El_SFwMedium,
                                vector<double>   *El_SFwMediumLH,
                                vector<double>   *El_SFwTight,
                                vector<double>   *El_SFwTightLH,
                                vector<bool>     *El_isLooseLH,
                                vector<bool>     *El_isMediumLH,
                                vector<bool>     *El_isTightLH,
                                vector<bool>     *El_isLoose,
                                vector<bool>     *El_isMedium,
                                vector<bool>     *El_isTight,
                                vector<double>   *El_ptcone20,
                                vector<double>   *El_ptcone30,
                                vector<double>   *El_ptcone40,
                                vector<double>   *El_ptvarcone20,
                                vector<double>   *El_ptvarcone30,
                                vector<double>   *El_ptvarcone40,
                                vector<double>   *El_topoetcone20,
                                vector<double>   *El_topoetcone30,
                                vector<double>   *El_topoetcone40,
                                vector<bool>     *El_passIsoVeryLooseTO,
                                vector<bool>     *El_passIsoVeryLoose,
                                vector<bool>     *El_passIsoLoose,
                                vector<bool>     *El_passIsoTight,
                                vector<bool>     *El_passIsoGrad,
                                vector<bool>     *El_passIsoGradCustom,
                                vector<bool>     *El_passIsoGradLoose)
{
    for (int i = 0; i < NEl; i++) {
        Electron el;
        el.set_number(NEl);
        el.set_flavor(flavor);
        el.set_eta( (*El_eta)[i] );
        el.set_phi( (*El_phi)[i] );
        el.set_pt( (*El_pT)[i] );
        el.set_E( (*El_E)[i] );
        el.set_charge( (*El_charge)[i] );
        el.set_sigd0( (*El_sigd0)[i] );
        el.set_z0pvtx( (*El_z0pvtx)[i] );
        el.set_d0pvtx( (*El_d0pvtx)[i] );
        el.set_SFwMedium( (*El_SFwMedium)[i] );
        el.set_SFwMediumLH( (*El_SFwMediumLH)[i] );
        el.set_SFwTight( (*El_SFwTight)[i] );
        el.set_SFwTightLH( (*El_SFwTightLH)[i] );
        el.set_isLooseLH( (*El_isLooseLH)[i] );
        el.set_isMediumLH( (*El_isMediumLH)[i] );
        el.set_isTightLH( (*El_isTightLH)[i] );
        el.set_isLoose( (*El_isLoose)[i] );
        el.set_isMedium( (*El_isMedium)[i] );
        el.set_isTight( (*El_isTight)[i] );
        el.set_ptcone20( (*El_ptcone20)[i] );
        el.set_ptcone30( (*El_ptcone30)[i] );
        el.set_ptcone40( (*El_ptcone40)[i] );
        el.set_ptvarcone20( (*El_ptvarcone20)[i] );
        el.set_ptvarcone30( (*El_ptvarcone30)[i] );
        el.set_ptvarcone40( (*El_ptvarcone40)[i] );
        el.set_topoetcone20( (*El_topoetcone20)[i] );
        el.set_topoetcone30( (*El_topoetcone30)[i] );
        el.set_topoetcone40( (*El_topoetcone40)[i] );
        el.set_passIsoVeryLooseTO( (*El_passIsoVeryLooseTO)[i] );
        el.set_passIsoVeryLoose( (*El_passIsoVeryLoose)[i] );
        el.set_passIsoLoose( (*El_passIsoLoose)[i] );
        el.set_passIsoTight( (*El_passIsoTight)[i] );
        el.set_passIsoGrad( (*El_passIsoGrad)[i] );
        el.set_passIsoGradCustom( (*El_passIsoGradCustom)[i] );
        el.set_passIsoGradLoose( (*El_passIsoGradLoose)[i] );
        el.set_TLV_E(el.get_pt(), el.get_eta(), el.get_phi(), el.get_E());
        vec_elec.push_back(el);
    }
}

void MySelector::Fill_muons(Int_t            NMu,
                            int              flavor,
                            vector<double>   *Mu_eta,
                            vector<double>   *Mu_phi,
                            vector<double>   *Mu_pT,
                            vector<double>   *Mu_SFw,
                            vector<int>      *Mu_charge,
                            vector<double>   *Mu_d0pvtx,
                            vector<double>   *Mu_sigd0,
                            vector<double>   *Mu_z0pvtx,
                            vector<bool>     *Mu_isBad,
                            vector<bool>     *Mu_isCosmic,
                            vector<double>   *Mu_ptcone20,
                            vector<double>   *Mu_ptcone30,
                            vector<double>   *Mu_ptcone40,
                            vector<double>   *Mu_ptvarcone20,
                            vector<double>   *Mu_ptvarcone30,
                            vector<double>   *Mu_ptvarcone40,
                            vector<double>   *Mu_topoetcone20,
                            vector<double>   *Mu_topoetcone30,
                            vector<double>   *Mu_topoetcone40,
                            vector<bool>     *Mu_passIsoVeryLooseTO,
                            vector<bool>     *Mu_passIsoVeryLoose,
                            vector<bool>     *Mu_passIsoLoose,
                            vector<bool>     *Mu_passIsoTight,
                            vector<bool>     *Mu_passIsoGrad,
                            vector<bool>     *Mu_passIsoGradCustom,
                            vector<bool>     *Mu_passIsoGradLoose)
{
    for (int i = 0; i < NMu; i++) {
        Muon mu;
        mu.set_number(NMu);
        mu.set_flavor(flavor);
        mu.set_eta( (*Mu_eta)[i] );
        mu.set_phi( (*Mu_phi)[i] );
        mu.set_pt( (*Mu_pT)[i] );
        mu.set_SFw( (*Mu_SFw)[i] );
        mu.set_charge( (*Mu_charge)[i] );
        mu.set_d0pvtx( (*Mu_d0pvtx)[i] );
        mu.set_sigd0( (*Mu_sigd0)[i] );
        mu.set_z0pvtx( (*Mu_z0pvtx)[i] );
        mu.set_isBad( (*Mu_isBad)[i] );
        mu.set_isCosmic( (*Mu_isCosmic)[i] );
        mu.set_ptcone20( (*Mu_ptcone20)[i] );
        mu.set_ptcone30( (*Mu_ptcone30)[i] );
        mu.set_ptcone40( (*Mu_ptcone40)[i] );
        mu.set_ptvarcone20( (*Mu_ptvarcone20)[i] );
        mu.set_ptvarcone30( (*Mu_ptvarcone30)[i] );
        mu.set_ptvarcone40( (*Mu_ptvarcone40)[i] );
        mu.set_topoetcone20( (*Mu_topoetcone20)[i] );
        mu.set_topoetcone30( (*Mu_topoetcone30)[i] );
        mu.set_topoetcone40( (*Mu_topoetcone40)[i] );
        mu.set_passIsoVeryLooseTO( (*Mu_passIsoVeryLooseTO)[i] );
        mu.set_passIsoVeryLoose( (*Mu_passIsoVeryLoose)[i] );
        mu.set_passIsoLoose( (*Mu_passIsoLoose)[i] );
        mu.set_passIsoTight( (*Mu_passIsoTight)[i] );
        mu.set_passIsoGrad( (*Mu_passIsoGrad)[i] );
        mu.set_passIsoGradCustom( (*Mu_passIsoGradCustom)[i] );
        mu.set_passIsoGradLoose( (*Mu_passIsoGradLoose)[i] );
        mu.set_TLV_M(mu.get_pt(), mu.get_eta(), mu.get_phi(), Mu_Mass);
        vec_muon.push_back(mu);
    }
}

void MySelector::Fill_jets(Int_t             NJet,
                           vector<double>    *Jet_eta,
                           vector<double>    *Jet_phi,
                           vector<double>    *Jet_pT,
                           vector<double>    *Jet_E,
                           vector<double>    *Jet_quality,
                           vector<double>    *Jet_JVF,
                           vector<double>    *Jet_JVT,
                           vector<double>    *Jet_MV2c20,
                           vector<double>    *Jet_SFw,
                           vector<int>       *Jet_nTrk)

{
    for (int i = 0; i < NJet; i++) {
        Jet je;
        je.set_number(NJet);
        je.set_eta( (*Jet_eta)[i] );
        je.set_phi( (*Jet_phi)[i] );
        je.set_pt( (*Jet_pT)[i] );
        je.set_E( (*Jet_E)[i] );
        je.set_quality( (*Jet_quality)[i] );
        je.set_JVF( (*Jet_JVF)[i] );
        je.set_JVF( (*Jet_JVT)[i] );
        je.set_MV2c20( (*Jet_MV2c20)[i] );
        je.set_SFw( (*Jet_SFw)[i] );
        je.set_nTrk( (*Jet_nTrk)[i] );
        je.set_TLV_E(je.get_pt(), je.get_eta(), je.get_phi(), je.get_E());
        vec_jets.push_back(je);
    }

}

void MySelector::Fill_leptons(vector<Electron> vec_elec, vector<Muon> vec_muon)
{
    for (auto & el_itr : vec_elec) {
        vec_lept.push_back(el_itr);
    }
    for (auto & mu_itr : vec_muon) {
        vec_lept.push_back(mu_itr);
    }
}

void MySelector::Fill_baseline_electrons(vector<Electron> vec_elec)
{
    for (auto & el_itr : vec_elec) {
        if (el_itr.get_baseline() == true &&
            el_itr.get_passOR() == true) {
            vec_OR_elec.push_back(el_itr);
        }
    }
}

void MySelector::Fill_baseline_muons(vector<Muon> vec_muon)
{
    for (auto & mu_itr : vec_muon) {
        if (mu_itr.get_baseline() == true &&
            mu_itr.get_passOR() == true) {
            vec_OR_muon.push_back(mu_itr);
        }
    }
}

void MySelector::Fill_baseline_jets(vector<Jet> jets)
{
    for (auto & jet_itr : vec_jets) {
        if (jet_itr.get_baseline() == true &&
            jet_itr.get_passOR() == true) {
            vec_OR_jets.push_back(jet_itr);
        }
    }
}

void MySelector::Fill_baseline_leptons(vector<Electron> signal_elec, vector<Muon> signal_muon)
{
    for (auto & el_itr : vec_elec) {
        if (el_itr.get_baseline() == true &&
            el_itr.get_passOR() == true) {
            vec_OR_lept.push_back(el_itr);
        }
    }
    for (auto & mu_itr : vec_muon) {
        if (mu_itr.get_baseline() == true &&
            mu_itr.get_passOR() == true) {
            vec_OR_lept.push_back(mu_itr);
        }
    }
}

void MySelector::Fill_signal_electrons(vector<Electron> vec_elec)
{
    for (auto & el_itr : vec_elec) {
        if (el_itr.get_baseline() == true &&
            el_itr.get_passOR() == true &&
            el_itr.get_isSignal() &&
            el_itr.get_pt() > 20000.) {
            vec_signal_elec.push_back(el_itr);
        }
    }
}

void MySelector::Fill_signal_muons(vector<Muon> vec_muon)
{
    for (auto & mu_itr : vec_muon) {
        if (mu_itr.get_baseline() == true &&
            mu_itr.get_passOR() == true &&
            mu_itr.get_isSignal() &&
            mu_itr.get_pt() > 20000.) {
            vec_signal_muon.push_back(mu_itr);
        }
    }
}

void MySelector::Fill_signal_jets(vector<Jet> jets)
{
    for (auto & jet_itr : vec_jets) {
        if (!jet_itr.get_baseline()) continue;
        if (!jet_itr.get_passOR()) continue;
        if (jet_itr.get_quality() == 1) continue; // 1=bad jet from SUSYToo ls IsGoodJet
        if (jet_itr.get_isBjet()) continue;
        if (jet_itr.get_pt() > 50000.) {
            vec_signal_jets.push_back(jet_itr);
        }
    }
}

void MySelector::Fill_signal_leptons(vector<Electron> signal_elec, vector<Muon> signal_muon)
{
    for (auto & el_itr : signal_elec) {
        vec_signal_lept.push_back(el_itr);
    }
    for (auto & mu_itr : signal_muon) {
        vec_signal_lept.push_back(mu_itr);
    }
}

void MySelector::Begin(TTree * /*tree*/)
{
    // The Begin() function is called at the start of the query.
    // When running with PROOF Begin() is only called on the client.
    // The tree argument is deprecated (on PROOF 0 is passed).
    
    TString option = GetOption();
    
    hCutFlows = new TH1F("hCutFlows", "Cut Flows", 31, 0, 31);
    int number_of_bins = sizeof(cut_name) / sizeof( cut_name[0] );
    for (int i = 1; i <= number_of_bins; i++) {
        hCutFlows->GetXaxis()->SetBinLabel(i, cut_name[i - 1]);
    }
    fOutput->Add(hCutFlows);
/*
    // For baseline leptons
    h_mll_baseline_OS_ee    = new TH1F("h_mll_baseline_OS_ee",   "OS M_{ee}",     200, 0, 200);
    h_mll_baseline_OS_emu   = new TH1F("h_mll_baseline_OS_emu",  "OS M_{e#mu}",   200, 0, 200);
    h_mll_baseline_OS_mumu  = new TH1F("h_mll_baseline_OS_mumu", "OS M_{#mu#mu}", 200, 0, 200);
    h_mll_baseline_SS_ee    = new TH1F("h_mll_baseline_SS_ee",   "SS M_{ee}",     200, 0, 200);
    h_mll_baseline_SS_emu   = new TH1F("h_mll_baseline_SS_emu",  "SS M_{e#mu}",   200, 0, 200);
    h_mll_baseline_SS_mumu  = new TH1F("h_mll_baseline_SS_mumu", "SS M_{#mu#mu}", 200, 0, 200);
    fOutput->Add(h_mll_baseline_OS_ee);
    fOutput->Add(h_mll_baseline_OS_emu);
    fOutput->Add(h_mll_baseline_OS_mumu);
    fOutput->Add(h_mll_baseline_SS_ee);
    fOutput->Add(h_mll_baseline_SS_emu);
    fOutput->Add(h_mll_baseline_SS_mumu);
    
    h_ptvarcone20_pt_baseline_OS_ee    = new TH1F("h_ptvarcone20_pt_baseline_OS_ee",   "ptvarcone20/pt OS ee",     100, 0, 1);
    h_ptvarcone20_pt_baseline_OS_emu   = new TH1F("h_ptvarcone20_pt_baseline_OS_emu",  "ptvarcone20/pt OS e#mu",   100, 0, 1);
    h_ptvarcone20_pt_baseline_OS_mumu  = new TH1F("h_ptvarcone20_pt_baseline_OS_mumu", "ptvarcone20/pt OS #mu#mu", 100, 0, 1);
    h_ptvarcone20_pt_baseline_SS_ee    = new TH1F("h_ptvarcone20_pt_baseline_SS_ee",   "ptvarcone20/pt SS ee",     100, 0, 1);
    h_ptvarcone20_pt_baseline_SS_emu   = new TH1F("h_ptvarcone20_pt_baseline_SS_emu",  "ptvarcone20/pt SS e#mu",   100, 0, 1);
    h_ptvarcone20_pt_baseline_SS_mumu  = new TH1F("h_ptvarcone20_pt_baseline_SS_mumu", "ptvarcone20/pt SS #mu#mu", 100, 0, 1);
    fOutput->Add(h_ptvarcone20_pt_baseline_OS_ee);
    fOutput->Add(h_ptvarcone20_pt_baseline_OS_emu);
    fOutput->Add(h_ptvarcone20_pt_baseline_OS_mumu);
    fOutput->Add(h_ptvarcone20_pt_baseline_SS_ee);
    fOutput->Add(h_ptvarcone20_pt_baseline_SS_emu);
    fOutput->Add(h_ptvarcone20_pt_baseline_SS_mumu);
    
    h_ptvarcone30_pt_baseline_OS_ee   = new TH1F("h_ptvarcone30_pt_baseline_OS_ee",   "ptvarcone30/pt OS ee",     100, 0, 1);
    h_ptvarcone30_pt_baseline_OS_emu  = new TH1F("h_ptvarcone30_pt_baseline_OS_emu",  "ptvarcone30/pt OS e#mu",   100, 0, 1);
    h_ptvarcone30_pt_baseline_OS_mumu = new TH1F("h_ptvarcone30_pt_baseline_OS_mumu", "ptvarcone30/pt OS #mu#mu", 100, 0, 1);
    h_ptvarcone30_pt_baseline_SS_ee   = new TH1F("h_ptvarcone30_pt_baseline_SS_ee",   "ptvarcone30/pt SS ee",     100, 0, 1);
    h_ptvarcone30_pt_baseline_SS_emu  = new TH1F("h_ptvarcone30_pt_baseline_SS_emu",  "ptvarcone30/pt SS e#mu",   100, 0, 1);
    h_ptvarcone30_pt_baseline_SS_mumu = new TH1F("h_ptvarcone30_pt_baseline_SS_mumu", "ptvarcone30/pt SS #mu#mu", 100, 0, 1);
    fOutput->Add(h_ptvarcone30_pt_baseline_OS_ee);
    fOutput->Add(h_ptvarcone30_pt_baseline_OS_emu);
    fOutput->Add(h_ptvarcone30_pt_baseline_OS_mumu);
    fOutput->Add(h_ptvarcone30_pt_baseline_SS_ee);
    fOutput->Add(h_ptvarcone30_pt_baseline_SS_emu);
    fOutput->Add(h_ptvarcone30_pt_baseline_SS_mumu);
    
    h_ptvarcone40_pt_baseline_OS_ee   = new TH1F("h_ptvarcone40_pt_baseline_OS_ee",   "ptvarcone40/pt OS ee",     100, 0, 1);
    h_ptvarcone40_pt_baseline_OS_emu  = new TH1F("h_ptvarcone40_pt_baseline_OS_emu",  "ptvarcone40/pt OS e#mu",   100, 0, 1);
    h_ptvarcone40_pt_baseline_OS_mumu = new TH1F("h_ptvarcone40_pt_baseline_OS_mumu", "ptvarcone40/pt OS #mu#mu", 100, 0, 1);
    h_ptvarcone40_pt_baseline_SS_ee   = new TH1F("h_ptvarcone40_pt_baseline_SS_ee",   "ptvarcone40/pt SS ee",     100, 0, 1);
    h_ptvarcone40_pt_baseline_SS_emu  = new TH1F("h_ptvarcone40_pt_baseline_SS_emu",  "ptvarcone40/pt SS e#mu",   100, 0, 1);
    h_ptvarcone40_pt_baseline_SS_mumu = new TH1F("h_ptvarcone40_pt_baseline_SS_mumu", "ptvarcone40/pt SS #mu#mu", 100, 0, 1);
    fOutput->Add(h_ptvarcone40_pt_baseline_OS_ee);
    fOutput->Add(h_ptvarcone40_pt_baseline_OS_emu);
    fOutput->Add(h_ptvarcone40_pt_baseline_OS_mumu);
    fOutput->Add(h_ptvarcone40_pt_baseline_SS_ee);
    fOutput->Add(h_ptvarcone40_pt_baseline_SS_emu);
    fOutput->Add(h_ptvarcone40_pt_baseline_SS_mumu);
    
    h_topoetcone20_pt_baseline_OS_ee   = new TH1F("h_topoetcone20_pt_baseline_OS_ee",   "topoetcone20/pt OS ee",     100, 0, 1);
    h_topoetcone20_pt_baseline_OS_emu  = new TH1F("h_topoetcone20_pt_baseline_OS_emu",  "topoetcone20/pt OS e#mu",   100, 0, 1);
    h_topoetcone20_pt_baseline_OS_mumu = new TH1F("h_topoetcone20_pt_baseline_OS_mumu", "topoetcone20/pt OS #mu#mu", 100, 0, 1);
    h_topoetcone20_pt_baseline_SS_ee   = new TH1F("h_topoetcone20_pt_baseline_SS_ee",   "topoetcone20/pt SS ee",     100, 0, 1);
    h_topoetcone20_pt_baseline_SS_emu  = new TH1F("h_topoetcone20_pt_baseline_SS_emu",  "topoetcone20/pt SS e#mu",   100, 0, 1);
    h_topoetcone20_pt_baseline_SS_mumu = new TH1F("h_topoetcone20_pt_baseline_SS_mumu", "topoetcone20/pt SS #mu#mu", 100, 0, 1);
    fOutput->Add(h_topoetcone20_pt_baseline_OS_ee);
    fOutput->Add(h_topoetcone20_pt_baseline_OS_emu);
    fOutput->Add(h_topoetcone20_pt_baseline_OS_mumu);
    fOutput->Add(h_topoetcone20_pt_baseline_SS_ee);
    fOutput->Add(h_topoetcone20_pt_baseline_SS_emu);
    fOutput->Add(h_topoetcone20_pt_baseline_SS_mumu);
    
    h_topoetcone30_pt_baseline_OS_ee   = new TH1F("h_topoetcone30_pt_baseline_OS_ee",   "topoetcone30/pt OS ee",     100, 0, 1);
    h_topoetcone30_pt_baseline_OS_emu  = new TH1F("h_topoetcone30_pt_baseline_OS_emu",  "topoetcone30/pt OS e#mu",   100, 0, 1);
    h_topoetcone30_pt_baseline_OS_mumu = new TH1F("h_topoetcone30_pt_baseline_OS_mumu", "topoetcone30/pt OS #mu#mu", 100, 0, 1);
    h_topoetcone30_pt_baseline_SS_ee   = new TH1F("h_topoetcone30_pt_baseline_SS_ee",   "topoetcone30/pt SS ee",     100, 0, 1);
    h_topoetcone30_pt_baseline_SS_emu  = new TH1F("h_topoetcone30_pt_baseline_SS_emu",  "topoetcone30/pt SS e#mu",   100, 0, 1);
    h_topoetcone30_pt_baseline_SS_mumu = new TH1F("h_topoetcone30_pt_baseline_SS_mumu", "topoetcone30/pt SS #mu#mu", 100, 0, 1);
    fOutput->Add(h_topoetcone30_pt_baseline_OS_ee);
    fOutput->Add(h_topoetcone30_pt_baseline_OS_emu);
    fOutput->Add(h_topoetcone30_pt_baseline_OS_mumu);
    fOutput->Add(h_topoetcone30_pt_baseline_SS_ee);
    fOutput->Add(h_topoetcone30_pt_baseline_SS_emu);
    fOutput->Add(h_topoetcone30_pt_baseline_SS_mumu);
    
    h_topoetcone40_pt_baseline_OS_ee   = new TH1F("h_topoetcone40_pt_baseline_OS_ee",   "topoetcone40/pt OS ee",     100, 0, 1);
    h_topoetcone40_pt_baseline_OS_emu  = new TH1F("h_topoetcone40_pt_baseline_OS_emu",  "topoetcone40/pt OS e#mu",   100, 0, 1);
    h_topoetcone40_pt_baseline_OS_mumu = new TH1F("h_topoetcone40_pt_baseline_OS_mumu", "topoetcone40/pt OS #mu#mu", 100, 0, 1);
    h_topoetcone40_pt_baseline_SS_ee   = new TH1F("h_topoetcone40_pt_baseline_SS_ee",   "topoetcone40/pt OS ee",     100, 0, 1);
    h_topoetcone40_pt_baseline_SS_emu  = new TH1F("h_topoetcone40_pt_baseline_SS_emu",  "topoetcone40/pt OS e#mu",   100, 0, 1);
    h_topoetcone40_pt_baseline_SS_mumu = new TH1F("h_topoetcone40_pt_baseline_SS_mumu", "topoetcone40/pt OS #mu#mu", 100, 0, 1);
    fOutput->Add(h_topoetcone40_pt_baseline_OS_ee);
    fOutput->Add(h_topoetcone40_pt_baseline_OS_emu);
    fOutput->Add(h_topoetcone40_pt_baseline_OS_mumu);
    fOutput->Add(h_topoetcone40_pt_baseline_SS_ee);
    fOutput->Add(h_topoetcone40_pt_baseline_SS_emu);
    fOutput->Add(h_topoetcone40_pt_baseline_SS_mumu);
    
    // For signal leptons
    h_mll_signal_OS_ee    = new TH1F("h_mll_signal_OS_ee",   "OS M_{ee}",     200, 0, 200);
    h_mll_signal_OS_emu   = new TH1F("h_mll_signal_OS_emu",  "OS M_{e#mu}",   200, 0, 200);
    h_mll_signal_OS_mumu  = new TH1F("h_mll_signal_OS_mumu", "OS M_{#mu#mu}", 200, 0, 200);
    h_mll_signal_SS_ee    = new TH1F("h_mll_signal_SS_ee",   "SS M_{ee}",     200, 0, 200);
    h_mll_signal_SS_emu   = new TH1F("h_mll_signal_SS_emu",  "SS M_{e#mu}",   200, 0, 200);
    h_mll_signal_SS_mumu  = new TH1F("h_mll_signal_SS_mumu", "SS M_{#mu#mu}", 200, 0, 200);
    fOutput->Add(h_mll_signal_OS_ee);
    fOutput->Add(h_mll_signal_OS_emu);
    fOutput->Add(h_mll_signal_OS_mumu);
    fOutput->Add(h_mll_signal_SS_ee);
    fOutput->Add(h_mll_signal_SS_emu);
    fOutput->Add(h_mll_signal_SS_mumu);
    
    h_ptvarcone20_pt_signal_OS_ee    = new TH1F("h_ptvarcone20_pt_signal_OS_ee",   "ptvarcone20/pt OS ee",     100, 0, 1);
    h_ptvarcone20_pt_signal_OS_emu   = new TH1F("h_ptvarcone20_pt_signal_OS_emu",  "ptvarcone20/pt OS e#mu",   100, 0, 1);
    h_ptvarcone20_pt_signal_OS_mumu  = new TH1F("h_ptvarcone20_pt_signal_OS_mumu", "ptvarcone20/pt OS #mu#mu", 100, 0, 1);
    h_ptvarcone20_pt_signal_SS_ee    = new TH1F("h_ptvarcone20_pt_signal_SS_ee",   "ptvarcone20/pt SS ee",     100, 0, 1);
    h_ptvarcone20_pt_signal_SS_emu   = new TH1F("h_ptvarcone20_pt_signal_SS_emu",  "ptvarcone20/pt SS e#mu",   100, 0, 1);
    h_ptvarcone20_pt_signal_SS_mumu  = new TH1F("h_ptvarcone20_pt_signal_SS_mumu", "ptvarcone20/pt SS #mu#mu", 100, 0, 1);
    fOutput->Add(h_ptvarcone20_pt_signal_OS_ee);
    fOutput->Add(h_ptvarcone20_pt_signal_OS_emu);
    fOutput->Add(h_ptvarcone20_pt_signal_OS_mumu);
    fOutput->Add(h_ptvarcone20_pt_signal_SS_ee);
    fOutput->Add(h_ptvarcone20_pt_signal_SS_emu);
    fOutput->Add(h_ptvarcone20_pt_signal_SS_mumu);
    
    h_ptvarcone30_pt_signal_OS_ee   = new TH1F("h_ptvarcone30_pt_signal_OS_ee",   "ptvarcone30/pt OS ee",     100, 0, 1);
    h_ptvarcone30_pt_signal_OS_emu  = new TH1F("h_ptvarcone30_pt_signal_OS_emu",  "ptvarcone30/pt OS e#mu",   100, 0, 1);
    h_ptvarcone30_pt_signal_OS_mumu = new TH1F("h_ptvarcone30_pt_signal_OS_mumu", "ptvarcone30/pt OS #mu#mu", 100, 0, 1);
    h_ptvarcone30_pt_signal_SS_ee   = new TH1F("h_ptvarcone30_pt_signal_SS_ee",   "ptvarcone30/pt SS ee",     100, 0, 1);
    h_ptvarcone30_pt_signal_SS_emu  = new TH1F("h_ptvarcone30_pt_signal_SS_emu",  "ptvarcone30/pt SS e#mu",   100, 0, 1);
    h_ptvarcone30_pt_signal_SS_mumu = new TH1F("h_ptvarcone30_pt_signal_SS_mumu", "ptvarcone30/pt SS #mu#mu", 100, 0, 1);
    fOutput->Add(h_ptvarcone30_pt_signal_OS_ee);
    fOutput->Add(h_ptvarcone30_pt_signal_OS_emu);
    fOutput->Add(h_ptvarcone30_pt_signal_OS_mumu);
    fOutput->Add(h_ptvarcone30_pt_signal_SS_ee);
    fOutput->Add(h_ptvarcone30_pt_signal_SS_emu);
    fOutput->Add(h_ptvarcone30_pt_signal_SS_mumu);
    
    h_ptvarcone40_pt_signal_OS_ee   = new TH1F("h_ptvarcone40_pt_signal_OS_ee",   "ptvarcone40/pt OS ee",     100, 0, 1);
    h_ptvarcone40_pt_signal_OS_emu  = new TH1F("h_ptvarcone40_pt_signal_OS_emu",  "ptvarcone40/pt OS e#mu",   100, 0, 1);
    h_ptvarcone40_pt_signal_OS_mumu = new TH1F("h_ptvarcone40_pt_signal_OS_mumu", "ptvarcone40/pt OS #mu#mu", 100, 0, 1);
    h_ptvarcone40_pt_signal_SS_ee   = new TH1F("h_ptvarcone40_pt_signal_SS_ee",   "ptvarcone40/pt SS ee",     100, 0, 1);
    h_ptvarcone40_pt_signal_SS_emu  = new TH1F("h_ptvarcone40_pt_signal_SS_emu",  "ptvarcone40/pt SS e#mu",   100, 0, 1);
    h_ptvarcone40_pt_signal_SS_mumu = new TH1F("h_ptvarcone40_pt_signal_SS_mumu", "ptvarcone40/pt SS #mu#mu", 100, 0, 1);
    fOutput->Add(h_ptvarcone40_pt_signal_OS_ee);
    fOutput->Add(h_ptvarcone40_pt_signal_OS_emu);
    fOutput->Add(h_ptvarcone40_pt_signal_OS_mumu);
    fOutput->Add(h_ptvarcone40_pt_signal_SS_ee);
    fOutput->Add(h_ptvarcone40_pt_signal_SS_emu);
    fOutput->Add(h_ptvarcone40_pt_signal_SS_mumu);
    
    h_topoetcone20_pt_signal_OS_ee   = new TH1F("h_topoetcone20_pt_signal_OS_ee",   "topoetcone20/pt OS ee",     100, 0, 1);
    h_topoetcone20_pt_signal_OS_emu  = new TH1F("h_topoetcone20_pt_signal_OS_emu",  "topoetcone20/pt OS e#mu",   100, 0, 1);
    h_topoetcone20_pt_signal_OS_mumu = new TH1F("h_topoetcone20_pt_signal_OS_mumu", "topoetcone20/pt OS #mu#mu", 100, 0, 1);
    h_topoetcone20_pt_signal_SS_ee   = new TH1F("h_topoetcone20_pt_signal_SS_ee",   "topoetcone20/pt SS ee",     100, 0, 1);
    h_topoetcone20_pt_signal_SS_emu  = new TH1F("h_topoetcone20_pt_signal_SS_emu",  "topoetcone20/pt SS e#mu",   100, 0, 1);
    h_topoetcone20_pt_signal_SS_mumu = new TH1F("h_topoetcone20_pt_signal_SS_mumu", "topoetcone20/pt SS #mu#mu", 100, 0, 1);
    fOutput->Add(h_topoetcone20_pt_signal_OS_ee);
    fOutput->Add(h_topoetcone20_pt_signal_OS_emu);
    fOutput->Add(h_topoetcone20_pt_signal_OS_mumu);
    fOutput->Add(h_topoetcone20_pt_signal_SS_ee);
    fOutput->Add(h_topoetcone20_pt_signal_SS_emu);
    fOutput->Add(h_topoetcone20_pt_signal_SS_mumu);
    
    h_topoetcone30_pt_signal_OS_ee   = new TH1F("h_topoetcone30_pt_signal_OS_ee",   "topoetcone30/pt OS ee",     100, 0, 1);
    h_topoetcone30_pt_signal_OS_emu  = new TH1F("h_topoetcone30_pt_signal_OS_emu",  "topoetcone30/pt OS e#mu",   100, 0, 1);
    h_topoetcone30_pt_signal_OS_mumu = new TH1F("h_topoetcone30_pt_signal_OS_mumu", "topoetcone30/pt OS #mu#mu", 100, 0, 1);
    h_topoetcone30_pt_signal_SS_ee   = new TH1F("h_topoetcone30_pt_signal_SS_ee",   "topoetcone30/pt SS ee",     100, 0, 1);
    h_topoetcone30_pt_signal_SS_emu  = new TH1F("h_topoetcone30_pt_signal_SS_emu",  "topoetcone30/pt SS e#mu",   100, 0, 1);
    h_topoetcone30_pt_signal_SS_mumu = new TH1F("h_topoetcone30_pt_signal_SS_mumu", "topoetcone30/pt SS #mu#mu", 100, 0, 1);
    fOutput->Add(h_topoetcone30_pt_signal_OS_ee);
    fOutput->Add(h_topoetcone30_pt_signal_OS_emu);
    fOutput->Add(h_topoetcone30_pt_signal_OS_mumu);
    fOutput->Add(h_topoetcone30_pt_signal_SS_ee);
    fOutput->Add(h_topoetcone30_pt_signal_SS_emu);
    fOutput->Add(h_topoetcone30_pt_signal_SS_mumu);
    
    h_topoetcone40_pt_signal_OS_ee   = new TH1F("h_topoetcone40_pt_signal_OS_ee",   "topoetcone40/pt OS ee",     100, 0, 1);
    h_topoetcone40_pt_signal_OS_emu  = new TH1F("h_topoetcone40_pt_signal_OS_emu",  "topoetcone40/pt OS e#mu",   100, 0, 1);
    h_topoetcone40_pt_signal_OS_mumu = new TH1F("h_topoetcone40_pt_signal_OS_mumu", "topoetcone40/pt OS #mu#mu", 100, 0, 1);
    h_topoetcone40_pt_signal_SS_ee   = new TH1F("h_topoetcone40_pt_signal_SS_ee",   "topoetcone40/pt OS ee",     100, 0, 1);
    h_topoetcone40_pt_signal_SS_emu  = new TH1F("h_topoetcone40_pt_signal_SS_emu",  "topoetcone40/pt OS e#mu",   100, 0, 1);
    h_topoetcone40_pt_signal_SS_mumu = new TH1F("h_topoetcone40_pt_signal_SS_mumu", "topoetcone40/pt OS #mu#mu", 100, 0, 1);
    fOutput->Add(h_topoetcone40_pt_signal_OS_ee);
    fOutput->Add(h_topoetcone40_pt_signal_OS_emu);
    fOutput->Add(h_topoetcone40_pt_signal_OS_mumu);
    fOutput->Add(h_topoetcone40_pt_signal_SS_ee);
    fOutput->Add(h_topoetcone40_pt_signal_SS_emu);
    fOutput->Add(h_topoetcone40_pt_signal_SS_mumu);

    // For jets
    h_jet_multiplicities_pt20_OS_ee   = new TH1F("h_jet_multiplicities_pt20_OS_ee",   "Jet multiplicities pT>20GeV OS ee",     10, 0, 10);
    h_jet_multiplicities_pt20_OS_emu  = new TH1F("h_jet_multiplicities_pt20_OS_emu",  "Jet multiplicities pT>20GeV OS e#mu",   10, 0, 10);
    h_jet_multiplicities_pt20_OS_mumu = new TH1F("h_jet_multiplicities_pt20_OS_mumu", "Jet multiplicities pT>20GeV OS #mu#mu", 10, 0, 10);
    h_jet_multiplicities_pt20_SS_ee   = new TH1F("h_jet_multiplicities_pt20_SS_ee",   "Jet multiplicities pT>20GeV SS ee",     10, 0, 10);
    h_jet_multiplicities_pt20_SS_emu  = new TH1F("h_jet_multiplicities_pt20_SS_emu",  "Jet multiplicities pT>20GeV SS e#mu",   10, 0, 10);
    h_jet_multiplicities_pt20_SS_mumu = new TH1F("h_jet_multiplicities_pt20_SS_mumu", "Jet multiplicities pT>20GeV SS #mu#mu", 10, 0, 10);
    fOutput->Add(h_jet_multiplicities_pt20_OS_ee);
    fOutput->Add(h_jet_multiplicities_pt20_OS_emu);
    fOutput->Add(h_jet_multiplicities_pt20_OS_mumu);
    fOutput->Add(h_jet_multiplicities_pt20_SS_ee);
    fOutput->Add(h_jet_multiplicities_pt20_SS_emu);
    fOutput->Add(h_jet_multiplicities_pt20_SS_mumu);
    
    h_jet_multiplicities_pt50_OS_ee   = new TH1F("h_jet_multiplicities_pt50_OS_ee",   "Jet multiplicities pT>50GeV OS ee",     10, 0, 10);
    h_jet_multiplicities_pt50_OS_emu  = new TH1F("h_jet_multiplicities_pt50_OS_emu",  "Jet multiplicities pT>50GeV OS e#mu",   10, 0, 10);
    h_jet_multiplicities_pt50_OS_mumu = new TH1F("h_jet_multiplicities_pt50_OS_mumu", "Jet multiplicities pT>50GeV OS #mu#mu", 10, 0, 10);
    h_jet_multiplicities_pt50_SS_ee   = new TH1F("h_jet_multiplicities_pt50_SS_ee",   "Jet multiplicities pT>50GeV SS ee",     10, 0, 10);
    h_jet_multiplicities_pt50_SS_emu  = new TH1F("h_jet_multiplicities_pt50_SS_emu",  "Jet multiplicities pT>50GeV SS e#mu",   10, 0, 10);
    h_jet_multiplicities_pt50_SS_mumu = new TH1F("h_jet_multiplicities_pt50_SS_mumu", "Jet multiplicities pT>50GeV SS #mu#mu", 10, 0, 10);
    fOutput->Add(h_jet_multiplicities_pt50_OS_ee);
    fOutput->Add(h_jet_multiplicities_pt50_OS_emu);
    fOutput->Add(h_jet_multiplicities_pt50_OS_mumu);
    fOutput->Add(h_jet_multiplicities_pt50_SS_ee);
    fOutput->Add(h_jet_multiplicities_pt50_SS_emu);
    fOutput->Add(h_jet_multiplicities_pt50_SS_mumu);
    
    h_pt_1st_jets = new TH1F("h_pt_1st_jets", "Jet pT 1st", 20, 0, 200);
    h_pt_2nd_jets = new TH1F("h_pt_2nd_jets", "Jet pT 2nd", 20, 0, 200);
    h_pt_3rd_jets = new TH1F("h_pt_3rd_jets", "Jet pT 3rd", 20, 0, 200);
    h_pt_4th_jets = new TH1F("h_pt_4th_jets", "Jet pT 4th", 20, 0, 200);
	
	fOutput->Add(h_pt_1st_jets); 
	fOutput->Add(h_pt_2nd_jets); 
	fOutput->Add(h_pt_3rd_jets); 
	fOutput->Add(h_pt_4th_jets); 

    // For Etmiss (baseline)
    h_MET_baseline_OS_ee   = new TH1F("h_MET_baseline_OS_ee",   "E_{T}^{miss} OS ee",     20, 0,200);
    h_MET_baseline_OS_emu  = new TH1F("h_MET_baseline_OS_emu",  "E_{T}^{miss} OS e#mu",   20, 0,200);
    h_MET_baseline_OS_mumu = new TH1F("h_MET_baseline_OS_mumu", "E_{T}^{miss} OS #mu#mu", 20, 0,200);
    h_MET_baseline_SS_ee   = new TH1F("h_MET_baseline_SS_ee",   "E_{T}^{miss} SS ee",     20, 0,200);
    h_MET_baseline_SS_emu  = new TH1F("h_MET_baseline_SS_emu",  "E_{T}^{miss} SS e#mu",   20, 0,200);
    h_MET_baseline_SS_mumu = new TH1F("h_MET_baseline_SS_mumu", "E_{T}^{miss} SS #mu#mu", 20, 0,200);
	fOutput->Add(h_MET_baseline_OS_ee);
	fOutput->Add(h_MET_baseline_OS_emu);
	fOutput->Add(h_MET_baseline_OS_mumu);
	fOutput->Add(h_MET_baseline_SS_ee);
	fOutput->Add(h_MET_baseline_SS_emu);
	fOutput->Add(h_MET_baseline_SS_mumu);

    // For Etmiss (signal)
    h_MET_signal_OS_ee   = new TH1F("h_MET_signal_OS_ee",   "E_{T}^{miss} OS ee",     20, 0,200);
    h_MET_signal_OS_emu  = new TH1F("h_MET_signal_OS_emu",  "E_{T}^{miss} OS e#mu",   20, 0,200);
    h_MET_signal_OS_mumu = new TH1F("h_MET_signal_OS_mumu", "E_{T}^{miss} OS #mu#mu", 20, 0,200);
    h_MET_signal_SS_ee   = new TH1F("h_MET_signal_SS_ee",   "E_{T}^{miss} SS ee",     20, 0,200);
    h_MET_signal_SS_emu  = new TH1F("h_MET_signal_SS_emu",  "E_{T}^{miss} SS e#mu",   20, 0,200);
    h_MET_signal_SS_mumu = new TH1F("h_MET_signal_SS_mumu", "E_{T}^{miss} SS #mu#mu", 20, 0,200);
	fOutput->Add(h_MET_signal_OS_ee);
	fOutput->Add(h_MET_signal_OS_emu);
	fOutput->Add(h_MET_signal_OS_mumu);
	fOutput->Add(h_MET_signal_SS_ee);
	fOutput->Add(h_MET_signal_SS_emu);
	fOutput->Add(h_MET_signal_SS_mumu);

	// For meff (baseline)
    h_meff_baseline_OS_ee   = new TH1F("h_meff_baseline_OS_ee",   "Meff OS ee",   200,0, 1000);
    h_meff_baseline_OS_emu  = new TH1F("h_meff_baseline_OS_emu",  "Meff OS emu",  200,0, 1000);
    h_meff_baseline_OS_mumu = new TH1F("h_meff_baseline_OS_mumu", "Meff OS mumu", 200,0, 1000);
    h_meff_baseline_SS_ee   = new TH1F("h_meff_baseline_SS_ee",   "Meff OS ee",   200,0, 1000);
    h_meff_baseline_SS_emu  = new TH1F("h_meff_baseline_SS_emu",  "Meff OS emu",  200,0, 1000);
    h_meff_baseline_SS_mumu = new TH1F("h_meff_baseline_SS_mumu", "Meff OS mumu", 200,0, 1000);
	fOutput->Add(h_meff_baseline_OS_ee);
	fOutput->Add(h_meff_baseline_OS_emu);
	fOutput->Add(h_meff_baseline_OS_mumu);
	fOutput->Add(h_meff_baseline_SS_ee);
	fOutput->Add(h_meff_baseline_SS_emu);
	fOutput->Add(h_meff_baseline_SS_mumu);
    
	// For meff (signal)
    h_meff_signal_OS_ee   = new TH1F("h_meff_signal_OS_ee",   "Meff OS ee",   200,0, 1000);
    h_meff_signal_OS_emu  = new TH1F("h_meff_signal_OS_emu",  "Meff OS emu",  200,0, 1000);
    h_meff_signal_OS_mumu = new TH1F("h_meff_signal_OS_mumu", "Meff OS mumu", 200,0, 1000);
    h_meff_signal_SS_ee   = new TH1F("h_meff_signal_SS_ee",   "Meff OS ee",   200,0, 1000);
    h_meff_signal_SS_emu  = new TH1F("h_meff_signal_SS_emu",  "Meff OS emu",  200,0, 1000);
    h_meff_signal_SS_mumu = new TH1F("h_meff_signal_SS_mumu", "Meff OS mumu", 200,0, 1000);
	fOutput->Add(h_meff_signal_OS_ee);
	fOutput->Add(h_meff_signal_OS_emu);
	fOutput->Add(h_meff_signal_OS_mumu);
	fOutput->Add(h_meff_signal_SS_ee);
	fOutput->Add(h_meff_signal_SS_emu);
	fOutput->Add(h_meff_signal_SS_mumu);
*/    
}

void MySelector::SlaveBegin(TTree * /*tree*/)
{
    // The SlaveBegin() function is called after the Begin() function.
    // When running with PROOF SlaveBegin() is called on each slave server.
    // The tree argument is deprecated (on PROOF 0 is passed).
    
    TString option = GetOption();
    
}

Bool_t MySelector::Process(Long64_t entry)
{
    // The Process() function is called for each entry in the tree (or possibly
    // keyed object in the case of PROOF) to be processed. The entry argument
    // specifies which entry in the currently loaded tree is to be processed.
    // It can be passed to either AnaNtupSelector::GetEntry() or TBranch::GetEntry()
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

    // TH1F* h_w = (TH1F*)f->Get("DerivationStat_Weights");
    // SumW += h_w->GetBinContent(1);
    fAllEventsBeforeDerivations = 3651777;
    hCutFlows->Fill(0); // Cut 0: All events before derivations (DerivationStat_Weights)
    
    AnaNtupSelector::Process(entry);
    
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
    
    Fill_electrons(NEl,
                   11, // particle id e- = 11
                   El_eta,
                   El_phi,
                   El_pT,
                   El_E,
                   El_charge,
                   El_sigd0,
                   El_z0pvtx,
                   El_d0pvtx,
                   El_SFwMedium,
                   El_SFwMediumLH,
                   El_SFwTight,
                   El_SFwTightLH,
                   El_isLooseLH,
                   El_isMediumLH,
                   El_isTightLH,
                   El_isLoose,
                   El_isMedium,
                   El_isTight,
                   El_ptcone20,
                   El_ptcone30,
                   El_ptcone40,
                   El_ptvarcone20,
                   El_ptvarcone30,
                   El_ptvarcone40,
                   El_topoetcone20,
                   El_topoetcone30,
                   El_topoetcone40,
                   El_passIsoVeryLooseTO,
                   El_passIsoVeryLoose,
                   El_passIsoLoose,
                   El_passIsoTight,
                   El_passIsoGrad,
                   El_passIsoGradCustom,
                   El_passIsoGradLoose);
    
    Fill_muons(NMu,
               13, // particle id mu- = 13
               Mu_eta,
               Mu_phi,
               Mu_pT,
               Mu_SFw,
               Mu_charge,
               Mu_d0pvtx,
               Mu_sigd0,
               Mu_z0pvtx,
               Mu_isBad,
               Mu_isCosmic,
               Mu_ptcone20,
               Mu_ptcone30,
               Mu_ptcone40,
               Mu_ptvarcone20,
               Mu_ptvarcone30,
               Mu_ptvarcone40,
               Mu_topoetcone20,
               Mu_topoetcone30,
               Mu_topoetcone40,
               Mu_passIsoVeryLooseTO,
               Mu_passIsoVeryLoose,
               Mu_passIsoLoose,
               Mu_passIsoTight,
               Mu_passIsoGrad,
               Mu_passIsoGradCustom,
               Mu_passIsoGradLoose);
    
    Fill_jets(NJet,
              Jet_eta,
              Jet_phi,
              Jet_pT,
              Jet_E,
              Jet_quality,
              Jet_JVF,
              Jet_JVT,
              Jet_MV2c20,
              Jet_SFw,
              Jet_nTrk);

    fAllEventsInNtuple++;
    hCutFlows->Fill(1); // Cut 1: All events in derivation/ntuple
    
    // sort by descending Pt
    sort(vec_elec.begin(), vec_elec.end(), sort_descending_Pt<Electron>);
    sort(vec_muon.begin(), vec_muon.end(), sort_descending_Pt<Muon>);
    sort(vec_jets.begin(), vec_jets.end(), sort_descending_Pt<Jet>);
    
    // Set the baseline for electrons, muons, and jets.
    // Initialize passOR = 0 (Actually this step is not needed becuase passOR is initialized in the Particle() constructor.)
    // Set the isSignal electrons and muons and set the isBjet for jets.
    for (auto & el_itr : vec_elec) {
        if (el_itr.get_isLooseLH() == true &&
            el_itr.get_pt() > 10000. &&
            fabs(el_itr.get_eta()) < 2.47 &&
            fabs(el_itr.get_sigd0()) < 5.) {
            if (fabs(el_itr.get_eta()) > 1.37 && fabs(el_itr.get_eta()) < 1.52) { // Reject electrons in the crack region: 1.37<|eta|<1.52
                el_itr.set_baseline(0);
            }
            else {
                el_itr.set_baseline(1);
            }
        }
        else {
            el_itr.set_baseline(0);
        }
        el_itr.set_passOR(0);
        double theta = (el_itr.get_TLV()).Theta();
        if (el_itr.get_isTightLH() == true &&
            el_itr.get_eta() <= 2. &&
            el_itr.get_passIsoGradLoose() == true &&
            fabs(el_itr.get_z0pvtx() * TMath::Sin(theta)) < 0.5) {
            el_itr.set_isSignal(1);
        }
    }
    for (auto & mu_itr : vec_muon) {
        if (mu_itr.get_pt() > 10000. &&
            fabs(mu_itr.get_eta()) < 2.4) {
            mu_itr.set_baseline(1);
        }
        else {
            mu_itr.set_baseline(0);
        }
        mu_itr.set_passOR(0);
        double theta = (mu_itr.get_TLV()).Theta();
        if (mu_itr.get_passIsoGradLoose() == true &&
            fabs(mu_itr.get_sigd0()) < 3.0 &&
            fabs(mu_itr.get_z0pvtx() * TMath::Sin(theta)) < 0.5) {
            mu_itr.set_isSignal(1);
        }
    }
    for (auto & jet_itr : vec_jets) {
        if (jet_itr.get_pt() > 20000. &&
            fabs(jet_itr.get_eta()) < 4.5) {
            jet_itr.set_baseline(1);
        }
        else {
            jet_itr.set_baseline(0);
        }
        jet_itr.set_passOR(0);
        if (jet_itr.get_pt() > 20000. &&
            fabs(jet_itr.get_eta()) < 2.5 &&
            jet_itr.get_MV2c20() > -0.0436) {
                jet_itr.set_isBjet(1);
        }
    }
    
    // Fill leptons into vector. Put the FillLeptons() function at here
    // then the lepton in the vector has correct baseline, flavor,
    // and isSignal information. And the passOR is 0.
    Fill_leptons(vec_elec, vec_muon);
    // Now sort leptons by descending Pt
    sort(vec_lept.begin(), vec_lept.end(), sort_descending_Pt<Lepton>);
    
    //----------------------------------//
    // Apply cuts
    //----------------------------------//
/*
    if (!passGRL) return kTRUE; // passGRL = -1 for MC
    fpassGRL++;
    hCutFlows->Fill(1); // GRL
*/
	// Using the information from http://atlasdqm.web.cern.ch/atlasdqm/grlgen/All_Good/data15_13TeV.periodA_DetStatus-v62-pro18_DQDefects-00-01-02_PHYS_StandardGRL_All_Good.xml#266904
    // Run: 266904
    // From: 423 to 531
    // From: 537 to 612
	if (RunNb == 266904) {
		if (LB < 423 || (LB > 531 && LB < 537) || LB > 612) return kTRUE;
	}
/*
	if (RunNb == 266919){
		if (LB < 107 || LB > 365) return kTRUE;
	}
*/
	fGRL++;
	hCutFlows->Fill(2); // Cut 2: GRL (for data only)

    if (L1_EM15 == false && L1_MU10 == false) return kTRUE;
    fTrigger++;
    hCutFlows->Fill(3); // Cut 3: Trigger
    
    if (DetError) return kTRUE; // DetError = 0 => pass
    fGlobalFlags++;
    hCutFlows->Fill(4); // Cut 4: Global flags (data only)

    //cout << "cut4: " << EventNumber << endl;
    
    // Bad muon event veto cut: veto any event where a baseline muon BEFORE overlap removal
    int badMuon = 0;
    for (auto & mu_itr : vec_muon) {
        if (mu_itr.get_isBad()) {
            mu_itr.set_baseline(0);
            badMuon++;
        }
    }
    if (badMuon > 0) return kTRUE;
    
    //cout << "After removing bad muon: " << EventNumber << endl;

    // debug
    if (EventNumber == 26947196 ||
        EventNumber == 31713873 ||
        EventNumber == 32088982 ||
        EventNumber == 33031718 ||
        EventNumber == 33953001 ||
        EventNumber == 34412629 ||
        EventNumber == 34771199 ||
        EventNumber == 37674347 ||
        EventNumber == 42635182 ||
        EventNumber == 48268871 ||
        EventNumber == 51483861 ||
        EventNumber == 56705745 ||
        EventNumber == 65334743 ||
        EventNumber == 93115665 ||
        EventNumber == 95479365) {
        for (auto & jet_itr : vec_jets) {
            cout << EventNumber << ": (jets)"
            << ", pt=" << jet_itr.get_pt()
            << ", eta=" << jet_itr.get_eta()
            << ", phi=" << jet_itr.get_phi()
            << ", baseline=" << jet_itr.get_baseline()
            << ", passOR=" << jet_itr.get_passOR()
            << ", bad=" << jet_itr.get_quality()
            << ", MV2c20=" << jet_itr.get_MV2c20()
            << endl;
        }
        for (auto & el_itr : vec_elec) {
            cout << EventNumber << ": (electrons)"
            << ", pt=" << el_itr.get_pt()
            << ", eta=" << el_itr.get_eta()
            << ", phi=" << el_itr.get_phi()
            << ", baseline=" << el_itr.get_baseline()
            << ", passOR=" << el_itr.get_passOR()
            << endl;
        }
    }
    

    
    
    
    
    
    
    // Apply the overlap removal.
    OverlapRemoval(&vec_elec, &vec_muon, &vec_jets);
    
    int badJet = 0;
    for (auto & jet_itr : vec_jets) {
        /*
        if (jet_itr.get_passOR() == true &&
            fabs(jet_itr.get_eta()) < 4.5 &&
            jet_itr.get_quality() == true) { // quality==1 are BAD jets
            jet_itr.set_baseline(0);
            jet_itr.set_cleaning(0)
            badJet++;
        }
         */
        if ((jet_itr.get_passOR() == true) && (jet_itr.get_cleaning() == false)) {
            badJet++;
        }
    }
    if (badJet > 0) return kTRUE;
    
    for (auto & jet_itr : vec_jets) {
        if (fabs(jet_itr.get_eta()) > 2.8) {
            jet_itr.set_baseline(0);
        }
    }
    
    
    //cout << "After removing bad jet: " << EventNumber << endl;
/*
    // JVT: reject jets with pT<50 GeV and |eta|<2.4 and JVT<0.64, after the overlap removal procedure and after jet cleaning
    for (auto & jet_itr : vec_jets) {
        if (jet_itr.get_passOR() == true &&
            jet_itr.get_baseline() == true) {
            if (jet_itr.get_pt() < 50000. &&
                fabs(jet_itr.get_eta()) < 2.4 &&
                jet_itr.get_JVT() < 0.64) {
                jet_itr.set_baseline(0);
            }
        }
    }
*/
    fJetAndMuonCleaning++;
    hCutFlows->Fill(5); // Cut 5: Jet and muon cleaning

    cout << "cut5: " << EventNumber << endl;
    
    fPrimaryVertex++;
    hCutFlows->Fill(6); // Cut 6: Primary Vertex

    // Cosmics rejection cuts: these cuts should be applied AFTER overlap removal to avoid removing muons from heavy flavor decays.
    int cosmicMuon = 0;
    for (auto & mu_itr : vec_muon) {
        if (mu_itr.get_isCosmic() &&
            mu_itr.get_passOR() == true) {
            mu_itr.set_baseline(0);
            mu_itr.set_passOR(0);
            cosmicMuon++;
        }
    }
    if (cosmicMuon > 0) return kTRUE;
    fCosmicsVeto++;
    hCutFlows->Fill(7); // Cut 7: Cosmics veto

    // Fill OR electrons, OR muons, OR jets, and OR leptons into vectors.
    Fill_baseline_electrons(vec_elec);
    Fill_baseline_muons(vec_muon);
    Fill_baseline_jets(vec_jets);
    Fill_baseline_leptons(vec_elec, vec_muon);
    
    // Fill signal electrons, signal muons, signal jets, and signal leptons into vectors.
    Fill_signal_electrons(vec_elec);
    Fill_signal_muons(vec_muon);
    Fill_signal_jets(vec_jets);
    Fill_signal_leptons(vec_signal_elec, vec_signal_muon);

/*
    Int_t Nel = 0, Nmu = 0, Nel_sig = 0, Nmu_sig = 0;
    Int_t Nel_pt20 = 0, Nmu_pt20 = 0, Nel_sig_pt20 = 0, Nmu_sig_pt20 = 0;
    TLorentzVector el_tlv, mu_tlv;
    int Nbjet_pt20 = 0, Njet_pt20 = 0, Njet_pt50 = 0;
    int same_sign = 1;
    
    for (auto & el_itr : vec_OR_elec) {
        Nel++;
        if (el_itr.get_pt() > 20000.) Nel_pt20++;
        if (el_itr.get_isSignal()) {
            Nel_sig++;
            if (el_itr.get_pt() > 20000.) {
                Nel_sig_pt20++;
                el_tlv = el_tlv + el_itr.get_TLV();
                same_sign = same_sign * el_itr.get_charge();
            }
        }
    }
    for (auto & mu_itr : vec_OR_muon) {
        Nmu++;
        if (mu_itr.get_pt() > 20000.) Nmu_pt20++;
        if (mu_itr.get_isSignal()) {
            Nmu_sig++;
            if (mu_itr.get_pt() > 20000.) {
                Nmu_sig_pt20++;
                mu_tlv = mu_tlv + mu_itr.get_TLV();
                same_sign = same_sign * mu_itr.get_charge();
            }
        }
    }
    for (auto & jet_itr : vec_OR_jets) {
        if (jet_itr.get_quality() == 1) continue; // 1=bad jet from SUSYTools IsGoodJet
        if (jet_itr.get_isBjet()) Nbjet_pt20++;
        if (jet_itr.get_pt() > 20000.) Njet_pt20++;
        if (jet_itr.get_pt() > 50000.) Njet_pt50++;
    }
*/
    //----------------------------------//
/*
    if ( (Nel + Nmu) >= 2) {
        fAtLeastTwoLeptons++;
        hCutFlows->Fill(3); // ≥ 2 leptons (10 GeV)
    }
    if ( (Nel_pt20 + Nmu_pt20) == 2) {
        fEqualTwoLeptons++;
        hCutFlows->Fill(4); // == 2 leptons (20 GeV) (! l3 signal lepton 10 GeV)
        
        if (Nel_pt20 == 2 && Nmu_pt20 == 0) {
            if (same_sign == 1) {
                h_mll_baseline_SS_ee->Fill( el_tlv.M() / 1000. );
            }
            else { // Opposite sign
                h_mll_baseline_OS_ee->Fill( el_tlv.M() / 1000. );
            }
        }
        else if (Nel_pt20 == 1 && Nmu_pt20 == 1) {
            if (same_sign == 1) {
                h_mll_baseline_SS_ee->Fill( (el_tlv + mu_tlv).M() / 1000. );
            }
            else { // Opposite sign
                h_mll_baseline_OS_ee->Fill( (el_tlv + mu_tlv).M() / 1000. );
            }
        }
        else if (Nel_pt20 == 0 && Nmu_pt20 == 2) {
            if (same_sign == 1) {
                h_mll_baseline_SS_mumu->Fill( mu_tlv.M() / 1000. );
            }
            else { // Opposite sign
                h_mll_baseline_OS_mumu->Fill( mu_tlv.M() / 1000. );
            }
        }
    }
    if ( (Nel_sig_pt20 + Nmu_sig_pt20) == 2) {
        fEqualTwoSignalLeptons++;
        hCutFlows->Fill(5); // == 2 signal leptons (20 GeV)
        
        if (Nel_sig_pt20 == 2 && Nmu_sig_pt20 == 0) {
            if (same_sign == 1) {
                h_mll_signal_SS_ee->Fill( el_tlv.M() / 1000. );
            }
            else { // Opposite sign
                h_mll_signal_OS_ee->Fill( el_tlv.M() / 1000. );
            }
        }
        else if (Nel_sig_pt20 == 1 && Nmu_sig_pt20 == 1) {
            if (same_sign == 1) {
                h_mll_signal_SS_ee->Fill( (el_tlv + mu_tlv).M() / 1000. );
            }
            else { // Opposite sign
                h_mll_signal_OS_ee->Fill( (el_tlv + mu_tlv).M() / 1000. );
            }
        }
        else if (Nel_sig_pt20 == 0 && Nmu_sig_pt20 == 2) {
            if (same_sign == 1) {
                h_mll_signal_SS_mumu->Fill( mu_tlv.M() / 1000. );
            }
            else { // Opposite sign
                h_mll_signal_OS_mumu->Fill( mu_tlv.M() / 1000. );
            }
        }
    }

    if ( (Nel_sig_pt20 + Nmu_sig_pt20) == 2) {
        double ht = calculate_Ht(vec_signal_lept, vec_signal_jets);
        double meff = calculate_Meff(ht, Etmiss_CST_Et);
    }
*/
    //----------------------------------//
/*
    TLorentzVector ml1l2_tlv = el_tlv + mu_tlv;
    
    // Channel separation [20,20]: El-El channel
    if (Nel_sig_pt20 == 2 && Nmu_sig_pt20 == 0) {
        fChannelSelection_elel++;
        hCutFlows->Fill(6); // Channel selection (20, 20 GeV)
        
        fTrigger_elel++;
        hCutFlows->Fill(7); // Trigger

        if (same_sign == 1) {
            h_jet_multiplicities_pt20_SS_ee->Fill(Njet_pt20);
            h_jet_multiplicities_pt50_SS_ee->Fill(Njet_pt50);
        }
        else {
            h_jet_multiplicities_pt20_OS_ee->Fill(Njet_pt20);
            h_jet_multiplicities_pt50_OS_ee->Fill(Njet_pt50);
        }
        
        if (ml1l2_tlv.M() > 12000.) {
            fMl1l2_elel++;
            hCutFlows->Fill(8); // ml1l2 > 12 GeV
            
            if (Nbjet_pt20 >= 1) {
                fAtLeastOneBJet_elel++;
                hCutFlows->Fill(9); // ≥ 1 b jet (20 GeV)
                
                if (Njet_pt50 >= 4) {
                    fAtLeastFourJets_elel++;
                    hCutFlows->Fill(10); // ≥ 4 jets (50GeV)
                    
                    if (same_sign == 1) {
                        fSameSign_elel++;
                        hCutFlows->Fill(11); // Same sign

                        if (Etmiss_CST_Et > 150000.) {
                            fMET_elel++;
                            hCutFlows->Fill(12); // MET > 150 GeV
                        }
                    }
                }
            }
        }
    }
    
    // Channel separation [20,20]: El-MU channel
    if (Nel_sig_pt20 == 1 && Nmu_sig_pt20 == 1) {
        fChannelSelection_elmu++;
        hCutFlows->Fill(13); // Channel selection (20, 20 GeV)
        
        fTrigger_elmu++;
        hCutFlows->Fill(14); // Trigger
        
        if (same_sign == 1) {
            h_jet_multiplicities_pt20_SS_emu->Fill(Njet_pt20);
            h_jet_multiplicities_pt50_SS_emu->Fill(Njet_pt50);
        }
        else {
            h_jet_multiplicities_pt20_OS_emu->Fill(Njet_pt20);
            h_jet_multiplicities_pt50_OS_emu->Fill(Njet_pt50);
        }
        
        if (ml1l2_tlv.M() > 12000.) {
            fMl1l2_elmu++;
            hCutFlows->Fill(15); // ml1l2 > 12 GeV
            
            if (Nbjet_pt20 >= 1) {
                fAtLeastOneBJet_elmu++;
                hCutFlows->Fill(16); // ≥ 1 b jet (20 GeV)
                
                if (Njet_pt50 >= 4) {
                    fAtLeastFourJets_elmu++;
                    hCutFlows->Fill(17); // ≥ 4 jets (50GeV)
                    
                    if (same_sign == 1) {
                        fSameSign_elmu++;
                        hCutFlows->Fill(18); // Same sign

                        if (Etmiss_CST_Et > 150000.) {
                            fMET_elmu++;
                            hCutFlows->Fill(19); // MET > 150 GeV
                        }
                    }
                }
            }
        }
    }
    // Channel separation [20,20]: MU-MU channel
    if (Nel_sig_pt20 == 0 && Nmu_sig_pt20 == 2) {
        fChannelSelection_mumu++;
        hCutFlows->Fill(20); // Channel selection (20, 20 GeV)
        
        fTrigger_mumu++;
        hCutFlows->Fill(21); // Trigger
        
        if (same_sign == 1) {
            h_jet_multiplicities_pt20_SS_mumu->Fill(Njet_pt20);
            h_jet_multiplicities_pt50_SS_mumu->Fill(Njet_pt50);
        }
        else {
            h_jet_multiplicities_pt20_OS_mumu->Fill(Njet_pt20);
            h_jet_multiplicities_pt50_OS_mumu->Fill(Njet_pt50);
        }
        
        if (ml1l2_tlv.M() > 12000.) {
            fMl1l2_mumu++;
            hCutFlows->Fill(22); // ml1l2 > 12 GeV
            
            if (Nbjet_pt20 >= 1) {
                fAtLeastOneBJet_mumu++;
                hCutFlows->Fill(23); // ≥ 1 b jet (20 GeV)
                
                if (Njet_pt50 >= 4) {
                    fAtLeastFourJets_mumu++;
                    hCutFlows->Fill(24); // ≥ 4 jets (50GeV)
                    
                    if (same_sign == 1) {
                        fSameSign_mumu++;
                        hCutFlows->Fill(25); // Same sign

                        if (Etmiss_CST_Et > 150000.) {
                            fMET_mumu++;
                            hCutFlows->Fill(26); // MET > 150 GeV
                        }
                    }
                }
            }
        }
    }
*/
    return kTRUE;
}

void MySelector::SlaveTerminate()
{
    // The SlaveTerminate() function is called after all entries or objects
    // have been processed. When running with PROOF SlaveTerminate() is called
    // on each slave server.
    
}

void MySelector::Terminate()
{
    // The Terminate() function is the last function to be called during
    // a query. It always runs on the client, it can be used to present
    // the results graphically or save the results to file.
    
    TFile *output_file = new TFile("results.root", "recreate");
    fOutput->Write();
    output_file->Close();

    cout << setw(20) << left << cut_name[0]  << " = " << setw(10) << fAllEventsBeforeDerivations << endl;
    cout << setw(20) << left << cut_name[1]  << " = " << setw(10) << fAllEventsInNtuple << endl;
    cout << setw(20) << left << cut_name[2]  << " = " << setw(10) << fGRL << endl;
    cout << setw(20) << left << cut_name[3]  << " = " << setw(10) << fTrigger << endl;
    cout << setw(20) << left << cut_name[4]  << " = " << setw(10) << fGlobalFlags << endl;
    cout << setw(20) << left << cut_name[5]  << " = " << setw(10) << fJetAndMuonCleaning << endl;
    cout << setw(20) << left << cut_name[6]  << " = " << setw(10) << fPrimaryVertex << endl;
    cout << setw(20) << left << cut_name[7]  << " = " << setw(10) << fCosmicsVeto << endl;
    cout << setw(20) << left << cut_name[8]  << " = " << setw(10) << fAtLeastTwoBaselineLeptons << endl;
    cout << setw(20) << left << cut_name[9]  << " = " << setw(10) << fAtLeastTwoSignalLeptons << endl;
    // El-El channel
    cout << "**********" << endl;
    cout << setw(20) << left << cut_name[10] << " = " << setw(10) << fChannelSelection_elel << endl;
    cout << setw(20) << left << cut_name[11] << " = " << setw(10) << fTrigger_elel << endl;
    cout << setw(20) << left << cut_name[12] << " = " << setw(10) << fMl1l2_elel << endl;
    cout << setw(20) << left << cut_name[13] << " = " << setw(10) << fAtLeastOneBJet_elel << endl;
    cout << setw(20) << left << cut_name[14] << " = " << setw(10) << fAtLeastFourJets_elel << endl;
    cout << setw(20) << left << cut_name[15] << " = " << setw(10) << fSameSign_elel << endl;
    cout << setw(20) << left << cut_name[16] << " = " << setw(10) << fMET_elel << endl;
    // El-Mu channel
    cout << "**********" << endl;
    cout << setw(20) << left << cut_name[17] << " = " << setw(10) << fChannelSelection_elmu << endl;
    cout << setw(20) << left << cut_name[18] << " = " << setw(10) << fTrigger_elmu << endl;
    cout << setw(20) << left << cut_name[19] << " = " << setw(10) << fMl1l2_elmu << endl;
    cout << setw(20) << left << cut_name[20] << " = " << setw(10) << fAtLeastOneBJet_elmu << endl;
    cout << setw(20) << left << cut_name[21] << " = " << setw(10) << fAtLeastFourJets_elmu << endl;
    cout << setw(20) << left << cut_name[22] << " = " << setw(10) << fSameSign_elmu << endl;
    cout << setw(20) << left << cut_name[23] << " = " << setw(10) << fMET_elmu << endl;
    // Mu-Mu channel
    cout << "**********" << endl;
    cout << setw(20) << left << cut_name[24] << " = " << setw(10) << fChannelSelection_mumu << endl;
    cout << setw(20) << left << cut_name[25] << " = " << setw(10) << fTrigger_mumu << endl;
    cout << setw(20) << left << cut_name[26] << " = " << setw(10) << fMl1l2_mumu << endl;
    cout << setw(20) << left << cut_name[27] << " = " << setw(10) << fAtLeastOneBJet_mumu << endl;
    cout << setw(20) << left << cut_name[28] << " = " << setw(10) << fAtLeastFourJets_mumu << endl;
    cout << setw(20) << left << cut_name[29] << " = " << setw(10) << fSameSign_mumu << endl;
    cout << setw(20) << left << cut_name[30] << " = " << setw(10) << fMET_mumu << endl;
}
