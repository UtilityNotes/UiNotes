#include "dom.h"

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

  }
  return (PyObject*) self;
}

int PyDOM::__init__(DOM* self, PyObject* args, PyObject* kwds)
{
  // Look at this: https://stackoverflow.com/questions/39813301/creating-a-python-object-in-c-and-calling-its-method
  return 0;
}

PyObject* PyDOM::getTag(DOM* self, PyObject* Py_UNUSED(ignored))
{
  if (self->tag == NULL)
  {
    PyErr_SetString(PyExc_AttributeError, "tag");
    return NULL;
  }

  return PyUnicode_FromFormat("%S", self->tag);
}

PyObject* PyDOM::html()
{
  return PyUnicode_FromString(jsc_value_is_string(jsc_value_object_invoke_method(self->JSCV, "html", G_TYPE_NONE)));
}

PyObject* PyDOM::html(const char*)
{
  return PyLong_FromLong(0);
}
