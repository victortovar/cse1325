#ifndef __store_h
#define __store_h
#include<vector>
#include "customer.h"
#include "order.h"

class Store{
   private:
      std::vector<Customer> customers;
      std::vector<Options *> options;
      std::vector<Desktop> desktops;
      std::vector<Order> orders;
   public:
      Store();
      Store(std::istream& ist);
      void save(std::ostream& ost);      
      void add_customer(Customer& customer);
      int num_customers();
      Customer& customer(int index);
      void add_option(Options& option);
      int num_options();
      Options& option(int index);
      int new_desktop();
      void add_option(int option, int desktop);
      int num_desktops();
      Desktop& desktop(int index);
      int new_order(int customer);
      void add_desktop(int desktop, int order);
      int num_orders();
      Order& order(int index);
};


#endif
