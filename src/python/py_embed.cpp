#include "python/py_embed.h"

int PyEmbed::secretInt = 54;
PyMethodDef PyEmbed::EmbMethods[] = {{"getSecretInt", emb_getSecretInt, METH_NOARGS, "Get the Secret Integer"}, {NULL, NULL, 0, NULL}};
PyModuleDef PyEmbed::EmbModule = {PyModuleDef_HEAD_INIT, "UiNotes", NULL, -2, EmbMethods, NULL, NULL, NULL, NULL};

void PyEmbed::embedImportModule()
{
  PyImport_AppendInittab("UiNotes", &PyInit_emb);
}

PyObject* PyEmbed::PyInit_emb()
{
  return PyModule_Create(&EmbModule);
}

PyObject* PyEmbed::emb_getSecretInt(PyObject* self, PyObject* args)
{
  return PyLong_FromLong(secretInt);
}
