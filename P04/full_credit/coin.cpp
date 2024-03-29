#include<iostream>
#include<string>
#include "coin.h"
#include "logger.h"

Coin::Coin(Coin_size size, Year year)
     :_size{size},_year{year}, _notes{nullptr}{LOG("Coin::Coin");}
Coin::Coin(const Coin &rhs){
   _size=rhs._size; _year=rhs._year;_notes=new std::string();
   _notes->assign(*(rhs._notes));
   LOG("Coin::Coin copy constructor");
}
Coin::~Coin(){LOG("Coin::~Coin");delete _notes;}
Coin& Coin::operator=(const Coin &rhs) {
   _size=rhs._size; _year=rhs._year;
   LOG("Coin::operator=");
   if(this != &rhs) {
      _notes = new std::string;
      _notes->assign(*(rhs._notes));
      return *this;
}
}

std::ostream& operator<<(std::ostream& ost, const Coin& coin){
   std::string coinString="";
   if(coin._size==Coin_size::PENNY) coinString="penny";
   else if(coin._size==Coin_size::NICKEL) coinString="nickel";
   else if(coin._size==Coin_size::DIME) coinString="dime";
   else if(coin._size==Coin_size::QUARTER) coinString="quarter";
   else throw std::runtime_error{"Invalid coin"};
   ost << coin._year << " "<< coinString << "\n" << *(coin._notes)  ;
   return ost;
}

std::istream& operator >>(std::istream& ist, Coin& coin){
   
   return ist;
}

void Coin::add_note(std::string s){
   if(!_notes){
      _notes = new std::string;
      _notes->assign(s);
} 

   else {
      _notes->append(s);
}

}


