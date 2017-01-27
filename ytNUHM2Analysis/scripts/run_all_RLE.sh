#!/bin/bash
RLE isData sample=merged_data15 electron > RLE_merged_data15_elec.log 2>&1 &
RLE isData sample=merged_data16_periodA electron > RLE_merged_data16_periodA_elec.log 2>&1 &
RLE isData sample=merged_data16_periodB electron > RLE_merged_data16_periodB_elec.log 2>&1 &
RLE isData sample=merged_data16_periodC electron > RLE_merged_data16_periodC_elec.log 2>&1 &
RLE isData sample=merged_data16_periodD electron > RLE_merged_data16_periodD_elec.log 2>&1 &
RLE isData sample=merged_data16_periodE electron > RLE_merged_data16_periodE_elec.log 2>&1 &
RLE isData sample=merged_data16_periodF electron > RLE_merged_data16_periodF_elec.log 2>&1 &
RLE isData sample=merged_data16_periodG electron > RLE_merged_data16_periodG_elec.log 2>&1 &
RLE isData sample=merged_data16_periodI electron > RLE_merged_data16_periodI_elec.log 2>&1 &
RLE isData sample=merged_data16_rest electron > RLE_merged_data16_rest_elec.log 2>&1 &
RLE isData sample=merged_data15 muon > RLE_merged_data15_muon.log 2>&1 &
RLE isData sample=merged_data16_periodA muon > RLE_merged_data16_periodA_muon.log 2>&1 &
RLE isData sample=merged_data16_periodB muon > RLE_merged_data16_periodB_muon.log 2>&1 &
RLE isData sample=merged_data16_periodC muon > RLE_merged_data16_periodC_muon.log 2>&1 &
RLE isData sample=merged_data16_periodD muon > RLE_merged_data16_periodD_muon.log 2>&1 &
RLE isData sample=merged_data16_periodE muon > RLE_merged_data16_periodE_muon.log 2>&1 &
RLE isData sample=merged_data16_periodF muon > RLE_merged_data16_periodF_muon.log 2>&1 &
RLE isData sample=merged_data16_periodG muon > RLE_merged_data16_periodG_muon.log 2>&1 &
RLE isData sample=merged_data16_periodI muon > RLE_merged_data16_periodI_muon.log 2>&1 &
RLE isData sample=merged_data16_rest muon > RLE_merged_data16_rest_muon.log 2>&1 &
RLE isMC Zee > RLE_Zee.log 2>&1 &
RLE isMC Zee_TandP_truth_match > RLE_Zee_TandP_truth_match.log 2>&1 &
RLE isMC Zee_truth_match > RLE_Zee_truth_match.log 2>&1 &
RLE isMC Zmumu > RLE_Zmumu.log 2>&1 &
RLE isMC Zmumu_TandP_truth_match > RLE_Zmumu_TandP_truth_match.log 2>&1 &
RLE isMC Zmumu_truth_match > RLE_Zmumu_truth_match.log 2>&1 &
RLE isMC ttbar electron > RLE_ttbar_elec.log 2>&1 &
RLE isMC ttbar muon > RLE_ttbar_muon.log 2>&1 &
RLE isMC GG_ttn1 electron > RLE_GG_ttn1_elec.log 2>&1 &
RLE isMC GG_ttn1 muon > RLE_GG_ttn1_muon.log 2>&1 &

