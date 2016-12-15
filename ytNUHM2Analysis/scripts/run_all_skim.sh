#!/bin/bash
Run skim isMC Zee > skim_MC_Zee.log 2>&1 &
Run skim isMC Zmumu > skim_MC_Zmumu.log 2>&1 &
Run skim isMC ttbar > skim_MC_ttbar.log 2>&1 &
Run skim isMC GG_ttn1 > skim_MC_GG_ttn1.log 2>&1 &
Run skim isData sample=merged_data15 > skim_Data_merged_data15.log 2>&1 &
Run skim isData sample=merged_data16_periodA > skim_Data_merged_data16_periodA.log 2>&1 &
Run skim isData sample=merged_data16_periodB > skim_Data_merged_data16_periodB.log 2>&1 &
Run skim isData sample=merged_data16_periodC > skim_Data_merged_data16_periodC.log 2>&1 &
Run skim isData sample=merged_data16_periodD > skim_Data_merged_data16_periodD.log 2>&1 &
Run skim isData sample=merged_data16_periodE > skim_Data_merged_data16_periodE.log 2>&1 &
Run skim isData sample=merged_data16_periodF > skim_Data_merged_data16_periodF.log 2>&1 &
Run skim isData sample=merged_data16_periodG > skim_Data_merged_data16_periodG.log 2>&1 &
Run skim isData sample=merged_data16_periodI > skim_Data_merged_data16_periodI.log 2>&1 &
Run skim isData sample=merged_data16_rest > skim_Data_merged_data16_rest.log 2>&1 &
