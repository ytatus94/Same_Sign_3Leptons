#ifndef MYSELECTOR_H
#define MYSELECTOR_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <iterator>
using namespace std;

#define Mu_Mass 105.6583715

#include "MyPackages/AnaNtupSelector.h"
#include "MyPackages/Leptons.h"
#include "MyPackages/Jet.h"

class GoodRunsListSelectionTool;

class MySelector : public AnaNtupSelector {
public:
    // flag
    int isMC;
    int isData;
    
    // GRL
    GoodRunsListSelectionTool *m_grl;

    // Variables for counting number of events after cuts
    int fAllEventsBeforeDerivations;
    int fAllEventsInNtuple;
    int fGRL;
    int fTrigger;
    int fGlobalFlags;
    int fJetAndMuonCleaning;
    int fPrimaryVertex;
    int fCosmicsVeto;
    int fAtLeastTwoBaselineLeptons;
    int fAtLeastTwoSignalLeptons;
    // El-El channel
    int fChannelSelection_elel;
    int fTrigger_elel;
    int fMl1l2_elel;
    int fAtLeastOneBJet_elel;
    int fAtLeastFourJets_elel;
    int fSameSign_elel;
    int fMET_elel;
    // El-Mu channel
    int fChannelSelection_elmu;
    int fTrigger_elmu;
    int fMl1l2_elmu;
    int fAtLeastOneBJet_elmu;
    int fAtLeastFourJets_elmu;
    int fSameSign_elmu;
    int fMET_elmu;
    // Mu-Mu channel
    int fChannelSelection_mumu;
    int fTrigger_mumu;
    int fMl1l2_mumu;
    int fAtLeastOneBJet_mumu;
    int fAtLeastFourJets_mumu;
    int fSameSign_mumu;
    int fMET_mumu;

    vector<Electron> vec_elec;
    vector<Muon>     vec_muon;
    vector<Jet>      vec_jets;
    vector<Lepton>   vec_lept;

    vector<Electron> vec_OR_elec;
    vector<Muon>     vec_OR_muon;
    vector<Jet>      vec_OR_jets;
    vector<Lepton>   vec_OR_lept;

    vector<Electron> vec_signal_elec;
    vector<Muon>     vec_signal_muon;
    vector<Jet>      vec_signal_jets;
    vector<Lepton>   vec_signal_lept;

