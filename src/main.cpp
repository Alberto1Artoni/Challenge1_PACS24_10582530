#include <iostream>
#include "readParameters.hpp"
#include <GetPot>
#include "GradientMethod.hpp"
#include <fstream>
#include <functional>
//Here the user can define the function and its derivatives
//Whichever scalar function of two variables x1 and x2 is fine
//definition of the function
double fun(double x1, double x2)
{
  //return x1*x1+x2*x2;
  return x1*x2+4*std::pow(x1,4)+  std::pow(x2,2)+ 3*x1;
}
//definition of the derivatives
double dfun1(double x1, double x2)
{
  //return 2*x1;
  return x2 + 16*std::pow(x1,3) + 3;
}
double dfun2(double x1, double x2)
{
  //return 2*x2;
  return x1 + 2*x2;
}

//! a helper function. Prints a help message
void printHelp()
{
  std::cout
    << "USAGE: main [-h] -f parameterFile (default: data_example.json)"
    << std::endl;
  std::cout << "-h this help" << std::endl;
  
}

int main(int argc, char** argv)
{

  //Use GetPot to call the help
  GetPot command_line(argc, argv);
  if (command_line.search(2, "-h", "--help"))
  {
    printHelp();
    return 0;
  }
  
  //Use GetPot to call a Default file or the file the user wants
  std::string filename = command_line.follow("../data/data_example.json",2, "-f", "--file");
  parameters param;
  //Read the File
  param= readParameters(filename);
  
  //fun and fun can be chosen by the user, but then compilation is required
  std::function<double(double, double)> FUN=fun;
  std::vector<std::function<double(double, double)>> DFUN;
  DFUN.emplace_back(dfun1);
  DFUN.emplace_back(dfun2);
  //Define a solver of type GradientMethod
  GradientMethod solver(FUN, DFUN, param.MaxIter, param.eps_r, param.eps_s);
  // Check which strategy to find alpha to apply and then solve
  if (param.strategy=="EXPONENTIAL")
  {
    solver.SolveExponential(param.starting_point, param.alpha_0, param.mu);
  }
  else if (param.strategy=="INVERSE")
  {
    solver.SolveInverse(param.starting_point, param.alpha_0, param.mu);
  }
  else
  {
    solver.SolveArmijo(param.starting_point, param.alpha_0, param.sigma);
  }
   
  //Print the Results
  std::cout<<"Solution found is: "<<std::endl;
  std::cout<<"x1 = "<<solver.Get_Result()[0]<<std::endl;
  std::cout<<"x2 = "<<solver.Get_Result()[1]<<std::endl;
  std::cout<<"Number of iterations= "<<solver.Get_Iter();
  std::cout<<" Residue= "<<solver.Get_Residual()<<std::endl;
  return 0;


}