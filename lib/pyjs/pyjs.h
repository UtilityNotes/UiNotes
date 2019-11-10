#ifndef PY_JS
#define PY_JS

#include <webkit2/webkit-web-extension.h>
#include <jsc/jsc.h>
#include "py_manager.h"
#include "dom/dom.h"
#include <string>

extern void PyJS_JSHandler(WebKitWebPage*);

#endif
