#define AnaNtupV04Selector_cxx
// The class definition in AnaNtupV04Selector.h has been generated automatically
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
// Root > T->Process("AnaNtupV04Selector.C")
// Root > T->Process("AnaNtupV04Selector.C","some options")
// Root > T->Process("AnaNtupV04Selector.C+")
//

#include "AnaNtupV04Selector.h"
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

void AnaNtupV04Selector::SetElecTLV(int iEl, vector<double> *el_pt, 
                                             vector<double> *el_eta, 
                                             vector<double> *el_phi,
                                             vector<double> *el_E)
{
    for (int i = 0; i < iEl; i++) {
        TLorentzVector tlv;
        tlv.SetPtEtaPhiE( (*el_pt)[i], (*el_eta)[i], (*el_phi)[i], (*el_E)[i] );
        m_el.push_back(tlv);
    }
}

void AnaNtupV04Selector::SetMuonTLV(int iMu, vector<double> *mu_pt, 
                                             vector<double> *mu_eta, 
                                             vector<double> *mu_phi, 
                                             double mu_M)
{
    for (int i = 0; i < iMu; i++) {
        TLorentzVector tlv;
        tlv.SetPtEtaPhiM( (*mu_pt)[i], (*mu_eta)[i], (*mu_phi)[i], mu_M );
        m_mu.push_back(tlv);
    }
}

