#include <iostream>
#include <string>

int main() {
std::string MyName;
std::cout << "What's your name?" << std::endl;
std::getline(std::cin,MyName);
std::cout <<"Hello " << MyName << std::endl;

return 0;
}

