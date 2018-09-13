#ifndef HIGH_LEVEL_TRIGGER_H
#define HIGH_LEVEL_TRIGGER_H

class HLT {
    // ntuple variables
    bool    HLT_e24_lhmedium_nod0_ivarloose;
    bool    HLT_e24_lhtight_nod0_ivarloose;
    bool    HLT_e26_lhtight_iloose;
    bool    HLT_e26_lhtight_ivarloose;
    bool    HLT_e26_lhtight_nod0_iloose;
    bool    HLT_e26_lhtight_nod0_ivarloose;
    bool    HLT_e60_lhmedium;
    bool    HLT_e60_lhmedium_nod0;
    bool    HLT_e120_lhloose_nod0;
    bool    HLT_e140_lhloose_nod0;
    bool    HLT_2e17_lhvloose_nod0;
    bool    HLT_2e15_lhvloose_nod0_L12EM13VH;
    bool    HLT_e24_lhmedium_e9_lhmedium;
    bool    HLT_e24_lhmedium_L1EM20VH;
    bool    HLT_e12_lhvloose_L12EM10VH;
    bool    HLT_e17_lhloose_2e9_lhloose;
    bool    HLT_mu24_ivarmedium;
    bool    HLT_mu24_imedium;
    bool    HLT_mu24_ivarloose;
    bool    HLT_mu24_iloose;
    bool    HLT_mu26_ivarmedium;
    bool    HLT_mu26_imedium;
    bool    HLT_mu20_ivarmedium_L1MU15;
    bool    HLT_mu20_imedium_L1MU15;
    bool    HLT_mu20_ivarloose_L1MU15;
    bool    HLT_mu20_iloose_L1MU15;
    bool    HLT_mu20_L1MU15;
    bool    HLT_mu20_mu8noL1;
    bool    HLT_mu22_mu8noL1;
    bool    HLT_mu22_2mu4noL1;
    bool    HLT_mu40;
    bool    HLT_mu50;
    bool    HLT_2mu10;
    bool    HLT_2mu10_nomucomb;
    bool    HLT_2mu14;
    bool    HLT_2mu14_nomucomb;
    bool    HLT_3mu6;
    bool    HLT_3mu6_msonly;
    bool    HLT_xe100_L1XE50;
    bool    HLT_xe80_mht_L1XE50;
    bool    HLT_xe90_mht_L1XE50;
    bool    HLT_xe110_pueta_L1XE50;
    bool    HLT_xe110_pufit_L1XE50;
    bool    HLT_xe100_tc_em_L1XE50;
    bool    HLT_xe80_tc_lcw_L1XE50;
    bool    HLT_xe90_tc_lcw_L1XE50;
    bool    HLT_xe80_tc_lcw_wEFMu_L1XE50;
    bool    HLT_e7_lhmedium_mu24;
    bool    HLT_e17_lhloose_nod0_mu14;
    bool    HLT_e26_lhmedium_nod0_L1EM22VHI_mu8noL1;
    bool    HLT_e24_lhmedium_nod0_L1EM22VHI_mu8noL1;
    bool    HLT_2e12_lhloose_L12EM10VH;
    bool    HLT_e17_lhloose_mu14;
    bool    HLT_mu18_mu8noL1;
    bool    HLT_xe70;

public:
    HLT() : HLT_e24_lhmedium_nod0_ivarloose(0),
            HLT_e24_lhtight_nod0_ivarloose(0),
            HLT_e26_lhtight_iloose(0),
            HLT_e26_lhtight_ivarloose(0),
            HLT_e26_lhtight_nod0_iloose(0),
            HLT_e26_lhtight_nod0_ivarloose(0),
            HLT_e60_lhmedium(0),
            HLT_e60_lhmedium_nod0(0),
            HLT_e120_lhloose_nod0(0),
            HLT_e140_lhloose_nod0(0),
            HLT_2e17_lhvloose_nod0(0),
            HLT_2e15_lhvloose_nod0_L12EM13VH(0),
            HLT_e24_lhmedium_e9_lhmedium(0),
            HLT_e24_lhmedium_L1EM20VH(0),
            HLT_e12_lhvloose_L12EM10VH(0),
            HLT_e17_lhloose_2e9_lhloose(0),
            HLT_mu24_ivarmedium(0),
            HLT_mu24_imedium(0),
            HLT_mu24_ivarloose(0),
            HLT_mu24_iloose(0),
            HLT_mu26_ivarmedium(0),
            HLT_mu26_imedium(0),
            HLT_mu20_ivarmedium_L1MU15(0),
            HLT_mu20_imedium_L1MU15(0),
            HLT_mu20_ivarloose_L1MU15(0),
            HLT_mu20_iloose_L1MU15(0),
            HLT_mu20_L1MU15(0),
            HLT_mu20_mu8noL1(0),
            HLT_mu22_mu8noL1(0),
            HLT_mu22_2mu4noL1(0),
            HLT_mu40(0),
            HLT_mu50(0),
            HLT_2mu10(0),
            HLT_2mu10_nomucomb(0),
            HLT_2mu14(0),
            HLT_2mu14_nomucomb(0),
            HLT_3mu6(0),
            HLT_3mu6_msonly(0),
            HLT_xe100_L1XE50(0),
            HLT_xe80_mht_L1XE50(0),
            HLT_xe90_mht_L1XE50(0),
            HLT_xe110_pueta_L1XE50(0),
            HLT_xe110_pufit_L1XE50(0),
            HLT_xe100_tc_em_L1XE50(0),
            HLT_xe80_tc_lcw_L1XE50(0),
            HLT_xe90_tc_lcw_L1XE50(0),
            HLT_xe80_tc_lcw_wEFMu_L1XE50(0),
            HLT_e7_lhmedium_mu24(0),
            HLT_e17_lhloose_nod0_mu14(0),
            HLT_e26_lhmedium_nod0_L1EM22VHI_mu8noL1(0),
            HLT_e24_lhmedium_nod0_L1EM22VHI_mu8noL1(0),
            HLT_2e12_lhloose_L12EM10VH(0),
            HLT_e17_lhloose_mu14(0),
            HLT_mu18_mu8noL1(0),
            HLT_xe70(0) {}
    ~HLT() {}

