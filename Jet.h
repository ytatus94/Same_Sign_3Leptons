#ifndef JET_H
#define JET_H

#include "Particle.h"

class Jet : public Particle {
    bool    isBjet;
    double  quality;
    double  JVF;
    double  JVT;
    double  MV2c20;
    double  SFw;
    int	    nTrk;
    bool    cleaning;

public:
    Jet() : isBjet(0), quality(0), JVF(0), JVT(0), MV2c20(0), SFw(0), nTrk(0), cleaning(1) {}
    ~Jet() {}
    // get methods
    bool    get_isBjet()    { return isBjet; }
    double  get_quality()   { return quality; }
    double  get_JVF()	    { return JVF; }
    double  get_JVT()	    { return JVT; }
    double  get_MV2c20()    { return MV2c20; }
    double  get_SFw()	    { return SFw; }
    int	    get_nTrk()	    { return nTrk; }
    bool    get_cleaning()    { return cleaning; }
    // set methods
    void    set_isBjet(bool b)      { isBjet = b; }
    void    set_quality(double d)   { quality = d; }
    void    set_JVF(double d)	    { JVF = d; }
    void    set_JVT(double d)	    { JVT = d; }
    void    set_MV2c20(double d)    { MV2c20 = d; }
    void    set_SFw(double d)       { SFw = d; }
    void    set_nTrk(int i)         { nTrk = i; }
    void    set_cleaning(bool b)    { cleaning = b; }
};

#endif
