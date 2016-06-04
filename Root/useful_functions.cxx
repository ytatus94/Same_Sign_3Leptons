#ifdef MYSELECTOR_CXX
#ifndef USEFUL_FUNCTIONS_CXX
#define USEFUL_FUNCTIONS_CXX

// Functions declarations
template<typename T> bool sort_descending_Pt(T obj1, T obj2); // NOTE: cannot use const ref for arguments.
template<> bool sort_descending_Pt(TLorentzVector tlv1, TLorentzVector tlv2); // explicit specialization
double calculate_Ht(vector<Lepton> signal_leptons, vector<Jet> signal_jets);
double calculate_Meff(double Ht, double Etmiss);

// Function definitions
template <typename T>
bool sort_descending_Pt(T obj1, T obj2) // Cannot use bool sort_descending_Pt(const T & obj1, const T & obj2)
{
    return (obj1.get_TLV()).Pt() > (obj2.get_TLV()).Pt();
}

template <>  // explicit specialization
bool sort_descending_Pt(TLorentzVector tlv1, TLorentzVector tlv2)
{
    return tlv1.Pt() > tlv2.Pt();
}

double calculate_Ht(vector<Lepton> signal_leptons, vector<Jet> signal_jets)
{
    double Ht = 0;
    for (auto & lep : signal_leptons) {
        Ht = Ht + lep.get_pt();
    }
    for (auto & jet : signal_jets) {
        Ht = Ht + jet.get_pt();
    }
    return Ht;
}

double calculate_Meff(double Ht, double Etmiss)
{
    // the scalar sum of the signal leptons pT, all signal jets pT, and ETmiss
    return  Ht + Etmiss;
}

#endif // #define USEFUL_FUNCTIONS_CXX
#endif // #ifdef MYSELECTOR_CXX
