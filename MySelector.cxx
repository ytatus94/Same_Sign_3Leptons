#define MYSELECTOR_CXX
// The class definition in AnaNtupSelector.h has been generated automatically
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
// Root > T->Process("AnaNtupSelector.C")
// Root > T->Process("AnaNtupSelector.C","some options")
// Root > T->Process("AnaNtupSelector.C+")
//

#include "MyPackages/MySelector.h"
#include "Root/Fill_and_Set.cxx"
#include "Root/useful_functions.cxx"
#include "Root/OverlapRemoval.cxx"
#include "GoodRunsLists/GoodRunsListSelectionTool.h"
//#include "CPAnalysisExamples/errorcheck.h"
#include <TH2.h>
#include <TStyle.h>
#include <string>

const char* cut_name[] = {
    "Cut 0: All events before derivations (DerivationStat_Weights)",
    "Cut 1: All events in derivation/ntuple",
    "Cut 2: GRL (for data only)",
    "Cut 3: Trigger",
    "Cut 4: Global flags (data only)",
    "Cut 5: Jet and muon cleaning",
    "Cut 6: Primary Vertex",
    "Cut 7: Cosmics veto",
    "Cut 8: ≥ 2 baseline leptons (>10 GeV)",
    "Cut 9: ≥ 2 signal leptons (>20 GeV)",
    // El-El channel
    "Cut 10: Channel selection (20, 20 GeV): el-el",
    "Cut 11: Trigger: el-el",
    "Cut 12: ml1l2 > 12 GeV: el-el",
    "Cut 13: ≥ 1 b jet (>20 GeV): el-el",
    "Cut 14: ≥ 4 jets (>50GeV): el-el",
    "Cut 15: Same sign leptons: el-el",
    "Cut 16: MET > 150 GeV: el-el",
    // El-Mu channel
    "Cut 10: Channel selection (20, 20 GeV): el-mu",
    "Cut 11: Trigger: el-mu",
    "Cut 12: ml1l2 > 12 GeV: el-mu",
    "Cut 13: ≥ 1 b jet (>20 GeV): el-mu",
    "Cut 14: ≥ 4 jets (>50GeV): el-mu",
    "Cut 15: Same sign leptons: el-mu",
    "Cut 16: MET > 150 GeV: el-mu",
    // Mu-Mu channel
    "Cut 10: Channel selection (20, 20 GeV): mu-mu",
    "Cut 11: Trigger: mu-mu",
    "Cut 12: ml1l2 > 12 GeV: mu-mu",
    "Cut 13: ≥ 1 b jet (>20 GeV): mu-mu",
    "Cut 14: ≥ 4 jets (>50GeV): mu-mu",
    "Cut 15: Same sign leptons: mu-mu",
    "Cut 16: MET > 150 GeV: mu-mu"
};

