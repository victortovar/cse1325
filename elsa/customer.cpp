#include "customer.h"

Customer::Customer(std::string name, std::string phone, std::string email)
   :_name{name}, _phone{phone}, _email{email}{}
std::ostream& operator<<(std::ostream& ost, const Customer& customer){
   std::cout << customer._name << ", " << customer._phone << ", " << customer._email << std::endl;
   return ost;
}


