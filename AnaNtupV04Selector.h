//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon May  4 22:32:04 2015 by ROOT version 5.34/25
// from TTree AnaNtup/AnaNtup
// found on file: user.jpoveda.5286937._000001.output.root
//////////////////////////////////////////////////////////

#ifndef AnaNtupV04Selector_h
#define AnaNtupV04Selector_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TLorentzVector.h>

// Header file for the classes stored in the TTree if any.
//#include "/var/build/72a/x86_64-slc6-gcc48-opt-build/projects/ROOT-5.34.25/src/ROOT/5.34.25/cint/cint/lib/prec_stl/vector"
//#include "/var/build/72a/x86_64-slc6-gcc48-opt-build/projects/ROOT-5.34.25/src/ROOT/5.34.25/cint/cint/lib/prec_stl/vector"

// Fixed size dimensions of array or collections stored in the TTree if any.

#include <iostream>
#include <iomanip>
#include <vector>
#include <iterator>
using namespace std;

struct OR_Object {
    TLorentzVector tlv;
    bool baseline;
    bool passOR;
    int charge;
    int flavor;
};

bool sort_descending_Pt(const OR_Object obj1, const OR_Object obj2)
{
    return obj1.tlv.Pt() > obj2.tlv.Pt();
}

class AnaNtupV04Selector : public TSelector {
public:
    Int_t fNumberOfEvents;
    Int_t fpassGRL;
    Int_t fDetError;
    Int_t fAtLeastTwoLeptons;
    Int_t fEqualTwoLeptons;
    Int_t fEqualTwoSignalLeptons;
    // El-El channel
    Int_t fChannelSelection_elel;
    Int_t fTrigger_elel;
    Int_t fMl1l2_elel;
    Int_t fAtLeastOneBJet_elel;
    Int_t fAtLeastFourJets_elel;
    Int_t fSameSign_elel;
    Int_t fMET_elel;
    // El-Mu channel
    Int_t fChannelSelection_elmu;
    Int_t fTrigger_elmu;
    Int_t fMl1l2_elmu;
    Int_t fAtLeastOneBJet_elmu;
    Int_t fAtLeastFourJets_elmu;
    Int_t fSameSign_elmu;
    Int_t fMET_elmu;
    // Mu-Mu channel
    Int_t fChannelSelection_mumu;
    Int_t fTrigger_mumu;
    Int_t fMl1l2_mumu;
    Int_t fAtLeastOneBJet_mumu;
    Int_t fAtLeastFourJets_mumu;
    Int_t fSameSign_mumu;
    Int_t fMET_mumu;

    vector<TLorentzVector> m_el;
    vector<TLorentzVector> m_mu;
    vector<TLorentzVector> m_jet;

    vector<OR_Object> m_el_passOR;
    vector<OR_Object> m_mu_passOR;
    vector<OR_Object> m_jet_passOR;
    vector<OR_Object> m_lep_passOR;

    TH1* hCutFlows;
    TTree* myTree;

public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain

