#include "dom.h"
#include <iostream>

PyMemberDef PyDOM::members[] =
{
  {NULL}
};

PyTypeObject PyDOM::TypeObj =
{
  PyVarObject_HEAD_INIT(NULL, 0)
  .tp_name = "js.DOM",
  .tp_doc = "Python DOM Objects",
  .tp_basicsize = sizeof(DOM),
  .tp_itemsize = 0,
  .tp_flags = Py_TPFLAGS_DEFAULT,
  .tp_new = PyDOM::__new__,
  .tp_init = (initproc) PyDOM::__init__,
  .tp_dealloc = (destructor) PyDOM::__dealloc__,
  .tp_members = PyDOM::members,
  .tp_methods = PyDOM::methods,
};

PyMethodDef PyDOM::methods[] =
{
  {"html", (PyCFunction) PyDOM::html, METH_VARARGS, "Return the html contents of the element"},
  {NULL}
};

void PyDOM::__dealloc__(DOM* self)
{
  Py_TYPE(self)->tp_free((PyObject*) self);
}

PyObject* PyDOM::__new__(PyTypeObject* type, PyObject* args, PyObject* kwds)
{
  DOM* self;
  self = (DOM*) type->tp_alloc(type, 0);
  if (self != NULL)
  {
    static char *kwlist[] = {const_cast<char*>("JSCV"), NULL};

    PyObject* capsule = NULL;
    PyArg_ParseTupleAndKeywords(args, kwds, "O", kwlist, &capsule);
    self->JSCV = (JSCValue*) PyCapsule_GetPointer(capsule, "JSCValue");
    Py_DECREF(capsule);
  }
  return (PyObject*) self;
}

int PyDOM::__init__(DOM* self, PyObject* args, PyObject* kwds)
{
  // Look at this: https://stackoverflow.com/questions/39813301/creating-a-python-object-in-c-and-calling-its-method
  return 0;
}

PyObject* PyDOM::html(DOM* self, PyObject* args)
{
  char* string = NULL;
  PyArg_ParseTuple(args, "|s", &string);
  if (string)
  {
    std::cout << string << "\n";
    jsc_value_object_invoke_method(self->JSCV, "html", G_TYPE_STRING, string);
    delete string;
    return PyLong_FromLong(0);
  }
  else
  {
    return PyUnicode_FromString(jsc_value_to_string(jsc_value_object_invoke_method(self->JSCV, "html", G_TYPE_NONE)));
  }
}
