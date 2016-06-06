#ifdef YT_SELECTOR_CXX
#ifndef FILL_AND_SET_CXX
#define FILL_AND_SET_CXX

// Fill methods
/*
void yt_selector::fill_HLT(Bool_t	HLT_e24_lhmedium_nod0_ivarloose,
						   Bool_t	HLT_e24_lhtight_nod0_ivarloose,
						   Bool_t	HLT_e26_lhtight_iloose,
						   Bool_t	HLT_e26_lhtight_ivarloose,
						   Bool_t	HLT_e26_lhtight_nod0_iloose,
						   Bool_t	HLT_e26_lhtight_nod0_ivarloose,
						   Bool_t	HLT_e60_lhmedium,
						   Bool_t	HLT_e60_lhmedium_nod0,
						   Bool_t	HLT_e120_lhloose_nod0,
						   Bool_t	HLT_e140_lhloose_nod0,
						   Bool_t	HLT_2e17_lhvloose_nod0,
						   Bool_t	HLT_2e15_lhvloose_nod0_L12EM13VH,
						   Bool_t	HLT_e24_lhmedium_e9_lhmedium,
						   Bool_t	HLT_e24_lhmedium_L1EM20VH,
						   Bool_t	HLT_e12_lhvloose_L12EM10VH,
						   Bool_t	HLT_e17_lhloose_2e9_lhloose,
						   Bool_t	HLT_mu24_ivarmedium,
						   Bool_t	HLT_mu24_imedium,
						   Bool_t	HLT_mu24_ivarloose,
						   Bool_t	HLT_mu24_iloose,
						   Bool_t	HLT_mu26_ivarmedium,
						   Bool_t	HLT_mu26_imedium,
						   Bool_t	HLT_mu20_ivarmedium_L1MU15,
						   Bool_t	HLT_mu20_imedium_L1MU15,
						   Bool_t	HLT_mu20_ivarloose_L1MU15,
						   Bool_t	HLT_mu20_iloose_L1MU15,
						   Bool_t	HLT_mu20_L1MU15,
						   Bool_t	HLT_mu20_mu8noL1,
						   Bool_t	HLT_mu22_mu8noL1,
						   Bool_t	HLT_mu22_2mu4noL1,
						   Bool_t	HLT_mu40,
						   Bool_t	HLT_mu50,
						   Bool_t	HLT_2mu10,
						   Bool_t	HLT_2mu10_nomucomb,
						   Bool_t	HLT_2mu14,
						   Bool_t	HLT_2mu14_nomucomb,
						   Bool_t	HLT_3mu6,
						   Bool_t	HLT_3mu6_msonly,
						   Bool_t	HLT_xe100_L1XE50,
						   Bool_t	HLT_xe80_mht_L1XE50,
						   Bool_t	HLT_xe90_mht_L1XE50,
						   Bool_t	HLT_xe110_pueta_L1XE50,
						   Bool_t	HLT_xe110_pufit_L1XE50,
						   Bool_t	HLT_xe100_tc_em_L1XE50,
						   Bool_t	HLT_xe80_tc_lcw_L1XE50,
						   Bool_t	HLT_xe90_tc_lcw_L1XE50,
						   Bool_t	HLT_xe80_tc_lcw_wEFMu_L1XE50,
						   Bool_t	HLT_e7_lhmedium_mu24,
						   Bool_t	HLT_e17_lhloose_nod0_mu14,
						   Bool_t	HLT_e26_lhmedium_nod0_L1EM22VHI_mu8noL1,
						   Bool_t	HLT_e24_lhmedium_nod0_L1EM22VHI_mu8noL1,
						   Bool_t	HLT_2e12_lhloose_L12EM10VH,
						   Bool_t	HLT_e17_lhloose_mu14,
						   Bool_t	HLT_mu18_mu8noL1,
						   Bool_t	HLT_xe70)
{
	HLT_object->set_HLT_e24_lhmedium_nod0_ivarloose(HLT_e24_lhmedium_nod0_ivarloose);
	HLT_object->set_HLT_e24_lhtight_nod0_ivarloose(HLT_e24_lhtight_nod0_ivarloose);
	HLT_object->set_HLT_e26_lhtight_iloose(HLT_e26_lhtight_iloose);
	HLT_object->set_HLT_e26_lhtight_ivarloose(HLT_e26_lhtight_ivarloose);
	HLT_object->set_HLT_e26_lhtight_nod0_iloose(HLT_e26_lhtight_nod0_iloose);
	HLT_object->set_HLT_e26_lhtight_nod0_ivarloose(HLT_e26_lhtight_nod0_ivarloose);
	HLT_object->set_HLT_e60_lhmedium(HLT_e60_lhmedium);
	HLT_object->set_HLT_e60_lhmedium_nod0(HLT_e60_lhmedium_nod0);
	HLT_object->set_HLT_e120_lhloose_nod0(HLT_e120_lhloose_nod0);
	HLT_object->set_HLT_e140_lhloose_nod0(HLT_e140_lhloose_nod0);
	HLT_object->set_HLT_2e17_lhvloose_nod0(HLT_2e17_lhvloose_nod0);
	HLT_object->set_HLT_2e15_lhvloose_nod0_L12EM13VH(HLT_2e15_lhvloose_nod0_L12EM13VH);
	HLT_object->set_HLT_e24_lhmedium_e9_lhmedium(HLT_e24_lhmedium_e9_lhmedium);
	HLT_object->set_HLT_e24_lhmedium_L1EM20VH(HLT_e24_lhmedium_L1EM20VH);
	HLT_object->set_HLT_e12_lhvloose_L12EM10VH(HLT_e12_lhvloose_L12EM10VH);
	HLT_object->set_HLT_e17_lhloose_2e9_lhloose(HLT_e17_lhloose_2e9_lhloose);
	HLT_object->set_HLT_mu24_ivarmedium(HLT_mu24_ivarmedium);
	HLT_object->set_HLT_mu24_imedium(HLT_mu24_imedium);
	HLT_object->set_HLT_mu24_ivarloose(HLT_mu24_ivarloose);
	HLT_object->set_HLT_mu24_iloose(HLT_mu24_iloose);
	HLT_object->set_HLT_mu26_ivarmedium(HLT_mu26_ivarmedium);
	HLT_object->set_HLT_mu26_imedium(HLT_mu26_imedium);
	HLT_object->set_HLT_mu20_ivarmedium_L1MU15(HLT_mu20_ivarmedium_L1MU15);
	HLT_object->set_HLT_mu20_imedium_L1MU15(HLT_mu20_imedium_L1MU15);
	HLT_object->set_HLT_mu20_ivarloose_L1MU15(HLT_mu20_ivarloose_L1MU15);
	HLT_object->set_HLT_mu20_iloose_L1MU15(HLT_mu20_iloose_L1MU15);
	HLT_object->set_HLT_mu20_L1MU15(HLT_mu20_L1MU15);
	HLT_object->set_HLT_mu20_mu8noL1(HLT_mu20_mu8noL1);
	HLT_object->set_HLT_mu22_mu8noL1(HLT_mu22_mu8noL1);
	HLT_object->set_HLT_mu22_2mu4noL1(HLT_mu22_2mu4noL1);
	HLT_object->set_HLT_mu40(HLT_mu40);
	HLT_object->set_HLT_mu50(HLT_mu50);
	HLT_object->set_HLT_2mu10(HLT_2mu10);
	HLT_object->set_HLT_2mu10_nomucomb(HLT_2mu10_nomucomb);
	HLT_object->set_HLT_2mu14(HLT_2mu14);
	HLT_object->set_HLT_2mu14_nomucomb(HLT_2mu14_nomucomb);
	HLT_object->set_HLT_3mu6(HLT_3mu6);
	HLT_object->set_HLT_3mu6_msonly(HLT_3mu6_msonly);
	HLT_object->set_HLT_xe100_L1XE50(HLT_xe100_L1XE50);
	HLT_object->set_HLT_xe80_mht_L1XE50(HLT_xe80_mht_L1XE50);
	HLT_object->set_HLT_xe90_mht_L1XE50(HLT_xe90_mht_L1XE50);
	HLT_object->set_HLT_xe110_pueta_L1XE50(HLT_xe110_pueta_L1XE50);
	HLT_object->set_HLT_xe110_pufit_L1XE50(HLT_xe110_pufit_L1XE50);
	HLT_object->set_HLT_xe100_tc_em_L1XE50(HLT_xe100_tc_em_L1XE50);
	HLT_object->set_HLT_xe80_tc_lcw_L1XE50(HLT_xe80_tc_lcw_L1XE50);
	HLT_object->set_HLT_xe90_tc_lcw_L1XE50(HLT_xe90_tc_lcw_L1XE50);
	HLT_object->set_HLT_xe80_tc_lcw_wEFMu_L1XE50(HLT_xe80_tc_lcw_wEFMu_L1XE50);
	HLT_object->set_HLT_e7_lhmedium_mu24(HLT_e7_lhmedium_mu24);
	HLT_object->set_HLT_e17_lhloose_nod0_mu14(HLT_e17_lhloose_nod0_mu14);
	HLT_object->set_HLT_e26_lhmedium_nod0_L1EM22VHI_mu8noL1(HLT_e26_lhmedium_nod0_L1EM22VHI_mu8noL1);
	HLT_object->set_HLT_e24_lhmedium_nod0_L1EM22VHI_mu8noL1(HLT_e24_lhmedium_nod0_L1EM22VHI_mu8noL1);
	HLT_object->set_HLT_2e12_lhloose_L12EM10VH(HLT_2e12_lhloose_L12EM10VH);
	HLT_object->set_HLT_e17_lhloose_mu14(HLT_e17_lhloose_mu14);
	HLT_object->set_HLT_mu18_mu8noL1(HLT_mu18_mu8noL1);
	HLT_object->set_HLT_xe70(HLT_xe70);
}
*/
void yt_selector::fill_electrons(Int_t           NEl,
								 int             flavor,
								 vector<double>  *El_eta,
								 vector<double>  *El_etaclus,
								 vector<double>  *El_phi,
								 vector<double>  *El_pT,
								 vector<double>  *El_E,
								 vector<int>     *El_charge,
								 vector<double>  *El_sigd0,
								 vector<double>  *El_z0sinTheta,
								 vector<double>  *El_d0pvtx,
								 vector<bool>    *El_passOR,
								 vector<double>  *El_SFwMediumLH,
								 vector<float>   *El_IsoSFwTightLH,
								 vector<double>  *El_SFwTightLH,
								 vector<double>  *El_SFwLooseAndBLayerLH,
								 vector<double>  *El_SFwTrigMediumLH_e12_lhloose_L1EM10VH,
								 vector<double>  *El_SFwTrigTightLH_e12_lhloose_L1EM10VH,
								 vector<double>  *El_SFwTrigTightLH_e17_lhloose,
								 vector<double>  *El_SFwTrigTightLH_single,
								 vector<double>  *El_SFwTrigLooseAndBLayerLH_e12_lhloose_L1EM10VH,
								 vector<bool>    *El_isLooseAndBLayerLH,
								 vector<bool>    *El_isMediumLH,
								 vector<bool>    *El_isTightLH,
								 vector<int>     *El_nBLayerHits,
								 vector<int>     *El_expectBLayerHit,
								 vector<int>     *El_type,
								 vector<int>     *El_origin,
								 vector<int>     *El_bkgMotherPdgId,
								 vector<int>     *El_bkgOrigin,
								 vector<int>     *El_chFlip,
								 vector<double>  *El_ptcone20,
								 vector<double>  *El_ptcone30,
								 vector<double>  *El_ptcone40,
								 vector<double>  *El_ptvarcone20,
								 vector<double>  *El_ptvarcone30,
								 vector<double>  *El_ptvarcone40,
								 vector<double>  *El_topoetcone20,
								 vector<double>  *El_topoetcone30,
								 vector<double>  *El_topoetcone40,
								 vector<bool>    *El_passIsoLooseTO,
								 vector<bool>    *El_passIsoLoose,
								 vector<bool>    *El_passIsoTight,
								 vector<bool>    *El_passIsoGrad,
								 vector<bool>    *El_passIsoGradCustomTight,
								 vector<bool>    *El_passIsoGradCustom,
								 vector<bool>    *El_passIsoGradLoose,
								 vector<bool>    *El_trigMatch_e12_lhloose_L1EM10VH,
								 vector<bool>    *El_trigMatch_e17_lhloose,
								 vector<bool>    *El_trigMatch_e60_lhmedium,
								 vector<bool>    *El_trigMatch_e24_lhmedium_iloose_L1EM20VH)
{
	for (int i = 0; i < NEl; i++) {
		Electron el;
		el.set_number(NEl);
		el.set_flavor(flavor);
		el.set_eta( (*El_eta)[i] );
		el.set_etaclus( (*El_etaclus)[i] );
		el.set_phi( (*El_phi)[i] );
		el.set_pt( (*El_pT)[i] );
		el.set_E( (*El_E)[i] );
		el.set_charge( (*El_charge)[i] );
		el.set_sigd0( (*El_sigd0)[i] );
		el.set_z0sinTheta( (*El_z0sinTheta)[i] );
		el.set_d0pvtx( (*El_d0pvtx)[i] );
		el.set_passOR( (*El_passOR)[i] );
		el.set_SFwMediumLH( (*El_SFwMediumLH)[i] );
		el.set_IsoSFwTightLH( (*El_IsoSFwTightLH)[i] );
		el.set_SFwTightLH( (*El_SFwTightLH)[i] );
		el.set_SFwLooseAndBLayerLH( (*El_SFwLooseAndBLayerLH)[i] );
		el.set_SFwTrigMediumLH_e12_lhloose_L1EM10VH( (*El_SFwTrigMediumLH_e12_lhloose_L1EM10VH)[i] );
		el.set_SFwTrigTightLH_e12_lhloose_L1EM10VH( (*El_SFwTrigTightLH_e12_lhloose_L1EM10VH)[i] );
		el.set_SFwTrigTightLH_e17_lhloose( (*El_SFwTrigTightLH_e17_lhloose)[i] );
		el.set_SFwTrigTightLH_single( (*El_SFwTrigTightLH_single)[i] );
		el.set_SFwTrigLooseAndBLayerLH_e12_lhloose_L1EM10VH( (*El_SFwTrigLooseAndBLayerLH_e12_lhloose_L1EM10VH)[i] );
		el.set_isLooseAndBLayerLH( (*El_isLooseAndBLayerLH)[i] );
		el.set_isMediumLH( (*El_isMediumLH)[i] );
		el.set_isTightLH( (*El_isTightLH)[i] );
		el.set_nBLayerHits( (*El_nBLayerHits)[i] );
		el.set_expectBLayerHit( (*El_expectBLayerHit)[i] );
		el.set_type( (*El_type)[i] );
		el.set_origin( (*El_origin)[i] );
		el.set_bkgMotherPdgId( (*El_bkgMotherPdgId)[i] );
		el.set_bkgOrigin( (*El_bkgOrigin)[i] );
		el.set_chFlip( (*El_chFlip)[i] );
		el.set_ptcone20( (*El_ptcone20)[i] );
		el.set_ptcone30( (*El_ptcone30)[i] );
		el.set_ptcone40( (*El_ptcone40)[i] );
		el.set_ptvarcone20( (*El_ptvarcone20)[i] );
		el.set_ptvarcone30( (*El_ptvarcone30)[i] );
		el.set_ptvarcone40( (*El_ptvarcone40)[i] );
		el.set_topoetcone20( (*El_topoetcone20)[i] );
		el.set_topoetcone30( (*El_topoetcone30)[i] );
		el.set_topoetcone40( (*El_topoetcone40)[i] );
		el.set_passIsoLooseTO( (*El_passIsoLooseTO)[i] );
		el.set_passIsoLoose( (*El_passIsoLoose)[i] );
		el.set_passIsoTight( (*El_passIsoTight)[i] );
		el.set_passIsoGrad( (*El_passIsoGrad)[i] );
		el.set_passIsoGradCustomTight( (*El_passIsoGradCustomTight)[i] );
		el.set_passIsoGradCustom( (*El_passIsoGradCustom)[i] );
		el.set_passIsoGradLoose( (*El_passIsoGradLoose)[i] );
		el.set_trigMatch_e12_lhloose_L1EM10VH( (*El_trigMatch_e12_lhloose_L1EM10VH)[i] );
		el.set_trigMatch_e17_lhloose( (*El_trigMatch_e17_lhloose)[i] );
		el.set_trigMatch_e60_lhmedium( (*El_trigMatch_e60_lhmedium)[i] );
		el.set_trigMatch_e24_lhmedium_iloose_L1EM20VH( (*El_trigMatch_e24_lhmedium_iloose_L1EM20VH)[i] );
		el.set_TLV_E(el.get_pt(), el.get_eta(), el.get_phi(), el.get_E());
		vec_elec.push_back(el);
	}
}

