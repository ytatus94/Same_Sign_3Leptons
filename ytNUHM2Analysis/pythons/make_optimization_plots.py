#!/usr/bin/python
import os, ROOT, array

def main():
    # Define optimization cuts
    n_lept_cuts = [2, 3, 4]
    n_bjet_cuts = [0, 1, 2, 3]
    n_jets_cuts = [2, 3, 4, 5, 6]
    bjet_pt_cuts = [20, 25, 30, 40]
    jets_pt_cuts = [20, 25, 30, 35, 40, 50]
    met_cuts = [0, 50, 100, 150, 200, 250, 300, 350, 400, 500]
    meff_cuts = [0, 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000]

    # # Define arraies
    array_met = array.array("d", met_cuts)
    array_meff = array.array("d", meff_cuts)

    # h_test = ROOT.TH2F("h2", "title", len(met_cuts)-1, array_met, len(meff_cuts)-1, array_meff)
    # c1 = ROOT.TCanvas("c1", "c1")
    # h_test.SetBinContent(1,1,11)   
    # h_test.SetBinContent(2,1,22)
    # h_test.SetBinContent(3,1,33)
    # h_test.SetBinContent(4,1,44)
    # h_test.SetBinContent(5,1,55)
    # h_test.SetBinContent(6,1,66)
    # h_test.SetBinContent(7,1,77)
    # h_test.SetBinContent(8,1,88)
    # h_test.SetBinContent(9,1,99)
    # h_test.SetBinContent(10,1,100)
    # h_test.Draw("text")
    # c1.SaveAs("h_test.pdf")

    # This list keeps all the histograms
    # The number of histograms = n_lept_cuts * n_bjet_cuts * n_jets_cuts * bjet_pt_cuts * jets_pt_cuts
    hist_collections = []

    # lept = 0
    # bjet_pt = 0
    # bjet = 0
    # jet_pt = 0
    # jet = 0

    # # Load values from opt.txt
    # with open("../scripts/opt_test.txt") as fopen:
    #     lines = fopen.readlines()
    #     for line in lines:
    #         if "bin=" in line:
    #             bin = line[line.find("bin=")+4 : line.find(", n_signal=")]
    #             if int(bin) > 0:
    #                 significance = line[line.find("significance=")+13 : line.find(", n_lept_cuts=")]
    #                 tmp_lept = line[line.find(", n_lept_cuts=")+14 : line.find(", bjet_pt_cuts=")]
    #                 tmp_bjet_pt = line[line.find(", bjet_pt_cuts=")+15 : line.find(", n_bjet_cuts=")]
    #                 tmp_bjet = line[line.find(", n_bjet_cuts=")+14 : line.find(", jets_pt_cuts=")]
    #                 tmp_jet_pt = line[line.find(", jets_pt_cuts=")+15 : line.find(", n_jets_cuts=")]
    #                 tmp_jet = line[line.find(", n_jets_cuts=")+14 : line.find(", met_cuts=")]
    #                 met = line[line.find(", met_cuts=")+11 : line.find(", meff_cuts=")]
    #                 meff = line[line.find(", meff_cuts=")+12 : len(line)]

    hist_counter = 0
    for i_lept in n_lept_cuts:
        for i_bjet_pt in bjet_pt_cuts:
            for i_bjet in n_bjet_cuts:
                for i_jet_pt in jets_pt_cuts:
                    for i_jet in n_jets_cuts:
                        #print "n_lept_cuts=", i_lept, ", bjet_pt_cuts=", i_bjet_pt, ", n_bjet_cuts=", i_bjet, ", jets_pt_cuts=", i_jet_pt, ", n_jets_cuts=", i_jet
                        hist_title = "N_{#ell}=" + str(i_lept) +\
                                     " b-jet p_{T}=" + str(i_bjet_pt) +\
                                     " N_{b-jet}=" + str(i_bjet) +\
                                     " jet p_{T}=" + str(i_jet_pt) +\
                                     " N_{jet}=" + str(i_jet)+\
                                     ": E_{T}^{miss} [GeV] : M_{eff} [GeV]"
                        hist_name = "hist_" + str(hist_counter)
                        #print hist_title, hist_name
                        hist = ROOT.TH2F(hist_name, hist_title, len(met_cuts)-1, array_met, len(meff_cuts)-1, array_meff)

                        # Load values from opt.txt
                        with open("../scripts/opt.txt") as fopen:
                            lines = fopen.readlines()
                            for line in lines:
                                if "bin=" in line:
                                    bin = line[line.find("bin=")+4 : line.find(", significance=")]
                                    significance = line[line.find("significance=")+13 : line.find(", n_lept_cuts=")]
                                    lept = line[line.find(", n_lept_cuts=")+14 : line.find(", bjet_pt_cuts=")]
                                    bjet_pt = line[line.find(", bjet_pt_cuts=")+15 : line.find(", n_bjet_cuts=")]
                                    bjet = line[line.find(", n_bjet_cuts=")+14 : line.find(", jets_pt_cuts=")]
                                    jet_pt = line[line.find(", jets_pt_cuts=")+15 : line.find(", n_jets_cuts=")]
                                    jet = line[line.find(", n_jets_cuts=")+14 : line.find(", met_cuts=")]
                                    met = line[line.find(", met_cuts=")+11 : line.find(", meff_cuts=")]
                                    meff = line[line.find(", meff_cuts=")+12 : len(line)]

                                    # compare loaded values with cut values
                                    if int(lept) == i_lept and int(bjet_pt) == i_bjet_pt and int(bjet) == i_bjet and int(jet_pt) == i_jet_pt and int(jet) == i_jet:
                                        x_index = met_cuts.index(int(met))+1
                                        y_index = meff_cuts.index(int(meff))+1
                                        #print int(x_index), int(y_index), float(significance)
                                        hist.SetBinContent(int(x_index), int(y_index), float(significance))
                        fopen.close()
                        hist_counter += 1
                        hist_collections.append(hist)

    print len(hist_collections)





