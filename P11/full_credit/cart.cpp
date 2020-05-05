#include "cart.h"


Cart::Cart(std::string customer):
  _customer{customer}{}
Cart::~Cart(){
  for(auto item: _items) delete item;
}

Cart::Cart(const Cart& cart) : _items(cart._items){
  _customer = cart._customer;
  std::vector<Item *>::iterator i = _items.begin(), end = _items.end();
  while(i != end){
    *i = new Item(**i); i++;
} 
}
Cart& Cart::operator=(const Cart& cart){
  if(this==&cart) return *this;
  std::vector<Item *>::iterator i = _items.begin(), end = _items.end();
  while(i != end){
    *i = new Item(**i); i++;
}
  return *this;
}
void Cart::add_item(Item& item){
  item = new Item(_name, _price);
  _items.push_back(&item);
}
double Cart::cost(){
  double total = 0.0;
  for(auto item: _items) total = total + item->cost();
  return total;
}

