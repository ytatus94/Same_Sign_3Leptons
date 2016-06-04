//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Mon Jul  6 14:30:16 2015 by ROOT version 6.02/05
// from TTree AnaNtup/AnaNtup
// found on file: user.jpoveda.5632900._000001.output.root
//////////////////////////////////////////////////////////

#ifndef AnaNtupSelector_h
#define AnaNtupSelector_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>

// Header file for the classes stored in the TTree if any.
#include <vector>
using std::vector;

class AnaNtupSelector : public TSelector {
public :
   TTree          *fChain;   //!pointer to the analyzed TTree or TChain

// Fixed size dimensions of array or collections stored in the TTree if any.

   // Declaration of leaf types
   Bool_t          HLT_noalg_L12EM15;
   Bool_t          HLT_noalg_L12EM7;
   Bool_t          HLT_noalg_L12MU4;
   Bool_t          HLT_noalg_L1EM12;
   Bool_t          HLT_noalg_L1EM15;
   Bool_t          HLT_noalg_L1EM18VH;
   Bool_t          HLT_noalg_L1MU10;
   Bool_t          HLT_noalg_L1XE35;
   Bool_t          L1_2EM15;
   Bool_t          L1_2EM7;
   Bool_t          L1_2MU4;
   Bool_t          L1_2MU6;
   Bool_t          L1_EM12;
   Bool_t          L1_EM15;
   Bool_t          L1_EM15_MU4;
   Bool_t          L1_EM7_MU10;
   Bool_t          L1_MU10;
   Bool_t          L1_MU15;
   Bool_t          L1_MU4;
   Bool_t          L1_XE35;
   Bool_t          HLT_e24_lhmedium_iloose_L1EM18VH;
   Bool_t          HLT_e24_lhmedium_iloose_L1EM20VH;
   Bool_t          HLT_e24_lhmedium_L1EM18VH;
   Bool_t          HLT_e24_lhtight_iloose;
   Bool_t          HLT_e24_lhtight_iloose_L1EM20VH;
   Bool_t          HLT_e24_medium_iloose_L1EM18VH;
   Bool_t          HLT_e24_medium_iloose_L1EM20VH;
   Bool_t          HLT_e24_medium_L1EM18VH;
   Bool_t          HLT_e24_tight_iloose;
   Bool_t          HLT_e24_tight_iloose_L1EM20VH;
   Bool_t          HLT_e26_lhtight_iloose;
   Bool_t          HLT_e26_tight_iloose;
   Bool_t          HLT_e60_lhmedium;
   Bool_t          HLT_e60_medium;
   Bool_t          HLT_j100_xe80;
   Bool_t          HLT_j80_xe80;
   Bool_t          HLT_mu18;
   Bool_t          HLT_mu20_iloose_L1MU15;
   Bool_t          HLT_mu24_iloose_L1MU15;
   Bool_t          HLT_mu24_imedium;
   Bool_t          HLT_mu26_imedium;
   Bool_t          HLT_mu50;
   Bool_t          HLT_x700_pufit_wEFMu;
   Bool_t          HLT_xe100;
   Bool_t          HLT_xe100_mht;
   Bool_t          HLT_xe100_mht_wEFMu;
   Bool_t          HLT_xe100_pueta;
   Bool_t          HLT_xe100_pueta_wEFMu;
   Bool_t          HLT_xe100_pufit;
   Bool_t          HLT_xe100_pufit_wEFMu;
   Bool_t          HLT_xe100_wEFMu;
   Bool_t          HLT_xe35;
   Bool_t          HLT_xe35_mht;
   Bool_t          HLT_xe35_mht_wEFMu;
   Bool_t          HLT_xe35_pueta;
   Bool_t          HLT_xe35_pueta_wEFMu;
   Bool_t          HLT_xe35_pufit;
   Bool_t          HLT_xe35_pufit_wEFMu;
   Bool_t          HLT_xe35_wEFMu;
   Bool_t          HLT_xe70;
   Bool_t          HLT_xe70_mht;
   Bool_t          HLT_xe70_mht_wEFMu;
   Bool_t          HLT_xe70_pueta;
   Bool_t          HLT_xe70_pueta_wEFMu;
   Bool_t          HLT_xe70_pufit;
   Bool_t          HLT_xe70_wEFMu;
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
   vector<double>  *Mu_sigd0;
   vector<double>  *Mu_z0pvtx;
   vector<bool>    *Mu_isBad;
   vector<bool>    *Mu_isCosmic;
   vector<double>  *Mu_ptcone20;
   vector<double>  *Mu_ptcone30;
   vector<double>  *Mu_ptcone40;
   vector<double>  *Mu_ptvarcone20;
   vector<double>  *Mu_ptvarcone30;
   vector<double>  *Mu_ptvarcone40;
   vector<double>  *Mu_topoetcone20;
   vector<double>  *Mu_topoetcone30;
   vector<double>  *Mu_topoetcone40;
   vector<bool>    *Mu_passIsoVeryLooseTO;
   vector<bool>    *Mu_passIsoVeryLoose;
   vector<bool>    *Mu_passIsoLoose;
   vector<bool>    *Mu_passIsoTight;
   vector<bool>    *Mu_passIsoGrad;
   vector<bool>    *Mu_passIsoGradCustom;
   vector<bool>    *Mu_passIsoGradLoose;
   Int_t           NEl;
   vector<double>  *El_eta;
   vector<double>  *El_phi;
   vector<double>  *El_pT;
   vector<double>  *El_E;
   vector<int>     *El_charge;
   vector<double>  *El_sigd0;
   vector<double>  *El_z0pvtx;
   vector<double>  *El_d0pvtx;
   vector<double>  *El_SFwMedium;
   vector<double>  *El_SFwMediumLH;
   vector<double>  *El_SFwTight;
   vector<double>  *El_SFwTightLH;
   vector<bool>    *El_isLooseLH;
   vector<bool>    *El_isMediumLH;
   vector<bool>    *El_isTightLH;
   vector<bool>    *El_isLoose;
   vector<bool>    *El_isMedium;
   vector<bool>    *El_isTight;
   vector<double>  *El_ptcone20;
   vector<double>  *El_ptcone30;
   vector<double>  *El_ptcone40;
   vector<double>  *El_ptvarcone20;
   vector<double>  *El_ptvarcone30;
   vector<double>  *El_ptvarcone40;
   vector<double>  *El_topoetcone20;
   vector<double>  *El_topoetcone30;
   vector<double>  *El_topoetcone40;
   vector<bool>    *El_passIsoVeryLooseTO;
   vector<bool>    *El_passIsoVeryLoose;
   vector<bool>    *El_passIsoLoose;
   vector<bool>    *El_passIsoTight;
   vector<bool>    *El_passIsoGrad;
   vector<bool>    *El_passIsoGradCustom;
   vector<bool>    *El_passIsoGradLoose;
   Int_t           NJet;
   vector<double>  *Jet_eta;
   vector<double>  *Jet_phi;
   vector<double>  *Jet_pT;
   vector<double>  *Jet_E;
   vector<double>  *Jet_quality;
   vector<double>  *Jet_JVF;
   vector<double>  *Jet_JVT;
   vector<double>  *Jet_MV2c20;
   vector<double>  *Jet_SFw;
   vector<int>     *Jet_nTrk;
   Float_t         Etmiss_CST_Etx;
   Float_t         Etmiss_CST_Ety;
   Float_t         Etmiss_CST_Et;
   Float_t         Etmiss_TST_Etx;
   Float_t         Etmiss_TST_Ety;
   Float_t         Etmiss_TST_Et;
   Float_t         PV_z;

