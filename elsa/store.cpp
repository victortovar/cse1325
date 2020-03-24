#include "store.h"

void Store::add_customer(Customer& customer){
   customers.push_back(customer);
}
int Store::num_customers(){
   return customers.size();
}
Customer& Store::customer(int index){
   return customers[index];
}
void Store::add_option(Options& option){
   options.push_back(&option);
}
int Store::num_options(){
   return options.size();
}
Options& Store::option(int index){
   return *options[index];
}/*
int Store::new_desktop(){
   desktops.push_back(Desktop());
   return desktops.size()-1;
}*/ 
void Store::add_option(int option, int desktop){
   desktops.emplace(desktop, options[option]);
}/*
int Store::num_desktops(){
   return _products.size();
}
Desktop& Store::desktop(int index){

}
int Store::new_order(int customer){

}
void Store::add_desktop(int desktop, int order){

}
int Store::num_orders(){
   return orders.size();
}
Order& Store::order(int index){

}
*/
