#ifndef PY_DOM
#define PY_DOM

#include <Python.h>
#include <structmember.h>
#include <jsc/jsc.h>

typedef struct
{
  JSCValue* JSCV; // The JSC value of the struct
  PyObject_HEAD
} DOM;

class PyDOM
{
public:
  static PyMemberDef members[];
  static PyTypeObject TypeObj;

  static void __dealloc__(DOM* self);
  static PyObject* __new__(PyTypeObject* type, PyObject* args, PyObject* kwds);
  static int __init__(DOM* self, PyObject* args, PyObject* kwds);
  // Custom functions
  static PyObject* html();
  static PyObject* html(const char*);
private:
  PyDOM();
};

#endif
