# SS_v44
This is SS/3L+jet cutflows study v44.

Sample: user.jpoveda.t0789_v44.410080.MadGraphPythia8EvtGen_A14NNPDF23_4topSM.DAOD_SUSY2.s2608_r7725_p2666_output.root

Use rcSetup Base,2.4.16

V12-01. Create a new MC_weight_comparison branch
1. This branch is based on v12.
2. The code is used to compare the weight with Ximo.
3. The EventNumber == 16646043 is used to compare the weight with Ximo. The results are:
-1941.45 * 0.414337 * 0.9755 * 1.00245 * 0.987084 * 1.00704 * 1.00711 * 0.969889 * 0.998115 * 0.969889 * 0.99829 * 0.969889 = -715.8978658001982

EventNumber=16646043
EventWeight=-1941.45
AvgMu=29.5
PRWrandomRunNumber=303560
PRWWeight=0.414337
Info in <CP::TPileupReweighting::GetCombinedWeight>: Initializing the subtool..
pileupwgh=0.530051
*** Event Number=16646043
NEl=2
1: pt=44977.2, eta=-0.859558, etaclus=-0.855311, phi=-1.73185, baseline=1, passOR=1, isSignal=1, flavor=11, charge=-1, |d0sig|=0.0193125, |z0sinTheta|=0.0201597, ptvarcone20/pt=0, topoetcone20/pt=0.0261693, trigMatch_2e12_lhloose_L12EM10VH=1, trigMatch_e17_lhloose_mu14=0, trigMatch_2e17_lhvloose_nod0=1, trigMatch_e17_lhloose_nod0_mu14=0, SFwMediumLH=0.9755, SFwLooseAndBLayerLH=0.9872, IsoSFwMediumLH=1.00245, SFwTrigMediumLH_e12_lhloose_L1EM10VH=0.9978, SFwTrigMediumLH_e17_lhloose=0.99351, SFwTrigMediumLH_single=0.98396, SFwTrigLooseAndBLayerLH_e12_lhloose_L1EM10VH=0.9
2: pt=35632.1, eta=0.165315, etaclus=0.169984, phi=1.86222, baseline=1, passOR=1, isSignal=1, flavor=11, charge=1, |d0sig|=0.589697, |z0sinTheta|=0.049366, ptvarcone20/pt=0, topoetcone20/pt=-0.0208897, trigMatch_2e12_lhloose_L12EM10VH=1, trigMatch_e17_lhloose_mu14=0, trigMatch_2e17_lhvloose_nod0=1, trigMatch_e17_lhloose_nod0_mu14=0, SFwMediumLH=0.987084, SFwLooseAndBLayerLH=0.991709, IsoSFwMediumLH=1.00704, SFwTrigMediumLH_e12_lhloose_L1EM10VH=1.00032, SFwTrigMediumLH_e17_lhloose=1.00014, SFwTrigMediumLH_single=1.00426, SFwTrigLooseAndBLayerLH_e12_lhloose_L1EM10VH=0.9
*** Event Number=16646043
NJet=3
1: pt=27334.4, eta=-0.0621781, phi=0.71565, baseline=1, passOR=1, isBjet=1, quality=0, JVT=1, MV2c10=0.994369, SFw=1.00711, JVTsf=0.969889
2: pt=21867.4, eta=-0.244413, phi=1.33076, baseline=1, passOR=1, isBjet=0, quality=0, JVT=0.988756, MV2c10=0.546097, SFw=0.998115, JVTsf=0.969889
3: pt=21691.2, eta=0.908503, phi=1.48255, baseline=1, passOR=1, isBjet=0, quality=0, JVT=0.927557, MV2c10=-0.376234, SFw=0.99829, JVTsf=0.969889


v12. Add weight calculation and change indentations.
1. In yt_selector: change the indentations of fill methods, add new methods for calculating weights.
2. In yt_cutflows: change the type of events_pass_cutflow from unsigned int to double. Also change the PRW file.
3. In yt_skim_MC: add baseline_weight and signal_weight.
4. In Fill_and_Set.cxx: change the indentations.
5. In cutflow.cxx: add Zee testing samples.

v11. Add sample 303421 to test the skim and the lumi is set to 13.2 fb-1.

v10. Add the tag single lepton trigger which Sebastien used.
But still comment the tag single lepton trigger.

v09. Add _SKIM_ in the preprocessor.
1. Modify yt_selector.h, yt_selector.cxx, and cutflow.cxx

v08. Correct TriggMatched to TriggerMatched.
1. Modify yt_skim_MC.h, yt_skim_MC.cxx, yt_skim_data.h, and yt_skim_data.cxx.

v07. Add data samples in cutflow.cxx.
1. The data run 303304 is added.

v06. Provide set functions and luminosity now becomes an input in the cutflow.cxx.
1. Provide set functions for yt_selector class.
2. Change the type of events_pass_cutflow from int to unsigned int.
3. Luminosity becomes an input in the cutflow.cxx.
4. Use PRWWeight instead calculated by myself.
5. Modify yt_selector.h, yt_cutflows.h, yt_cutflows.cxx, and cutflow.cxx.

v05. Add _IS_DATA_ and _IS_MC_ in the preprocessor.
1. The code knows to use data or MC once the #define _IS_MC_ and #define _IS_DATA_ set correctly.
2. The fill functions have two version, one is for MC and another is for data.
3. Modify yt_selector.h, yt_selector.cxx, and Fill_and_Set.cxx.

v04. Add skimming codes.

v03. This version gets correct cutflow results.

v02. Add rcSetup version in README.md.

v01. Initial commit.
