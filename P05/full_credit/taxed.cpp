#include "taxed.h"

Taxed::Taxed(std::string name, double cost):Product::Product(name, cost){}
double Taxed::_tax = 0.0825;
Taxed::~Taxed(){}
void Taxed::set_tax_rate(double sales_tax){
  Taxed::_tax = sales_tax;
}
double Taxed::price() const{
  return _quantity*_cost*(1+_tax);
}
std::ostream& operator<<(std::ostream& ost, const Taxed &taxed){
  ost<< static_cast<Product>(taxed);
  return ost;
}
