#include <parameters.hpp>
#include <iostream>
std::ostream &
operator<<(std::ostream &out, const parameters &p)
{
  out << "PARAMETER VALUES:"
      << "\n";
  out << "starting point=("<<p.starting_point[0]<< ", " <<p.starting_point[1]<<")\n"; 
  out << "epsilon_s= " << p.eps_s << "\n";
  out << "epsilon_r= " << p.eps_r << "\n";
  out << "Strategy= "<<p.strategy<<"\n";
  out << "itermax= " << p.MaxIter << "\n";
  out << "alpha_0= " << p.alpha_0 << "\n";
  out << "mu= " << p.mu << "\n";
  out << "sigma= "<< p.sigma<<"\n";
 
  return out;
}
