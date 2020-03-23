#include "desktop.h"


Desktop::Desktop(){}/*
void Desktop::add_option(Options& option){
   options->push_back(option);
}
*/
double Desktop::price() const {
   double sum = 0.0;
   for(auto option : options) sum+=option->_cost;
   return sum;
}
