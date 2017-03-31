# SS_v50
This is SS/3L+jet cutflows study for v50 ntuples.

### Sample:
`user.othrif.t0845_v50.410080.MadGraphPythia8EvtGen_A14NNPDF23_4topSM.DAOD_SUSY2.s2608_r7725_p2879_output.root`

### Setting:
* AnalysisBase 2.4.26
* ST-00-08-45


### v14. (master) Add background samples
1. `Run.cxx`: Add correct bkg samples
2. Copy `run_signal_samples.sh`, `run_optimization.sh` and `ytOptimization_plots.C` from `SS_v47`
3. Copy `run_bkg_samples.sh` from `SS_v47` and modify the bkg samples to run.


### v13. (master) Copy the `yt_optimization.h` and `yt_optimization.cxx` from NUHM2


### v12. (master) output the difference between truth match and T&P method
1. `ytPlots.C`: output the difference between truth match and T&P method in `yt_truth_match_TandP_comparison_table()`


### v11. (master) Add the codes for SR optimization.
1. In `yt_optimization`: `apply_signal_region_cuts()`
2. `yt_SR_definitions.h`: New file.


### v10. (master) Use the correct optimization code from v47 newskim branch


### v09. (master) Add nw script run_all_optimization.sh


### v08. (master) Add optimization code
1. Add optimization in `ytEventSelection`


### v07. (master) Add optimization code.
1. Add new class `yt_optimization`
2. Add class in `LinkDef.h`


### v06. v52 branch 
1. `run_all_skim.sh`: Add GG_ttn1 samples to run.
2. `make_final_RLE_plots.py`: Change the path of input files.
3. `make_matrix_method_input.py`: Change the path of input files.
4. `run_elec_systematics.py`: Fix typo.
5. `run_muon_systematics.py`: Change the path of input files.
6. `run_trigger_systematics.py`: Change the path of input files.
7. `run_relative_differences_of_efficiency.py`: Change pT bins from [50, 65, 80, 200] to [50, 60, 80, 150, 200].
8. `run_making_plots.py`: Add some line of codes to make more plots.
9. `run_everything.py`: Add trigger background scription.
10.`run_trigger_bkg_subtraction.py`: New script.
11.`ytBackground_subtraction.C`: Change the path of input files.
12.`ytRelative_difference_of_efficiency.C`: Change the path of input files.
13.`Run.cxx`: Add comments.
14.`ytPlots.C`:
   * Change the path of input files.
   * Use `tag_trigger_matched` to make all plots.
   * Change cosmatics
   * Add new function `yt_real_efficiency_function_of_eta_with_different_pt()`
   * Add new function `yt_truth_match_TandP_comparison_table()`


### v05. DerivationStat_Weights becomes input
1. `ytEventSelection.cxx`: comment the part to load `DerivationStat_Weights` from root file.
2. `Run.cxx`: Add code for reading `DerivationStat_Weights` from root file.
3. `ytEventSelection.h`: Add new method `set_derivation_stat_weights()`


### v04. Use tag_trigger_matched as the nominal
1. `make_AvgMu_and_mll.py`: Change the input file path
2. `make_matrix_method_input.py`:
	* Change the input file path
	* `get_muon_real_efficiency()`: Correct the index while read the input file
3. `run_elec_systematics.py`: Change from `single_lepton_trigger` to `tag_trigger_matched`
4. `run_muon_systematics.py`: Change the input file path and use tag_trigger_matched as the nominal
5. `run_trigger_systematics.py`: Use tag_trigger_matched as the nominal
6. `run_all_RLE.sh`: Uncommont the ttbar
7. `ytBackground_subtraction.C`: Change the input path
8. `RLE.cxx`: Change the input path
9. `run_everything.py`: Use tag_trigger_matched as the nominal
10. `run_making_plots.py`:
    * Change the input path
    * Comment out the part related to Gtt because we don't have Gtt sample in v50.


### v03. Change the 2015 single lepton trigger
1. `yt_skim.cxx`: Use `get_trigMatch_e24_lhmedium_iloose_L1EM20VH()` because of `get_trigMatch_e24_lhmedium_L1EM20VH()` doesn't work correctly.
2. `ytRealLeptonsEfficiency.cxx`: Use `HLT_e24_lhmedium_iloose_L1EM20VH` instead of using `HLT_e24_lhmedium_L1EM20VH`
3. `run_all_skim.sh`: Turn ttbar skim
4. `ytPlots.C`: Fix typo


### v02. New OR + signal elec object definition
1. `yt_useful_functions`: Add new function `deltaR()` in header and implementation.
2. `ytEventSelection.h`:
    * Add new vectors: `vec_new_OR_elec`, `vec_new_OR_muon`, `vec_new_OR_lept`
    * Add new fill methods: `fill_new_OR_electrons()`, `fill_new_OR_muons()`, and `fill_new_OR_leptons()`
3. `yt_cutflows.cxx`: Comment unused `pileupwgh` variable in `get_mc_random_event_number()`
4. New cutflow results: `ytNUHM2Analysis/logs/4topSM_new_OR.txt`


### v01. First commit
This version can get the correct cutflow results.
