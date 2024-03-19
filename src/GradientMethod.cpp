#include "GradientMethod.hpp"


GradientMethod::GradientMethod(std::function<double( double,  double)> &fun_,
                   std::vector<std::function<double(const double&, const double&)>> &dfun_,
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
            m_iter(),
            m_res()
{}
void GradientMethod::solve(const std::vector<double> &x0, double &alpha0, double &mu)    
{ 
    //initial guess
    m_x= x0;
    m_alpha=alpha0;
    m_mu=mu;
    // definisco una lambda function per calcolare la norma di un vettore
    auto norm = [](const std::vector<double> &vec){ 
    double sum{0};
    for (auto i=vec.begin(); i!=vec.end(); ++i){
        sum +=std::pow(*i,2);
        }
        return std::sqrt(sum);
    };
    m_iter=0;
    std::vector<double> step_lenght(m_x.size(), 0.0);
    std::vector<double> m_xold;
    do
    {   
        m_xold=m_x;
        std::cout<<m_xold[0]<<m_xold[1]<<std::endl;
        //m_alpha=alpha0/(1 + m_mu*m_iter); 
        m_alpha=alpha0*std::exp(-m_mu*m_iter);
        for (size_t i=0; i<m_x.size(); ++i){   
        m_x[i] = m_xold[i] - m_alpha* m_dfun[i](m_xold[0], m_xold[1]);
        step_lenght[i]=- m_alpha* m_dfun[i](m_xold[0], m_xold[1]);
        std::cout<<m_x[i]<<std::endl;
        }
                
        m_iter++;
        std::cout<<"alpha "<<m_alpha<<std::endl;
        } while (norm(step_lenght)>m_eps_s  && m_iter<m_n_max_it && std::abs( m_fun(m_xold[0],m_xold[1])-m_fun(m_x[0],m_x[1])) >m_eps_r);//manca un criterio di stop
            
}

std::vector<double> GradientMethod::Get_Result() const
{
    return m_x;
}
double GradientMethod::Get_Residual() const
{
    return m_res;
}
unsigned int GradientMethod::Get_Iter() const
{
    return m_iter;   
}