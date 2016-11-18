#ifndef YT_SKIM_H
#define YT_SKIM_H

#include <TROOT.h>
#include <TFile.h>
#include <TTree.h>

#include "ytNUHM2Analysis/Leptons.h"
#include "ytNUHM2Analysis/Jet.h"

#include <iostream>
#include <vector>
using namespace std;

class yt_skim
{
public:
	vector<Electron>	vec_elec;
	vector<Muon>		vec_muon;
	vector<Lepton>		vec_lept;
	vector<Jet>			vec_jets;

	vector<Electron>	vec_baseline_elec;
	vector<Muon>		vec_baseline_muon;
	vector<Lepton>		vec_baseline_lept;
	vector<Jet>			vec_baseline_jets;

	vector<Electron> 	vec_signal_elec;
	vector<Muon>     	vec_signal_muon;
	vector<Lepton>   	vec_signal_lept;
	vector<Jet>      	vec_signal_jets;

	vector<Jet>			vec_signal_jets_no_eta_cut;
	vector<Jet>			vec_signal_bjet;

public:
	yt_skim() {}
	virtual ~yt_skim() {}

	virtual void initialize();
	virtual void execute(vector<Electron> elec, vector<Muon> muon, vector<Lepton> lept, vector<Jet> jets,
						 vector<Electron> baseline_elec, vector<Muon> baseline_muon, vector<Lepton> baseline_lept, vector<Jet> baseline_jets,
						 vector<Electron> signal_elec, vector<Muon> signal_muon, vector<Lepton> signal_lept, vector<Jet> signal_jets);
	virtual void finalize();

	void copy_raw_object_vectors(vector<Electron> elec, vector<Muon> muon, vector<Lepton> lept, vector<Jet> jets);
	void copy_baseline_object_vectors(vector<Electron> elec, vector<Muon> muon, vector<Lepton> lept, vector<Jet> jets);
	void copy_signal_object_vectors(vector<Electron> elec, vector<Muon> muon, vector<Lepton> lept, vector<Jet> jets);

	void fill_signal_jets_no_eta_cut(vector<Jet> jets);
	void fill_signal_bjet(vector<Jet> signal_jets);

	double calculate_mll(vector<Lepton> leptons);
	double calculate_mjj(vector<Jet> jets);
	double calculate_Ht(vector<Lepton> leptons, vector<Jet> jets);
	double calculate_Meff(double Ht, double Etmiss);

	vector<double> calculate_DR_closestJet(Lepton lept, vector<Jet> jets);

	int Get_channel(vector<Lepton> lept);

	ClassDef(yt_skim, 0);
};

#endif // #ifndef YT_SKIM_H
