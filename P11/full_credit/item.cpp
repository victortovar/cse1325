#include "item.h"
#include <iomanip>

Item::Item(std::string name, double price):
  _name{name}, _price{price}{}
double Item::cost(){
  return _price;
}
std::ostream& operator<<(std::ostream& ost, const Item& item){
  std::cout<<"$ "<<std::setprecision(2)<<item._price<<" "<<item._name<<std::endl;
  return ost;
}
std::istream& operator>>(std::istream& ist, Item& item){
  std::string s, name; double price;
  ist >> s;
  std::size_t last = s.find_last_of(' ', s.size()-1);
  name = s.substr(0, last);
  item._name = name;
  try{
    price = stod(s.substr(last+1));// throw std::runtime_error{"Bad price"};
  //  else item._price = price;
}catch(std::runtime_error e){std::cerr << "Bad Price: " << e.what() << std::endl;}
  ist.ignore(32767, '\n');
  return ist;
}