void MySelector::Begin(TTree * /*tree*/)
{
    // The Begin() function is called at the start of the query.
    // When running with PROOF Begin() is only called on the client.
    // The tree argument is deprecated (on PROOF 0 is passed).

    TString option = GetOption();

    // GRL
    // Using the information from http://atlasdqm.web.cern.ch/atlasdqm/grlgen/All_Good/data15_13TeV.periodA_DetStatus-v62-pro18_DQDefects-00-01-02_PHYS_StandardGRL_All_Good.xml#266904
    m_grl = new GoodRunsListSelectionTool("GoodRunsListSelectionTool");
    std::vector<std::string> vecStringGRL;
    vecStringGRL.push_back("/afs/cern.ch/work/y/yushen/private/Ximo/v12/cutflow_v12/MyPackages/data/data15_13TeV.periodA_DetStatus-v62-pro18_DQDefects-00-01-02_PHYS_StandardGRL_All_Good.xml");
    //CHECK( m_grl->setProperty("GoodRunsListVec", vecStringGRL) );
    //CHECK( m_grl->setProperty("PassThrough", false) );
    m_grl->setProperty("GoodRunsListVec", vecStringGRL);
    m_grl->setProperty("PassThrough", false);
    if ( !m_grl->initialize().isSuccess() ) {
        Error("In Begin()", "Fail to properly initialize the GRL. Exiting.");
        //return kTRUE;
    }

    hCutFlows = new TH1F("hCutFlows", "Cut Flows", 31, 0, 31);
    int number_of_bins = sizeof(cut_name) / sizeof( cut_name[0] );
    for (int i = 1; i <= number_of_bins; i++) {
        hCutFlows->GetXaxis()->SetBinLabel(i, cut_name[i - 1]);
    }
    fOutput->Add(hCutFlows);

/*
    // For baseline leptons
    h_mll_baseline_OS_ee    = new TH1F("h_mll_baseline_OS_ee",   "OS M_{ee}",     200, 0, 200);
    h_mll_baseline_OS_emu   = new TH1F("h_mll_baseline_OS_emu",  "OS M_{e#mu}",   200, 0, 200);
    h_mll_baseline_OS_mumu  = new TH1F("h_mll_baseline_OS_mumu", "OS M_{#mu#mu}", 200, 0, 200);
    h_mll_baseline_SS_ee    = new TH1F("h_mll_baseline_SS_ee",   "SS M_{ee}",     200, 0, 200);
    h_mll_baseline_SS_emu   = new TH1F("h_mll_baseline_SS_emu",  "SS M_{e#mu}",   200, 0, 200);
    h_mll_baseline_SS_mumu  = new TH1F("h_mll_baseline_SS_mumu", "SS M_{#mu#mu}", 200, 0, 200);
    fOutput->Add(h_mll_baseline_OS_ee);
    fOutput->Add(h_mll_baseline_OS_emu);
    fOutput->Add(h_mll_baseline_OS_mumu);
    fOutput->Add(h_mll_baseline_SS_ee);
    fOutput->Add(h_mll_baseline_SS_emu);
    fOutput->Add(h_mll_baseline_SS_mumu);
    
    h_ptvarcone20_pt_baseline_OS_ee    = new TH1F("h_ptvarcone20_pt_baseline_OS_ee",   "ptvarcone20/pt OS ee",     100, 0, 1);
    h_ptvarcone20_pt_baseline_OS_emu   = new TH1F("h_ptvarcone20_pt_baseline_OS_emu",  "ptvarcone20/pt OS e#mu",   100, 0, 1);
    h_ptvarcone20_pt_baseline_OS_mumu  = new TH1F("h_ptvarcone20_pt_baseline_OS_mumu", "ptvarcone20/pt OS #mu#mu", 100, 0, 1);
    h_ptvarcone20_pt_baseline_SS_ee    = new TH1F("h_ptvarcone20_pt_baseline_SS_ee",   "ptvarcone20/pt SS ee",     100, 0, 1);
    h_ptvarcone20_pt_baseline_SS_emu   = new TH1F("h_ptvarcone20_pt_baseline_SS_emu",  "ptvarcone20/pt SS e#mu",   100, 0, 1);
    h_ptvarcone20_pt_baseline_SS_mumu  = new TH1F("h_ptvarcone20_pt_baseline_SS_mumu", "ptvarcone20/pt SS #mu#mu", 100, 0, 1);
    fOutput->Add(h_ptvarcone20_pt_baseline_OS_ee);
    fOutput->Add(h_ptvarcone20_pt_baseline_OS_emu);
    fOutput->Add(h_ptvarcone20_pt_baseline_OS_mumu);
    fOutput->Add(h_ptvarcone20_pt_baseline_SS_ee);
    fOutput->Add(h_ptvarcone20_pt_baseline_SS_emu);
    fOutput->Add(h_ptvarcone20_pt_baseline_SS_mumu);
    
    h_ptvarcone30_pt_baseline_OS_ee   = new TH1F("h_ptvarcone30_pt_baseline_OS_ee",   "ptvarcone30/pt OS ee",     100, 0, 1);
    h_ptvarcone30_pt_baseline_OS_emu  = new TH1F("h_ptvarcone30_pt_baseline_OS_emu",  "ptvarcone30/pt OS e#mu",   100, 0, 1);
    h_ptvarcone30_pt_baseline_OS_mumu = new TH1F("h_ptvarcone30_pt_baseline_OS_mumu", "ptvarcone30/pt OS #mu#mu", 100, 0, 1);
    h_ptvarcone30_pt_baseline_SS_ee   = new TH1F("h_ptvarcone30_pt_baseline_SS_ee",   "ptvarcone30/pt SS ee",     100, 0, 1);
    h_ptvarcone30_pt_baseline_SS_emu  = new TH1F("h_ptvarcone30_pt_baseline_SS_emu",  "ptvarcone30/pt SS e#mu",   100, 0, 1);
    h_ptvarcone30_pt_baseline_SS_mumu = new TH1F("h_ptvarcone30_pt_baseline_SS_mumu", "ptvarcone30/pt SS #mu#mu", 100, 0, 1);
    fOutput->Add(h_ptvarcone30_pt_baseline_OS_ee);
    fOutput->Add(h_ptvarcone30_pt_baseline_OS_emu);
    fOutput->Add(h_ptvarcone30_pt_baseline_OS_mumu);
    fOutput->Add(h_ptvarcone30_pt_baseline_SS_ee);
    fOutput->Add(h_ptvarcone30_pt_baseline_SS_emu);
    fOutput->Add(h_ptvarcone30_pt_baseline_SS_mumu);
    
    h_ptvarcone40_pt_baseline_OS_ee   = new TH1F("h_ptvarcone40_pt_baseline_OS_ee",   "ptvarcone40/pt OS ee",     100, 0, 1);
    h_ptvarcone40_pt_baseline_OS_emu  = new TH1F("h_ptvarcone40_pt_baseline_OS_emu",  "ptvarcone40/pt OS e#mu",   100, 0, 1);
    h_ptvarcone40_pt_baseline_OS_mumu = new TH1F("h_ptvarcone40_pt_baseline_OS_mumu", "ptvarcone40/pt OS #mu#mu", 100, 0, 1);
    h_ptvarcone40_pt_baseline_SS_ee   = new TH1F("h_ptvarcone40_pt_baseline_SS_ee",   "ptvarcone40/pt SS ee",     100, 0, 1);
    h_ptvarcone40_pt_baseline_SS_emu  = new TH1F("h_ptvarcone40_pt_baseline_SS_emu",  "ptvarcone40/pt SS e#mu",   100, 0, 1);
    h_ptvarcone40_pt_baseline_SS_mumu = new TH1F("h_ptvarcone40_pt_baseline_SS_mumu", "ptvarcone40/pt SS #mu#mu", 100, 0, 1);
    fOutput->Add(h_ptvarcone40_pt_baseline_OS_ee);
    fOutput->Add(h_ptvarcone40_pt_baseline_OS_emu);
    fOutput->Add(h_ptvarcone40_pt_baseline_OS_mumu);
    fOutput->Add(h_ptvarcone40_pt_baseline_SS_ee);
    fOutput->Add(h_ptvarcone40_pt_baseline_SS_emu);
    fOutput->Add(h_ptvarcone40_pt_baseline_SS_mumu);
    
    h_topoetcone20_pt_baseline_OS_ee   = new TH1F("h_topoetcone20_pt_baseline_OS_ee",   "topoetcone20/pt OS ee",     100, 0, 1);
    h_topoetcone20_pt_baseline_OS_emu  = new TH1F("h_topoetcone20_pt_baseline_OS_emu",  "topoetcone20/pt OS e#mu",   100, 0, 1);
    h_topoetcone20_pt_baseline_OS_mumu = new TH1F("h_topoetcone20_pt_baseline_OS_mumu", "topoetcone20/pt OS #mu#mu", 100, 0, 1);
    h_topoetcone20_pt_baseline_SS_ee   = new TH1F("h_topoetcone20_pt_baseline_SS_ee",   "topoetcone20/pt SS ee",     100, 0, 1);
    h_topoetcone20_pt_baseline_SS_emu  = new TH1F("h_topoetcone20_pt_baseline_SS_emu",  "topoetcone20/pt SS e#mu",   100, 0, 1);
    h_topoetcone20_pt_baseline_SS_mumu = new TH1F("h_topoetcone20_pt_baseline_SS_mumu", "topoetcone20/pt SS #mu#mu", 100, 0, 1);
    fOutput->Add(h_topoetcone20_pt_baseline_OS_ee);
    fOutput->Add(h_topoetcone20_pt_baseline_OS_emu);
    fOutput->Add(h_topoetcone20_pt_baseline_OS_mumu);
    fOutput->Add(h_topoetcone20_pt_baseline_SS_ee);
    fOutput->Add(h_topoetcone20_pt_baseline_SS_emu);
    fOutput->Add(h_topoetcone20_pt_baseline_SS_mumu);
    
    h_topoetcone30_pt_baseline_OS_ee   = new TH1F("h_topoetcone30_pt_baseline_OS_ee",   "topoetcone30/pt OS ee",     100, 0, 1);
    h_topoetcone30_pt_baseline_OS_emu  = new TH1F("h_topoetcone30_pt_baseline_OS_emu",  "topoetcone30/pt OS e#mu",   100, 0, 1);
    h_topoetcone30_pt_baseline_OS_mumu = new TH1F("h_topoetcone30_pt_baseline_OS_mumu", "topoetcone30/pt OS #mu#mu", 100, 0, 1);
    h_topoetcone30_pt_baseline_SS_ee   = new TH1F("h_topoetcone30_pt_baseline_SS_ee",   "topoetcone30/pt SS ee",     100, 0, 1);
    h_topoetcone30_pt_baseline_SS_emu  = new TH1F("h_topoetcone30_pt_baseline_SS_emu",  "topoetcone30/pt SS e#mu",   100, 0, 1);
    h_topoetcone30_pt_baseline_SS_mumu = new TH1F("h_topoetcone30_pt_baseline_SS_mumu", "topoetcone30/pt SS #mu#mu", 100, 0, 1);
    fOutput->Add(h_topoetcone30_pt_baseline_OS_ee);
    fOutput->Add(h_topoetcone30_pt_baseline_OS_emu);
    fOutput->Add(h_topoetcone30_pt_baseline_OS_mumu);
    fOutput->Add(h_topoetcone30_pt_baseline_SS_ee);
    fOutput->Add(h_topoetcone30_pt_baseline_SS_emu);
    fOutput->Add(h_topoetcone30_pt_baseline_SS_mumu);
    
    h_topoetcone40_pt_baseline_OS_ee   = new TH1F("h_topoetcone40_pt_baseline_OS_ee",   "topoetcone40/pt OS ee",     100, 0, 1);
    h_topoetcone40_pt_baseline_OS_emu  = new TH1F("h_topoetcone40_pt_baseline_OS_emu",  "topoetcone40/pt OS e#mu",   100, 0, 1);
    h_topoetcone40_pt_baseline_OS_mumu = new TH1F("h_topoetcone40_pt_baseline_OS_mumu", "topoetcone40/pt OS #mu#mu", 100, 0, 1);
    h_topoetcone40_pt_baseline_SS_ee   = new TH1F("h_topoetcone40_pt_baseline_SS_ee",   "topoetcone40/pt OS ee",     100, 0, 1);
    h_topoetcone40_pt_baseline_SS_emu  = new TH1F("h_topoetcone40_pt_baseline_SS_emu",  "topoetcone40/pt OS e#mu",   100, 0, 1);
    h_topoetcone40_pt_baseline_SS_mumu = new TH1F("h_topoetcone40_pt_baseline_SS_mumu", "topoetcone40/pt OS #mu#mu", 100, 0, 1);
    fOutput->Add(h_topoetcone40_pt_baseline_OS_ee);
    fOutput->Add(h_topoetcone40_pt_baseline_OS_emu);
    fOutput->Add(h_topoetcone40_pt_baseline_OS_mumu);
    fOutput->Add(h_topoetcone40_pt_baseline_SS_ee);
    fOutput->Add(h_topoetcone40_pt_baseline_SS_emu);
    fOutput->Add(h_topoetcone40_pt_baseline_SS_mumu);
    
    // For signal leptons
    h_mll_signal_OS_ee    = new TH1F("h_mll_signal_OS_ee",   "OS M_{ee}",     200, 0, 200);
    h_mll_signal_OS_emu   = new TH1F("h_mll_signal_OS_emu",  "OS M_{e#mu}",   200, 0, 200);
    h_mll_signal_OS_mumu  = new TH1F("h_mll_signal_OS_mumu", "OS M_{#mu#mu}", 200, 0, 200);
    h_mll_signal_SS_ee    = new TH1F("h_mll_signal_SS_ee",   "SS M_{ee}",     200, 0, 200);
    h_mll_signal_SS_emu   = new TH1F("h_mll_signal_SS_emu",  "SS M_{e#mu}",   200, 0, 200);
    h_mll_signal_SS_mumu  = new TH1F("h_mll_signal_SS_mumu", "SS M_{#mu#mu}", 200, 0, 200);
    fOutput->Add(h_mll_signal_OS_ee);
    fOutput->Add(h_mll_signal_OS_emu);
    fOutput->Add(h_mll_signal_OS_mumu);
    fOutput->Add(h_mll_signal_SS_ee);
    fOutput->Add(h_mll_signal_SS_emu);
    fOutput->Add(h_mll_signal_SS_mumu);
    
    h_ptvarcone20_pt_signal_OS_ee    = new TH1F("h_ptvarcone20_pt_signal_OS_ee",   "ptvarcone20/pt OS ee",     100, 0, 1);
    h_ptvarcone20_pt_signal_OS_emu   = new TH1F("h_ptvarcone20_pt_signal_OS_emu",  "ptvarcone20/pt OS e#mu",   100, 0, 1);
    h_ptvarcone20_pt_signal_OS_mumu  = new TH1F("h_ptvarcone20_pt_signal_OS_mumu", "ptvarcone20/pt OS #mu#mu", 100, 0, 1);
    h_ptvarcone20_pt_signal_SS_ee    = new TH1F("h_ptvarcone20_pt_signal_SS_ee",   "ptvarcone20/pt SS ee",     100, 0, 1);
    h_ptvarcone20_pt_signal_SS_emu   = new TH1F("h_ptvarcone20_pt_signal_SS_emu",  "ptvarcone20/pt SS e#mu",   100, 0, 1);
    h_ptvarcone20_pt_signal_SS_mumu  = new TH1F("h_ptvarcone20_pt_signal_SS_mumu", "ptvarcone20/pt SS #mu#mu", 100, 0, 1);
    fOutput->Add(h_ptvarcone20_pt_signal_OS_ee);
    fOutput->Add(h_ptvarcone20_pt_signal_OS_emu);
    fOutput->Add(h_ptvarcone20_pt_signal_OS_mumu);
    fOutput->Add(h_ptvarcone20_pt_signal_SS_ee);
    fOutput->Add(h_ptvarcone20_pt_signal_SS_emu);
    fOutput->Add(h_ptvarcone20_pt_signal_SS_mumu);
    
    h_ptvarcone30_pt_signal_OS_ee   = new TH1F("h_ptvarcone30_pt_signal_OS_ee",   "ptvarcone30/pt OS ee",     100, 0, 1);
    h_ptvarcone30_pt_signal_OS_emu  = new TH1F("h_ptvarcone30_pt_signal_OS_emu",  "ptvarcone30/pt OS e#mu",   100, 0, 1);
    h_ptvarcone30_pt_signal_OS_mumu = new TH1F("h_ptvarcone30_pt_signal_OS_mumu", "ptvarcone30/pt OS #mu#mu", 100, 0, 1);
    h_ptvarcone30_pt_signal_SS_ee   = new TH1F("h_ptvarcone30_pt_signal_SS_ee",   "ptvarcone30/pt SS ee",     100, 0, 1);
    h_ptvarcone30_pt_signal_SS_emu  = new TH1F("h_ptvarcone30_pt_signal_SS_emu",  "ptvarcone30/pt SS e#mu",   100, 0, 1);
    h_ptvarcone30_pt_signal_SS_mumu = new TH1F("h_ptvarcone30_pt_signal_SS_mumu", "ptvarcone30/pt SS #mu#mu", 100, 0, 1);
    fOutput->Add(h_ptvarcone30_pt_signal_OS_ee);
    fOutput->Add(h_ptvarcone30_pt_signal_OS_emu);
    fOutput->Add(h_ptvarcone30_pt_signal_OS_mumu);
    fOutput->Add(h_ptvarcone30_pt_signal_SS_ee);
    fOutput->Add(h_ptvarcone30_pt_signal_SS_emu);
    fOutput->Add(h_ptvarcone30_pt_signal_SS_mumu);
    
    h_ptvarcone40_pt_signal_OS_ee   = new TH1F("h_ptvarcone40_pt_signal_OS_ee",   "ptvarcone40/pt OS ee",     100, 0, 1);
    h_ptvarcone40_pt_signal_OS_emu  = new TH1F("h_ptvarcone40_pt_signal_OS_emu",  "ptvarcone40/pt OS e#mu",   100, 0, 1);
    h_ptvarcone40_pt_signal_OS_mumu = new TH1F("h_ptvarcone40_pt_signal_OS_mumu", "ptvarcone40/pt OS #mu#mu", 100, 0, 1);
    h_ptvarcone40_pt_signal_SS_ee   = new TH1F("h_ptvarcone40_pt_signal_SS_ee",   "ptvarcone40/pt SS ee",     100, 0, 1);
    h_ptvarcone40_pt_signal_SS_emu  = new TH1F("h_ptvarcone40_pt_signal_SS_emu",  "ptvarcone40/pt SS e#mu",   100, 0, 1);
    h_ptvarcone40_pt_signal_SS_mumu = new TH1F("h_ptvarcone40_pt_signal_SS_mumu", "ptvarcone40/pt SS #mu#mu", 100, 0, 1);
    fOutput->Add(h_ptvarcone40_pt_signal_OS_ee);
    fOutput->Add(h_ptvarcone40_pt_signal_OS_emu);
    fOutput->Add(h_ptvarcone40_pt_signal_OS_mumu);
    fOutput->Add(h_ptvarcone40_pt_signal_SS_ee);
    fOutput->Add(h_ptvarcone40_pt_signal_SS_emu);
    fOutput->Add(h_ptvarcone40_pt_signal_SS_mumu);
    
    h_topoetcone20_pt_signal_OS_ee   = new TH1F("h_topoetcone20_pt_signal_OS_ee",   "topoetcone20/pt OS ee",     100, 0, 1);
    h_topoetcone20_pt_signal_OS_emu  = new TH1F("h_topoetcone20_pt_signal_OS_emu",  "topoetcone20/pt OS e#mu",   100, 0, 1);
    h_topoetcone20_pt_signal_OS_mumu = new TH1F("h_topoetcone20_pt_signal_OS_mumu", "topoetcone20/pt OS #mu#mu", 100, 0, 1);
    h_topoetcone20_pt_signal_SS_ee   = new TH1F("h_topoetcone20_pt_signal_SS_ee",   "topoetcone20/pt SS ee",     100, 0, 1);
    h_topoetcone20_pt_signal_SS_emu  = new TH1F("h_topoetcone20_pt_signal_SS_emu",  "topoetcone20/pt SS e#mu",   100, 0, 1);
    h_topoetcone20_pt_signal_SS_mumu = new TH1F("h_topoetcone20_pt_signal_SS_mumu", "topoetcone20/pt SS #mu#mu", 100, 0, 1);
    fOutput->Add(h_topoetcone20_pt_signal_OS_ee);
    fOutput->Add(h_topoetcone20_pt_signal_OS_emu);
    fOutput->Add(h_topoetcone20_pt_signal_OS_mumu);
    fOutput->Add(h_topoetcone20_pt_signal_SS_ee);
    fOutput->Add(h_topoetcone20_pt_signal_SS_emu);
    fOutput->Add(h_topoetcone20_pt_signal_SS_mumu);
    
    h_topoetcone30_pt_signal_OS_ee   = new TH1F("h_topoetcone30_pt_signal_OS_ee",   "topoetcone30/pt OS ee",     100, 0, 1);
    h_topoetcone30_pt_signal_OS_emu  = new TH1F("h_topoetcone30_pt_signal_OS_emu",  "topoetcone30/pt OS e#mu",   100, 0, 1);
    h_topoetcone30_pt_signal_OS_mumu = new TH1F("h_topoetcone30_pt_signal_OS_mumu", "topoetcone30/pt OS #mu#mu", 100, 0, 1);
    h_topoetcone30_pt_signal_SS_ee   = new TH1F("h_topoetcone30_pt_signal_SS_ee",   "topoetcone30/pt SS ee",     100, 0, 1);
    h_topoetcone30_pt_signal_SS_emu  = new TH1F("h_topoetcone30_pt_signal_SS_emu",  "topoetcone30/pt SS e#mu",   100, 0, 1);
    h_topoetcone30_pt_signal_SS_mumu = new TH1F("h_topoetcone30_pt_signal_SS_mumu", "topoetcone30/pt SS #mu#mu", 100, 0, 1);
    fOutput->Add(h_topoetcone30_pt_signal_OS_ee);
    fOutput->Add(h_topoetcone30_pt_signal_OS_emu);
    fOutput->Add(h_topoetcone30_pt_signal_OS_mumu);
    fOutput->Add(h_topoetcone30_pt_signal_SS_ee);
    fOutput->Add(h_topoetcone30_pt_signal_SS_emu);
    fOutput->Add(h_topoetcone30_pt_signal_SS_mumu);
    
    h_topoetcone40_pt_signal_OS_ee   = new TH1F("h_topoetcone40_pt_signal_OS_ee",   "topoetcone40/pt OS ee",     100, 0, 1);
    h_topoetcone40_pt_signal_OS_emu  = new TH1F("h_topoetcone40_pt_signal_OS_emu",  "topoetcone40/pt OS e#mu",   100, 0, 1);
    h_topoetcone40_pt_signal_OS_mumu = new TH1F("h_topoetcone40_pt_signal_OS_mumu", "topoetcone40/pt OS #mu#mu", 100, 0, 1);
    h_topoetcone40_pt_signal_SS_ee   = new TH1F("h_topoetcone40_pt_signal_SS_ee",   "topoetcone40/pt OS ee",     100, 0, 1);
    h_topoetcone40_pt_signal_SS_emu  = new TH1F("h_topoetcone40_pt_signal_SS_emu",  "topoetcone40/pt OS e#mu",   100, 0, 1);
    h_topoetcone40_pt_signal_SS_mumu = new TH1F("h_topoetcone40_pt_signal_SS_mumu", "topoetcone40/pt OS #mu#mu", 100, 0, 1);
    fOutput->Add(h_topoetcone40_pt_signal_OS_ee);
    fOutput->Add(h_topoetcone40_pt_signal_OS_emu);
    fOutput->Add(h_topoetcone40_pt_signal_OS_mumu);
    fOutput->Add(h_topoetcone40_pt_signal_SS_ee);
    fOutput->Add(h_topoetcone40_pt_signal_SS_emu);
    fOutput->Add(h_topoetcone40_pt_signal_SS_mumu);

    // For jets
    h_jet_multiplicities_pt20_OS_ee   = new TH1F("h_jet_multiplicities_pt20_OS_ee",   "Jet multiplicities pT>20GeV OS ee",     10, 0, 10);
    h_jet_multiplicities_pt20_OS_emu  = new TH1F("h_jet_multiplicities_pt20_OS_emu",  "Jet multiplicities pT>20GeV OS e#mu",   10, 0, 10);
    h_jet_multiplicities_pt20_OS_mumu = new TH1F("h_jet_multiplicities_pt20_OS_mumu", "Jet multiplicities pT>20GeV OS #mu#mu", 10, 0, 10);
    h_jet_multiplicities_pt20_SS_ee   = new TH1F("h_jet_multiplicities_pt20_SS_ee",   "Jet multiplicities pT>20GeV SS ee",     10, 0, 10);
    h_jet_multiplicities_pt20_SS_emu  = new TH1F("h_jet_multiplicities_pt20_SS_emu",  "Jet multiplicities pT>20GeV SS e#mu",   10, 0, 10);
    h_jet_multiplicities_pt20_SS_mumu = new TH1F("h_jet_multiplicities_pt20_SS_mumu", "Jet multiplicities pT>20GeV SS #mu#mu", 10, 0, 10);
    fOutput->Add(h_jet_multiplicities_pt20_OS_ee);
    fOutput->Add(h_jet_multiplicities_pt20_OS_emu);
    fOutput->Add(h_jet_multiplicities_pt20_OS_mumu);
    fOutput->Add(h_jet_multiplicities_pt20_SS_ee);
    fOutput->Add(h_jet_multiplicities_pt20_SS_emu);
    fOutput->Add(h_jet_multiplicities_pt20_SS_mumu);
    
    h_jet_multiplicities_pt50_OS_ee   = new TH1F("h_jet_multiplicities_pt50_OS_ee",   "Jet multiplicities pT>50GeV OS ee",     10, 0, 10);
    h_jet_multiplicities_pt50_OS_emu  = new TH1F("h_jet_multiplicities_pt50_OS_emu",  "Jet multiplicities pT>50GeV OS e#mu",   10, 0, 10);
    h_jet_multiplicities_pt50_OS_mumu = new TH1F("h_jet_multiplicities_pt50_OS_mumu", "Jet multiplicities pT>50GeV OS #mu#mu", 10, 0, 10);
    h_jet_multiplicities_pt50_SS_ee   = new TH1F("h_jet_multiplicities_pt50_SS_ee",   "Jet multiplicities pT>50GeV SS ee",     10, 0, 10);
    h_jet_multiplicities_pt50_SS_emu  = new TH1F("h_jet_multiplicities_pt50_SS_emu",  "Jet multiplicities pT>50GeV SS e#mu",   10, 0, 10);
    h_jet_multiplicities_pt50_SS_mumu = new TH1F("h_jet_multiplicities_pt50_SS_mumu", "Jet multiplicities pT>50GeV SS #mu#mu", 10, 0, 10);
    fOutput->Add(h_jet_multiplicities_pt50_OS_ee);
    fOutput->Add(h_jet_multiplicities_pt50_OS_emu);
    fOutput->Add(h_jet_multiplicities_pt50_OS_mumu);
    fOutput->Add(h_jet_multiplicities_pt50_SS_ee);
    fOutput->Add(h_jet_multiplicities_pt50_SS_emu);
    fOutput->Add(h_jet_multiplicities_pt50_SS_mumu);
    
    h_pt_1st_jets = new TH1F("h_pt_1st_jets", "Jet pT 1st", 20, 0, 200);
    h_pt_2nd_jets = new TH1F("h_pt_2nd_jets", "Jet pT 2nd", 20, 0, 200);
    h_pt_3rd_jets = new TH1F("h_pt_3rd_jets", "Jet pT 3rd", 20, 0, 200);
    h_pt_4th_jets = new TH1F("h_pt_4th_jets", "Jet pT 4th", 20, 0, 200);
	
    fOutput->Add(h_pt_1st_jets); 
    fOutput->Add(h_pt_2nd_jets); 
    fOutput->Add(h_pt_3rd_jets); 
    fOutput->Add(h_pt_4th_jets); 

    // For Etmiss (baseline)
    h_MET_baseline_OS_ee   = new TH1F("h_MET_baseline_OS_ee",   "E_{T}^{miss} OS ee",     20, 0,200);
    h_MET_baseline_OS_emu  = new TH1F("h_MET_baseline_OS_emu",  "E_{T}^{miss} OS e#mu",   20, 0,200);
    h_MET_baseline_OS_mumu = new TH1F("h_MET_baseline_OS_mumu", "E_{T}^{miss} OS #mu#mu", 20, 0,200);
    h_MET_baseline_SS_ee   = new TH1F("h_MET_baseline_SS_ee",   "E_{T}^{miss} SS ee",     20, 0,200);
    h_MET_baseline_SS_emu  = new TH1F("h_MET_baseline_SS_emu",  "E_{T}^{miss} SS e#mu",   20, 0,200);
    h_MET_baseline_SS_mumu = new TH1F("h_MET_baseline_SS_mumu", "E_{T}^{miss} SS #mu#mu", 20, 0,200);
    fOutput->Add(h_MET_baseline_OS_ee);
    fOutput->Add(h_MET_baseline_OS_emu);
    fOutput->Add(h_MET_baseline_OS_mumu);
    fOutput->Add(h_MET_baseline_SS_ee);
    fOutput->Add(h_MET_baseline_SS_emu);
    fOutput->Add(h_MET_baseline_SS_mumu);

    // For Etmiss (signal)
    h_MET_signal_OS_ee   = new TH1F("h_MET_signal_OS_ee",   "E_{T}^{miss} OS ee",     20, 0,200);
    h_MET_signal_OS_emu  = new TH1F("h_MET_signal_OS_emu",  "E_{T}^{miss} OS e#mu",   20, 0,200);
    h_MET_signal_OS_mumu = new TH1F("h_MET_signal_OS_mumu", "E_{T}^{miss} OS #mu#mu", 20, 0,200);
    h_MET_signal_SS_ee   = new TH1F("h_MET_signal_SS_ee",   "E_{T}^{miss} SS ee",     20, 0,200);
    h_MET_signal_SS_emu  = new TH1F("h_MET_signal_SS_emu",  "E_{T}^{miss} SS e#mu",   20, 0,200);
    h_MET_signal_SS_mumu = new TH1F("h_MET_signal_SS_mumu", "E_{T}^{miss} SS #mu#mu", 20, 0,200);
    fOutput->Add(h_MET_signal_OS_ee);
    fOutput->Add(h_MET_signal_OS_emu);
    fOutput->Add(h_MET_signal_OS_mumu);
    fOutput->Add(h_MET_signal_SS_ee);
    fOutput->Add(h_MET_signal_SS_emu);
    fOutput->Add(h_MET_signal_SS_mumu);

    // For meff (baseline)
    h_meff_baseline_OS_ee   = new TH1F("h_meff_baseline_OS_ee",   "Meff OS ee",   200,0, 1000);
    h_meff_baseline_OS_emu  = new TH1F("h_meff_baseline_OS_emu",  "Meff OS emu",  200,0, 1000);
    h_meff_baseline_OS_mumu = new TH1F("h_meff_baseline_OS_mumu", "Meff OS mumu", 200,0, 1000);
    h_meff_baseline_SS_ee   = new TH1F("h_meff_baseline_SS_ee",   "Meff OS ee",   200,0, 1000);
    h_meff_baseline_SS_emu  = new TH1F("h_meff_baseline_SS_emu",  "Meff OS emu",  200,0, 1000);
    h_meff_baseline_SS_mumu = new TH1F("h_meff_baseline_SS_mumu", "Meff OS mumu", 200,0, 1000);
    fOutput->Add(h_meff_baseline_OS_ee);
    fOutput->Add(h_meff_baseline_OS_emu);
    fOutput->Add(h_meff_baseline_OS_mumu);
    fOutput->Add(h_meff_baseline_SS_ee);
    fOutput->Add(h_meff_baseline_SS_emu);
    fOutput->Add(h_meff_baseline_SS_mumu);
    
    // For meff (signal)
    h_meff_signal_OS_ee   = new TH1F("h_meff_signal_OS_ee",   "Meff OS ee",   200,0, 1000);
    h_meff_signal_OS_emu  = new TH1F("h_meff_signal_OS_emu",  "Meff OS emu",  200,0, 1000);
    h_meff_signal_OS_mumu = new TH1F("h_meff_signal_OS_mumu", "Meff OS mumu", 200,0, 1000);
    h_meff_signal_SS_ee   = new TH1F("h_meff_signal_SS_ee",   "Meff OS ee",   200,0, 1000);
    h_meff_signal_SS_emu  = new TH1F("h_meff_signal_SS_emu",  "Meff OS emu",  200,0, 1000);
    h_meff_signal_SS_mumu = new TH1F("h_meff_signal_SS_mumu", "Meff OS mumu", 200,0, 1000);
    fOutput->Add(h_meff_signal_OS_ee);
    fOutput->Add(h_meff_signal_OS_emu);
    fOutput->Add(h_meff_signal_OS_mumu);
    fOutput->Add(h_meff_signal_SS_ee);
    fOutput->Add(h_meff_signal_SS_emu);
    fOutput->Add(h_meff_signal_SS_mumu);
*/    
}