void yt_selector::fill_muons(Int_t           NMu,
							 int             flavor,
							 vector<double>  *Mu_eta,
							 vector<double>  *Mu_phi,
							 vector<double>  *Mu_pT,
							 vector<double>  *Mu_SFw,
							 vector<float>   *Mu_IsoSFw,
							 vector<int>     *Mu_charge,
							 vector<double>  *Mu_d0pvtx,
							 vector<double>  *Mu_sigd0,
							 vector<double>  *Mu_z0sinTheta,
							 vector<bool>    *Mu_isBad,
							 vector<bool>    *Mu_passOR,
							 vector<bool>    *Mu_isTight,
							 vector<bool>    *Mu_isCosmic,
							 vector<int>     *Mu_type,
							 vector<int>     *Mu_origin,
							 vector<double>  *Mu_ptcone20,
							 vector<double>  *Mu_ptcone30,
							 vector<double>  *Mu_ptcone40,
							 vector<double>  *Mu_ptvarcone20,
							 vector<double>  *Mu_ptvarcone30,
							 vector<double>  *Mu_ptvarcone40,
							 vector<double>  *Mu_topoetcone20,
							 vector<double>  *Mu_topoetcone30,
							 vector<double>  *Mu_topoetcone40,
							 vector<bool>    *Mu_passIsoLooseTO,
							 vector<bool>    *Mu_passIsoLoose,
							 vector<bool>    *Mu_passIsoTight,
							 vector<bool>    *Mu_passIsoGrad,
							 vector<bool>    *Mu_passIsoGradCustomTight,
							 vector<bool>    *Mu_passIsoGradCustom,
							 vector<bool>    *Mu_passIsoGradLoose,
							 Float_t         MuTrigSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50,
							 vector<bool>    *Mu_trigMatch_mu26_imedium,
							 vector<bool>    *Mu_trigMatch_mu50,
							 vector<bool>    *Mu_trigMatch_mu18_mu8noL1,
							 vector<bool>    *Mu_trigMatch_mu14,
							 vector<bool>    *Mu_trigMatch_mu18)
{
	for (int i = 0; i < NMu; i++) {
		Muon mu;
		mu.set_number(NMu);
		mu.set_flavor(flavor);
		mu.set_eta( (*Mu_eta)[i] );
		mu.set_phi( (*Mu_phi)[i] );
		mu.set_pt( (*Mu_pT)[i] );
		mu.set_SFw( (*Mu_SFw)[i] );
		mu.set_IsoSFw( (*Mu_IsoSFw)[i] );
		mu.set_charge( (*Mu_charge)[i] );
		mu.set_d0pvtx( (*Mu_d0pvtx)[i] );
		mu.set_sigd0( (*Mu_sigd0)[i] );
		mu.set_z0sinTheta( (*Mu_z0sinTheta)[i] );
		mu.set_isBad( (*Mu_isBad)[i] );
		mu.set_passOR( (*Mu_passOR)[i] );
		mu.set_isTight( (*Mu_isTight)[i] );
		mu.set_isCosmic( (*Mu_isCosmic)[i] );
		mu.set_type( (*Mu_type)[i] );
		mu.set_origin( (*Mu_origin)[i] );
		mu.set_ptcone20( (*Mu_ptcone20)[i] );
		mu.set_ptcone30( (*Mu_ptcone30)[i] );
		mu.set_ptcone40( (*Mu_ptcone40)[i] );
		mu.set_ptvarcone20( (*Mu_ptvarcone20)[i] );
		mu.set_ptvarcone30( (*Mu_ptvarcone30)[i] );
		mu.set_ptvarcone40( (*Mu_ptvarcone40)[i] );
		mu.set_topoetcone20( (*Mu_topoetcone20)[i] );
		mu.set_topoetcone30( (*Mu_topoetcone30)[i] );
		mu.set_topoetcone40( (*Mu_topoetcone40)[i] );
		mu.set_passIsoLooseTO( (*Mu_passIsoLooseTO)[i] );
		mu.set_passIsoLoose( (*Mu_passIsoLoose)[i] );
		mu.set_passIsoTight( (*Mu_passIsoTight)[i] );
		mu.set_passIsoGrad( (*Mu_passIsoGrad)[i] );
		mu.set_passIsoGradCustomTight( (*Mu_passIsoGradCustomTight)[i] );
		mu.set_passIsoGradCustom( (*Mu_passIsoGradCustom)[i] );
		mu.set_passIsoGradLoose( (*Mu_passIsoGradLoose)[i] );
		mu.set_MuTrigSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50( MuTrigSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50 );
		mu.set_trigMatch_mu26_imedium( (*Mu_trigMatch_mu26_imedium)[i] );
		mu.set_trigMatch_mu50( (*Mu_trigMatch_mu50)[i] );
		mu.set_trigMatch_mu18_mu8noL1( (*Mu_trigMatch_mu18_mu8noL1)[i] );
		mu.set_trigMatch_mu14( (*Mu_trigMatch_mu14)[i] );
		mu.set_trigMatch_mu18( (*Mu_trigMatch_mu18)[i] );
		mu.set_TLV_M(mu.get_pt(), mu.get_eta(), mu.get_phi(), Mu_Mass);
		vec_muon.push_back(mu);
	}
}

