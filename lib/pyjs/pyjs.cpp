#include "pyjs.h"

static JSCContext* jsCtx; // Keeping this global so that Python can access it

// Function prototypes
void embedImportModule();
PyMODINIT_FUNC PyInit_js(void);
PyObject* emb_js_run(PyObject* self, PyObject* args);
PyObject* emb_js_selector(PyObject* self, PyObject* args);
PyObject* jsToPy(JSCValue*);
static void printPropertyNames(JSCValue*);
PyObject* buildPyDOM(JSCValue* jscv);

// Module Method Table
PyMethodDef EmbMethods[] =
{
  {"run", emb_js_run, METH_VARARGS, "Execute JS Code"},
  {"S", emb_js_selector, METH_VARARGS, "Execute JS Code"},
  {NULL, NULL, 0, NULL}
};
PyModuleDef EmbModule = {PyModuleDef_HEAD_INIT, "js", NULL, -1, EmbMethods, NULL, NULL, NULL, NULL};

// Python stuff
void embedImportModule()
{
  PyImport_AppendInittab("js", PyInit_js);
}

PyMODINIT_FUNC PyInit_js(void)
{
  PyObject* module;

  if (PyType_Ready(&PyDOM::TypeObj) < 0)
    return NULL;

  module = PyModule_Create(&EmbModule);
  if (module == NULL)
    return NULL;

  Py_INCREF(&PyDOM::TypeObj);
  if (PyModule_AddObject(module, "DOM", (PyObject*) &PyDOM::TypeObj) < 0)
  {
    Py_DECREF(&PyDOM::TypeObj);
    Py_DECREF(module);
    return NULL;
  }

  return module;
}

/* Simply execute the JS String */
PyObject* emb_js_run(PyObject* self, PyObject* args)
{
  char* command;
  PyArg_ParseTuple(args, "s", &command);

  // Return result if possible
  JSCValue* result = jsc_context_evaluate(jsCtx, command, -1);
  return jsToPy(result);
}

/*
 * jsToPy()
 *
 * Convert a JSCValue* to a PyObject*
 */
PyObject* jsToPy(JSCValue* jsVar)
{
  // Number (Will be converted to double)
  if (jsc_value_is_number(jsVar))
  {
    return PyLong_FromLong(jsc_value_to_double(jsVar));
  }
  // Boolean
  else if (jsc_value_is_boolean(jsVar))
  {
    return PyBool_FromLong(jsc_value_to_boolean(jsVar));
  }
  // String
  else if (jsc_value_is_string(jsVar))
  {
    return PyUnicode_FromString(jsc_value_to_string(jsVar));
  }
  // Arrays
  // Functions
  // Objects
  else if (jsc_value_is_object(jsVar))
  {
    // printPropertyNames(jsVar);

    return buildPyDOM(jsVar);
  }
  // Return 0 if nothing else, returning NULL terminates the script
  else
  {
    return PyLong_FromLong(0);
  }
}

/*
 * printPropertyNames()
 */
void printPropertyNames(JSCValue* jsVar)
{
  char** foo = jsc_value_object_enumerate_properties(jsVar);

  for (char** ptr = foo; *ptr != NULL; ptr++)
  {
    std::cout << *ptr << "\n";
    std::cout << jsc_value_to_string(jsc_value_object_get_property(jsVar, *ptr)) << "\n\n";
  }
}

/*
 * PyJS_JSHandler
 *
 * The function to be exported and used in webkit_web_extension_initialize
 */
void PyJS_JSHandler(WebKitWebPage* webPage)
{
  jsCtx = webkit_frame_get_js_context(webkit_web_page_get_main_frame(webPage));

  embedImportModule();
  PyManager::init();
  PyManager::runFile("menu", "./ui/");
  PyManager::close();
}

PyObject* buildPyDOM(JSCValue* jscv)
{
  PyTypeObject* type = &PyDOM::TypeObj;
  DOM *self = (DOM*) type->tp_alloc(type, 0);
  self->JSCV = jscv;
  return (PyObject*) self;
}

PyObject* emb_js_selector(PyObject* self, PyObject* args)
{
  char* selector;
  PyArg_ParseTuple(args, "s", &selector);
  string command = "$(\"";
  command += selector;
  command += "\")";

  // Return result if possible
  JSCValue* result = jsc_context_evaluate(jsCtx, command.c_str(), -1);
  return jsToPy(result);
}
