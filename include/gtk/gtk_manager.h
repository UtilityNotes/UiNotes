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
  static void init(int argc, char* args[]); // Creates the window
  static void run(); // Begins the loop
  static void destroyWindowCb(GtkWidget* widget, GtkWidget* window);
  static gboolean closeWebViewCb(WebKitWebView* webView, GtkWidget* window);
private:
  GTKManager();
};

#endif
