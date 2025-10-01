#ifndef __VANILLA_OPTION_CC
#define __VANILLA_OPTION_CC

#include "VanillaOption.h"

void VanillaOption::init_() {
    K_ = 100.0;
    r_ = 0.05;      // 5% interest rate
    T_ = 1.0;       // One year until maturity
    S_ = 100.0;     // Option is "at the money" as spot equals the strike
    sigma_ = 0.2;   // Volatility is 20%
}

void VanillaOption::copy_(const VanillaOption& rhs) {
    K_ = rhs.get_K();
    r_ = rhs.get_r();
    T_ = rhs.get_T();
    S_ = rhs.get_S();
    sigma_ = rhs.get_sigma();
}

VanillaOption::VanillaOption() { init_(); }

VanillaOption::VanillaOption(const double& K, const double& r,
                             const double& T, const double& S,
                             const double& sigma) {
    K_ = K;
    r_ = r;
    T_ = T;
    S_ = S;
    sigma_ = sigma;
}

VanillaOption::VanillaOption(const VanillaOption& rhs) {
    copy_(rhs);
}

VanillaOption& VanillaOption::operator=(const VanillaOption& rhs) {
    if(this == &rhs) return *this;
    copy_(rhs);
    return *this;
}

VanillaOption::~VanillaOption() {}

double VanillaOption::get_K() const { return K_; }

double VanillaOption::get_r() const { return r_; }

double VanillaOption::get_T() const { return T_; }

double VanillaOption::get_S() const { return S_; }

double VanillaOption::get_sigma() const { return sigma_; }

double VanillaOption::calc_call_price() const {
    double sigma_sqrt_T = sigma_ * sqrt( T_ );
    double d_1 = ( log( S_ / K_ ) + ( r_ + sigma_ * sigma_ * 0.5 ) * T_ ) / sigma_sqrt_T;
    double d_2 = d_1 - sigma_sqrt_T;
    return S_ * normalCDF( d_1 ) - K_ * exp( - r_ * T_ ) * normalCDF( d_2 );
}

double VanillaOption::calc_put_price() const {
    double sigma_sqrt_T = sigma_ * sqrt( T_ );
    double d_1 = ( log( S_ / K_ ) + ( r_ + sigma_ * sigma_ * 0.5 ) * T_ ) / sigma_sqrt_T;
    double d_2 = d_1 - sigma_sqrt_T;
    return K_ * exp( - r_ * T_ ) * normalCDF( d_2 ) - S_ * normalCDF( d_1 );
}

#endif