   // Declaration of leaf types
   Int_t           EventNumber;
   Int_t           ChannelNumber;
   Double_t        AvgMu;
   Double_t        EventWeight;
   Int_t           bcid;
   Int_t           LB;
   Int_t           passGRL;
   Int_t           RunNb;
   Int_t           DetError;
   Int_t           NMu;
   vector<double>  *Mu_eta;
   vector<double>  *Mu_phi;
   vector<double>  *Mu_pT;
   vector<double>  *Mu_SFw;
   vector<int>     *Mu_charge;
   vector<double>  *Mu_d0pvtx;
   vector<double>  *Mu_d0pvtxerr;
   vector<double>  *Mu_sigd0;
   vector<double>  *Mu_z0pvtx;
   vector<int>     *Mu_isBad;
   vector<int>     *Mu_isSig;
   vector<int>     *Mu_isCosmic;
   vector<int>     *Mu_type;
   vector<int>     *Mu_origin;
   vector<double>  *Mu_ptcone20;
   vector<double>  *Mu_ptcone30;
   vector<double>  *Mu_ptcone40;
   vector<double>  *Mu_ptvarcone20;
   vector<double>  *Mu_ptvarcone30;
   vector<double>  *Mu_ptvarcone40;
   vector<double>  *Mu_topoetcone20;
   vector<double>  *Mu_topoetcone30;
   vector<double>  *Mu_topoetcone40;
   Int_t           NEl;
   vector<double>  *El_eta;
   vector<double>  *El_phi;
   vector<double>  *El_pT;
   vector<double>  *El_E;
   vector<int>     *El_charge;
   vector<double>  *El_sigd0;
   vector<double>  *El_z0pvtx;
   vector<double>  *El_d0pvtx;
   vector<double>  *El_d0pvtxerr;
   vector<double>  *El_SFw;
   vector<double>  *El_SFwMed;
   vector<int>     *El_isSig;
   vector<int>     *El_isSigMed;
   vector<int>     *El_type;
   vector<int>     *El_origin;
   vector<double>  *El_ptcone20;
   vector<double>  *El_ptcone30;
   vector<double>  *El_ptcone40;
   vector<double>  *El_ptvarcone20;
   vector<double>  *El_ptvarcone30;
   vector<double>  *El_ptvarcone40;
   vector<double>  *El_topoetcone20;
   vector<double>  *El_topoetcone30;
   vector<double>  *El_topoetcone40;
   Int_t           NJet;
   vector<double>  *Jet_eta;
   vector<double>  *Jet_phi;
   vector<double>  *Jet_pT;
   vector<double>  *Jet_E;
   vector<double>  *Jet_quality;
   vector<double>  *Jet_JVF;
   vector<double>  *Jet_MV1;
   vector<double>  *Jet_SFw;
   vector<int>     *Jet_JetLabel;
   vector<int>     *Jet_nTrk;
   Int_t           NTruthV;
   vector<double>  *TruthV_eta;
   vector<double>  *TruthV_phi;
   vector<double>  *TruthV_pT;
   vector<double>  *TruthV_m;
   Float_t         Etmiss_Etx;
   Float_t         Etmiss_Ety;
   Float_t         Etmiss_Et;
   Int_t           SUSY_Spart_pdgId1;
   Int_t           SUSY_Spart_pdgId2;
   Float_t         PV_z;

