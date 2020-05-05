#ifndef __cart_h
#define __cart_h
#include "item.h"
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

class Cart{
  private:
    std::string _customer;
    typedef std::vector<Item *> _items;
    _items items;
  public:
    Cart(std::string customer);
    ~Cart();
    Cart(const Cart& cart);
    Cart& operator=(const Cart& cart);
    void add_item(Item& item);
    double cost();
    typedef _items::iterator iterator;
    typedef _items::const_iterator const_iterator;
    iterator begin(){return items.begin();}
    iterator end(){return items.end();}
    

};

#endif
