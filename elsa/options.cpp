#include "options.h"

Options::Options(std::string name, double cost)
   :_name{name}, _cost{cost}{}
Options::~Options(){}
double Options::cost(){

}
std::string Options::to_string(){

}
std::ostream& operator<<(std::ostream& ost, const Options& option){

   return ost;
}
