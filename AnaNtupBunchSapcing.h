//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Tue May 12 15:19:05 2015 by ROOT version 5.34/25
// from TTree AnaNtup/AnaNtup
// found on file: user.jpoveda.5399374._000001.output.root
//////////////////////////////////////////////////////////

#ifndef AnaNtupBunchSapcing_h
#define AnaNtupBunchSapcing_h

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

#define Mu_M 105.6583715
/*
struct OR_Object {
    TLorentzVector tlv;
    bool baseline;
    bool passOR;
    int  charge;
    int  flavor;
    double pT;
    double eta;
    double phi;
};
*/
class Particle;
class Lepton;
class Electron;
class Muon;
class Jet;

// functions declarations
template<typename T> bool sort_descending_Pt(T obj1, T obj2);
template<> bool sort_descending_Pt(TLorentzVector tlv1, TLorentzVector tlv2); // explicit specialization
double calculate_Ht(vector<Lepton> signal_leptons, vector<Jet> signal_jets);
double calculate_Meff(double Ht, double Etmiss);

class AnaNtupBunchSapcing : public TSelector {
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
/*
    vector<TLorentzVector> m_el;
    vector<TLorentzVector> m_mu;
    vector<TLorentzVector> m_jet;
    vector<TLorentzVector> m_lep;

    vector<OR_Object> m_el_passOR;
    vector<OR_Object> m_mu_passOR;
    vector<OR_Object> m_jet_passOR;
    vector<OR_Object> m_lep_passOR;
*/
    vector<Lepton>   vec_lept;
    vector<Electron> vec_elec;
    vector<Muon>     vec_muon;
    vector<Jet>      vec_jets;
    vector<Particle> vec_truthv;
    
    TH1* hCutFlows;
    
    TH1* hCut1_Njet;
    TH1* hCut1_Njet_OR;
    TH1* hCut1_Jet_Pt;
    TH1* hCut1_Jet_Eta;
    TH1* hCut1_Jet_Phi;
    TH1* hCut1_Jet_Pt1;
    TH1* hCut1_Jet_Pt2;
    TH1* hCut1_Jet_Pt3;
    TH1* hCut1_Jet_Pt4;
    
    TH1* hCut1_Nelec;
    TH1* hCut1_Nelec_OR;
    TH1* hCut1_Elec_Pt;
    TH1* hCut1_Elec_Eta;
    TH1* hCut1_Elec_Phi;
    TH1* hCut1_Elec_Pt1;
    TH1* hCut1_Elec_Pt2;
    
    TH1* hCut1_Nmuon;
    TH1* hCut1_Nmuon_OR;
    TH1* hCut1_Muon_Pt;
    TH1* hCut1_Muon_Eta;
    TH1* hCut1_Muon_Phi;
    TH1* hCut1_Muon_Pt1;
    TH1* hCut1_Muon_Pt2;
    
    TH1* hCut1_Nlep;
    TH1* hCut1_Nlep_OR;
    TH1* hCut1_lep_Pt;
    TH1* hCut1_lep_Pt1;
    TH1* hCut1_lep_Pt2;
    
    TH1* hCut1_MET;
    TH1* hCut1_Meff;
    TH1* hCut1_Nbjet;
    TH1* hCut1_Nbjet_OR;
 
    TH1* hCut5_Njet;
    TH1* hCut5_Jet_Pt;
    TH1* hCut5_Jet_Eta;
    TH1* hCut5_Jet_Phi;
    TH1* hCut5_Jet_Pt1;
    TH1* hCut5_Jet_Pt2;
    TH1* hCut5_Jet_Pt3;
    TH1* hCut5_Jet_Pt4;
    
    TH1* hCut5_Nelec;
    TH1* hCut5_Elec_Pt;
    TH1* hCut5_Elec_Eta;
    TH1* hCut5_Elec_Phi;
    TH1* hCut5_Elec_Pt1;
    TH1* hCut5_Elec_Pt2;
    
    TH1* hCut5_Nmuon;
    TH1* hCut5_Muon_Pt;
    TH1* hCut5_Muon_Eta;
    TH1* hCut5_Muon_Phi;
    TH1* hCut5_Muon_Pt1;
    TH1* hCut5_Muon_Pt2;
    