   // List of branches
   TBranch        *b_HLT_noalg_L12EM15;   //!
   TBranch        *b_HLT_noalg_L12EM7;   //!
   TBranch        *b_HLT_noalg_L12MU4;   //!
   TBranch        *b_HLT_noalg_L1EM12;   //!
   TBranch        *b_HLT_noalg_L1EM15;   //!
   TBranch        *b_HLT_noalg_L1EM18VH;   //!
   TBranch        *b_HLT_noalg_L1MU10;   //!
   TBranch        *b_HLT_noalg_L1XE35;   //!
   TBranch        *b_L1_2EM15;   //!
   TBranch        *b_L1_2EM7;   //!
   TBranch        *b_L1_2MU4;   //!
   TBranch        *b_L1_2MU6;   //!
   TBranch        *b_L1_EM12;   //!
   TBranch        *b_L1_EM15;   //!
   TBranch        *b_L1_EM15_MU4;   //!
   TBranch        *b_L1_EM7_MU10;   //!
   TBranch        *b_L1_MU10;   //!
   TBranch        *b_L1_MU15;   //!
   TBranch        *b_L1_MU4;   //!
   TBranch        *b_L1_XE35;   //!
   TBranch        *b_HLT_e24_lhmedium_iloose_L1EM18VH;   //!
   TBranch        *b_HLT_e24_lhmedium_iloose_L1EM20VH;   //!
   TBranch        *b_HLT_e24_lhmedium_L1EM18VH;   //!
   TBranch        *b_HLT_e24_lhtight_iloose;   //!
   TBranch        *b_HLT_e24_lhtight_iloose_L1EM20VH;   //!
   TBranch        *b_HLT_e24_medium_iloose_L1EM18VH;   //!
   TBranch        *b_HLT_e24_medium_iloose_L1EM20VH;   //!
   TBranch        *b_HLT_e24_medium_L1EM18VH;   //!
   TBranch        *b_HLT_e24_tight_iloose;   //!
   TBranch        *b_HLT_e24_tight_iloose_L1EM20VH;   //!
   TBranch        *b_HLT_e26_lhtight_iloose;   //!
   TBranch        *b_HLT_e26_tight_iloose;   //!
   TBranch        *b_HLT_e60_lhmedium;   //!
   TBranch        *b_HLT_e60_medium;   //!
   TBranch        *b_HLT_j100_xe80;   //!
   TBranch        *b_HLT_j80_xe80;   //!
   TBranch        *b_HLT_mu18;   //!
   TBranch        *b_HLT_mu20_iloose_L1MU15;   //!
   TBranch        *b_HLT_mu24_iloose_L1MU15;   //!
   TBranch        *b_HLT_mu24_imedium;   //!
   TBranch        *b_HLT_mu26_imedium;   //!
   TBranch        *b_HLT_mu50;   //!
   TBranch        *b_HLT_x700_pufit_wEFMu;   //!
   TBranch        *b_HLT_xe100;   //!
   TBranch        *b_HLT_xe100_mht;   //!
   TBranch        *b_HLT_xe100_mht_wEFMu;   //!
   TBranch        *b_HLT_xe100_pueta;   //!
   TBranch        *b_HLT_xe100_pueta_wEFMu;   //!
   TBranch        *b_HLT_xe100_pufit;   //!
   TBranch        *b_HLT_xe100_pufit_wEFMu;   //!
   TBranch        *b_HLT_xe100_wEFMu;   //!
   TBranch        *b_HLT_xe35;   //!
   TBranch        *b_HLT_xe35_mht;   //!
   TBranch        *b_HLT_xe35_mht_wEFMu;   //!
   TBranch        *b_HLT_xe35_pueta;   //!
   TBranch        *b_HLT_xe35_pueta_wEFMu;   //!
   TBranch        *b_HLT_xe35_pufit;   //!
   TBranch        *b_HLT_xe35_pufit_wEFMu;   //!
   TBranch        *b_HLT_xe35_wEFMu;   //!
   TBranch        *b_HLT_xe70;   //!
   TBranch        *b_HLT_xe70_mht;   //!
   TBranch        *b_HLT_xe70_mht_wEFMu;   //!
   TBranch        *b_HLT_xe70_pueta;   //!
   TBranch        *b_HLT_xe70_pueta_wEFMu;   //!
   TBranch        *b_HLT_xe70_pufit;   //!
   TBranch        *b_HLT_xe70_wEFMu;   //!
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
   TBranch        *b_Mu_sigd0;   //!
   TBranch        *b_Mu_z0pvtx;   //!
   TBranch        *b_Mu_isBad;   //!
   TBranch        *b_Mu_isCosmic;   //!
   TBranch        *b_Mu_ptcone20;   //!
   TBranch        *b_Mu_ptcone30;   //!
   TBranch        *b_Mu_ptcone40;   //!
   TBranch        *b_Mu_ptvarcone20;   //!
   TBranch        *b_Mu_ptvarcone30;   //!
   TBranch        *b_Mu_ptvarcone40;   //!
   TBranch        *b_Mu_topoetcone20;   //!
   TBranch        *b_Mu_topoetcone30;   //!
   TBranch        *b_Mu_topoetcone40;   //!
   TBranch        *b_Mu_passIsoVeryLooseTO;   //!
   TBranch        *b_Mu_passIsoVeryLoose;   //!
   TBranch        *b_Mu_passIsoLoose;   //!
   TBranch        *b_Mu_passIsoTight;   //!
   TBranch        *b_Mu_passIsoGrad;   //!
   TBranch        *b_Mu_passIsoGradCustom;   //!
   TBranch        *b_Mu_passIsoGradLoose;   //!
   TBranch        *b_NEl;   //!
   TBranch        *b_El_eta;   //!
   TBranch        *b_El_phi;   //!
   TBranch        *b_El_pT;   //!
   TBranch        *b_El_E;   //!
   TBranch        *b_El_charge;   //!
   TBranch        *b_El_sigd0;   //!
   TBranch        *b_El_z0pvtx;   //!
   TBranch        *b_El_d0pvtx;   //!
   TBranch        *b_El_SFwMedium;   //!
   TBranch        *b_El_SFwMediumLH;   //!
   TBranch        *b_El_SFwTight;   //!
   TBranch        *b_El_SFwTightLH;   //!
   TBranch        *b_El_isLooseLH;   //!
   TBranch        *b_El_isMediumLH;   //!
   TBranch        *b_El_isTightLH;   //!
   TBranch        *b_El_isLoose;   //!
   TBranch        *b_El_isMedium;   //!
   TBranch        *b_El_isTight;   //!
   TBranch        *b_El_ptcone20;   //!
   TBranch        *b_El_ptcone30;   //!
   TBranch        *b_El_ptcone40;   //!
   TBranch        *b_El_ptvarcone20;   //!
   TBranch        *b_El_ptvarcone30;   //!
   TBranch        *b_El_ptvarcone40;   //!
   TBranch        *b_El_topoetcone20;   //!
   TBranch        *b_El_topoetcone30;   //!
   TBranch        *b_El_topoetcone40;   //!
   TBranch        *b_El_passIsoVeryLooseTO;   //!
   TBranch        *b_El_passIsoVeryLoose;   //!
   TBranch        *b_El_passIsoLoose;   //!
   TBranch        *b_El_passIsoTight;   //!
   TBranch        *b_El_passIsoGrad;   //!
   TBranch        *b_El_passIsoGradCustom;   //!
   TBranch        *b_El_passIsoGradLoose;   //!
   TBranch        *b_NJet;   //!
   TBranch        *b_Jet_eta;   //!
   TBranch        *b_Jet_phi;   //!
   TBranch        *b_Jet_pT;   //!
   TBranch        *b_Jet_E;   //!
   TBranch        *b_Jet_quality;   //!
   TBranch        *b_Jet_JVF;   //!
   TBranch        *b_Jet_JVT;   //!
   TBranch        *b_Jet_MV2c20;   //!
   TBranch        *b_Jet_SFw;   //!
   TBranch        *b_Jet_nTrk;   //!
   TBranch        *b_Etmiss_CST_Etx;   //!
   TBranch        *b_Etmiss_CST_Ety;   //!
   TBranch        *b_Etmiss_CST_Et;   //!
   TBranch        *b_Etmiss_TST_Etx;   //!
   TBranch        *b_Etmiss_TST_Ety;   //!
   TBranch        *b_Etmiss_TST_Et;   //!
   TBranch        *b_PV_z;   //!

