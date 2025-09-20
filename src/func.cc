#ifndef __FUNC_CC
#define __FUNC_CC

#include "func.h"

double normalCDF(double value) // Cumulative Normal Distribution Function
{
   return 0.5 * erfc(-value * M_SQRT1_2);
}

#endif