    // get methods
    bool    get_HLT_e24_lhmedium_nod0_ivarloose()           { return HLT_e24_lhmedium_nod0_ivarloose; }
    bool    get_HLT_e24_lhtight_nod0_ivarloose()            { return HLT_e24_lhtight_nod0_ivarloose; }
    bool    get_HLT_e26_lhtight_iloose()                    { return HLT_e26_lhtight_iloose; }
    bool    get_HLT_e26_lhtight_ivarloose()                 { return HLT_e26_lhtight_ivarloose; }
    bool    get_HLT_e26_lhtight_nod0_iloose()               { return HLT_e26_lhtight_nod0_iloose; }
    bool    get_HLT_e26_lhtight_nod0_ivarloose()            { return HLT_e26_lhtight_nod0_ivarloose; }
    bool    get_HLT_e60_lhmedium()                          { return HLT_e60_lhmedium; }
    bool    get_HLT_e60_lhmedium_nod0()                     { return HLT_e60_lhmedium_nod0; }
    bool    get_HLT_e120_lhloose_nod0()                     { return HLT_e120_lhloose_nod0; }
    bool    get_HLT_e140_lhloose_nod0()                     { return HLT_e140_lhloose_nod0; }
    bool    get_HLT_2e17_lhvloose_nod0()                    { return HLT_2e17_lhvloose_nod0; }
    bool    get_HLT_2e15_lhvloose_nod0_L12EM13VH()          { return HLT_2e15_lhvloose_nod0_L12EM13VH; }
    bool    get_HLT_e24_lhmedium_e9_lhmedium()              { return HLT_e24_lhmedium_e9_lhmedium; }
    bool    get_HLT_e24_lhmedium_L1EM20VH()                 { return HLT_e24_lhmedium_L1EM20VH; }
    bool    get_HLT_e12_lhvloose_L12EM10VH()                { return HLT_e12_lhvloose_L12EM10VH; }
    bool    get_HLT_e17_lhloose_2e9_lhloose()               { return HLT_e17_lhloose_2e9_lhloose; }
    bool    get_HLT_mu24_ivarmedium()                       { return HLT_mu24_ivarmedium; }
    bool    get_HLT_mu24_imedium()                          { return HLT_mu24_imedium; }
    bool    get_HLT_mu24_ivarloose()                        { return HLT_mu24_ivarloose; }
    bool    get_HLT_mu24_iloose()                           { return HLT_mu24_iloose; }
    bool    get_HLT_mu26_ivarmedium()                       { return HLT_mu26_ivarmedium; }
    bool    get_HLT_mu26_imedium()                          { return HLT_mu26_imedium; }
    bool    get_HLT_mu20_ivarmedium_L1MU15()                { return HLT_mu20_ivarmedium_L1MU15; }
    bool    get_HLT_mu20_imedium_L1MU15()                   { return HLT_mu20_imedium_L1MU15; }
    bool    get_HLT_mu20_ivarloose_L1MU15()                 { return HLT_mu20_ivarloose_L1MU15; }
    bool    get_HLT_mu20_iloose_L1MU15()                    { return HLT_mu20_iloose_L1MU15; }
    bool    get_HLT_mu20_L1MU15()                           { return HLT_mu20_L1MU15; }
    bool    get_HLT_mu20_mu8noL1()                          { return HLT_mu20_mu8noL1; }
    bool    get_HLT_mu22_mu8noL1()                          { return HLT_mu22_mu8noL1; }
    bool    get_HLT_mu22_2mu4noL1()                         { return HLT_mu22_2mu4noL1; }
    bool    get_HLT_mu40()                                  { return HLT_mu40; }
    bool    get_HLT_mu50()                                  { return HLT_mu50; }
    bool    get_HLT_2mu10()                                 { return HLT_2mu10; }
    bool    get_HLT_2mu10_nomucomb()                        { return HLT_2mu10_nomucomb; }
    bool    get_HLT_2mu14()                                 { return HLT_2mu14; }
    bool    get_HLT_2mu14_nomucomb()                        { return HLT_2mu14_nomucomb; }
    bool    get_HLT_3mu6()                                  { return HLT_3mu6; }
    bool    get_HLT_3mu6_msonly()                           { return HLT_3mu6_msonly; }
    bool    get_HLT_xe100_L1XE50()                          { return HLT_xe100_L1XE50; }
    bool    get_HLT_xe80_mht_L1XE50()                       { return HLT_xe80_mht_L1XE50; }
    bool    get_HLT_xe90_mht_L1XE50()                       { return HLT_xe90_mht_L1XE50; }
    bool    get_HLT_xe110_pueta_L1XE50()                    { return HLT_xe110_pueta_L1XE50; }
    bool    get_HLT_xe110_pufit_L1XE50()                    { return HLT_xe110_pufit_L1XE50; }
    bool    get_HLT_xe100_tc_em_L1XE50()                    { return HLT_xe100_tc_em_L1XE50; }
    bool    get_HLT_xe80_tc_lcw_L1XE50()                    { return HLT_xe80_tc_lcw_L1XE50; }
    bool    get_HLT_xe90_tc_lcw_L1XE50()                    { return HLT_xe90_tc_lcw_L1XE50; }
    bool    get_HLT_xe80_tc_lcw_wEFMu_L1XE50()              { return HLT_xe80_tc_lcw_wEFMu_L1XE50; }
    bool    get_HLT_e7_lhmedium_mu24()                      { return HLT_e7_lhmedium_mu24; }
    bool    get_HLT_e17_lhloose_nod0_mu14()                 { return HLT_e17_lhloose_nod0_mu14; }
    bool    get_HLT_e26_lhmedium_nod0_L1EM22VHI_mu8noL1()   { return HLT_e26_lhmedium_nod0_L1EM22VHI_mu8noL1; }
    bool    get_HLT_e24_lhmedium_nod0_L1EM22VHI_mu8noL1()   { return HLT_e24_lhmedium_nod0_L1EM22VHI_mu8noL1; }
    bool    get_HLT_2e12_lhloose_L12EM10VH()                { return HLT_2e12_lhloose_L12EM10VH; }
    bool    get_HLT_e17_lhloose_mu14()                      { return HLT_e17_lhloose_mu14; }
    bool    get_HLT_mu18_mu8noL1()                          { return HLT_mu18_mu8noL1; }
    bool    get_HLT_xe70()                                  { return HLT_xe70; }

