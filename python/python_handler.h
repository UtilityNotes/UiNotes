#ifndef PYTHON_HANDLER
#define PYTHON_HANDLER

#define PY_SSIZE_T_CLEAN
#include <Python.h>
#include <cstdarg>

class PythonHandler
{
public:
  /*
   * PythonHandler::init()
   * ---------------------
   * Needed before using any other method
   */
  static void init();

  /*
   * PythonHandler::close()
   * ----------------------
   * Call this before ending the program
   */
  static void close();

  /*
   * PythonHandler::runFile()
   * ------------------------
   * Runs the main function of a Python Script and
   * returns a PyOject which has the return of the
   * main function of that script.
   */
  static PyObject* runFile(const char *module, const char *location);
  static PyObject* runFile(const char *module, const char *location, const int argc, ...);
private:
  // Make sure no instances are created
  PythonHandler();
};

#endif