void yt_selector::fill_jets(Int_t           NJet,
							vector<double>  *Jet_eta,
							vector<double>  *Jet_phi,
							vector<double>  *Jet_pT,
							vector<double>  *Jet_E,
							vector<double>  *Jet_quality,
							vector<double>  *Jet_JVT,
							vector<double>  *Jet_JVTsf,
							vector<double>  *Jet_MV2c20,
							vector<double>  *Jet_MV2c10,
							vector<double>  *Jet_SFw,
							vector<int>     *Jet_ConeTruthLabel,
							vector<int>     *Jet_PartonTruthLabel,
							vector<int>     *Jet_HadronConeExclTruthLabel,
							vector<double>  *Jet_deltaR,
							vector<int>     *Jet_nTrk,
							vector<bool>    *Jet_passOR)
{
	for (int i = 0; i < NJet; i++) {
		Jet je;
		je.set_number(NJet);
		je.set_eta( (*Jet_eta)[i] );
		je.set_phi( (*Jet_phi)[i] );
		je.set_pt( (*Jet_pT)[i] );
		je.set_E( (*Jet_E)[i] );
		je.set_quality( (*Jet_quality)[i] );
		je.set_JVT( (*Jet_JVT)[i] );
		je.set_JVTsf( (*Jet_JVTsf)[i] );
		je.set_MV2c20( (*Jet_MV2c20)[i] );
		je.set_MV2c10( (*Jet_MV2c10)[i] );
		je.set_SFw( (*Jet_SFw)[i] );
		je.set_ConeTruthLabel( (*Jet_ConeTruthLabel)[i] );
		je.set_PartonTruthLabel( (*Jet_PartonTruthLabel)[i] );
		je.set_HadronConeExclTruthLabel( (*Jet_HadronConeExclTruthLabel)[i] );
		je.set_deltaR( (*Jet_deltaR)[i] );
		je.set_nTrk( (*Jet_nTrk)[i] );
		je.set_passOR( (*Jet_passOR)[i]);
		je.set_TLV_E(je.get_pt(), je.get_eta(), je.get_phi(), je.get_E());
		vec_jets.push_back(je);
	}
}

