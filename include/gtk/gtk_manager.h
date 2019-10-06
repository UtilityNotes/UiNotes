#ifndef GTK_MANAGER
#define GTK_MANAGER

#include <gtk/gtk.h>
#include <glib.h>
#include <webkit2/webkit2.h>
#include <boost/filesystem.hpp>
#include <string>
using std::string;

class GTKManager
{
public:
  static void init(int argc, char* args[]); // Creates the window and begin GTK loop
private:
  GTKManager();
  static void destroyWindowCb(GtkWidget* widget, GtkWidget* window);
  static gboolean closeWebViewCb(WebKitWebView* webView, GtkWidget* window);
};

#endif
