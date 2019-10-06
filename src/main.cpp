#include "gtk/gtk_manager.h"
#include "python/py_manager.h"

int main(int argc, char* args[])
{
  GTKManager::init(argc, args);

  /*
  PyManager::init();
  PyManager::runFile("hello_world", "./test/");
  PyManager::close();
  */

  return 0;
}
