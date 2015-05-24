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
