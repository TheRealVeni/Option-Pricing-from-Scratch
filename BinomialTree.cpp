#include <cmath>
#include <vector>
#include <algorithm>
#include "BinomialTree.h"

double BinomialTree::Call(
    double S,
    double K,
    double T,
    double r,
    double sigma,
    int N)
{
    double dt=T/N;

    double u=std::exp(sigma*std::sqrt(dt));
    double d=1.0/u;

    double p=
        (std::exp(r*dt)-d)/(u-d);

    std::vector<double> option(N+1);

    for(int i=0;i<=N;i++)
    {
        double ST=
            S*std::pow(u,i)
             *std::pow(d,N-i);

        option[i]=std::max(ST-K,0.0);
    }

    for(int step=N-1;step>=0;step--)
    {
        for(int i=0;i<=step;i++)
        {
            option[i]=
                std::exp(-r*dt)
                *(
                    p*option[i+1]
                    +(1-p)*option[i]
                );
        }
    }

    return option[0];
}
