#include "taxfree.h"

Taxfree::Taxfree(std::string name, double cost):Product::Product{name, cost}{}
Taxfree::~Taxfree(){}
double Taxfree::price() const{
  return (double)_quantity*_cost;
}
std::ostream& operator<<(std::ostream& ost, const Taxfree &taxfree){
  ost<< static_cast<Product>(taxfree);
  return ost;
}