    TH1* hCut5_Nlep;
    TH1* hCut5_lep_Pt;
    TH1* hCut5_lep_Pt1;
    TH1* hCut5_lep_Pt2;
    
    TH1* hCut5_MET;
    TH1* hCut5_Meff;
    TH1* hCut5_Nbjet;
    
    
    
    
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
   vector<double>  *Jet_deltaR;
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
   TBranch        *b_Jet_deltaR;   //!
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

   AnaNtupBunchSapcing(TTree * /*tree*/ =0) : fChain(0) { }
   virtual ~AnaNtupBunchSapcing() { }
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
/*
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
*/

    virtual void FillElec(Int_t iEl,
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
                          vector<double>  *el_topoetcone40);
    
    virtual void FillMuon(Int_t iMu,
                          int flavor,
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
                          vector<double>  *mu_topoetcone40);
    
    virtual void FillJets(Int_t iJet,
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
                          vector<double>  *jet_deltaR);
    
    virtual void FillTruthV(Int_t iTruthV,
                            vector<double>  *TruthV_eta,
                            vector<double>  *TruthV_phi,
                            vector<double>  *TruthV_pT,
                            vector<double>  *TruthV_m);
/*
    virtual void OverlapRemoval(vector<OR_Object> *el_obj,
                                vector<OR_Object> *mu_obj,
                                vector<OR_Object> *jet_obj,
                                double dRejet = 0.2,
                                double dRjetmu = 0.4,
                                double dRjete = 0.4,
                                double dRemu = 0.1,
                                double dRee = 0.1);
*/
    virtual void OverlapRemoval(vector<Electron> *el_obj,
                                vector<Muon>     *mu_obj,
                                vector<Jet>      *jet_obj,
                                double dRejet = 0.2,
                                double dRjetmu = 0.4,
                                double dRjete = 0.4,
                                double dRemu = 0.1,
                                double dRee = 0.1);

   ClassDef(AnaNtupBunchSapcing,0);
};

#endif

#ifdef AnaNtupBunchSapcing_cxx
void AnaNtupBunchSapcing::Init(TTree *tree)
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
   Jet_deltaR = 0;
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
   fChain->SetBranchAddress("Jet_deltaR", &Jet_deltaR, &b_Jet_deltaR);
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

Bool_t AnaNtupBunchSapcing::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}



// class definitions
class Particle {
    TLorentzVector tlv;
    bool    baseline;
    bool    passOR;
    double  pT;
    double  eta;
    double  phi;
    double  E;
    double  M;

public:
    Particle() : baseline(0), passOR(0), pT(0), eta(0), phi(0), E(0), M(0) {}
    ~Particle() {}
    // get methods
    TLorentzVector get_TLV(){ return tlv; }
    bool    get_baseline()  { return baseline; }
    bool    get_passOR()    { return passOR; }
    double  get_pt()        { return pT; }
    double  get_eta()       { return eta; }
    double  get_phi()       { return phi; }
    double  get_E()         { return E; }
    double  get_M()         { return M; }
    // set methods
    virtual void set_TLV_E(double Pt, double Eta, double Phi, double Energy) { tlv.SetPtEtaPhiE(Pt, Eta, Phi, Energy); }
    virtual void set_TLV_M(double Pt, double Eta, double Phi, double Mass) { tlv.SetPtEtaPhiM(Pt, Eta, Phi, Mass); }
    void    set_baseline(bool b){ baseline = b; }
    void    set_passOR(bool b)  { passOR = b; }
    void    set_pt(double d)    { pT = d; }
    void    set_eta(double d)   { eta = d; }
    void    set_phi(double d)   { phi = d; }
    void    set_E(double d)     { E = d; }
    void    set_M(double d)     { M = d; }
};

class Lepton : public Particle {
    int     flavor;
    bool    isSignal;
    
