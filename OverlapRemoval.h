#ifdef MYSELECTOR_CXX
#ifndef OVERLAPREMOVAL_H
#define OVERLAPREMOVAL_H

void OverlapRemoval(vector<Electron> *el_obj,
                    vector<Muon>     *mu_obj,
                    vector<Jet>      *jet_obj,
                    double dRejet,
                    double dRjetmu,
                    double dRjete,
                    double dRemu,
                    double dRee)
{
    vector<Jet>::iterator jet_itr = jet_obj->begin();
    vector<Jet>::iterator jet_end = jet_obj->end();
    for (; jet_itr != jet_end; jet_itr++) {
        bool jet_sel = jet_itr->get_baseline();
        if (jet_sel)
            jet_itr->set_passOR(1);
        else
            jet_itr->set_passOR(0);
    }

    vector<Muon>::iterator mu_itr = mu_obj->begin();
    vector<Muon>::iterator mu_end = mu_obj->end();
    for (; mu_itr != mu_end; mu_itr++) {
        bool mu_sel = mu_itr->get_baseline();
        if (mu_sel)
            mu_itr->set_passOR(1);
        else
            mu_itr->set_passOR(0);
    }

    // remove jets overlapping with (baseline/signal) electrons
    vector<Electron>::iterator el_itr = el_obj->begin();
    vector<Electron>::iterator el_end = el_obj->end();
    for (; el_itr != el_end; el_itr++) {
        bool el_sel = el_itr->get_baseline();
        if (el_sel)
            el_itr->set_passOR(1);
        else
            el_itr->set_passOR(0);

        jet_itr = jet_obj->begin();
        jet_end = jet_obj->end();
        for (; jet_itr != jet_end; jet_itr++) {
            if (!jet_itr->get_passOR()) continue;
            TLorentzVector el4vec = el_itr->get_TLV();
            TLorentzVector jet4vec = jet_itr->get_TLV();
            if (el4vec.DeltaR(jet4vec) < dRejet) {
                jet_itr->set_passOR(0);
            }
        }
    }

    // Remove electrons and muons overlapping with jets
    el_itr = el_obj->begin();
    el_end = el_obj->end();
    for (; el_itr != el_end; el_itr++) {
        if (!el_itr->get_passOR()) continue;

        jet_itr = jet_obj->begin();
        jet_end = jet_obj->end();
        for (; jet_itr != jet_end; jet_itr++) {
            if (!jet_itr->get_passOR()) continue;
            TLorentzVector el4vec = el_itr->get_TLV();
            TLorentzVector jet4vec = jet_itr->get_TLV();
            if (el4vec.DeltaR(jet4vec) < dRjete) {
                el_itr->set_passOR(0);
            }
        }
    }

    mu_itr = mu_obj->begin();
    mu_end = mu_obj->end();
    for (; mu_itr != mu_end; mu_itr++) {
        if (!mu_itr->get_passOR()) continue;

        jet_itr = jet_obj->begin();
        jet_end = jet_obj->end();
        for (; jet_itr != jet_end; jet_itr++) {
            if (!jet_itr->get_passOR()) continue;
            TLorentzVector mu4vec = mu_itr->get_TLV();
            TLorentzVector jet4vec = jet_itr->get_TLV();
            if (mu4vec.DeltaR(jet4vec) < dRjetmu) {
                mu_itr->set_passOR(0);
            }
        }
    }
 
    // Remove electrons and muons overlapping with each other
    el_itr = el_obj->begin();
    el_end = el_obj->end();
    for (; el_itr != el_end; el_itr++) {
        if (!el_itr->get_passOR()) continue;

        mu_itr = mu_obj->begin();
        mu_end = mu_obj->end();
        for (; mu_itr != mu_end; mu_itr++) {
            if (!mu_itr->get_passOR()) continue;

            TLorentzVector el4vec = el_itr->get_TLV();
            TLorentzVector mu4vec = mu_itr->get_TLV();
            if (el4vec.DeltaR(mu4vec) < dRemu) {
                el_itr->set_passOR(0);
                //mu_itr->set_passOR(0); // Otilia says we remove electron      only.
            }
        }
    }

    // Remove electrons overlapping with each other
    el_itr = el_obj->begin();
    el_end = el_obj->end();
    for (; el_itr != el_end; el_itr++) {
        if (!el_itr->get_passOR()) continue;

        vector<Electron>::iterator el2_itr = el_obj->begin();
        vector<Electron>::iterator el2_end = el_obj->end();
        if (el_itr == el2_itr) continue;
        if (!el2_itr->get_passOR()) continue;
        TLorentzVector el4vec = el_itr->get_TLV();
        TLorentzVector el24vec = el2_itr->get_TLV();
        if (el4vec.DeltaR(el24vec) < dRee) {
            if ((el_itr->get_TLV()).Pt() < (el2_itr->get_TLV()).Pt()) {
                el_itr->set_passOR(0);
            }
            else {
                el2_itr->set_passOR(0);
            }
        }
    }
/*
    // debug
    // Count number of objects after overlap removal
    int Nel = 0;
    el_itr = el_obj->begin();
    el_end = el_obj->end();
    for (; el_itr != el_end; el_itr++) {
        if (el_itr->get_passOR()) Nel++;
    }

    int Nmu = 0;
    mu_itr = mu_obj->begin();
    mu_end = mu_obj->end();
    for (; mu_itr != mu_end; mu_itr++) {
        if (mu_itr->get_passOR()) Nmu++;
    }

    int Njet = 0;
    jet_itr = jet_obj->begin();
    jet_end = jet_obj->end();
    for (; jet_itr != jet_end; jet_itr++) {
        if (jet_itr->get_passOR()) Njet++;
    }
    
    cout << "After overlap removal: Nel=" << Nel <<", Nmu="<< Nmu <<", Nje     t=" << Njet << endl;
*/
}

#endif // #ifndef OVERLAPREMOVAL_H
#endif // #ifdef MYSELECTOR_CXX