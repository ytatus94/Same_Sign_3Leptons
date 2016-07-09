#ifndef LEPTONS_H
#define LEPTONS_H

#include "ytCutflows/Particle.h"

class Lepton : public Particle {
    // user defined variables
    int		flavor;
    bool	isSignal;
    // ntuple variables
    int	    charge;
    double  d0pvtx;
    //double  z0pvtx;
    double	z0sinTheta;
	bool	passOR;
    double  sigd0;
	int		type; // MC only
	int 	origin; // MC only
    double  ptcone20;
    double  ptcone30;
    double  ptcone40;
    double  ptvarcone20;
    double  ptvarcone30;
    double  ptvarcone40;
    double  topoetcone20;
    double  topoetcone30;
    double  topoetcone40;
    bool    passIsoTight;
    bool    passIsoLoose;
    bool    passIsoLooseTO;
    //bool	passIsoVeryLoose;
    //bool	passIsoVeryLooseTO;
    bool    passIsoGrad;
    bool    passIsoGradLoose;
    bool    passIsoGradCustom;
    bool    passIsoGradCustomTight;

public:
	Lepton() : flavor(0), isSignal(0),
               charge(0), d0pvtx(0), z0sinTheta(0), passOR(0), sigd0(0),
               type(0), origin(0),
               ptcone20(0), ptcone30(0), ptcone40(0),
               ptvarcone20(0), ptvarcone30(0), ptvarcone40(0),
               topoetcone20(0), topoetcone30(0), topoetcone40(0),
               passIsoTight(0), passIsoLoose(0), passIsoLooseTO(0),
               passIsoGrad(0), passIsoGradLoose(0), passIsoGradCustom(0), passIsoGradCustomTight(0) {}
    ~Lepton() {}
    // get methods
    int		get_flavor()					{ return flavor; }
    bool	get_isSignal()					{ return isSignal; }
    int	    get_charge()					{ return charge; }
    double  get_d0pvtx()					{ return d0pvtx; }
    //double  get_z0pvtx()					{ return z0pvtx; }
    double  get_z0sinTheta()				{ return z0sinTheta; }
	bool	get_passOR()					{ return passOR; }
    double  get_sigd0()						{ return sigd0; }
	int		get_type()						{ return type; }
	int		get_origin()					{ return origin; }
    double  get_ptcone20()					{ return ptcone20; }
    double  get_ptcone30()					{ return ptcone30; }
    double  get_ptcone40()					{ return ptcone40; }
    double  get_ptvarcone20()				{ return ptvarcone20; }
    double  get_ptvarcone30()				{ return ptvarcone30; }
    double  get_ptvarcone40()				{ return ptvarcone40; }
    double  get_topoetcone20()				{ return topoetcone20; }
    double  get_topoetcone30()				{ return topoetcone30; }
    double  get_topoetcone40()				{ return topoetcone40; }
    bool    get_passIsoTight()	    		{ return passIsoTight; }
    bool    get_passIsoLoose()	    		{ return passIsoLoose; }
    bool    get_passIsoLooseTO()			{ return passIsoLooseTO; }
    //bool	get_passIsoVeryLooseTO()		{ return passIsoVeryLooseTO; }
    //bool	get_passIsoVeryLoose()			{ return passIsoVeryLoose; }
    bool    get_passIsoGrad()				{ return passIsoGrad; }
    bool    get_passIsoGradLoose()			{ return passIsoGradLoose; }
    bool    get_passIsoGradCustom()			{ return passIsoGradCustom; }
    bool    get_passIsoGradCustomTight()	{ return passIsoGradCustomTight; }
    // set methods
    void	set_flavor(int i)					{ flavor = i; }
    void	set_isSignal(bool b)				{ isSignal = b; }
    void    set_charge(int i)					{ charge = i; }
    void    set_d0pvtx(double d)				{ d0pvtx = d; }
    //void    set_z0pvtx(double d)				{ z0pvtx = d; }
    void    set_z0sinTheta(double d)			{ z0sinTheta = d; }
	void	set_passOR(bool b)					{ passOR = b; }
    void    set_sigd0(double d)					{ sigd0 = d; }
	void	set_type(int i)						{ type = i; }
	void	set_origin(int i)					{ origin = i; }
    void    set_ptcone20(double d)				{ ptcone20 = d; }
    void    set_ptcone30(double d)				{ ptcone30 = d; }
    void    set_ptcone40(double d)				{ ptcone40 = d; }
    void    set_ptvarcone20(double d)			{ ptvarcone20 = d; }
    void    set_ptvarcone30(double d)			{ ptvarcone30 = d; }
    void    set_ptvarcone40(double d)			{ ptvarcone40 = d; }
    void    set_topoetcone20(double d)			{ topoetcone20 = d; }
    void    set_topoetcone30(double d)			{ topoetcone30 = d; }
    void    set_topoetcone40(double d)			{ topoetcone40 = d; }
    void    set_passIsoTight(bool b)			{ passIsoTight = b; }
    void    set_passIsoLoose(bool b)			{ passIsoLoose = b; }
    void    set_passIsoLooseTO(bool b)			{ passIsoLooseTO = b; }
    //void	set_passIsoVeryLooseTO(bool b)		{ passIsoVeryLooseTO = b; }
    //void	set_passIsoVeryLoose(bool b)		{ passIsoVeryLoose = b; }
    void    set_passIsoGrad(bool b)				{ passIsoGrad = b; }
    void    set_passIsoGradLoose(bool b)		{ passIsoGradLoose = b; }
    void    set_passIsoGradCustom(bool b)		{ passIsoGradCustom = b; }
    void    set_passIsoGradCustomTight(bool b)	{ passIsoGradCustomTight = b; }
};

