#include<iostream>
#include<string>
#include "color.h"

int main(){
	Color red{255,0,0};
	Color green{0,255,0};
	Color blue{0,0,255};
	std::cout<<red.colorize("Red")<<std::endl;
	std::cout<<green.colorize("Green")<<std::endl;
	std::cout<<blue.colorize("Blue")<<std::endl;
	int r,g,b=-1;
	while(r<0||r>255){
	std::cout << "Enter an integer between 0 and 255: " << std::endl;	
	std::cin>>r;
	if(r<0||r>255)std::cout<<"Value out of range"<<std::endl;
}
	while(g<0||g>255){
	std::cout << "Enter an integer between 0 and 255: " << std::endl;
	std::cin>>g;
	if(g<0||g>255)std::cout<<"Value out of range"<<std::endl;
}
	while(b<0||b>255){
	std::cout << "Enter an integer between 0 and 255: " << std::endl;
	std::cin>>b;
	if(b<0||b>255)std::cout<<"Value out of range"<<std::endl;
}
	Color userColor{r,g,b};	
	std::cout<<userColor.colorize(userColor.to_string())<<std::endl;

return 0;
}
