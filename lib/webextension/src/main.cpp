#include <webkit2/webkit-web-extension.h>
#include <pyjs.h>
#include "jquery.h"

static void document_loaded_callback(WebKitWebPage* webPage, gpointer userData)
{
  // Run jQuery
  jsc_context_evaluate(webkit_frame_get_js_context(webkit_web_page_get_main_frame(webPage)), jQuery::getStr().c_str(), -1);

  PyJS_JSHandler(webPage);
}

static void web_page_created_callback(WebKitWebExtension* extension, WebKitWebPage* webPage, gpointer userData)
{
  g_signal_connect(webPage, "document-loaded", G_CALLBACK(document_loaded_callback), NULL);
}

extern "C" G_MODULE_EXPORT void webkit_web_extension_initialize(WebKitWebExtension* extension)
{
  g_signal_connect(extension, "page-created", G_CALLBACK(web_page_created_callback), NULL);
}

// It seems window-object-cleared doesn't work, the callback isn't being called
/*
static void window_object_cleared_callback(WebKitScriptWorld* world, WebKitWebPage* page, WebKitFrame* frame, gpointer userData)
{
  PyJS_JSHandler(frame, world);
}

extern "C" G_MODULE_EXPORT void webkit_web_extension_initialize(WebKitWebExtension* extension)
{
  g_signal_connect(webkit_script_world_get_default(), "window-object-cleared", G_CALLBACK(window_object_cleared_callback), NULL);
}
*/
