#pragma once
#include <cmath>

double sigd0_fixed(double lepton_d0,double lepton_sigd0,double lepton_phi,double BSWx, double BSWy, double BSWxy)
{
    const double sin_phi = sin(lepton_phi);
    const double cos_phi = cos(lepton_phi);
    const double d0_uncert2 = sin_phi*(sin_phi*BSWx*BSWx - cos_phi*BSWxy)
        + cos_phi*(cos_phi*BSWy*BSWy - sin_phi*BSWxy);
    return fabs(lepton_d0)/sqrt(d0_uncert2 + pow(lepton_d0/lepton_sigd0,2));
}

double sigd0_fixed_data(int runNumber,double lepton_d0,double lepton_sigd0,double lepton_phi)
{
    double BSWx, BSWy, BSWxy;
    switch(runNumber)
    {
        case 266904:
            BSWx = 0.0160142; BSWy = 0.0151017; BSWxy = -3.11808e-06; break; // BSWz = 42.4603;
        case 266919:
            BSWx = 0.0126416; BSWy = 0.0129553; BSWxy = -1.54226e-05; break; // BSWz = 44.8705;
        case 267073:  	
            BSWx = 0.0126798; BSWy = 0.0123966; BSWxy = -8.02791e-06; break; // BSWz = 42.9207;
        case 267152:
            BSWx = 0.0137358; BSWy = 0.0151954; BSWxy = -1.63432e-05; break; // BSWz = 43.2129
        case 267162:     
            BSWx = 0.0155468; BSWy = 0.016172; BSWxy = 9.77371e-06; break; // BSWz = 41.5601;
        case 267167:
            BSWx = 0.0147207; BSWy = 0.0172065; BSWxy = -1.16307e-05; break; // BSWz = 44.863;
        case 267638:
            BSWx = 0.0125596; BSWy = 0.0123676; BSWxy = -2.32873e-05; break; // BSWz = 40.5317;
        case 267639:
            BSWx = 0.0140376; BSWy = 0.015743; BSWxy = -7.89887e-06; break; // BSWz = 41.31
        default:
        throw;
    }
    // note that the values above are retrieved for a random LB, and evolve during the run, so this is only an approximation
    return sigd0_fixed(lepton_d0,lepton_sigd0,lepton_phi,BSWx,BSWy,BSWxy);
}

double sigd0_fixed_mc(int rtag,double lepton_d0,double lepton_sigd0,double lepton_phi)
{
    double BSWx, BSWy, BSWxy;
    switch(rtag)
    {
        case 5787: // DC14
            BSWx = 0.0079; BSWy = 0.0079; BSWxy = 9.3e-08; break; // BSWz = 43;
        case 6630: case 6633: // MC15 50ns or first week (no trains)
            BSWx = 0.014; BSWy = 0.014; BSWxy = 0.; break; // BSWz = 53;
        default:
        throw;
    }
    return sigd0_fixed(lepton_d0,lepton_sigd0,lepton_phi,BSWx,BSWy,BSWxy);
}
