#ifdef MYSELECTOR_CXX
#ifndef FILL_AND_SET_CXX
#define FILL_AND_SET_CXX

// Fill methods
void MySelector::Fill_electrons(Int_t            NEl,
                                int              flavor,
                                vector<double>   *El_eta,
                                vector<double>   *El_phi,
                                vector<double>   *El_pT,
                                vector<double>   *El_E,
                                vector<int>      *El_charge,
                                vector<double>   *El_sigd0,
                                vector<double>   *El_z0pvtx,
                                vector<double>   *El_d0pvtx,
                                vector<double>   *El_SFwMedium,
                                vector<double>   *El_SFwMediumLH,
                                vector<double>   *El_SFwTight,
                                vector<double>   *El_SFwTightLH,
                                vector<bool>     *El_isLooseLH,
                                vector<bool>     *El_isMediumLH,
                                vector<bool>     *El_isTightLH,
                                vector<bool>     *El_isLoose,
                                vector<bool>     *El_isMedium,
                                vector<bool>     *El_isTight,
                                vector<double>   *El_ptcone20,
                                vector<double>   *El_ptcone30,
                                vector<double>   *El_ptcone40,
                                vector<double>   *El_ptvarcone20,
                                vector<double>   *El_ptvarcone30,
                                vector<double>   *El_ptvarcone40,
                                vector<double>   *El_topoetcone20,
                                vector<double>   *El_topoetcone30,
                                vector<double>   *El_topoetcone40,
                                vector<bool>     *El_passIsoVeryLooseTO,
                                vector<bool>     *El_passIsoVeryLoose,
                                vector<bool>     *El_passIsoLoose,
                                vector<bool>     *El_passIsoTight,
                                vector<bool>     *El_passIsoGrad,
                                vector<bool>     *El_passIsoGradCustom,
                                vector<bool>     *El_passIsoGradLoose)
{
    for (int i = 0; i < NEl; i++) {
        Electron el;
        el.set_number(NEl);
        el.set_flavor(flavor);
        el.set_eta( (*El_eta)[i] );
        el.set_phi( (*El_phi)[i] );
        el.set_pt( (*El_pT)[i] );
        el.set_E( (*El_E)[i] );
        el.set_charge( (*El_charge)[i] );
        el.set_sigd0( (*El_sigd0)[i] );
        el.set_z0pvtx( (*El_z0pvtx)[i] );
        el.set_d0pvtx( (*El_d0pvtx)[i] );
        el.set_SFwMedium( (*El_SFwMedium)[i] );
        el.set_SFwMediumLH( (*El_SFwMediumLH)[i] );
        el.set_SFwTight( (*El_SFwTight)[i] );
        el.set_SFwTightLH( (*El_SFwTightLH)[i] );
        el.set_isLooseLH( (*El_isLooseLH)[i] );
        el.set_isMediumLH( (*El_isMediumLH)[i] );
        el.set_isTightLH( (*El_isTightLH)[i] );
        el.set_isLoose( (*El_isLoose)[i] );
        el.set_isMedium( (*El_isMedium)[i] );
        el.set_isTight( (*El_isTight)[i] );
        el.set_ptcone20( (*El_ptcone20)[i] );
        el.set_ptcone30( (*El_ptcone30)[i] );
        el.set_ptcone40( (*El_ptcone40)[i] );
        el.set_ptvarcone20( (*El_ptvarcone20)[i] );
        el.set_ptvarcone30( (*El_ptvarcone30)[i] );
        el.set_ptvarcone40( (*El_ptvarcone40)[i] );
        el.set_topoetcone20( (*El_topoetcone20)[i] );
        el.set_topoetcone30( (*El_topoetcone30)[i] );
        el.set_topoetcone40( (*El_topoetcone40)[i] );
        el.set_passIsoVeryLooseTO( (*El_passIsoVeryLooseTO)[i] );
        el.set_passIsoVeryLoose( (*El_passIsoVeryLoose)[i] );
        el.set_passIsoLoose( (*El_passIsoLoose)[i] );
        el.set_passIsoTight( (*El_passIsoTight)[i] );
        el.set_passIsoGrad( (*El_passIsoGrad)[i] );
        el.set_passIsoGradCustom( (*El_passIsoGradCustom)[i] );
        el.set_passIsoGradLoose( (*El_passIsoGradLoose)[i] );
        el.set_TLV_E(el.get_pt(), el.get_eta(), el.get_phi(), el.get_E());
        vec_elec.push_back(el);
    }
}

