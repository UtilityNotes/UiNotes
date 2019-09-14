#include "gtk/gtk_manager.h"
#include <iostream>

// Function prototypes
void createMenu(GtkWidget*, GtkWidget*, WebKitWebView*);
void openFile(GtkWidget*, gpointer);

void GTKManager::init(int argc, char* args[])
{
  // Initialize GTK
  gtk_init(&argc, &args);

  // Create the GTK window
  GtkWidget* main_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_default_size(GTK_WINDOW(main_window), 800, 600);
  gtk_window_set_title(GTK_WINDOW(main_window), "UiNotes");

  // Create the GTK box for packing
  GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
  gtk_container_add(GTK_CONTAINER(main_window), box);

  WebKitWebView* webView = WEBKIT_WEB_VIEW(webkit_web_view_new());
  // Create the menu bar
  createMenu(main_window, box, webView);

  // Add the WebKitView as a GTK container

  //gtk_container_add(GTK_CONTAINER(main_window), GTK_WIDGET(webView));
  gtk_box_pack_start(GTK_BOX(box), GTK_WIDGET(webView), TRUE, TRUE, 0);

  // Set up event handlers
  g_signal_connect(main_window, "destroy", G_CALLBACK(destroyWindowCb), NULL);
  g_signal_connect(webView, "close", G_CALLBACK(closeWebViewCb), main_window);

  // Open up the load file
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

gboolean GTKManager::closeWebViewCb(WebKitWebView* webView, GtkWidget* window)
{
  gtk_widget_destroy(window);
  return TRUE;
}

void createMenu(GtkWidget* window, GtkWidget* box, WebKitWebView *webView)
{
  /*
   * Menu Item = The button
   * Menu = Container with the buttons
   * Menu bar = Container with the menus
   */

   // Create the file menu
   GtkWidget* file_menu = gtk_menu_new();
   // Create the file menu items
   GtkWidget* file_open = gtk_menu_item_new_with_label("Open file");
   // Add the file menu items to the menu
   gtk_menu_shell_append(GTK_MENU_SHELL(file_menu), file_open);
   // Add the callback functions
   g_signal_connect(file_open, "activate", G_CALLBACK(openFile), webView);
   //g_signal_connect_swapped(file_open, "activate", G_CALLBACK(menuitem_response), (gpointer) "file.open");
   // Show the items
   gtk_widget_show(file_open);

   // Create the menu bar
   GtkWidget* menu_bar = gtk_menu_bar_new();
   //gtk_container_add(GTK_CONTAINER(window), menu_bar);
   gtk_box_pack_start(GTK_BOX(box), menu_bar, FALSE, TRUE, 0);
   gtk_widget_show(menu_bar);
   // Create the menus
   GtkWidget* file_item = gtk_menu_item_new_with_label("File");
   gtk_widget_show(file_item);
   gtk_menu_item_set_submenu(GTK_MENU_ITEM(file_item), file_menu);
   // Add the menus to the menu bar
   gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), file_item);
}

void openFile(GtkWidget *window, gpointer callbackData)
{
  GtkWidget *dialog;
  GtkFileChooserAction action = GTK_FILE_CHOOSER_ACTION_OPEN;
  gint res;
  WebKitWebView* webView = static_cast<WebKitWebView*>(callbackData);

  dialog = gtk_file_chooser_dialog_new("Open File", NULL, action, "Cancel", GTK_RESPONSE_CANCEL, "Open", GTK_RESPONSE_ACCEPT, NULL);
  res = gtk_dialog_run(GTK_DIALOG(dialog));
  if (res == GTK_RESPONSE_ACCEPT)
  {
    GtkFileChooser *chooser = GTK_FILE_CHOOSER(dialog);
    char *filename = gtk_file_chooser_get_filename(chooser);
    std::cout << filename << "\n";
    string newFileUri = "file://";
    newFileUri += filename;
    webkit_web_view_load_uri(webView, newFileUri.c_str());
  }

  gtk_widget_destroy(dialog);
}
