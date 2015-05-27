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
/*
    // ttbar
    // 50ns
    fChain->Add("user.jpoveda.5399374._000001.output.root");
    fChain->Add("user.jpoveda.5399374._000002.output.root");
    fChain->Add("user.jpoveda.5399374._000003.output.root");
    fChain->Add("user.jpoveda.5399374._000004.output.root");
    fChain->Add("user.jpoveda.5399374._000005.output.root");
    fChain->Add("user.jpoveda.5399374._000006.output.root");

    // 25ns
    fChain->Add("user.jpoveda.5283774._000001.output.root");
    fChain->Add("user.jpoveda.5283774._000002.output.root");
    fChain->Add("user.jpoveda.5283774._000003.output.root");
    fChain->Add("user.jpoveda.5283774._000004.output.root");
    fChain->Add("user.jpoveda.5283774._000005.output.root");
    fChain->Add("user.jpoveda.5283774._000006.output.root");
    fChain->Add("user.jpoveda.5283774._000007.output.root");
    fChain->Add("user.jpoveda.5283774._000008.output.root");
*/
    // G1000_T5000_L100
    // 50ns
    //fChain->Add("user.jpoveda.5399484._000001.output.root");
    // 25ns
    //fChain->Add("user.jpoveda.5286937._000001.output.root");

    // G1300_T5000_L700
    // 50ns
    //fChain->Add("user.jpoveda.5399493._000001.output.root");
    // 25ns
    fChain->Add("user.jpoveda.5286954._000001.output.root");
    
    fChain->Process("./AnaNtupBunchSapcing.C+");
}

// Draw two histograms in the same plot
void make_plot(TH1 *hName1, const char* xTitle, const char* yTitle, Color_t lineColor1, Width_t lineWidth1,
               TH1 *hName2, Color_t lineColor2, Width_t lineWidth2,
               Int_t logY, string outputFileName)
{
    gROOT->Reset();
    string command = ".! rm -f " + outputFileName;
    gROOT->ProcessLine(command.c_str());
    hName1->SetXTitle(xTitle);
    hName1->SetYTitle(yTitle);
    if (logY) {
        hName1->SetMinimum(1);
    }
    hName1->SetLineColor(lineColor1);
    hName1->SetLineWidth(lineWidth1);
    hName1->Draw();
    gPad->SetFrameLineWidth(2);

    hName2->SetLineColor(lineColor2);
    hName2->SetLineWidth(lineWidth2);
    hName2->Draw("same");

    gPad->SetLogy(logY);
    gPad->SaveAs(outputFileName.c_str());
}

// Draw three histograms in the same plot
void make_plot(TH1 *hName1, const char *xTitle, const char *yTitle, Color_t lineColor1, Width_t lineWidth1,
               TH1 *hName2, Color_t lineColor2, Width_t lineWidth2,
               TH1 *hName3, Color_t lineColor3, Width_t lineWidth3,
               Int_t logY, string outputFileName)
{
    gROOT->Reset();
    string command = ".! rm -f " + outputFileName;
    gROOT->ProcessLine(command.c_str());
    hName1->SetXTitle(xTitle);
    hName1->SetYTitle(yTitle);
    if (logY) {
        hName1->SetMinimum(1);
    }
    hName1->SetLineColor(lineColor1);
    hName1->SetLineWidth(lineWidth1);
    hName1->Draw();
    
    hName2->SetLineColor(lineColor2);
    hName2->SetLineWidth(lineWidth2);
    hName2->Draw("same");
    
    hName3->SetLineColor(lineColor3);
    hName3->SetLineWidth(lineWidth3);
    hName3->Draw("same");
    
    gPad->SetLogy(logY);
    gPad->SaveAs(outputFileName.c_str());
}

