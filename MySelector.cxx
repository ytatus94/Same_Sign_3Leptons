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
"All events",
"GRL",
"Global flags ",
"≥ 2 leptons (10 GeV)",
"== 2 leptons (20 GeV)",
"== 2 signal leptons (20 GeV)",
// El-El channel
"Channel selection (20, 20 GeV): el-el",
"Trigger: el-el",
"ml1l2 > 12 GeV: el-el",
"≥ 1 b jet (20 GeV): el-el",
"≥ 4 jets (50GeV): el-el",
"Same sign: el-el",
"MET > 150 GeV: el-el",
// El-Mu channel
"Channel selection (20, 20 GeV): el-mu",
"Trigger: el-mu",
"ml1l2 > 12 GeV: el-mu",
"≥ 1 b jet (20 GeV): el-mu",
"≥ 4 jets (50GeV): el-mu",
"Same sign: el-mu",
"MET > 150 GeV: el-mu",
// Mu-Mu channel
"Channel selection (20, 20 GeV): mu-mu",
"Trigger: mu-mu",
"ml1l2 > 12 GeV: mu-mu",
"≥ 1 b jet (20 GeV): mu-mu",
"≥ 4 jets (50GeV): mu-mu",
"Same sign: mu-mu",
"MET > 150 GeV: mu-mu"
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
    
    hCutFlows = new TH1F("hCutFlows", "Cut Flows", 30, 0, 30);
    int number_of_bins = sizeof(cut_name) / sizeof( cut_name[0] );
    for (int i = 1; i <= number_of_bins; i++) {
        hCutFlows->GetXaxis()->SetBinLabel(i, cut_name[i - 1]);
    }
    fOutput->Add(hCutFlows);
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

    fNumberOfEvents++;
    hCutFlows->Fill(0); // All events
    
    // sort by descending Pt
    sort(vec_elec.begin(), vec_elec.end(), sort_descending_Pt<Electron>);
    sort(vec_muon.begin(), vec_muon.end(), sort_descending_Pt<Muon>);
    sort(vec_jets.begin(), vec_jets.end(), sort_descending_Pt<Jet>);
    
    // Set the baseline for electrons, muons, and jets.
    // Initialize passOR = 0 (Actually this step is not needed becuase passOR is initialized in the Particle() constructor.)
    // Set the isSignal electrons and muons.
    // Set the isBjet for jets.
    for (auto & el_itr : vec_elec) {
        //if (el_itr.get_pt() > 10000. && fabs(el_itr.get_eta()) < 2.47) { // for v04 ntuple
        if (el_itr.get_pt() > 10000. && fabs(el_itr.get_eta()) < 2.47 && el_itr.get_isLooseLH() == true) { // for v12 ntuple
            el_itr.set_baseline(1);
        }
        else {
            el_itr.set_baseline(0);
        }
        el_itr.set_passOR(0);
        double theta = (el_itr.get_TLV()).Theta();
        if (el_itr.get_ptvarcone20() / el_itr.get_pt() < 0.06 &&
            el_itr.get_topoetcone20() / el_itr.get_pt() < 0.06 &&
            fabs(el_itr.get_z0pvtx() * TMath::Sin(theta)) < 0.4 &&
            fabs(el_itr.get_sigd0()) < 3.0 &&
            // el_itr.get_isSig() == 1) { // This is for v04 ntuple. There is no get_isSig() in v12 ntuple
            el_itr.get_isTightLH() == true) {
            el_itr.set_isSignal(1);
        }
    }
    for (auto & mu_itr : vec_muon) {
        if (mu_itr.get_pt() > 10000. && fabs(mu_itr.get_eta()) < 2.4) {
            mu_itr.set_baseline(1);
        }
        else {
            mu_itr.set_baseline(0);
        }
        mu_itr.set_passOR(0);
        double theta = (mu_itr.get_TLV()).Theta();
        if (mu_itr.get_ptvarcone30() / mu_itr.get_pt() < 0.06 &&
            fabs(mu_itr.get_z0pvtx() * TMath::Sin(theta)) < 0.4 &&
            fabs(mu_itr.get_sigd0()) < 3.0) {
            mu_itr.set_isSignal(1);
        }
    }
    for (auto & jet_itr : vec_jets) {
        if (jet_itr.get_pt() > 20000. && fabs(jet_itr.get_eta()) < 2.8) {
            jet_itr.set_baseline(1);
        }
        else {
            jet_itr.set_baseline(0);
        }
        jet_itr.set_passOR(0);
        //if (jet_itr.get_pt() > 20000. && fabs(jet_itr.get_eta()) < 2.5 && jet_itr.get_MV1() > 0.7892) { // There is no get_MV1() in v12 ntuple
        if (jet_itr.get_pt() > 20000. && fabs(jet_itr.get_eta()) < 2.5 && jet_itr.get_MV2c20() > 0.0314) {
            jet_itr.set_isBjet(1);
        }
    }
    
    // Fill leptons into vector. Put the FillLeptons() function at here
    // then the lepton in the vector has correct baseline, flavor,
    // and isSignal information. And the passOR is 0.
    Fill_leptons(vec_elec, vec_muon);
    // Now sort leptons by descending Pt
    sort(vec_lept.begin(), vec_lept.end(), sort_descending_Pt<Lepton>);
    
    // Apply the overlap removal.
    OverlapRemoval(&vec_elec, &vec_muon, &vec_jets);
    
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
    
    //----------------------------------//
    // Apply cuts
    //----------------------------------//
