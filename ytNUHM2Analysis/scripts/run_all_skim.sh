#!/bin/bash
Run skim isMC Zee > skim_MC_Zee.log
Run skim isMC Zmumu > skim_MC_Zmumu.log
Run skim isMC ttbar > skim_MC_ttbar.log
Run skim isMC GG_ttn1 > skim_MC_GG_ttn1.log
Run skim isData sample=merged_data15.root > skim_Data_merged_data15.log
Run skim isData sample=merged_data16_periodA.root > skim_Data_merged_data16_periodA.log
Run skim isData sample=merged_data16_periodB.root > skim_Data_merged_data16_periodB.log
Run skim isData sample=merged_data16_periodC.root > skim_Data_merged_data16_periodC.log
Run skim isData sample=merged_data16_periodD.root > skim_Data_merged_data16_periodD.log
Run skim isData sample=merged_data16_periodE.root > skim_Data_merged_data16_periodE.log
Run skim isData sample=merged_data16_periodF.root > skim_Data_merged_data16_periodF.log
Run skim isData sample=merged_data16_periodG.root > skim_Data_merged_data16_periodG.log
Run skim isData sample=merged_data16_periodI.root > skim_Data_merged_data16_periodI.log
Run skim isData sample=merged_data16_rest.root > skim_Data_merged_data16_rest.log
