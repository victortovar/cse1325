#include "desktop.h"

Desktop::Desktop(){}
void Desktop::add_option(Options& option){
   options.push_back(&option);
}
double Desktop::price() {
   double sum = 0.0;
   for(auto option : options) sum+=option->cost();
   return sum;
}
std::ostream& operator<<(std::ostream& ost, const Desktop& desktop){

   return ost;
}