   // List of branches
   TBranch        *b_EventNumber;   //!
   TBranch        *b_ChannelNumber;   //!
   TBranch        *b_AvgMu;   //!
   TBranch        *b_EventWeight;   //!
   TBranch        *b_bcid;   //!
   TBranch        *b_LB;   //!
   TBranch        *b_passGRL;   //!
   TBranch        *b_RunNb;   //!
   TBranch        *b_DetError;   //!
   TBranch        *b_NMu;   //!
   TBranch        *b_Mu_eta;   //!
   TBranch        *b_Mu_phi;   //!
   TBranch        *b_Mu_pT;   //!
   TBranch        *b_Mu_SFw;   //!
   TBranch        *b_Mu_charge;   //!
   TBranch        *b_Mu_d0pvtx;   //!
   TBranch        *b_Mu_d0pvtxerr;   //!
   TBranch        *b_Mu_sigd0;   //!
   TBranch        *b_Mu_z0pvtx;   //!
   TBranch        *b_Mu_isBad;   //!
   TBranch        *b_Mu_isSig;   //!
   TBranch        *b_Mu_isCosmic;   //!
   TBranch        *b_Mu_type;   //!
   TBranch        *b_Mu_origin;   //!
   TBranch        *b_Mu_ptcone20;   //!
   TBranch        *b_Mu_ptcone30;   //!
   TBranch        *b_Mu_ptcone40;   //!
   TBranch        *b_Mu_ptvarcone20;   //!
   TBranch        *b_Mu_ptvarcone30;   //!
   TBranch        *b_Mu_ptvarcone40;   //!
   TBranch        *b_Mu_topoetcone20;   //!
   TBranch        *b_Mu_topoetcone30;   //!
   TBranch        *b_Mu_topoetcone40;   //!
   TBranch        *b_NEl;   //!
   TBranch        *b_El_eta;   //!
   TBranch        *b_El_phi;   //!
   TBranch        *b_El_pT;   //!
   TBranch        *b_El_E;   //!
   TBranch        *b_El_charge;   //!
   TBranch        *b_El_sigd0;   //!
   TBranch        *b_El_z0pvtx;   //!
   TBranch        *b_El_d0pvtx;   //!
   TBranch        *b_El_d0pvtxerr;   //!
   TBranch        *b_El_SFw;   //!
   TBranch        *b_El_SFwMed;   //!
   TBranch        *b_El_isSig;   //!
   TBranch        *b_El_isSigMed;   //!
   TBranch        *b_El_type;   //!
   TBranch        *b_El_origin;   //!
   TBranch        *b_El_ptcone20;   //!
   TBranch        *b_El_ptcone30;   //!
   TBranch        *b_El_ptcone40;   //!
   TBranch        *b_El_ptvarcone20;   //!
   TBranch        *b_El_ptvarcone30;   //!
   TBranch        *b_El_ptvarcone40;   //!
   TBranch        *b_El_topoetcone20;   //!
   TBranch        *b_El_topoetcone30;   //!
   TBranch        *b_El_topoetcone40;   //!
   TBranch        *b_NJet;   //!
   TBranch        *b_Jet_eta;   //!
   TBranch        *b_Jet_phi;   //!
   TBranch        *b_Jet_pT;   //!
   TBranch        *b_Jet_E;   //!
   TBranch        *b_Jet_quality;   //!
   TBranch        *b_Jet_JVF;   //!
   TBranch        *b_Jet_MV1;   //!
   TBranch        *b_Jet_SFw;   //!
   TBranch        *b_Jet_JetLabel;   //!
   TBranch        *b_Jet_nTrk;   //!
   TBranch        *b_NTruthV;   //!
   TBranch        *b_TruthV_eta;   //!
   TBranch        *b_TruthV_phi;   //!
   TBranch        *b_TruthV_pT;   //!
   TBranch        *b_TruthV_m;   //!
   TBranch        *b_Etmiss_Etx;   //!
   TBranch        *b_Etmiss_Ety;   //!
   TBranch        *b_Etmiss_Et;   //!
   TBranch        *b_SUSY_Spart_pdgId1;   //!
   TBranch        *b_SUSY_Spart_pdgId2;   //!
   TBranch        *b_PV_z;   //!

   AnaNtupV04Selector(TTree * /*tree*/ =0) : fChain(0) { }
   virtual ~AnaNtupV04Selector() { }
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

    virtual void SetElecTLV(int iEl, vector<double> *el_pt,
                                     vector<double> *el_eta,
                                     vector<double> *el_phi,
                                     vector<double> *el_E);

    virtual void SetMuonTLV(int iMu, vector<double> *mu_pt,
                                     vector<double> *mu_eta,
                                     vector<double> *mu_phi,
                                     double mu_M);

    virtual void SetJetTLV(int iJet, vector<double> *jet_pt,
                                     vector<double> *jet_eta,
                                     vector<double> *jet_phi,
                                     vector<double> *jet_E);


    virtual void OverlapRemoval(vector<OR_Object> *el_obj,
                                vector<OR_Object> *mu_obj,
                                vector<OR_Object> *jet_obj,
                                double dRejet = 0.2,
                                double dRjetmu = 0.4,
                                double dRjete = 0.4,
                                double dRemu = 0.1,
                                double dRee = 0.1);

   ClassDef(AnaNtupV04Selector,0);
};

#endif

