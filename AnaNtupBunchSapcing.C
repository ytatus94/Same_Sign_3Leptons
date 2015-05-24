#define AnaNtupBunchSapcing_cxx
// The class definition in AnaNtupBunchSapcing.h has been generated automatically
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
// Root > T->Process("AnaNtupBunchSapcing.C")
// Root > T->Process("AnaNtupBunchSapcing.C","some options")
// Root > T->Process("AnaNtupBunchSapcing.C+")
//

#include "AnaNtupBunchSapcing.h"
#include <TH2.h>
#include <TStyle.h>

//==================
// Dictionary (for saving vector into branches)
//#ifdef __CINT__
//#pragma link C++ class vector<TLorentzVector>+;
//#pragma link C++ class vector<OR_Object>+;
//#endif
//==================

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

/*
void AnaNtupBunchSapcing::SetElecTLV(int iEl, vector<double> *el_pt, 
                                              vector<double> *el_eta,
                                              vector<double> *el_phi,
                                              vector<double> *el_E)
{
    for (int i = 0; i < iEl; i++) {
        TLorentzVector tlv;
        tlv.SetPtEtaPhiE( (*el_pt)[i], (*el_eta)[i], (*el_phi)[i], (*el_E)[i] );
        m_el.push_back(tlv);
        
        m_lep.push_back(tlv);
    }
}

void AnaNtupBunchSapcing::SetMuonTLV(int iMu, vector<double> *mu_pt, 
                                              vector<double> *mu_eta,
                                              vector<double> *mu_phi,
                                              double mu_M)
{
    for (int i = 0; i < iMu; i++) {
        TLorentzVector tlv;
        tlv.SetPtEtaPhiM( (*mu_pt)[i], (*mu_eta)[i], (*mu_phi)[i], mu_M );
        m_mu.push_back(tlv);
        
        m_lep.push_back(tlv);
    }
}

void AnaNtupBunchSapcing::SetJetTLV(int iJet, vector<double> *jet_pt, 
                                              vector<double> *jet_eta,
                                              vector<double> *jet_phi,
                                              vector<double> *jet_E)
{
    for (int i = 0; i < iJet; i++) {
        TLorentzVector tlv;
        tlv.SetPtEtaPhiE( (*jet_pt)[i], (*jet_eta)[i], (*jet_phi)[i], (*jet_E)[i] );
        m_jet.push_back(tlv);
    }
}
*/
void AnaNtupBunchSapcing::FillElec(Int_t iEl,
                                   int   flavor,
                                   vector<double>  *el_eta,
                                   vector<double>  *el_phi,
                                   vector<double>  *el_pT,
                                   vector<double>  *el_E,
                                   vector<int>     *el_charge,
                                   vector<double>  *el_sigd0,
                                   vector<double>  *el_z0pvtx,
                                   vector<double>  *el_d0pvtx,
                                   vector<double>  *el_d0pvtxerr,
                                   vector<double>  *el_SFw,
                                   vector<double>  *el_SFwMed,
                                   vector<int>     *el_isSig,
                                   vector<int>     *el_isSigMed,
                                   vector<int>     *el_type,
                                   vector<int>     *el_origin,
                                   vector<double>  *el_ptcone20,
                                   vector<double>  *el_ptcone30,
                                   vector<double>  *el_ptcone40,
                                   vector<double>  *el_ptvarcone20,
                                   vector<double>  *el_ptvarcone30,
                                   vector<double>  *el_ptvarcone40,
                                   vector<double>  *el_topoetcone20,
                                   vector<double>  *el_topoetcone30,
                                   vector<double>  *el_topoetcone40)
{
    for (int i = 0; i < iEl; i++) {
        Electron el;
        el.set_flavor(flavor);
        el.set_eta( (*el_eta)[i] );
        el.set_phi( (*el_phi)[i] );
        el.set_pt( (*el_pT)[i] );
        el.set_E( (*el_E)[i] );
        el.set_charge( (*el_charge)[i] );
        el.set_sigd0( (*el_sigd0)[i] );
        el.set_z0pvtx( (*el_z0pvtx)[i] );
        el.set_d0pvtx( (*el_d0pvtx)[i] );
        el.set_d0pvtxerr( (*el_d0pvtxerr)[i] );
        el.set_SFw( (*el_SFw)[i] );
        el.set_SFwMed( (*el_SFwMed)[i] );
        el.set_isSig( (*el_isSig)[i] );
        el.set_isSigMed( (*el_isSigMed)[i] );
        el.set_type( (*el_type)[i] );
        el.set_origin( (*el_origin)[i] );
        el.set_ptcone20( (*el_ptcone20)[i] );
        el.set_ptcone30( (*el_ptcone30)[i] );
        el.set_ptcone40( (*el_ptcone40)[i] );
        el.set_ptvarcone20( (*el_ptvarcone20)[i] );
        el.set_ptvarcone30( (*el_ptvarcone30)[i] );
        el.set_ptvarcone40( (*el_ptvarcone40)[i] );
        el.set_topoetcone20( (*el_topoetcone20)[i] );
        el.set_topoetcone30( (*el_topoetcone30)[i] );
        el.set_topoetcone40( (*el_topoetcone40)[i] );
        el.set_TLV_E(el.get_pt(), el.get_eta(), el.get_phi(), el.get_E());
        vec_elec.push_back(el);
    }
}

void AnaNtupBunchSapcing::FillMuon(Int_t iMu,
                                   int   flavor,
                                   vector<double>  *mu_eta,
                                   vector<double>  *mu_phi,
                                   vector<double>  *mu_pT,
                                   vector<double>  *mu_SFw,
                                   vector<int>     *mu_charge,
                                   vector<double>  *mu_d0pvtx,
                                   vector<double>  *mu_d0pvtxerr,
                                   vector<double>  *mu_sigd0,
                                   vector<double>  *mu_z0pvtx,
                                   vector<int>     *mu_isBad,
                                   vector<int>     *mu_isSig,
                                   vector<int>     *mu_isCosmic,
                                   vector<int>     *mu_type,
                                   vector<int>     *mu_origin,
                                   vector<double>  *mu_ptcone20,
                                   vector<double>  *mu_ptcone30,
                                   vector<double>  *mu_ptcone40,
                                   vector<double>  *mu_ptvarcone20,
                                   vector<double>  *mu_ptvarcone30,
                                   vector<double>  *mu_ptvarcone40,
                                   vector<double>  *mu_topoetcone20,
                                   vector<double>  *mu_topoetcone30,
                                   vector<double>  *mu_topoetcone40)
{
    for (int i = 0; i < iMu; i++) {
        Muon mu;
        mu.set_flavor(flavor);
        mu.set_eta(  (*mu_eta)[i] );
        mu.set_phi( (*mu_phi)[i] );
        mu.set_pt( (*mu_pT)[i] );
        mu.set_SFw( (*mu_SFw)[i] );
        mu.set_charge( (*mu_charge)[i] );
        mu.set_d0pvtx( (*mu_d0pvtx)[i] );
        mu.set_d0pvtxerr( (*mu_d0pvtxerr)[i] );
        mu.set_sigd0( (*mu_sigd0)[i] );
        mu.set_z0pvtx( (*mu_z0pvtx)[i] );
        mu.set_isBad( (*mu_isBad)[i] );
        mu.set_isSig( (*mu_isSig)[i] );
        mu.set_isCosmic( (*mu_isCosmic)[i] );
        mu.set_type( (*mu_type)[i] );
        mu.set_origin( (*mu_origin)[i] );
        mu.set_ptcone20( (*mu_ptcone20)[i] );
        mu.set_ptcone30( (*mu_ptcone30)[i] );
        mu.set_ptcone40( (*mu_ptcone40)[i] );
        mu.set_ptvarcone20( (*mu_ptvarcone20)[i] );
        mu.set_ptvarcone30( (*mu_ptvarcone30)[i] );
        mu.set_ptvarcone40( (*mu_ptvarcone40)[i] );
        mu.set_topoetcone20( (*mu_topoetcone20)[i] );
        mu.set_topoetcone30( (*mu_topoetcone30)[i] );
        mu.set_topoetcone40( (*mu_topoetcone40)[i] );
        mu.set_TLV_M(mu.get_pt(), mu.get_eta(), mu.get_phi(), Mu_M);
        vec_muon.push_back(mu);
    }
}

