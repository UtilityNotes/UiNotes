#include <webkit2/webkit-web-extension.h>
#include <iostream>
#include "py_manager.h"
#include <boost/python.hpp>

static JSCContext* jsCtx; // Keeping this global so that Python can access it

void embedImportModule();
PyObject* PyInit_emb();
PyObject* emb_runJS(PyObject* self, PyObject* args);

PyMethodDef EmbMethods[] = {{"runJS", emb_runJS, METH_VARARGS, "Execute JS Code"}, {NULL, NULL, 0, NULL}};
PyModuleDef EmbModule = {PyModuleDef_HEAD_INIT, "UiNotes", NULL, -2, EmbMethods, NULL, NULL, NULL, NULL};

PyObject* jsToPy(JSCValue*);

// Webkit stuff
static void js_handler(WebKitWebPage* webPage)
{
  jsCtx = webkit_frame_get_js_context(webkit_web_page_get_main_frame(webPage));

  embedImportModule();
  PyManager::init();
  PyManager::runFile("menu", "./ui/");
  PyManager::close();
}

static void document_loaded_callback(WebKitWebPage* webPage, gpointer userData)
{
  // g_print("Page %lu created for %s\n", webkit_web_page_get_id(webPage), webkit_web_page_get_uri(webPage));
  js_handler(webPage);
}

static void web_page_created_callback(WebKitWebExtension* extension, WebKitWebPage* webPage, gpointer userData)
{
  g_signal_connect(webPage, "document-loaded", G_CALLBACK(document_loaded_callback), NULL);
}

extern "C" G_MODULE_EXPORT void webkit_web_extension_initialize(WebKitWebExtension* extension)
{
  g_signal_connect(extension, "page-created", G_CALLBACK(web_page_created_callback), NULL);
}

// Python stuff
void embedImportModule()
{
  PyImport_AppendInittab("UiNotes", &PyInit_emb);
}

PyObject* PyInit_emb()
{
  return PyModule_Create(&EmbModule);
}

PyObject* emb_runJS(PyObject* self, PyObject* args)
{
  char* command;
  PyArg_ParseTuple(args, "s", &command);

  // Return result if possible
  JSCValue* result = jsc_context_evaluate(jsCtx, command, -1);
  return jsToPy(result);
}

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
  // Return 0 if nothing else, returning NULL terminates the script
  else
  {
    return PyLong_FromLong(0);
  }
}
