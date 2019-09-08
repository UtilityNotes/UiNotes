#include "gtk/gtk_manager.h"

int main(int argc, char* args[])
{
  GTKManager::init(argc, args);
  GTKManager::run();

  return 0;
}