/*    cout << "EventNumber=" << EventNumber << " passGRL=" << passGRL << "DetError=" << DetError << endl;
    if (!passGRL) return kTRUE; // passGRL = -1 for MC
    fpassGRL++;
    hCutFlows->Fill(1); // GRL
*/
    if (DetError) return kTRUE; // DetError = 0 => pass
    fDetError++;
    hCutFlows->Fill(2); // Global flags
    
    Int_t Nel = 0, Nmu = 0, Nel_sig = 0, Nmu_sig = 0;
    Int_t Nel_pt20 = 0, Nmu_pt20 = 0, Nel_sig_pt20 = 0, Nmu_sig_pt20 = 0;
    TLorentzVector el_tlv, mu_tlv;
    int Nbjet_pt20 = 0, Njet_pt50 = 0;
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
        if (jet_itr.get_pt() > 50000.) Njet_pt50++;
    }

    //----------------------------------//
    
    if ( (Nel + Nmu) >= 2) {
        fAtLeastTwoLeptons++;
        hCutFlows->Fill(3); // ≥ 2 leptons (10 GeV)
    }
    if ( (Nel_pt20 + Nmu_pt20) == 2) {
        fEqualTwoLeptons++;
        hCutFlows->Fill(4); // == 2 leptons (20 GeV) (! l3 signal lepton 10 GeV)
    }
    if ( (Nel_sig_pt20 + Nmu_sig_pt20) == 2) {
        fEqualTwoSignalLeptons++;
        hCutFlows->Fill(5); // == 2 signal leptons (20 GeV)
    }