void MySelector::Fill_muons(Int_t            NMu,
                            int              flavor,
                            vector<double>   *Mu_eta,
                            vector<double>   *Mu_phi,
                            vector<double>   *Mu_pT,
                            vector<double>   *Mu_SFw,
                            vector<int>      *Mu_charge,
                            vector<double>   *Mu_d0pvtx,
                            vector<double>   *Mu_sigd0,
                            vector<double>   *Mu_z0pvtx,
                            vector<bool>     *Mu_isBad,
                            vector<bool>     *Mu_isCosmic,
                            vector<double>   *Mu_ptcone20,
                            vector<double>   *Mu_ptcone30,
                            vector<double>   *Mu_ptcone40,
                            vector<double>   *Mu_ptvarcone20,
                            vector<double>   *Mu_ptvarcone30,
                            vector<double>   *Mu_ptvarcone40,
                            vector<double>   *Mu_topoetcone20,
                            vector<double>   *Mu_topoetcone30,
                            vector<double>   *Mu_topoetcone40,
                            vector<bool>     *Mu_passIsoVeryLooseTO,
                            vector<bool>     *Mu_passIsoVeryLoose,
                            vector<bool>     *Mu_passIsoLoose,
                            vector<bool>     *Mu_passIsoTight,
                            vector<bool>     *Mu_passIsoGrad,
                            vector<bool>     *Mu_passIsoGradCustom,
                            vector<bool>     *Mu_passIsoGradLoose)
{
    for (int i = 0; i < NMu; i++) {
        Muon mu;
        mu.set_number(NMu);
        mu.set_flavor(flavor);
        mu.set_eta( (*Mu_eta)[i] );
        mu.set_phi( (*Mu_phi)[i] );
        mu.set_pt( (*Mu_pT)[i] );
        mu.set_SFw( (*Mu_SFw)[i] );
        mu.set_charge( (*Mu_charge)[i] );
        mu.set_d0pvtx( (*Mu_d0pvtx)[i] );
        mu.set_sigd0( (*Mu_sigd0)[i] );
        mu.set_z0pvtx( (*Mu_z0pvtx)[i] );
        mu.set_isBad( (*Mu_isBad)[i] );
        mu.set_isCosmic( (*Mu_isCosmic)[i] );
        mu.set_ptcone20( (*Mu_ptcone20)[i] );
        mu.set_ptcone30( (*Mu_ptcone30)[i] );
        mu.set_ptcone40( (*Mu_ptcone40)[i] );
        mu.set_ptvarcone20( (*Mu_ptvarcone20)[i] );
        mu.set_ptvarcone30( (*Mu_ptvarcone30)[i] );
        mu.set_ptvarcone40( (*Mu_ptvarcone40)[i] );
        mu.set_topoetcone20( (*Mu_topoetcone20)[i] );
        mu.set_topoetcone30( (*Mu_topoetcone30)[i] );
        mu.set_topoetcone40( (*Mu_topoetcone40)[i] );
        mu.set_passIsoVeryLooseTO( (*Mu_passIsoVeryLooseTO)[i] );
        mu.set_passIsoVeryLoose( (*Mu_passIsoVeryLoose)[i] );
        mu.set_passIsoLoose( (*Mu_passIsoLoose)[i] );
        mu.set_passIsoTight( (*Mu_passIsoTight)[i] );
        mu.set_passIsoGrad( (*Mu_passIsoGrad)[i] );
        mu.set_passIsoGradCustom( (*Mu_passIsoGradCustom)[i] );
        mu.set_passIsoGradLoose( (*Mu_passIsoGradLoose)[i] );
        mu.set_TLV_M(mu.get_pt(), mu.get_eta(), mu.get_phi(), Mu_Mass);
        vec_muon.push_back(mu);
    }
}

void MySelector::Fill_jets(Int_t             NJet,
                           vector<double>    *Jet_eta,
                           vector<double>    *Jet_phi,
                           vector<double>    *Jet_pT,
                           vector<double>    *Jet_E,
                           vector<double>    *Jet_quality,
                           vector<double>    *Jet_JVF,
                           vector<double>    *Jet_JVT,
                           vector<double>    *Jet_MV2c20,
                           vector<double>    *Jet_SFw,
                           vector<int>       *Jet_nTrk)

{
    for (int i = 0; i < NJet; i++) {
        Jet je;
        je.set_number(NJet);
        je.set_eta( (*Jet_eta)[i] );
        je.set_phi( (*Jet_phi)[i] );
        je.set_pt( (*Jet_pT)[i] );
        je.set_E( (*Jet_E)[i] );
        je.set_quality( (*Jet_quality)[i] );
	je.set_JVT( (*Jet_JVF)[i] );
        je.set_JVT( (*Jet_JVT)[i] );
        je.set_MV2c20( (*Jet_MV2c20)[i] );
        je.set_SFw( (*Jet_SFw)[i] );
        je.set_nTrk( (*Jet_nTrk)[i] );
        je.set_TLV_E(je.get_pt(), je.get_eta(), je.get_phi(), je.get_E());
        vec_jets.push_back(je);
    }
    
}

void MySelector::Fill_leptons(vector<Electron> vec_elec, vector<Muon> vec_muon)
{
    for (auto & el_itr : vec_elec) {
        vec_lept.push_back(el_itr);
    }
    for (auto & mu_itr : vec_muon) {
        vec_lept.push_back(mu_itr);
    }
}

void MySelector::Fill_baseline_electrons(vector<Electron> vec_elec)
{
    for (auto & el_itr : vec_elec) {
        if (el_itr.get_baseline() == true &&
            el_itr.get_passOR() == true) {
            vec_OR_elec.push_back(el_itr);
        }
    }
}

