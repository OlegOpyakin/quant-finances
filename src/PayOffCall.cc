#ifndef __PAYOFF_CALL_CC
#define __PAYOFF_CALL_CC

#include "PayOffCall.h"

double PayOffCall::operator() (const double S) const {
    return std::max(S - K_, 0.0);
}

#endif