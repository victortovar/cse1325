#include "product.h"
#include<string>
#include<iostream>

Product::Product(std::string name, double cost)
   :_name{name}, _cost{cost}, _quantity{0}{if(_cost<0)throw std::runtime_error("Invalid cost");}
Product::~Product(){}
void Product::set_quantity(int quantity){
  Product::_quantity = quantity;
}
double Product::price() const{}
std::ostream& operator<<(std::ostream& ost, const Product& product){
  if(product._quantity==0) std::cout<<product._name<<"("<<product._cost<<")"<<std::endl;
  else std::cout << product._name << "(" << product._quantity <<" @ " << product._cost
       << ")" << std::endl;
}

