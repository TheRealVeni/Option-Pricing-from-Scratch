#ifndef BLACKSCHOLES_H
#define BLACKSCHOLES_H

class BlackScholes
{
public:

    static double Call(
        double S,
        double K,
        double T,
        double r,
        double sigma);

    static double Put(
        double S,
        double K,
        double T,
        double r,
        double sigma);
};

#endif
