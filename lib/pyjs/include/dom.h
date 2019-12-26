#ifndef PY_DOM
#define PY_DOM

#include <Python.h>
#include <structmember.h>
#include <jsc/jsc.h>

typedef struct
{
  PyObject_HEAD
  JSCValue* JSCV; // The JSC value of the struct
} DOM;

class PyDOM
{
public:
  static PyObject* invokeMethod(DOM* self, PyObject* args, const char* methName);
  // Custom functions, see https://api.jquery.com/ for more information
  static PyObject* add(DOM* self, PyObject* args);
  static PyObject* addBack(DOM* self, PyObject* args);
  static PyObject* addClass(DOM* self, PyObject* args);
  static PyObject* after(DOM* self, PyObject* args);
  static PyObject* ajaxComplete(DOM* self, PyObject* args);
  static PyObject* ajaxError(DOM* self, PyObject* args);
  static PyObject* ajaxSend(DOM* self, PyObject* args);
  static PyObject* ajaxStart(DOM* self, PyObject* args);
  static PyObject* ajaxStop(DOM* self, PyObject* args);
  static PyObject* ajaxSuccess(DOM* self, PyObject* args);
  static PyObject* animate(DOM* self, PyObject* args);
  static PyObject* append(DOM* self, PyObject* args);
  static PyObject* appendTo(DOM* self, PyObject* args);
  static PyObject* attr(DOM* self, PyObject* args);
  static PyObject* before(DOM* self, PyObject* args);
  static PyObject* bind(DOM* self, PyObject* args);
  static PyObject* blur(DOM* self, PyObject* args);
  static PyObject* change(DOM* self, PyObject* args);
  static PyObject* children(DOM* self, PyObject* args);
  static PyObject* clearQueue(DOM* self, PyObject* args);
  static PyObject* click(DOM* self, PyObject* args);
  static PyObject* clone(DOM* self, PyObject* args);
  static PyObject* closest(DOM* self, PyObject* args);
  static PyObject* contents(DOM* self, PyObject* args);
  static PyObject* contextmenu(DOM* self, PyObject* args);
  static PyObject* css(DOM* self, PyObject* args);
  static PyObject* data(DOM* self, PyObject* args);
  static PyObject* dblclick(DOM* self, PyObject* args);
  static PyObject* delay(DOM* self, PyObject* args);
  static PyObject* delegate(DOM* self, PyObject* args);
  static PyObject* dequeue(DOM* self, PyObject* args);
  static PyObject* detach(DOM* self, PyObject* args);
  static PyObject* each(DOM* self, PyObject* args);
  static PyObject* empty(DOM* self, PyObject* args);
  static PyObject* end(DOM* self, PyObject* args);
  static PyObject* eq(DOM* self, PyObject* args);
  static PyObject* fadeIn(DOM* self, PyObject* args);
  static PyObject* fadeOut(DOM* self, PyObject* args);
  static PyObject* fadeTo(DOM* self, PyObject* args);
  static PyObject* fadeToggle(DOM* self, PyObject* args);
  static PyObject* filter(DOM* self, PyObject* args);
  static PyObject* find(DOM* self, PyObject* args);
  static PyObject* finish(DOM* self, PyObject* args);
  static PyObject* first(DOM* self, PyObject* args);
  static PyObject* focus(DOM* self, PyObject* args);
  static PyObject* focusin(DOM* self, PyObject* args);
  static PyObject* focusout(DOM* self, PyObject* args);
  static PyObject* get(DOM* self, PyObject* args);
  static PyObject* has(DOM* self, PyObject* args);
  static PyObject* hasClass(DOM* self, PyObject* args);
  static PyObject* height(DOM* self, PyObject* args);
  static PyObject* hide(DOM* self, PyObject* args);
  static PyObject* hover(DOM* self, PyObject* args);
  static PyObject* html(DOM* self, PyObject* args);
  static PyObject* index(DOM* self, PyObject* args);
  static PyObject* innerHeight(DOM* self, PyObject* args);
  static PyObject* innerWidth(DOM* self, PyObject* args);
  static PyObject* insertAfter(DOM* self, PyObject* args);
  static PyObject* insertBefore(DOM* self, PyObject* args);
  static PyObject* is(DOM* self, PyObject* args);
  static PyObject* keydown(DOM* self, PyObject* args);
  static PyObject* keypress(DOM* self, PyObject* args);
  static PyObject* keyup(DOM* self, PyObject* args);
  static PyObject* last(DOM* self, PyObject* args);
  static PyObject* load(DOM* self, PyObject* args);
  static PyObject* map(DOM* self, PyObject* args);
  static PyObject* mousedown(DOM* self, PyObject* args);
  static PyObject* mouseenter(DOM* self, PyObject* args);
  static PyObject* mouseleave(DOM* self, PyObject* args);
  static PyObject* mousemove(DOM* self, PyObject* args);
  static PyObject* mouseout(DOM* self, PyObject* args);
  static PyObject* mouseover(DOM* self, PyObject* args);
  static PyObject* mouseup(DOM* self, PyObject* args);
  static PyObject* next(DOM* self, PyObject* args);
  static PyObject* nextAll(DOM* self, PyObject* args);
  static PyObject* nextUntil(DOM* self, PyObject* args);
  static PyObject* isnot(DOM* self, PyObject* args); // same as jQuery .not()
  static PyObject* off(DOM* self, PyObject* args);
  static PyObject* offset(DOM* self, PyObject* args);
  static PyObject* offsetParent(DOM* self, PyObject* args);
  static PyObject* on(DOM* self, PyObject* args);
  static PyObject* one(DOM* self, PyObject* args);
  static PyObject* outerHeight(DOM* self, PyObject* args);
  static PyObject* outerWidth(DOM* self, PyObject* args);
  static PyObject* parent(DOM* self, PyObject* args);
  static PyObject* parents(DOM* self, PyObject* args);
  static PyObject* parentsUntil(DOM* self, PyObject* args);
  static PyObject* position(DOM* self, PyObject* args);
  static PyObject* prepend(DOM* self, PyObject* args);
  static PyObject* prependTo(DOM* self, PyObject* args);
  static PyObject* prev(DOM* self, PyObject* args);
  static PyObject* prevAll(DOM* self, PyObject* args);
  static PyObject* prevUntil(DOM* self, PyObject* args);
  static PyObject* promise(DOM* self, PyObject* args);
  static PyObject* prop(DOM* self, PyObject* args);
  static PyObject* pushStack(DOM* self, PyObject* args);
  static PyObject* queue(DOM* self, PyObject* args);
  static PyObject* ready(DOM* self, PyObject* args);
  static PyObject* remove(DOM* self, PyObject* args);
  static PyObject* removeAttr(DOM* self, PyObject* args);
  static PyObject* removeClass(DOM* self, PyObject* args);
  static PyObject* removeData(DOM* self, PyObject* args);
  static PyObject* removeProp(DOM* self, PyObject* args);
  static PyObject* replaceAll(DOM* self, PyObject* args);
  static PyObject* replaceWith(DOM* self, PyObject* args);
  static PyObject* resize(DOM* self, PyObject* args);
  static PyObject* scroll(DOM* self, PyObject* args);
  static PyObject* scrollLeft(DOM* self, PyObject* args);
  static PyObject* scrollTop(DOM* self, PyObject* args);
  static PyObject* select(DOM* self, PyObject* args);
  static PyObject* serialize(DOM* self, PyObject* args);
  static PyObject* serializeArray(DOM* self, PyObject* args);
  static PyObject* show(DOM* self, PyObject* args);
  static PyObject* siblings(DOM* self, PyObject* args);
  static PyObject* slice(DOM* self, PyObject* args);
  static PyObject* slideDown(DOM* self, PyObject* args);
  static PyObject* slideToggle(DOM* self, PyObject* args);
  static PyObject* slideUp(DOM* self, PyObject* args);
  static PyObject* stop(DOM* self, PyObject* args);
  static PyObject* submit(DOM* self, PyObject* args);
  static PyObject* text(DOM* self, PyObject* args);
  static PyObject* toArray(DOM* self, PyObject* args);
  static PyObject* toggle(DOM* self, PyObject* args);
  static PyObject* toggleClass(DOM* self, PyObject* args);
  static PyObject* trigger(DOM* self, PyObject* args);
  static PyObject* triggerHandler(DOM* self, PyObject* args);
  static PyObject* unbind(DOM* self, PyObject* args);
  static PyObject* undelegate(DOM* self, PyObject* args);
  static PyObject* unwrap(DOM* self, PyObject* args);
  static PyObject* val(DOM* self, PyObject* args);
  static PyObject* width(DOM* self, PyObject* args);
  static PyObject* wrap(DOM* self, PyObject* args);
  static PyObject* wrapAll(DOM* self, PyObject* args);
  static PyObject* wrapInner(DOM* self, PyObject* args);

  /* Properties visible with enumerate properties but not in jQuery API
  static PyObject* push(DOM* self, PyObject* args);
  static PyObject* sort(DOM* self, PyObject* args);
  static PyObject* splice(DOM* self, PyObject* args);
  static PyObject* extend(DOM* self, PyObject* args);
  static PyObject* init(DOM* self, PyObject* args);
  */

  // Variables
  static PyMemberDef members[];
  static PyTypeObject TypeObj;
  static PyMethodDef methods[];

  // Default functions
  static void __dealloc__(DOM* self);
private:
  PyDOM(); // This class shouldn't be initialized
};

#endif
