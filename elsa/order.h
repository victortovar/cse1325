#ifndef __order_h
#define __order_h

class Order{
   private:
      Customer& _customer;
      std::vector<Desktop *> _products;
   public:
      Order(Customer& customer);
      ~Order();
      int add_product(Desktop& desktop);
      double price();
};


#endif
