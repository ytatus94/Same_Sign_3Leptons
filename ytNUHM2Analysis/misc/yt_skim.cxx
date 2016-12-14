#define YT_SKIM_CXX
#include "ytNUHM2Analysis/yt_skim.h"

void yt_skim::initialize()
{
    // clear all vectors
    vec_elec.clear();
    vec_muon.clear();
    vec_lept.clear();
    vec_jets.clear();

    vec_baseline_elec.clear();
    vec_baseline_muon.clear();
    vec_baseline_lept.clear();
    vec_baseline_jets.clear();

    vec_signal_elec.clear();
    vec_signal_muon.clear();
    vec_signal_lept.clear();
    vec_signal_jets.clear();

    vec_signal_jets_no_eta_cut.clear();
    vec_signal_bjet.clear();
}

void yt_skim::execute(vector<Electron> elec, vector<Muon> muon, vector<Lepton> lept, vector<Jet> jets,
                      vector<Electron> baseline_elec, vector<Muon> baseline_muon, vector<Lepton> baseline_lept, vector<Jet> baseline_jets,
                      vector<Electron> signal_elec, vector<Muon> signal_muon, vector<Lepton> signal_lept, vector<Jet> signal_jets)
{
    // in event loop:
    // copy vectors from yt_selector.
    copy_raw_object_vectors(elec, muon, lept, jets);
    copy_baseline_object_vectors(baseline_elec, baseline_muon, baseline_lept, baseline_jets);
    copy_signal_object_vectors(signal_elec, signal_muon, signal_lept, signal_jets);
    fill_signal_jets_no_eta_cut(jets);
    fill_signal_bjet(signal_jets);
}

void yt_skim::finalize()
{
}

void yt_skim::copy_raw_object_vectors(vector<Electron> elec, vector<Muon> muon, vector<Lepton> lept, vector<Jet> jets)
{
    vec_elec = elec;
    vec_muon = muon;
    vec_lept = lept;
    vec_jets = jets;
}

void yt_skim::copy_baseline_object_vectors(vector<Electron> elec, vector<Muon> muon, vector<Lepton> lept, vector<Jet> jets)
{
    vec_baseline_elec = elec;
    vec_baseline_muon = muon;
    vec_baseline_lept = lept;
    vec_baseline_jets = jets;
}

void yt_skim::copy_signal_object_vectors(vector<Electron> elec, vector<Muon> muon, vector<Lepton> lept, vector<Jet> jets)
{
    vec_signal_elec = elec;
    vec_signal_muon = muon;
    vec_signal_lept = lept;
    vec_signal_jets = jets;
}

void yt_skim::fill_signal_jets_no_eta_cut(vector<Jet> jets)
{
    for (auto & jet_itr : jets) {
        if (jet_itr.get_pt() > 20000. &&
            jet_itr.get_passOR() == true) {
            if (jet_itr.get_pt() < 60000. &&
                fabs(jet_itr.get_eta()) < 2.4 &&
                jet_itr.get_JVT() < 0.59) {
                continue;
            }
            else {
                if (jet_itr.get_quality() < 0.5)
                    vec_signal_jets_no_eta_cut.push_back(jet_itr);
            }
        }
    }
}

void yt_skim::fill_signal_bjet(vector<Jet> signal_jets)
{
    for (auto & signal_jets_itr : signal_jets) {
        if (signal_jets_itr.get_isBjet() == true)
            vec_signal_bjet.push_back(signal_jets_itr); 
    }
}

double yt_skim::calculate_mll(vector<Lepton> leptons)
{
    // calculate the invariant mass of the 2 leading leptons
    if (leptons.size() < 2)
        return -999.;

    TLorentzVector tlv_lept_0, tlv_lept_1;
    tlv_lept_0.SetPtEtaPhiM(leptons.at(0).get_pt(), leptons.at(0).get_eta(), leptons.at(0).get_phi(), leptons.at(0).get_M());
    tlv_lept_1.SetPtEtaPhiM(leptons.at(1).get_pt(), leptons.at(1).get_eta(), leptons.at(1).get_phi(), leptons.at(1).get_M());
    double mll = (tlv_lept_0 + tlv_lept_1).M();
    return mll;
}

double yt_skim::calculate_mjj(vector<Jet> jets)
{
    // calculate the invariant mass of the 2 leading jets
    if (jets.size() < 2) 
        return -999.;

    TLorentzVector tlv_jets_0, tlv_jets_1;
    tlv_jets_0.SetPtEtaPhiE(jets.at(0).get_pt(), jets.at(0).get_eta(), jets.at(0).get_phi(), jets.at(0).get_E());
    tlv_jets_1.SetPtEtaPhiE(jets.at(1).get_pt(), jets.at(1).get_eta(), jets.at(1).get_phi(), jets.at(1).get_E());
    double mjj = (tlv_jets_0 + tlv_jets_1).M();
    return mjj;
}

double yt_skim::calculate_Ht(vector<Lepton> leptons, vector<Jet> jets)
{
    double Ht = 0;
    for (auto & lep : leptons) {
        Ht = Ht + lep.get_pt();
    }
    for (auto & jet : jets) {
        Ht = Ht + jet.get_pt();
    }
    return Ht;
}

double yt_skim::calculate_Meff(double Ht, double Etmiss)
{
    // the scalar sum of the signal leptons pT, all signal jets pT, and ETmiss
    return  Ht + Etmiss;
}

