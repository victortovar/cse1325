#ifndef __COLOR_H
#define __COLOR_H
#include<iostream>
#include<string>

class Color {
	public:
		Color(int red, int green, int blue);
		std::string to_string();
		std::string colorize(std::string text);
	private:
		int _red,_green,_blue;	

};



#endif

