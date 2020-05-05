#include "item.h"
#include <iomanip>

Item::Item(std::string name, double price):
  _name{name}, _price{price}{}
double Item::cost(){
  return _price;
}
std::ostream& operator<<(std::ostream& ost, const Item& item){
  std::cout<<"$ "<<std::setprecision(2)<<item._price;
  return ost;
}
std::istream& operator>>(std::istream& ist, Item& item){
  std::string s, name; double price;
  ist >> s;
  std::size_t last = s.find_last_of('\n', s.size()-1);
  name = s.substr(0, last);
  price = stod(s.substr(last+1));
  return ist;
}