void AnaNtupBunchSapcing::FillJets(Int_t iJet,
                                   vector<double>  *jet_eta,
                                   vector<double>  *jet_phi,
                                   vector<double>  *jet_pT,
                                   vector<double>  *jet_E,
                                   vector<double>  *jet_quality,
                                   vector<double>  *jet_JVF,
                                   vector<double>  *jet_MV1,
                                   vector<double>  *jet_SFw,
                                   vector<int>     *jet_JetLabel,
                                   vector<int>     *jet_nTrk,
                                   vector<double>  *jet_deltaR)
{
    for (int i = 0; i < iJet; i++) {
        Jet je;
        je.set_eta( (*jet_eta)[i] );
        je.set_phi( (*jet_phi)[i] );
        je.set_pt( (*jet_pT)[i] );
        je.set_E( (*jet_E)[i] );
        je.set_quality( (*jet_quality)[i] );
        je.set_JVF( (*jet_JVF)[i] );
        je.set_MV1( (*jet_MV1)[i] );
        je.set_SFw( (*jet_SFw)[i] );
        je.set_JetLabel( (*jet_JetLabel)[i] );
        je.set_nTrk( (*jet_nTrk)[i] );
        je.set_deltaR( (*jet_deltaR)[i] );
        je.set_TLV_E(je.get_pt(), je.get_eta(), je.get_phi(), je.get_E());
        vec_jets.push_back(je);
    }
}

void AnaNtupBunchSapcing::FillTruthV(Int_t iTruthV,
                                     vector<double>  *TruthV_eta,
                                     vector<double>  *TruthV_phi,
                                     vector<double>  *TruthV_pT,
                                     vector<double>  *TruthV_m)
{
    for (int i = 0; i < iTruthV; i++) {
        Particle tr;
        tr.set_eta( (*TruthV_eta)[i] );
        tr.set_phi( (*TruthV_phi)[i] );
        tr.set_pt( (*TruthV_pT)[i] );
        tr.set_M( (*TruthV_m)[i] );
        tr.set_TLV_M(tr.get_pt(), tr.get_eta(), tr.get_phi(), tr.get_M());
        vec_truthv.push_back(tr);
    }
}

/*
void AnaNtupBunchSapcing::OverlapRemoval(vector<OR_Object> *el_obj,
                                         vector<OR_Object> *mu_obj,
                                         vector<OR_Object> *jet_obj,
                                         double dRejet,
                                         double dRjetmu,
                                         double dRjete,
                                         double dRemu,
                                         double dRee)
{
    vector<OR_Object>::iterator jet_itr = jet_obj->begin();
    vector<OR_Object>::iterator jet_end = jet_obj->end();
    for (; jet_itr != jet_end; jet_itr++) {
        bool jet_sel = jet_itr->baseline;
        if (jet_sel)
            jet_itr->passOR = 1;
        else
            jet_itr->passOR = 0;
    }

    vector<OR_Object>::iterator mu_itr = mu_obj->begin();
    vector<OR_Object>::iterator mu_end = mu_obj->end();
    for (; mu_itr != mu_end; mu_itr++) {
        bool mu_sel = mu_itr->baseline;
        if (mu_sel)
            mu_itr->passOR = 1;
        else
            mu_itr->passOR = 0;
    }

    // remove jets overlapping with (baseline/signal) electrons
    vector<OR_Object>::iterator el_itr = el_obj->begin();
    vector<OR_Object>::iterator el_end = el_obj->end();
    for (; el_itr != el_end; el_itr++) {
        bool el_sel = el_itr->baseline;
        if (el_sel)
            el_itr->passOR = 1;
        else
            el_itr->passOR = 0;

        vector<OR_Object>::iterator jet_itr = jet_obj->begin();
        vector<OR_Object>::iterator jet_end = jet_obj->end();
        for (; jet_itr != jet_end; jet_itr++) {
            if (!jet_itr->passOR) continue;
            TLorentzVector el4vec = el_itr->tlv;
            TLorentzVector jet4vec = jet_itr->tlv;
            if (el4vec.DeltaR(jet4vec) < dRejet) {
                jet_itr->passOR = 0;
            }
        }
    }

    // Remove electrons and muons overlapping with jets
    el_itr = el_obj->begin();
    el_end = el_obj->end();
    for (; el_itr != el_end; el_itr++) {
        if (!el_itr->passOR) continue;

        vector<OR_Object>::iterator jet_itr = jet_obj->begin();
        vector<OR_Object>::iterator jet_end = jet_obj->end();
        for (; jet_itr != jet_end; jet_itr++) {
            if (!jet_itr->passOR) continue;
            TLorentzVector el4vec = el_itr->tlv;
            TLorentzVector jet4vec = jet_itr->tlv;
            if (el4vec.DeltaR(jet4vec) < dRjete) {
                el_itr->passOR = 0;
            }
        }
    }

    mu_itr = mu_obj->begin();
    mu_end = mu_obj->end();
    for (; mu_itr != mu_end; mu_itr++) {
        if (!mu_itr->passOR) continue;

        vector<OR_Object>::iterator jet_itr = jet_obj->begin();
        vector<OR_Object>::iterator jet_end = jet_obj->end();
        for (; jet_itr != jet_end; jet_itr++) {
            if (!jet_itr->passOR) continue;
            TLorentzVector mu4vec = mu_itr->tlv;
            TLorentzVector jet4vec = jet_itr->tlv;
            if (mu4vec.DeltaR(jet4vec) < dRjetmu) {
                mu_itr->passOR = 0;
            }
        }
    }

    // Remove electrons and muons overlapping with each other
    el_itr = el_obj->begin();
    el_end = el_obj->end();
    for (; el_itr != el_end; el_itr++) {
        if (!el_itr->passOR) continue;

        mu_itr = mu_obj->begin();
        mu_end = mu_obj->end();
        for (; mu_itr != mu_end; mu_itr++) {
            if (!mu_itr->passOR) continue;

            TLorentzVector el4vec = el_itr->tlv;
            TLorentzVector mu4vec = mu_itr->tlv;
            if (el4vec.DeltaR(mu4vec) < dRemu) {
                el_itr->passOR = 0;
                //mu_itr->passOR = 0; // Otilia says we remove electron only.
            }
        }
    }

    // Remove electrons overlapping with each other
    el_itr = el_obj->begin();
    el_end = el_obj->end();
    for (; el_itr != el_end; el_itr++) {
        if (!el_itr->passOR) continue;

        vector<OR_Object>::iterator el2_itr = el_obj->begin();
        vector<OR_Object>::iterator el2_end = el_obj->end();
        if (el_itr == el2_itr) continue;
        if (!el2_itr->passOR) continue;
        TLorentzVector el4vec = el_itr->tlv;
        TLorentzVector el24vec = el2_itr->tlv;
        if (el4vec.DeltaR(el24vec) < dRee) {
            if ((el_itr->tlv).Pt() < (el2_itr->tlv).Pt()) {
                el_itr->passOR = 0;
            }
            else {
                el2_itr->passOR = 0;
            }
        }
    }
//
    // debug
    // Count number of objects after overlap removal
    int Nel = 0;
    el_itr = el_obj->begin();
    el_end = el_obj->end();
    for (; el_itr != el_end; el_itr++) {
        if (el_itr->passOR) Nel++;
    } 

    int Nmu = 0;
    mu_itr = mu_obj->begin();
    mu_end = mu_obj->end();
    for (; mu_itr != mu_end; mu_itr++) {
        if (mu_itr->passOR) Nmu++;
    }

    int Njet = 0;
    jet_itr = jet_obj->begin();
    jet_end = jet_obj->end();
    for (; jet_itr != jet_end; jet_itr++) {
        if (jet_itr->passOR) Njet++;
    }

    cout << "After overlap removal: Nel=" << Nel <<", Nmu="<< Nmu <<", Njet=" << Njet << endl;
//
}
*/

