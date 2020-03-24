#include "order.h"

Order::Order(Customer& customer)
   :_customer{customer}{}
Order::~Order(){}
int Order::add_product(Desktop& desktop){
   _products.push_back(&desktop);
   return _products.size();
}
double Order::price(){
   double sum = 0.0;
   for(auto product: _products) sum+= product->price();
   return sum;
}
std::ostream& operator<<(std::ostream& ost, const Order& order){
   std::cout << std::endl;
   return ost;
}
