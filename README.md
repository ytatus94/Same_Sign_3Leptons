# SS_v39This is SS/3L+jet cutflows study v39.
Sample: user.jpoveda.t0769_v39.410080.MadGraphPythia8EvtGen_A14NNPDF23_4topSM.DAOD_SUSY2.s2608_r7725_p2613
Use rcSetup Base,2.4.12 and check out this package.

v03. This version can get correct cutflow results using 4topSM sample.
1. Add cutflow results using 4topSM sample.
2. Add Ximo's results for trigger matching in each channel: ssee.txt, ssemu.txt, ssmumu.txt
3. Add Ximo's results for mu-mu channel selection: ssmm_nomatch.txt
4. Fixed Fill_and_Set.cxx:
   4a.) using Mu_trigMatch_e17_lhloose_mu14->at(2*i)
   4b.) using fabs(mu_itr.get_z0sinTheta())
5. Add pass_trigger_matching()
6. ytCutflows/yt_selector.h
7. ytCutflows/yt_cutflows.h
8. Root/yt_selector.cxx
9. Root/yt_cutflows.cxx
10. Root/Fill_and_Set.cxx

v02. remove diff.log
Remove ytCutflows/ytCutflows/diff.log

v01. initial commit
The current cutflow works till cut 12  >=2 signal leptons >20 GeV but with one more event in same-sign cut. The extra event is in mu-mu channel.