# for trigger uncertainties study without tag_trigger_matched
# data only
RLE isData sample=merged_data15 electron trigger="dilepton_trigger" > RLE_merged_data15_elec_dilepton_trigger.log 2>&1 &
RLE isData sample=merged_data16_periodA electron trigger="dilepton_trigger" > RLE_merged_data16_periodA_elec_dilepton_trigger.log 2>&1 &
RLE isData sample=merged_data16_periodB electron trigger="dilepton_trigger" > RLE_merged_data16_periodB_elec_dilepton_trigger.log 2>&1 &
RLE isData sample=merged_data16_periodC electron trigger="dilepton_trigger" > RLE_merged_data16_periodC_elec_dilepton_trigger.log 2>&1 &
RLE isData sample=merged_data16_periodD electron trigger="dilepton_trigger" > RLE_merged_data16_periodD_elec_dilepton_trigger.log 2>&1 &
RLE isData sample=merged_data16_periodE electron trigger="dilepton_trigger" > RLE_merged_data16_periodE_elec_dilepton_trigger.log 2>&1 &
RLE isData sample=merged_data16_periodF electron trigger="dilepton_trigger" > RLE_merged_data16_periodF_elec_dilepton_trigger.log 2>&1 &
RLE isData sample=merged_data16_periodG electron trigger="dilepton_trigger" > RLE_merged_data16_periodG_elec_dilepton_trigger.log 2>&1 &
RLE isData sample=merged_data16_periodI electron trigger="dilepton_trigger" > RLE_merged_data16_periodI_elec_dilepton_trigger.log 2>&1 &
RLE isData sample=merged_data16_rest electron trigger="dilepton_trigger" > RLE_merged_data16_rest_elec_dilepton_trigger.log 2>&1 &
RLE isData sample=merged_data15 muon trigger="dilepton_trigger" > RLE_merged_data15_muon_dilepton_trigger.log 2>&1 &
RLE isData sample=merged_data16_periodA muon trigger="dilepton_trigger" > RLE_merged_data16_periodA_muon_dilepton_trigger.log 2>&1 &
RLE isData sample=merged_data16_periodB muon trigger="dilepton_trigger" > RLE_merged_data16_periodB_muon_dilepton_trigger.log 2>&1 &
RLE isData sample=merged_data16_periodC muon trigger="dilepton_trigger" > RLE_merged_data16_periodC_muon_dilepton_trigger.log 2>&1 &
RLE isData sample=merged_data16_periodD muon trigger="dilepton_trigger" > RLE_merged_data16_periodD_muon_dilepton_trigger.log 2>&1 &
RLE isData sample=merged_data16_periodE muon trigger="dilepton_trigger" > RLE_merged_data16_periodE_muon_dilepton_trigger.log 2>&1 &
RLE isData sample=merged_data16_periodF muon trigger="dilepton_trigger" > RLE_merged_data16_periodF_muon_dilepton_trigger.log 2>&1 &
RLE isData sample=merged_data16_periodG muon trigger="dilepton_trigger" > RLE_merged_data16_periodG_muon_dilepton_trigger.log 2>&1 &
RLE isData sample=merged_data16_periodI muon trigger="dilepton_trigger" > RLE_merged_data16_periodI_muon_dilepton_trigger.log 2>&1 &
RLE isData sample=merged_data16_rest muon trigger="dilepton_trigger" > RLE_merged_data16_rest_muon_dilepton_trigger.log 2>&1 &