/*
    if ( (Nel_sig_pt20 + Nmu_sig_pt20) == 2) {
        double ht = calculate_Ht(vec_signal_lept, vec_signal_jets);
        double meff = calculate_Meff(ht, Etmiss_Et);
    }
*/
    //----------------------------------//
    
    TLorentzVector ml1l2_tlv = el_tlv + mu_tlv;
    
    // Channel separation [20,20]: El-El channel
    if (Nel_sig_pt20 == 2 && Nmu_sig_pt20 == 0) {
        fChannelSelection_elel++;
        hCutFlows->Fill(6); // Channel selection (20, 20 GeV)
        
        fTrigger_elel++;
        hCutFlows->Fill(7); // Trigger
        
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
/*
                        if (Etmiss_Et > 150000.) {
                            fMET_elel++;
                            hCutFlows->Fill(12); // MET > 150 GeV
                        }
*/
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
/*
                        if (Etmiss_Et > 150000.) {
                            fMET_elmu++;
                            hCutFlows->Fill(19); // MET > 150 GeV
                        }
*/
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
/*
                        if (Etmiss_Et > 150000.) {
                            fMET_mumu++;
                            hCutFlows->Fill(26); // MET > 150 GeV
                        }
*/
                    }
                }
            }
        }
    }

    
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
    
    cout << setw(20) << left << cut_name[0]  << " = " << setw(10) << fNumberOfEvents << endl;
    cout << setw(20) << left << cut_name[1]  << " = " << setw(10) << fpassGRL << endl;
    cout << setw(20) << left << cut_name[2]  << " = " << setw(10) << fDetError << endl;
    cout << setw(20) << left << cut_name[3]  << " = " << setw(10) << fAtLeastTwoLeptons << endl;
    cout << setw(20) << left << cut_name[4]  << " = " << setw(10) << fEqualTwoLeptons << endl;
    cout << setw(20) << left << cut_name[5]  << " = " << setw(10) << fEqualTwoSignalLeptons << endl;
    // El-El channel
    cout << "**********" << endl;
    cout << setw(20) << left << cut_name[6]  << " = " << setw(10) << fChannelSelection_elel << endl;
    cout << setw(20) << left << cut_name[7]  << " = " << setw(10) << fTrigger_elel << endl;
    cout << setw(20) << left << cut_name[8]  << " = " << setw(10) << fMl1l2_elel << endl;
    cout << setw(20) << left << cut_name[9]  << " = " << setw(10) << fAtLeastOneBJet_elel << endl;
    cout << setw(20) << left << cut_name[10] << " = " << setw(10) << fAtLeastFourJets_elel << endl;
    cout << setw(20) << left << cut_name[11] << " = " << setw(10) << fSameSign_elel << endl;
    cout << setw(20) << left << cut_name[12] << " = " << setw(10) << fMET_elel << endl;
    // El-Mu channel
    cout << "**********" << endl;
    cout << setw(20) << left << cut_name[13]  << " = " << setw(10) << fChannelSelection_elmu << endl;
    cout << setw(20) << left << cut_name[14]  << " = " << setw(10) << fTrigger_elmu << endl;
    cout << setw(20) << left << cut_name[15]  << " = " << setw(10) << fMl1l2_elmu << endl;
    cout << setw(20) << left << cut_name[16]  << " = " << setw(10) << fAtLeastOneBJet_elmu << endl;
    cout << setw(20) << left << cut_name[17] << " = " << setw(10) <<  fAtLeastFourJets_elmu << endl;
    cout << setw(20) << left << cut_name[18] << " = " << setw(10) <<  fSameSign_elmu << endl;
    cout << setw(20) << left << cut_name[19] << " = " << setw(10) <<  fMET_elmu << endl;
    // Mu-Mu channel
    cout << "**********" << endl;
    cout << setw(20) << left << cut_name[20]  << " = " << setw(10) << fChannelSelection_mumu << endl;
    cout << setw(20) << left << cut_name[21]  << " = " << setw(10) << fTrigger_mumu << endl;
    cout << setw(20) << left << cut_name[22]  << " = " << setw(10) << fMl1l2_mumu << endl;
    cout << setw(20) << left << cut_name[23]  << " = " << setw(10) << fAtLeastOneBJet_mumu << endl;
    cout << setw(20) << left << cut_name[24] << " = " << setw(10) <<  fAtLeastFourJets_mumu << endl;
    cout << setw(20) << left << cut_name[25] << " = " << setw(10) <<  fSameSign_mumu << endl;
    cout << setw(20) << left << cut_name[26] << " = " << setw(10) <<  fMET_mumu << endl;
}
