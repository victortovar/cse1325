#include "order.h"

Order::Order(Customer& customer)
   :_customer{customer}{}
Order::~Order(){}
int Order::add_product(Desktop& desktop){
   _products.push_back(&desktop);
   return _products.size()-1;
}
double Order::price() const{
   double sum = 0.0;
   for(auto product: _products) sum+= product->price();
   return sum;
}
std::ostream& operator<<(std::ostream& ost, const Order& order){
  ost << "Customer: " << order._customer;
  for(auto p : order._products) 
    ost << "\n  " << *p << "\n  Price: $" << p->price() << "\n";
  ost << "\nTotal price: $" << order.price() << "\n";
  return ost;
}

void Order::save(std::ostream& ost) {
   _customer.save(ost);
   ost << _products.size() << '\n';
   for (auto product : _products) product->save(ost);
}

Order::Order(std::istream& ist) {
  _customer = new Customer{ist} 
  int csize;
  ist >> csize;
  ist.ignore(32767, '\n');
  while(csize--)
    _products.push_back(new Desktop{ist});
}