RLE isData sample=merged_data15 electron trigger="dilepton_trigger_but_fail_single_lepton_trigger" > RLE_merged_data15_elec_dilepton_trigger_but_fail_single_lepton_trigger.log 2>&1 &
RLE isData sample=merged_data16_periodA electron trigger="dilepton_trigger_but_fail_single_lepton_trigger" > RLE_merged_data16_periodA_elec_dilepton_trigger_but_fail_single_lepton_trigger.log 2>&1 &
RLE isData sample=merged_data16_periodB electron trigger="dilepton_trigger_but_fail_single_lepton_trigger" > RLE_merged_data16_periodB_elec_dilepton_trigger_but_fail_single_lepton_trigger.log 2>&1 &
RLE isData sample=merged_data16_periodC electron trigger="dilepton_trigger_but_fail_single_lepton_trigger" > RLE_merged_data16_periodC_elec_dilepton_trigger_but_fail_single_lepton_trigger.log 2>&1 &
RLE isData sample=merged_data16_periodD electron trigger="dilepton_trigger_but_fail_single_lepton_trigger" > RLE_merged_data16_periodD_elec_dilepton_trigger_but_fail_single_lepton_trigger.log 2>&1 &
RLE isData sample=merged_data16_periodE electron trigger="dilepton_trigger_but_fail_single_lepton_trigger" > RLE_merged_data16_periodE_elec_dilepton_trigger_but_fail_single_lepton_trigger.log 2>&1 &
RLE isData sample=merged_data16_periodF electron trigger="dilepton_trigger_but_fail_single_lepton_trigger" > RLE_merged_data16_periodF_elec_dilepton_trigger_but_fail_single_lepton_trigger.log 2>&1 &
RLE isData sample=merged_data16_periodG electron trigger="dilepton_trigger_but_fail_single_lepton_trigger" > RLE_merged_data16_periodG_elec_dilepton_trigger_but_fail_single_lepton_trigger.log 2>&1 &
RLE isData sample=merged_data16_periodI electron trigger="dilepton_trigger_but_fail_single_lepton_trigger" > RLE_merged_data16_periodI_elec_dilepton_trigger_but_fail_single_lepton_trigger.log 2>&1 &
RLE isData sample=merged_data16_rest electron trigger="dilepton_trigger_but_fail_single_lepton_trigger" > RLE_merged_data16_rest_elec_dilepton_trigger_but_fail_single_lepton_trigger.log 2>&1 &
RLE isData sample=merged_data15 muon trigger="dilepton_trigger_but_fail_single_lepton_trigger" > RLE_merged_data15_muon_dilepton_trigger_but_fail_single_lepton_trigger.log 2>&1 &
RLE isData sample=merged_data16_periodA muon trigger="dilepton_trigger_but_fail_single_lepton_trigger" > RLE_merged_data16_periodA_muon_dilepton_trigger_but_fail_single_lepton_trigger.log 2>&1 &
RLE isData sample=merged_data16_periodB muon trigger="dilepton_trigger_but_fail_single_lepton_trigger" > RLE_merged_data16_periodB_muon_dilepton_trigger_but_fail_single_lepton_trigger.log 2>&1 &
RLE isData sample=merged_data16_periodC muon trigger="dilepton_trigger_but_fail_single_lepton_trigger" > RLE_merged_data16_periodC_muon_dilepton_trigger_but_fail_single_lepton_trigger.log 2>&1 &
RLE isData sample=merged_data16_periodD muon trigger="dilepton_trigger_but_fail_single_lepton_trigger" > RLE_merged_data16_periodD_muon_dilepton_trigger_but_fail_single_lepton_trigger.log 2>&1 &
RLE isData sample=merged_data16_periodE muon trigger="dilepton_trigger_but_fail_single_lepton_trigger" > RLE_merged_data16_periodE_muon_dilepton_trigger_but_fail_single_lepton_trigger.log 2>&1 &
RLE isData sample=merged_data16_periodF muon trigger="dilepton_trigger_but_fail_single_lepton_trigger" > RLE_merged_data16_periodF_muon_dilepton_trigger_but_fail_single_lepton_trigger.log 2>&1 &
RLE isData sample=merged_data16_periodG muon trigger="dilepton_trigger_but_fail_single_lepton_trigger" > RLE_merged_data16_periodG_muon_dilepton_trigger_but_fail_single_lepton_trigger.log 2>&1 &
RLE isData sample=merged_data16_periodI muon trigger="dilepton_trigger_but_fail_single_lepton_trigger" > RLE_merged_data16_periodI_muon_dilepton_trigger_but_fail_single_lepton_trigger.log 2>&1 &
RLE isData sample=merged_data16_rest muon trigger="dilepton_trigger_but_fail_single_lepton_trigger" > RLE_merged_data16_rest_muon_dilepton_trigger_but_fail_single_lepton_trigger.log 2>&1 &

