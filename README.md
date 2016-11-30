# SS_v37
This is SS/3L+jet cutflows study.

### Samples:
* 4topSM v37 Sample: `user.jpoveda.t0756_v37.410080.MadGraphPythia8EvtGen_A14NNPDF23_4topSM.DAOD_SUSY2.s2608_r7725_p2613_output.root`
* ttbar v37 Sample: `user.jpoveda.t0756_v37.410000.PowhegPythiaEvtGen_P2012_ttbar_hdamp17    2p5_nonallhad.DAOD_SUSY2.s2608_r7725_p2613_output.root`


### v08:
Change the descriptions in `README.md`


### v07:
Add ttbar samples into `util/cutflow.cxx`


### v06:
Modify the `yt_cutflows.h` and `yt_selector.h`

1. Add `degug_print()` functions.
2. Correct the prototypes of `pass_at_least_one_bjet_greater_than_20GeV()` and `pass_four_jets_greater_than_50GeV()` functions.


### v05: Comment out some output.


### v04: Add EventNumber protection.
1. Using the `passOR` vectors to fill the signal vectors.
2. Adding `vec_event_number` to save `EventNumber`. Use this mechanism to protect the channel selection part. All the events used in channel selection must be the events pass same-sign cut.


### v03: Add channel selection
Adding codes for channel selection. As long as there are at lease two signal leptons with pT>20 GeV, we don’t require the pT of same sign pair greater than 20 GeV.


### v02: Make RootCore package structure.
Creating folders and moving files to the corresponding folders such that the structure satisfies the RootCore requirement.


### v01: First commit
The cutflow works to same sign cut.