    double  SFw;
    int     charge;
    double  z0pvtx;
    double  d0pvtx;
    double  d0pvtxerr;
    double  sigd0;
    int     isSig;
    int     type;
    int     origin;
    double  ptcone20;
    double  ptcone30;
    double  ptcone40;
    double  ptvarcone20;
    double  ptvarcone30;
    double  ptvarcone40;
    double  topoetcone20;
    double  topoetcone30;
    double  topoetcone40;
    
public:
    Lepton() : flavor(0), isSignal(0),
               SFw(0), charge(0), z0pvtx(0), d0pvtx(0), d0pvtxerr(0),
               sigd0(0), isSig(0), type(0), origin(0),
               ptcone20(0), ptcone30(0), ptcone40(0),
               ptvarcone20(0), ptvarcone30(0), ptvarcone40(0),
               topoetcone20(0), topoetcone30(0), topoetcone40(0) {}
    ~Lepton() {}
    // get methods
    int     get_flavor()    { return flavor; }
    bool    get_isSignal()  { return isSignal; }
    double  get_SFw()       { return SFw; }
    int     get_charge()    { return charge; }
    double  get_z0pvtx()    { return z0pvtx; }
    double  get_d0pvtx()    { return d0pvtx; }
    double  get_d0pvtxerr() { return d0pvtxerr; }
    double  get_sigd0()     { return sigd0; }
    int     get_isSig()     { return isSig; }
    int     get_type()      { return type; }
    int     get_origin()    { return origin; }
    double  get_ptcone20()  { return ptcone20; }
    double  get_ptcone30()  { return ptcone30; }
    double  get_ptcone40()  { return ptcone40; }
    double  get_ptvarcone20() { return ptvarcone20; }
    double  get_ptvarcone30() { return ptvarcone30; }
    double  get_ptvarcone40() { return ptvarcone40; }
    double  get_topoetcone20(){ return topoetcone20; }
    double  get_topoetcone30(){ return topoetcone30; }
    double  get_topoetcone40(){ return topoetcone40; }
    // set methods
    void    set_flavor(int i)   { flavor = i; }
    void    set_isSignal(bool b){ isSignal = b; }
    void    set_SFw(double d)   { SFw = d; }
    void    set_charge(int i)   { charge = i; }
    void    set_z0pvtx(double d){ z0pvtx = d; }
    void    set_d0pvtx(double d){ d0pvtx = d; }
    void    set_d0pvtxerr(double d) { d0pvtxerr = d; }
    void    set_sigd0(double d) { sigd0 = d; }
    void    set_isSig(int i)    { isSig = i; }
    void    set_type(int i)     { type = i; }
    void    set_origin(int i)   { origin = i; }
    void    set_ptcone20(double d)      { ptcone20 = d; }
    void    set_ptcone30(double d)      { ptcone30 = d; }
    void    set_ptcone40(double d)      { ptcone40 = d; }
    void    set_ptvarcone20(double d)   { ptvarcone20 = d; }
    void    set_ptvarcone30(double d)   { ptvarcone30 = d; }
    void    set_ptvarcone40(double d)   { ptvarcone40 = d; }
    void    set_topoetcone20(double d)  { topoetcone20 = d; }
    void    set_topoetcone30(double d)  { topoetcone30 = d; }
    void    set_topoetcone40(double d)  { topoetcone40 = d; }

};


class Electron : public Lepton {    
    double  SFwMed;
    int     isSigMed;

public:
    Electron() : SFwMed(0), isSigMed(0) {}
    ~Electron() {}
    // get methods
    double  get_SFwMed()   { return SFwMed; }
    int     get_isSigMed() { return isSigMed; }
    // set methods
    void    set_SFwMed(double d) { SFwMed = d; }
    void    set_isSigMed(int i)  { isSigMed = i; }
};

class Muon : public Lepton {
    int     isBad;
    int     isCosmic;
    
public:
    Muon() : isBad(0), isCosmic(0) {}
    ~Muon() {}
    // get methods
    int     get_isBad()  { return isBad; }
    int     get_isCosmic() { return isCosmic; }
    // set methods
    void    set_isBad(int i)   { isBad = i; }
    void    set_isCosmic(int i){ isCosmic = i; }
};