# for trigger uncertainties study with tag_trigger_matched requirement
# data only
RLE isData sample=merged_data15 electron trigger="dilepton_trigger" tag_trigger_matched > RLE_merged_data15_elec_dilepton_trigger_tag_trigger_matched.log 2>&1 &
RLE isData sample=merged_data16_periodA electron trigger="dilepton_trigger" tag_trigger_matched > RLE_merged_data16_periodA_elec_dilepton_trigger_tag_trigger_matched.log 2>&1 &
RLE isData sample=merged_data16_periodB electron trigger="dilepton_trigger" tag_trigger_matched > RLE_merged_data16_periodB_elec_dilepton_trigger_tag_trigger_matched.log 2>&1 &
RLE isData sample=merged_data16_periodC electron trigger="dilepton_trigger" tag_trigger_matched > RLE_merged_data16_periodC_elec_dilepton_trigger_tag_trigger_matched.log 2>&1 &
RLE isData sample=merged_data16_periodD electron trigger="dilepton_trigger" tag_trigger_matched > RLE_merged_data16_periodD_elec_dilepton_trigger_tag_trigger_matched.log 2>&1 &
RLE isData sample=merged_data16_periodE electron trigger="dilepton_trigger" tag_trigger_matched > RLE_merged_data16_periodE_elec_dilepton_trigger_tag_trigger_matched.log 2>&1 &
RLE isData sample=merged_data16_periodF electron trigger="dilepton_trigger" tag_trigger_matched > RLE_merged_data16_periodF_elec_dilepton_trigger_tag_trigger_matched.log 2>&1 &
RLE isData sample=merged_data16_periodG electron trigger="dilepton_trigger" tag_trigger_matched > RLE_merged_data16_periodG_elec_dilepton_trigger_tag_trigger_matched.log 2>&1 &
RLE isData sample=merged_data16_periodI electron trigger="dilepton_trigger" tag_trigger_matched > RLE_merged_data16_periodI_elec_dilepton_trigger_tag_trigger_matched.log 2>&1 &
RLE isData sample=merged_data16_rest electron trigger="dilepton_trigger" tag_trigger_matched > RLE_merged_data16_rest_elec_dilepton_trigger_tag_trigger_matched.log 2>&1 &
RLE isData sample=merged_data15 muon trigger="dilepton_trigger" tag_trigger_matched > RLE_merged_data15_muon_dilepton_trigger_tag_trigger_matched.log 2>&1 &
RLE isData sample=merged_data16_periodA muon trigger="dilepton_trigger" tag_trigger_matched > RLE_merged_data16_periodA_muon_dilepton_trigger_tag_trigger_matched.log 2>&1 &
RLE isData sample=merged_data16_periodB muon trigger="dilepton_trigger" tag_trigger_matched > RLE_merged_data16_periodB_muon_dilepton_trigger_tag_trigger_matched.log 2>&1 &
RLE isData sample=merged_data16_periodC muon trigger="dilepton_trigger" tag_trigger_matched > RLE_merged_data16_periodC_muon_dilepton_trigger_tag_trigger_matched.log 2>&1 &
RLE isData sample=merged_data16_periodD muon trigger="dilepton_trigger" tag_trigger_matched > RLE_merged_data16_periodD_muon_dilepton_trigger_tag_trigger_matched.log 2>&1 &
RLE isData sample=merged_data16_periodE muon trigger="dilepton_trigger" tag_trigger_matched > RLE_merged_data16_periodE_muon_dilepton_trigger_tag_trigger_matched.log 2>&1 &
RLE isData sample=merged_data16_periodF muon trigger="dilepton_trigger" tag_trigger_matched > RLE_merged_data16_periodF_muon_dilepton_trigger_tag_trigger_matched.log 2>&1 &
RLE isData sample=merged_data16_periodG muon trigger="dilepton_trigger" tag_trigger_matched > RLE_merged_data16_periodG_muon_dilepton_trigger_tag_trigger_matched.log 2>&1 &
RLE isData sample=merged_data16_periodI muon trigger="dilepton_trigger" tag_trigger_matched > RLE_merged_data16_periodI_muon_dilepton_trigger_tag_trigger_matched.log 2>&1 &
RLE isData sample=merged_data16_rest muon trigger="dilepton_trigger" tag_trigger_matched > RLE_merged_data16_rest_muon_dilepton_trigger_tag_trigger_matched.log 2>&1 &

