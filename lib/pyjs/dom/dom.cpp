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
  .tp_new = NULL,
  .tp_init = NULL,
  .tp_dealloc = (destructor) PyDOM::__dealloc__,
  .tp_members = PyDOM::members,
  .tp_methods = PyDOM::methods,
};

PyMethodDef PyDOM::methods[] =
{
  {"html", (PyCFunction) PyDOM::html, METH_VARARGS, "Return the html contents of the element"},
  {"css", (PyCFunction) PyDOM::css, METH_VARARGS, "Return the css contents of the element"},
  {NULL}
};

void PyDOM::__dealloc__(DOM* self)
{
  Py_TYPE(self)->tp_free((PyObject*) self);
}

PyObject* PyDOM::html(DOM* self, PyObject* args)
{
  const char* string;
  PyArg_ParseTuple(args, "|s", &string);
  if (string)
  {
    jsc_value_object_invoke_method(self->JSCV, "html", G_TYPE_STRING, string, G_TYPE_NONE);
    return PyLong_FromLong(0);
  }
  else
  {
    return PyUnicode_FromString(jsc_value_to_string(jsc_value_object_invoke_method(self->JSCV, "html", G_TYPE_NONE)));
  }
}

PyObject* PyDOM::css(DOM* self, PyObject* args)
{
  const char* property;
  const char* value;
  PyArg_ParseTuple(args, "|ss", &property, &value);
  if (property)
  {
    if (value)
    {
      jsc_value_object_invoke_method(self->JSCV, "css", G_TYPE_STRING, property, G_TYPE_STRING, value, G_TYPE_NONE);
      return PyLong_FromLong(0);
    }
    return PyUnicode_FromString(jsc_value_to_string(jsc_value_object_invoke_method(self->JSCV, "css", G_TYPE_STRING, property, G_TYPE_NONE)));
  }
  return PyLong_FromLong(0);
}
