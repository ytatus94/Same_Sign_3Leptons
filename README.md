# SS_v47
This is SS/3L+jet cutflows study v44.

### Sample:
`user.othrif.t0812_v47.410080.MadGraphPythia8EvtGen_A14NNPDF23_4topSM.DAOD_SUSY2.s2608_r7725_p2666_output.root`

### Setting:


### v01-14. (oldskim branch) Change the implementation in set_derivation_stat_weights()
* Now the `h_derivation_stat_weights` is set in `set_derivation_stat_weights()`


### v01-13. (oldskim branch) Also use new single lepton trigger in ytRealLeptonsEfficiency_MC


### v01-12. (oldskim branch) Use new single lepton trigger and tag pt threshold.
1. tag pt threshold use 30 GeV (original use 25 GeV)
2. Single lepton trigger for 2016 uses: `HLT_e26_lhtight_nod0_ivarloose` and `HLT_mu26_ivarmedium`


### v01-11. (oldskim branch) Add two methods to calculate AvgMu and pileup_weight in yt_cutflows
*  Add `get_AvgMu()` and `get_pileup_weight()` in `yt_cutflows`


### v01-10. (oldskim branch) Scripts run in the background
* Let `run_all_RLE.sh` and `run_all_skim.sh` run in the background


### v01-09. (oldskim branch) Fix bug in `RLE.cxx`


### v01-08. (oldskim branch) Add two scripts to run skim and RLE
* Add `run_all_RLE.sh` and `run_all_skim.sh`
* Modify `RLE.cxx` to read different period of data.


### v01-07. (oldskim branch) Change lumi
The lumi for 2015 + 2016 data is 3.2 + 33.3 = 36.5 fb-1


### v01-06. (oldskim branch) Add RLE codes.
* new file:   `ytNUHM2Analysis/Root/ytRealLeptonsEfficiency_Data.cxx`
* new file:   `ytNUHM2Analysis/Root/ytRealLeptonsEfficiency_MC.cxx`
* new file:   `ytNUHM2Analysis/util/RLE.cxx`
* new file:   `ytNUHM2Analysis/ytNUHM2Analysis/ytRealLeptonsEfficiency_Data.h`
* new file:   `ytNUHM2Analysis/ytNUHM2Analysis/ytRealLeptonsEfficiency_MC.h`



### v01-05. (oldskim branch) Modify skim code so it can run over different dataset now.
* modified:   `ytNUHM2Analysis/Root/LinkDef.h`
* modified:   `ytNUHM2Analysis/Root/ytEventSelection.cxx`
* modified:   `ytNUHM2Analysis/Root/yt_skim_data.cxx`
* modified:   `ytNUHM2Analysis/util/Run.cxx`
* modified:   `ytNUHM2Analysis/ytNUHM2Analysis/yt_skim_data.h`


### v01-04. (oldskim branch) Change `cutflow.cxx` to `Run.cxx`.


### v01-03. (oldskim branch) Change the include path in skim codes.
Also add skim classes into `LinkDef.h`


### v01-02. (oldskim branch) Add skim codes
Add `yt_skim`, `yt_skim_MC`, `yt_skim_data` classes


### v01-01. (oldskim branch) Add `AnaNtup_Data` codes in misc


### v01. First commit
This version can get the correct results.
