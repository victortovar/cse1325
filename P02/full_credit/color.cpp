#include<iostream>
#include<string>
#include "color.h"

Color::Color(int red, int green, int blue)
	:_red{red},_green{green},_blue{blue}{}
std::string Color::to_string(){
	std::string myString= "("+std::to_string(_red)+","+std::to_string(_green)+","+std::to_string(_blue)+")";
	return myString;
}

std::string Color::colorize(std::string text){
	std::string colorString, newString;
	for(int i=0;i<text.size();i++)
	{
	   if(text[i]==',') text.replace(i,1,";");
	}
	for(int i=1;i<text.size()-1;i++)
	{
	   newString[i-1]=text[i];
	}
	colorString="\033[38;2;"+std::to_string(_red)+";"+std::to_string(_green)+";"+std::to_string(_blue)+";177m"+text+"\033[0m";
	return colorString;
}


	