    TH1 *hCutFlows;
/*
    // For baseline leptons
    TH1 *h_mll_baseline_OS_ee;
    TH1 *h_mll_baseline_OS_emu;
    TH1 *h_mll_baseline_OS_mumu;
    TH1 *h_mll_baseline_SS_ee;
    TH1 *h_mll_baseline_SS_emu;
    TH1 *h_mll_baseline_SS_mumu;
    
    TH1 *h_ptvarcone20_pt_baseline_OS_ee;
    TH1 *h_ptvarcone20_pt_baseline_OS_emu;
    TH1 *h_ptvarcone20_pt_baseline_OS_mumu;
    TH1 *h_ptvarcone20_pt_baseline_SS_ee;
    TH1 *h_ptvarcone20_pt_baseline_SS_emu;
    TH1 *h_ptvarcone20_pt_baseline_SS_mumu;
    
    TH1 *h_ptvarcone30_pt_baseline_OS_ee;
    TH1 *h_ptvarcone30_pt_baseline_OS_emu;
    TH1 *h_ptvarcone30_pt_baseline_OS_mumu;
    TH1 *h_ptvarcone30_pt_baseline_SS_ee;
    TH1 *h_ptvarcone30_pt_baseline_SS_emu;
    TH1 *h_ptvarcone30_pt_baseline_SS_mumu;
    
    TH1 *h_ptvarcone40_pt_baseline_OS_ee;
    TH1 *h_ptvarcone40_pt_baseline_OS_emu;
    TH1 *h_ptvarcone40_pt_baseline_OS_mumu;
    TH1 *h_ptvarcone40_pt_baseline_SS_ee;
    TH1 *h_ptvarcone40_pt_baseline_SS_emu;
    TH1 *h_ptvarcone40_pt_baseline_SS_mumu;
    
    TH1 *h_topoetcone20_pt_baseline_OS_ee;
    TH1 *h_topoetcone20_pt_baseline_OS_emu;
    TH1 *h_topoetcone20_pt_baseline_OS_mumu;
    TH1 *h_topoetcone20_pt_baseline_SS_ee;
    TH1 *h_topoetcone20_pt_baseline_SS_emu;
    TH1 *h_topoetcone20_pt_baseline_SS_mumu;
    
    TH1 *h_topoetcone30_pt_baseline_OS_ee;
    TH1 *h_topoetcone30_pt_baseline_OS_emu;
    TH1 *h_topoetcone30_pt_baseline_OS_mumu;
    TH1 *h_topoetcone30_pt_baseline_SS_ee;
    TH1 *h_topoetcone30_pt_baseline_SS_emu;
    TH1 *h_topoetcone30_pt_baseline_SS_mumu;
    
    TH1 *h_topoetcone40_pt_baseline_OS_ee;
    TH1 *h_topoetcone40_pt_baseline_OS_emu;
    TH1 *h_topoetcone40_pt_baseline_OS_mumu;
    TH1 *h_topoetcone40_pt_baseline_SS_ee;
    TH1 *h_topoetcone40_pt_baseline_SS_emu;
    TH1 *h_topoetcone40_pt_baseline_SS_mumu;

    // For signal leptons
    TH1 *h_mll_signal_OS_ee;
    TH1 *h_mll_signal_OS_emu;
    TH1 *h_mll_signal_OS_mumu;
    TH1 *h_mll_signal_SS_ee;
    TH1 *h_mll_signal_SS_emu;
    TH1 *h_mll_signal_SS_mumu;
    
    TH1 *h_ptvarcone20_pt_signal_OS_ee;
    TH1 *h_ptvarcone20_pt_signal_OS_emu;
    TH1 *h_ptvarcone20_pt_signal_OS_mumu;
    TH1 *h_ptvarcone20_pt_signal_SS_ee;
    TH1 *h_ptvarcone20_pt_signal_SS_emu;
    TH1 *h_ptvarcone20_pt_signal_SS_mumu;
    
    TH1 *h_ptvarcone30_pt_signal_OS_ee;
    TH1 *h_ptvarcone30_pt_signal_OS_emu;
    TH1 *h_ptvarcone30_pt_signal_OS_mumu;
    TH1 *h_ptvarcone30_pt_signal_SS_ee;
    TH1 *h_ptvarcone30_pt_signal_SS_emu;
    TH1 *h_ptvarcone30_pt_signal_SS_mumu;
    
    TH1 *h_ptvarcone40_pt_signal_OS_ee;
    TH1 *h_ptvarcone40_pt_signal_OS_emu;
    TH1 *h_ptvarcone40_pt_signal_OS_mumu;
    TH1 *h_ptvarcone40_pt_signal_SS_ee;
    TH1 *h_ptvarcone40_pt_signal_SS_emu;
    TH1 *h_ptvarcone40_pt_signal_SS_mumu;
    
    TH1 *h_topoetcone20_pt_signal_OS_ee;
    TH1 *h_topoetcone20_pt_signal_OS_emu;
    TH1 *h_topoetcone20_pt_signal_OS_mumu;
    TH1 *h_topoetcone20_pt_signal_SS_ee;
    TH1 *h_topoetcone20_pt_signal_SS_emu;
    TH1 *h_topoetcone20_pt_signal_SS_mumu;
    
    TH1 *h_topoetcone30_pt_signal_OS_ee;
    TH1 *h_topoetcone30_pt_signal_OS_emu;
    TH1 *h_topoetcone30_pt_signal_OS_mumu;
    TH1 *h_topoetcone30_pt_signal_SS_ee;
    TH1 *h_topoetcone30_pt_signal_SS_emu;
    TH1 *h_topoetcone30_pt_signal_SS_mumu;
    
    TH1 *h_topoetcone40_pt_signal_OS_ee;
    TH1 *h_topoetcone40_pt_signal_OS_emu;
    TH1 *h_topoetcone40_pt_signal_OS_mumu;
    TH1 *h_topoetcone40_pt_signal_SS_ee;
    TH1 *h_topoetcone40_pt_signal_SS_emu;
    TH1 *h_topoetcone40_pt_signal_SS_mumu;
    
    TH1 *h_pt_leading_signal_OS_ee;
    TH1 *h_pt_leading_signal_OS_emu;
    TH1 *h_pt_leading_signal_OS_mumu;
    TH1 *h_pt_leading_signal_SS_ee;
    TH1 *h_pt_leading_signal_SS_emu;
    TH1 *h_pt_leading_signal_SS_mumu;
    
    TH1 *h_pt_subleading_signal_OS_ee;
    TH1 *h_pt_subleading_signal_OS_emu;
    TH1 *h_pt_subleading_signal_OS_mumu;
    TH1 *h_pt_subleading_signal_SS_ee;
    TH1 *h_pt_subleading_signal_SS_emu;
    TH1 *h_pt_subleading_signal_SS_mumu;
    
    // For jets
    TH1 *h_jet_multiplicities_pt20_OS_ee;
    TH1 *h_jet_multiplicities_pt20_OS_emu;
    TH1 *h_jet_multiplicities_pt20_OS_mumu;
    TH1 *h_jet_multiplicities_pt20_SS_ee;
    TH1 *h_jet_multiplicities_pt20_SS_emu;
    TH1 *h_jet_multiplicities_pt20_SS_mumu;
    
    TH1 *h_jet_multiplicities_pt50_OS_ee;
    TH1 *h_jet_multiplicities_pt50_OS_emu;
    TH1 *h_jet_multiplicities_pt50_OS_mumu;
    TH1 *h_jet_multiplicities_pt50_SS_ee;
    TH1 *h_jet_multiplicities_pt50_SS_emu;
    TH1 *h_jet_multiplicities_pt50_SS_mumu;
    
    TH1 *h_pt_1st_jets;
    TH1 *h_pt_2nd_jets;
    TH1 *h_pt_3rd_jets;
    TH1 *h_pt_4th_jets;
    
    // For Etmiss (baseline)
    TH1 *h_MET_baseline_OS_ee;
    TH1 *h_MET_baseline_OS_emu;
    TH1 *h_MET_baseline_OS_mumu;
    TH1 *h_MET_baseline_SS_ee;
    TH1 *h_MET_baseline_SS_emu;
    TH1 *h_MET_baseline_SS_mumu;

    // For Etmiss (signal)
    TH1 *h_MET_signal_OS_ee;
    TH1 *h_MET_signal_OS_emu;
    TH1 *h_MET_signal_OS_mumu;
    TH1 *h_MET_signal_SS_ee;
    TH1 *h_MET_signal_SS_emu;
    TH1 *h_MET_signal_SS_mumu;

	// For Meff (baseline)
    TH1 *h_meff_baseline_OS_ee;
    TH1 *h_meff_baseline_OS_emu;
    TH1 *h_meff_baseline_OS_mumu;
    TH1 *h_meff_baseline_SS_ee;
    TH1 *h_meff_baseline_SS_emu;
    TH1 *h_meff_baseline_SS_mumu;
    
	// For Meff (signal)
    TH1 *h_meff_signal_OS_ee;
    TH1 *h_meff_signal_OS_emu;
    TH1 *h_meff_signal_OS_mumu;
    TH1 *h_meff_signal_SS_ee;
    TH1 *h_meff_signal_SS_emu;
    TH1 *h_meff_signal_SS_mumu;
*/    
public:
    TTree	*fChain; //!pointer to the analyzed TTree or TChain

