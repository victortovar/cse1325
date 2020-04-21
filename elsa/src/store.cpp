#include "store.h"

Store::Store() {}
Store::Store(std::istream& ist){
  std::string str;
  int csize;
  std::getline(ist, str);

  ist >> csize; ist.ignore(32767, '\n');
  while(csize--) customers.push_back(Customer{ist});
  if(!ist) throw std::runtime_error{"Bad Customer Data"};

  ist >> csize; ist.ignore(32767, '\n');
  while(csize--) options.push_back(new Options{ist});
  if(!ist) throw std::runtime_error{"Bad Options Data"};

  ist >> csize; ist.ignore(32767, '\n');
  while(csize--) desktops.push_back(Desktop{ist});
  if(!ist) throw std::runtime_error{"Bad Product Data"};

  ist >> csize; ist.ignore(32767, '\n');
  while(csize--) orders.push_back(Order{ist});
  if(!ist) throw std::runtime_error{"Bad Order Data"};
}

void Store::save(std::ostream& ost) {

  //  ost << ELSA_COOKIE << "\n";
    //ost << ELSA_FILE_VERSION << "\n";

    ost << customers.size() << '\n';
    for(auto c : customers) c.save(ost);

    ost << options.size() << '\n';
    for(auto o : options) o->save(ost);

    ost << desktops.size() << '\n';
    for(auto d : desktops) d.save(ost);

    ost << orders.size() << '\n';
    for(auto o : orders) o.save(ost);
}

void Store::add_customer(Customer& customer){
   customers.push_back(customer);
}
int Store::num_customers(){
   return customers.size();
}
Customer& Store::customer(int index){
   return customers.at(index);
}
void Store::add_option(Options& option){
   options.push_back(new Options{option});
}
int Store::num_options(){
   return options.size();
}
Options& Store::option(int index){
   return *options.at(index);
}
int Store::new_desktop(){
   desktops.push_back(Desktop{});
   return desktops.size()-1;
}
void Store::add_option(int option, int desktop){
   desktops[desktop].add_option(*options[option]);
}
int Store::num_desktops(){
   return desktops.size();
}
Desktop& Store::desktop(int index){
  return desktops[index];
}
int Store::new_order(int customer){
   orders.push_back(Order{customers[customer]});
   return orders.size()-1;
}
void Store::add_desktop(int desktop, int order){
	orders[order].add_product(desktops[desktop]);
}
int Store::num_orders(){
   return orders.size();
}
Order& Store::order(int index){
   return orders[index];
}