   AnaNtupSelector(TTree * /*tree*/ =0) : fChain(0) { }
   virtual ~AnaNtupSelector() { }
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

   ClassDef(AnaNtupSelector,0);
};

#endif

#ifdef AnaNtupSelector_cxx
void AnaNtupSelector::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the branch addresses and branch
   // pointers of the tree will be set.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   // Set object pointer
   Mu_eta = 0;
   Mu_phi = 0;
   Mu_pT = 0;
   Mu_SFw = 0;
   Mu_charge = 0;
   Mu_d0pvtx = 0;
   Mu_sigd0 = 0;
   Mu_z0pvtx = 0;
   Mu_isBad = 0;
   Mu_isCosmic = 0;
   Mu_ptcone20 = 0;
   Mu_ptcone30 = 0;
   Mu_ptcone40 = 0;
   Mu_ptvarcone20 = 0;
   Mu_ptvarcone30 = 0;
   Mu_ptvarcone40 = 0;
   Mu_topoetcone20 = 0;
   Mu_topoetcone30 = 0;
   Mu_topoetcone40 = 0;
   Mu_passIsoVeryLooseTO = 0;
   Mu_passIsoVeryLoose = 0;
   Mu_passIsoLoose = 0;
   Mu_passIsoTight = 0;
   Mu_passIsoGrad = 0;
   Mu_passIsoGradCustom = 0;
   Mu_passIsoGradLoose = 0;
   El_eta = 0;
   El_phi = 0;
   El_pT = 0;
   El_E = 0;
   El_charge = 0;
   El_sigd0 = 0;
   El_z0pvtx = 0;
   El_d0pvtx = 0;
   El_SFwMedium = 0;
   El_SFwMediumLH = 0;
   El_SFwTight = 0;
   El_SFwTightLH = 0;
   El_isLooseLH = 0;
   El_isMediumLH = 0;
   El_isTightLH = 0;
   El_isLoose = 0;
   El_isMedium = 0;
   El_isTight = 0;
   El_ptcone20 = 0;
   El_ptcone30 = 0;
   El_ptcone40 = 0;
   El_ptvarcone20 = 0;
   El_ptvarcone30 = 0;
   El_ptvarcone40 = 0;
   El_topoetcone20 = 0;
   El_topoetcone30 = 0;
   El_topoetcone40 = 0;
   El_passIsoVeryLooseTO = 0;
   El_passIsoVeryLoose = 0;
   El_passIsoLoose = 0;
   El_passIsoTight = 0;
   El_passIsoGrad = 0;
   El_passIsoGradCustom = 0;
   El_passIsoGradLoose = 0;
   Jet_eta = 0;
   Jet_phi = 0;
   Jet_pT = 0;
   Jet_E = 0;
   Jet_quality = 0;
   Jet_JVF = 0;
   Jet_JVT = 0;
   Jet_MV2c20 = 0;
   Jet_SFw = 0;
   Jet_nTrk = 0;
   // Set branch addresses and branch pointers
   if (!tree) return;
   fChain = tree;
   fChain->SetMakeClass(1);

   fChain->SetBranchAddress("HLT_noalg_L12EM15", &HLT_noalg_L12EM15, &b_HLT_noalg_L12EM15);
   fChain->SetBranchAddress("HLT_noalg_L12EM7", &HLT_noalg_L12EM7, &b_HLT_noalg_L12EM7);
   fChain->SetBranchAddress("HLT_noalg_L12MU4", &HLT_noalg_L12MU4, &b_HLT_noalg_L12MU4);
   fChain->SetBranchAddress("HLT_noalg_L1EM12", &HLT_noalg_L1EM12, &b_HLT_noalg_L1EM12);
   fChain->SetBranchAddress("HLT_noalg_L1EM15", &HLT_noalg_L1EM15, &b_HLT_noalg_L1EM15);
   fChain->SetBranchAddress("HLT_noalg_L1EM18VH", &HLT_noalg_L1EM18VH, &b_HLT_noalg_L1EM18VH);
   fChain->SetBranchAddress("HLT_noalg_L1MU10", &HLT_noalg_L1MU10, &b_HLT_noalg_L1MU10);
   fChain->SetBranchAddress("HLT_noalg_L1XE35", &HLT_noalg_L1XE35, &b_HLT_noalg_L1XE35);
   fChain->SetBranchAddress("L1_2EM15", &L1_2EM15, &b_L1_2EM15);
   fChain->SetBranchAddress("L1_2EM7", &L1_2EM7, &b_L1_2EM7);
   fChain->SetBranchAddress("L1_2MU4", &L1_2MU4, &b_L1_2MU4);
   fChain->SetBranchAddress("L1_2MU6", &L1_2MU6, &b_L1_2MU6);
   fChain->SetBranchAddress("L1_EM12", &L1_EM12, &b_L1_EM12);
   fChain->SetBranchAddress("L1_EM15", &L1_EM15, &b_L1_EM15);
   fChain->SetBranchAddress("L1_EM15_MU4", &L1_EM15_MU4, &b_L1_EM15_MU4);
   fChain->SetBranchAddress("L1_EM7_MU10", &L1_EM7_MU10, &b_L1_EM7_MU10);
   fChain->SetBranchAddress("L1_MU10", &L1_MU10, &b_L1_MU10);
   fChain->SetBranchAddress("L1_MU15", &L1_MU15, &b_L1_MU15);
   fChain->SetBranchAddress("L1_MU4", &L1_MU4, &b_L1_MU4);
   fChain->SetBranchAddress("L1_XE35", &L1_XE35, &b_L1_XE35);
   fChain->SetBranchAddress("HLT_e24_lhmedium_iloose_L1EM18VH", &HLT_e24_lhmedium_iloose_L1EM18VH, &b_HLT_e24_lhmedium_iloose_L1EM18VH);
   fChain->SetBranchAddress("HLT_e24_lhmedium_iloose_L1EM20VH", &HLT_e24_lhmedium_iloose_L1EM20VH, &b_HLT_e24_lhmedium_iloose_L1EM20VH);
   fChain->SetBranchAddress("HLT_e24_lhmedium_L1EM18VH", &HLT_e24_lhmedium_L1EM18VH, &b_HLT_e24_lhmedium_L1EM18VH);
   fChain->SetBranchAddress("HLT_e24_lhtight_iloose", &HLT_e24_lhtight_iloose, &b_HLT_e24_lhtight_iloose);
   fChain->SetBranchAddress("HLT_e24_lhtight_iloose_L1EM20VH", &HLT_e24_lhtight_iloose_L1EM20VH, &b_HLT_e24_lhtight_iloose_L1EM20VH);
   fChain->SetBranchAddress("HLT_e24_medium_iloose_L1EM18VH", &HLT_e24_medium_iloose_L1EM18VH, &b_HLT_e24_medium_iloose_L1EM18VH);
   fChain->SetBranchAddress("HLT_e24_medium_iloose_L1EM20VH", &HLT_e24_medium_iloose_L1EM20VH, &b_HLT_e24_medium_iloose_L1EM20VH);
   fChain->SetBranchAddress("HLT_e24_medium_L1EM18VH", &HLT_e24_medium_L1EM18VH, &b_HLT_e24_medium_L1EM18VH);
   fChain->SetBranchAddress("HLT_e24_tight_iloose", &HLT_e24_tight_iloose, &b_HLT_e24_tight_iloose);
   fChain->SetBranchAddress("HLT_e24_tight_iloose_L1EM20VH", &HLT_e24_tight_iloose_L1EM20VH, &b_HLT_e24_tight_iloose_L1EM20VH);
   fChain->SetBranchAddress("HLT_e26_lhtight_iloose", &HLT_e26_lhtight_iloose, &b_HLT_e26_lhtight_iloose);
   fChain->SetBranchAddress("HLT_e26_tight_iloose", &HLT_e26_tight_iloose, &b_HLT_e26_tight_iloose);
   fChain->SetBranchAddress("HLT_e60_lhmedium", &HLT_e60_lhmedium, &b_HLT_e60_lhmedium);
   fChain->SetBranchAddress("HLT_e60_medium", &HLT_e60_medium, &b_HLT_e60_medium);
   fChain->SetBranchAddress("HLT_j100_xe80", &HLT_j100_xe80, &b_HLT_j100_xe80);
   fChain->SetBranchAddress("HLT_j80_xe80", &HLT_j80_xe80, &b_HLT_j80_xe80);
   fChain->SetBranchAddress("HLT_mu18", &HLT_mu18, &b_HLT_mu18);
   fChain->SetBranchAddress("HLT_mu20_iloose_L1MU15", &HLT_mu20_iloose_L1MU15, &b_HLT_mu20_iloose_L1MU15);
   fChain->SetBranchAddress("HLT_mu24_iloose_L1MU15", &HLT_mu24_iloose_L1MU15, &b_HLT_mu24_iloose_L1MU15);
   fChain->SetBranchAddress("HLT_mu24_imedium", &HLT_mu24_imedium, &b_HLT_mu24_imedium);
   fChain->SetBranchAddress("HLT_mu26_imedium", &HLT_mu26_imedium, &b_HLT_mu26_imedium);
   fChain->SetBranchAddress("HLT_mu50", &HLT_mu50, &b_HLT_mu50);
   fChain->SetBranchAddress("HLT_x700_pufit_wEFMu", &HLT_x700_pufit_wEFMu, &b_HLT_x700_pufit_wEFMu);
   fChain->SetBranchAddress("HLT_xe100", &HLT_xe100, &b_HLT_xe100);
   fChain->SetBranchAddress("HLT_xe100_mht", &HLT_xe100_mht, &b_HLT_xe100_mht);
   fChain->SetBranchAddress("HLT_xe100_mht_wEFMu", &HLT_xe100_mht_wEFMu, &b_HLT_xe100_mht_wEFMu);
   fChain->SetBranchAddress("HLT_xe100_pueta", &HLT_xe100_pueta, &b_HLT_xe100_pueta);
   fChain->SetBranchAddress("HLT_xe100_pueta_wEFMu", &HLT_xe100_pueta_wEFMu, &b_HLT_xe100_pueta_wEFMu);
   fChain->SetBranchAddress("HLT_xe100_pufit", &HLT_xe100_pufit, &b_HLT_xe100_pufit);
   fChain->SetBranchAddress("HLT_xe100_pufit_wEFMu", &HLT_xe100_pufit_wEFMu, &b_HLT_xe100_pufit_wEFMu);
   fChain->SetBranchAddress("HLT_xe100_wEFMu", &HLT_xe100_wEFMu, &b_HLT_xe100_wEFMu);
   fChain->SetBranchAddress("HLT_xe35", &HLT_xe35, &b_HLT_xe35);
   fChain->SetBranchAddress("HLT_xe35_mht", &HLT_xe35_mht, &b_HLT_xe35_mht);
   fChain->SetBranchAddress("HLT_xe35_mht_wEFMu", &HLT_xe35_mht_wEFMu, &b_HLT_xe35_mht_wEFMu);
   fChain->SetBranchAddress("HLT_xe35_pueta", &HLT_xe35_pueta, &b_HLT_xe35_pueta);
   fChain->SetBranchAddress("HLT_xe35_pueta_wEFMu", &HLT_xe35_pueta_wEFMu, &b_HLT_xe35_pueta_wEFMu);
   fChain->SetBranchAddress("HLT_xe35_pufit", &HLT_xe35_pufit, &b_HLT_xe35_pufit);
   fChain->SetBranchAddress("HLT_xe35_pufit_wEFMu", &HLT_xe35_pufit_wEFMu, &b_HLT_xe35_pufit_wEFMu);
   fChain->SetBranchAddress("HLT_xe35_wEFMu", &HLT_xe35_wEFMu, &b_HLT_xe35_wEFMu);
   fChain->SetBranchAddress("HLT_xe70", &HLT_xe70, &b_HLT_xe70);
   fChain->SetBranchAddress("HLT_xe70_mht", &HLT_xe70_mht, &b_HLT_xe70_mht);
   fChain->SetBranchAddress("HLT_xe70_mht_wEFMu", &HLT_xe70_mht_wEFMu, &b_HLT_xe70_mht_wEFMu);
   fChain->SetBranchAddress("HLT_xe70_pueta", &HLT_xe70_pueta, &b_HLT_xe70_pueta);
   fChain->SetBranchAddress("HLT_xe70_pueta_wEFMu", &HLT_xe70_pueta_wEFMu, &b_HLT_xe70_pueta_wEFMu);
   fChain->SetBranchAddress("HLT_xe70_pufit", &HLT_xe70_pufit, &b_HLT_xe70_pufit);
   fChain->SetBranchAddress("HLT_xe70_wEFMu", &HLT_xe70_wEFMu, &b_HLT_xe70_wEFMu);
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
   fChain->SetBranchAddress("Mu_sigd0", &Mu_sigd0, &b_Mu_sigd0);
   fChain->SetBranchAddress("Mu_z0pvtx", &Mu_z0pvtx, &b_Mu_z0pvtx);
   fChain->SetBranchAddress("Mu_isBad", &Mu_isBad, &b_Mu_isBad);
   fChain->SetBranchAddress("Mu_isCosmic", &Mu_isCosmic, &b_Mu_isCosmic);
   fChain->SetBranchAddress("Mu_ptcone20", &Mu_ptcone20, &b_Mu_ptcone20);
   fChain->SetBranchAddress("Mu_ptcone30", &Mu_ptcone30, &b_Mu_ptcone30);
   fChain->SetBranchAddress("Mu_ptcone40", &Mu_ptcone40, &b_Mu_ptcone40);
   fChain->SetBranchAddress("Mu_ptvarcone20", &Mu_ptvarcone20, &b_Mu_ptvarcone20);
   fChain->SetBranchAddress("Mu_ptvarcone30", &Mu_ptvarcone30, &b_Mu_ptvarcone30);
   fChain->SetBranchAddress("Mu_ptvarcone40", &Mu_ptvarcone40, &b_Mu_ptvarcone40);
   fChain->SetBranchAddress("Mu_topoetcone20", &Mu_topoetcone20, &b_Mu_topoetcone20);
   fChain->SetBranchAddress("Mu_topoetcone30", &Mu_topoetcone30, &b_Mu_topoetcone30);
   fChain->SetBranchAddress("Mu_topoetcone40", &Mu_topoetcone40, &b_Mu_topoetcone40);
   fChain->SetBranchAddress("Mu_passIsoVeryLooseTO", &Mu_passIsoVeryLooseTO, &b_Mu_passIsoVeryLooseTO);
   fChain->SetBranchAddress("Mu_passIsoVeryLoose", &Mu_passIsoVeryLoose, &b_Mu_passIsoVeryLoose);
   fChain->SetBranchAddress("Mu_passIsoLoose", &Mu_passIsoLoose, &b_Mu_passIsoLoose);
   fChain->SetBranchAddress("Mu_passIsoTight", &Mu_passIsoTight, &b_Mu_passIsoTight);
   fChain->SetBranchAddress("Mu_passIsoGrad", &Mu_passIsoGrad, &b_Mu_passIsoGrad);
   fChain->SetBranchAddress("Mu_passIsoGradCustom", &Mu_passIsoGradCustom, &b_Mu_passIsoGradCustom);
   fChain->SetBranchAddress("Mu_passIsoGradLoose", &Mu_passIsoGradLoose, &b_Mu_passIsoGradLoose);
   fChain->SetBranchAddress("NEl", &NEl, &b_NEl);
   fChain->SetBranchAddress("El_eta", &El_eta, &b_El_eta);
   fChain->SetBranchAddress("El_phi", &El_phi, &b_El_phi);
   fChain->SetBranchAddress("El_pT", &El_pT, &b_El_pT);
   fChain->SetBranchAddress("El_E", &El_E, &b_El_E);
   fChain->SetBranchAddress("El_charge", &El_charge, &b_El_charge);
   fChain->SetBranchAddress("El_sigd0", &El_sigd0, &b_El_sigd0);
   fChain->SetBranchAddress("El_z0pvtx", &El_z0pvtx, &b_El_z0pvtx);
   fChain->SetBranchAddress("El_d0pvtx", &El_d0pvtx, &b_El_d0pvtx);
   fChain->SetBranchAddress("El_SFwMedium", &El_SFwMedium, &b_El_SFwMedium);
   fChain->SetBranchAddress("El_SFwMediumLH", &El_SFwMediumLH, &b_El_SFwMediumLH);
   fChain->SetBranchAddress("El_SFwTight", &El_SFwTight, &b_El_SFwTight);
   fChain->SetBranchAddress("El_SFwTightLH", &El_SFwTightLH, &b_El_SFwTightLH);
   fChain->SetBranchAddress("El_isLooseLH", &El_isLooseLH, &b_El_isLooseLH);
   fChain->SetBranchAddress("El_isMediumLH", &El_isMediumLH, &b_El_isMediumLH);
   fChain->SetBranchAddress("El_isTightLH", &El_isTightLH, &b_El_isTightLH);
   fChain->SetBranchAddress("El_isLoose", &El_isLoose, &b_El_isLoose);
   fChain->SetBranchAddress("El_isMedium", &El_isMedium, &b_El_isMedium);
   fChain->SetBranchAddress("El_isTight", &El_isTight, &b_El_isTight);
   fChain->SetBranchAddress("El_ptcone20", &El_ptcone20, &b_El_ptcone20);
   fChain->SetBranchAddress("El_ptcone30", &El_ptcone30, &b_El_ptcone30);
   fChain->SetBranchAddress("El_ptcone40", &El_ptcone40, &b_El_ptcone40);
   fChain->SetBranchAddress("El_ptvarcone20", &El_ptvarcone20, &b_El_ptvarcone20);
   fChain->SetBranchAddress("El_ptvarcone30", &El_ptvarcone30, &b_El_ptvarcone30);
   fChain->SetBranchAddress("El_ptvarcone40", &El_ptvarcone40, &b_El_ptvarcone40);
   fChain->SetBranchAddress("El_topoetcone20", &El_topoetcone20, &b_El_topoetcone20);
   fChain->SetBranchAddress("El_topoetcone30", &El_topoetcone30, &b_El_topoetcone30);
   fChain->SetBranchAddress("El_topoetcone40", &El_topoetcone40, &b_El_topoetcone40);
   fChain->SetBranchAddress("El_passIsoVeryLooseTO", &El_passIsoVeryLooseTO, &b_El_passIsoVeryLooseTO);
   fChain->SetBranchAddress("El_passIsoVeryLoose", &El_passIsoVeryLoose, &b_El_passIsoVeryLoose);
   fChain->SetBranchAddress("El_passIsoLoose", &El_passIsoLoose, &b_El_passIsoLoose);
   fChain->SetBranchAddress("El_passIsoTight", &El_passIsoTight, &b_El_passIsoTight);
   fChain->SetBranchAddress("El_passIsoGrad", &El_passIsoGrad, &b_El_passIsoGrad);
   fChain->SetBranchAddress("El_passIsoGradCustom", &El_passIsoGradCustom, &b_El_passIsoGradCustom);
   fChain->SetBranchAddress("El_passIsoGradLoose", &El_passIsoGradLoose, &b_El_passIsoGradLoose);
   fChain->SetBranchAddress("NJet", &NJet, &b_NJet);
   fChain->SetBranchAddress("Jet_eta", &Jet_eta, &b_Jet_eta);
   fChain->SetBranchAddress("Jet_phi", &Jet_phi, &b_Jet_phi);
   fChain->SetBranchAddress("Jet_pT", &Jet_pT, &b_Jet_pT);
   fChain->SetBranchAddress("Jet_E", &Jet_E, &b_Jet_E);
   fChain->SetBranchAddress("Jet_quality", &Jet_quality, &b_Jet_quality);
   fChain->SetBranchAddress("Jet_JVF", &Jet_JVF, &b_Jet_JVF);
   fChain->SetBranchAddress("Jet_JVT", &Jet_JVT, &b_Jet_JVT);
   fChain->SetBranchAddress("Jet_MV2c20", &Jet_MV2c20, &b_Jet_MV2c20);
   fChain->SetBranchAddress("Jet_SFw", &Jet_SFw, &b_Jet_SFw);
   fChain->SetBranchAddress("Jet_nTrk", &Jet_nTrk, &b_Jet_nTrk);
   fChain->SetBranchAddress("Etmiss_CST_Etx", &Etmiss_CST_Etx, &b_Etmiss_CST_Etx);
   fChain->SetBranchAddress("Etmiss_CST_Ety", &Etmiss_CST_Ety, &b_Etmiss_CST_Ety);
   fChain->SetBranchAddress("Etmiss_CST_Et", &Etmiss_CST_Et, &b_Etmiss_CST_Et);
   fChain->SetBranchAddress("Etmiss_TST_Etx", &Etmiss_TST_Etx, &b_Etmiss_TST_Etx);
   fChain->SetBranchAddress("Etmiss_TST_Ety", &Etmiss_TST_Ety, &b_Etmiss_TST_Ety);
   fChain->SetBranchAddress("Etmiss_TST_Et", &Etmiss_TST_Et, &b_Etmiss_TST_Et);
   fChain->SetBranchAddress("PV_z", &PV_z, &b_PV_z);
}

Bool_t AnaNtupSelector::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}

#endif // #ifdef AnaNtupSelector_cxx
