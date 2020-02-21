#include "product.h"
#include<string>
#include<iostream>

Product::Product(std::string name, double cost)
   :_name{name}, _cost{cost}{}
std::ostream& operator<<(std::ostream& ost, const Product& product){
   
}

