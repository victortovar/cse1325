#ifndef __DESKTOP_H
#define __DESKTOP_H
#include<vector>
#include "options.h"

class Desktop{
   private:
      std::vector<Options *> option;
   public:
      Desktop();
      void add_option(Options& option);
      double price();
};

#endif