void AnaNtupBunchSapcing::OverlapRemoval(vector<Electron> *el_obj,
                                         vector<Muon>     *mu_obj,
                                         vector<Jet>      *jet_obj,
                                         double dRejet,
                                         double dRjetmu,
                                         double dRjete,
                                         double dRemu,
                                         double dRee)
{
    vector<Jet>::iterator jet_itr = jet_obj->begin();
    vector<Jet>::iterator jet_end = jet_obj->end();
    for (; jet_itr != jet_end; jet_itr++) {
        bool jet_sel = jet_itr->get_baseline();
        if (jet_sel)
            jet_itr->set_passOR(1);
        else
            jet_itr->set_passOR(0);
    }
    
    vector<Muon>::iterator mu_itr = mu_obj->begin();
    vector<Muon>::iterator mu_end = mu_obj->end();
    for (; mu_itr != mu_end; mu_itr++) {
        bool mu_sel = mu_itr->get_baseline();
        if (mu_sel)
            mu_itr->set_passOR(1);
        else
            mu_itr->set_passOR(0);
    }
    
    // remove jets overlapping with (baseline/signal) electrons
    vector<Electron>::iterator el_itr = el_obj->begin();
    vector<Electron>::iterator el_end = el_obj->end();
    for (; el_itr != el_end; el_itr++) {
        bool el_sel = el_itr->get_baseline();
        if (el_sel)
            el_itr->set_passOR(1);
        else
            el_itr->set_passOR(0);
        
        jet_itr = jet_obj->begin();
        jet_end = jet_obj->end();
        for (; jet_itr != jet_end; jet_itr++) {
            if (!jet_itr->get_passOR()) continue;
            TLorentzVector el4vec = el_itr->get_TLV();
            TLorentzVector jet4vec = jet_itr->get_TLV();
            if (el4vec.DeltaR(jet4vec) < dRejet) {
                jet_itr->set_passOR(0);
            }
        }
    }
    
    // Remove electrons and muons overlapping with jets
    el_itr = el_obj->begin();
    el_end = el_obj->end();
    for (; el_itr != el_end; el_itr++) {
        if (!el_itr->get_passOR()) continue;
        
        jet_itr = jet_obj->begin();
        jet_end = jet_obj->end();
        for (; jet_itr != jet_end; jet_itr++) {
            if (!jet_itr->get_passOR()) continue;
            TLorentzVector el4vec = el_itr->get_TLV();
            TLorentzVector jet4vec = jet_itr->get_TLV();
            if (el4vec.DeltaR(jet4vec) < dRjete) {
                el_itr->set_passOR(0);
            }
        }
    }
    
    mu_itr = mu_obj->begin();
    mu_end = mu_obj->end();
    for (; mu_itr != mu_end; mu_itr++) {
        if (!mu_itr->get_passOR()) continue;
        
        jet_itr = jet_obj->begin();
        jet_end = jet_obj->end();
        for (; jet_itr != jet_end; jet_itr++) {
            if (!jet_itr->get_passOR()) continue;
            TLorentzVector mu4vec = mu_itr->get_TLV();
            TLorentzVector jet4vec = jet_itr->get_TLV();
            if (mu4vec.DeltaR(jet4vec) < dRjetmu) {
                mu_itr->set_passOR(0);
            }
        }
    }
    
    // Remove electrons and muons overlapping with each other
    el_itr = el_obj->begin();
    el_end = el_obj->end();
    for (; el_itr != el_end; el_itr++) {
        if (!el_itr->get_passOR()) continue;
        
        mu_itr = mu_obj->begin();
        mu_end = mu_obj->end();
        for (; mu_itr != mu_end; mu_itr++) {
            if (!mu_itr->get_passOR()) continue;
            
            TLorentzVector el4vec = el_itr->get_TLV();
            TLorentzVector mu4vec = mu_itr->get_TLV();
            if (el4vec.DeltaR(mu4vec) < dRemu) {
                el_itr->set_passOR(0);
                //mu_itr->set_passOR(0); // Otilia says we remove electron only.
            }
        }
    }
    
    // Remove electrons overlapping with each other
    el_itr = el_obj->begin();
    el_end = el_obj->end();
    for (; el_itr != el_end; el_itr++) {
        if (!el_itr->get_passOR()) continue;
        
        vector<Electron>::iterator el2_itr = el_obj->begin();
        vector<Electron>::iterator el2_end = el_obj->end();
        if (el_itr == el2_itr) continue;
        if (!el2_itr->get_passOR()) continue;
        TLorentzVector el4vec = el_itr->get_TLV();
        TLorentzVector el24vec = el2_itr->get_TLV();
        if (el4vec.DeltaR(el24vec) < dRee) {
            if ((el_itr->get_TLV()).Pt() < (el2_itr->get_TLV()).Pt()) {
                el_itr->set_passOR(0);
            }
            else {
                el2_itr->set_passOR(0);
            }
        }
    }
/*
     // debug
     // Count number of objects after overlap removal
     int Nel = 0;
     el_itr = el_obj->begin();
     el_end = el_obj->end();
     for (; el_itr != el_end; el_itr++) {
     if (el_itr->get_passOR()) Nel++;
     }
     
     int Nmu = 0;
     mu_itr = mu_obj->begin();
     mu_end = mu_obj->end();
     for (; mu_itr != mu_end; mu_itr++) {
     if (mu_itr->get_passOR()) Nmu++;
     }
     
     int Njet = 0;
     jet_itr = jet_obj->begin();
     jet_end = jet_obj->end();
     for (; jet_itr != jet_end; jet_itr++) {
     if (jet_itr->get_passOR()) Njet++;
     }
     
     cout << "After overlap removal: Nel=" << Nel <<", Nmu="<< Nmu <<", Njet=" << Njet << endl;
*/
}