# def load_values_from_optimization_file()
#     # Load values from opt.txt
#     with open("../scripts/opt_test.txt") as fopen:
#         lines = fopen.readlines()
#         for line in lines:
#             if "bin=" in line:
#                 bin = line[line.find("bin=")+4 : line.find(", significance=")]
#                 significance = line[line.find("significance=")+13 : line.find(", n_lept_cuts=")]
#                 lept = line[line.find(", n_lept_cuts=")+14 : line.find(", bjet_pt_cuts=")]
#                 bjet_pt = line[line.find(", bjet_pt_cuts=")+15 : line.find(", n_bjet_cuts=")]
#                 bjet = line[line.find(", n_bjet_cuts=")+14 : line.find(", jets_pt_cuts=")]
#                 jet_pt = line[line.find(", jets_pt_cuts=")+15 : line.find(", n_jets_cuts=")]
#                 jet = line[line.find(", n_jets_cuts=")+14 : line.find(", met_cuts=")]
#                 met = line[line.find(", met_cuts=")+11 : line.find(", meff_cuts=")]
#                 meff = line[line.find(", meff_cuts=")+12 : len(line)]

#                 # print "significance=", significance, \
#                 #       "bin=", bin,\
#                 #       "lept=", lept,\
#                 #       "bjet_pt=", bjet_pt,\
#                 #       "bjet=", bjet,\
#                 #       "jet_pt=", jet_pt,\
#                 #       "jet=", jet,\
#                 #       "met=", met,\
#                 #       "meff=", meff

#                 hist_collections.append( fill_histogram(significance, bin, lept, bjet_pt, bjet, jet_pt, jet, met, meff) )
#     fopen.close()

#     print hist_collections[5].GetName()





# def fill_histogram(significance, bin, lept, bjet_pt, bjet, jet_pt, jet, met, meff):
#     met_cuts = [0, 50, 100, 150, 200, 250, 300, 350, 400, 500]
#     meff_cuts = [0, 100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000]

#     # Define arraies
#     array_met = array.array("d", met_cuts)
#     array_meff = array.array("d", meff_cuts)

#     hist_title = "N_{#ell}=" + str(lept) +\
#                  " b-jet p_{T}=" + str(bjet_pt) +\
#                  " N_{b-jet}=" + str(bjet) +\
#                  " jet p_{T}=" + str(jet_pt) +\
#                  " N_{jet}=" + str(jet)+\
#                  ": E_{T}^{miss} [GeV] : M_{eff} [GeV]"
#     hist_name = "hist_" + str(bin)

#     x_index = met_cuts.index(int(met))+1
#     y_index = meff_cuts.index(int(meff))+1

#     hist = ROOT.TH2F(hist_name, hist_title, len(met_cuts)-1, array_met, len(meff_cuts)-1, array_meff)
#     hist.SetBinContent(int(x_index), int(y_index), float(significance))

#     return hist





                # for i_lept in n_lept_cuts:
                #     for i_bjet_pt in bjet_pt_cuts:
                #         for i_bjet in n_bjet_cuts:
                #             for i_jet_pt in jets_pt_cuts:
                #                 for i_jet in n_jets_cuts:
                #                     #print "n_lept_cuts=", i_lept, ", bjet_pt_cuts=", i_bjet_pt, ", n_bjet_cuts=", i_bjet, ", jets_pt_cuts=", i_jet_pt, ", n_jets_cuts=", i_jet
                #                     hist_title = "N_{#ell}=" + str(i_lept) +\
                #                                  " b-jet p_{T}=" + str(i_bjet_pt) +\
                #                                  " N_{b-jet}=" + str(i_bjet) +\
                #                                  " jet p_{T}=" + str(i_jet_pt) +\
                #                                  " N_{jet}=" + str(i_jet)+\
                #                                  ": E_{T}^{miss} [GeV] : M_{eff} [GeV]"
                #                     if lept == i_lept and bjet_pt == i_bjet_pt and bjet == i_bjet and jet_pt == i_jet_pt and jet == i_jet:
                #                         print hist_title
                #                         # x_counter = 1
                #                         # for i_met in met_cuts:
                #                         #     if met == i_met:
                #                         #         y_counter = 1
                #                         #         for i_meff in meff_cuts:
                #                         #             if meff == i_meff:
                #                         #                 print x_counter, y_counter, met, meff
                #                         #                 y_counter += 1
                #                         #         x_counter += 1





                                    # hist_name = "hist_" + str(hist_counter)
                                    
                                    # #print hist_name, hist_title
                                    # hist_counter += 1
                                    # hist = ROOT.TH2F(hist_name, hist_title, len(met_cuts)-1, array_met, len(meff_cuts)-1, array_meff)

if __name__ == "__main__":
    main()
