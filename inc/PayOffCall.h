#ifndef __PAYOFF_CALL_H
#define __PAYOFF_CALL_H

#include "PayOff.h"

class PayOffCall : public PayOff {
private: 
    double K_; // Strike price

public:
    PayOffCall(const double K): K_(K) {};
    virtual ~PayOffCall() {};

    virtual double operator() (const double S) const override;
};

#endif