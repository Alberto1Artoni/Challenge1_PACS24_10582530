#ifndef HH_GRADIENTMETHOD_HH
#define HH_GRADIENTMETHOD_HH
#include <functional>
#include <cmath>
#include <iostream>
// Pure Declaration of the GradientMethodClass
// The class has one constructor to initilize some parameters:
//  1. The function and its derivative;
//  2. Maximum number of iteration
//  3. Tolerances
//Other parameters are called accordingly to the different methods
class GradientMethod
{
    private:
    // function
     std::function<double(double,double)> m_fun;
    //derivative of the function
     std::vector<std::function<double(double, double)>> m_dfun;
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
    //sigma
    double m_sigma;
    //number of iterations
    unsigned int m_iter;
    //residual
    double m_res;

    public:
    //Constructor
    GradientMethod( std::function<double(double,double)> &fun_,
                 std::vector<std::function<double(double, double)>> &dfun_,
                const unsigned int      n_max_it,
                   const double            eps_s,
                   const double            eps_r);
        
    // Methods to call the solver (the gradient method)
    //This method applies the gradient method applying the exponential decay to find alpha
    void SolveExponential(const std::vector<double> &x0, double &alpha0, double &mu);
    //This method applies the gradient method applying the inverse decay to find alpha
    void SolveInverse(const std::vector<double> &x0, double &alpha0, double &mu);
    //This method applies the gradient method applying the Armijo Rule to find alpha
    void SolveArmijo(const std::vector<double> &x0, double &alpha0, double &sigma);
    //Method to access the result 
    std::vector<double>  Get_Result() const;
    //Method to access the residual
    double Get_Residual() const;
    //Method to access the number of iterations
    unsigned int Get_Iter() const;

    
};
#endif