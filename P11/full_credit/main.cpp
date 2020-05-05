#include "cart.h"
#include "item.h"


int main(){
  Cart cart{"Bugs Bunny"}; Item item{"", 0};
  std::cout << "Enter product names and price: " << std::endl;
  for(int i = 0; i < 5; i++){
    std::cin>>item; cart.add_item(item);
}
  for(Item* c: cart) std::cout << c->cost() << std::endl;
  std::cout << "---------------" << std::endl;
  std::cout << "$ " << cart.cost() << "Total Cost" << std::endl;

  return 0;
}
