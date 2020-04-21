#include "customer.h"

Customer::Customer(std::string name, std::string phone, std::string email)
   :_name{name}, _phone{phone}, _email{email}{}
std::ostream& operator<<(std::ostream& ost, const Customer& customer){
   std::cout << customer._name << ", " << customer._phone << ", " << customer._email << std::endl;
   return ost;
}

void Customer::save(std::ostream& ost) {
  ost << _name << '\n' << _phone << '\n' << _email  << '\n';
} 

Customer::Customer(std::istream& ist) {
    std::getline(ist, _name);
    std::getline(ist, _phone);
    std::getline(ist, _email);
}



