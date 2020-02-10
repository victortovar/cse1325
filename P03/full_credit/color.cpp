#include<iostream>
#include<string>
#include "color.h"

Color::Color(int red, int green, int blue)
   :_red{red},_green{green},_blue{blue},_reset{false}{}
Color::Color()
   :_reset{true}{}
std::string Color::to_string(){
   std::string myString= "("+std::to_string(_red)+","+std::to_string(_green)
                        +","+std::to_string(_blue)+")";
   return myString;
}

std::ostream& operator <<(std::ostream& ost, Color& color){
   if(color._reset){
      ost <<"\033[0m";
}
   else{
      ost << "\033[38;2;"+std::to_string(color._red)+";"
                      +std::to_string(color._green)+";"
		      +std::to_string(color._blue)+";177m"
		      ;
}
   return ost;
}

std::istream& operator>>(std::istream& ist, Color& color){

   ist >> color._red >> color._green >> color._blue;
   return ist;
}

/*
std::string Color::colorize(std::string text){
	std::string colorString;
	colorString="\033[38;2;"+std::to_string(_red)+";"+std::to_string(_green)+";"+std::to_string(_blue)+";177m"+text+"\033[0m";
	return colorString;

}
*/


	



