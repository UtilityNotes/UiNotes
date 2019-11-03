#ifndef PY_DOM
#define PY_DOM

#include <Python.h>
#include <structmember.h>
#include <jsc/jsc.h>

typedef struct
{
  PyObject_HEAD
  JSCValue* JSCV; // The JSC value of the struct
} DOM;

class PyDOM
{
public:
  // Custom functions
  static PyObject* html(DOM* self, PyObject*);

  // Variables
  static PyMemberDef members[];
  static PyTypeObject TypeObj;
  static PyMethodDef methods[];

  // Default functions
  static void __dealloc__(DOM* self);
  static PyObject* __new__(PyTypeObject* type, PyObject* args, PyObject* kwds);
  static int __init__(DOM* self, PyObject* args, PyObject* kwds);
private:
  PyDOM();
};

#endif
