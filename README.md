# SS_v04_bunch_spacing_study
The 25 ns vs 50 ns bunch spacing study for SS/3L+jets

v01:
Modify from AnaNtupV04Selector.h and AnaNtupV04Selector.C.
The run.cxx run the root file for cutflow comparison and can get the same results.
Comment out the lines include Jet_deltaR because the root file has no Jet_deltaR branch.

v02:
Uncomment the Jet_deltaR branch in codes.

v03:
Modify some histogram Fill() functions.
Fill pT, eta, phi using TLorentzVector in Fill().

v04:
Add new classes in header and source.
Modify run.cxx to run the 50ns root file.
user.jpoveda.t26_v04.50ns.110401.PowhegPythia_P2012_ttbar_nonallhad_output.root/
Add functions to make plots in run.cxx.

v05:
Fix the bug in FillMuon().
The order of the argument must match the order in the branch.

v06:
Comment out the lines include Jet_deltaR in header and source files.
Modify run.cxx to run 25ns root file.
user.jpoveda.t26_v04_p1872.204533.Herwigpp_UEEE4_CTEQ6L1_Gtt_G1000_T5000_L100_output.root.24717794
This version can get the same result as cutflow study.
