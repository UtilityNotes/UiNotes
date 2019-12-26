CXX = clang++
SRCS = src/*.cpp
CXXFLAGS = -I./include

WEBKITCXXFLAGS = -pthread -I/usr/include/webkitgtk-4.0 -I/usr/include/gtk-3.0 -I/usr/include/at-spi2-atk/2.0 -I/usr/include/at-spi-2.0 -I/usr/include/dbus-1.0 -I/usr/lib/x86_64-linux-gnu/dbus-1.0/include -I/usr/include/gtk-3.0 -I/usr/include/gio-unix-2.0/ -I/usr/include/cairo -I/usr/include/pango-1.0 -I/usr/include/harfbuzz -I/usr/include/pango-1.0 -I/usr/include/atk-1.0 -I/usr/include/cairo -I/usr/include/pixman-1 -I/usr/include/freetype2 -I/usr/include/libpng16 -I/usr/include/freetype2 -I/usr/include/libpng16 -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/libpng16 -I/usr/include/libsoup-2.4 -I/usr/include/libxml2 -I/usr/include/webkitgtk-4.0 -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include
WEBKITLDFLAGS = -lwebkit2gtk-4.0 -lgtk-3 -lgdk-3 -lpangocairo-1.0 -lpango-1.0 -latk-1.0 -lcairo-gobject -lcairo -lgdk_pixbuf-2.0 -lsoup-2.4 -lgio-2.0 -ljavascriptcoregtk-4.0 -lgobject-2.0 -lglib-2.0

PYCFLAGS     = -I/usr/include/python3.6m -I/usr/include/python3.6m -Wno-unused-result -Wsign-compare -g -fdebug-prefix-map=/build/python3.6-PEMn0O/python3.6-3.6.8=. -fstack-protector -Wformat -Werror=format-security  -DNDEBUG -g -fwrapv -O3 -Wall
PYLDFLAGS    = -L/usr/lib/python3.6/config-3.6m-x86_64-linux-gnu -L/usr/lib -lpython3.6m -lpthread -ldl  -lutil -lm  -Xlinker -export-dynamic -Wl,-O1 -Wl,-Bsymbolic-functions

main:
	$(CXX) -g -Wall -fPIC -c  $(CXXFLAGS) $(WEBKITCXXFLAGS) $(PYCFLAGS) $(SRCS)
	$(CXX) -shared -Wl,-soname,libpyjs.so.1 -o libpyjs.so.1.0 *.o $(PYLDFLAGS) $(WEBKITLDFLAGS) -Wl,-z,defs
	ln -sf libpyjs.so.1.0 libpyjs.so.1
	ln -sf libpyjs.so.1 libpyjs.so
	rm *.o

	mv libpyjs.so bin
	mv libpyjs.so.1 bin
	mv libpyjs.so.1.0 bin

remove:
	rm libpyjs.so.1.0
