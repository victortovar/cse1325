#include "options.h"

Options::Options(std::string name, double cost)
   :_name{name}, _cost{cost}{}
Options::~Options(){}
double Options::cost(){
   return _cost;
}
std::string Options::to_string() const{
   return _name + " ($" + std::to_string(_cost) + ")";
}
std::ostream& operator<<(std::ostream& ost, const Options& option){
   ost << option._name << " ($" << option._cost << ")";
   return ost;
}

void Options::save(std::ostream& ost) {
   ost << _name << '\n' << _cost << '\n';
}

Options::Options(std::istream& ist) {
   std::getline(ist, _name);
   ist >> _cost; ist.ignore(32767, '\n');
}