class Jet : public Particle {
    bool    isBjet;
    double  quality;
    double  JVF;
    double  MV1;
    double  SFw;
    int     JetLabel;
    int     nTrk;
    double  deltaR;
    
public:
    Jet() : isBjet(0), quality(0), JVF(0), MV1(0), SFw(0), JetLabel(0), nTrk(0), deltaR(0) {}
    ~Jet() {}
    // get methods
    bool    get_isBjet()  { return isBjet; }
    double  get_quality() { return quality; }
    double  get_MV1() { return MV1; }
    double  get_JVF() { return JVF; }
    double  get_SFw() { return SFw; }
    int     get_JetLabel(){ return JetLabel; }
    int     get_nTrk()    { return nTrk; }
    int     get_deltaR()  { return deltaR; }
    // set methods
    void    set_isBjet(bool b) { isBjet = b; }
    void    set_quality(double d){ quality = d; }
    void    set_JVF(double d) { JVF = d; }
    void    set_MV1(double d) { MV1 = d; }
    void    set_SFw(double d) { SFw = d; }
    void    set_JetLabel(int i) { JetLabel = i; }
    void    set_nTrk(int i)   { nTrk = i; }
    void    set_deltaR(double d) { deltaR = d; }
};


/*
class Muon : public OR_Object {
    double  Mu_eta;
    double  Mu_phi;
    double  Mu_pT;
    double  Mu_SFw;
    int     Mu_charge;
    double  Mu_d0pvtx;
    double  Mu_d0pvtxerr;
    double  Mu_sigd0;
    double  Mu_z0pvtx;
    int     Mu_isBad;
    int     Mu_isSig;
    int     Mu_isCosmic;
    int     Mu_type;
    int     Mu_origin;
    double  Mu_ptcone20;
    double  Mu_ptcone30;
    double  Mu_ptcone40;
    double  Mu_ptvarcone20;
    double  Mu_ptvarcone30;
    double  Mu_ptvarcone40;
    double  Mu_topoetcone20;
    double  Mu_topoetcone30;
    double  Mu_topoetcone40;
    
    TLorentzVector tlv;
    
public:
    Muon() {
        Mu_eta = 0.;
        Mu_phi = 0.;
        Mu_pT = 0.;
        Mu_SFw = 0.;
        Mu_charge = 0;
        Mu_d0pvtx = 0.;
        Mu_d0pvtxerr = 0.;
        Mu_sigd0 = 0.;
        Mu_z0pvtx = 0.;
        Mu_isBad = 0;
        Mu_isSig = 0;
        Mu_isCosmic = 0;
        Mu_type = 0;
        Mu_origin = 0;
        Mu_ptcone20 = 0.;
        Mu_ptcone30 = 0.;
        Mu_ptcone40 = 0.;
        Mu_ptvarcone20 = 0.;
        Mu_ptvarcone30 = 0.;
        Mu_ptvarcone40 = 0.;
        Mu_topoetcone20 = 0.;
        Mu_topoetcone30 = 0.;
        Mu_topoetcone40 = 0.;
    }
    ~Muon() {}
    void set_Mu_eta(double eta) { Mu_eta = eta; }
    void set_Mu_phi(double phi) { Mu_phi = phi; }
    void set_Mu_pT(double pT) { Mu_pT = pT; }
    void set_Mu_SFw(double SFw) { Mu_SFw = SFw; }
    void set_Mu_charge(int charge) { Mu_charge = charge; }
    void set_Mu_d0pvtx(double d0pvtx) { Mu_d0pvtx = d0pvtx; }
    void set_Mu_d0pvtxerr(double d0pvtxerr) { Mu_d0pvtxerr = d0pvtxerr; }
    void set_Mu_sigd0(double sigd0) { Mu_sigd0 = sigd0; }
    void set_Mu_z0pvtx(double z0pvtx) { Mu_z0pvtx = z0pvtx; }
    void set_Mu_isBad(int isBad) { Mu_isBad = isBad; }
    void set_Mu_isSig(int isSig) { Mu_isSig = isSig; }
    void set_Mu_isCosmic(int isCosmic) { Mu_isCosmic = isCosmic; }
    void set_Mu_type(int type) { Mu_type = type; }
    void set_Mu_origin(int origin) { Mu_origin = origin; }
    void set_Mu_ptcone20(double ptcone20) { Mu_ptcone20 = ptcone20; }
    void set_Mu_ptcone30(double ptcone30) { Mu_ptcone30 = ptcone30; }
    void set_Mu_ptcone40(double ptcone40) { Mu_ptcone40 = ptcone40; }
    void set_Mu_ptvarcone20(double ptvarcone20) { Mu_ptvarcone20 = ptvarcone20; }
    void set_Mu_ptvarcone30(double ptvarcone30) { Mu_ptvarcone30 = ptvarcone30; }
    void set_Mu_ptvarcone40(double ptvarcone40) { Mu_ptvarcone40 = ptvarcone40; }
    void set_Mu_topoetcone20(double topoetcone20) { Mu_topoetcone20 = topoetcone20; }
    void set_Mu_topoetcone30(double topoetcone30) { Mu_topoetcone30 = topoetcone30; }
    void set_Mu_topoetcone40(double topoetcone40) { Mu_topoetcone40 = topoetcone40; }
    
    void set_MuonTLV() { tlv.SetPtEtaPhiM( Mu_pT, Mu_eta, Mu_phi, Mu_M ); }
    
    double  get_Mu_eta() { return Mu_eta; }
    double  get_Mu_phi() { return Mu_phi; }
    double  get_Mu_pT() { return Mu_pT; }
    double  get_Mu_SFw() { return Mu_SFw; }
    int     get_Mu_charge() { return Mu_charge; }
    double  get_Mu_d0pvtx() { return Mu_d0pvtx; }
    double  get_Mu_d0pvtxerr() { return Mu_d0pvtxerr; }
    double  get_Mu_sigd0() { return Mu_sigd0; }
    double  get_Mu_z0pvtx() { return Mu_z0pvtx; }
    int     get_Mu_isBad() { return Mu_isBad; }
    int     get_Mu_isSig() { return Mu_isSig; }
    int     get_Mu_isCosmic() { return Mu_isCosmic; }
    int     get_Mu_type() { return Mu_type; }
    int     get_Mu_origin() { return Mu_origin; }
    double  get_Mu_ptcone20() { return Mu_ptcone20; }
    double  get_Mu_ptcone30() { return Mu_ptcone30; }
    double  get_Mu_ptcone40() { return Mu_ptcone40; }
    double  get_Mu_ptvarcone20() { return Mu_ptvarcone20; }
    double  get_Mu_ptvarcone30() { return Mu_ptvarcone30; }
    double  get_Mu_ptvarcone40() { return Mu_ptvarcone40; }
    double  get_Mu_topoetcone20() { return Mu_topoetcone20; }
    double  get_Mu_topoetcone30() { return Mu_topoetcone30; }
    double  get_Mu_topoetcone40() { return Mu_topoetcone40; }

    TLorentzVector get_MuonTLV() { return tlv; }
};

class Electron : public OR_Object {
    double  El_eta;
    double  El_phi;
    double  El_pT;
    double  El_E;
    int     El_charge;
    double  El_sigd0;
    double  El_z0pvtx;
    double  El_d0pvtx;
    double  El_d0pvtxerr;
    double  El_SFw;
    double  El_SFwMed;
    int     El_isSig;
    int     El_isSigMed;
    int     El_type;
    int     El_origin;
    double  El_ptcone20;
    double  El_ptcone30;
    double  El_ptcone40;
    double  El_ptvarcone20;
    double  El_ptvarcone30;
    double  El_ptvarcone40;
    double  El_topoetcone20;
    double  El_topoetcone30;
    double  El_topoetcone40;
    
    TLorentzVector tlv;
    
public:
    Electron() {
        double  El_eta = 0.;
        double  El_phi = 0.;
        double  El_pT = 0.;
        double  El_E = 0.;
        int     El_charge = 0;
        double  El_sigd0 = 0.;
        double  El_z0pvtx = 0.;
        double  El_d0pvtx = 0.;
        double  El_d0pvtxerr = 0.;
        double  El_SFw = 0.;
        double  El_SFwMed = 0.;
        int     El_isSig = 0;
        int     El_isSigMed = 0;
        int     El_type = 0;
        int     El_origin = 0;
        double  El_ptcone20 = 0.;
        double  El_ptcone30 = 0.;
        double  El_ptcone40 = 0.;
        double  El_ptvarcone20 = 0.;
        double  El_ptvarcone30 = 0.;
        double  El_ptvarcone40 = 0.;
        double  El_topoetcone20 = 0.;
        double  El_topoetcone30 = 0.;
        double  El_topoetcone40 = 0.;
    }
    ~Electron() {}
    void set_El_eta(double eta) { El_eta = eta; }
    void set_El_phi(double phi) { El_phi = phi; }
    void set_El_pT(double pT) { El_pT = pT; }
    void set_El_E(double E) { El_E = E; }
    void set_El_charge(int charge) { El_charge = charge; }
    void set_El_sigd0(double sigd0) { El_sigd0 = sigd0; }
    void set_El_z0pvtx(double z0pvtx) { El_z0pvtx = z0pvtx; }
    void set_El_d0pvtx(double d0pvtx) { El_d0pvtx = d0pvtx; }
    void set_El_d0pvtxerr(double d0pvtxerr) { El_d0pvtxerr = d0pvtxerr; }
    void set_El_SFw(double SFw) { El_SFw = SFw; }
    void set_El_SFwMed(double SFwMed) {El_SFwMed = SFwMed; }
    void set_El_isSig(int isSig) { El_isSig = isSig; }
    void set_El_isSigMed(int isSigMed) { El_isSigMed = isSigMed; }
    void set_El_type(int type) { El_type = type; }
    void set_El_origin(int origin) {El_origin = origin; }
    void set_El_ptcone20(double ptcone20) { El_ptcone20 = ptcone20; }
    void set_El_ptcone30(double ptcone30) { El_ptcone30 = ptcone30; }
    void set_El_ptcone40(double ptcone40) { El_ptcone40 = ptcone40; }
    void set_El_ptvarcone20(double ptvarcone20) { El_ptvarcone20 = ptvarcone20; }
    void set_El_ptvarcone30(double ptvarcone30) { El_ptvarcone30 = ptvarcone30; }
    void set_El_ptvarcone40(double ptvarcone40) { El_ptvarcone40 = ptvarcone40; }
    void set_El_topoetcone20(double topoetcone20) { El_topoetcone20 = topoetcone20; }
    void set_El_topoetcone30(double topoetcone30) { El_topoetcone30 = topoetcone30; }
    void set_El_topoetcone40(double topoetcone40) { El_topoetcone40 = topoetcone40; }
    
    void set_ElecTLV() { tlv.SetPtEtaPhiE( El_pT, El_eta, El_phi, El_E ); }
    
    double get_El_eta() { return El_eta; }
    double get_El_phi() { return El_phi; }
    double get_El_pT() { return El_pT; }
    double get_El_E() { return El_E; }
    int    get_El_charge() { return El_charge; }
    double get_El_sigd0() { return El_sigd0; }
    double get_El_z0pvtx() { return El_z0pvtx; }
    double get_El_d0pvtx() { return El_d0pvtx; }
    double get_El_d0pvtxerr() { return El_d0pvtxerr; }
    double get_El_SFw() { return El_SFw; }
    double get_El_SFwMed() { return El_SFwMed; }
    int    get_El_isSig() { return El_isSig; }
    int    get_El_isSigMed() { return El_isSigMed; }
    int    get_El_type() { return El_type; }
    int    get_El_origin() { return El_origin; }
    double get_El_ptcone20() { return El_ptcone20; }
    double get_El_ptcone30() { return El_ptcone30; }
    double get_El_ptcone40() { return El_ptcone40; }
    double get_El_ptvarcone20() { return El_ptvarcone20; }
    double get_El_ptvarcone30() { return El_ptvarcone30; }
    double get_El_ptvarcone40() { return El_ptvarcone40; }
    double get_El_topoetcone20() { return El_topoetcone20; }
    double get_El_topoetcone30() { return El_topoetcone30; }
    double get_El_topoetcone40() { return El_topoetcone40; }
    
    TLorentzVector get_ElecTLV() { return tlv; }
};

class Jets : public OR_Object {
    double  Jet_eta;
    double  Jet_phi;
    double  Jet_pT;
    double  Jet_E;
    double  Jet_quality;
    double  Jet_JVF;
    double  Jet_MV1;
    double  Jet_SFw;
    int     Jet_JetLabel;
    int     Jet_nTrk;
    double  Jet_deltaR;
    
    TLorentzVector tlv;
    
public:
    Jets() {
        Jet_eta = 0.;
        Jet_phi = 0.;
        Jet_pT = 0.;
        Jet_E = 0.;
        Jet_quality = 0.;
        Jet_JVF = 0.;
        Jet_MV1 = 0.;
        Jet_SFw = 0.;
        Jet_JetLabel = 0;
        Jet_nTrk = 0;
        Jet_deltaR = 0.;
    }
    ~Jets() {}
    void set_Jet_eta(double eta) { Jet_eta = eta; }
    void set_Jet_phi(double phi) { Jet_phi = phi; }
    void set_Jet_pT(double pT) { Jet_pT = pT; }
    void set_Jet_E(double E) { Jet_E = E; }
    void set_jet_quality(double quality) { Jet_quality = quality; }
    void set_Jet_JVF(double JVF) { Jet_JVF = JVF; }
    void set_Jet_MV1(double MV1) { Jet_MV1 = MV1; }
    void set_Jet_SFw(double SFw) { Jet_SFw = SFw; }
    void set_Jet_JetLabel(int JetLabel) { Jet_JetLabel = JetLabel; }
    void set_Jet_nTrk(int nTrk) { Jet_nTrk = nTrk; }
    void set_Jet_deltaR(double deltaR) { Jet_deltaR = deltaR; }
    
    void set_JetTLV() { tlv.SetPtEtaPhiE( Jet_pT, Jet_eta, Jet_phi, Jet_E ); }
    
    double  get_Jet_eta() { return Jet_eta; }
    double  get_Jet_phi() { return Jet_phi; }
    double  get_Jet_pT() { return Jet_pT; }
    double  get_Jet_E() { return Jet_E; }
    double  get_Jet_quality() { return Jet_quality; }
    double  get_Jet_MV1() { return Jet_MV1; }
    double  get_Jet_JVF() { return Jet_JVF; }
    double  get_Jet_SFw() { return Jet_SFw; }
    int     get_Jet_JetLabel() { return Jet_JetLabel; }
    int     get_Jet_nTrk() { return Jet_nTrk; }
    int     get_Jet_deltaR() { return Jet_deltaR; }
    
    TLorentzVector get_JetTLV() { return tlv; }
};

class TruthV
{
    double  TruthV_eta;
    double  TruthV_phi;
    double  TruthV_pT;
    double  TruthV_m;

    TLorentzVector tlv;
    
public:
    TruthV() {
        TruthV_eta = 0;
        TruthV_phi = 0;
        TruthV_pT = 0;
        TruthV_m = 0;
    }
    ~TruthV() {}
    void set_TruthV_eta(double eta) { TruthV_eta = eta; }
    void set_TruthV_phi(double phi) { TruthV_phi = phi; }
    void set_TruthV_pT(double pT) { TruthV_pT = pT; }
    void set_TruthV_m(double m) { TruthV_m = m; }
    
    void set_TruthV_TLV() { tlv.SetPtEtaPhiM( TruthV_pT, TruthV_eta, TruthV_phi, TruthV_m); }
    
    double get_TruthV_eta() { return TruthV_eta; }
    double get_TruthV_phi() { return TruthV_phi; }
    double get_TruthV_pT() { return TruthV_pT; }
    double get_TruthV_m() { return TruthV_m; }
    
    TLorentzVector get_TruthV_TLV() { return tlv; }
};
*/

// Function definitions
template <typename T>
bool sort_descending_Pt(T obj1, T obj2)
{
    return (obj1.get_TLV()).Pt() > (obj2.get_TLV()).Pt();
}

template <>  // explicit specialization
bool sort_descending_Pt(TLorentzVector tlv1, TLorentzVector tlv2)
{
    return tlv1.Pt() > tlv2.Pt();
}

double calculate_Ht(vector<Lepton> signal_leptons, vector<Jet> signal_jets)
{
    double Ht = 0;
    for (auto & lep : signal_leptons) {
        Ht = Ht + lep.get_pt();
    }
    for (auto & jet : signal_jets) {
        Ht = Ht + jet.get_pt();
    }
    return Ht;
}


double calculate_Meff(double Ht, double Etmiss)
{
    // the scalar sum of the signal leptons pT, all signal jets pT, and ETmiss
    return  Ht + Etmiss;
}

#endif // #ifdef AnaNtupBunchSapcing_cxx
