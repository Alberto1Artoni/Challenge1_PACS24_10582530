#include "GradientMethod.hpp"
// Here the constructur and the methods are properly defined 
// accordingly their declarations

//norm function
double norm(const std::vector<double> &vec){ 
    double sum{0};
    for (auto i=vec.begin(); i!=vec.end(); ++i){
        sum +=std::pow(*i,2);
        }
        return std::sqrt(sum);
    };
// Constructor of the GradientMethod Class
GradientMethod::GradientMethod(std::function<double(double,double)> &fun_,
                                std::vector<std::function<double(double, double)>> &dfun_,
                                const unsigned int      n_max_it,
                   const double            eps_s,
                   const double            eps_r): 
            m_fun(fun_),
            m_dfun(dfun_),
            m_n_max_it(n_max_it),
            m_eps_s(eps_s),
            m_eps_r(eps_r),
            m_x(),
            m_alpha(),
            m_mu(),
            m_sigma(),
            m_iter(),
            m_res()
{}
//This method applies the gradient method applying the exponential decay to find alpha
void GradientMethod::SolveExponential(const std::vector<double> &x0, double &alpha0, double &mu)    
{ 
    //initial guess
    m_x= x0;
    //Initizialize class members
    m_alpha=alpha0;
    m_mu=mu;
    //initilize the counter of the number of iterations
    m_iter=0;
    //vector to be used in the stopping criteria
    std::vector<double> step_lenght(m_x.size(), 0.0);
    //ausiliary variable to store the solution of the previous iteration
    std::vector<double> m_xold;
    // Start the loop
    do
    {   
        m_xold=m_x;
        m_alpha=alpha0*std::exp(-m_mu*m_iter);
        for (size_t i=0; i<m_x.size(); ++i){   
        m_x[i] = m_xold[i] - m_alpha* m_dfun[i](m_xold[0], m_xold[1]);
        step_lenght[i]=- m_alpha* m_dfun[i](m_xold[0], m_xold[1]);
        }
                
        m_iter++;
        m_res= -m_fun(m_xold[0],m_xold[1])+m_fun(m_x[0],m_x[1]);
        } while (norm(step_lenght)>m_eps_s  && m_iter<m_n_max_it && std::abs(m_res) >m_eps_r);
            
}
//This method applies the gradient method applying the inverse decay to find alpha
void GradientMethod::SolveInverse(const std::vector<double> &x0, double &alpha0, double &mu)    
{ 
    //initial guess
    m_x= x0;
    //Initizialize class members
    m_alpha=alpha0;
    m_mu=mu;
    //initilize the counter of the number of iterations
    m_iter=0;
    //vector to be used in the stopping criteria
    std::vector<double> step_lenght(m_x.size(), 0.0);
    //ausiliary variable to store the solution of the previous iteration
    std::vector<double> m_xold;
    // Start the loop
    do
    {   
        m_xold=m_x;
        m_alpha=alpha0/(1 + m_mu*m_iter); 
        for (size_t i=0; i<m_x.size(); ++i){   
        m_x[i] = m_xold[i] - m_alpha* m_dfun[i](m_xold[0], m_xold[1]);
        step_lenght[i]=- m_alpha* m_dfun[i](m_xold[0], m_xold[1]);
        }   
        m_iter++;
        m_res= -m_fun(m_xold[0],m_xold[1])+m_fun(m_x[0],m_x[1]);
        } while (norm(step_lenght)>m_eps_s  && m_iter<m_n_max_it && std::abs(m_res) >m_eps_r);
            
}
//This method applies the gradient method applying the Armijo Rule to find alpha
void GradientMethod::SolveArmijo(const std::vector<double> &x0, double &alpha0, double &sigma)
{
    //initial guess
    m_x= x0;
    //Initizialize class members
    m_sigma=sigma;
    //initilize the counter of the number of iterations
    m_iter=0;
    //vector to be used in the stopping criteria
    std::vector<double> step_lenght(m_x.size(), 0.0);
    //ausiliary variable to store the solution of the previous iteration
    std::vector<double> m_xold;
    // Start the loop
    do
    {   
        m_xold=m_x;
        std::vector<double> grad;
        for(unsigned int i=0;i<m_n_max_it/10; ++i){
            grad.emplace_back(m_dfun[0](m_xold[0],m_xold[1]));
            grad.emplace_back(m_dfun[1](m_xold[0],m_xold[1]));
            if(m_fun(m_xold[0],m_xold[1])-m_fun(m_xold[0]-alpha0*grad[0],m_xold[1]-alpha0*grad[1])< m_sigma*alpha0*std::pow(norm(grad),2))
            {
                alpha0=alpha0/2;
            }
            else
                break;
        }
        m_alpha=alpha0; 
        for (size_t i=0; i<m_x.size(); ++i){   
        m_x[i] = m_xold[i] - m_alpha* m_dfun[i](m_xold[0], m_xold[1]);
        step_lenght[i]=- m_alpha* m_dfun[i](m_xold[0], m_xold[1]);
        }
                
        m_iter++;
        m_res= -m_fun(m_xold[0],m_xold[1])+m_fun(m_x[0],m_x[1]);
        } while (norm(step_lenght)>m_eps_s  && m_iter<m_n_max_it && std::abs( m_res)>m_eps_r);
        
}
//Method to access the result
std::vector<double> GradientMethod::Get_Result() const
{
    return m_x;
}
//Method to access the residual
double GradientMethod::Get_Residual() const
{
    return m_res;
}
//Method to access the residual
unsigned int GradientMethod::Get_Iter() const
{
    return m_iter;   
}