    MySelector(TTree * /*tree*/ =0) : fChain(0) { }
    virtual ~MySelector() { }
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

    void Fill_electrons(int              RunNb,
                        Int_t            NEl,
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
                        vector<bool>     *El_passIsoGradLoose);
    
    void Fill_muons(int              RunNb,
                    Int_t            NMu,
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
                    vector<bool>     *Mu_passIsoGradLoose);
    
    void Fill_jets(Int_t             NJet,
                   vector<double>    *Jet_eta,
                   vector<double>    *Jet_phi,
                   vector<double>    *Jet_pT,
                   vector<double>    *Jet_E,
                   vector<double>    *Jet_quality,
                   vector<double>    *Jet_JVF,
                   vector<double>    *Jet_JVT,
                   vector<double>    *Jet_MV2c20,
                   vector<double>    *Jet_SFw,
                   vector<int>       *Jet_nTrk);
    
    void Fill_leptons(vector<Electron> vec_elec, vector<Muon> vec_muon);
    
    void Fill_baseline_electrons(vector<Electron> vec_elec);
    void Fill_baseline_muons(vector<Muon> vec_muon);
    void Fill_baseline_jets(vector<Jet> jets);
    void Fill_baseline_leptons(vector<Electron> signal_elec, vector<Muon> signal_muon);
    
    void Fill_signal_electrons(vector<Electron> vec_elec);
    void Fill_signal_muons(vector<Muon> vec_muon);
    void Fill_signal_jets(vector<Jet> jets);
    void Fill_signal_leptons(vector<Electron> signal_elec, vector<Muon> signal_muon);

    void Set_baseline_and_signal_electrons();
    void Set_baseline_and_signal_muons();
    void Set_baseline_and_signal_jets();

    friend void OverlapRemoval(int EventNumber,
			       			   vector<Electron> *el_obj,
                               vector<Muon>     *mu_obj,
                               vector<Jet>      *jet_obj,
                               double dRejet,
                               double dRjetmu,
                               double dRjete,
                               double dRemu,
                               double dRee);

   ClassDef(MySelector,0);
};
#endif // #define MYSELECTOR_H

#ifdef MYSELECTOR_CXX
void MySelector::Init(TTree *tree)
{
    // The Init() function is called when the selector needs to initialize
    // a new tree or chain. Typically here the branch addresses and branch
    // pointers of the tree will be set.
    // It is normally not necessary to make changes to the generated
    // code, but the routine can be extended by the user if needed.
    // Init() will be called many times when running on PROOF
    // (once per file to be processed).
    
    AnaNtupSelector::Init(tree);

    fAllEventsBeforeDerivations = 0;
    fAllEventsInNtuple = 0;
    fGRL = 0;
    fTrigger = 0;
    fGlobalFlags = 0;
    fJetAndMuonCleaning = 0;
    fPrimaryVertex = 0;
    fCosmicsVeto = 0;
    fAtLeastTwoBaselineLeptons = 0;
    fAtLeastTwoSignalLeptons = 0;
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
}

Bool_t MySelector::Notify()
{
    // The Notify() function is called when a new file is opened. This
    // can be either for a new TTree in a TChain or when when a new TTree
    // is started when using PROOF. It is normally not necessary to make changes
    // to the generated code, but the routine can be extended by the
    // user if needed. The return value is currently not used.
    
    return kTRUE;
}
#endif // #ifdef MYSELECTOR_CXX
