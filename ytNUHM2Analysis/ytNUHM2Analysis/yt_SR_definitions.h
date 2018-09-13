#ifndef YT_SR_DEFINITIONS_H
#define YT_SR_DEFINITIONS_H

#include <string>

class yt_SR_definitions
{
public:
	stirng name;

	int   n_lept;
	int   n_bjets_20;
	float bjets_pT;
	int   n_jets;
	float jets_pT;
	float met;
	float meff;
	float met_over_meff;

	yt_SR_definitions() : n_lept(0), n_bjets_20(0), bjets_pT(0), n_jets(0), jets_pT(0), met(0), meff(0), met_over_meff(0) {}
	~yt_SR_definitions() {}
	// set methods
	void set_name(string s)				{ name = s; }
	void set_n_lept_cut(int i) 			{ n_lept = i; }
	void set_n_bjets_20_cut(int i) 		{ n_bjets_20 = i; }
	void set_bjets_pT(float f)			{ bjets_pT = f; }
	void set_njets_cut(int i) 			{ n_jets = i; }
	void set_jet_pT_cut(float f) 		{ jet_pT = f; }
	void set_met_cut(float f) 			{ met = f; }
	void set_meff_cut(float f) 			{ meff = f; }
	void set_met_over_meff_cut(float f) { met_over_meff = f; }
	// get methods
	string get_name()			  { return name; }
	int   get_n_lept_cut() 		  { return n_lept; }
	int   get_n_bjets_20_cut() 	  { return n_bjets_20; }
	float get_bjets_pT()		  { return bjets_pT; }
	int   get_njets_cut() 		  { return n_jets; }
	float get_jet_pT_cut() 		  { return jet_pT; }
	float get_met_cut() 		  { return met; }
	float get_meff_cut() 		  { return meff; }
	float get_met_over_meff_cut() { return met_over_meff; }


	ClassDef(yt_SR_definitions, 0);
}

//
// Definitions of the RPV signal regions
//
yt_SR_definitions Rpv2L1bS;
Rpv2L1bS.set_name("Rpv2L1bS");
Rpv2L1bS.set_n_lept_cut(2); // >=
Rpv2L1bS.set_n_bjets_20_cut(1); // >=
Rpv2L1bS.set_bjets_pT(20.);
Rpv2L1bS.set_njets_cut(4); // >=
Rpv2L1bS.set_jet_pT_cut(50.);
Rpv2L1bS.set_met_cut(0.);
Rpv2L1bS.set_meff_cut(1200.); // >
Rpv2L1bS.set_met_over_meff_cut(0.);
// 2 negatively-charged leptons

yt_SR_definitions Rpv2L1bM;
Rpv2L1bM.set_name("Rpv2L1bM");
Rpv2L1bM.set_n_lept_cut(2); // >=
Rpv2L1bM.set_n_bjets_20_cut(1); // >=
Rpv2L1bM.set_bjets_pT(20.);
Rpv2L1bM.set_njets_cut(4); // >=
Rpv2L2bH.set_jet_pT_cut(50.);
Rpv2L2bH.set_met_cut(0.);
Rpv2L1bM.set_meff_cut(1800.); // >
Rpv2L1bM.set_met_over_meff_cut(0.);
// 2 negatively-charged leptons

yt_SR_definitions Rpv2L2bS;
Rpv2L2bS.set_name("Rpv2L2bS");
Rpv2L2bS.set_n_lept_cut(2); // >=
Rpv2L2bS.set_n_bjets_20_cut(2); // >=
Rpv2L2bS.set_bjets_pT(20.);
Rpv2L2bS.set_njets_cut(3); // >=
Rpv2L2bS.set_jet_pT_cut(50.);
Rpv2L2bS.set_met_cut(0.);
Rpv2L2bS.set_meff_cut(1200.); // >
Rpv2L2bS.set_met_over_meff_cut(0.);
// 2 negatively-charged leptons

yt_SR_definitions Rpv2L1bH;
Rpv2L1bH.set_name("Rpv2L1bH");
Rpv2L1bH.set_n_lept_cut(2); // >=
Rpv2L1bH.set_n_bjets_20_cut(1); // >=
Rpv2L1bH.set_bjets_pT(20.);
Rpv2L1bH.set_njets_cut(6); // >=
Rpv2L1bH.set_jet_pT_cut(50.);
Rpv2L1bH.set_met_cut(0.);
Rpv2L1bH.set_meff_cut(2200.); // >
Rpv2L1bH.set_met_over_meff_cut(0.);