void yt_selector::fill_leptons(vector<Electron> vec_elec, vector<Muon> vec_muon)
{
	for (auto & el_itr : vec_elec) {
		vec_lept.push_back(el_itr);
	}
	for (auto & mu_itr : vec_muon) {
		vec_lept.push_back(mu_itr);
	}
}

void yt_selector::fill_baseline_electrons(vector<Electron> vec_elec)
{
	for (auto & el_itr : vec_elec) {
		if (el_itr.get_baseline() == true &&
			el_itr.get_passOR() == true) {
			vec_OR_elec.push_back(el_itr);
		}
	}
}

void yt_selector::fill_baseline_muons(vector<Muon> vec_muon)
{
	for (auto & mu_itr : vec_muon) {
		if (mu_itr.get_baseline() == true &&
			mu_itr.get_passOR() == true) {
			vec_OR_muon.push_back(mu_itr);
		}
	}
}

void yt_selector::fill_baseline_jets(vector<Jet> vec_jets)
{
	for (auto & jet_itr : vec_jets) {
		if (jet_itr.get_baseline() == true &&
			jet_itr.get_passOR() == true) {
			// reject jets with pT<60 GeV and |eta|<2.4 and JVT<0.59 (new values, see JVTCalibration twiki), after the overlap removal procedure
			if (jet_itr.get_pt() < 60000. &&
				fabs(jet_itr.get_phi()) < 2.4 &&
				jet_itr.get_JVT() < 0.59) {
				jet_itr.set_baseline(0);
				continue;
			}
			else
				vec_OR_jets.push_back(jet_itr);
		}
	}
}

