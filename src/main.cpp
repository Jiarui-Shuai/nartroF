#include <iostream>
#include <sstream>
#include <unordered_map>
#include <cstdlib>
#define elif else if
int main(int argc, char** argv){
    if (argc <= 1) {
        // Interpreter
        std::cout << "Welcome to nartroF Interpreter\n";
        std::cout << "Compile time: [" << __DATE__ << " " << __TIME__ << "]\n";
        std::unordered_map<std::string, double> real_list;
        while (1) {
            std::string cmd;
            std::cout << '>';
            std::getline(std::cin, cmd);
            std::istringstream iss(cmd);
            std::string c;
            iss >> c;
            if (!c.compare("variable")) {
                std::string subcmd;
                iss >> subcmd;
                if (!subcmd.compare("create")) {
                    std::string  tp_name;
                    iss >> tp_name;
                    std::string var_name;
                    iss >> var_name;
                    if (!tp_name.compare("real")) {
                        double value = 0;
                        iss >> value;
                        real_list[var_name] = value;
                    } else {
                        std::cerr << "ERROR: unknow type: " << tp_name;
                    }
                } else if (!subcmd.compare("print")) {
                    std::string var_name;
                    iss >> var_name;
                    if (real_list.count(var_name)) {
                        std::cout << var_name << " 的值是 " << real_list[var_name];
                    } else {
                        std::cerr << "ERROR: variable " << var_name << " is not defined";
                    }
                } else if (!subcmd.compare("operation")) {
                    std::string  opt;
                    iss >> opt;
                    std::string  opt1;
                    iss >> opt1;
                    std::string  opt2;
                    iss >> opt2;
                    std::string  res;
                    iss >> res;
                    if (!opt.compare("add")) 
                        if (real_list.count(opt1)) 
                            if (real_list.count(opt2))
                                real_list[res] = real_list[opt1] + real_list[opt2];
                            else 
                                std::cerr << "ERROR: variable " << opt2 << " is not defined";
                        else 
                            std::cerr << "ERROR: variable " << opt1 << " is not defined";

                     else
                        std::cerr << "ERROR: operation " << opt << " is not defined";
                } else {
                    std::cerr << "ERROR: unknow subcmd: " << cmd << ' ' << subcmd;
                }
            }
            else if (!c.compare("print"))
                std::cout << "看啥看, 不会";
            else if (!c.compare("quit"))
                return 0;
            else
                std::cerr << "ERROR: Unknow command: " << c;
            
            std::cout << '\n';
        }
    } else {
        std::abort();
    }
    return 0;
}