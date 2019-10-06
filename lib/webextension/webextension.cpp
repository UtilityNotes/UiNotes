#include <webkit2/webkit-web-extension.h>
#include <iostream>

/*
static void window_object_cleared_callback(WebKitScriptWorld* world, WebKitWebPage* webPage, WebKitFrame* frame, gpointer userData)
{
  std::cout << "Callback reached\n";

  JSCContext *jsCtx = webkit_frame_get_js_context_for_script_world(frame, world);
  JSCValue* title = jsc_context_evaluate(jsCtx, "document.title;", -1);

  std::cout << "Title: " << jsc_value_to_string(title) << "\n";
}
*/

static void document_loaded_callback(WebKitWebPage* webPage, gpointer userData)
{
  g_print("Page %lu created for %s\n", webkit_web_page_get_id(webPage), webkit_web_page_get_uri(webPage));
}

static void web_page_created_callback(WebKitWebExtension* extension, WebKitWebPage* webPage, gpointer userData)
{
  g_signal_connect(webPage, "document-loaded", G_CALLBACK(document_loaded_callback), NULL);
}

extern "C" G_MODULE_EXPORT void webkit_web_extension_initialize(WebKitWebExtension* extension)
{
  g_signal_connect(extension, "page-created", G_CALLBACK(web_page_created_callback), NULL);
  // g_signal_connect(webkit_script_world_get_default(), "window-object-cleared", G_CALLBACK(window_object_cleared_callback), NULL);
}
