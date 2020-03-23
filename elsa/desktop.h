#ifndef __DESKTOP_H
#define __DESKTOP_H
#include<vector>
#include "options.h"

class Desktop{
   private:
      std::vector<Options *> options;
   public:
      Desktop();
      void add_option(Options& option);
      double price() const;
      //std::ostream& operator<<(std::ostream& ost, const Desktop& desktop);
};

#endif
