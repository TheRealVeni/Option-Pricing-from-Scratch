#ifndef BLACKSCHOLES_H
#define BLACKSCHOLES_H

//predefined characteristics which we will use in BlackScholes.cpp
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