void yt_selector::fill_baseline_leptons(vector<Electron> vec_elec, vector<Muon> vec_muon)
{
	for (auto & el_itr : vec_elec) {
		if (el_itr.get_baseline() == true &&
			el_itr.get_passOR() == true) {
			vec_OR_lept.push_back(el_itr);
		}
	}
	for (auto & mu_itr : vec_muon) {
		if (mu_itr.get_baseline() == true &&
			mu_itr.get_passOR() == true) {
			vec_OR_lept.push_back(mu_itr);
		}
	}
}

void yt_selector::fill_signal_electrons(vector<Electron> vec_elec)
{
	for (auto & el_itr : vec_elec) {
		if (el_itr.get_baseline() == true &&
			el_itr.get_passOR() == true &&
			el_itr.get_isSignal()) {
			//el_itr.get_isSignal() &&
			//el_itr.get_pt() > 20000.) {
			vec_signal_elec.push_back(el_itr);
		}
	}
}

void yt_selector::fill_signal_muons(vector<Muon> vec_muon)
{
	for (auto & mu_itr : vec_muon) {
		if (mu_itr.get_baseline() == true &&
			mu_itr.get_passOR() == true &&
			mu_itr.get_isSignal()) {
			//mu_itr.get_isSignal() &&
			//mu_itr.get_pt() > 20000.) {
			vec_signal_muon.push_back(mu_itr);
		}
	}
}

