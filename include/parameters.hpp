#ifndef HH_PARAMETERS_HH
#define HH_PARAMETERS_HH

#include <vector>
#include <array>
#include<string>
#include <iosfwd>
//define the structure that containt the input
struct parameters
{
    //*******************************************************//
    //voglio rendere la dimensione del problema un parametro?//                                                        
    //*******************************************************//
    //dimensionality of the problem
    int dim{2};
    // function
    std::string fun="x1x2 + 4x1^4 + x2^2 + 3x1";
    //derivative
    std::array<std::string,2> dfun{"x2 +12x1^3 +x2^2 +3", "x1 + 4x1^4 + 2x2 + 3x1"};
    // Starting point
    std::vector<double> starting_point{0.0,0.0};
    // Maximum number of iterations
    int MaxIter{1000};
    // Tolerance to control the step lenght
    double eps_s{1e-6};
    // Tolerance to control the residual
    double eps_r{1e-6};
    // Initial step
    double alpha_0{1};
    // Mu (for Exponential and Inverse Decay strategies)
    double mu{0.2};
};
//! Prints parameters
std::ostream &operator<<(std::ostream &, const parameters &);
#endif






