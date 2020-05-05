#ifndef __cart_h
#define __cart_h
#include "item.h"
#include <string>
#include <vector>

class Cart{
  private:
    std::string _customer;
    std::vector<Item *> _items;
  public:
    Cart(std::string customer);
    ~Cart();
    Cart(const Cart& cart);
    Cart& operator=(const Cart& cart);
    void add_item(Item& item);
    double cost();
  //  iterator begin();
    //iterator end();
    

};

#endif
