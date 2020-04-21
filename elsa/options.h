#ifndef __OPTIONS_H
#define __OPTIONS_H
#include<string>
#include<iostream>

class Options{
  protected:
    std::string _name;
    double _cost;
  public:
    Options(std::string name, double cost);
    ~Options();
    double cost();
    std::string to_string() const;
    void save(std::ostream& ost);
    Options(std::istream& ist);
    friend std::ostream& operator<<(std::ostream& ost, const Options& option);
};


#endif
