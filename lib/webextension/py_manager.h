#ifndef PY_MANAGER
#define PY_MANAGER

#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <cstdarg>
#include <string>
using std::string;
#include <iostream>
using std::cout;

class PyManager
{
public:
  /*
   * PyManager::init()
   * ---------------------
   * Needed before using any other method
   */
  static void init();


  /*
   * PyManager::close()
   * ----------------------
   * Call this before ending the program
   */
  static void close();

  /*
   * PyManager::runFile()
   * ------------------------
   * Runs the main function of a Python Script and
   * returns a PyOject which has the return of the
   * main function of that script.
   */
  static PyObject* runFile(const char* module, const char* location);
  static PyObject* runFile(const char* module, const char* location, const int argc, ...);
private:
  // Make sure no instances are created
  PyManager();
};

#endif
