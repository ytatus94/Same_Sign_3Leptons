#ifndef LEPTONS_H
#define LEPTONS_H

#include "MyPackages/Particle.h"

class Lepton : public Particle {
    // user defined variables
    int	    flavor;
    bool    isSignal;
    // ntuple variables
    int	    charge;
    double  d0pvtx;
    double  z0pvtx;
    double  sigd0;
    double  sigd0old;
    int	    type;
    int	    origin;
    double  ptcone20;
    double  ptcone30;
    double  ptcone40;
    double  ptvarcone20;
    double  ptvarcone30;
    double  ptvarcone40;
    double  topoetcone20;
    double  topoetcone30;
    double  topoetcone40;
    bool    passIsoLooseTO;
    bool    passIsoLoose;
    bool    passIsoTight;
    bool    passIsoGrad;
    bool    passIsoGradLoose;

public:
    Lepton() : flavor(0), isSignal(0),
               charge(0), d0pvtx(0), z0pvtx(0),
	       sigd0(0), sigd0old(0),
	       type(0), origin(0),
               ptcone20(0), ptcone30(0), ptcone40(0),
               ptvarcone20(0), ptvarcone30(0), ptvarcone40(0),
               topoetcone20(0), topoetcone30(0), topoetcone40(0),
               passIsoLooseTO(0),
               passIsoLoose(0), passIsoTight(0),
               passIsoGrad(0), passIsoGradLoose(0) {}
    ~Lepton() {}
    // get methods
    int	    get_flavor()            { return flavor; }
    bool    get_isSignal()          { return isSignal; }
    int	    get_charge()            { return charge; }
    double  get_d0pvtx()            { return d0pvtx; }
    double  get_z0pvtx()            { return z0pvtx; }
    double  get_sigd0()             { return sigd0; }
    double  get_sigd0old()	    { return sigd0old; }
    int	    get_type()		    { return type; }
    int	    get_origin()	    { return origin; }
    double  get_ptcone20()          { return ptcone20; }
    double  get_ptcone30()          { return ptcone30; }
    double  get_ptcone40()          { return ptcone40; }
    double  get_ptvarcone20()	    { return ptvarcone20; }
    double  get_ptvarcone30()	    { return ptvarcone30; }
    double  get_ptvarcone40()	    { return ptvarcone40; }
    double  get_topoetcone20()	    { return topoetcone20; }
    double  get_topoetcone30()	    { return topoetcone30; }
    double  get_topoetcone40()	    { return topoetcone40; }
    bool    get_passIsoLooseTO()    { return passIsoLooseTO; }
    bool    get_passIsoLoose()	    { return passIsoLoose; }
    bool    get_passIsoTight()	    { return passIsoTight; }
    bool    get_passIsoGrad()	    { return passIsoGrad; }
    bool    get_passIsoGradLoose()  { return passIsoGradLoose; }
    // set methods
    void    set_flavor(int i)               { flavor = i; }
    void    set_isSignal(bool b)            { isSignal = b; }
    void    set_charge(int i)               { charge = i; }
    void    set_d0pvtx(double d)            { d0pvtx = d; }
    void    set_z0pvtx(double d)            { z0pvtx = d; }
    void    set_sigd0(double d)             { sigd0 = d; }
    void    set_sigd0old(double d)          { sigd0old = d; }
    void    set_type(int i)		    { type = i; }
    void    set_origin(int i)		    { origin = i; }
    void    set_ptcone20(double d)          { ptcone20 = d; }
    void    set_ptcone30(double d)          { ptcone30 = d; }
    void    set_ptcone40(double d)          { ptcone40 = d; }
    void    set_ptvarcone20(double d)	    { ptvarcone20 = d; }
    void    set_ptvarcone30(double d)	    { ptvarcone30 = d; }
    void    set_ptvarcone40(double d)	    { ptvarcone40 = d; }
    void    set_topoetcone20(double d)	    { topoetcone20 = d; }
    void    set_topoetcone30(double d)	    { topoetcone30 = d; }
    void    set_topoetcone40(double d)	    { topoetcone40 = d; }
    void    set_passIsoLooseTO(bool b)	    { passIsoLooseTO = b; }
    void    set_passIsoLoose(bool b)	    { passIsoLoose = b; }
    void    set_passIsoTight(bool b)	    { passIsoTight = b; }
    void    set_passIsoGrad(bool b)         { passIsoGrad = b; }
    void    set_passIsoGradLoose(bool b)    { passIsoGradLoose = b; }
};

