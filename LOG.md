# Progress Log
This is the weekly update of the progress made on UiNotes, which is updated every Saturday.

This is a general progress log. It contains the item that was completed and who completed that item. More detailed changes can be found by viewing the commits.

For further clarification, this progress log will pertain to anything involing UiNotes, not just this repository.

General References:
* GTK+ 3: https://developer.gnome.org/gtk3/stable/
* WebKitGTK: https://webkitgtk.org/reference/webkit2gtk/stable/index.html
----------------------

## November 9th, 2019, End of week 11
1. Progress on main app (Linux)
  * Python can call functions with parameters: **Mister Mjir**
  * CSS function added: **Mister Mjir**
  * Factory function (Python DOM object can only be added from C++ factory function): **Mister Mjir**

----------------------

## November 2nd, 2019, End of week 10
1. Progress made on main app (Linux)
  * Python can now call JS (jQuery) functions without parameters (html is the only function for now): **Mister Mjir**
  
----------------------

## October 26th, 2019, End of week 9
1. No progress made

----------------------

## October 19th, 2019, End of Week 8
1. Progress made on main app (Linux)
  * Cleaned up extension code: **Mister Mjir**
    * Separated Python stuff from webkit stuff
    * Made pyjs library neater by breaking up code into multiple files
		
----------------------

## October 12th, 2019, End of Week 7
1. Progress made on main app (Linux)
  * Javascript can be executed in C++: **Mister Mjir**
  * Python can execute Javascript: **Mister Mjir**
    * Python can store numeric, boolean, and string values from executing JS

References:
  * Extending Python: https://docs.python.org/3/extending/extending.html
  
----------------------

## October 5th, 2019, End of Week 6
1. Progress made on main app (Linux)
  * Extension now showing the uri: **Mister Mjir**
  
----------------------

## September 28th, 2019- End of Week 5
1. Progress made on main app (Linux)
  * Most likely going to keep original python idea
  * The extension is found and loaded, does not work correctly
2. Research done on build systems
  * Most likely going to use CMake

References:
 * Shared Library Guides:
  * http://www.yolinux.com/TUTORIALS/LibraryArchives-StaticAndDynamic.html
  * http://www.tldp.org/HOWTO/Program-Library-HOWTO/shared-libraries.html
 * Makefile Reference: https://www.tutorialspoint.com/makefile/makefile_quick_guide.htm
 
----------------------

## September 21st, 2019- End of Week 4
1. Status update on main app (On Linux)
  * Most likely switching from python modules to js modules
    * Will try to make a js module that will make python work
  * Trying to get Javascript API to work

References:
  * WebKit2GTK+ Web Extensions: https://blogs.igalia.com/carlosgc/2013/09/10/webkit2gtk-web-process-extensions/

----------------------

## September 14th, 2019- End of Week 3
1. Progress made on main app (On Linux)
  * Added menu bar: **Mister Mjir**
  * Can open up any file (except images) as text, HTML is rendered as it usually is: **Mister Mjir**
2. Repository changes
  * Deleted "coding" branch, now "c++" and "python" branches: **Mister Mjir**

References:
  * Creating a menu: https://developer.gnome.org/gtk-tutorial/stable/c1499.html
  * Opening a file: https://developer.gnome.org/gtk3/stable/GtkFileChooserDialog.html

----------------------

## September 7th, 2019- End of Week 2
1. Some prototypes finished
  * Android text editor: **harkyboi**
  * iOS / MacOS drawing app: **GG**
2. Progress made on main app (On Linux)
  * Able to render HTML files with CSS: **Mister Mjir**
  * Able to run Python files and allow Python to access the API through import: **Mister Mjir**

References:
  * Using WebKit to render HTML: https://wiki.gnome.org/Projects/WebKitGtk/ProgrammingGuide
  * Integrating Python and C++: https://docs.python.org/3/extending/embedding.html

----------------------

## August 31st, 2019- End of Week 1
1. Split up Jobs
  * Documentation: **XeroxSin**
  * Design/Ui: **GG and Mister Mjir**
    * Logo design: **Mister Mjir**
  * Boss: **harkyboi**
  * Coding (Source code and modules): **XeroxSin and Mister Mjir**
    * Windows Port: **harkyboi**
    * Linux Port: **Mister Mjir**
    * MacOS Port: **GG**
    * Android Port: **harkyboi**
    * iOS Port: **GG**
2. Finished Logos for multiple themes: **Mister Mjir**
  * [x] Gradient
  * [x] Solid
  * [ ] Inverse (Solid)
