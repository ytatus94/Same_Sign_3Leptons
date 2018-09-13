# SS_v44
This is SS/3L+jet cutflows study v44.

### Sample: 
`user.jpoveda.t0789_v44.410080.MadGraphPythia8EvtGen_A14NNPDF23_4topSM.DAOD_SUSY2.s2608_r7725_p2666_output.root`


### Setting:
Use `rcSetup Base,2.4.16`


### v15. Add Sherpa samples
1. Add `merged_Sherpa_Zee.root` and `merged_Sherpa_Zmumu.root` in `cutflow.cxx`.
2. Change `/UserDisk2/yushen` to `/raid05/users`.


### v14. Change the indentation in `yt_selector.h`


### v13. Tag must fires single lepton trigger in the Z T&P method.


### v12. Add weight calculation and change indentations.
1. In `yt_selector`: change the indentations of fill methods, add new methods for calculating weights.
2. In `yt_cutflows`: change the type of `events_pass_cutflow` from `unsigned int` to `double`. Also change the PRW file.
3. In `yt_skim_MC`: add `baseline_weight` and `signal_weight`.
4. In `Fill_and_Set.cxx`: change the indentations.
5. In `cutflow.cxx`: add Zee testing samples.


### v11. Add sample 303421 to test the skim and the lumi is set to 13.2 fb-1.


### v10. Add the tag single lepton trigger which Sebastien used.
But still comment the tag single lepton trigger.


### v09. Add `_SKIM_` in the preprocessor.
1. Modify `yt_selector.h`, `yt_selector.cxx`, and `cutflow.cxx`


### v08. Correct TriggMatched to TriggerMatched.
1. Modify `yt_skim_MC.h`, `yt_skim_MC.cxx`, `yt_skim_data.h`, and `yt_skim_data.cxx`.


### v07. Add data samples in `cutflow.cxx`.
1. The data run 303304 is added.


### v06. Provide set functions and luminosity now becomes an input in the `cutflow.cxx`.
1. Provide set functions for `yt_selector` class.
2. Change the type of `events_pass_cutflow` from `int` to `unsigned int`.
3. Luminosity becomes an input in the `cutflow.cxx`.
4. Use `PRWWeight` instead calculated by myself.
5. Modify `yt_selector.h`, `yt_cutflows.h`, `yt_cutflows.cxx`, and `cutflow.cxx`.


### v05. Add `_IS_DATA_` and `_IS_MC_` in the preprocessor.
1. The code knows to use data or MC once the `#define _IS_MC_` and `#define _IS_DATA_` set correctly.
2. The fill functions have two version, one is for MC and another is for data.
3. Modify `yt_selector.h`, `yt_selector.cxx`, and `Fill_and_Set.cxx`.


### v04. Add skimming codes.


### v03. This version gets correct cutflow results.


### v02. Add rcSetup version in `README.md`.


### v01. Initial commit.