vector<double> yt_skim::calculate_DR_closestJet(Lepton lept, vector<Jet> jets)
{
    // Get the DR between the considered lepton and the closest jet
    //  - The first number is the DR computed with the rapidity
    //  - The second is the truth categorisation of the closest jet :
    //      1 -> light-jet
    //      2 -> c-jet
    //      3 -> b-jet
    //      0 -> other jets ( mainly tau jets )

    double out_DR = 100.;
    double closest_jet_label = 0;
    int flavor = lept.get_flavor();
    for (auto & jet_itr : jets) {
        // computing DR
        TLorentzVector lep_tlv;
        TLorentzVector jet_tlv;
        if (flavor == 11)
            lep_tlv.SetPtEtaPhiE(lept.get_pt(), lept.get_eta(), lept.get_phi(), lept.get_E());
        else if (flavor == 13)
            lep_tlv.SetPtEtaPhiM(lept.get_pt(), lept.get_eta(), lept.get_phi(), lept.get_M());
        jet_tlv.SetPtEtaPhiE(jet_itr.get_pt(), jet_itr.get_eta(), jet_itr.get_phi(), jet_itr.get_E());
        double lep_rapidity = lep_tlv.Rapidity();
        double jet_rapidity = jet_tlv.Rapidity();
        double Deta = fabs(lep_rapidity - jet_rapidity);
        double Dphi = fabs(lept.get_phi() - jet_itr.get_phi());
        if (Dphi > TMath::Pi()) Dphi = 2 * TMath::Pi() - Dphi;
        double DR = sqrt(pow(Deta, 2) + pow(Dphi, 2));

        // DR cut
        if ( DR < out_DR ) {
            out_DR = DR;
            //closest_jet_label = current_jet.label;
            closest_jet_label = 0; // This part may cause problem!!!
        }
    }

    // Generates the output
    vector<double> output;
    output.push_back(out_DR);
    if (closest_jet_label >= 3)
        output.push_back(1);
    else if (closest_jet_label == 4)
        output.push_back(2);
    else if (closest_jet_label == 5)
        output.push_back(3);
    else output.push_back(0);

    return output;
}

int yt_skim::Get_channel(vector<Lepton> vec_signal_lept) // Copy from Sebastien, but this part seems problematic
{
  int lepton_pairing = -1;

  // Getting the up and down charge
  vector<int> up_charge_index;
  vector<int> down_charge_index;
  for (int ii = 0 ; ii < (int)vec_signal_lept.size() ; ii++ ) {
    if      ( vec_signal_lept.at(ii).get_charge() == 1  ) up_charge_index.push_back(ii);
    else if ( vec_signal_lept.at(ii).get_charge() == -1 ) down_charge_index.push_back(ii);
  }

  // Assesing the channel with the up ss charge (no down charge ss pair)
  if      ( up_charge_index.size() >= 2 && down_charge_index.size() < 2 ) {
    if      ( vec_signal_lept.at( up_charge_index.at(0) ).get_flavor() == 11 && vec_signal_lept.at( up_charge_index.at(1) ).get_flavor() == 11 ) lepton_pairing = 1;
    else if ( vec_signal_lept.at( up_charge_index.at(0) ).get_flavor() == 13 && vec_signal_lept.at( up_charge_index.at(1) ).get_flavor() == 13 ) lepton_pairing = 3;
    else lepton_pairing = 2;
  }
  // Assesing the channel with the down ss charge (no up charge ss pair)
  else if ( down_charge_index.size() >= 2 && up_charge_index.size() < 2 ) {
    if      ( vec_signal_lept.at( down_charge_index.at(0) ).get_flavor() == 11 && vec_signal_lept.at( down_charge_index.at(1) ).get_flavor() == 11 ) lepton_pairing = 1;
    else if ( vec_signal_lept.at( down_charge_index.at(0) ).get_flavor() == 13 && vec_signal_lept.at( down_charge_index.at(1) ).get_flavor() == 13 ) lepton_pairing = 3;
    else lepton_pairing = 2;
  }
  
  // Assesing the channel when both up and down ss pair are present
  else if ( vec_signal_lept.size() != 0 ){
    if ( vec_signal_lept.at(0).get_charge() == 1 && up_charge_index.size() >= 2 ) {
      if      ( vec_signal_lept.at( up_charge_index.at(0) ).get_flavor() == 11 && vec_signal_lept.at( up_charge_index.at(1) ).get_flavor() == 11 ) lepton_pairing = 1;
      else if ( vec_signal_lept.at( up_charge_index.at(0) ).get_flavor() == 13 && vec_signal_lept.at( up_charge_index.at(1) ).get_flavor() == 13 ) lepton_pairing = 3;
      else lepton_pairing = 2;
    }   
    if ( vec_signal_lept.at(0).get_charge() == -1 && down_charge_index.size() >= 2  ) {
      if      ( vec_signal_lept.at( down_charge_index.at(0) ).get_flavor() == 11 && vec_signal_lept.at( down_charge_index.at(1) ).get_flavor() == 11 ) lepton_pairing = 1;
      else if ( vec_signal_lept.at( down_charge_index.at(0) ).get_flavor() == 13 && vec_signal_lept.at( down_charge_index.at(1) ).get_flavor() == 13 ) lepton_pairing = 3;
      else lepton_pairing = 2;      
    }
    
    // if ( vec_signal_lept.at(0).lepton_type == 1 ) lepton_pairing = 1;
    // else if ( vec_signal_lept.at(0).lepton_type == 2 ) lepton_pairing = 3;
  }
  
  return lepton_pairing;
}