#ifdef AnaNtupV04Selector_cxx
void AnaNtupV04Selector::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

    fNumberOfEvents = 0;
    fpassGRL = 0;
    fDetError = 0;
    fAtLeastTwoLeptons = 0;
    fEqualTwoLeptons = 0;
    fEqualTwoSignalLeptons = 0;
    // El-El channel
    fChannelSelection_elel = 0;
    fTrigger_elel = 0;
    fMl1l2_elel = 0;
    fAtLeastOneBJet_elel = 0;
    fAtLeastFourJets_elel = 0;
    fSameSign_elel = 0;
    fMET_elel = 0;
    // El-Mu channel
    fChannelSelection_elmu = 0;
    fTrigger_elmu = 0;
    fMl1l2_elmu = 0;
    fAtLeastOneBJet_elmu = 0;
    fAtLeastFourJets_elmu = 0;
    fSameSign_elmu = 0;
    fMET_elmu = 0;
    // Mu-Mu channel
    fChannelSelection_mumu = 0;
    fTrigger_mumu = 0;
    fMl1l2_mumu = 0;
    fAtLeastOneBJet_mumu = 0;
    fAtLeastFourJets_mumu = 0;
    fSameSign_mumu = 0;
    fMET_mumu = 0;


   // Set object pointer
   Mu_eta = 0;
   Mu_phi = 0;
   Mu_pT = 0;
   Mu_SFw = 0;
   Mu_charge = 0;
   Mu_d0pvtx = 0;
   Mu_d0pvtxerr = 0;
   Mu_sigd0 = 0;
   Mu_z0pvtx = 0;
   Mu_isBad = 0;
   Mu_isSig = 0;
   Mu_isCosmic = 0;
   Mu_type = 0;
   Mu_origin = 0;
   Mu_ptcone20 = 0;
   Mu_ptcone30 = 0;
   Mu_ptcone40 = 0;
   Mu_ptvarcone20 = 0;
   Mu_ptvarcone30 = 0;
   Mu_ptvarcone40 = 0;
   Mu_topoetcone20 = 0;
   Mu_topoetcone30 = 0;
   Mu_topoetcone40 = 0;
   El_eta = 0;
   El_phi = 0;
   El_pT = 0;
   El_E = 0;
   El_charge = 0;
   El_sigd0 = 0;
   El_z0pvtx = 0;
   El_d0pvtx = 0;
   El_d0pvtxerr = 0;
   El_SFw = 0;
   El_SFwMed = 0;
   El_isSig = 0;
   El_isSigMed = 0;
   El_type = 0;
   El_origin = 0;
   El_ptcone20 = 0;
   El_ptcone30 = 0;
   El_ptcone40 = 0;
   El_ptvarcone20 = 0;
   El_ptvarcone30 = 0;
   El_ptvarcone40 = 0;
   El_topoetcone20 = 0;
   El_topoetcone30 = 0;
   El_topoetcone40 = 0;
   Jet_eta = 0;
   Jet_phi = 0;
   Jet_pT = 0;
   Jet_E = 0;
   Jet_quality = 0;
   Jet_JVF = 0;
   Jet_MV1 = 0;
   Jet_SFw = 0;
   Jet_JetLabel = 0;
   Jet_nTrk = 0;
   TruthV_eta = 0;
   TruthV_phi = 0;
   TruthV_pT = 0;
   TruthV_m = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("EventNumber", &EventNumber, &b_EventNumber);
   fChain->SetBranchAddress("ChannelNumber", &ChannelNumber, &b_ChannelNumber);
   fChain->SetBranchAddress("AvgMu", &AvgMu, &b_AvgMu);
   fChain->SetBranchAddress("EventWeight", &EventWeight, &b_EventWeight);
   fChain->SetBranchAddress("bcid", &bcid, &b_bcid);
   fChain->SetBranchAddress("LB", &LB, &b_LB);
   fChain->SetBranchAddress("passGRL", &passGRL, &b_passGRL);
   fChain->SetBranchAddress("RunNb", &RunNb, &b_RunNb);
   fChain->SetBranchAddress("DetError", &DetError, &b_DetError);
   fChain->SetBranchAddress("NMu", &NMu, &b_NMu);
   fChain->SetBranchAddress("Mu_eta", &Mu_eta, &b_Mu_eta);
   fChain->SetBranchAddress("Mu_phi", &Mu_phi, &b_Mu_phi);
   fChain->SetBranchAddress("Mu_pT", &Mu_pT, &b_Mu_pT);
   fChain->SetBranchAddress("Mu_SFw", &Mu_SFw, &b_Mu_SFw);
   fChain->SetBranchAddress("Mu_charge", &Mu_charge, &b_Mu_charge);
   fChain->SetBranchAddress("Mu_d0pvtx", &Mu_d0pvtx, &b_Mu_d0pvtx);
   fChain->SetBranchAddress("Mu_d0pvtxerr", &Mu_d0pvtxerr, &b_Mu_d0pvtxerr);
   fChain->SetBranchAddress("Mu_sigd0", &Mu_sigd0, &b_Mu_sigd0);
   fChain->SetBranchAddress("Mu_z0pvtx", &Mu_z0pvtx, &b_Mu_z0pvtx);
   fChain->SetBranchAddress("Mu_isBad", &Mu_isBad, &b_Mu_isBad);
   fChain->SetBranchAddress("Mu_isSig", &Mu_isSig, &b_Mu_isSig);
   fChain->SetBranchAddress("Mu_isCosmic", &Mu_isCosmic, &b_Mu_isCosmic);
   fChain->SetBranchAddress("Mu_type", &Mu_type, &b_Mu_type);
   fChain->SetBranchAddress("Mu_origin", &Mu_origin, &b_Mu_origin);
   fChain->SetBranchAddress("Mu_ptcone20", &Mu_ptcone20, &b_Mu_ptcone20);
   fChain->SetBranchAddress("Mu_ptcone30", &Mu_ptcone30, &b_Mu_ptcone30);
   fChain->SetBranchAddress("Mu_ptcone40", &Mu_ptcone40, &b_Mu_ptcone40);
   fChain->SetBranchAddress("Mu_ptvarcone20", &Mu_ptvarcone20, &b_Mu_ptvarcone20);
   fChain->SetBranchAddress("Mu_ptvarcone30", &Mu_ptvarcone30, &b_Mu_ptvarcone30);
   fChain->SetBranchAddress("Mu_ptvarcone40", &Mu_ptvarcone40, &b_Mu_ptvarcone40);
   fChain->SetBranchAddress("Mu_topoetcone20", &Mu_topoetcone20, &b_Mu_topoetcone20);
   fChain->SetBranchAddress("Mu_topoetcone30", &Mu_topoetcone30, &b_Mu_topoetcone30);
   fChain->SetBranchAddress("Mu_topoetcone40", &Mu_topoetcone40, &b_Mu_topoetcone40);
   fChain->SetBranchAddress("NEl", &NEl, &b_NEl);
   fChain->SetBranchAddress("El_eta", &El_eta, &b_El_eta);
   fChain->SetBranchAddress("El_phi", &El_phi, &b_El_phi);
   fChain->SetBranchAddress("El_pT", &El_pT, &b_El_pT);
   fChain->SetBranchAddress("El_E", &El_E, &b_El_E);
   fChain->SetBranchAddress("El_charge", &El_charge, &b_El_charge);
   fChain->SetBranchAddress("El_sigd0", &El_sigd0, &b_El_sigd0);
   fChain->SetBranchAddress("El_z0pvtx", &El_z0pvtx, &b_El_z0pvtx);
   fChain->SetBranchAddress("El_d0pvtx", &El_d0pvtx, &b_El_d0pvtx);
   fChain->SetBranchAddress("El_d0pvtxerr", &El_d0pvtxerr, &b_El_d0pvtxerr);
   fChain->SetBranchAddress("El_SFw", &El_SFw, &b_El_SFw);
   fChain->SetBranchAddress("El_SFwMed", &El_SFwMed, &b_El_SFwMed);
   fChain->SetBranchAddress("El_isSig", &El_isSig, &b_El_isSig);
   fChain->SetBranchAddress("El_isSigMed", &El_isSigMed, &b_El_isSigMed);
   fChain->SetBranchAddress("El_type", &El_type, &b_El_type);
   fChain->SetBranchAddress("El_origin", &El_origin, &b_El_origin);
   fChain->SetBranchAddress("El_ptcone20", &El_ptcone20, &b_El_ptcone20);
   fChain->SetBranchAddress("El_ptcone30", &El_ptcone30, &b_El_ptcone30);
   fChain->SetBranchAddress("El_ptcone40", &El_ptcone40, &b_El_ptcone40);
   fChain->SetBranchAddress("El_ptvarcone20", &El_ptvarcone20, &b_El_ptvarcone20);
   fChain->SetBranchAddress("El_ptvarcone30", &El_ptvarcone30, &b_El_ptvarcone30);
   fChain->SetBranchAddress("El_ptvarcone40", &El_ptvarcone40, &b_El_ptvarcone40);
   fChain->SetBranchAddress("El_topoetcone20", &El_topoetcone20, &b_El_topoetcone20);
   fChain->SetBranchAddress("El_topoetcone30", &El_topoetcone30, &b_El_topoetcone30);
   fChain->SetBranchAddress("El_topoetcone40", &El_topoetcone40, &b_El_topoetcone40);
   fChain->SetBranchAddress("NJet", &NJet, &b_NJet);
   fChain->SetBranchAddress("Jet_eta", &Jet_eta, &b_Jet_eta);
   fChain->SetBranchAddress("Jet_phi", &Jet_phi, &b_Jet_phi);
   fChain->SetBranchAddress("Jet_pT", &Jet_pT, &b_Jet_pT);
   fChain->SetBranchAddress("Jet_E", &Jet_E, &b_Jet_E);
   fChain->SetBranchAddress("Jet_quality", &Jet_quality, &b_Jet_quality);
   fChain->SetBranchAddress("Jet_JVF", &Jet_JVF, &b_Jet_JVF);
   fChain->SetBranchAddress("Jet_MV1", &Jet_MV1, &b_Jet_MV1);
   fChain->SetBranchAddress("Jet_SFw", &Jet_SFw, &b_Jet_SFw);
   fChain->SetBranchAddress("Jet_JetLabel", &Jet_JetLabel, &b_Jet_JetLabel);
   fChain->SetBranchAddress("Jet_nTrk", &Jet_nTrk, &b_Jet_nTrk);
   fChain->SetBranchAddress("NTruthV", &NTruthV, &b_NTruthV);
   fChain->SetBranchAddress("TruthV_eta", &TruthV_eta, &b_TruthV_eta);
   fChain->SetBranchAddress("TruthV_phi", &TruthV_phi, &b_TruthV_phi);
   fChain->SetBranchAddress("TruthV_pT", &TruthV_pT, &b_TruthV_pT);
   fChain->SetBranchAddress("TruthV_m", &TruthV_m, &b_TruthV_m);
   fChain->SetBranchAddress("Etmiss_Etx", &Etmiss_Etx, &b_Etmiss_Etx);
   fChain->SetBranchAddress("Etmiss_Ety", &Etmiss_Ety, &b_Etmiss_Ety);
   fChain->SetBranchAddress("Etmiss_Et", &Etmiss_Et, &b_Etmiss_Et);
   fChain->SetBranchAddress("SUSY_Spart_pdgId1", &SUSY_Spart_pdgId1, &b_SUSY_Spart_pdgId1);
   fChain->SetBranchAddress("SUSY_Spart_pdgId2", &SUSY_Spart_pdgId2, &b_SUSY_Spart_pdgId2);
   fChain->SetBranchAddress("PV_z", &PV_z, &b_PV_z);
}

Bool_t AnaNtupV04Selector::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

#endif // #ifdef AnaNtupV04Selector_cxx