void MySelector::SlaveBegin(TTree * /*tree*/)
{
    // The SlaveBegin() function is called after the Begin() function.
    // When running with PROOF SlaveBegin() is called on each slave server.
    // The tree argument is deprecated (on PROOF 0 is passed).

    TString option = GetOption();

}

Bool_t MySelector::Process(Long64_t entry)
{
    // The Process() function is called for each entry in the tree (or possibly
    // keyed object in the case of PROOF) to be processed. The entry argument
    // specifies which entry in the currently loaded tree is to be processed.
    // It can be passed to either AnaNtupSelector::GetEntry() or TBranch::GetEntry()
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

    // TH1F* h_w = (TH1F*)f->Get("DerivationStat_Weights");
    // SumW += h_w->GetBinContent(1);
    if (isData == 1)
	fAllEventsBeforeDerivations = 3651777; // data 266904
    if (isMC == 1)
	fAllEventsBeforeDerivations = 1997000; // MC ttbar
    hCutFlows->Fill(0); // Cut 0: All events before derivations (DerivationStat_Weights)

    AnaNtupSelector::Process(entry);

    vec_elec.clear();
    vec_muon.clear();
    vec_jets.clear();
    vec_lept.clear();

    vec_OR_elec.clear();
    vec_OR_muon.clear();
    vec_OR_jets.clear();
    vec_OR_lept.clear();

    vec_signal_elec.clear();
    vec_signal_muon.clear();
    vec_signal_jets.clear();
    vec_signal_lept.clear();

    Fill_electrons(RunNb,
                   NEl,
                   11, // particle id e- = 11
                   El_eta,
                   El_phi,
                   El_pT,
                   El_E,
                   El_charge,
                   El_sigd0,
                   El_z0pvtx,
                   El_d0pvtx,
                   El_SFwMedium,
                   El_SFwMediumLH,
                   El_SFwTight,
                   El_SFwTightLH,
                   El_isLooseLH,
                   El_isMediumLH,
                   El_isTightLH,
                   El_isLoose,
                   El_isMedium,
                   El_isTight,
                   El_ptcone20,
                   El_ptcone30,
                   El_ptcone40,
                   El_ptvarcone20,
                   El_ptvarcone30,
                   El_ptvarcone40,
                   El_topoetcone20,
                   El_topoetcone30,
                   El_topoetcone40,
                   El_passIsoVeryLooseTO,
                   El_passIsoVeryLoose,
                   El_passIsoLoose,
                   El_passIsoTight,
                   El_passIsoGrad,
                   El_passIsoGradCustom,
                   El_passIsoGradLoose);

    Fill_muons(RunNb,
               NMu,
               13, // particle id mu- = 13
               Mu_eta,
               Mu_phi,
               Mu_pT,
               Mu_SFw,
               Mu_charge,
               Mu_d0pvtx,
               Mu_sigd0,
               Mu_z0pvtx,
               Mu_isBad,
               Mu_isCosmic,
               Mu_ptcone20,
               Mu_ptcone30,
               Mu_ptcone40,
               Mu_ptvarcone20,
               Mu_ptvarcone30,
               Mu_ptvarcone40,
               Mu_topoetcone20,
               Mu_topoetcone30,
               Mu_topoetcone40,
               Mu_passIsoVeryLooseTO,
               Mu_passIsoVeryLoose,
               Mu_passIsoLoose,
               Mu_passIsoTight,
               Mu_passIsoGrad,
               Mu_passIsoGradCustom,
               Mu_passIsoGradLoose);

    Fill_jets(NJet,
              Jet_eta,
              Jet_phi,
              Jet_pT,
              Jet_E,
              Jet_quality,
              Jet_JVF,
              Jet_JVT,
              Jet_MV2c20,
              Jet_SFw,
              Jet_nTrk);

    fAllEventsInNtuple++;
    hCutFlows->Fill(1); // Cut 1: All events in derivation/ntuple

    // sort by descending Pt
    sort(vec_elec.begin(), vec_elec.end(), sort_descending_Pt<Electron>);
    sort(vec_muon.begin(), vec_muon.end(), sort_descending_Pt<Muon>);
    sort(vec_jets.begin(), vec_jets.end(), sort_descending_Pt<Jet>);

    // Set the baseline for electrons, muons, and jets.
    // Set the isSignal property for electrons and muons and set the isBjet property for jets.
    Set_baseline_and_signal_electrons();
    Set_baseline_and_signal_muons();
    Set_baseline_and_signal_jets();

    // Fill leptons into vector. Put the FillLeptons() function at here then the lepton in the
    // vector has correct baseline, flavor, and isSignal information.
    // And the passOR is 0.
    Fill_leptons(vec_elec, vec_muon);
    // Now sort leptons by descending Pt
    sort(vec_lept.begin(), vec_lept.end(), sort_descending_Pt<Lepton>);

    //----------------------------------//
    // Apply cuts
    //----------------------------------//

    if (isData)
        if ( !m_grl->passRunLB(RunNb, LB) ) return kTRUE; // GRL for data only
    fGRL++;
    hCutFlows->Fill(2); // Cut 2: GRL (for data only)

    if (L1_EM15 == false && L1_MU10 == false) return kTRUE;
    fTrigger++;
    hCutFlows->Fill(3); // Cut 3: Trigger

    if (DetError) return kTRUE; // DetError = 0 => pass
    fGlobalFlags++;
    hCutFlows->Fill(4); // Cut 4: Global flags (data only)

    // Bad muon event veto cut: veto any event where a baseline muon BEFORE overlap removal
    int badMuon = 0;
    for (auto & mu_itr : vec_muon) {
        if (mu_itr.get_isBad()) {
            mu_itr.set_baseline(0);
            badMuon++;
        }
    }
    if (badMuon > 0) return kTRUE;

    // Apply the overlap removal.
    double dRejet = 0.2, dRjetmu = 0.2, dRjete = 0.4, dRemu = 0.01, dRee = 0.05;
    OverlapRemoval(EventNumber, &vec_elec, &vec_muon, &vec_jets, dRejet, dRjetmu, dRjete, dRemu, dRee);

    int badJet = 0;
    for (auto & jet_itr : vec_jets) {
        if ((jet_itr.get_passOR() == true) &&
            (jet_itr.get_cleaning() == false)) {
            badJet++;
        }
    }
    if (badJet > 0) return kTRUE;

    // reject all jet with 2.8 < |eta| < 4.5
    for (auto & jet_itr : vec_jets) {
        if (fabs(jet_itr.get_eta()) > 2.8) {
            jet_itr.set_baseline(0);
        }
    }

    // JVT: reject jets with pT<50 GeV and |eta|<2.4 and JVT<0.64, after the overlap removal procedure and after jet cleaning
    for (auto & jet_itr : vec_jets) {
        if (jet_itr.get_passOR() == true &&
            jet_itr.get_baseline() == true) {
            if (jet_itr.get_pt() < 50000. &&
                fabs(jet_itr.get_eta()) < 2.4 &&
                jet_itr.get_JVT() < 0.64) {
                jet_itr.set_baseline(0);
            }
        }
    }

    fJetAndMuonCleaning++;
    hCutFlows->Fill(5); // Cut 5: Jet and muon cleaning

    if (PV_z == -999) return kTRUE; // In common ntuples: PV_z>-999 (-999 is the default value if no PV is found in the event).
    fPrimaryVertex++;
    hCutFlows->Fill(6); // Cut 6: Primary Vertex

    // Cosmics rejection cuts: these cuts should be applied AFTER overlap removal to avoid removing muons from heavy flavor decays.
    int cosmicMuon = 0;
    for (auto & mu_itr : vec_muon) {
	if (!mu_itr.get_passOR()) continue;	
        if (mu_itr.get_isCosmic() == true &&
            mu_itr.get_passOR() == true) {
            mu_itr.set_baseline(0);
            mu_itr.set_passOR(0);
            cosmicMuon++;
        }
    }
    if (cosmicMuon > 0) return kTRUE;
    fCosmicsVeto++;
    hCutFlows->Fill(7); // Cut 7: Cosmics veto

    // Fill OR electrons, OR muons, OR jets, and OR leptons into vectors.
    Fill_baseline_electrons(vec_elec);
    Fill_baseline_muons(vec_muon);
    Fill_baseline_jets(vec_jets);
    Fill_baseline_leptons(vec_elec, vec_muon);
    // Now sort leptons by descending Pt
    sort(vec_OR_lept.begin(), vec_OR_lept.end(), sort_descending_Pt<Lepton>);

    // Fill signal electrons, signal muons, signal jets, and signal leptons into vectors.
    Fill_signal_electrons(vec_elec);
    Fill_signal_muons(vec_muon);
    Fill_signal_jets(vec_jets);
    Fill_signal_leptons(vec_signal_elec, vec_signal_muon);
    // Now sort leptons by descending Pt
    sort(vec_signal_lept.begin(), vec_signal_lept.end(), sort_descending_Pt<Lepton>);

    int Nlep = 0, Nel = 0, Nmu = 0;
    for (auto & lep_itr : vec_OR_lept) {
        Nlep++;
        if (lep_itr.get_flavor() == 11) Nel++;
        if (lep_itr.get_flavor() == 13) Nmu++;
    }
    if (Nlep >= 2) {
        fAtLeastTwoBaselineLeptons++;
        hCutFlows->Fill(8); // Cut 8: ≥ 2 baseline leptons (>10 GeV)
    }

    int Nlep_sig = 0, Nel_sig = 0, Nmu_sig = 0;
    int Nlep_sig_pt20 = 0, Nel_sig_pt20 = 0, Nmu_sig_pt20 = 0;
    int same_sign = 1, same_sign_e = 1, same_sign_mu = 1;
    TLorentzVector lep_tlv, el_tlv, mu_tlv;
    
    for (auto & lep_itr : vec_signal_lept) {
        Nlep_sig++;
        if (lep_itr.get_pt() >= 20000.) Nlep_sig_pt20++;
        lep_tlv = lep_tlv + lep_itr.get_TLV();
        
        if (lep_itr.get_flavor() == 11) {
            Nel_sig++;
            if (lep_itr.get_pt() >= 20000.) Nel_sig_pt20++;
            el_tlv = el_tlv + lep_itr.get_TLV();
            same_sign_e = same_sign_e * lep_itr.get_charge();
        }
        
        if (lep_itr.get_flavor() == 13) {
            Nmu_sig++;
            if (lep_itr.get_pt() >= 20000.) Nmu_sig_pt20++;
            mu_tlv = mu_tlv + lep_itr.get_TLV();
            same_sign_mu = same_sign_mu * lep_itr.get_charge();
        }
        
        same_sign = same_sign_e * same_sign_mu;
    }

    int Nbjet_pt20 = 0, Njet_pt20 = 0, Njet_pt50 = 0;
    for (auto & jet_itr : vec_OR_jets) {
        if (jet_itr.get_quality() == 1) continue; // 1=bad jet from SUSYTools IsGoodJet
        if (jet_itr.get_isBjet()) Nbjet_pt20++;
        if (jet_itr.get_pt() > 20000.) Njet_pt20++;
        if (jet_itr.get_pt() > 50000.) Njet_pt50++;
    }

    //----------------------------------//

    if (Nlep_sig_pt20 >= 2) {
        if (Nlep_sig_pt20 == 2 && same_sign == 1) { // a same-sign pair within the signal leptons in the event
            fAtLeastTwoSignalLeptons++;
            hCutFlows->Fill(9); // Cut 9: ≥ 2 signal leptons (>20 GeV)
	}
        else {
            fAtLeastTwoSignalLeptons++;
            hCutFlows->Fill(9); // Cut 9: ≥ 2 signal leptons (>20 GeV)
        }
    }

/*
    if ( (Nel_sig_pt20 + Nmu_sig_pt20) == 2) {
        double ht = calculate_Ht(vec_signal_lept, vec_signal_jets);
        double meff = calculate_Meff(ht, Etmiss_TST_Et);
    }
*/
    //----------------------------------//

    TLorentzVector ml1l2_tlv = el_tlv + mu_tlv;
    int channel_selection = 0; // 1: el-el, 2: el-mu, 3: mu-mu

    // Channel separation [20,20]
    if (Nlep_sig_pt20 >= 2) {
	    bool same_sign_pair = false;
        
	    for (int i = 0; i < Nlep_sig - 1; i++) {
            int i_charge = vec_signal_lept.at(i).get_charge();
            int i_flavor = vec_signal_lept.at(i).get_flavor();

            for (int j = i + 1; j < Nlep_sig; j++) {
                int j_charge = vec_signal_lept.at(j).get_charge();
                int j_flavor = vec_signal_lept.at(j).get_flavor();
                if (i_charge * j_charge == 1) {
                    same_sign_pair = true;
                    
                    if (i_flavor == 13 && j_flavor == 13)
                        channel_selection = 3;
                    else if (i_flavor == 13 || j_flavor == 13)
                        channel_selection = 2;
                    else
                        channel_selection = 1;
                }
            }
            if (same_sign_pair)
                break;
	    }
    }
    
    switch (channel_selection) {
        // Channel separation [20,20]: El-El channel
        case 1:
            //cout << "ee: " << EventNumber << endl;
            fChannelSelection_elel++;
            hCutFlows->Fill(10); // Cut 10: Channel selection (20, 20 GeV): el-el
            
            if (isMC) {
                if (Nbjet_pt20 >= 1) {
                    fAtLeastOneBJet_elel++;
                    hCutFlows->Fill(13); // Cut 13: ≥ 1 b jet (>20 GeV): el-el
                
                    if (Njet_pt50 >= 4) {
                        fAtLeastFourJets_elel++;
                        hCutFlows->Fill(14); // Cut 14: ≥ 4 jets (>50GeV): el-el
                    
                        if (Etmiss_TST_Et > 150000.) {
                            fMET_elel++;
                            hCutFlows->Fill(16); // Cut 16: MET > 150 GeV: el-el
                        }
                    }
                }
            }
            
            if (isData) {
                fTrigger_elel++;
                hCutFlows->Fill(11); // Cut 11: Trigger: el-el
                
                if (ml1l2_tlv.M() > 12000.) {
                    fMl1l2_elel++;
                    hCutFlows->Fill(12); // Cut 12: ml1l2 > 12 GeV: el-el
                    
                    if (Nbjet_pt20 >= 1) {
                        fAtLeastOneBJet_elel++;
                        hCutFlows->Fill(13); // Cut 13: ≥ 1 b jet (>20 GeV): el-el
                        
                        if (Njet_pt50 >= 4) {
                            fAtLeastFourJets_elel++;
                            hCutFlows->Fill(14); // Cut 14: ≥ 4 jets (>50GeV): el-el
                            
                            if (same_sign == 1) {
                                fSameSign_elel++;
                                hCutFlows->Fill(15); // Cut 15: Same sign leptons: el-el
                                
                                if (Etmiss_TST_Et > 150000.) {
                                    fMET_elel++;
                                    hCutFlows->Fill(16); // Cut 16: MET > 150 GeV: el-el
                                }
                            }
                        }
                    }
                }
            }
            
            break;
        // Channel separation [20,20]: El-MU channel
        case 2:
            //cout << "em: " << EventNumber << endl;
            fChannelSelection_elmu++;
            hCutFlows->Fill(17); // Cut 10: Channel selection (20, 20 GeV): el-mu
            
            if (isMC) {
                if (Nbjet_pt20 >= 1) {
                    fAtLeastOneBJet_elmu++;
                    hCutFlows->Fill(20); // Cut 13: ≥ 1 b jet (>20 GeV): el-mu
                
                    if (Njet_pt50 >= 4) {
                        fAtLeastFourJets_elmu++;
                        hCutFlows->Fill(21); // Cut 14: ≥ 4 jets (>50GeV): el-mu
                    
                        if (Etmiss_TST_Et > 150000.) {
                            fMET_elmu++;
                            hCutFlows->Fill(23); // Cut 16: MET > 150 GeV: el-mu
                        }
                    }
                }
            }
            
            if (isData) {
                fTrigger_elmu++;
                hCutFlows->Fill(18); // Cut 11: Trigger: el-mu
                
                if (ml1l2_tlv.M() > 12000.) {
                    fMl1l2_elmu++;
                    hCutFlows->Fill(19); // Cut 12: ml1l2 > 12 GeV: el-mu
                    
                    if (Nbjet_pt20 >= 1) {
                        fAtLeastOneBJet_elmu++;
                        hCutFlows->Fill(20); // Cut 13: ≥ 1 b jet (>20 GeV): el-mu
                        
                        if (Njet_pt50 >= 4) {
                            fAtLeastFourJets_elmu++;
                            hCutFlows->Fill(21); // Cut 14: ≥ 4 jets (>50GeV): el-mu
                            
                            if (same_sign == 1) {
                                fSameSign_elmu++;
                                hCutFlows->Fill(22); // Cut 15: Same sign leptons: el-mu
                                
                                if (Etmiss_TST_Et > 150000.) {
                                    fMET_elmu++;
                                    hCutFlows->Fill(23); // Cut 16: MET > 150 GeV: el-mu
                                }
                            }
                        }
                    }
                }
            }
            
            break;
        // Channel separation [20,20]: MU-MU channel
        case 3:
            //cout << "mm: " << EventNumber << endl;
            fChannelSelection_mumu++;
            hCutFlows->Fill(24); // Cut 10: Channel selection (20, 20 GeV): mu-mu
            
            if (isMC) {
                if (Nbjet_pt20 >= 1) {
                    fAtLeastOneBJet_mumu++;
                    hCutFlows->Fill(27); // Cut 13: ≥ 1 b jet (>20 GeV): mu-mu
                
                    if (Njet_pt50 >= 4) {
                        fAtLeastFourJets_mumu++;
                        hCutFlows->Fill(28); // Cut 14: ≥ 4 jets (>50GeV): mu-mu
                    
                        if (Etmiss_TST_Et > 150000.) {
                            fMET_mumu++;
                            hCutFlows->Fill(30); // Cut 16: MET > 150 GeV: mu-mu
                        }
                    }
                }
            }
            
            if (isData) {
                fTrigger_mumu++;
                hCutFlows->Fill(25); // Cut 11: Trigger: mu-mu
                
                if (ml1l2_tlv.M() > 12000.) {
                    fMl1l2_mumu++;
                    hCutFlows->Fill(26); // Cut 12: ml1l2 > 12 GeV: mu-mu
                    
                    if (Nbjet_pt20 >= 1) {
                        fAtLeastOneBJet_mumu++;
                        hCutFlows->Fill(27); // Cut 13: ≥ 1 b jet (>20 GeV): mu-mu
                        
                        if (Njet_pt50 >= 4) {
                            fAtLeastFourJets_mumu++;
                            hCutFlows->Fill(28); // Cut 14: ≥ 4 jets (>50GeV): mu-mu
                            
                            if (same_sign == 1) {
                                fSameSign_mumu++;
                                hCutFlows->Fill(29); // Cut 15: Same sign leptons: mu-mu
                                
                                if (Etmiss_TST_Et > 150000.) {
                                    fMET_mumu++;
                                    hCutFlows->Fill(30); // Cut 16: MET > 150 GeV: mu-mu
                                }
                            }
                        }
                    }
                }
            }
            
            break;
        default:
            break;
    }

/*	     
    // Channel separation [20,20]: El-El channel
    if (Nel_sig_pt20 == 2 && Nmu_sig_pt20 == 0) {
        fChannelSelection_elel++;
        hCutFlows->Fill(10); // Cut 10: Channel selection (20, 20 GeV): el-el
        
        fTrigger_elel++;
        hCutFlows->Fill(11); // Cut 11: Trigger: el-el
        
        if (ml1l2_tlv.M() > 12000.) {
            fMl1l2_elel++;
            hCutFlows->Fill(12); // Cut 12: ml1l2 > 12 GeV: el-el
            
            if (Nbjet_pt20 >= 1) {
                fAtLeastOneBJet_elel++;
                hCutFlows->Fill(13); // Cut 13: ≥ 1 b jet (>20 GeV): el-el
                
                if (Njet_pt50 >= 4) {
                    fAtLeastFourJets_elel++;
                    hCutFlows->Fill(14); // Cut 14: ≥ 4 jets (>50GeV): el-el
                    
                    if (same_sign == 1) {
                        fSameSign_elel++;
                        hCutFlows->Fill(15); // Cut 15: Same sign leptons: el-el

                        if (Etmiss_TST_Et > 150000.) {
                            fMET_elel++;
                            hCutFlows->Fill(16); // Cut 16: MET > 150 GeV: el-el
                        }
                    }
                }
            }
        }
    }

    // Channel separation [20,20]: El-MU channel
    if (Nel_sig_pt20 == 1 && Nmu_sig_pt20 == 1) {
        fChannelSelection_elmu++;
        hCutFlows->Fill(17); // Cut 10: Channel selection (20, 20 GeV): el-mu
        
        fTrigger_elmu++;
        hCutFlows->Fill(18); // Cut 11: Trigger: el-mu
        
        if (ml1l2_tlv.M() > 12000.) {
            fMl1l2_elmu++;
            hCutFlows->Fill(19); // Cut 12: ml1l2 > 12 GeV: el-mu
            
            if (Nbjet_pt20 >= 1) {
                fAtLeastOneBJet_elmu++;
                hCutFlows->Fill(20); // Cut 13: ≥ 1 b jet (>20 GeV): el-mu
                
                if (Njet_pt50 >= 4) {
                    fAtLeastFourJets_elmu++;
                    hCutFlows->Fill(21); // Cut 14: ≥ 4 jets (>50GeV): el-mu
                    
                    if (same_sign == 1) {
                        fSameSign_elmu++;
                        hCutFlows->Fill(22); // Cut 15: Same sign leptons: el-mu

                        if (Etmiss_TST_Et > 150000.) {
                            fMET_elmu++;
                            hCutFlows->Fill(23); // Cut 16: MET > 150 GeV: el-mu
                        }
                    }
                }
            }
        }
    }

    // Channel separation [20,20]: MU-MU channel
   if (Nel_sig_pt20 == 0 && Nmu_sig_pt20 == 2) {
        fChannelSelection_mumu++;
        hCutFlows->Fill(24); // Cut 10: Channel selection (20, 20 GeV): mu-mu
        
        fTrigger_mumu++;
        hCutFlows->Fill(25); // Cut 11: Trigger: mu-mu
        
        if (ml1l2_tlv.M() > 12000.) {
            fMl1l2_mumu++;
            hCutFlows->Fill(26); // Cut 12: ml1l2 > 12 GeV: mu-mu
            
            if (Nbjet_pt20 >= 1) {
                fAtLeastOneBJet_mumu++;
                hCutFlows->Fill(27); // Cut 13: ≥ 1 b jet (>20 GeV): mu-mu
                
                if (Njet_pt50 >= 4) {
                    fAtLeastFourJets_mumu++;
                    hCutFlows->Fill(28); // Cut 14: ≥ 4 jets (>50GeV): mu-mu
                    
                    if (same_sign == 1) {
                        fSameSign_mumu++;
                        hCutFlows->Fill(29); // Cut 15: Same sign leptons: mu-mu

                        if (Etmiss_TST_Et > 150000.) {
                            fMET_mumu++;
                            hCutFlows->Fill(30); // Cut 16: MET > 150 GeV: mu-mu
                        }
                    }
                }
            }
        }
    }
*/

    return kTRUE;
}

