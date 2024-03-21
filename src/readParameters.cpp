#include <readParameters.hpp>
#include <json.hpp>
#include <fstream>
#include <iostream>
parameters readParameters(std::string const &filename)
{
    // Parameter default constructor fills it with the defaults values
    parameters defaults;
    // checks if file exixts and is readable
    std::ifstream check(filename);
    if(!check)
    {
        std::cerr << "ERROR: Parameter file " << filename << " does not exist"
                << std::endl;
        std::cerr << "Reverting to default values." << std::endl;
        std::cout << defaults;
        check.close();
        return defaults;
    }
    else
    {
        check.close();
    }
    
    std::ifstream jfile(filename);
    using json = nlohmann::json;
    json data = json::parse(jfile);
    parameters values;
    // Read parameters from json file
    values.starting_point=data["starting_coor"].value("x_0", defaults.starting_point);
    values.eps_s = data["tolerances"].value("eps_s", defaults.eps_s);
    values.eps_r = data["tolerances"].value("eps_r", defaults.eps_r);
    values.strategy=data["method"].value("Strategy", defaults.strategy);
    values.MaxIter = data["method"].value("MaxIter", defaults.MaxIter);
    values.alpha_0 = data["method"].value("alpha_0", defaults.alpha_0);
    values.mu = data["method"].value("mu", defaults.mu);
    values.sigma = data["method"].value("sigma", defaults.sigma);

    //Print out the read data and the actual values stored to check
    std::cout << "PARAMETER VALUES IN JSON FILE"
                << "\n";
    std::cout<<std::setw(4)<<data;
    std::cout << std::endl;
    std::cout << "ACTUAL VALUES"
                << "\n"
                << values;

  return values;
}
