#ifndef __PAYOFF_DOUBLE_DIGITAL_H
#define __PAYOFF_DOUBLE_DIGITAL_H

#include "PayOff.h"

class PayOffDoubleDigital : public PayOff {
private: 
    double U_; // Upper strike price
    double D_; // Lower strike price

public:
    PayOffDoubleDigital(const double U, const double D): U_(U), D_(D) {};
    virtual ~PayOffDoubleDigital() {};

    virtual double operator() (const double S) const override;
};

#endif