void MySelector::SlaveTerminate()
{
    // The SlaveTerminate() function is called after all entries or objects
    // have been processed. When running with PROOF SlaveTerminate() is called
    // on each slave server.
    
}

void MySelector::Terminate()
{
    // The Terminate() function is the last function to be called during
    // a query. It always runs on the client, it can be used to present
    // the results graphically or save the results to file.
    
    delete m_grl;

    TFile *output_file = new TFile("results.root", "recreate");
    fOutput->Write();
    output_file->Close();

    cout << setw(20) << left << cut_name[0]  << " = " << setw(10) << fAllEventsBeforeDerivations << endl;
    cout << setw(20) << left << cut_name[1]  << " = " << setw(10) << fAllEventsInNtuple << endl;
    cout << setw(20) << left << cut_name[2]  << " = " << setw(10) << fGRL << endl;
    cout << setw(20) << left << cut_name[3]  << " = " << setw(10) << fTrigger << endl;
    cout << setw(20) << left << cut_name[4]  << " = " << setw(10) << fGlobalFlags << endl;
    cout << setw(20) << left << cut_name[5]  << " = " << setw(10) << fJetAndMuonCleaning << endl;
    cout << setw(20) << left << cut_name[6]  << " = " << setw(10) << fPrimaryVertex << endl;
    cout << setw(20) << left << cut_name[7]  << " = " << setw(10) << fCosmicsVeto << endl;
    cout << setw(20) << left << cut_name[8]  << " = " << setw(10) << fAtLeastTwoBaselineLeptons << endl;
    cout << setw(20) << left << cut_name[9]  << " = " << setw(10) << fAtLeastTwoSignalLeptons << endl;
    // El-El channel
    cout << "**********" << endl;
    cout << setw(20) << left << cut_name[10] << " = " << setw(10) << fChannelSelection_elel << endl;
    cout << setw(20) << left << cut_name[11] << " = " << setw(10) << fTrigger_elel << endl;
    cout << setw(20) << left << cut_name[12] << " = " << setw(10) << fMl1l2_elel << endl;
    cout << setw(20) << left << cut_name[13] << " = " << setw(10) << fAtLeastOneBJet_elel << endl;
    cout << setw(20) << left << cut_name[14] << " = " << setw(10) << fAtLeastFourJets_elel << endl;
    cout << setw(20) << left << cut_name[15] << " = " << setw(10) << fSameSign_elel << endl;
    cout << setw(20) << left << cut_name[16] << " = " << setw(10) << fMET_elel << endl;
    // El-Mu channel
    cout << "**********" << endl;
    cout << setw(20) << left << cut_name[17] << " = " << setw(10) << fChannelSelection_elmu << endl;
    cout << setw(20) << left << cut_name[18] << " = " << setw(10) << fTrigger_elmu << endl;
    cout << setw(20) << left << cut_name[19] << " = " << setw(10) << fMl1l2_elmu << endl;
    cout << setw(20) << left << cut_name[20] << " = " << setw(10) << fAtLeastOneBJet_elmu << endl;
    cout << setw(20) << left << cut_name[21] << " = " << setw(10) << fAtLeastFourJets_elmu << endl;
    cout << setw(20) << left << cut_name[22] << " = " << setw(10) << fSameSign_elmu << endl;
    cout << setw(20) << left << cut_name[23] << " = " << setw(10) << fMET_elmu << endl;
    // Mu-Mu channel
    cout << "**********" << endl;
    cout << setw(20) << left << cut_name[24] << " = " << setw(10) << fChannelSelection_mumu << endl;
    cout << setw(20) << left << cut_name[25] << " = " << setw(10) << fTrigger_mumu << endl;
    cout << setw(20) << left << cut_name[26] << " = " << setw(10) << fMl1l2_mumu << endl;
    cout << setw(20) << left << cut_name[27] << " = " << setw(10) << fAtLeastOneBJet_mumu << endl;
    cout << setw(20) << left << cut_name[28] << " = " << setw(10) << fAtLeastFourJets_mumu << endl;
    cout << setw(20) << left << cut_name[29] << " = " << setw(10) << fSameSign_mumu << endl;
    cout << setw(20) << left << cut_name[30] << " = " << setw(10) << fMET_mumu << endl;
}
