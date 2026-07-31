#include <cmath>
#include "Utils.h"

double normalCDF(double x)
{
    return 0.5 * erfc(-x / std::sqrt(2.0));
}
