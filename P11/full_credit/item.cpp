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
  
  return ist;
}

