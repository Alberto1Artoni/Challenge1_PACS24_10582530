#include <iostream>
#include <readParameters.hpp>
#include <GetPot>
#include <muparser_fun.hpp>
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

    MuparserFun fun(param.fun);
    MuparserFun dfun1(param.dfun[0]);
    MuparserFun dfun2(param.dfun[1]);

    std::cout<<"valus is=" <<fun(2,1)<<std::endl;
    std::cout<<"valus is=" <<dfun1(2,1)<<std::endl;
    std::cout<<"valus is=" <<dfun2(2,1)<<std::endl;
    return 0;


}