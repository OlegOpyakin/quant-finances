#ifndef __PAYOFF_H
#define __PAYOFF_H

#include <algorithm>

class PayOff {
public:
    PayOff() {} // Default 
    virtual ~PayOff() {}

    virtual double operator() (const double S) const = 0;
};

#endif