class Electron : public Lepton {
    // ntuple variables
    double  SFwMedium;
    double  SFwMediumLH;
    double  SFwTight;
    double  SFwTightLH;
    bool    isLooseLH;
    bool    isMediumLH;
    bool    isTightLH;
    bool    isLoose;
    bool    isMedium;
    bool    isTight;
    double  etaclus;
    int	    nBLayerHits;
    int	    expectBLayerHit;
    int	    bkgMotherPdgId;
    int	    bkgOrigin;

public:
    Electron() : SFwMedium(0), SFwMediumLH(0),
                 SFwTight(0), SFwTightLH(0),
                 isLooseLH(0), isMediumLH(0), isTightLH(0),
                 isLoose(0), isMedium(0), isTight(0),
		 etaclus(0), nBLayerHits(0), expectBLayerHit(0),
		 bkgMotherPdgId(0), bkgOrigin(0) {}
    ~Electron() {}
    // get methods
    double  get_SFwMedium()       { return SFwMedium; }
    double  get_SFwMediumLH()     { return SFwMediumLH; }
    double  get_SFwTight()        { return SFwTight; }
    double  get_SFwTightLH()      { return SFwTightLH; }
    bool    get_isLooseLH()       { return isLooseLH; }
    bool    get_isMediumLH()      { return isMediumLH; }
    bool    get_isTightLH()       { return isTightLH; }
    bool    get_isLoose()         { return isLoose; }
    bool    get_isMedium()        { return isMedium; }
    bool    get_isTight()         { return isTight; }
    double  get_etaclus()	  { return etaclus; }
    int	    get_nBLayerHits()	  { return nBLayerHits; }
    int	    get_expectBLayerHit() { return expectBLayerHit; }
    int	    get_bkgMotherPdgId()  { return bkgMotherPdgId; }
    int	    get_bkgOrigin()	  { return bkgOrigin; }
    // set methods
    void    set_SFwMedium(double d)     { SFwMedium = d; }
    void    set_SFwMediumLH(double d)	{ SFwMediumLH = d; }
    void    set_SFwTight(double d)      { SFwTight = d; }
    void    set_SFwTightLH(double d)    { SFwTightLH = d; }
    void    set_isLooseLH(bool b)       { isLooseLH = b; }
    void    set_isMediumLH(bool b)      { isMediumLH = b; }
    void    set_isTightLH(bool b)       { isTightLH = b; }
    void    set_isLoose(bool b)         { isLoose = b; }
    void    set_isMedium(bool b)        { isMedium = b; }
    void    set_isTight(bool b)         { isTight = b; }
    void    set_etaclus(double d)	{ etaclus = d; }
    void    set_nBLayerHits(int i)	{ nBLayerHits = i; }
    void    set_expectBLayerHit(int i)	{ expectBLayerHit = i; }
    void    set_bkgMotherPdgId(int i)	{ bkgMotherPdgId = i; }
    void    set_bkgOrigin(int i)	{ bkgOrigin = i; }
};

class Muon : public Lepton {
    // ntuple variables
    double  SFw;
    bool    isBad;
    bool    isCosmic;

public:
    Muon() : SFw(0), isBad(0), isCosmic(0) {}
    ~Muon() {}
    // get methods
    double  get_SFw()	    { return SFw; }
    bool    get_isBad()	    { return isBad; }
    bool    get_isCosmic()  { return isCosmic; }
    // set methods
    void    set_SFw(double d)	 { SFw = d; }
    void    set_isBad(bool b)	 { isBad = b; }
    void    set_isCosmic(bool b) { isCosmic = b; }
};

#endif
