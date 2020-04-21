#ifndef __order_h
#define __order_h
#include "customer.h"
#include "desktop.h"

class Order{
   private:
      Customer& _customer;
      std::vector<Desktop *> _products;
   public:
      Order(Customer& customer);
      virtual ~Order();
      int add_product(Desktop& desktop);
      double price() const;
      Order(std::istream& ist);
      void save(std::ostream& ost);
      friend std::ostream& operator<<(std::ostream& ost, const Order& order);
};


#endif