void yt_selector::fill_signal_jets(vector<Jet> vec_jets)
{
	for (auto & jet_itr : vec_jets) {
		if (!jet_itr.get_baseline()) continue;
		if (!jet_itr.get_passOR()) continue;
		if (jet_itr.get_quality() > 0.5) continue; // 1=bad jet from SUSYToo ls IsGoodJet
		//if (jet_itr.get_isBjet()) continue;
		//if (jet_itr.get_pt() > 20000. &&
		//	fabs(jet_itr.get_eta()) < 2.8) {
			vec_signal_jets.push_back(jet_itr);
		//}
	}
}

void yt_selector::fill_signal_leptons(vector<Electron> signal_elec, vector<Muon> signal_muon)
{
	for (auto & el_itr : signal_elec) {
		vec_signal_lept.push_back(el_itr);
	}
	for (auto & mu_itr : signal_muon) {
		vec_signal_lept.push_back(mu_itr);
	}
}

// Set methods
void yt_selector::set_baseline_and_signal_electrons()
{
	for (auto & el_itr : vec_elec) {
		// baseline electrons
		if (el_itr.get_isLooseAndBLayerLH() == true &&
			el_itr.get_pt() > 10000. &&
			fabs(el_itr.get_etaclus()) < 2.47 &&
			fabs(el_itr.get_sigd0()) < 5.) {
			// Reject electrons in the crack region: 1.37<|eta|<1.52
			// Use the cluster eta (detector level)
			if (fabs(el_itr.get_etaclus()) > 1.37 &&
				fabs(el_itr.get_etaclus()) < 1.52) {
				el_itr.set_baseline(0); // Not a baseline electron
			}
			else {
				el_itr.set_baseline(1);
			}
		}
		else {
			el_itr.set_baseline(0);
		}
		// signal electrons
		if (el_itr.get_isMediumLH() == true &&
			fabs(el_itr.get_eta()) <= 2. &&
			el_itr.get_ptvarcone20() / el_itr.get_pt() < 0.06 &&
			el_itr.get_topoetcone20() / el_itr.get_pt() < 0.06 &&
			fabs(el_itr.get_z0sinTheta()) < 0.5) {
			el_itr.set_isSignal(1);
		}
	}
}

