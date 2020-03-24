#include "options.h"

Options::Options(std::string name, double cost)
   :_name{name}, _cost{cost}{}
Options::~Options(){}
double Options::cost(){
   return _cost;
}
std::string Options::to_string(){
   return _name;
}
std::ostream& operator<<(std::ostream& ost, const Options& option){
   std::cout << option._name << option._cost << std::endl;
   return ost;
}