class Electron : public Lepton {
    // ntuple variables
    double	etaclus;
    //bool	isTight;
    //bool	isMedium;
    //bool	isLoose;
    bool    isTightLH;
    bool    isMediumLH;
    bool    isLooseAndBLayerLH;
    //double	SFwTight;
    //double	SFwMedium;
    double  SFwTightLH;
    double  SFwMediumLH;
	double	SFwLooseAndBLayerLH;
	//float	IsoSFwTightLH;
	//double	SFwTrigTightLH_single;
	//double	SFwTrigTightLH_e12_lhloose_L1EM10VH;
	//double	SFwTrigTightLH_e17_lhloose;
	float	IsoSFwMediumLH;
	double	SFwTrigMediumLH_single;
	double	SFwTrigMediumLH_e12_lhloose_L1EM10VH;
	double	SFwTrigMediumLH_e17_lhloose;
	double	SFwTrigLooseAndBLayerLH_e12_lhloose_L1EM10VH;
    int		nBLayerHits;
	int		expectBLayerHit;
	int		bkgMotherPdgId; // MC only
	int		bkgOrigin; // MC only
	int		chFlip; // MC only
	bool	trigMatch_e12_lhloose_L1EM10VH;
	bool	trigMatch_e17_lhloose;
	bool	trigMatch_e17_lhloose_mu14;
	bool	trigMatch_e17_lhloose_nod0_mu14;
	bool	trigMatch_e24_lhmedium_iloose_L1EM20VH;
	bool	trigMatch_e60_lhmedium;
	bool	trigMatch_2e12_lhloose_L12EM10VH;
	bool	trigMatch_2e15_lhloose_L12EM10VH;
	bool	trigMatch_2e15_lhvloose_L12EM13VH;
	bool	trigMatch_2e15_lhvloose_nod0_L12EM13VH;
	bool	trigMatch_2e17_lhvloose_nod0_L12EM15VH; // MC only
	bool	trigMatch_2e17_lhvloose_nod0; // Data only

public:
    Electron() : etaclus(0),
                 isTightLH(0), isMediumLH(0), isLooseAndBLayerLH(0),
				 SFwTightLH(0), SFwMediumLH(0), SFwLooseAndBLayerLH(0),
				 //IsoSFwTightLH(0), 
                 //SFwTrigTightLH_single(0), SFwTrigTightLH_e12_lhloose_L1EM10VH(0), SFwTrigTightLH_e17_lhloose(0),
                 IsoSFwMediumLH(0),
				 SFwTrigMediumLH_single(0), SFwTrigMediumLH_e12_lhloose_L1EM10VH(0), SFwTrigMediumLH_e17_lhloose(0),
				 SFwTrigLooseAndBLayerLH_e12_lhloose_L1EM10VH(0),
				 nBLayerHits(0), expectBLayerHit(0), 
				 bkgMotherPdgId(0), bkgOrigin(0), 
				 chFlip(0),
				 trigMatch_e12_lhloose_L1EM10VH(0),
				 trigMatch_e17_lhloose(0), trigMatch_e17_lhloose_mu14(0), trigMatch_e17_lhloose_nod0_mu14(0),
				 trigMatch_e24_lhmedium_iloose_L1EM20VH(0),
				 trigMatch_e60_lhmedium(0),
				 trigMatch_2e12_lhloose_L12EM10VH(0),
				 trigMatch_2e15_lhloose_L12EM10VH(0), trigMatch_2e15_lhvloose_L12EM13VH(0), trigMatch_2e15_lhvloose_nod0_L12EM13VH(0),
				 trigMatch_2e17_lhvloose_nod0_L12EM15VH(0),
				 trigMatch_2e17_lhvloose_nod0(0) {}