yt_SR_definitions Rpv2L0b;
Rpv2L0b.set_name("Rpv2L0b");
Rpv2L0b.set_n_lept_cut(2);
Rpv2L0b.set_n_bjets_20_cut(0);
Rpv2L0b.set_bjets_pT(20.);
Rpv2L0b.set_njets_cut(6); // >=
Rpv2L0b.set_jet_pT_cut(40.);
Rpv2L0b.set_met_cut(0.);
Rpv2L0b.set_meff_cut(1800.); // >
Rpv2L0b.set_met_over_meff_cut(0.);
// veto 81 < mee < 101 GeV

yt_SR_definitions Rpv2L2bH;
Rpv2L2bH.set_name("Rpv2L2bH");
Rpv2L2bH.set_n_lept_cut(2); // >=
Rpv2L2bH.set_n_bjets_20_cut(2); // >=
Rpv2L2bH.set_bjets_pT(20.);
Rpv2L2bH.set_njets_cut(6); // >=
Rpv2L2bH.set_jet_pT_cut(40.);
Rpv2L2bH.set_met_cut(0.);
Rpv2L2bH.set_meff_cut(2000.); // >
Rpv2L2bH.set_met_over_meff_cut(0.);
// veto 81 < mee < 101 GeV


//
// Definitions of the PRC signal regions
//
yt_SR_definitions Rpc3L0bS;
Rpc3L0bS.set_n_lept_cut(3); // >=
Rpc3L0bS.set_n_bjets_20_cut(0); // =
Rpc3L0bS.set_bjets_pT(20.);
Rpc3L0bS.set_njets_cut(4); // >=
Rpc3L0bS.set_jet_pT_cut(40.);
Rpc3L0bS.set_met_cut(200.); // >
Rpc3L0bS.set_meff_cut(600.); // >
Rpc3L0bS.set_met_over_meff_cut(0.);

yt_SR_definitions Rpc3L0bH;
Rpc3L0bH.set_n_lept_cut(3); // >=
Rpc3L0bH.set_n_bjets_20_cut(0); // =
Rpc3L0bH.set_bjets_pT(20.);
Rpc3L0bH.set_njets_cut(4); // >=
Rpc3L0bH.set_jet_pT_cut(40.);
Rpc3L0bH.set_met_cut(200.); // >
Rpc3L0bH.set_meff_cut(1600.); // >
Rpc3L0bH.set_met_over_meff_cut(0);

yt_SR_definitions Rpc2L0bS;
Rpc2L0bS.set_n_lept_cut(2); // >=
Rpc2L0bS.set_n_bjets_20_cut(0); // =
Rpc2L0bS.set_bjets_pT(20.);
Rpc2L0bS.set_njets_cut(6); // >=
Rpc2L0bS.set_jet_pT_cut(25.);
Rpc2L0bS.set_met_cut(150.); // >
Rpc2L0bS.set_meff_cut(0.);
Rpc2L0bS.set_met_over_meff_cut(0.25); // >

yt_SR_definitions Rpc2L0bH;
Rpc2L0bH.set_n_lept_cut(2); // >=
Rpc2L0bH.set_n_bjets_20_cut(0); // =
Rpc2L0bH.set_bjets_pT(20.);
Rpc2L0bH.set_njets_cut(6); // >=
Rpc2L0bH.set_jet_pT_cut(40.);
Rpc2L0bH.set_met_cut(250.); // >
Rpc2L0bH.set_meff_cut(900.); // >
Rpc2L0bH.set_met_over_meff_cut(0.);

yt_SR_definitions Rpc2L1bS;
Rpc2L1bS.set_n_lept_cut(2); // >=
Rpc2L1bS.set_n_bjets_20_cut(1); // >=
Rpc2L1bS.set_bjets_pT(20.);
Rpc2L1bS.set_njets_cut(6); // >=
Rpc2L1bS.set_jet_pT_cut(25.);
Rpc2L1bS.set_met_cut(150.); // >
Rpc2L1bS.set_meff_cut(600.); // >
Rpc2L1bS.set_met_over_meff_cut(0.25); // >

yt_SR_definitions Rpc2L1bH;
Rpc2L1bH.set_n_lept_cut(2); // >=
Rpc2L1bH.set_n_bjets_20_cut(1); // >=
Rpc2L1bH.set_bjets_pT(20.);
Rpc2L1bH.set_njets_cut(6); // >=
Rpc2L1bH.set_jet_pT_cut(25.);
Rpc2L1bH.set_met_cut(250.); // >
Rpc2L1bH.set_meff_cut(0.);
Rpc2L1bH.set_met_over_meff_cut(0.2); // >