void yt_selector::set_baseline_and_signal_muons()
{
	for (auto & mu_itr : vec_muon) {
		// baseline muons
		//if (mu_itr.get_isMediumLH() == true && // Medium is already applied at the ntuple, you can assume all the muon have it applied
		//	mu_itr.get_pt() > 10000. &&
		if (mu_itr.get_pt() > 10000. &&
			fabs(mu_itr.get_eta()) < 2.5) {
			mu_itr.set_baseline(1);
		}
		else {
			mu_itr.set_baseline(0);
		}
		// signal muons
		if (mu_itr.get_ptvarcone30() / mu_itr.get_pt() < 0.06 &&
			fabs(mu_itr.get_sigd0()) < 3.0 &&
			fabs(mu_itr.get_z0sinTheta() < 0.5)) {
			mu_itr.set_isSignal(1);
		}
	}
}

void yt_selector::set_jets_and_bjets()
{
	for (auto & jet_itr : vec_jets) {
		// Jets
		if (jet_itr.get_pt() > 20000. &&
			fabs(jet_itr.get_eta()) < 2.8) {
			jet_itr.set_baseline(1);
		}
		else {
			jet_itr.set_baseline(0);
		}
		// b-jets
		if (jet_itr.get_pt() > 20000. &&
			fabs(jet_itr.get_eta()) < 2.5 &&
			jet_itr.get_MV2c10() > 0.8244) {
			jet_itr.set_isBjet(1);
		}
	}
}

#endif // #ifndef FILL_AND_SET_CXX
#endif // #ifdef YT_SELECTOR_CXX
