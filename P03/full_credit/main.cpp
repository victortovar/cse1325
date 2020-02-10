#include<iostream>
//#include<string>
#include "color.h"

int main(){
   Color red{255,0,0};
   Color green{0,255,0};
   Color blue{0,0,255};
   Color reset;
   std::cout<<red<<"Red"<<std::endl;
   std::cout<<green<<"Green"<<std::endl;
   std::cout<<blue<<"Blue"<<std::endl;
   std::cout<<reset;
   Color color{0,0,0};
   std::cout<<"Enter red, green, and blue ints: ";
   std::cin>>color;
   std::cout<<color<<color.to_string()<<std::endl;
   return 0;
}

