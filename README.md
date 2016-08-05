# SS_v44
This is SS/3L+jet cutflows study v44.

Sample: user.jpoveda.t0789_v44.410080.MadGraphPythia8EvtGen_A14NNPDF23_4topSM.DAOD_SUSY2.s2608_r7725_p2666_output.root

Use rcSetup Base,2.4.16

v08. Correct TriggMatched to TriggerMatched

v07. Add data samples in cutflow.cxx

v06. Provide set functions and luminosity now becomes an input in the cutflow.cxx
1. Provide set functions for yt_selector.
2. Change the type of events_pass_cutflow from int to unsigned int.
3. Luminosity becomes an input in the cutflow.cxx.
4. Use PRWWeight instead calculated by myself.

v05. Add _IS_DATA_ and _IS_MC_ in the preprocessor
The code knows to use data or MC once the #define _IS_MC_ and #define _IS_DATA_ set correctly.

v04. Add skimming codes.

v03. This version gets correct cutflow results

v02. Add rcSetup version in README.md

v01. Initial commit
