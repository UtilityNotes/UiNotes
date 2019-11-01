#ifndef JQUERY
#define JQUERY

#include <string>
#include <fstream>
#include <streambuf>

class jQuery
{
public:
  static std::string getStr();
private:
  jQuery();
  static std::string jQueryStr;
};

#endif
