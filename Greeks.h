#ifndef GREEKS_H
#define GREEKS_H

class Greeks
{
public:

    static double Delta(
        double S,
        double K,
        double T,
        double r,
        double sigma);

    static double Gamma(
        double S,
        double K,
        double T,
        double r,
        double sigma);

    static double Vega(
        double S,
        double K,
        double T,
        double r,
        double sigma);

    static double Theta(
        double S,
        double K,
        double T,
        double r,
        double sigma);

    static double Rho(
        double S,
        double K,
        double T,
        double r,
        double sigma);
};

#endif
