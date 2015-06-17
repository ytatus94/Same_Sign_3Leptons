# SS_v12
This contains the codes for analysing Ximo's v12 ntuples.
Use data SUSY9 and MC SUSY5 on grid: user.jpoveda.t0609_v12.*_output.root/

v01:
1. Using MakeSelector in ROOT to generate AnaNtupSelector.{h,C}. And change .C to .cxx.
2. MySelector are inherited from AnaNtupSelector.
3. The particles classes are defined in
   - Particle.h: define a Particle class which contains basic properties of particles, such as pt, eta, phi, and E.
   - Leptons.h: basic properties of leptons are defined in Lepton class which inherits from Particle class. The Muon and Electron classes are inherit from Lepton class.
   - Jet.h: properties of Jets which inherits from Particle class.
4. OverlapRemoval and the other useful functions are defined in separate files.
