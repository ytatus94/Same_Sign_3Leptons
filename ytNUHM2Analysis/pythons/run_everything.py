#!/usr/bin/python
import os
os.system(". ../scripts/run_all_skim.sh")
os.system("./merge_data.py -b --skimmed")
os.system("./make_AvgMu_and_mll.py -b --skimmed")
os.system(". ../scripts/run_all_RLE.sh")
os.system("./merge_data.py -b --RLE")
os.system("../make_AvgMu_and_mll.py -b --RLE")
os.system("./run_making_plots.py")
os.system("./run_background_subtraction.py")
os.system("./run_elec_systematics.py")
# need to save the output files: el_var_templates.txt, el_var_fitting_ranges.txt, and el_var_mll_windows.txt
os.system("./run_muon_efficiency.py")
# need to save the output mu_eff.txt
os.system("./run_relative_differences_of_efficiency.py")
os.system("./make_final_RLE_plots.py")
