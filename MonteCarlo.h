#ifndef MONTECARLO_H
#define MONTECARLO_H

class MonteCarlo
{
public:

    static double Call(
        double S,
        double K,
        double T,
        double r,
        double sigma,
        int simulations);
};

#endif