void root_plots()
{
    TFile *f = new TFile("results.root");

    // jets
    make_plot(hCut1_Njet, "nJet w/ and w/o OR", "counts", kBlack, 2,
              hCut1_Njet_OR, kBlue, 2,
              1, "nJet.pdf");
    make_plot(hCut1_Njet_OR, "nJet", "counts", kBlue, 2,
              hCut5_Njet, kRed, 2,
              1, "nJet_OR.pdf");
    make_plot(hCut1_Njet, "nJet w/o OR, w/ OR, and w/ OR + cuts", "counts", kBlack, 2,
              hCut1_Njet_OR, kBlue, 2,
              hCut5_Njet, kRed, 2,
              1, "nJet_all.pdf");
    make_plot(hCut1_Njet_OR_pt20, "nJet pT>20GeV", "counts", kBlue, 2,
              hCut5_Njet_pt20, kRed, 2,
              1, "nJte_OR_pt20");
    make_plot(hCut1_Njet_OR_pt50, "nJet pT>50GeV", "counts", kBlue, 2,
              hCut5_Njet_pt50, kRed, 2,
              1, "nJet_OR_pt50");
    make_plot(hCut1_Jet_Pt, "jet Pt (MeV)", "counts", kBlue, 2,
              hCut5_Jet_Pt, kRed, 2,
              1, "Jet_Pt.pdf");
    make_plot(hCut1_Jet_Eta, "jet Eta", "counts", kBlue, 2,
              hCut5_Jet_Eta, kRed, 2,
              1, "Jet_Eta.pdf");
    make_plot(hCut1_Jet_Phi, "jet Phi", "counts", kBlue, 2,
              hCut5_Jet_Phi, kRed, 2,
              1, "Jet_Phi.pdf");
    make_plot(hCut1_Jet_Pt1, "jet 1 Pt (MeV)", "counts", kBlue, 2,
              hCut5_Jet_Pt1, kRed, 2,
              1, "Jet_Pt1.pdf");
    make_plot(hCut1_Jet_Pt2, "jet 2 Pt (MeV)", "counts", kBlue, 2,
              hCut5_Jet_Pt2, kRed, 2,
              1, "Jet_Pt2.pdf");
    make_plot(hCut1_Jet_Pt3, "jet 3 Pt (MeV)", "counts", kBlue, 2,
              hCut5_Jet_Pt3, kRed, 2,
              1, "Jet_Pt3.pdf");
    make_plot(hCut1_Jet_Pt4, "jet 4 Pt (MeV)", "counts", kBlue, 2,
              hCut5_Jet_Pt4, kRed, 2,
              1, "Jet_Pt4.pdf");

    // electrons
    make_plot(hCut1_Nelec, "nElec w/ and w/o OR", "counts", kBlack, 2,
              hCut1_Nelec_OR, kBlue, 2,
              1, "nElec.pdf");
    make_plot(hCut1_Nelec_OR, "nElec", "counts", kBlue, 2,
              hCut5_Nelec, kRed, 2,
              1, "nElec_OR.pdf");
    make_plot(hCut1_Nelec, "nElec w/o OR, w/ OR, and w/ OR + cuts", "counts", kBlack, 2,
              hCut1_Nelec_OR, kBlue, 2,
              hCut5_Nelec, kRed, 2,
              1, "nElec_all.pdf");
    make_plot(hCut1_Elec_Pt, "Elec Pt (MeV)", "counts", kBlue, 2,
              hCut5_Elec_Pt, kRed, 2,
              1, "Elec_Pt.pdf");
    make_plot(hCut1_Elec_Eta, "Elec Eta", "counts", kBlue, 2,
              hCut5_Elec_Eta, kRed, 2,
              1, "Elec_Eta.pdf");
    make_plot(hCut1_Elec_Phi, "Elec Phi", "counts", kBlue, 2,
              hCut5_Elec_Phi, kRed, 2,
              1, "Elec_Phi.pdf");
    make_plot(hCut1_Elec_Pt1, "Elec 1 Pt (MeV)", "counts", kBlue, 2,
              hCut5_Elec_Pt1, kRed, 2,
              1, "Elec_Pt1.pdf");
    make_plot(hCut1_Elec_Pt2, "Elec 2 Pt (MeV)", "counts", kBlue, 2,
              hCut5_Elec_Pt2, kRed, 2,
              1, "Elec_Pt2.pdf");

    // muons
    make_plot(hCut1_Nmuon, "nMuon w/ and w/o OR", "counts", kBlack, 2,
              hCut1_Nmuon_OR, kBlue, 2,
              1, "nMuon.pdf");
    make_plot(hCut1_Nmuon_OR, "nMuon", "counts", kBlue, 2,
              hCut5_Nmuon, kRed, 2,
              1, "nMuon_OR.pdf");
    make_plot(hCut1_Nmuon, "nMuon w/o OR, w/ OR, and w/ OR + cuts", "counts", kBlack, 2,
              hCut1_Nmuon_OR, kBlue, 2,
              hCut5_Nmuon, kRed, 2,
              1, "nMuon_all.pdf");
    make_plot(hCut1_Muon_Pt, "Muon Pt (MeV)", "counts", kBlue, 2,
              hCut5_Muon_Pt, kRed, 2,
              1, "Muon_Pt.pdf");
    make_plot(hCut1_Muon_Eta, "Muon Eta", "counts", kBlue, 2,
              hCut5_Muon_Eta, kRed, 2,
              1, "Muon_Eta.pdf");
    make_plot(hCut1_Muon_Phi, "Muon Phi", "counts", kBlue, 2,
              hCut5_Muon_Phi, kRed, 2,
              1, "Muon_Phi.pdf");
    make_plot(hCut1_Muon_Pt1, "Muon 1 Pt (MeV)", "counts", kBlue, 2,
              hCut5_Muon_Pt1, kRed, 2,
              1, "Muon_Pt1.pdf");
    make_plot(hCut1_Muon_Pt2, "Muon 2 Pt (MeV)", "counts", kBlue, 2,
              hCut5_Muon_Pt2, kRed, 2,
              1, "Muon_Pt2.pdf");

    // leptons
    make_plot(hCut1_Nlep, "nLep w/ and w/o OR", "counts", kBlack, 2,
              hCut1_Nlep_OR, kBlue, 2,
              1, "nLep.pdf");
    make_plot(hCut1_Nlep_OR, "nLep", "counts", kBlue, 2,
              hCut5_Nlep, kRed, 2,
              1, "nLep_OR.pdf");
    make_plot(hCut1_Nlep, "nLep w/o OR, w/ OR, and w/ OR + cuts", "counts", kBlack, 2,
              hCut1_Nlep_OR, kBlue, 2,
              hCut5_Nlep, kRed, 2,
              1, "nLep_all.pdf");
    make_plot(hCut1_lep_Pt, "lep Pt (MeV)", "counts", kBlue, 2,
              hCut5_lep_Pt, kRed, 2,
              1, "lep_Pt.pdf");
    make_plot(hCut1_lep_Pt1, "lep 1 Pt (MeV)", "counts", kBlue, 2,
              hCut5_lep_Pt1, kRed, 2,
              1, "lep_Pt1.pdf");
    make_plot(hCut1_lep_Pt2, "lep 2 Pt (MeV)", "counts", kBlue, 2,
              hCut5_lep_Pt2, kRed, 2,
              1, "lep_Pt2.pdf");

    // missing Et
    make_plot(hCut1_MET, "MET (MeV)", "counts", kBlue, 2,
              hCut5_MET, kRed, 2,
              1, "MET.pdf");

    // meff
    //make_plot(hCut1_Meff, "Meff (MeV)", "counts", 4, 2,
    //          hCut5_Meff, 2, 2,
    //          1, "Meff.pdf");
    hCut5_Meff->SetLineColor(kRed);
    hCut5_Meff->SetLineWidth(2);
    hCut5_Meff->SetXTitle("Meff (MeV)");
    hCut5_Meff->SetYTitle("counts");
    hCut5_Meff->Draw();
    gPad->SetLogy(1);
    gPad->SaveAs("Meff.pdf");

    // Nbjet
    make_plot(hCut1_Nbjet, "nBjet", "counts", kBlue, 2,
              hCut5_Nbjet, kRed, 2,
              1, "nBjet.pdf");
}
