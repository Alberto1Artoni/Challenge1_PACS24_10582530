#include <parameters.hpp>
#include <iostream>
std::ostream &
operator<<(std::ostream &out, const parameters &p)
{
  out << "PARAMETER VALUES:"
      << "\n";
  out << "Dimension= "<< p.dim << "\n";
  out << "Function= "<< p.fun<<"\n";
  out << "Derivative= [ " << p.dfun[0]<<", "<< p.dfun[1]<<" ]\n";
  out << "starting point=("<<p.starting_point[0]<< ", " <<p.starting_point[1]<<")\n";  
  out << "itermax= " << p.MaxIter << "\n";
  out << "epsilon_s= " << p.eps_s << "\n";
  out << "epsilon_r= " << p.eps_r << "\n";
  out << "alpha_0= " << p.alpha_0 << "\n";

  return out;
}
