#include "make_ratio_plot.C"

void root_ratio_plots()
{
    gROOT->Reset();

    string file50ns = "results.root";
    // ttbar
    string file25ns = "../user.jpoveda.t26_v04_p1872.110401.PowhegPythia_P2012_ttbar_nonallhad_output.root/results.root";
    // G1000_T5000_L100
    //string file25ns = "../user.jpoveda.t26_v04_p1872.204533.Herwigpp_UEEE4_CTEQ6L1_Gtt_G1000_T5000_L100_output.root/results.root";
    // G1300_T5000_L700
    //string file25ns = "../user.jpoveda.t26_v04_p1872.204540.Herwigpp_UEEE4_CTEQ6L1_Gtt_G1300_T5000_L700_output.root/results.root";
    
    make_ratio_plot(file50ns.c_str(), file25ns.c_str(),
                    "hCut5_Njet",
                    "nJet", "counts", "50ns/25ns",
                    0., 20.,
                    "ratio_ttbar_Njet.pdf");
    make_ratio_plot(file50ns.c_str(), file25ns.c_str(),
                    "hCut5_Njet_pt20",
                    "nJet20", "counts", "50ns/25ns",
                    0., 20.,
                    "ratio_ttbar_nJet20.pdf");
    make_ratio_plot(file50ns.c_str(), file25ns.c_str(),
                    "hCut5_Njet_pt50",
                    "nJet50", "counts", "50ns/25ns",
                    0., 20.,
                    "ratio_ttbar_nJet50.pdf");
    make_ratio_plot(file50ns.c_str(), file25ns.c_str(),
                    "hCut5_Jet_Pt",
                    "Jet Pt (GeV)", "counts", "50ns/25ns",
                    0., 1500.,
                    "ratio_ttbar_Jet_Pt.pdf");
    make_ratio_plot(file50ns.c_str(), file25ns.c_str(),
                    "hCut5_Jet_Pt1",
                    "Jet 1 Pt (GeV)", "counts", "50ns/25ns",
                    0., 1500.,
                    "ratio_ttbar_Jet_Pt1.pdf");
    make_ratio_plot(file50ns.c_str(), file25ns.c_str(),
                    "hCut5_Jet_Pt2",
                    "Jet 2 Pt (GeV)", "counts", "50ns/25ns",
                    0., 1000.,
                    "ratio_ttbar_Jet_Pt2.pdf");
    make_ratio_plot(file50ns.c_str(), file25ns.c_str(),
                    "hCut5_Jet_Pt3",
                    "Jet 3 Pt (GeV)", "counts", "50ns/25ns",
                    0., 500.,
                    "ratio_ttbar_Jet_Pt3.pdf");
    make_ratio_plot(file50ns.c_str(), file25ns.c_str(),
                    "hCut5_Jet_Pt4",
                    "Jet 4 Pt (GeV)", "counts", "50ns/25ns",
                    0., 500.,
                    "ratio_ttbar_Jet_Pt4.pdf");
    make_ratio_plot(file50ns.c_str(), file25ns.c_str(),
                    "hCut5_Nelec",
                    "nElec", "counts", "50ns/25ns",
                    0., 20.,
                    "ratio_ttbar_nElec.pdf");
    make_ratio_plot(file50ns.c_str(), file25ns.c_str(),
                    "hCut5_Elec_Pt",
                    "Elec Pt (GeV)", "counts", "50ns/25ns",
                    0., 1000.,
                    "ratio_ttbar_Elec_Pt.pdf");
    make_ratio_plot(file50ns.c_str(), file25ns.c_str(),
                    "hCut5_Elec_Pt1",
                    "Elec 1 Pt (GeV)", "counts", "50ns/25ns",
                    0., 1000.,
                    "ratio_ttbar_Elec_Pt1.pdf");
    make_ratio_plot(file50ns.c_str(), file25ns.c_str(),
                    "hCut5_Elec_Pt2",
                    "Elec 2 Pt (GeV)", "counts", "50ns/25ns",
                    0., 1000.,
                    "ratio_ttbar_Elec_Pt2.pdf");
    make_ratio_plot(file50ns.c_str(), file25ns.c_str(),
                    "hCut5_Nmuon",
                    "nMuon", "counts", "50ns/25ns",
                    0., 20.,
                    "ratio_ttbar_nMuon.pdf");
    make_ratio_plot(file50ns.c_str(), file25ns.c_str(),
                    "hCut5_Muon_Pt",
                    "Muon Pt (GeV)", "counts", "50ns/25ns",
                    0., 1000.,
                    "ratio_ttbar_Muon_Pt.pdf");
    make_ratio_plot(file50ns.c_str(), file25ns.c_str(),
                    "hCut5_Muon_Pt1",
                    "Muon 1 Pt (GeV)", "counts", "50ns/25ns",
                    0., 1000.,
                    "ratio_ttbar_Muon_Pt1.pdf");
    make_ratio_plot(file50ns.c_str(), file25ns.c_str(),
                    "hCut5_Muon_Pt2",
                    "Muon 2 Pt (GeV)", "counts", "50ns/25ns",
                    0., 1000.,
                    "ratio_ttbar_Muon_Pt2.pdf");
    make_ratio_plot(file50ns.c_str(), file25ns.c_str(),
                    "hCut5_Nlep",
                    "nLept", "counts", "50ns/25ns",
                    0., 20.,
                    "ratio_ttbar_nLept.pdf");
    make_ratio_plot(file50ns.c_str(), file25ns.c_str(),
                    "hCut5_lep_Pt",
                    "Lept Pt (GeV)", "counts", "50ns/25ns",
                    0., 1000.,
                    "ratio_ttbar_Lept_Pt.pdf");
    make_ratio_plot(file50ns.c_str(), file25ns.c_str(),
                    "hCut5_lep_Pt1",
                    "lep 1 Pt (GeV)", "counts", "50ns/25ns",
                    0., 1000.,
                    "ratio_ttbar_lep_Pt1.pdf");
    make_ratio_plot(file50ns.c_str(), file25ns.c_str(),
                    "hCut5_lep_Pt2",
                    "lep 2 Pt (GeV)", "counts", "50ns/25ns",
                    0., 1000.,
                    "ratio_ttbar_lep_Pt2.pdf");
    make_ratio_plot(file50ns.c_str(), file25ns.c_str(),
                    "hCut5_MET",
                    "MET (GeV)", "counts", "50ns/25ns",
                    0., 1000.,
                    "ratio_ttbar_MET.pdf");
    make_ratio_plot(file50ns.c_str(), file25ns.c_str(),
                    "hCut5_Meff",
                    "Meff (GeV)", "counts", "50ns/25ns",
                    0., 3000.,
                    "ratio_ttbar_Meff.pdf");
}
