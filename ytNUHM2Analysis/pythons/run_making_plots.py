#!/usr/bin/python
import os, ROOT
os.sys.argv.append( '-b' ) #Batch mode, same as python <somescript>.py -b

#cwd = os.getcwd()
#print cwd
print "NOTE!!! Fix the input path before running."
#ROOT.gROOT.LoadMacro("../scripts/ytPlots.C")
ROOT.gROOT.LoadMacro("/Users/ytshen/Documents/Working/OU/HEP/my_codes/SS_v47/ytNUHM2Analysis/scripts/ytPlots.C")

#RLE_data_elec = "/raid05/users/shen/Ximo_ntuples/v47/Cutflow/Results/20170112/hist-RLE-merged-data-elec.root"
#RLE_data_muon = "/raid05/users/shen/Ximo_ntuples/v47/Cutflow/Results/20170112/hist-RLE-merged-data-muon.root"
RLE_data_elec = "/Users/ytshen/Desktop/skim/Results/20170112/hist-RLE-merged-data-elec.root"
RLE_data_muon = "/Users/ytshen/Desktop/skim/Results/20170112hist-RLE-merged-data-muon.root"

ROOT.gROOT.ProcessLine("yt_mll_plots()")

#ROOT.gROOT.ProcessLine("yt_baseline_mll_plots()")
ROOT.gROOT.ProcessLine("yt_baseline_mll_ratio_plots(1,1,true,false)")
ROOT.gROOT.ProcessLine("yt_baseline_mll_ratio_plots(2,2,true,false)")
ROOT.gROOT.ProcessLine("yt_baseline_mll_ratio_plots(3,3,true,false)")
ROOT.gROOT.ProcessLine("yt_baseline_mll_ratio_plots(4,4,true,false)")
ROOT.gROOT.ProcessLine("yt_baseline_mll_ratio_plots(5,5,true,false)")
ROOT.gROOT.ProcessLine("yt_baseline_mll_ratio_plots(6,6,true,false)")
ROOT.gROOT.ProcessLine("yt_baseline_mll_ratio_plots(7,7,true,false)")
ROOT.gROOT.ProcessLine("yt_baseline_mll_ratio_plots(8,8,true,false)")
ROOT.gROOT.ProcessLine("yt_baseline_mll_ratio_plots(9,9,true,false)")
ROOT.gROOT.ProcessLine("yt_baseline_mll_ratio_plots(10,10,true,false)")
ROOT.gROOT.ProcessLine("yt_baseline_mll_ratio_plots(11,11,true,false)")
ROOT.gROOT.ProcessLine("yt_baseline_mll_ratio_plots(12,12,true,false)")
ROOT.gROOT.ProcessLine("yt_baseline_mll_ratio_plots(13,13,true,false)")

#ROOT.gROOT.ProcessLine("yt_signal_mll_plots()")
ROOT.gROOT.ProcessLine("yt_signal_mll_ratio_plots(1,1,true,false)")
ROOT.gROOT.ProcessLine("yt_signal_mll_ratio_plots(2,2,true,false)")
ROOT.gROOT.ProcessLine("yt_signal_mll_ratio_plots(3,3,true,false)")
ROOT.gROOT.ProcessLine("yt_signal_mll_ratio_plots(4,4,true,false)")
ROOT.gROOT.ProcessLine("yt_signal_mll_ratio_plots(5,5,true,false)")
ROOT.gROOT.ProcessLine("yt_signal_mll_ratio_plots(6,6,true,false)")
ROOT.gROOT.ProcessLine("yt_signal_mll_ratio_plots(7,7,true,false)")
ROOT.gROOT.ProcessLine("yt_signal_mll_ratio_plots(8,8,true,false)")
ROOT.gROOT.ProcessLine("yt_signal_mll_ratio_plots(9,9,true,false)")
ROOT.gROOT.ProcessLine("yt_signal_mll_ratio_plots(10,10,true,false)")
ROOT.gROOT.ProcessLine("yt_signal_mll_ratio_plots(11,11,true,false)")
ROOT.gROOT.ProcessLine("yt_signal_mll_ratio_plots(12,12,true,false)")
ROOT.gROOT.ProcessLine("yt_signal_mll_ratio_plots(13,13,true,false)")

ROOT.gROOT.ProcessLine("yt_make_cut_efficiency_plot(\"RLE_data_elec\",\"electron\")")
ROOT.gROOT.ProcessLine("yt_make_cut_efficiency_plot(\"RLE_data_muon\",\"muon\")")
ROOT.gROOT.ProcessLine("yt_make_electron_real_efficiency_plot(\"RLE_data_elec\")")
ROOT.gROOT.ProcessLine("yt_make_muon_real_efficiency_plot(\"RLE_data_muon\")")
ROOT.gROOT.ProcessLine("yt_make_real_efficiency_plots(true,true,true)")
ROOT.gROOT.ProcessLine("yt_truth_match_TandP_comparison(\"electron\", \"pt\",true)")
ROOT.gROOT.ProcessLine("yt_truth_match_TandP_comparison(\"electron\", \"eta\",true)")
ROOT.gROOT.ProcessLine("yt_truth_match_TandP_comparison(\"electron\", \"dRjet\",true)")
ROOT.gROOT.ProcessLine("yt_truth_match_TandP_comparison(\"muon\", \"pt\",true)")
ROOT.gROOT.ProcessLine("yt_truth_match_TandP_comparison(\"muon\", \"eta\",true)")
ROOT.gROOT.ProcessLine("yt_truth_match_TandP_comparison(\"muon\", \"dRjet\",true)")

#ROOT.gROOT.ProcessLine("yt_Gtt_electron_real_efficiency_individual_cut_study()")
#ROOT.gROOT.ProcessLine("yt_Gtt_electron_real_efficiency_combine_cuts_study()")
#ROOT.gROOT.ProcessLine("yt_Gtt_electron_real_efficiency_comparison()")

ROOT.gROOT.ProcessLine("yt_background_subtraction_illustration()")
ROOT.gROOT.ProcessLine("yt_background_template_mll_plot(1,1)")
ROOT.gROOT.ProcessLine("yt_background_template_mll_plot(2,2)")
ROOT.gROOT.ProcessLine("yt_kinematics_distribution()")
ROOT.gROOT.ProcessLine("yt_deltaR_and_NJets_distribution()")

#os.system("root -q -b '../scripts/ytRelative_difference_of_efficiency.C(10, 20, true, true)' > relative_difference_of_efficiency_pt1020.txt")
#os.system("root -q -b '../scripts/ytRelative_difference_of_efficiency.C(20, 30, true, true)' > relative_difference_of_efficiency_pt2030.txt")
#os.system("root -q -b '../scripts/ytRelative_difference_of_efficiency.C(30, 50, true, true)' > relative_difference_of_efficiency_pt3050.txt")
#os.system("root -q -b '../scripts/ytRelative_difference_of_efficiency.C(50, 80, true, true)' > relative_difference_of_efficiency_pt5080.txt")
#os.system("root -q -b '../scripts/ytRelative_difference_of_efficiency.C(80, 200, true, true)' > relative_difference_of_efficiency_pt80200.txt")
