#!/bin/bash
function run_signal_optimization() {
    Run optimization isMC NUHM2_m12_300_strong > optimization_MC_NUHM2_m12_300_strong.log 2>&1 &
    Run optimization isMC NUHM2_m12_350_strong > optimization_MC_NUHM2_m12_350_strong.log 2>&1 &
    Run optimization isMC NUHM2_m12_400_strong > optimization_MC_NUHM2_m12_400_strong.log 2>&1 &
    Run optimization isMC NUHM2_m12_500_strong > optimization_MC_NUHM2_m12_500_strong.log 2>&1 &
    Run optimization isMC NUHM2_m12_600_strong > optimization_MC_NUHM2_m12_600_strong.log 2>&1 &
    Run optimization isMC NUHM2_m12_700_strong > optimization_MC_NUHM2_m12_700_strong.log 2>&1 &
    Run optimization isMC NUHM2_m12_800_strong > optimization_MC_NUHM2_m12_800_strong.log 2>&1 &
}

function run_background_optimization_v44() {
    Run optimization isMC Zee > optimization_MC_Zee.log 2>&1 &
    Run optimization isMC Zmumu > optimization_MC_Zmumu.log 2>&1 &
    Run optimization isMC Ztautau > optimization_MC_Ztautau.log 2>&1 &

    Run optimization isMC Wplusenu > optimization_MC_Wplusenu.log 2>&1 &
    Run optimization isMC Wplusmunu > optimization_MC_Wplusmunu.log 2>&1 &
    Run optimization isMC Wplustaunu > optimization_MC_Wplustaunu.log 2>&1 &
    Run optimization isMC Wminusenu > optimization_MC_Wminusenu.log 2>&1 &
    Run optimization isMC Wminusmunu > optimization_MC_Wminusmunu.log 2>&1 &
    Run optimization isMC Wminustaunu > optimization_MC_Wminustaunu.log 2>&1 &

    Run optimization isMC ttee_Np0 > optimization_MC_ttee_Np0.log 2>&1 &
    Run optimization isMC ttee_Np1 > optimization_MC_ttee_Np1.log 2>&1 &
    Run optimization isMC ttmumu_Np0 > optimization_MC_ttmumu_Np0.log 2>&1 &
    Run optimization isMC ttmumu_Np1 > optimization_MC_ttmumu_Np1.log 2>&1 &
    Run optimization isMC tttautau_Np0 > optimization_MC_tttautau_Np0.log 2>&1 &
    Run optimization isMC tttautau_Np1 > optimization_MC_tttautau_Np1.log 2>&1 &

    Run optimization isMC ttW_Np0 > optimization_MC_ttW_Np0.log 2>&1 &
    Run optimization isMC ttW_Np1 > optimization_MC_ttW_Np1.log 2>&1 &
    Run optimization isMC ttW_Np2 > optimization_MC_ttW_Np2.log 2>&1 &

    Run optimization isMC ttbar > optimization_MC_ttbar.log 2>&1 &
    Run optimization isMC ttbarHT6c_1k_hdamp172p5 > optimization_MC_ttbarHT6c_1k_hdamp172p5.log 2>&1 &
    Run optimization isMC ttbarHT1k_1k5_hdamp172p5 > optimization_MC_ttbarHT1k_1k5_hdamp172p5.log 2>&1 &
    Run optimization isMC ttbarHT1k5_hdamp172p5_no > optimization_MC_ttbarHT1k5_hdamp172p5_no.log 2>&1 &

    Run optimization isMC ttbarWW > optimization_MC_ttbarWW.log 2>&1 &

    Run optimization isMC 3top_SM > optimization_MC_3top_SM.log 2>&1 &
    Run optimization isMC 4top_SM > optimization_MC_4top_SM.log 2>&1 &

    Run optimization isMC singletop_tchan_lept_top > optimization_MC_singletop_tchan_lept_top.log 2>&1 &
    Run optimization isMC singletop_tchan_lept_antitop > optimization_MC_singletop_tchan_lept_antitop.log 2>&1 &

    Run optimization isMC Wt_inclusive_top > optimization_MC_Wt_inclusive_top.log 2>&1 &
    Run optimization isMC Wt_inclusive_antitop > optimization_MC_Wt_inclusive_antitop.log 2>&1 &
    Run optimization isMC Wt_dilepton_top > optimization_MC_Wt_dilepton_top.log 2>&1 &
    Run optimization isMC Wt_dilepton_antitop > optimization_MC_Wt_dilepton_antitop.log 2>&1 &

    Run optimization isMC WqqZll > optimization_MC_WqqZll.log 2>&1 &
    Run optimization isMC ZqqZll > optimization_MC_ZqqZll.log 2>&1 &

    Run optimization isMC ZZZ_6l0v > optimization_MC_ZZZ_6l0v.log 2>&1 &
    Run optimization isMC ZZZ_4l2v > optimization_MC_ZZZ_4l2v.log 2>&1 &
    Run optimization isMC ZZZ_2l4v > optimization_MC_ZZZ_2l4v.log 2>&1 &

    Run optimization isMC lllvSFMinus > optimization_MC_lllvSFMinus.log 2>&1 &
    Run optimization isMC lllvOFMinus > optimization_MC_lllvOFMinus.log 2>&1 &
    Run optimization isMC lllvSFPlus > optimization_MC_lllvSFPlus.log 2>&1 &
    Run optimization isMC lllvOFPlus > optimization_MC_lllvOFPlus.log 2>&1 &

    Run optimization isMC ggllll > optimization_MC_ggllll.log 2>&1 &
    Run optimization isMC ggllvv > optimization_MC_ggllvv.log 2>&1 &

    Run optimization isMC llll > optimization_MC_llll.log 2>&1 &
    Run optimization isMC llvv > optimization_MC_llvv.log 2>&1 &

    Run optimization isMC llvvjj_ss_EW4 > optimization_MC_llvvjj_ss_EW4.log 2>&1 &
    Run optimization isMC llvvjj_ss_EW6 > optimization_MC_llvvjj_ss_EW6.log 2>&1 &
    Run optimization isMC lllvjj_EW6 > optimization_MC_lllvjj_EW6.log 2>&1 &
    Run optimization isMC lllljj_EW6 > optimization_MC_lllljj_EW6.log 2>&1 &
}

function run_background_optimization_v47() {
}

function run_background_optimization_v50() {
}

function run_background_optimization_v52() {
}
#####
#
# Main function
#
#####

run_signal_optimization

