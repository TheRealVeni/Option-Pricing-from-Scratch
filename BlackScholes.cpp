#include <cmath>
#include "BlackScholes.h"
#include "Utils.h"

double BlackScholes::Call(
    double S,
    double K,
    double T,
    double r,
    double sigma)
{
    double d1 =
        (std::log(S/K)+(r+0.5*sigma*sigma)*T)/
        (sigma*std::sqrt(T));

    double d2 =
        d1-sigma*std::sqrt(T);

    return
        S*normalCDF(d1)
        -K*std::exp(-r*T)*normalCDF(d2);
}

double BlackScholes::Put(
    double S,
    double K,
    double T,
    double r,
    double sigma)
{
    double d1 =
        (std::log(S/K)+(r+0.5*sigma*sigma)*T)/
        (sigma*std::sqrt(T));

    double d2 =
        d1-sigma*std::sqrt(T);

    return
        K*std::exp(-r*T)*normalCDF(-d2)
        -S*normalCDF(-d1);
}
