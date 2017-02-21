# SS_v50
This is SS/3L+jet cutflows study for v50 ntuples.

### Sample:
`user.othrif.t0845_v50.410080.MadGraphPythia8EvtGen_A14NNPDF23_4topSM.DAOD_SUSY2.s2608_r7725_p2879_output.root`

### Setting:
* AnalysisBase 2.4.26
* ST-00-08-45


### v02. New OR + signal elec object definition
1. `yt_useful_functions`: Add new function `deltaR()` in header and implementation.
2. `ytEventSelection.h`:
    * Add new vectors: `vec_new_OR_elec`, `vec_new_OR_muon`, `vec_new_OR_lept`
    * Add new fill methods: `fill_new_OR_electrons()`, `fill_new_OR_muons()`, and `fill_new_OR_leptons()`
3. `yt_cutflows.cxx`: Comment unused `pileupwgh` variable in `get_mc_random_event_number()`
4. New cutflow results: `ytNUHM2Analysis/logs/4topSM_new_OR.txt`


### v01. First commit
This version can get the correct cutflow results.
