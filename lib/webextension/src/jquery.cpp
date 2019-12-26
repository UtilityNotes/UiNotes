/*
 * Code finessed from https://stackoverflow.com/questions/2602013/read-whole-ascii-file-into-c-stdstring
 */
#include "jquery.h"

std::ifstream in("ui/jquery.js");
std::string jQuery::jQueryStr((std::istreambuf_iterator<char>(in)), std::istreambuf_iterator<char>());

std::string jQuery::getStr()
{
  return jQueryStr;
}
