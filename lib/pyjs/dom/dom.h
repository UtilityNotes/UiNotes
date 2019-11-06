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
  static PyObject* html(DOM* self, PyObject* args);
  static PyObject* css (DOM* self, PyObject* args);

  // Variables
  static PyMemberDef members[];
  static PyTypeObject TypeObj;
  static PyMethodDef methods[];

  // Default functions
  static void __dealloc__(DOM* self);
private:
  PyDOM();
};

#endif
