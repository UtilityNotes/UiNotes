#ifndef PY_EMBED
#define PY_EMBED

#include <Python.h>

/*
 * PyEmbed
 * ----------------
 * Static class that embeds the methods
 * that are in this class
 */
class PyEmbed
{
public:
  static void embedImportModule();
private:
  PyEmbed(); // Forces class to be static
  static int secretInt;
  static PyMethodDef EmbMethods[];
  static PyModuleDef EmbModule;
  static PyObject* PyInit_emb();
  // Custom functions
  static PyObject* emb_getSecretInt(PyObject *self, PyObject *args);
};

#endif
