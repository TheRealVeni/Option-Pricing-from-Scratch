#include <iostream>
#include <chrono>

#include "BlackScholes.h"
#include "BinomialTree.h"
#include "MonteCarlo.h"
#include "Greeks.h"

int main()
{
    double S=100;
    double K=100;
    double T=1;
    double r=0.05;
    double sigma=0.2;

    auto start=
        std::chrono::high_resolution_clock::now();

    double bs=
        BlackScholes::Call(
            S,K,T,r,sigma);

    auto end=
        std::chrono::high_resolution_clock::now();

    std::cout<<"Black-Scholes: "
             <<bs<<"\n";

    std::cout<<"Runtime "
             <<std::chrono::duration<double,std::micro>(end-start).count()
             <<" us\n\n";

    std::cout<<"Binomial Tree Convergence\n";

    for(int n : {10,25,50,100,250,500,1000})
    {
        double price=
            BinomialTree::Call(
                S,K,T,r,sigma,n);

        std::cout
            <<n
            <<" steps -> "
            <<price
            <<" Error "
            <<std::abs(price-bs)
            <<"\n";
    }

    std::cout<<"\nMonte Carlo Convergence\n";

    for(int sims : {100,1000,5000,10000,50000,100000,500000})
    {
        double price=
            MonteCarlo::Call(
                S,K,T,r,sigma,sims);

        std::cout
            <<sims
            <<" simulations -> "
            <<price
            <<" Error "
            <<std::abs(price-bs)
            <<"\n";
    }

    std::cout<<"\nGreeks\n";

    std::cout<<"Delta : "<<Greeks::Delta(S,K,T,r,sigma)<<"\n";
    std::cout<<"Gamma : "<<Greeks::Gamma(S,K,T,r,sigma)<<"\n";
    std::cout<<"Vega  : "<<Greeks::Vega(S,K,T,r,sigma)<<"\n";
    std::cout<<"Theta : "<<Greeks::Theta(S,K,T,r,sigma)<<"\n";
    std::cout<<"Rho   : "<<Greeks::Rho(S,K,T,r,sigma)<<"\n";

    return 0;
}
