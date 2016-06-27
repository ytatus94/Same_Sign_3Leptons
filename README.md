# SS_v37
This is SS/3L+jet cutflows study.
Sample:  user.jpoveda.t0756_v37.410080.MadGraphPythia8EvtGen_A14NNPDF23_4topSM.DAOD_SUSY2.s2608_r7725_p2613_output.root

v14:(debug branch) This version cat correct number of events using 4topSM sample without applying Trigger matching.
But also get the same ttbar results as Simon's results except cut 5 and cut 6.
1. Correct the Fill_and_Set.cxx: the fabs(mu_itr.get_z0sinTheta()) < 0.5
2. Add pass_trigger_matching(), but still comment this part.
3. Read data on EOS.
4. README.md
5. ytCutflows/yt_cutflows.h
6. util/cutflow.cxx
7. Root/Fill_and_Set.cxx
8. Root/yt_cutflows.cxx
9. Root/yt_selector.cxx
10. Add 4topSM and ttbar results.
11. Add Juilien's results for cut11 using 4topSM.

v13:(debug branch) This version can get correct number of events using 4topSM sample.
1. README.md
2. Root/yt_cutflows.cxx
3. Root/yt_selector.cxx

v12:(debug branch) Modify 6 files and add .gitignore
1. ytCutflows/yt_selector.h
2. ytCutflows/yt_cutflows.h
3. Root/yt_selector.cxx
4. Root/yt_cutflows.cxx
5. Root/Fill_and_Set.cxx
6. Root/LinkDef.h

v11:(debug branch) Modify 3 files
1. Root/Fill_and_Set.cxx
2. Root/yt_cutflows.cxx
3. Root/yt_selector.cxx

v10:(debug branch) Fix the isBjet problem in Jet.h
Initialize isBjet to 0 in the constructor to avoid memory leak.

v09:(debug branch) This version get 4top sample agree to cut13
1. Root/Fill_and_Set.cxx: comment out fill_baseline_xxx()
2. Root/yt_cutflows.cxx: change pass_same_sign()
3. Root/yt_selector.cxx: comment out vec_OR_xxx related lines.
4. util/cutflow.cxx: Add ttbar sample
5. ytCutflows/yt_selector.h: comment out the vec_OR_xxx and debug_print()


v08:(debug branch) Modify 4 files in branch debug
1. ytCutflows/yt_selector.h: uncomment vec_OR_xxx
2. Root/yt_selector.cxx:
3. Root/yt_cutflow.cxx:
4. Root/Fill_and_Set.cxx


v06: Modify the yt_cutflows.h and yt_selector.h
1. Add degug_print functions.
2. Correct the prototypes of pass_at_least_one_bjet_greater_than_20GeV() and pass_four_jets_greater_than_50GeV() functions.


v05: comment out some output.

v04: Add EventNumber protection.
1. Using the passOR vectors to fill the signal vectors.
2. Adding vec_event_number to save EventNumber. Use this mechanism to protect the channel selection part. All the events used in channel selection must be the events pass same-sign cut.

v03: Add channel selection
Adding codes for channel selection. As long as there are at lease two signal leptons with pT>20 GeV, we don’t require the pT of same sign pair greater than 20 GeV.


v02: Make RootCore package structure.
Creating folders and moving files to the corresponding folders such that the structure satisfies the RootCore requirement.


v01: First commit
The cutflow works to same sign cut.