    ~Electron() {}
    // get methods
	double	get_etaclus()										{ return etaclus; }
    //bool	get_isTight()										{ return isTight; }
    //bool	get_isMedium()										{ return isMedium; }
    //bool	get_isLoose()										{ return isLoose; }
    bool	get_isTightLH()										{ return isTightLH; }
    bool	get_isMediumLH()									{ return isMediumLH; }
    bool	get_isLooseAndBLayerLH()							{ return isLooseAndBLayerLH; }
    //double	get_SFwTight()      							{ return SFwTight; }
    //double	get_SFwMedium()     							{ return SFwMedium; }
    double	get_SFwTightLH()    								{ return SFwTightLH; }
    double	get_SFwMediumLH()   								{ return SFwMediumLH; }
	double	get_SFwLooseAndBLayerLH()							{ return SFwLooseAndBLayerLH; }
	//float	get_IsoSFwTightLH()									{ return IsoSFwTightLH; }
    //double	get_SFwTrigTightLH_single() 						{ return SFwTrigTightLH_single; }
	//double	get_SFwTrigTightLH_e12_lhloose_L1EM10VH() 			{ return SFwTrigTightLH_e12_lhloose_L1EM10VH;; }
	//double	get_SFwTrigTightLH_e17_lhloose() 					{ return SFwTrigTightLH_e17_lhloose; }
	float	get_IsoSFwMediumLH()								{ return IsoSFwMediumLH; }
	double	get_SFwTrigMediumLH_single()						{ return SFwTrigMediumLH_single; }
	double	get_SFwTrigMediumLH_e12_lhloose_L1EM10VH() 			{ return SFwTrigMediumLH_e12_lhloose_L1EM10VH; }
	double	get_SFwTrigMediumLH_e17_lhloose()					{ return SFwTrigMediumLH_e17_lhloose; }
	double	get_SFwTrigLooseAndBLayerLH_e12_lhloose_L1EM10VH() 	{ return SFwTrigLooseAndBLayerLH_e12_lhloose_L1EM10VH; }
    int		get_nBLayerHits() 									{ return nBLayerHits; }
	int 	get_expectBLayerHit() 								{ return expectBLayerHit; }
	int 	get_bkgMotherPdgId() 								{ return bkgMotherPdgId; }
	int 	get_bkgOrigin() 									{ return bkgOrigin; }
	int 	get_chFlip() 										{ return chFlip; }
	bool 	get_trigMatch_e12_lhloose_L1EM10VH() 				{ return trigMatch_e12_lhloose_L1EM10VH; }
	bool 	get_trigMatch_e17_lhloose() 						{ return trigMatch_e17_lhloose; }
	bool	get_trigMatch_e17_lhloose_mu14()					{ return trigMatch_e17_lhloose_mu14; }
	bool	get_trigMatch_e17_lhloose_nod0_mu14()				{ return trigMatch_e17_lhloose_nod0_mu14; }
	bool 	get_trigMatch_e24_lhmedium_iloose_L1EM20VH() 		{ return trigMatch_e24_lhmedium_iloose_L1EM20VH; }
	bool 	get_trigMatch_e60_lhmedium() 						{ return trigMatch_e60_lhmedium; }
	bool	get_trigMatch_2e12_lhloose_L12EM10VH()				{ return trigMatch_2e12_lhloose_L12EM10VH; }
	bool	get_trigMatch_2e15_lhloose_L12EM10VH()				{ return trigMatch_2e15_lhloose_L12EM10VH; }
	bool	get_trigMatch_2e15_lhvloose_L12EM13VH()				{ return trigMatch_2e15_lhvloose_L12EM13VH; }
	bool	get_trigMatch_2e15_lhvloose_nod0_L12EM13VH()		{ return trigMatch_2e15_lhvloose_nod0_L12EM13VH; }
	bool	get_trigMatch_2e17_lhvloose_nod0_L12EM15VH()		{ return trigMatch_2e17_lhvloose_nod0_L12EM15VH; }
	bool	get_trigMatch_2e17_lhvloose_nod0()					{ return trigMatch_2e17_lhvloose_nod0; }
    // set methods
    void	set_etaclus(double d)										{ etaclus = d; }
    //void    set_isTight(bool b)         								{ isTight = b; }
    //void    set_isMedium(bool b)        								{ isMedium = b; }
    //void    set_isLoose(bool b)         								{ isLoose = b; }
    void    set_isTightLH(bool b)       								{ isTightLH = b; }
    void    set_isMediumLH(bool b)      								{ isMediumLH = b; }
	void	set_isLooseAndBLayerLH(bool b)								{ isLooseAndBLayerLH = b; }
    //void    set_SFwTight(double d)     								{ SFwTight = d; }
    //void    set_SFwMedium(double d)     								{ SFwMedium = d; }
    void    set_SFwTightLH(double d)    								{ SFwTightLH = d; }
    void    set_SFwMediumLH(double d)									{ SFwMediumLH = d; }
	void	set_SFwLooseAndBLayerLH(double d)							{ SFwLooseAndBLayerLH = d; }
	//void	set_IsoSFwTightLH(float f)									{ IsoSFwTightLH = f; }
	//void	set_SFwTrigTightLH_single(double d)							{ SFwTrigTightLH_single = d; }
	//void 	set_SFwTrigTightLH_e12_lhloose_L1EM10VH(double d)			{ SFwTrigTightLH_e12_lhloose_L1EM10VH = d;}
	//void	set_SFwTrigTightLH_e17_lhloose(double d)					{ SFwTrigTightLH_e17_lhloose = d; }
	void	set_IsoSFwMediumLH(float f)									{ IsoSFwMediumLH = f; }
	void	set_SFwTrigMediumLH_single(double d)						{ SFwTrigMediumLH_single = d; }
	void	set_SFwTrigMediumLH_e12_lhloose_L1EM10VH(double d)			{ SFwTrigMediumLH_e12_lhloose_L1EM10VH = d; }
	void	set_SFwTrigMediumLH_e17_lhloose(double d)					{ SFwTrigMediumLH_e17_lhloose = d; }
	void	set_SFwTrigLooseAndBLayerLH_e12_lhloose_L1EM10VH(double d)	{SFwTrigLooseAndBLayerLH_e12_lhloose_L1EM10VH = d; }
    void	set_nBLayerHits(int i)										{ nBLayerHits = i; }
	void	set_expectBLayerHit(int i)									{ expectBLayerHit = i; }
	void	set_bkgMotherPdgId(int i)									{ bkgMotherPdgId = i; }
	void	set_bkgOrigin(int i)										{ bkgOrigin = i; }
	void	set_chFlip(int i)											{ chFlip = i; }
	void	set_trigMatch_e12_lhloose_L1EM10VH(bool b)					{ trigMatch_e12_lhloose_L1EM10VH = b; }
	void	set_trigMatch_e17_lhloose(bool b)							{ trigMatch_e17_lhloose = b; }
	void	set_trigMatch_e17_lhloose_mu14(bool b)						{ trigMatch_e17_lhloose_mu14 = b; }
	void	set_trigMatch_e17_lhloose_nod0_mu14(bool b)					{ trigMatch_e17_lhloose_nod0_mu14 = b; }
	void	set_trigMatch_e24_lhmedium_iloose_L1EM20VH(bool b)			{ trigMatch_e24_lhmedium_iloose_L1EM20VH = b; }
	void	set_trigMatch_e60_lhmedium(bool b)							{ trigMatch_e60_lhmedium = b; }
	void	set_trigMatch_2e12_lhloose_L12EM10VH(bool b)				{ trigMatch_2e12_lhloose_L12EM10VH = b; }
	void	set_trigMatch_2e15_lhloose_L12EM10VH(bool b)				{ trigMatch_2e15_lhloose_L12EM10VH = b; }
	void	set_trigMatch_2e15_lhvloose_L12EM13VH(bool b)				{ trigMatch_2e15_lhvloose_L12EM13VH = b; }
	void	set_trigMatch_2e15_lhvloose_nod0_L12EM13VH(bool b)			{ trigMatch_2e15_lhvloose_nod0_L12EM13VH = b; }
	void	set_trigMatch_2e17_lhvloose_nod0_L12EM15VH(bool b)			{ trigMatch_2e17_lhvloose_nod0_L12EM15VH = b; }
	void	set_trigMatch_2e17_lhvloose_nod0(bool b)					{ trigMatch_2e17_lhvloose_nod0 = b; }
};

