#ifndef YT_SKIM_DATA_H
#define YT_SKIM_DATA_H

#include "ytNUHM2Analysis/yt_skim.h"

#include <iostream>
#include <vector>
using namespace std;

class yt_skim_data : public yt_skim 
{
public:
    // user defined variables

    // Declare the output
    TFile *output_file;
    TTree *output_tree;

    // Declaring the new variables
    // Physics object variables
    vector<double>  *El_ZTandP_mll;
    vector<double>  *El_DR_closest_Jet;
    vector<bool>    *El_isBaseline;
    vector<bool>    *El_isSignal;
    vector<bool>    *El_isZProbe;
    vector<bool>    *El_isZProbe_TriggerMatched;
    vector<bool>    *El_isTTbarProbe;

    vector<double>  *Mu_ZTandP_mll;
    vector<double>  *Mu_DR_closest_Jet;
    vector<bool>    *Mu_isBaseline;
    vector<bool>    *Mu_isSignal;
    vector<bool>    *Mu_isZProbe;
    vector<bool>    *Mu_isZProbe_TriggerMatched;
    vector<bool>    *Mu_isTTbarProbe;

    vector<bool>    *Jet_Jet_isBaseline;
    vector<bool>    *Jet_Jet_isSignal;
    vector<bool>    *Jet_bJet_isSignal;

    // Events variables
    bool    isSS2l_trigger;
    double  baseline_mll;
    double  mll;
    double  mjj;
    double  meff;
    double  Ht;
    double  mT;
    int     nBaseLeps;
    int     nSigLeps;
    double  lep1Pt;
    double  lep2Pt;
    double  lep3Pt;
    double  lep1Eta;
    double  lep2Eta;
    double  lep3Eta;
    bool    lep1Type;
    bool    lep2Type;
    bool    lep3Type;
    bool    lep1Origin;
    bool    lep2Origin;
    bool    lep3Origin;
    int     nSigBJets;
    int     nSigJets;
    double  jet1Pt;
    double  jet2Pt;
    double  jet3Pt;
    bool    is3l; // not use
    bool    isSS2l;
    int     baseline_channel;
    int     channel; // -1 for less than 2 leptons,  1 for ee,  2 for em ,  3 for mm

    // ----------------------------

    // Counters
    //int n_duplicated_EventNumber; // not use
    int n_tot_baseline_electrons;
    int n_tot_baseline_muons;
    int n_tot_2baseline_leptons;
    int n_tot_baseline_leptons_in_TTbarTandP_Events;
    int n_2Baseline_leptons_Events;
    int n_2Baseline_Bjets_Events;
    int n_TTbarEtmiss_Events;
    int n_TTbarMll_Events;
    int n_tot_ZTandP_electrons;
    int n_tot_ZTandP_muons;
    int n_tot_TTbarTandP_electrons;
    int n_tot_TTbarTandP_muons;

    int n_CutFlow_ee_ChanSep;
    int n_CutFlow_ee_AtLeast1Bjets_pT20;
    int n_CutFlow_ee_AtLeast4Jets_pt50;
    int n_CutFlow_emu_ChanSep;
    int n_CutFlow_emu_AtLeast1Bjets_pT20;
    int n_CutFlow_emu_AtLeast4Jets_pt50;
    int n_CutFlow_mumu_ChanSep;
    int n_CutFlow_mumu_AtLeast1Bjets_pT20;
    int n_CutFlow_mumu_AtLeast4Jets_pt50;

public:
    yt_skim_data();
    virtual ~yt_skim_data();

    void initialize(TTree *tree, TString process);
    void execute(vector<Electron> elec, vector<Muon> muon, vector<Lepton> lept, vector<Jet> jets,
                 vector<Electron> baseline_elec, vector<Muon> baseline_muon, vector<Lepton> baseline_lept, vector<Jet> baseline_jets,
                 vector<Electron> signal_elec, vector<Muon> signal_muon, vector<Lepton> signal_lept, vector<Jet> signal_jets,
                 double Etmiss_TST_Et, int run_number);
    void finalize();    

    void reset_vectors();
    void calculate_new_variables(double Etmiss_TST_Et);
    void tag_and_probe_Zee(int run_number);
    void tag_and_probe_ttbar(double Etmiss_TST_Et);

    ClassDef(yt_skim_data, 0);
};

#endif // #ifndef YT_SKIM_DATA_H