void AnaNtupV04Selector::SetJetTLV(int iJet, vector<double> *jet_pt, 
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


void AnaNtupV04Selector::OverlapRemoval(vector<OR_Object> *el_obj,
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
/*
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
*/
}

void AnaNtupV04Selector::Begin(TTree * /*tree*/)
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

void AnaNtupV04Selector::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

Bool_t AnaNtupV04Selector::Process(Long64_t entry)
{
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // It can be passed to either AnaNtupV04Selector::GetEntry() or TBranch::GetEntry()
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

    m_el.clear();
    m_mu.clear();
    m_jet.clear();

    m_el_passOR.clear();
    m_mu_passOR.clear();
    m_jet_passOR.clear();
    m_lep_passOR.clear();

    fChain->GetTree()->GetEntry(entry);
    
    fNumberOfEvents++;
    hCutFlows->Fill(0); // All events

    SetElecTLV(NEl, El_pT, El_eta, El_phi, El_E);
    double Mu_M = 105.6583715;
    SetMuonTLV(NMu, Mu_pT, Mu_eta, Mu_phi, Mu_M);
    SetJetTLV(NJet, Jet_pT, Jet_eta, Jet_phi, Jet_E);

    // Get the baseline electrons, muons, and jets.
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
        m_jet_passOR.push_back(tmp);
    }
/*
    // sort by descending Pt
    // if doing sort, then the other vectors must be sorted too!
    sort(m_el_passOR.begin(), m_el_passOR.end(), sort_descending_Pt);
    sort(m_mu_passOR.begin(), m_mu_passOR.end(), sort_descending_Pt);
    sort(m_jet_passOR.begin(), m_jet_passOR.end(), sort_descending_Pt);
*/
    if (!passGRL) return kTRUE; // passGRL = -1 for MC
    fpassGRL++;
    hCutFlows->Fill(1); // GRL

    if (DetError) return kTRUE; // DetError = 0 => pass
    fDetError++;
    hCutFlows->Fill(2); // Global flags 

    // debug
    //cout << "Processing OR for " << EventNumber << " nmu=" << NMu << " nele=" << NEl << endl;

    // Apply the overlap removal.
    OverlapRemoval(&m_el_passOR, &m_mu_passOR, &m_jet_passOR);
/*
    // debug
    if (EventNumber == 4745){
        cout << "EventNumber = " << EventNumber << endl;
        cout << "NEl = " << NEl << endl;
        for (int i = 0; i < NEl; i++) {
            //cout << "(*El_pT).at(i) = " << (*El_pT).at(i) << ", "
            //<< "(*El_eta).at(i) = " << (*El_eta).at(i) << ", "
            //<< "(*El_phi).at(i) = " << (*El_phi).at(i) << ", "
            cout << "(*El_sigd0).at(i) = " << (*El_sigd0).at(i) << endl;
            cout << "m_el_passOR.at(i).tlv.Pt() = " << m_el_passOR.at(i).tlv.Pt() << ", "
                 << "m_el_passOR.at(i).tlv.Eta() = " << m_el_passOR.at(i).tlv.Eta() << ", "
                 << "m_el_passOR.at(i).tlv.Phi() = " << m_el_passOR.at(i).tlv.Phi() << ", "
                 << "m_el_passOR.at(i).baseline = " << m_el_passOR.at(i).baseline << ", "
                 << "m_el_passOR.at(i).passOR = " << m_el_passOR.at(i).passOR << endl;
        }
        cout << "NMu = " << NMu << endl;
        for (int i = 0; i < NMu; i++) {
            //cout << "(*Mu_pT).at(i) = " << (*Mu_pT).at(i) << ", "
            //<< "(*Mu_eta).at(i) = " << (*Mu_eta).at(i) << ", "
            //<< "(*Mu_phi).at(i) = " << (*Mu_phi).at(i) << ", "
            cout << "(*Mu_sigd0).at(i) = " << (*Mu_sigd0).at(i) << endl;
            cout << "m_mu_passOR.at(i).tlv.Pt() = " << m_mu_passOR.at(i).tlv.Pt() << ", "
                 << "m_mu_passOR.at(i).tlv.Eta() = " << m_mu_passOR.at(i).tlv.Eta() << ", "
                 << "m_mu_passOR.at(i).tlv.Phi() = " << m_mu_passOR.at(i).tlv.Phi() << ", "
                 << "m_mu_passOR.at(i).baseline = " << m_mu_passOR.at(i).baseline << ", "
                 << "m_mu_passOR.at(i).passOR = " << m_mu_passOR.at(i).passOR << endl;
        }
        cout << "NJet = " << NJet << endl;
    }
*/
/*
    // merge e and mu
    for (int i = 0; i < static_cast<int> (m_el_passOR.size()); i++) {
        OR_Object tmp = m_el_passOR.at(i);
        m_lep_passOR.push_back(tmp);
    }
    for (int i = 0; i < static_cast<int> (m_mu_passOR.size()); i++) {
        OR_Object tmp = m_mu_passOR.at(i);
        m_lep_passOR.push_back(tmp);
    }

    // debug
    cout << "m_lep_passOR.size()=" << m_lep_passOR.size()
         << " m_el_passOR.size()=" << m_el_passOR.size()
         << " m_mu_passOR.size()=" << m_mu_passOR.size() << endl;

    if (m_lep_passOR.size() >= 5) {
        cout << "Before sort:" << endl;
        for (int i = 0; i < static_cast<int> (m_lep_passOR.size()); i++) {
            cout << "m_lep_passOR.at(" << i << ").tlv.Pt()=" << m_lep_passOR.at(i).tlv.Pt() << " flavor=" << m_lep_passOR.at(i).flavor << endl;
        }
    }

    sort(m_lep_passOR.begin(), m_lep_passOR.end(), sort_descending_Pt);

    // debug
    if (m_lep_passOR.size() >= 5) {
        cout << "After sort:" << endl;
        for (int i = 0; i < static_cast<int> (m_lep_passOR.size()); i++) {
            cout << "m_lep_passOR.at(" << i << ").tlv.Pt()=" << m_lep_passOR.at(i).tlv.Pt() << " flavor=" << m_lep_passOR.at(i).flavor << endl;
        }
    }
    Int_t Nlep = 0;
    vector<OR_Object>::iterator lep_itr = m_lep_passOR.begin();
    vector<OR_Object>::iterator lep_end = m_lep_passOR.end();
    for (; lep_itr != lep_end; lep_itr++) {
        if (lep_itr->baseline == true && lep_itr->passOR == true) Nlep++;
    }
    if (Nlep >= 2) {
        fAtLeastTwoLeptons++;
        hCutFlows->Fill(3);
    }
*/
/*
    Int_t Nel = 0, Nmu = 0;
    vector<OR_Object>::iterator el_itr = m_el_passOR.begin();
    vector<OR_Object>::iterator el_end = m_el_passOR.end();
    for (; el_itr != el_end; el_itr++) {
        if (el_itr->baseline == true && el_itr->passOR == true) Nel++;
    }
    vector<OR_Object>::iterator mu_itr = m_mu_passOR.begin();
    vector<OR_Object>::iterator mu_end = m_mu_passOR.end();
    for (; mu_itr != mu_end; mu_itr++) {
        if (mu_itr->baseline == true && mu_itr->passOR == true) Nmu++;
    }
    if ( (Nel + Nmu) >= 2) {
        // debug
        //cout << EventNumber << " nmu=" << Nmu << " nele=" << Nel << endl;
        fAtLeastTwoLeptons++;
        hCutFlows->Fill(3); // ≥ 2 leptons (10 GeV)
    }
*/
/*
    Nel = 0, Nmu = 0;
    el_itr = m_el_passOR.begin();
    mu_itr = m_mu_passOR.begin();
    //cout << EventNumber << " Nel=" << NEl << " Nmu=" << NMu << endl;
    for (; el_itr != el_end; el_itr++) {
        if (el_itr->baseline == true && el_itr->passOR == true) {
            if (el_itr->tlv.Pt() > 20000.) Nel++;
            //cout << EventNumber << " nel=" << distance(m_el_passOR.begin(), el_itr) << " pt=" << el_itr->tlv.Pt();
            //if (el_itr->tlv.Pt() > 20000.) cout << " Pt>20GeV" << endl;
            //else cout << endl;

            //if (el_itr->tlv.Pt() > 20000.) {
                //Nel++;
                //cout << EventNumber << " Nel=" << NEl << " Nmu=" << NMu << " nel=" << distance(m_el_passOR.begin(), el_itr) << " pt=" << el_itr->tlv.Pt() << " Pt>20GeV" << endl;
            //}
        }
    }
    for (; mu_itr != mu_end; mu_itr++) {
        if (mu_itr->baseline == true && mu_itr->passOR == true) {
            if (mu_itr->tlv.Pt() > 20000.) Nmu++;
            //cout << EventNumber << " nmu=" << distance(m_mu_passOR.begin(), mu_itr) << " pt=" << mu_itr->tlv.Pt();
            //if (mu_itr->tlv.Pt() > 20000.) cout << " Pt>20GeV" << endl;
            //else cout << endl;

            //if (mu_itr->tlv.Pt() > 20000.) {
                //Nmu++;
                //cout << EventNumber << " Nel=" << NEl << " Nmu=" << NMu << " nmu=" << distance(m_mu_passOR.begin(), mu_itr) << " pt=" << mu_itr->tlv.Pt() << " Pt>20GeV" << endl;
            //}
        }
    }
    if ( (Nel + Nmu) == 2) {
        //cout << EventNumber << " Nel+Nmu=2" << " nel=" << Nel << " nmu=" << Nmu << endl;
        fEqualTwoLeptons++;
        hCutFlows->Fill(4); // == 2 leptons (20 GeV) (! l3 signal lepton 10 GeV)
    }
*/
/*
    Nel = 0, Nmu = 0;
    int Nel_sig = 0, Nmu_sig = 0, Nel_sig_pt20 = 0, Nmu_sig_pt20 = 0;
    el_itr = m_el_passOR.begin();
    mu_itr = m_mu_passOR.begin();
    for (; el_itr != el_end; el_itr++) {
    	if (el_itr->baseline == true && el_itr->passOR == true) {
    	    Nel++;
    	    //debug
            //if (EventNumber == 10581) {
            ////if (EventNumber == 13222) {
                //cout << EventNumber << "el pt=" << el_itr->tlv.Pt() << " eta=" << el_itr->tlv.Eta() << " phi=" << el_itr->tlv.Phi();
                //int index = distance(m_el_passOR.begin(), el_itr);
                //double theta = el_itr->tlv.Theta();
                //cout << " sigd0=" << (*El_sigd0)[index] << " ptvarcone20/pt=" << (*El_ptvarcone20)[index] / (*El_pT)[index]
                //<< " topetcone20/pt=" << (*El_topoetcone20)[index] / (*El_pT)[index] << endl;
            //}

            int index = distance(m_el_passOR.begin(), el_itr);
            double theta = el_itr->tlv.Theta();
            if ((*El_ptvarcone20)[index] / (*El_pT)[index] < 0.06 && 
                (*El_topoetcone20)[index] / (*El_pT)[index] < 0.06 &&
                fabs( (*El_z0pvtx)[index] * TMath::Sin(theta) ) < 0.4 &&
                fabs( (*El_sigd0)[index] ) < 3.0  &&
                (*El_isSig)[index] == 1) {
                Nel_sig++;
                if (el_itr->tlv.Pt() > 20000.) Nel_sig_pt20++;
                //cout << EventNumber << " el=" << index << " pt=" << el_itr->tlv.Pt();
                //if (el_itr->tlv.Pt() > 20000.) cout << " Pt>20" << endl;
                //else cout << endl;
    	    }
    	}
    }
    for (; mu_itr != mu_end; mu_itr++) {
        if (mu_itr->baseline == true && mu_itr->passOR == true) {
            //// debug
            //int index = distance(m_mu_passOR.begin(), mu_itr);  
            //cout << EventNumber << " mu sigd0=" << (*Mu_sigd0)[index] << " ptvarcone30/pt=" << (*Mu_ptvarcone30)[index] / (*Mu_pT)[index] << endl;

            Nmu++;
            //// debug
            //cout << EventNumber << " mu sigd0 all: Mu_sigd0.size()=" << Mu_sigd0->size() << endl;
            //for (int i = 0; i < Mu_sigd0->size(); i++) cout << "sigd0=" << (*Mu_sigd0)[i] << endl;
            //if (EventNumber == 10581) {
            ////if (EventNumber == 13222) {
                //cout << EventNumber << "mu pt=" << mu_itr->tlv.Pt() << " eta=" << mu_itr->tlv.Eta() << " phi=" << mu_itr->tlv.Phi();
                //cout << " sigd0=" << (*Mu_sigd0)[index] << " ptvarcone30/pt=" << (*Mu_ptvarcone30)[index] / (*Mu_pT)[index] << endl;
            //}

            int index = distance(m_mu_passOR.begin(), mu_itr);
            double theta = mu_itr->tlv.Theta();
            if ((*Mu_ptvarcone30)[index] / (*Mu_pT)[index] < 0.06 &&
                fabs( (*Mu_z0pvtx)[index] * TMath::Sin(theta) ) < 0.4 &&
                fabs( (*Mu_sigd0)[index] ) < 3.0) {
                Nmu_sig++;
                if (mu_itr->tlv.Pt() > 20000.) Nmu_sig_pt20++;
                // debug
                //cout << EventNumber << " mu=" << index << " pt=" << mu_itr->tlv.Pt();
                //if (mu_itr->tlv.Pt() > 20000.) cout << " Pt>20" << endl;
                //else cout << endl;
            }
        }
    }
    //if ( (Nel + Nmu) >= 2 && (Nel_sig_pt20 + Nmu_sig_pt20) == 2) {
    if ((Nel_sig_pt20 + Nmu_sig_pt20) == 2) {
    //if ( (Nel + Nmu) >= 2) {
        // debug
        //cout << EventNumber << " nlep=" << Nel+Nmu << " nel=" << Nel << " nmu=" << Nmu << " nelsig=" << Nel_sig << " nmusig=" << Nmu_sig << " nelsigpt20=" << Nel_sig_pt20 << " nmusigpt20=" << Nmu_sig_pt20 << endl;
        fEqualTwoSignalLeptons++;
        hCutFlows->Fill(5); // == 2 signal leptons (20 GeV)
    }
*/

    Int_t Nel = 0, Nmu = 0, Nel_sig = 0, Nmu_sig = 0;
    Int_t Nel_pt20 = 0, Nmu_pt20 = 0, Nel_sig_pt20 = 0, Nmu_sig_pt20 = 0;
    TLorentzVector el_tlv, mu_tlv;
    int Nbjet_pt20 = 0, Njet_pt50 = 0;
    int same_sign = 1;
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

void AnaNtupV04Selector::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void AnaNtupV04Selector::Terminate()
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