RLE isData sample=merged_data15 electron trigger="dilepton_trigger_but_fail_single_lepton_trigger" tag_trigger_matched > RLE_merged_data15_elec_dilepton_trigger_but_fail_single_lepton_trigger_tag_trigger_matched.log 2>&1 &
RLE isData sample=merged_data16_periodA electron trigger="dilepton_trigger_but_fail_single_lepton_trigger" tag_trigger_matched > RLE_merged_data16_periodA_elec_dilepton_trigger_but_fail_single_lepton_trigger_tag_trigger_matched.log 2>&1 &
RLE isData sample=merged_data16_periodB electron trigger="dilepton_trigger_but_fail_single_lepton_trigger" tag_trigger_matched > RLE_merged_data16_periodB_elec_dilepton_trigger_but_fail_single_lepton_trigger_tag_trigger_matched.log 2>&1 &
RLE isData sample=merged_data16_periodC electron trigger="dilepton_trigger_but_fail_single_lepton_trigger" tag_trigger_matched > RLE_merged_data16_periodC_elec_dilepton_trigger_but_fail_single_lepton_trigger_tag_trigger_matched.log 2>&1 &
RLE isData sample=merged_data16_periodD electron trigger="dilepton_trigger_but_fail_single_lepton_trigger" tag_trigger_matched > RLE_merged_data16_periodD_elec_dilepton_trigger_but_fail_single_lepton_trigger_tag_trigger_matched.log 2>&1 &
RLE isData sample=merged_data16_periodE electron trigger="dilepton_trigger_but_fail_single_lepton_trigger" tag_trigger_matched > RLE_merged_data16_periodE_elec_dilepton_trigger_but_fail_single_lepton_trigger_tag_trigger_matched.log 2>&1 &
RLE isData sample=merged_data16_periodF electron trigger="dilepton_trigger_but_fail_single_lepton_trigger" tag_trigger_matched > RLE_merged_data16_periodF_elec_dilepton_trigger_but_fail_single_lepton_trigger_tag_trigger_matched.log 2>&1 &
RLE isData sample=merged_data16_periodG electron trigger="dilepton_trigger_but_fail_single_lepton_trigger" tag_trigger_matched > RLE_merged_data16_periodG_elec_dilepton_trigger_but_fail_single_lepton_trigger_tag_trigger_matched.log 2>&1 &
RLE isData sample=merged_data16_periodI electron trigger="dilepton_trigger_but_fail_single_lepton_trigger" tag_trigger_matched > RLE_merged_data16_periodI_elec_dilepton_trigger_but_fail_single_lepton_trigger_tag_trigger_matched.log 2>&1 &
RLE isData sample=merged_data16_rest electron trigger="dilepton_trigger_but_fail_single_lepton_trigger" tag_trigger_matched > RLE_merged_data16_rest_elec_dilepton_trigger_but_fail_single_lepton_trigger_tag_trigger_matched.log 2>&1 &
RLE isData sample=merged_data15 muon trigger="dilepton_trigger_but_fail_single_lepton_trigger" tag_trigger_matched > RLE_merged_data15_muon_dilepton_trigger_but_fail_single_lepton_trigger_tag_trigger_matched.log 2>&1 &
RLE isData sample=merged_data16_periodA muon trigger="dilepton_trigger_but_fail_single_lepton_trigger" tag_trigger_matched > RLE_merged_data16_periodA_muon_dilepton_trigger_but_fail_single_lepton_trigger_tag_trigger_matched.log 2>&1 &
RLE isData sample=merged_data16_periodB muon trigger="dilepton_trigger_but_fail_single_lepton_trigger" tag_trigger_matched > RLE_merged_data16_periodB_muon_dilepton_trigger_but_fail_single_lepton_trigger_tag_trigger_matched.log 2>&1 &
RLE isData sample=merged_data16_periodC muon trigger="dilepton_trigger_but_fail_single_lepton_trigger" tag_trigger_matched > RLE_merged_data16_periodC_muon_dilepton_trigger_but_fail_single_lepton_trigger_tag_trigger_matched.log 2>&1 &
RLE isData sample=merged_data16_periodD muon trigger="dilepton_trigger_but_fail_single_lepton_trigger" tag_trigger_matched > RLE_merged_data16_periodD_muon_dilepton_trigger_but_fail_single_lepton_trigger_tag_trigger_matched.log 2>&1 &
RLE isData sample=merged_data16_periodE muon trigger="dilepton_trigger_but_fail_single_lepton_trigger" tag_trigger_matched > RLE_merged_data16_periodE_muon_dilepton_trigger_but_fail_single_lepton_trigger_tag_trigger_matched.log 2>&1 &
RLE isData sample=merged_data16_periodF muon trigger="dilepton_trigger_but_fail_single_lepton_trigger" tag_trigger_matched > RLE_merged_data16_periodF_muon_dilepton_trigger_but_fail_single_lepton_trigger_tag_trigger_matched.log 2>&1 &
RLE isData sample=merged_data16_periodG muon trigger="dilepton_trigger_but_fail_single_lepton_trigger" tag_trigger_matched > RLE_merged_data16_periodG_muon_dilepton_trigger_but_fail_single_lepton_trigger_tag_trigger_matched.log 2>&1 &
RLE isData sample=merged_data16_periodI muon trigger="dilepton_trigger_but_fail_single_lepton_trigger" tag_trigger_matched > RLE_merged_data16_periodI_muon_dilepton_trigger_but_fail_single_lepton_trigger_tag_trigger_matched.log 2>&1 &
RLE isData sample=merged_data16_rest muon trigger="dilepton_trigger_but_fail_single_lepton_trigger" tag_trigger_matched > RLE_merged_data16_rest_muon_dilepton_trigger_but_fail_single_lepton_trigger_tag_trigger_matched.log 2>&1 &
