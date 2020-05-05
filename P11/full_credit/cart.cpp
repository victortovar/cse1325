#include "cart.h"


Cart::Cart(std::string customer):
  _customer{customer}{}
Cart::~Cart(){
//  for(auto item: _items) delete *item;
}

Cart::Cart(const Cart& cart){
  _customer = cart._customer;
  for(iterator i = items.begin();i!=items.end(); ++i){
    *i = new Item(**i);
}
}

Cart& Cart::operator=(const Cart& cart){
  if(this==&cart) return *this;
  for(iterator i = items.begin();i!=items.end(); ++i){
    *i = new Item(**i);
}
  return *this;
}
void Cart::add_item(Item& item){
//  item = new Item(_name, _price);
  items.push_back(&item);
}
double Cart::cost(){
  double total = 0.0;
  for(auto i: items) total = total + i->cost();
  return total;
}

