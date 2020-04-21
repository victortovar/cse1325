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
  ost << "Desktop includes: ";
  for(auto option: desktop.options) ost << "\n " << *option;
  return ost;
}

void Desktop::save(std::ostream& ost) {
   ost << options.size() << '\n';
   for(auto c : options) c->save(ost);
}

Desktop::Desktop(std::istream& ist) {
  int csize;
  ist >> csize; 
  ist.ignore(32767, '\n');
  while(csize--)
    options.push_back(new Options{ist});
}


