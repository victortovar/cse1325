#ifndef __taxfree_h
#define __taxfree_h
#include "product.h"
#include<iostream>
#include<string>

class Taxfree: public Product{
  public:
    Taxfree(std::string name, double cost);
    virtual ~Taxfree();
    double price() const override;
};

#endif