    // set methods
    void    set_HLT_e24_lhmedium_nod0_ivarloose(bool b)         { HLT_e24_lhmedium_nod0_ivarloose = b; }
    void    set_HLT_e24_lhtight_nod0_ivarloose(bool b)          { HLT_e24_lhtight_nod0_ivarloose = b; }
    void    set_HLT_e26_lhtight_iloose(bool b)                  { HLT_e26_lhtight_iloose = b; }
    void    set_HLT_e26_lhtight_ivarloose(bool b)               { HLT_e26_lhtight_ivarloose = b; }
    void    set_HLT_e26_lhtight_nod0_iloose(bool b)             { HLT_e26_lhtight_nod0_iloose = b; }
    void    set_HLT_e26_lhtight_nod0_ivarloose(bool b)          { HLT_e26_lhtight_nod0_ivarloose = b; }
    void    set_HLT_e60_lhmedium(bool b)                        { HLT_e60_lhmedium = b; }
    void    set_HLT_e60_lhmedium_nod0(bool b)                   { HLT_e60_lhmedium_nod0 = b; }
    void    set_HLT_e120_lhloose_nod0(bool b)                   { HLT_e120_lhloose_nod0 = b; }
    void    set_HLT_e140_lhloose_nod0(bool b)                   { HLT_e140_lhloose_nod0 = b; }
    void    set_HLT_2e17_lhvloose_nod0(bool b)                  { HLT_2e17_lhvloose_nod0 = b; }
    void    set_HLT_2e15_lhvloose_nod0_L12EM13VH(bool b)        { HLT_2e15_lhvloose_nod0_L12EM13VH = b; }
    void    set_HLT_e24_lhmedium_e9_lhmedium(bool b)            { HLT_e24_lhmedium_e9_lhmedium = b; }
    void    set_HLT_e24_lhmedium_L1EM20VH(bool b)               { HLT_e24_lhmedium_L1EM20VH = b; }
    void    set_HLT_e12_lhvloose_L12EM10VH(bool b)              { HLT_e12_lhvloose_L12EM10VH = b; }
    void    set_HLT_e17_lhloose_2e9_lhloose(bool b)             { HLT_e17_lhloose_2e9_lhloose = b; }
    void    set_HLT_mu24_ivarmedium(bool b)                     { HLT_mu24_ivarmedium = b; }
    void    set_HLT_mu24_imedium(bool b)                        { HLT_mu24_imedium = b; }
    void    set_HLT_mu24_ivarloose(bool b)                      { HLT_mu24_ivarloose = b; }
    void    set_HLT_mu24_iloose(bool b)                         { HLT_mu24_iloose = b; }
    void    set_HLT_mu26_ivarmedium(bool b)                     { HLT_mu26_ivarmedium = b; }
    void    set_HLT_mu26_imedium(bool b)                        { HLT_mu26_imedium = b; }
    void    set_HLT_mu20_ivarmedium_L1MU15(bool b)              { HLT_mu20_ivarmedium_L1MU15 = b; }
    void    set_HLT_mu20_imedium_L1MU15(bool b)                 { HLT_mu20_imedium_L1MU15 = b; }
    void    set_HLT_mu20_ivarloose_L1MU15(bool b)               { HLT_mu20_ivarloose_L1MU15 = b; }
    void    set_HLT_mu20_iloose_L1MU15(bool b)                  { HLT_mu20_iloose_L1MU15 = b; }
    void    set_HLT_mu20_L1MU15(bool b)                         { HLT_mu20_L1MU15 = b; }
    void    set_HLT_mu20_mu8noL1(bool b)                        { HLT_mu20_mu8noL1 = b; }
    void    set_HLT_mu22_mu8noL1(bool b)                        { HLT_mu22_mu8noL1 = b; }
    void    set_HLT_mu22_2mu4noL1(bool b)                       { HLT_mu22_2mu4noL1 = b; }
    void    set_HLT_mu40(bool b)                                { HLT_mu40 = b; }
    void    set_HLT_mu50(bool b)                                { HLT_mu50 = b; }
    void    set_HLT_2mu10(bool b)                               { HLT_2mu10 = b; }
    void    set_HLT_2mu10_nomucomb(bool b)                      { HLT_2mu10_nomucomb = b; }
    void    set_HLT_2mu14(bool b)                               { HLT_2mu14 = b; }
    void    set_HLT_2mu14_nomucomb(bool b)                      { HLT_2mu14_nomucomb = b; }
    void    set_HLT_3mu6(bool b)                                { HLT_3mu6 = b; }
    void    set_HLT_3mu6_msonly(bool b)                         { HLT_3mu6_msonly = b; }
    void    set_HLT_xe100_L1XE50(bool b)                        { HLT_xe100_L1XE50 = b; }
    void    set_HLT_xe80_mht_L1XE50(bool b)                     { HLT_xe80_mht_L1XE50 = b; }
    void    set_HLT_xe90_mht_L1XE50(bool b)                     { HLT_xe90_mht_L1XE50 = b; }
    void    set_HLT_xe110_pueta_L1XE50(bool b)                  { HLT_xe110_pueta_L1XE50 = b; }
    void    set_HLT_xe110_pufit_L1XE50(bool b)                  { HLT_xe110_pufit_L1XE50 = b; }
    void    set_HLT_xe100_tc_em_L1XE50(bool b)                  { HLT_xe100_tc_em_L1XE50 = b; }
    void    set_HLT_xe80_tc_lcw_L1XE50(bool b)                  { HLT_xe80_tc_lcw_L1XE50 = b; }
    void    set_HLT_xe90_tc_lcw_L1XE50(bool b)                  { HLT_xe90_tc_lcw_L1XE50 = b; }
    void    set_HLT_xe80_tc_lcw_wEFMu_L1XE50(bool b)            { HLT_xe80_tc_lcw_wEFMu_L1XE50 = b; }
    void    set_HLT_e7_lhmedium_mu24(bool b)                    { HLT_e7_lhmedium_mu24 = b; }
    void    set_HLT_e17_lhloose_nod0_mu14(bool b)               { HLT_e17_lhloose_nod0_mu14 = b; }
    void    set_HLT_e26_lhmedium_nod0_L1EM22VHI_mu8noL1(bool b) { HLT_e26_lhmedium_nod0_L1EM22VHI_mu8noL1 = b; }
    void    set_HLT_e24_lhmedium_nod0_L1EM22VHI_mu8noL1(bool b) { HLT_e24_lhmedium_nod0_L1EM22VHI_mu8noL1 = b; }
    void    set_HLT_2e12_lhloose_L12EM10VH(bool b)              { HLT_2e12_lhloose_L12EM10VH = b; }
    void    set_HLT_e17_lhloose_mu14(bool b)                    { HLT_e17_lhloose_mu14 = b; }
    void    set_HLT_mu18_mu8noL1(bool b)                        { HLT_mu18_mu8noL1 = b; }
    void    set_HLT_xe70(bool b)                                { HLT_xe70 = b; }
};

#endif // #define HIGH_LEVEL_TRIGGER_H