class Muon : public Lepton {
    // ntuple variables
    double  SFw;
	double 	IsoSFw;
    bool    isBad;
    bool    isCosmic;
	bool	isTight;
	float	MuTrigSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50;
	//bool	trigMatch_MU10;
	//bool	trigMatch_MU15;
	//bool	trigMatch_MU20;
	bool	trigMatch_mu8noL1;
	bool	trigMatch_mu14;
	bool	trigMatch_mu18;
	bool	trigMatch_mu18_mu8noL1;
	bool	trigMatch_mu20_mu8noL1;
	bool	trigMatch_mu22_mu8noL1;
	bool	trigMatch_mu26_imedium;
	bool	trigMatch_mu50;
	bool	trigMatch_e17_lhloose_mu14;
	bool	trigMatch_e17_lhloose_nod0_mu14;

public:
    Muon() : SFw(0), IsoSFw(0),
			 isBad(0), isCosmic(0), isTight(0),
			 MuTrigSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50(0),
			 trigMatch_mu8noL1(0), 
			 trigMatch_mu14(0),
			 trigMatch_mu18(0), trigMatch_mu18_mu8noL1(0),
			 trigMatch_mu20_mu8noL1(0),
			 trigMatch_mu22_mu8noL1(0),
			 trigMatch_mu26_imedium(0),
			 trigMatch_mu50(0),
			 trigMatch_e17_lhloose_mu14(0), trigMatch_e17_lhloose_nod0_mu14(0) {}
    ~Muon() {}
    // get methods
    double	get_SFw()	    									{ return SFw; }
	double	get_IsoSFw()										{ return IsoSFw; }
    bool	get_isBad()	    									{ return isBad; }
    bool	get_isCosmic()  									{ return isCosmic; }
	bool	get_isTight()										{ return isTight; }
	float	get_MuTrigSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50()	{ return MuTrigSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50; }
	//bool	get_trigMatch_MU10()								{ return trigMatch_MU10; }
	//bool	get_trigMatch_MU15()								{ return trigMatch_MU15; }
	//bool	get_trigMatch_MU20()								{ return trigMatch_MU20; }
	bool	get_trigMatch_mu8noL1()								{ return trigMatch_mu8noL1; }
	bool	get_trigMatch_mu14()								{ return trigMatch_mu14; }
	bool	get_trigMatch_mu18()								{ return trigMatch_mu18; }
	bool	get_trigMatch_mu18_mu8noL1()						{ return trigMatch_mu18_mu8noL1; }
	bool	get_trigMatch_mu20_mu8noL1()						{ return trigMatch_mu20_mu8noL1; }
	bool	get_trigMatch_mu22_mu8noL1()						{ return trigMatch_mu22_mu8noL1; }
	bool	get_trigMatch_mu26_imedium()						{ return trigMatch_mu26_imedium; }
	bool	get_trigMatch_mu50()								{ return trigMatch_mu50; }
	bool	get_trigMatch_e17_lhloose_mu14()					{ return trigMatch_e17_lhloose_mu14; }
	bool	get_trigMatch_e17_lhloose_nod0_mu14()				{ return trigMatch_e17_lhloose_nod0_mu14; }
    // set methods
    void	set_SFw(double d)											{ SFw = d; }
    void	set_isBad(bool b)											{ isBad = b; }
    void	set_isCosmic(bool b)										{ isCosmic = b; }
	void	set_IsoSFw(double b)										{ IsoSFw = b; }
	void	set_isTight(bool b)											{ isTight = b; }
	void	set_MuTrigSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50(float f)	{ MuTrigSF_HLT_mu20_iloose_L1MU15_OR_HLT_mu50 = f; }
	//void	set_trigMatch_MU10(bool b)									{ trigMatch_MU10 = b; }
	//void	set_trigMatch_MU15(bool b)									{ trigMatch_MU15 = b; }
	//void	set_trigMatch_MU20(bool b)									{ trigMatch_MU20 = b; }
	void	set_trigMatch_mu8noL1(bool b)								{ trigMatch_mu8noL1 = b; }
	void	set_trigMatch_mu14(bool b)									{ trigMatch_mu14 = b; }
	void	set_trigMatch_mu18(bool b)									{ trigMatch_mu18 = b; }
	void	set_trigMatch_mu18_mu8noL1(bool b)							{ trigMatch_mu18_mu8noL1 = b; }
	void	set_trigMatch_mu20_mu8noL1(bool b)							{ trigMatch_mu20_mu8noL1 = b; }
	void	set_trigMatch_mu22_mu8noL1(bool b)							{ trigMatch_mu22_mu8noL1 = b; }
	void	set_trigMatch_mu26_imedium(bool b)							{ trigMatch_mu26_imedium = b; }
	void	set_trigMatch_mu50(bool b)									{ trigMatch_mu50 = b; }
	void	set_trigMatch_e17_lhloose_mu14(bool b)						{ trigMatch_e17_lhloose_mu14 = b; }
	void	set_trigMatch_e17_lhloose_nod0_mu14(bool b)					{ trigMatch_e17_lhloose_nod0_mu14 = b; }
};

#endif // #define LEPTONS_H