yt_SR_definitions Rpc2L2bS;
Rpc2L2bS.set_n_lept_cut(2); // >=
Rpc2L2bS.set_n_bjets_20_cut(3); // >=
Rpc2L2bS.set_bjets_pT(20.);
Rpc2L2bS.set_njets_cut(6); // >=
Rpc2L2bS.set_jet_pT_cut(25.);
Rpc2L2bS.set_met_cut(200.); // >
Rpc2L2bS.set_meff_cut(600.); // >
Rpc2L2bS.set_met_over_meff_cut(0.25); // >

yt_SR_definitions Rpc2L2bH;
Rpc2L2bH.set_n_lept_cut(2); // >=
Rpc2L2bH.set_n_bjets_20_cut(3); // >=
Rpc2L2bH.set_bjets_pT(20.);
Rpc2L2bH.set_njets_cut(6); // >=
Rpc2L2bH.set_jet_pT_cut(25.);
Rpc2L2bH.set_met_cut(0.);
Rpc2L2bH.set_meff_cut(1800.); // >
Rpc2L2bH.set_met_over_meff_cut(0.15); // >

//
// Definitions of the RPC signal regions
//
yt_SR_definitions Rpc2Lsoft2b;
Rpc2Lsoft2b.set_njets_cut(2); // >=
Rpc2Lsoft2b.set_n_bjets_20_cut(2); // >=
Rpc2Lsoft2b.set_bjets_pT(20.);
Rpc2Lsoft2b.set_njets_cut(6); // >=
Rpc2Lsoft2b.set_jet_pT_cut(25.);
Rpc2Lsoft2b.set_met_cut(200.); // >
Rpc2Lsoft2b.set_meff_cut(600.); // >
Rpc2Lsoft2b.set_met_over_meff_cut(0.25); // >
// 20 < pT(l1) < 100 GeV
// pT(l2) > 10 GeV

yt_SR_definitions Rpc2Lsoft1b;
Rpc2Lsoft1b.set_njets_cut(2); // >=
Rpc2Lsoft1b.set_n_bjets_20_cut(1); // >=
Rpc2Lsoft1b.set_bjets_pT(20.);
Rpc2Lsoft1b.set_njets_cut(6); // >=
Rpc2Lsoft1b.set_jet_pT_cut(25.);
Rpc2Lsoft1b.set_met_cut(100.); // >
Rpc2Lsoft1b.set_meff_cut(0.);
Rpc2Lsoft1b.set_met_over_meff_cut(0.3); // >
// 20 < pT(l1) < 100 GeV
// pT(l2) > 10 GeV

yt_SR_definitions Rpc3LSS1b;
Rpc3LSS1b.set_njets_cut(3); // >=
Rpc3LSS1b.set_n_bjets_20_cut(1); // >=
Rpc3LSS1b.set_bjets_pT(20.);
Rpc3LSS1b.set_njets_cut(0);
Rpc3LSS1b.set_jet_pT_cut(0.);
Rpc3LSS1b.set_met_cut(0.);
Rpc3LSS1b.set_meff_cut(0.);
Rpc3LSS1b.set_met_over_meff_cut(0.);
// veto 81 < mee < 101 GeV

yt_SR_definitions Rpc3L1bS;
Rpc3L1bS.set_njets_cut(3); // >=
Rpc3L1bS.set_n_bjets_20_cut(1); // >=
Rpc3L1bS.set_bjets_pT(20.);
Rpc3L1bS.set_njets_cut(4); // >=
Rpc3L1bS.set_jet_pT_cut(40.);
Rpc3L1bS.set_met_cut(200.); // >
Rpc3L1bS.set_meff_cut(600.); // >
Rpc3L1bS.set_met_over_meff_cut(0.);

yt_SR_definitions Rpc3L1bH;
Rpc3L1bH.set_njets_cut(3); // >=
Rpc3L1bH.set_n_bjets_20_cut(1); // >=
Rpc3L1bH.set_bjets_pT(20.);
Rpc3L1bH.set_njets_cut(4); // >=
Rpc3L1bH.set_jet_pT_cut(40.);
Rpc3L1bH.set_met_cut(200.); // >
Rpc3L1bH.set_meff_cut(1600.); // >
Rpc3L1bH.set_met_over_meff_cut(0.);

#endif // #ifndef YT_SR_DEFINITIONS_H
