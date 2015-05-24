// Steering macro
#include "TROOT.h"
#include "TChain.h"
#include "TInterpreter.h"
 
void run() 
{
    gROOT->Reset();
    gInterpreter->EnableAutoLoading();
    //gROOT->ProcessLine(".L ");
    gROOT->ProcessLine(".! rm -f result.root");
    TChain *fChain = new TChain("AnaNtup", "chain");
    // for testing
/*
    fChain->Add("../user.jpoveda.t26_v04_p1872.204533.Herwigpp_UEEE4_CTEQ6L1_Gtt_G1000_T5000_L100_output.root.24717794/user.jpoveda.5286937._000001.output.root");
    //fChain->Process("./AnaNtupV04Selector.C+");
*/

    // ttbar
    fChain->Add("user.jpoveda.5399374._000001.output.root");
    fChain->Add("user.jpoveda.5399374._000002.output.root");
    fChain->Add("user.jpoveda.5399374._000003.output.root");
    fChain->Add("user.jpoveda.5399374._000004.output.root");
    fChain->Add("user.jpoveda.5399374._000005.output.root");
    fChain->Add("user.jpoveda.5399374._000006.output.root");

    fChain->Process("./AnaNtupBunchSapcing.C+");
}

void make_plot(TH1 *hName1, const char* xTitle, const char* yTitle, Color_t lineColor1, Width_t lineWidth1,
               TH1 *hName2, Color_t lineColor2, Width_t lineWidth2,
               Int_t logY, string fileName)
{
    gROOT->Reset();
    string command = ".! rm -f " + fileName;
    gROOT->ProcessLine(command.c_str());
    hName1->SetXTitle(xTitle);
    hName1->SetYTitle(yTitle);
    hName1->SetLineColor(lineColor1);
    hName1->SetLineWidth(lineWidth1);
    hName1->Draw();

    hName2->SetLineColor(lineColor2);
    hName2->SetLineWidth(lineWidth2);
    hName2->Draw("same");

    gPad->SetLogy(logY);
    gPad->SaveAs(fileName.c_str());
}

void root_plots()
{
    TFile *f = new TFile("results.root");

    // jets
    make_plot(hCut1_Njet, "nJet", "counts", 4, 2,
              hCut5_Njet, 2, 2,
              1, "nJet.pdf");
    make_plot(hCut1_Jet_Pt, "jet Pt (MeV)", "counts", 4, 2,
              hCut5_Jet_Pt, 2, 2,
              1, "Jet_Pt.pdf");
    make_plot(hCut1_Jet_Eta, "jet Eta", "counts", 4, 2,
              hCut5_Jet_Eta, 2, 2,
              1, "Jet_Eta.pdf");
    make_plot(hCut1_Jet_Phi, "jet Phi", "counts", 4, 2,
              hCut5_Jet_Phi, 2, 2,
              0, "Jet_Phi.pdf");

    // electrons
    make_plot(hCut1_Nelec, "nElec", "counts", 4, 2, 
              hCut5_Nelec, 2, 2,
              1, "nElec.pdf");
    make_plot(hCut1_Elec_Pt, "Elec Pt (MeV)", "counts", 4, 2,
              hCut5_Elec_Pt, 2, 2,
              1, "Elec_Pt.pdf");
    make_plot(hCut1_Elec_Eta, "Elec Eta", "counts", 4, 2,
              hCut5_Elec_Eta, 2, 2,
              1, "Elec_Eta.pdf");
    make_plot(hCut1_Elec_Phi, "Elec Phi", "counts", 4, 2,
              hCut5_Elec_Phi, 2, 2,
              1, "Elec_Phi.pdf");

    // muons
    make_plot(hCut1_Nmuon, "nMuon", "counts", 4, 2,
              hCut5_Nmuon, 2, 2,
              1, "nMuon.pdf");
    make_plot(hCut1_Muon_Pt, "Muon Pt (MeV)", "counts", 4, 2,
              hCut5_Muon_Pt, 2, 2,
              1, "Muon_Pt.pdf");
    make_plot(hCut1_Muon_Eta, "Muon Eta", "counts", 4, 2,
              hCut5_Muon_Eta, 2, 2,
              1, "Muon_Eta.pdf");
    make_plot(hCut1_Muon_Phi, "Muon Phi", "counts", 4, 2,
              hCut5_Muon_Phi, 2, 2,
              1, "Muon_Phi.pdf");

    // leptons
    make_plot(hCut1_Nlep, "nLep", "counts", 4, 2,
              hCut5_Nlep, 2, 2,
              1, "nLep.pdf");
    make_plot(hCut1_lep_Pt, "lep Pt (MeV)", "counts", 4, 2,
              hCut5_lep_Pt, 2, 2,
              1, "lep_Pt.pdf");

    // missing Et
    make_plot(hCut1_MET, "MET (MeV)", "counts", 4, 2,
              hCut5_MET, 2, 2,
              1, "MET.pdf");

    // meff
    make_plot(hCut1_Meff, "Meff (MeV)", "counts", 4, 2,
              hCut5_Meff, 2, 2,
              1, "Meff.pdf");

    make_plot(hCut1_Nbjet, "nBjet", "counts", 4, 2,
              hCut5_Nbjet, 2, 2,
              1, "nBjet.pdf");
}
