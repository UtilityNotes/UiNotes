#include "gtk/gtk_manager.h"

void GTKManager::init(int argc, char* args[])
{
  gtk_init(&argc, &args);

  GtkWidget *main_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_default_size(GTK_WINDOW(main_window), 800, 600);

  WebKitWebView *webView = WEBKIT_WEB_VIEW(webkit_web_view_new());

  gtk_container_add(GTK_CONTAINER(main_window), GTK_WIDGET(webView));

  g_signal_connect(main_window, "destroy", G_CALLBACK(destroyWindowCb), NULL);
  g_signal_connect(webView, "close", G_CALLBACK(closeWebViewCb), main_window);

  boost::filesystem::path cwd(boost::filesystem::current_path());
  string cwdUri = "file://" + cwd.native() + "/test/load.html";
  webkit_web_view_load_uri(webView, cwdUri.c_str());

  gtk_widget_grab_focus(GTK_WIDGET(webView));

  gtk_widget_show_all(main_window);

  gtk_main(); // this is substituting the run method
}

void GTKManager::run()
{
  /*
  while (true)
    if (!gtk_main_iteration_do(FALSE))
      break;
  */
}

void GTKManager::destroyWindowCb(GtkWidget* widget, GtkWidget* window)
{
  gtk_main_quit();
}

gboolean GTKManager::closeWebViewCb(WebKitWebView *webView, GtkWidget *window)
{
  gtk_widget_destroy(window);
  return TRUE;
}
