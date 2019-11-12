#include "gtk/gtk_manager.h"
#define WEB_EXTENSIONS_DIR "/home/mihir/Coding/UiNotes/app/lib/webextension"
#include <iostream>

// Function prototypes
void createMenu(GtkWidget*, GtkWidget*);
void openFile(GtkWidget*, gpointer);
void initialize_web_extensions(WebKitWebContext*, gpointer);

/*
 * init()
 * ---------------------
 * Initializes GTK, creates the GTK menu, creates the WebKitWebView,
 * loads the loading screen, and runs the GTK main loop
 */
void GTKManager::init(int argc, char* args[])
{
  // Connect Web Extensions
  g_signal_connect(webkit_web_context_get_default(), "initialize-web-extensions", G_CALLBACK(initialize_web_extensions), NULL);

  // Initialize GTK
  gtk_init(&argc, &args);

  // Create the GTK window
  GtkWidget* main_window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
  gtk_window_set_default_size(GTK_WINDOW(main_window), 800, 600);
  gtk_window_set_title(GTK_WINDOW(main_window), "UiNotes");
  gtk_window_set_default_icon_from_file("./images/icon48x48.png", NULL);

  // Create the GTK box for packing
  GtkWidget *box = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
  gtk_container_add(GTK_CONTAINER(main_window), box);

  // Create the menu bar
  createMenu(main_window, box);

  // Add the WebKitView to the box
  WebKitWebView* webView = WEBKIT_WEB_VIEW(webkit_web_view_new());
  gtk_box_pack_start(GTK_BOX(box), GTK_WIDGET(webView), TRUE, TRUE, 0);
  // Set up event handlers
  g_signal_connect(main_window, "destroy", G_CALLBACK(destroyWindowCb), NULL);
  g_signal_connect(webView, "close", G_CALLBACK(closeWebViewCb), main_window);
  // Open up the load file
  boost::filesystem::path cwd(boost::filesystem::current_path());
  string cwdUri = "file://" + cwd.native() + "/ui/menu.html";
  webkit_web_view_load_uri(webView, cwdUri.c_str());
  /*
  //Enable developer extras
  WebKitSettings* setting = webkit_web_view_get_settings(WEBKIT_WEB_VIEW(webView));
  g_object_set(G_OBJECT(setting), "enable-developer-extras", TRUE, NULL);
  // Show inspector
  WebKitWebInspector* inspector = webkit_web_view_get_inspector(WEBKIT_WEB_VIEW(webView));
  webkit_web_inspector_show(WEBKIT_WEB_INSPECTOR(inspector));
  */

  gtk_widget_grab_focus(GTK_WIDGET(webView)); // Keyboard focus

  // Show everything
  gtk_widget_show(GTK_WIDGET(webView));
  gtk_widget_show(box);
  gtk_widget_show_now(main_window);

  gtk_main();
}

/*
 * destroyWindowCb()
 * ---------------------
 * Callback function for when the GTK window is destroyed
 */
void GTKManager::destroyWindowCb(GtkWidget* widget, GtkWidget* window)
{
  gtk_main_quit();
}

/*
 * closeWebViewCb()
 * ---------------------
 * Callback function to destory the window when webview is closed
 */
gboolean GTKManager::closeWebViewCb(WebKitWebView* webView, GtkWidget* window)
{
  gtk_widget_destroy(window);
  return TRUE;
}

/*
 * createMenu()
 * ---------------------
 * Creates the GTK menu
 */
void createMenu(GtkWidget* window, GtkWidget* box)
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
   g_signal_connect(file_open, "activate", G_CALLBACK(openFile), NULL);
   // Show the items
   gtk_widget_show(file_open);

   // Create the menu bar
   GtkWidget* menu_bar = gtk_menu_bar_new();
   gtk_box_pack_start(GTK_BOX(box), menu_bar, FALSE, TRUE, 0);
   //gtk_widget_show(menu_bar);
   // Create the menus
   GtkWidget* file_item = gtk_menu_item_new_with_label("File");
   gtk_widget_show(file_item);
   gtk_menu_item_set_submenu(GTK_MENU_ITEM(file_item), file_menu);
   // Add the menus to the menu bar
   gtk_menu_shell_append(GTK_MENU_SHELL(menu_bar), file_item);
}

/*
 * openFile()
 * ---------------------
 * Opens the file chooser dialog and opens that file
 */
void openFile(GtkWidget* window, gpointer callbackData)
{
  GtkWidget* dialog;
  GtkFileChooserAction action = GTK_FILE_CHOOSER_ACTION_OPEN;
  gint res;

  dialog = gtk_file_chooser_dialog_new("Open File", GTK_WINDOW(gtk_widget_get_toplevel(window)), action, "Cancel", GTK_RESPONSE_CANCEL, "Open", GTK_RESPONSE_ACCEPT, NULL);
  res = gtk_dialog_run(GTK_DIALOG(dialog));
  if (res == GTK_RESPONSE_ACCEPT)
  {
    GtkFileChooser *chooser = GTK_FILE_CHOOSER(dialog);
    char *filename = gtk_file_chooser_get_filename(chooser);
    string newFileUri = "file://";
    newFileUri += filename;

    // Implementation of opening a file
  }

  gtk_widget_destroy(dialog);
}

void initialize_web_extensions(WebKitWebContext* context, gpointer userData)
{
  static guint uniqueId = 0;
  webkit_web_context_set_web_extensions_directory(context, WEB_EXTENSIONS_DIR);
  webkit_web_context_set_web_extensions_initialization_user_data(context, g_variant_new_uint32(uniqueId++));
}