void AnaNtupBunchSapcing::Begin(TTree * /*tree*/)
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

    hCut1_Njet = new TH1F("hCut1_Njet", "Number of Jets", 100, 0, 100);
    hCut1_Njet_OR = new TH1F("hCut1_Njet_OR", "Number of Jets (OR)", 100, 0, 100);
    hCut1_Jet_Pt = new TH1F("hCut1_Jet_Pt", "Jet pT", 100, 0, 1000000);
    hCut1_Jet_Eta = new TH1F("hCut1_Jet_Eta", "Jet eta", 100, -5, 5);
    hCut1_Jet_Phi = new TH1F("hCut1_Jet_Phi", "Jet phi", 100, -5, 5);
    hCut1_Jet_Pt1 = new TH1F("hCut1_Jet_Pt1", "Jet 1 pT", 100, 0, 1000000);
    hCut1_Jet_Pt2 = new TH1F("hCut1_Jet_Pt2", "Jet 2 pT", 100, 0, 1000000);
    hCut1_Jet_Pt3 = new TH1F("hCut1_Jet_Pt3", "Jet 3 pT", 100, 0, 1000000);
    hCut1_Jet_Pt4 = new TH1F("hCut1_Jet_Pt4", "Jet 4 pT", 100, 0, 1000000);
    fOutput->Add(hCut1_Njet);
    fOutput->Add(hCut1_Njet_OR);
    fOutput->Add(hCut1_Jet_Pt);
    fOutput->Add(hCut1_Jet_Eta);
    fOutput->Add(hCut1_Jet_Phi);
    fOutput->Add(hCut1_Jet_Pt1);
    fOutput->Add(hCut1_Jet_Pt2);
    fOutput->Add(hCut1_Jet_Pt3);
    fOutput->Add(hCut1_Jet_Pt4);
    
    hCut1_Nelec = new TH1F("hCut1_Nelec", "Number of electrons", 10, 0, 10);
    hCut1_Nelec_OR = new TH1F("hCut1_Nelec_OR", "Number of electrons (OR)", 10, 0, 10);
    hCut1_Elec_Pt = new TH1F("hCut1_Elec_Pt", "Elec pT", 100, 0, 1000000);
    hCut1_Elec_Eta = new TH1F("hCut1_Elec_Eta", "Elec eta", 100, -5, 5);
    hCut1_Elec_Phi = new TH1F("hCut1_Elec_Phi", "Elec phi", 100, -5, 5);
    hCut1_Elec_Pt1 = new TH1F("hCut1_Elec_Pt1", "Elec 1 pT", 100, 0, 1000000);
    hCut1_Elec_Pt2 = new TH1F("hCut1_Elec_Pt2", "Elec 2 pT", 100, 0, 1000000);
    fOutput->Add(hCut1_Nelec);
    fOutput->Add(hCut1_Nelec_OR);
    fOutput->Add(hCut1_Elec_Pt);
    fOutput->Add(hCut1_Elec_Eta);
    fOutput->Add(hCut1_Elec_Phi);
    fOutput->Add(hCut1_Elec_Pt1);
    fOutput->Add(hCut1_Elec_Pt2);

    hCut1_Nmuon = new TH1F("hCut1_Nmuon", "Number of muons", 10, 0, 10);
    hCut1_Nmuon_OR = new TH1F("hCut1_Nmuon_OR", "Number of muons (OR)", 10, 0, 10);
    hCut1_Muon_Pt = new TH1F("hCut1_Muon_Pt", "Muon pT", 100, 0, 1000000);
    hCut1_Muon_Eta = new TH1F("hCut1_Muon_Eta", "Muon eta", 100, -5, 5);
    hCut1_Muon_Phi = new TH1F("hCut1_Muon_Phi", "Muon phi", 100, -5, 5);
    hCut1_Muon_Pt1 = new TH1F("hCut1_Muon_Pt1", "Muon 1 pT", 100, 0, 1000000);
    hCut1_Muon_Pt2 = new TH1F("hCut1_Muon_Pt2", "Muon 2 pT", 100, 0, 1000000);
    fOutput->Add(hCut1_Nmuon);
    fOutput->Add(hCut1_Nmuon_OR);
    fOutput->Add(hCut1_Muon_Pt);
    fOutput->Add(hCut1_Muon_Eta);
    fOutput->Add(hCut1_Muon_Phi);
    fOutput->Add(hCut1_Muon_Pt1);
    fOutput->Add(hCut1_Muon_Pt2);
    
    hCut1_Nlep = new TH1F("hCut1_Nlep", "Number of leptons", 10, 0, 10);
    hCut1_Nlep_OR = new TH1F("hCut1_Nlep_OR", "Number of leptons (OR)", 10, 0, 10);
    hCut1_lep_Pt = new TH1F("hCut1_lep_Pt", "Lepton pT", 100, 0, 1000000);
    hCut1_lep_Pt1 = new TH1F("hCut1_lep_Pt1", "Lepton 1 pT", 100, 0, 1000000);
    hCut1_lep_Pt2 = new TH1F("hCut1_lep_Pt2", "Lepton 2 pT", 100, 0, 1000000);
    fOutput->Add(hCut1_Nlep);
    fOutput->Add(hCut1_Nlep_OR);
    fOutput->Add(hCut1_lep_Pt);
    fOutput->Add(hCut1_lep_Pt1);
    fOutput->Add(hCut1_lep_Pt2);
    
    hCut1_MET = new TH1F("hCut1_MET", "MET", 100, 0, 1000000);
    fOutput->Add(hCut1_MET);
    
    hCut1_Meff = new TH1F("hCut1_Meff", "Meff", 100, 0, 1000000);
    fOutput->Add(hCut1_Meff);
    
    hCut1_Nbjet = new TH1F("hCut1_Nbjet", "Number of b-jets", 10, 0, 10);
    hCut1_Nbjet_OR = new TH1F("hCut1_Nbjet_OR", "Number of b-jets (OR)", 10, 0, 10);
    fOutput->Add(hCut1_Nbjet);
    fOutput->Add(hCut1_Nbjet_OR);
    
    hCut5_Njet = new TH1F("hCut5_Njet", "Number of Jets", 20, 0, 20);
    hCut5_Jet_Pt = new TH1F("hCut5_Jet_Pt", "Jet pT", 100, 0, 1000000);
    hCut5_Jet_Eta = new TH1F("hCut5_Jet_Eta", "Jet eta", 100, -5, 5);
    hCut5_Jet_Phi = new TH1F("hCut5_Jet_Phi", "Jet phi", 100, -5, 5);
    hCut5_Jet_Pt1 = new TH1F("hCut5_Jet_Pt1", "Jet 1 pT", 100, 0, 1000000);
    hCut5_Jet_Pt2 = new TH1F("hCut5_Jet_Pt2", "Jet 2 pT", 100, 0, 1000000);
    hCut5_Jet_Pt3 = new TH1F("hCut5_Jet_Pt3", "Jet 3 pT", 100, 0, 1000000);
    hCut5_Jet_Pt4 = new TH1F("hCut5_Jet_Pt4", "Jet 4 pT", 100, 0, 1000000);
    fOutput->Add(hCut5_Njet);
    fOutput->Add(hCut5_Jet_Pt);
    fOutput->Add(hCut5_Jet_Eta);
    fOutput->Add(hCut5_Jet_Phi);
    fOutput->Add(hCut5_Jet_Pt1);
    fOutput->Add(hCut5_Jet_Pt2);
    fOutput->Add(hCut5_Jet_Pt3);
    fOutput->Add(hCut5_Jet_Pt4);
    
    hCut5_Nelec = new TH1F("hCut5_Nelec", "Number of electrons", 10, 0, 10);
    hCut5_Elec_Pt = new TH1F("hCut5_Elec_Pt", "Elec pT", 100, 0, 1000000);
    hCut5_Elec_Eta = new TH1F("hCut5_Elec_Eta", "Elec eta", 100, -5, 5);
    hCut5_Elec_Phi = new TH1F("hCut5_Elec_Phi", "Elec phi", 100, -5, 5);
    hCut5_Elec_Pt1 = new TH1F("hCut5_Elec_Pt1", "Elec 1 pT", 100, 0, 1000000);
    hCut5_Elec_Pt2 = new TH1F("hCut5_Elec_Pt2", "Elec 2 pT", 100, 0, 1000000);
    fOutput->Add(hCut5_Nelec);
    fOutput->Add(hCut5_Elec_Pt);
    fOutput->Add(hCut5_Elec_Eta);
    fOutput->Add(hCut5_Elec_Phi);
    fOutput->Add(hCut5_Elec_Pt1);
    fOutput->Add(hCut5_Elec_Pt2);
    
    hCut5_Nmuon = new TH1F("hCut5_Nmuon", "Number of muons", 10, 0, 10);
    hCut5_Muon_Pt = new TH1F("hCut5_Muon_Pt", "Muon pT", 100, 0, 1000000);
    hCut5_Muon_Eta = new TH1F("hCut5_Muon_Eta", "Muon eta", 100, -5, 5);
    hCut5_Muon_Phi = new TH1F("hCut5_Muon_Phi", "Muon phi", 100, -5, 5);
    hCut5_Muon_Pt1 = new TH1F("hCut5_Muon_Pt1", "Muon 1 pT", 100, 0, 1000000);
    hCut5_Muon_Pt2 = new TH1F("hCut5_Muon_Pt2", "Muon 2 pT", 100, 0, 1000000);
    fOutput->Add(hCut5_Nmuon);
    fOutput->Add(hCut5_Muon_Pt);
    fOutput->Add(hCut5_Muon_Eta);
    fOutput->Add(hCut5_Muon_Phi);
    fOutput->Add(hCut5_Muon_Pt1);
    fOutput->Add(hCut5_Muon_Pt2);
    
    hCut5_Nlep = new TH1F("hCut5_Nlep", "Number of leptons", 10, 0, 10);
    hCut5_lep_Pt = new TH1F("hCut5_lep_Pt", "Lepton pT", 100, 0, 1000000);
    hCut5_lep_Pt1 = new TH1F("hCut5_lep_Pt1", "Lepton 1 pT", 100, 0, 1000000);
    hCut5_lep_Pt2 = new TH1F("hCut5_lep_Pt2", "Lepton 2 pT", 100, 0, 1000000);
    fOutput->Add(hCut5_Nlep);
    fOutput->Add(hCut5_lep_Pt);
    fOutput->Add(hCut5_lep_Pt1);
    fOutput->Add(hCut5_lep_Pt2);
    
    hCut5_MET = new TH1F("hCut5_MET", "MET", 100, 0, 1000000);
    fOutput->Add(hCut5_MET);
    
    hCut5_Meff = new TH1F("hCut5_Meff", "Meff", 100, 0, 1000000);
    fOutput->Add(hCut5_Meff);
    
    hCut5_Nbjet = new TH1F("hCut5_Nbjet", "Number of b-jets", 10, 0, 10);
    fOutput->Add(hCut5_Nbjet);
    
