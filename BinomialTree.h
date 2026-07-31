#ifndef BINOMIALTREE_H
#define BINOMIALTREE_H

class BinomialTree
{
public:

    static double Call(
        double S,
        double K,
        double T,
        double r,
        double sigma,
        int steps);
};

#endif
