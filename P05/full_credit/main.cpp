#include "product.h"
#include "taxed.h"
#include "taxfree.h"
#include <vector>

int main(){
  std::vector<Taxfree> taxfree;
  std::vector<Taxed> taxed;
  Taxfree Milk("Milk", 2.85);
  Taxfree Bread("Bread", 1.99);
  Taxfree Cheese("Cheese", 0.99);
  taxfree.push_back(Milk); taxfree.push_back(Bread); taxfree.push_back(Cheese);
  Taxed Ice_cream("Ice Cream", 4.95);
  Taxed Poptarts("Poptarts", 3.49);
  Taxed Oreos("Oreos", 5.99);
  taxed.push_back(Ice_cream); taxed.push_back(Poptarts); taxed.push_back(Oreos);
  std::vector<Taxfree> cart1;
  std::vector<Taxed> cart2;
  int quant=1, index=0; double total = 0;
  try{
  while(quant!=0){
    std::cout<<"===========\nWelcome to the Store\n===========\n";
    for(int i=0;i<taxfree.size();i++){
      std::cout << i << ")" << taxfree[i] << std::endl;
}
    for(int i=0;i<taxed.size();i++){
      std::cout << i+taxfree.size() << ")" << taxed[i] << std::endl;
}
    do{
      std::cout<<"Enter quantity (0 to exit) and product index: ";
      std::cin>> quant; std::cin>>index;
      if(quant<0){throw "Invalid quantity";}
      if(index<0||index>5) {throw std::runtime_error{"Undefined grocery item"};}
}   while(quant<0||index<0||index>5);

    if(total!=0){
      std::cout << "Current Order\n----------" << std::endl;
      if(index<taxfree.size()) total = total + taxfree[index]._cost*quant;

}
}

}catch(std::runtime_error e){}
  std::cout << "Hello" << std::endl;
  return 0;
}