/*
    myTree = new TTree("myTree", "Tree");

    myTree->Branch("m_el", &m_el);
    myTree->Branch("m_mu", &m_mu);
    myTree->Branch("m_jet", &m_jet);

    myTree->Branch("m_el_passOR", &m_el_passOR);
    myTree->Branch("m_mu_passOR", &m_mu_passOR);
    myTree->Branch("m_jet_passOR", &m_jet_passOR);

    fOutput->Add(myTree);
*/
}

void AnaNtupBunchSapcing::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

Bool_t AnaNtupBunchSapcing::Process(Long64_t entry)
{
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // It can be passed to either AnaNtupBunchSapcing::GetEntry() or TBranch::GetEntry()
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

/*
    m_el.clear();
    m_mu.clear();
    m_jet.clear();
    m_lep.clear();

    m_el_passOR.clear();
    m_mu_passOR.clear();
    m_jet_passOR.clear();
    m_lep_passOR.clear();

    vec_el.clear();
    vec_mu.clear();
    vec_jet.clear();
*/
    vec_lept.clear();
    vec_elec.clear();
    vec_muon.clear();
    vec_jets.clear();
    vec_truthv.clear();
    
    fChain->GetTree()->GetEntry(entry);

    FillElec(NEl,
             11, // particle id e- = 11
             El_eta,
             El_phi,
             El_pT,
             El_E,
             El_charge,
             El_sigd0,
             El_z0pvtx,
             El_d0pvtx,
             El_d0pvtxerr,
             El_SFw,
             El_SFwMed,
             El_isSig,
             El_isSigMed,
             El_type,
             El_origin,
             El_ptcone20,
             El_ptcone30,
             El_ptcone40,
             El_ptvarcone20,
             El_ptvarcone30,
             El_ptvarcone40,
             El_topoetcone20,
             El_topoetcone30,
             El_topoetcone40);
    
    FillMuon(NMu,
             13, // particle id mu- = 13
             Mu_eta,
             Mu_phi,
             Mu_pT,
             Mu_SFw,
             Mu_charge,
             Mu_d0pvtx,
             Mu_d0pvtxerr,
             Mu_sigd0,
             Mu_z0pvtx,
             Mu_isBad,
             Mu_isSig,
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
             Mu_topoetcone40);
    
    FillJets(NJet,
             Jet_eta,
             Jet_phi,
             Jet_pT,
             Jet_E,
             Jet_quality,
             Jet_JVF,
             Jet_MV1,
             Jet_SFw,
             Jet_JetLabel,
             Jet_nTrk,
             Jet_deltaR);
    
    FillTruthV(NTruthV,
               TruthV_eta,
               TruthV_phi,
               TruthV_pT,
               TruthV_m);
    
    fNumberOfEvents++;
    hCutFlows->Fill(0); // All events

    // sort by descending Pt
    sort(vec_elec.begin(), vec_elec.end(), sort_descending_Pt<Electron>);
    sort(vec_muon.begin(), vec_muon.end(), sort_descending_Pt<Muon>);
    sort(vec_jets.begin(), vec_jets.end(), sort_descending_Pt<Jet>);

/*
    SetElecTLV(NEl, El_pT, El_eta, El_phi, El_E);
//    double Mu_M = 105.6583715;
    SetMuonTLV(NMu, Mu_pT, Mu_eta, Mu_phi, Mu_M);
    SetJetTLV(NJet, Jet_pT, Jet_eta, Jet_phi, Jet_E);
*/

    // Get the baseline electrons, muons, and jets.
    for (auto & el_itr : vec_elec) {
        if ((el_itr.get_TLV()).Pt() > 10000. && fabs((el_itr.get_TLV()).Eta()) < 2.47) {
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
            el_itr.get_isSig() == 1) {
            el_itr.set_isSignal(1);
        }
    }
    for (auto & mu_itr : vec_muon) {
        if ((mu_itr.get_TLV()).Pt() > 10000. && fabs((mu_itr.get_TLV()).Eta()) < 2.4) {
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
        if ((jet_itr.get_TLV()).Pt() > 20000. && fabs((jet_itr.get_TLV()).Eta()) < 2.8) {
            jet_itr.set_baseline(1);
        }
        else {
            jet_itr.set_baseline(0);
        }
        jet_itr.set_passOR(0);
        if ((jet_itr.get_TLV()).Pt() > 20000. && fabs((jet_itr.get_TLV()).Eta()) < 2.5 && jet_itr.get_MV1() > 0.7892) {
            jet_itr.set_isBjet(1);
        }
    }
/*
    for (int i = 0; i < NEl; i++) {
        OR_Object tmp;
        tmp.tlv = m_el[i];
        tmp.charge = (*El_charge)[i];
        tmp.flavor = 11;
        if (tmp.tlv.Pt() > 10000. && fabs(tmp.tlv.Eta()) < 2.47) {
            tmp.baseline = 1;
        }
        else {
            tmp.baseline = 0;
        }
        tmp.passOR = 0;
        tmp.pT = (*El_pT)[i];
        tmp.eta = (*El_eta)[i];
        tmp.phi = (*El_phi)[i];
        m_el_passOR.push_back(tmp);
    }

    for (int i = 0; i < NMu; i++) {
        OR_Object tmp;
        tmp.tlv = m_mu[i];
        tmp.charge = (*Mu_charge)[i];
        tmp.flavor = 13;
        if (tmp.tlv.Pt() > 10000. && fabs(tmp.tlv.Eta()) < 2.4) {
            tmp.baseline = 1;
        }
        else {
            tmp.baseline = 0;
        }
        tmp.passOR = 0;
        tmp.pT = (*Mu_pT)[i];
        tmp.eta = (*Mu_eta)[i];
        tmp.phi = (*Mu_phi)[i];
        m_mu_passOR.push_back(tmp);
    }

    for (int i = 0; i < NJet; i++) {
        OR_Object tmp;
        tmp.tlv = m_jet[i];
        tmp.charge = 0;
        tmp.flavor = 0;
        if (tmp.tlv.Pt() > 20000. && fabs(tmp.tlv.Eta()) < 2.8) {
            tmp.baseline = 1;
        }
        else {
            tmp.baseline = 0;
        }
        tmp.passOR = 0;
        tmp.pT = (*Jet_pT)[i];
        tmp.eta = (*Jet_eta)[i];
        tmp.phi = (*Jet_phi)[i];
        m_jet_passOR.push_back(tmp);
    }
*/

    // Njet/Nelec/Nmuon before OR
    hCut1_Nelec->Fill(NEl);
    hCut1_Nmuon->Fill(NMu);
    hCut1_Njet->Fill(NJet);
    hCut1_Nlep->Fill(NEl + NMu);
    int Nbjet = 0;
    for (auto & jet_itr : vec_jets) {
        if (!jet_itr.get_isBjet()) continue;
        Nbjet++;
    }
    hCut1_Nbjet->Fill(Nbjet);
    
    // Apply the overlap removal.
    OverlapRemoval(&vec_elec, &vec_muon, &vec_jets);

    // Before applying any cuts
    int NEl_OR = 0;
    //cout << EventNumber << " vec_elec.size()=" << vec_elec.size() << endl;
    for (auto & el_itr : vec_elec) {
        if(!el_itr.get_passOR()) continue;
        NEl_OR++;
        hCut1_Elec_Pt->Fill( (el_itr.get_TLV()).Pt() );
        hCut1_Elec_Eta->Fill( (el_itr.get_TLV()).Eta() );
        hCut1_Elec_Phi->Fill( (el_itr.get_TLV()).Phi() );
        hCut1_lep_Pt->Fill( (el_itr.get_TLV()).Pt() );
        //if (vec_elec.size() >=3 )
        //cout << el_itr.get_pt() << endl;
    }
    hCut1_Nelec_OR->Fill(NEl_OR);

    int NMu_OR = 0;
    //cout << EventNumber << " vec_muon.size()=" << m_mu_passOR.size() << endl;
    for (auto & mu_itr : vec_muon) {
        if (!mu_itr.get_passOR()) continue;
        NMu_OR++;
        hCut1_Muon_Pt->Fill( (mu_itr.get_TLV()).Pt() );
        hCut1_Muon_Eta->Fill( (mu_itr.get_TLV()).Eta() );
        hCut1_Muon_Phi->Fill( (mu_itr.get_TLV()).Phi() );
        hCut1_lep_Pt->Fill( (mu_itr.get_TLV()).Pt() );
        
        //cout << mu.pT << endl;
    }
    hCut1_Nmuon_OR->Fill(NMu_OR);

    hCut1_Nlep_OR->Fill(NEl_OR + NMu_OR);
    
    int NJet_OR = 0;
    //cout << EventNumber << " vec_jets.size()=" << m_jet_passOR.size() << endl;
    for (auto & jet_itr : vec_jets) {
        if (!jet_itr.get_passOR()) continue;
        NJet_OR++;
        hCut1_Jet_Pt->Fill( (jet_itr.get_TLV()).Pt() );
        hCut1_Jet_Eta->Fill( (jet_itr.get_TLV()).Eta() );
        hCut1_Jet_Phi->Fill( (jet_itr.get_TLV()).Phi() );
        
        //cout << jet.pT << endl;
    }
    hCut1_Njet_OR->Fill(NJet_OR);

    int Nbjet_OR = 0;
    for (auto & jet_itr : vec_jets) {
        if (!jet_itr.get_passOR()) continue;
        if (!jet_itr.get_isBjet()) continue;
        Nbjet_OR++;
    }
    hCut1_Nbjet_OR->Fill(Nbjet_OR);

    hCut1_MET->Fill(Etmiss_Et);

/*
    sort(m_lep.begin(), m_lep.end(), sort_by_Pt);
    if (m_lep.size() >= 2) {
	TLorentzVector l1l2 = m_lep[0] + m_lep[1];
	hCut1_Meff->Fill( l1l2.M() );
    }
*/

    if (!passGRL) return kTRUE; // passGRL = -1 for MC
    fpassGRL++;
    hCutFlows->Fill(1); // GRL

    if (DetError) return kTRUE; // DetError = 0 => pass
    fDetError++;
    hCutFlows->Fill(2); // Global flags

    // Apply the overlap removal.
    //OverlapRemoval(&m_el_passOR, &m_mu_passOR, &m_jet_passOR);

    Int_t Nel = 0, Nmu = 0, Nel_sig = 0, Nmu_sig = 0;
    Int_t Nel_pt20 = 0, Nmu_pt20 = 0, Nel_sig_pt20 = 0, Nmu_sig_pt20 = 0;
    TLorentzVector el_tlv, mu_tlv;
    int Nbjet_pt20 = 0, Njet_pt50 = 0;
    int same_sign = 1;
    
    for (auto & el_itr : vec_elec) {
        if (el_itr.get_baseline() == true && el_itr.get_passOR() == true) {
            Nel++;
            if ((el_itr.get_TLV()).Pt() > 20000.) Nel_pt20++;
            if (el_itr.get_isSignal()) {
                Nel_sig++;
                if ((el_itr.get_TLV()).Pt() > 20000.) {
                    Nel_sig_pt20++;
                    el_tlv = el_tlv + el_itr.get_TLV();
                    same_sign = same_sign * el_itr.get_charge();
                }
            }
        }
    }
    for (auto & mu_itr : vec_muon) {
        if (mu_itr.get_baseline() == true && mu_itr.get_passOR() == true) {
            Nmu++;
            if ((mu_itr.get_TLV()).Pt() > 20000.) Nmu_pt20++;
            if (mu_itr.get_isSignal()) {
                Nmu_sig++;
                if ((mu_itr.get_TLV()).Pt() > 20000.) {
                    Nmu_sig_pt20++;
                    mu_tlv = mu_tlv + mu_itr.get_TLV();
                    same_sign = same_sign * mu_itr.get_charge();
                }
            }
        }
    }
    for (auto & jet_itr : vec_jets) {
        if (!jet_itr.get_passOR()) continue;
        if (jet_itr.get_quality() == 1) continue; // 1=bad jet from SUSYTools IsGoodJet
        if (jet_itr.get_isBjet()) Nbjet_pt20++;
        if (jet_itr.get_pt() > 50000.) Njet_pt50++;
    }
    
/*
    vector<OR_Object>::iterator el_itr = m_el_passOR.begin();
    vector<OR_Object>::iterator el_end = m_el_passOR.end();
    for (; el_itr != el_end; el_itr++) {
        if (el_itr->baseline == true && el_itr->passOR == true) {
            Nel++;
            if (el_itr->tlv.Pt() > 20000.) Nel_pt20++;
            int index = distance(m_el_passOR.begin(), el_itr);
            double theta = el_itr->tlv.Theta();
            if ((*El_ptvarcone20)[index] / (*El_pT)[index] < 0.06 &&
                (*El_topoetcone20)[index] / (*El_pT)[index] < 0.06 &&
                fabs( (*El_z0pvtx)[index] * TMath::Sin(theta) ) < 0.4 &&
                fabs( (*El_sigd0)[index] ) < 3.0  &&
                (*El_isSig)[index] == 1) {
                Nel_sig++;
                if (el_itr->tlv.Pt() > 20000.) {
                    Nel_sig_pt20++;
                    el_tlv = el_tlv + el_itr->tlv;
                    same_sign = same_sign * (*El_charge)[index];
                }
            }
        }
    }

    vector<OR_Object>::iterator mu_itr = m_mu_passOR.begin();
    vector<OR_Object>::iterator mu_end = m_mu_passOR.end();
    for (; mu_itr != mu_end; mu_itr++) {
        if (mu_itr->baseline == true && mu_itr->passOR == true) {
            Nmu++;
            if (mu_itr->tlv.Pt() > 20000.) Nmu_pt20++;
            int index = distance(m_mu_passOR.begin(), mu_itr);
            double theta = mu_itr->tlv.Theta();
            if ((*Mu_ptvarcone30)[index] / (*Mu_pT)[index] < 0.06 &&
                fabs( (*Mu_z0pvtx)[index] * TMath::Sin(theta) ) < 0.4 &&
                fabs( (*Mu_sigd0)[index] ) < 3.0) {
                Nmu_sig++;
                if (mu_itr->tlv.Pt() > 20000.) {
                    Nmu_sig_pt20++;
                    mu_tlv = mu_tlv + mu_itr->tlv;
                    same_sign = same_sign * (*Mu_charge)[index];
                }
            }
        }
    }
    vector<OR_Object>::iterator jet_itr = m_jet_passOR.begin();
    vector<OR_Object>::iterator jet_end = m_jet_passOR.end();
    for (; jet_itr != jet_end; jet_itr++) {
        if (jet_itr->passOR != 1) continue;
        int index = distance(m_jet_passOR.begin(), jet_itr);
        if ((*Jet_quality)[index] == 1) continue; // 1=bad jet from SUSYTools IsGoodJet
        if ((*Jet_pT)[index] > 20000. && fabs((*Jet_eta)[index]) < 2.5 && (*Jet_MV1)[index] > 0.7892)  Nbjet_pt20++;
        if ((*Jet_pT)[index] > 50000.) Njet_pt50++;
    }
*/
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

        int ielec = 0;
        for (auto & el_itr : vec_elec) {
            if (el_itr.get_baseline() == true &&
                el_itr.get_passOR() == true &&
                el_itr.get_isSignal() == true &&
                (el_itr.get_TLV()).Pt()  > 20000.) {
                ielec++;
                
                hCut5_Elec_Pt->Fill( (el_itr.get_TLV()).Pt() );
                hCut5_Elec_Eta->Fill( (el_itr.get_TLV()).Eta() );
                hCut5_Elec_Phi->Fill( (el_itr.get_TLV()).Phi() );
                
                hCut5_lep_Pt->Fill( (el_itr.get_TLV()).Pt() );
            }
        }
        hCut5_Nelec->Fill(ielec);
/*
        el_itr = m_el_passOR.begin();
        for (; el_itr != el_end; el_itr++) {
            if (el_itr->baseline == true && el_itr->passOR == true) {
                //Nel++;
                //if (el_itr->tlv.Pt() > 20000.) Nel_pt20++;
                int index = distance(m_el_passOR.begin(), el_itr);
                double theta = el_itr->tlv.Theta();
                if ((*El_ptvarcone20)[index] / (*El_pT)[index] < 0.06 &&
                    (*El_topoetcone20)[index] / (*El_pT)[index] < 0.06 &&
                    fabs( (*El_z0pvtx)[index] * TMath::Sin(theta) ) < 0.4 &&
                    fabs( (*El_sigd0)[index] ) < 3.0  &&
                    (*El_isSig)[index] == 1) {
                    //Nel_sig++;
                    if (el_itr->tlv.Pt() > 20000.) {
                        //Nel_sig_pt20++;
                        //el_tlv = el_tlv + el_itr->tlv;
                        //same_sign = same_sign * (*El_charge)[index];
                        ielec++;
                        
                        hCut5_Elec_Pt->Fill( el_itr->tlv.Pt() );
                        hCut5_Elec_Eta->Fill( el_itr->tlv.Eta() );
                        hCut5_Elec_Phi->Fill( el_itr->tlv.Phi() );
                        
                        hCut5_lep_Pt->Fill( el_itr->tlv.Pt() );
                    }
                }
            }
 
        }
*/
        
        int imuon = 0;
        for (auto & mu_itr : vec_muon) {
            if (mu_itr.get_baseline() == true &&
                mu_itr.get_passOR() == true &&
                mu_itr.get_isSignal() == true &&
                (mu_itr.get_TLV()).Pt() > 20000.) {
                imuon++;
                
                hCut5_Muon_Pt->Fill( (mu_itr.get_TLV()).Pt() );
                hCut5_Muon_Eta->Fill( (mu_itr.get_TLV()).Eta() );
                hCut5_Muon_Phi->Fill( (mu_itr.get_TLV()).Phi() );
                
                hCut5_lep_Pt->Fill( (mu_itr.get_TLV()).Pt() );
            }
        }
        hCut5_Nmuon->Fill(imuon);
/*
        mu_itr = m_mu_passOR.begin();
        for (; mu_itr != mu_end; mu_itr++) {
            if (mu_itr->baseline == true && mu_itr->passOR == true) {
                //Nmu++;
                //if (mu_itr->tlv.Pt() > 20000.) Nmu_pt20++;
                int index = distance(m_mu_passOR.begin(), mu_itr);
                double theta = mu_itr->tlv.Theta();
                if ((*Mu_ptvarcone30)[index] / (*Mu_pT)[index] < 0.06 &&
                    fabs( (*Mu_z0pvtx)[index] * TMath::Sin(theta) ) < 0.4 &&
                    fabs( (*Mu_sigd0)[index] ) < 3.0) {
                    //Nmu_sig++;
                    if (mu_itr->tlv.Pt() > 20000.) {
                        //Nmu_sig_pt20++;
                        //mu_tlv = mu_tlv + mu_itr->tlv;
                        //same_sign = same_sign * (*Mu_charge)[index];
                        imuon++;
                        
                        hCut5_Muon_Pt->Fill( mu_itr->tlv.Pt() );
                        hCut5_Muon_Eta->Fill( mu_itr->tlv.Eta() );
                        hCut5_Muon_Phi->Fill( mu_itr->tlv.Phi() );
                        
                        hCut5_lep_Pt->Fill( mu_itr->tlv.Pt() );
                    }
                }
            }
        }
*/
        
        
        
        int ijets = 0, ibjets = 0;
        double jet_pt = 0, jet_eta = 0, jet_phi = 0;
        for (auto & jet_itr : vec_jets) {
            if (!jet_itr.get_passOR()) continue;
            if (jet_itr.get_quality() == 1) continue; // 1=bad jet from SUSYTools IsGoodJet
            if (jet_itr.get_isBjet() == 1) ibjets++;
            if ((jet_itr.get_TLV()).Pt() > 50000.) {
                ijets++;
                
                hCut5_Jet_Pt->Fill( (jet_itr.get_TLV()).Pt() );
                hCut5_Jet_Eta->Fill( (jet_itr.get_TLV()).Eta() );
                hCut5_Jet_Phi->Fill( (jet_itr.get_TLV()).Phi() );
            }
        }
        hCut5_Njet->Fill(ijets);
        hCut5_Nbjet->Fill(ibjets);
        
        hCut5_Nlep->Fill(ielec + imuon);
        
        hCut5_MET->Fill(Etmiss_Et);
        hCut5_Meff->Fill(0);
/*
        jet_itr = m_jet_passOR.begin();
        for (; jet_itr != jet_end; jet_itr++) {
            if (jet_itr->passOR != 1) continue;
            int index = distance(m_jet_passOR.begin(), jet_itr);
            if ((*Jet_quality)[index] == 1) continue; // 1=bad jet from SUSYTools IsGoodJet
            if ((*Jet_pT)[index] > 20000. && fabs((*Jet_eta)[index]) < 2.5 && (*Jet_MV1)[index] > 0.7892)  {//Nbjet_pt20++;
                ibjets++;
            }
            if ((*Jet_pT)[index] > 50000.) {//Njet_pt50++;
                ijets++;
                jet_pt = (*Jet_pT)[index];
                jet_eta = (*Jet_eta)[index];
                jet_phi = (*Jet_phi)[index];
                
                hCut5_Jet_Pt->Fill(jet_pt);
                hCut5_Jet_Eta->Fill(jet_eta);
                hCut5_Jet_Phi->Fill(jet_phi);
            }
        }
*/
        
    }

    TLorentzVector ml1l2_tlv = el_tlv + mu_tlv;

    hCut5_Meff->Fill( ml1l2_tlv.M() );
    
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

			if (Etmiss_Et > 150000.) {
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

			if (Etmiss_Et > 150000.) {
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

			if (Etmiss_Et > 150000.) {
			    fMET_mumu++;
			    hCutFlows->Fill(26); // MET > 150 GeV
			}
		    }
		}
	    }
	}
    }


   return kTRUE;
}

void AnaNtupBunchSapcing::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void AnaNtupBunchSapcing::Terminate()
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
