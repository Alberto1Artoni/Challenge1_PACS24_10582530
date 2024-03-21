#ifndef HH_PARAMETERS_HH
#define HH_PARAMETERS_HH

#include <vector>
#include <array>
#include<string>
#include <iosfwd>
//define the structure that containt the input
struct parameters
{
    // Starting point
    std::vector<double> starting_point{0.0,0.0};
    // Maximum number of iterations
    unsigned int MaxIter{1000};
    // Tolerance to control the step lenght
    double eps_s{1e-6};
    // Tolerance to control the residual
    double eps_r{1e-6};
    // Initial step
    double alpha_0{1};
    // Mu (for Exponential and Inverse Decay strategies)
    double mu{0.2};
    // Sigma for Armyo rule
    double sigma{0.5};
    // Strategy for searching alpha
    std::string strategy{"ARMIJO"};
};
//! Prints parameters
std::ostream &operator<<(std::ostream &, const parameters &);
#endif






