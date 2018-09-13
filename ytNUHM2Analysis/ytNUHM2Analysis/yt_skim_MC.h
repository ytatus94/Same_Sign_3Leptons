#ifndef YT_SKIM_MC_H
#define YT_SKIM_MC_H

#include "ytNUHM2Analysis/yt_skim.h"

#include <TString.h>

#include <iostream>
#include <vector>
using namespace std;

class yt_skim_MC : public yt_skim
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
    vector<double>  *El_DR_closest_truth_BJet;
    vector<double>  *El_DR_closest_truth_CJet;
    vector<double>  *El_DR_closest_truth_lightJet;
    vector<bool>    *El_isBaseline;
    vector<bool>    *El_isSignal;
    vector<bool>    *El_isZProbe;
    vector<bool>    *El_isZProbe_TriggerMatched;
    vector<bool>    *El_isTTbarProbe;
    vector<double>  *El_tag_trigger_SF;

    vector<double>  *Mu_ZTandP_mll;
    vector<double>  *Mu_DR_closest_Jet;
    vector<double>  *Mu_DR_closest_truth_BJet;
    vector<double>  *Mu_DR_closest_truth_CJet;
    vector<double>  *Mu_DR_closest_truth_lightJet;
    vector<bool>    *Mu_isBaseline;
    vector<bool>    *Mu_isSignal;
    vector<bool>    *Mu_isZProbe;
    vector<bool>    *Mu_isZProbe_TriggerMatched;
    vector<bool>    *Mu_isTTbarProbe;
    vector<float>   *Mu_tag_trigger_SF;

    vector<bool>    *Jet_Jet_isBaseline;
    vector<bool>    *Jet_Jet_isSignal;
    vector<bool>    *Jet_bJet_isSignal;

    // Events variables
    double  baseline_weight;
    double  signal_weight;
    bool    isSS2l_trigger;
    double  normalization;
    double  pileup_weight;
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
    bool    isSS2l;
    int     baseline_channel;
    int     channel; // -1 for less than 2 leptons,  1 for ee,  2 for em ,  3 for mm

    int     run_number;
    // ----------------------------
/*
    vector<int>     EventNumberList;
    vector<double>  EtmissList;
    vector<double>  EtmissXList;
    vector<double>  PVzList;
*/
    // Counters
    //int n_duplicated_EventNumber; // not use
    int n_tot_baseline_electrons;
    int n_tot_baseline_muons;
    int n_tot_2baseline_leptons;
    int n_tot_baseline_leptons_in_TTbarTandP_Events;
    int n_2Baseline_leptons_Events;
    int n_2Baseline_Bjets_Events;
    int n_tot_2baseline_leptons_pt30;
    int n_TTbarEtmiss_Events;
    int n_TTbarMll_Events;
    int n_tot_ZTandP_electrons;
    int n_tot_ZTandP_muons;
    int n_tot_TTbarTandP_electrons;
    int n_tot_TTbarTandP_muons;

    //double sum_event_weight; // not use
    double n_normalized_events;
    double n_normalized_tot_baseline_electrons;
    double n_normalized_tot_baseline_muons;
    double n_normalized_tot_2baseline_leptons;
    double n_normalized_2Baseline_leptons_Events;
    double n_normalized_2Baseline_Bjets_Events;
    double n_normalized_2Baseline_leptons_Events_pt30;
    double n_normalized_TTbarEtmiss_Events;
    double n_normalized_TTbarMll_Events;
    double n_normalized_tot_ZTandP_electrons;
    double n_normalized_tot_ZTandP_muons;
    double n_normalized_tot_TTbarTandP_electrons;
    double n_normalized_tot_TTbarTandP_muons;

    // Event weight
    double event_weight_sum;

    // Normalisation scale factor
    //const double lumi = 5.8; // unit: 1/fb, 3.2/fb (2015) + 2.6/fb (2016)
    double lumi;

    // Cross section
    double crossSection; // Inclusive crossSection * factor 1 * factor 2 * factor 3
    double kFactor;
    double filterEfficiency;

    // Derivation efficiency
    double analysis1LeptonFilter;  // ttbar (non all had)

public:
    yt_skim_MC();
    virtual ~yt_skim_MC();

    void initialize(TTree *tree, TString process);
    void execute(vector<Electron> elec, vector<Muon> muon, vector<Lepton> lept, vector<Jet> jets,
                 vector<Electron> baseline_elec, vector<Muon> baseline_muon, vector<Lepton> baseline_lept, vector<Jet> baseline_jets,
                 vector<Electron> signal_elec, vector<Muon> signal_muon, vector<Lepton> signal_lept, vector<Jet> signal_jets,
                 double Etmiss_TST_Et, double event_weight, int run_number, float pileup_weight, double baseline_weight, double signal_weight, TString process);
    void finalize(TString process);

    void reset_vectors();
    void calculate_new_variables(double Etmiss_TST_Et);
    void tag_and_probe_Zee(int run_number);
    void tag_and_probe_ttbar(double Etmiss_TST_Et);

    void set_luminosity(double number);
    void set_run_number(int number);
    void set_pileup_weight(float number);
    void set_baseline_weight(double number);
    void set_signal_weight(double number);
    void set_event_weight_sum(double sum);
    void set_cross_section_by_process(TString process);
    void set_derivation_efficiency(TString bunch_spacing, TString process);

    ClassDef(yt_skim_MC, 0);
};

#endif // #ifndef YT_SKIM_MC_H
