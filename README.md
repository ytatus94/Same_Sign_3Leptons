# SS_v12
This contains the codes for analysing Ximo's v12 ntuples.
Use data SUSY9 and MC SUSY5 on grid: user.jpoveda.t0609_v12.*_output.root/

v01:
1. Using MakeSelector in ROOT to generate AnaNtupSelector.{h,C}. And change .C to .cxx.
2. MySelector are inherited from AnaNtupSelector.
3. The particles classes are defined in:
   - Particle.h: define a Particle class which contains basic properties of particles, such as pt, eta, phi, and E.
   - Leptons.h: basic properties of leptons are defined in Lepton class which inherits from Particle class. The Muon and Electron classes are inherit from Lepton class.
   - Jet.h: properties of Jets which inherits from Particle class.
4. OverlapRemoval and the other useful functions are defined in separate files.

v02:
After discussing with Ximo, lots of modifications are made in order to fix the bugs. This version can get the same number of events as other peoples results from cut 1 to cut 7.

v03:
Add channel selections.

v04:
This version can get the correct results using data 266904.

v05:
Migrate to RootCore. 
1. All of the files are slightly modified to fit the RootCore requirement.
   - The included header files become #include "MyPackages/XXXX.h" and #include "Root/XXXX.cxx".
   - Add #include <vector> and using std::vector in AnaNtupSelector.h.
   - In MySelector.h, remove the default value in OverlapRemoval() method.
2. Change OverlapRemoval.h to OverlapRemoval.cxx and change usefull_functions.h to usefull_functions.cxx.
3. Add main function in ssv12_cutflow.cxx.
4. Add LinkDef.h for generating dictionaries.
   - Must include the headers which contain TSelector, then create dictionaries.
5. Also add Ximo's Ana.cxx for reference.

v06:
1. Change Fill.h to Fill_and_Set.cxx
2. Remove Fill.h, OverlapRemoval.h, and useful_functions.h.
3. Use GoodRunsList package in MySelector.cxx

v07:
1. Add sigd0_fixed.h to fix d0 significance in electrons and muons for data and MC.
2. In Jet() constructor, initialize the cleaning to 0.
3. Add EventNumber in OverlapRemoval(). It is easy for debugging.
4. Correct the typo from get_phi() to get_eta() because |eta| < 2.8 for jet in overlap removal.
5. Move the GRL to the Begin()

v08:
1. Add d0 significance correction in Fill_and_Set.cxx to fix d0 when fill the value of d0 into electrons and muons.
2. Rewrite the part of the number of electrons, muons, and leptons calculations.
3. All the cuts from cut 10 are modified (on going).

v09:
This version can get the correct results using MC ttbar. But if run over all data, then the channel selection parts are all zeros.
The 32 events are matched with Ximo's results but they are opposite sign not same sign. Why???
ANS: in Data, we apply same-sign at cut 15 but we require same-sign when do channel selection in MC.

1. Add isMC and isData selections in ssv12_cutflow.cxx
2. Add isMC and isData flag in MySelector.cxx
3. Add RunNb in Fill methods to correct the d0 significance in Fill_and_Set.cxx
4. Modify channel selection parts to selection el-el, el-mu,mu-mu channels in MC.
