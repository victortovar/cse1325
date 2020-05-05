#ifndef __item_h
#define __item_h
#include <string>
#include <iostream>
#include <iomanip>

class Item{
  private:
    std::string _name;
    double _price;
  public:
    Item(std::string name, double price);
    double cost();
    friend std::ostream& operator<<(std::ostream& ost, const Item& item);
    friend std::istream& operator>>(std::istream& ist, Item& item);
};

#endif
