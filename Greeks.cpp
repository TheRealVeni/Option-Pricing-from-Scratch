#include "Greeks.h"
#include "BlackScholes.h"

double Greeks::Delta(
    double S,
    double K,
    double T,
    double r,
    double sigma)
{
    double h=0.01;

    return
    (
        BlackScholes::Call(
            S+h,K,T,r,sigma)
        -
        BlackScholes::Call(
            S-h,K,T,r,sigma)
    )/(2*h);
}

double Greeks::Gamma(
    double S,
    double K,
    double T,
    double r,
    double sigma)
{
    double h=0.01;

    return
    (
        BlackScholes::Call(
            S+h,K,T,r,sigma)
        -
        2*BlackScholes::Call(
            S,K,T,r,sigma)
        +
        BlackScholes::Call(
            S-h,K,T,r,sigma)
    )/(h*h);
}

double Greeks::Vega(
    double S,
    double K,
    double T,
    double r,
    double sigma)
{
    double h=0.001;

    return
    (
        BlackScholes::Call(
            S,K,T,r,sigma+h)
        -
        BlackScholes::Call(
            S,K,T,r,sigma-h)
    )/(2*h);
}

double Greeks::Theta(
    double S,
    double K,
    double T,
    double r,
    double sigma)
{
    double h=1.0/365.0;

    return
    (
        BlackScholes::Call(
            S,K,T-h,r,sigma)
        -
        BlackScholes::Call(
            S,K,T+h,r,sigma)
    )/(2*h);
}

double Greeks::Rho(
    double S,
    double K,
    double T,
    double r,
    double sigma)
{
    double h=0.0001;

    return
    (
        BlackScholes::Call(
            S,K,T,r+h,sigma)
        -
        BlackScholes::Call(
            S,K,T,r-h,sigma)
    )/(2*h);
}
