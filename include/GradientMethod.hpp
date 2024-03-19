#ifndef HH_GRADIENTMETHOD_HH
#define HH_GRADIENTMETHOD_HH
#include <functional>
//#include <muparser_fun.hpp>
#include <cmath>
#include <iostream>
class GradientMethod
{
    private:
    // function
    std::function<double( double,  double)> m_fun;
    //derivative of the function
    std::vector<std::function<double(const double&, const double&)>> m_dfun;
    //Maximum number of iterarion
    const unsigned int m_n_max_it;
    //tolerence in the step lenght
    const double m_eps_s;
    //tolerance on the residual
    const double m_eps_r;
    // Minimum (solution)
    std::vector<double> m_x;
    //Initial step for the descent
    double m_alpha;
    // Mu
    double m_mu;
    //number of iterations
    unsigned int m_iter;
    //residual
    double m_res;

    public:
    //Constructor
    GradientMethod(std::function<double(double,  double)> &fun_,
                   std::vector<std::function<double(const double&, const double&)>> &dfun_,
                   const unsigned int      n_max_it,
                   const double            eps_s,
                   const double            eps_r);

        
    // Method to call the solver (the gradient method)
    void solve(const std::vector<double> &x0, double &alpha0, double &mu);
    //Method to access the result 
    std::vector<double>  Get_Result() const;
    //Method to access the residual
    double Get_Residual() const;
    //Method to access the number of iterations
    unsigned int Get_Iter() const;

    
};
#endif