void MySelector::Fill_baseline_muons(vector<Muon> vec_muon)
{
    for (auto & mu_itr : vec_muon) {
        if (mu_itr.get_baseline() == true &&
            mu_itr.get_passOR() == true) {
            vec_OR_muon.push_back(mu_itr);
        }
    }
}

void MySelector::Fill_baseline_jets(vector<Jet> jets)
{
    for (auto & jet_itr : vec_jets) {
        if (jet_itr.get_baseline() == true &&
            jet_itr.get_passOR() == true) {
            vec_OR_jets.push_back(jet_itr);
        }
    }
}

void MySelector::Fill_baseline_leptons(vector<Electron> signal_elec, vector<Muon> signal_muon)
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

void MySelector::Fill_signal_electrons(vector<Electron> vec_elec)
{
    for (auto & el_itr : vec_elec) {
        if (el_itr.get_baseline() == true &&
            el_itr.get_passOR() == true &&
            el_itr.get_isSignal() &&
            el_itr.get_pt() > 20000.) {
            vec_signal_elec.push_back(el_itr);
        }
    }
}

void MySelector::Fill_signal_muons(vector<Muon> vec_muon)
{
    for (auto & mu_itr : vec_muon) {
        if (mu_itr.get_baseline() == true &&
            mu_itr.get_passOR() == true &&
            mu_itr.get_isSignal() &&
            mu_itr.get_pt() > 20000.) {
            vec_signal_muon.push_back(mu_itr);
        }
    }
}

void MySelector::Fill_signal_jets(vector<Jet> jets)
{
    for (auto & jet_itr : vec_jets) {
        if (!jet_itr.get_baseline()) continue;
        if (!jet_itr.get_passOR()) continue;
        if (jet_itr.get_quality() == 1) continue; // 1=bad jet from SUSYToo ls IsGoodJet
        if (jet_itr.get_isBjet()) continue;
        if (jet_itr.get_pt() > 50000.) {
            vec_signal_jets.push_back(jet_itr);
        }
    }
}

void MySelector::Fill_signal_leptons(vector<Electron> signal_elec, vector<Muon> signal_muon)
{
    for (auto & el_itr : signal_elec) {
        vec_signal_lept.push_back(el_itr);
    }
    for (auto & mu_itr : signal_muon) {
        vec_signal_lept.push_back(mu_itr);
    }
}

// Set methods
void MySelector::Set_baseline_and_signal_electrons()
{
    for (auto & el_itr : vec_elec) {
        if (el_itr.get_isLooseLH() == true &&
            el_itr.get_pt() > 10000. &&
            fabs(el_itr.get_eta()) < 2.47 &&
            fabs(el_itr.get_sigd0()) < 5.) {
            // Reject electrons in the crack region: 1.37<|eta|<1.52
            if (fabs(el_itr.get_eta()) > 1.37 &&
                fabs(el_itr.get_eta()) < 1.52) {
                el_itr.set_baseline(0);
            }
            else {
                el_itr.set_baseline(1);
            }
        }
        else {
            el_itr.set_baseline(0);
        }
        double theta = (el_itr.get_TLV()).Theta();
        if (el_itr.get_isTightLH() == true &&
            fabs(el_itr.get_eta()) <= 2. &&
            el_itr.get_passIsoGradLoose() == true &&
            fabs(el_itr.get_z0pvtx() * TMath::Sin(theta)) < 0.5) {
            el_itr.set_isSignal(1);
        }
    }
}

void MySelector::Set_baseline_and_signal_muons()
{
    for (auto & mu_itr : vec_muon) {
        if (mu_itr.get_pt() > 10000. &&
            fabs(mu_itr.get_eta()) < 2.4) {
            mu_itr.set_baseline(1);
        }
        else {
            mu_itr.set_baseline(0);
        }
        double theta = (mu_itr.get_TLV()).Theta();
        if (mu_itr.get_passIsoGradLoose() == true &&
            fabs(mu_itr.get_sigd0()) < 3.0 &&
            fabs(mu_itr.get_z0pvtx() * TMath::Sin(theta)) < 0.5) {
            mu_itr.set_isSignal(1);
        }
    }
}

void MySelector::Set_baseline_and_signal_jets()
{
    for (auto & jet_itr : vec_jets) {
        if (jet_itr.get_pt() > 20000. &&
            fabs(jet_itr.get_eta()) < 4.5) { // baseline jet requires |eta| < 2.8 but we need |eta| < 4.5 for jet cleanning.
            jet_itr.set_baseline(1);
        }
        else {
            jet_itr.set_baseline(0);
        }
        if (jet_itr.get_pt() > 20000. &&
            fabs(jet_itr.get_eta()) < 2.5 &&
            jet_itr.get_MV2c20() > -0.0436) {
            jet_itr.set_isBjet(1);
        }
    }
}

#endif // #ifndef FILL_AND_SET_CXX
#endif // #ifdef MYSELECTOR_CXX
