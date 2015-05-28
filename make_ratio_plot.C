void make_ratio_plot(string file1, string file2, 
                     string hName,
                     char *xtitle, char *top_ytitle, char *bottom_ytitle,
                     double xlow, double xup,
                     string outputFileName)
{
    gROOT->Reset();

    TFile *f1 = new TFile(file1.c_str());
    TH1 *h1 = (TH1 *)f1->Get(hName.c_str());
    h1->SetDirectory(0);
    f1->Close();

    TFile *f2 = new TFile(file2.c_str());
    TH1 *h2 = (TH1 *)f2->Get(hName.c_str());
    h2->SetDirectory(0);
    f2->Close();

    // Normalize to one.
    Double_t scale1 = 1./h1->Integral();
    h1->Scale(scale1);
    Double_t scale2 = 1./h2->Integral();
    h2->Scale(scale2);

    // h1 settings
    h1->SetLineColor(kBlue);
    h1->SetLineWidth(2);
    h1->SetMarkerStyle(20);
    h1->SetMarkerColor(kBlue);
    h1->SetMarkerSize(1);
    // X axis h1 plot settings
    h1->GetXaxis()->SetRangeUser(xlow, xup);
    // Y axis h1 plot settings
    //h1->SetYTitle("counts");
    h1->SetYTitle(top_ytitle);
    h1->GetYaxis()->SetTitleSize(20);
    h1->GetYaxis()->SetTitleFont(43);
    h1->GetYaxis()->SetTitleOffset(1.55);

    // h2 settings
    h2->SetLineColor(kRed);
    h2->SetLineWidth(2);
    h2->SetMarkerStyle(26);
    h2->SetMarkerColor(kRed);
    h2->SetMarkerSize(1);

    // Define the Canvas
    TCanvas *c = new TCanvas("c", "canvas", 800, 800);

    //Upper plot will be in pad1
    TPad *pad1 = new TPad("pad1", "pad1", 0, 0.3, 1, 1.0);
    pad1->SetBottomMargin(0); // Upper and lower plot are joined
    //pad1->SetGridy(); // grid lines
    pad1->Draw();
    pad1->cd(); // pad1 becomes the current pad
    pad1->SetFrameLineWidth(2);

    h1->SetStats(0); // No statistics on upper plot
    h1->Draw("p"); // Draw h1 using current marker setting
    h2->Draw("psame"); // Draw h2 on the same plot using current marker setting
    pad1->SetLogy(1);

    // lower plot will be in pad
    c->cd(); // Go back to the main canvas before defining pad2
    TPad *pad2 = new TPad("pad2", "pad2", 0, 0.05, 1, 0.3);
    pad2->SetTopMargin(0);
    pad2->SetBottomMargin(0.2);
    pad2->SetGridy(); // grid lines
    pad2->Draw();
    pad2->cd(); // pad2 becomes the current pad
    pad2->SetFrameLineWidth(2);

    //Define the ratio plot
    TH1 *h3 = (TH1*)h1->Clone("h3");
//    h3->SetLineColor(kBlack);
    h3->SetMinimum(0.); // Define Y minimum.
    h3->SetMaximum(2.);	// Define Y maximum.
//    h3->Sumw2(); // sum of squares of weights
    h3->SetStats(0); // No statistics on lower plot
    h3->Divide(h2); // calculate the ratio
    h3->SetMarkerStyle(20);
    h3->SetMarkerColor(kBlack);
    h3->SetMarkerSize(1);

    // Ratio plot (h3) settings
    h3->SetTitle(""); // Remove the ratio title
    // X axis ratio plot settings
    h3->SetXTitle(xtitle);
    h3->GetXaxis()->SetTitleSize(27);
    h3->GetXaxis()->SetTitleFont(43);
    h3->GetXaxis()->SetTitleOffset(2.5);
    h3->GetXaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
    h3->GetXaxis()->SetLabelSize(15);
    // Y axis ratio plot settings
    h3->GetYaxis()->SetTitle(bottom_ytitle);
    h3->GetYaxis()->SetNdivisions(505);
    h3->GetYaxis()->SetTitleSize(27);
    h3->GetYaxis()->SetTitleFont(43);
    h3->GetYaxis()->SetTitleOffset(1);
    h3->GetYaxis()->SetLabelFont(43); // Absolute font size in pixel (precision 3)
    h3->GetYaxis()->SetLabelSize(15);

    //h3->Draw("ep"); // Draw the ratio plot with error bar
    h3->Draw("p"); // Draw the ratio plot w/o error bar

    // Draw a red line at 1.
    TLine *l = new TLine(xlow, 1, xup, 1);
    l->SetLineWidth(2);
    l->SetLineColor(kRed);
    l->Draw("same");
    
    c->SaveAs(outputFileName.c_str());
    c->Close();
}
