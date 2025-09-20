#ifndef __VANILLA_OPTION_H
#define __VANILLA_OPTION_H

#include "func.h"

class VanillaOption {
private:
    double K_;      // Strike price
    double r_;      // Risk-free rate
    double T_;      // Maturity time
    double S_;      // Underlying asset price
    double sigma_;  // Volatility of underlying asset

    void init_();
    void copy_(const VanillaOption& rhs);

    double normalCDF(double val) const;

public:
    VanillaOption(); // Default
    VanillaOption(const double& K, const double& r,
                  const double& T, const double& S,
                  const double& sigma);
    VanillaOption(const VanillaOption& rhs);
    VanillaOption& operator=(const VanillaOption& rhs);

    virtual ~VanillaOption();

    double get_K() const;
    double get_r() const;
    double get_T() const;
    double get_S() const;
    double get_sigma() const;

    // Option price calculation methods
    double calc_call_price() const;
    double calc_put_price() const;
};

#endif