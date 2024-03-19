#include <iostream>
#include <readParameters.hpp>
#include <GetPot>
#include <muparser_fun.hpp>
#include <GradientMethod.hpp>
//! a helper function. Prints a help message
void
printHelp()
{
  std::cout
    << "USAGE: main [-h] -f parameterFile (default: data.json)"
    << std::endl;
  std::cout << "-h this help" << std::endl;
  
}
int main(int argc, char** argv)
{
    GetPot command_line(argc, argv);
    if (command_line.search(2, "-h", "--help"))
    {
        printHelp();
        return 0;
    }
  

    std::string filename = command_line.follow("../data/data_example.json",2, "-f", "--file");
    parameters param;
    param= readParameters(filename);

    std::string funString;
    funString=param.fun;
    MuparserFun fun("x1+x2");
    std::vector<MuparserFun> dfun;
    dfun.reserve(param.dim);
    for (auto i=0; i<param.dim; ++i){
      dfun.emplace_back(param.dfun[i]);
    }
    

    std::cout<<"valus is=" <<fun(2,1)<<std::endl;
    std::cout<<"valus is=" <<dfun[0](2,1)<<std::endl;
    std::cout<<"valus is=" <<dfun[1](2,1)<<std::endl;

    auto function=[&fun](double x1,double x2){return fun(x1,x2);};
    GradientMethod solver(function, dfun, param.MaxIter, 
                  param.eps_s, param.eps_r);
    //solver.solve(param.starting_point, param.alpha_0, param.mu);
    
    //std::cout<<solver.Get_Result()[0]<<std::endl;
    //std::cout<<solver.Get_Result()[1]<<std::endl;
   // std::cout<<solver.Get_Iter();
    return 0;


}