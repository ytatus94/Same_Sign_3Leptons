# SS_v16
This cutflows codes are for SS/3L+jets v16 ntuple.
1. Use strong MC production file mc15_13TeV.370602.MGPy8EG_A14N23LO_NUHM2_m12_400_strong.merge.AOD.e4209_a766_a777_r6282_tid05980351_00 to generate SUSY2 derivations.
2. Use Ximo's ntuple maker, SS3LAnalysis v16, to run the SUSY2 derivations and product the flat ntuple mc15_13TeV.370602.MGPy8EG_A14N23LO_NUHM2_m12_400_strong.merge.DAOD.e4209_a766_a777_r6282.root
3. Use the flat ntuple to make TSelector: AnaNtupSelector.h and AnaNtupSelector.cxx
4. Copy the codes from SS_v12 and make some modification in order to run v16 ntuple.
Such as adding some variables in Lepton.h and Jet.h and correct the Fill_and_Set.cxx and the FillXXXX functions in MySelector.h and MySelector.cxx

v01:
Copy everything  from Lxplus to local and then commit to GitHub.
