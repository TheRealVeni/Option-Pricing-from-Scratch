#include <cmath>
#include <random>
#include <algorithm>
#include "MonteCarlo.h"

double MonteCarlo::Call(
    double S,
    double K,
    double T,
    double r,
    double sigma,
    int simulations)
{
    std::mt19937 gen(42);

    std::normal_distribution<>
        dist(0.0,1.0);

    double sum=0;

    for(int i=0;i<simulations;i++)
    {
        double Z=dist(gen);

        double ST=
            S*
            std::exp(
                (r-0.5*sigma*sigma)*T
                +sigma*std::sqrt(T)*Z
            );

        sum+=std::max(ST-K,0.0);
    }

    return
        std::exp(-r*T)
        *sum/simulations;
}
