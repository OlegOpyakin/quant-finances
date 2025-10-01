#ifndef __PAYOFF_DOUBLE_DIGITAL_CC
#define __PAYOFF_DOUBLE_DIGITAL_CC

#include "PayOffDoubleDigital.h"

double PayOffDoubleDigital::operator() (const double S) const {
    if(S >= D_ && S <= U_) {
        return 1.0;
    }
    else {
        return 0.0;
    }
}

#endif