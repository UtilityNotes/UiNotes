CXX = clang++
SRCS = src/*.cpp

CXXFLAGS = -I./include -I../pyjs/include
LDFLAGS = -lpyjs -L../pyjs/bin -Wl,-rpath='$$ORIGIN/../../pyjs/bin'

WEBKITCXXFLAGS = -pthread -I/usr/include/webkitgtk-4.0 -I/usr/include/gtk-3.0 -I/usr/include/at-spi2-atk/2.0 -I/usr/include/at-spi-2.0 -I/usr/include/dbus-1.0 -I/usr/lib/x86_64-linux-gnu/dbus-1.0/include -I/usr/include/gtk-3.0 -I/usr/include/gio-unix-2.0/ -I/usr/include/cairo -I/usr/include/pango-1.0 -I/usr/include/harfbuzz -I/usr/include/pango-1.0 -I/usr/include/atk-1.0 -I/usr/include/cairo -I/usr/include/pixman-1 -I/usr/include/freetype2 -I/usr/include/libpng16 -I/usr/include/freetype2 -I/usr/include/libpng16 -I/usr/include/gdk-pixbuf-2.0 -I/usr/include/libpng16 -I/usr/include/libsoup-2.4 -I/usr/include/libxml2 -I/usr/include/webkitgtk-4.0 -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include
WEBKITLDFLAGS = -lwebkit2gtk-4.0 -lgtk-3 -lgdk-3 -lpangocairo-1.0 -lpango-1.0 -latk-1.0 -lcairo-gobject -lcairo -lgdk_pixbuf-2.0 -lsoup-2.4 -lgio-2.0 -ljavascriptcoregtk-4.0 -lgobject-2.0 -lglib-2.0

PYCFLAGS     = -I/usr/include/python3.6m -I/usr/include/python3.6m -Wno-unused-result -Wsign-compare -g -fdebug-prefix-map=/build/python3.6-PEMn0O/python3.6-3.6.8=. -fstack-protector -Wformat -Werror=format-security  -DNDEBUG -g -fwrapv -O3 -Wall

main:
	$(CXX) -g -Wall -fPIC -c $(CXXFLAGS) $(WEBKITCXXFLAGS) $(PYCFLAGS) $(SRCS)
	$(CXX) -shared -Wl,-soname,libwebextension.so.1 -o libwebextension.so.1.0 *.o $(WEBKITLDFLAGS) $(LDFLAGS) -Wl,-z,defs
	ln -sf libwebextension.so.1.0 libwebextension.so.1
	ln -sf libwebextension.so.1 libwebextension.so
	rm *.o

	mv libwebextension.so bin
	mv libwebextension.so.1 bin
	mv libwebextension.so.1.0 bin

remove:
	rm libwebextension.so.1.0
