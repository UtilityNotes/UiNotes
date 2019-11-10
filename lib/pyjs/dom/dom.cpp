#include "dom.h"
#include <iostream>

/* PyObject Definition Stuff */
PyMemberDef PyDOM::members[] =
{
  {NULL}
};

PyTypeObject PyDOM::TypeObj =
{
  PyVarObject_HEAD_INIT(NULL, 0)
  .tp_name = "js.DOM",
  .tp_doc = "Python DOM Objects",
  .tp_basicsize = sizeof(DOM),
  .tp_itemsize = 0,
  .tp_flags = Py_TPFLAGS_DEFAULT,
  .tp_new = NULL,
  .tp_init = NULL,
  .tp_dealloc = (destructor) PyDOM::__dealloc__,
  .tp_members = PyDOM::members,
  .tp_methods = PyDOM::methods,
};

PyMethodDef PyDOM::methods[] =
{
  {"add", (PyCFunction) PyDOM::add, METH_VARARGS, "https://api.jquery.com/add/"},
  {"addBack", (PyCFunction) PyDOM::addBack, METH_VARARGS, "https://api.jquery.com/addBack/"},
  {"addClass", (PyCFunction) PyDOM::addClass, METH_VARARGS, "https://api.jquery.com/addClass/"},
  {"after", (PyCFunction) PyDOM::after, METH_VARARGS, "https://api.jquery.com/after/"},
  {"ajaxComplete", (PyCFunction) PyDOM::ajaxComplete, METH_VARARGS, "https://api.jquery.com/ajaxComplete/"},
  {"ajaxError", (PyCFunction) PyDOM::ajaxError, METH_VARARGS, "https://api.jquery.com/ajaxError/"},
  {"ajaxSend", (PyCFunction) PyDOM::ajaxSend, METH_VARARGS, "https://api.jquery.com/ajaxSend/"},
  {"ajaxStart", (PyCFunction) PyDOM::ajaxStart, METH_VARARGS, "https://api.jquery.com/ajaxStart/"},
  {"ajaxStop", (PyCFunction) PyDOM::ajaxStop, METH_VARARGS, "https://api.jquery.com/ajaxStop/"},
  {"ajaxSuccess", (PyCFunction) PyDOM::ajaxSuccess, METH_VARARGS, "https://api.jquery.com/ajaxSuccess/"},
  {"animate", (PyCFunction) PyDOM::animate, METH_VARARGS, "https://api.jquery.com/animate/"},
  {"append", (PyCFunction) PyDOM::append, METH_VARARGS, "https://api.jquery.com/append/"},
  {"appendTo", (PyCFunction) PyDOM::appendTo, METH_VARARGS, "https://api.jquery.com/appendTo/"},
  {"attr", (PyCFunction) PyDOM::attr, METH_VARARGS, "https://api.jquery.com/attr/"},
  {"before", (PyCFunction) PyDOM::before, METH_VARARGS, "https://api.jquery.com/before/"},
  {"bind", (PyCFunction) PyDOM::bind, METH_VARARGS, "https://api.jquery.com/bind/"},
  {"blur", (PyCFunction) PyDOM::blur, METH_VARARGS, "https://api.jquery.com/blur/"},
  {"change", (PyCFunction) PyDOM::change, METH_VARARGS, "https://api.jquery.com/change/"},
  {"children", (PyCFunction) PyDOM::children, METH_VARARGS, "https://api.jquery.com/children/"},
  {"clearQueue", (PyCFunction) PyDOM::clearQueue, METH_VARARGS, "https://api.jquery.com/clearQueue"},
  {"click", (PyCFunction) PyDOM::click, METH_VARARGS, "https://api.jquery.com/click/"},
  {"clone", (PyCFunction) PyDOM::clone, METH_VARARGS, "https://api.jquery.com/clone/"},
  {"closest", (PyCFunction) PyDOM::closest, METH_VARARGS, "https://api.jquery.com/closest/"},
  {"contents", (PyCFunction) PyDOM::contents, METH_VARARGS, "https://api.jquery.com/contents/"},
  {"contextmenu", (PyCFunction) PyDOM::contextmenu, METH_VARARGS, "https://api.jquery.com/contextmenu/"},
  {"css", (PyCFunction) PyDOM::css, METH_VARARGS, "https://api.jquery.com/css/"},
  {"data", (PyCFunction) PyDOM::data, METH_VARARGS, "https://api.jquery.com/data/"},
  {"dblclick", (PyCFunction) PyDOM::dblclick, METH_VARARGS, "https://api.jquery.com/dblclick/"},
  {"delay", (PyCFunction) PyDOM::delay, METH_VARARGS, "https://api.jquery.com/delay/"},
  {"delegate", (PyCFunction) PyDOM::delegate, METH_VARARGS, "https://api.jquery.com/delegate/"},
  {"dequeue", (PyCFunction) PyDOM::dequeue, METH_VARARGS, "https://api.jquery.com/dequeue/"},
  {"detach", (PyCFunction) PyDOM::detach, METH_VARARGS, "https://api.jquery.com/detach/"},
  {"each", (PyCFunction) PyDOM::each, METH_VARARGS, "https://api.jquery.com/each/"},
  {"empty", (PyCFunction) PyDOM::empty, METH_VARARGS, "https://api.jquery.com/empty/"},
  {"end", (PyCFunction) PyDOM::end, METH_VARARGS, "https://api.jquery.com/end/"},
  {"eq", (PyCFunction) PyDOM::eq, METH_VARARGS, "https://api.jquery.com/eq/"},
  {"fadeIn", (PyCFunction) PyDOM::fadeIn, METH_VARARGS, "https://api.jquery.com/fadeIn/"},
  {"fadeOut", (PyCFunction) PyDOM::fadeOut, METH_VARARGS, "https://api.jquery.com/fadeOut/"},
  {"fadeTo", (PyCFunction) PyDOM::fadeTo, METH_VARARGS, "https://api.jquery.com/fadeTo/"},
  {"fadeToggle", (PyCFunction) PyDOM::fadeToggle, METH_VARARGS, "https://api.jquery.com/fadeToggle/"},
  {"filter", (PyCFunction) PyDOM::filter, METH_VARARGS, "https://api.jquery.com/filter/"},
  {"find", (PyCFunction) PyDOM::find, METH_VARARGS, "https://api.jquery.com/find/"},
  {"finish", (PyCFunction) PyDOM::finish, METH_VARARGS, "https://api.jquery.com/finish/"},
  {"first", (PyCFunction) PyDOM::first, METH_VARARGS, "https://api.jquery.com/first/"},
  {"focus", (PyCFunction) PyDOM::focus, METH_VARARGS, "https://api.jquery.com/focus/"},
  {"focusin", (PyCFunction) PyDOM::focusin, METH_VARARGS, "https://api.jquery.com/focusin/"},
  {"focusout", (PyCFunction) PyDOM::focusout, METH_VARARGS, "https://api.jquery.com/focusout/"},
  {"get", (PyCFunction) PyDOM::get, METH_VARARGS, "https://api.jquery.com/get/"},
  {"has", (PyCFunction) PyDOM::has, METH_VARARGS, "https://api.jquery.com/has/"},
  {"hasClass", (PyCFunction) PyDOM::hasClass, METH_VARARGS, "https://api.jquery.com/hasClass/"},
  {"height", (PyCFunction) PyDOM::height, METH_VARARGS, "https://api.jquery.com/height/"},
  {"hide", (PyCFunction) PyDOM::hide, METH_VARARGS, "https://api.jquery.com/hide/"},
  {"hover", (PyCFunction) PyDOM::hover, METH_VARARGS, "https://api.jquery.com/hover/"},
  {"html", (PyCFunction) PyDOM::html, METH_VARARGS, "https://api.jquery.com/html/"},
  {"index", (PyCFunction) PyDOM::index, METH_VARARGS, "https://api.jquery.com/index/"},
  {"innerHeight", (PyCFunction) PyDOM::innerHeight, METH_VARARGS, "https://api.jquery.com/innerHeight/"},
  {"innerWidth", (PyCFunction) PyDOM::innerWidth, METH_VARARGS, "https://api.jquery.com/innerWidth/"},
  {"insertAfter", (PyCFunction) PyDOM::insertAfter, METH_VARARGS, "https://api.jquery.com/insertAfter/"},
  {"insertBefore", (PyCFunction) PyDOM::insertBefore, METH_VARARGS, "https://api.jquery.com/insertBefore/"},
  {"is", (PyCFunction) PyDOM::is, METH_VARARGS, "https://api.jquery.com/is/"},
  {"keydown", (PyCFunction) PyDOM::keydown, METH_VARARGS, "https://api.jquery.com/keydown/"},
  {"keypress", (PyCFunction) PyDOM::keypress, METH_VARARGS, "https://api.jquery.com/keypress/"},
  {"keyup", (PyCFunction) PyDOM::keyup, METH_VARARGS, "https://api.jquery.com/keyup/"},
  {"last", (PyCFunction) PyDOM::last, METH_VARARGS, "https://api.jquery.com/last/"},
  {"load", (PyCFunction) PyDOM::load, METH_VARARGS, "https://api.jquery.com/load/"},
  {"map", (PyCFunction) PyDOM::map, METH_VARARGS, "https://api.jquery.com/map/"},
  {"mousedown", (PyCFunction) PyDOM::mousedown, METH_VARARGS, "https://api.jquery.com/mousedown/"},
  {"mouseenter", (PyCFunction) PyDOM::mouseenter, METH_VARARGS, "https://api.jquery.com/mouseenter/"},
  {"mouseleave", (PyCFunction) PyDOM::mouseleave, METH_VARARGS, "https://api.jquery.com/mouseleave/"},
  {"mousemove", (PyCFunction) PyDOM::mousemove, METH_VARARGS, "https://api.jquery.com/mousemove/"},
  {"mouseout", (PyCFunction) PyDOM::mouseout, METH_VARARGS, "https://api.jquery.com/mouseout/"},
  {"mouseover", (PyCFunction) PyDOM::mouseover, METH_VARARGS, "https://api.jquery.com/mouseover/"},
  {"mouseup", (PyCFunction) PyDOM::mouseup, METH_VARARGS, "https://api.jquery.com/mouseup/"},
  {"next", (PyCFunction) PyDOM::next, METH_VARARGS, "https://api.jquery.com/next/"},
  {"nextAll", (PyCFunction) PyDOM::nextAll, METH_VARARGS, "https://api.jquery.com/nextAll/"},
  {"nextUntil", (PyCFunction) PyDOM::nextUntil, METH_VARARGS, "https://api.jquery.com/nextUntil/"},
  {"not", (PyCFunction) PyDOM::isnot, METH_VARARGS, "https://api.jquery.com/not/"},
  {"off", (PyCFunction) PyDOM::off, METH_VARARGS, "https://api.jquery.com/off/"},
  {"offset", (PyCFunction) PyDOM::offset, METH_VARARGS, "https://api.jquery.com/offset/"},
  {"offsetParent", (PyCFunction) PyDOM::offsetParent, METH_VARARGS, "https://api.jquery.com/offsetParent/"},
  {"on", (PyCFunction) PyDOM::on, METH_VARARGS, "https://api.jquery.com/on/"},
  {"one", (PyCFunction) PyDOM::one, METH_VARARGS, "https://api.jquery.com/one/"},
  {"outerHeight", (PyCFunction) PyDOM::outerHeight, METH_VARARGS, "https://api.jquery.com/outerHeight/"},
  {"outerWidth", (PyCFunction) PyDOM::outerWidth, METH_VARARGS, "https://api.jquery.com/outerWidth/"},
  {"parent", (PyCFunction) PyDOM::parent, METH_VARARGS, "https://api.jquery.com/parent/"},
  {"parents", (PyCFunction) PyDOM::parents, METH_VARARGS, "https://api.jquery.com/parents/"},
  {"parentsUntil", (PyCFunction) PyDOM::parentsUntil, METH_VARARGS, "https://api.jquery.com/parentsUntil/"},
  {"position", (PyCFunction) PyDOM::position, METH_VARARGS, "https://api.jquery.com/position/"},
  {"prepend", (PyCFunction) PyDOM::prepend, METH_VARARGS, "https://api.jquery.com/prepend/"},
  {"prependTo", (PyCFunction) PyDOM::prependTo, METH_VARARGS, "https://api.jquery.com/prependTo/"},
  {"prev", (PyCFunction) PyDOM::prev, METH_VARARGS, "https://api.jquery.com/prev/"},
  {"prevAll", (PyCFunction) PyDOM::prevAll, METH_VARARGS, "https://api.jquery.com/prevAll/"},
  {"prevUntil", (PyCFunction) PyDOM::prevUntil, METH_VARARGS, "https://api.jquery.com/prevUntil/"},
  {"promise", (PyCFunction) PyDOM::promise, METH_VARARGS, "https://api.jquery.com/promise/"},
  {"prop", (PyCFunction) PyDOM::prop, METH_VARARGS, "https://api.jquery.com/prop/"},
  {"pushStack", (PyCFunction) PyDOM::pushStack, METH_VARARGS, "https://api.jquery.com/pushStack/"},
  {"queue", (PyCFunction) PyDOM::queue, METH_VARARGS, "https://api.jquery.com/queue/"},
  {"ready", (PyCFunction) PyDOM::ready, METH_VARARGS, "https://api.jquery.com/ready/"},
  {"remove", (PyCFunction) PyDOM::remove, METH_VARARGS, "https://api.jquery.com/remove/"},
  {"removeAttr", (PyCFunction) PyDOM::removeAttr, METH_VARARGS, "https://api.jquery.com/removeAttr/"},
  {"removeClass", (PyCFunction) PyDOM::removeClass, METH_VARARGS, "https://api.jquery.com/removeClass/"},
  {"removeData", (PyCFunction) PyDOM::removeData, METH_VARARGS, "https://api.jquery.com/removeData/"},
  {"removeProp", (PyCFunction) PyDOM::removeProp, METH_VARARGS, "https://api.jquery.com/removeProp/"},
  {"replaceAll", (PyCFunction) PyDOM::replaceAll, METH_VARARGS, "https://api.jquery.com/replaceAll/"},
  {"replaceWith", (PyCFunction) PyDOM::replaceWith, METH_VARARGS, "https://api.jquery.com/replaceWith/"},
  {"resize", (PyCFunction) PyDOM::resize, METH_VARARGS, "https://api.jquery.com/resize/"},
  {"scroll", (PyCFunction) PyDOM::scroll, METH_VARARGS, "https://api.jquery.com/scroll/"},
  {"scrollLeft", (PyCFunction) PyDOM::scrollLeft, METH_VARARGS, "https://api.jquery.com/scrollLeft/"},
  {"scrollTop", (PyCFunction) PyDOM::scrollTop, METH_VARARGS, "https://api.jquery.com/scrollTop/"},
  {"select", (PyCFunction) PyDOM::select, METH_VARARGS, "https://api.jquery.com/select/"},
  {"serialize", (PyCFunction) PyDOM::serialize, METH_VARARGS, "https://api.jquery.com/serialize/"},
  {"serializeArray", (PyCFunction) PyDOM::serializeArray, METH_VARARGS, "https://api.jquery.com/serializeArray/"},
  {"show", (PyCFunction) PyDOM::show, METH_VARARGS, "https://api.jquery.com/show/"},
  {"siblings", (PyCFunction) PyDOM::siblings, METH_VARARGS, "https://api.jquery.com/siblings/"},
  {"slice", (PyCFunction) PyDOM::slice, METH_VARARGS, "https://api.jquery.com/slice/"},
  {"slideDown", (PyCFunction) PyDOM::slideDown, METH_VARARGS, "https://api.jquery.com/slideDown/"},
  {"slideToggle", (PyCFunction) PyDOM::slideToggle, METH_VARARGS, "https://api.jquery.com/slideToggle/"},
  {"slideUp", (PyCFunction) PyDOM::slideUp, METH_VARARGS, "https://api.jquery.com/slideUp/"},
  {"stop", (PyCFunction) PyDOM::stop, METH_VARARGS, "https://api.jquery.com/stop/"},
  {"submit", (PyCFunction) PyDOM::submit, METH_VARARGS, "https://api.jquery.com/submit/"},
  {"text", (PyCFunction) PyDOM::text, METH_VARARGS, "https://api.jquery.com/text/"},
  {"toArray", (PyCFunction) PyDOM::toArray, METH_VARARGS, "https://api.jquery.com/toArray/"},
  {"toggle", (PyCFunction) PyDOM::toggle, METH_VARARGS, "https://api.jquery.com/toggle/"},
  {"toggleClass", (PyCFunction) PyDOM::toggleClass, METH_VARARGS, "https://api.jquery.com/toggleClass/"},
  {"trigger", (PyCFunction) PyDOM::trigger, METH_VARARGS, "https://api.jquery.com/trigger/"},
  {"triggerHandler", (PyCFunction) PyDOM::triggerHandler, METH_VARARGS, "https://api.jquery.com/triggerHandler/"},
  {"unbind", (PyCFunction) PyDOM::unbind, METH_VARARGS, "https://api.jquery.com/unbind/"},
  {"undelegate", (PyCFunction) PyDOM::undelegate, METH_VARARGS, "https://api.jquery.com/undelegate/"},
  {"unwrap", (PyCFunction) PyDOM::unwrap, METH_VARARGS, "https://api.jquery.com/unwrap/"},
  {"val", (PyCFunction) PyDOM::val, METH_VARARGS, "https://api.jquery.com/val/"},
  {"width", (PyCFunction) PyDOM::width, METH_VARARGS, "https://api.jquery.com/width/"},
  {"wrap", (PyCFunction) PyDOM::wrap, METH_VARARGS, "https://api.jquery.com/wrap/"},
  {"wrapAll", (PyCFunction) PyDOM::wrapAll, METH_VARARGS, "https://api.jquery.com/wrapAll/"},
  {"wrapInner", (PyCFunction) PyDOM::wrapInner, METH_VARARGS, "https://api.jquery.com/wrapInner"},
  {NULL}
};

void PyDOM::__dealloc__(DOM* self)
{
  Py_TYPE(self)->tp_free((PyObject*) self);
}

/* Custom methods */

// .add()
PyObject* PyDOM::add(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .addBack()
PyObject* PyDOM::addBack(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .addClass()
PyObject* PyDOM::addClass(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .after()
PyObject* PyDOM::after(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}


// .ajaxComplete()
PyObject* PyDOM::ajaxComplete(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .ajaxError()
PyObject* PyDOM::ajaxError(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .ajaxSend()
PyObject* PyDOM::ajaxSend(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .ajaxStart()
PyObject* PyDOM::ajaxStart(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .ajaxStop()
PyObject* PyDOM::ajaxStop(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .ajaxSuccess()
PyObject* PyDOM::ajaxSuccess(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .animate()
PyObject* PyDOM::animate(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .append()
PyObject* PyDOM::append(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .appendTo()
PyObject* PyDOM::appendTo(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .attr()
PyObject* PyDOM::attr(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .before()
PyObject* PyDOM::before(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .bind()
PyObject* PyDOM::bind(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .blur()
PyObject* PyDOM::blur(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .change()
PyObject* PyDOM::change(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .children()
PyObject* PyDOM::children(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .clearQueue()
PyObject* PyDOM::clearQueue(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .click()
PyObject* PyDOM::click(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .clone()
PyObject* PyDOM::clone(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .closest()
PyObject* PyDOM::closest(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .contents()
PyObject* PyDOM::contents(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .contextmenu()
PyObject* PyDOM::contextmenu(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .css()
PyObject* PyDOM::css(DOM* self, PyObject* args)
{
  const char* property;
  const char* value;
  PyArg_ParseTuple(args, "|ss", &property, &value);
  if (property)
  {
    if (value)
    {
      jsc_value_object_invoke_method(self->JSCV, "css", G_TYPE_STRING, property, G_TYPE_STRING, value, G_TYPE_NONE);
      return PyLong_FromLong(0);
    }
    return PyUnicode_FromString(jsc_value_to_string(jsc_value_object_invoke_method(self->JSCV, "css", G_TYPE_STRING, property, G_TYPE_NONE)));
  }
  return PyLong_FromLong(0);
}

// .data()
PyObject* PyDOM::data(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .dblclick()
PyObject* PyDOM::dblclick(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .delay()
PyObject* PyDOM::delay(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .delegate()
PyObject* PyDOM::delegate(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .dequeue()
PyObject* PyDOM::dequeue(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .detach()
PyObject* PyDOM::detach(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .each()
PyObject* PyDOM::each(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .empty()
PyObject* PyDOM::empty(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .end()
PyObject* PyDOM::end(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .eq()
PyObject* PyDOM::eq(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .fadeIn()
PyObject* PyDOM::fadeIn(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .fadeOut()
PyObject* PyDOM::fadeOut(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .fadeTo()
PyObject* PyDOM::fadeTo(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .fadeToggle()
PyObject* PyDOM::fadeToggle(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .filter()
PyObject* PyDOM::filter(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .find()
PyObject* PyDOM::find(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .finish()
PyObject* PyDOM::finish(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .first()
PyObject* PyDOM::first(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .focus()
PyObject* PyDOM::focus(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .focusin()
PyObject* PyDOM::focusin(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .focusout()
PyObject* PyDOM::focusout(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .get()
PyObject* PyDOM::get(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .has()
PyObject* PyDOM::has(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .hasClass()
PyObject* PyDOM::hasClass(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .height()
PyObject* PyDOM::height(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .hide()
PyObject* PyDOM::hide(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .hover()
PyObject* PyDOM::hover(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .html()
PyObject* PyDOM::html(DOM* self, PyObject* args)
{
  const char* string;
  PyArg_ParseTuple(args, "|s", &string);
  if (string)
  {
    jsc_value_object_invoke_method(self->JSCV, "html", G_TYPE_STRING, string, G_TYPE_NONE);
    return PyLong_FromLong(0);
  }
  else
  {
    return PyUnicode_FromString(jsc_value_to_string(jsc_value_object_invoke_method(self->JSCV, "html", G_TYPE_NONE)));
  }
}

// .index()
PyObject* PyDOM::index(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .innerHeight()
PyObject* PyDOM::innerHeight(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .innerWidth()
PyObject* PyDOM::innerWidth(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .insertAfter()
PyObject* PyDOM::insertAfter(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .insertBefore()
PyObject* PyDOM::insertBefore(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .is()
PyObject* PyDOM::is(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .keydown()
PyObject* PyDOM::keydown(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .keypress()
PyObject* PyDOM::keypress(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .keyup()
PyObject* PyDOM::keyup(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .last()
PyObject* PyDOM::last(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .load()
PyObject* PyDOM::load(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .map()
PyObject* PyDOM::map(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .mousedown()
PyObject* PyDOM::mousedown(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .mouseenter()
PyObject* PyDOM::mouseenter(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .mouseleave()
PyObject* PyDOM::mouseleave(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .mousemove()
PyObject* PyDOM::mousemove(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .mouseout()
PyObject* PyDOM::mouseout(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .mouseover()
PyObject* PyDOM::mouseover(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .mouseup()
PyObject* PyDOM::mouseup(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .next()
PyObject* PyDOM::next(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .nextAll()
PyObject* PyDOM::nextAll(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .nextUntil()
PyObject* PyDOM::nextUntil(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .isnot()
PyObject* PyDOM::isnot(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .off()
PyObject* PyDOM::off(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .offset()
PyObject* PyDOM::offset(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .offsetParent()
PyObject* PyDOM::offsetParent(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .on()
PyObject* PyDOM::on(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .one()
PyObject* PyDOM::one(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .outerHeight()
PyObject* PyDOM::outerHeight(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .outerWidth()
PyObject* PyDOM::outerWidth(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .parent()
PyObject* PyDOM::parent(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .parents()
PyObject* PyDOM::parents(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .parentsUntil()
PyObject* PyDOM::parentsUntil(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .position()
PyObject* PyDOM::position(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .prepend()
PyObject* PyDOM::prepend(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .prependTo()
PyObject* PyDOM::prependTo(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .prev()
PyObject* PyDOM::prev(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .prevAll()
PyObject* PyDOM::prevAll(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .prevUntil()
PyObject* PyDOM::prevUntil(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .promise()
PyObject* PyDOM::promise(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .prop()
PyObject* PyDOM::prop(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .pushStack()
PyObject* PyDOM::pushStack(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .queue()
PyObject* PyDOM::queue(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .ready()
PyObject* PyDOM::ready(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .remove()
PyObject* PyDOM::remove(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .removeAttr()
PyObject* PyDOM::removeAttr(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .removeClass()
PyObject* PyDOM::removeClass(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .removeData()
PyObject* PyDOM::removeData(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .removeProp()
PyObject* PyDOM::removeProp(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .replaceAll()
PyObject* PyDOM::replaceAll(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .replaceWith()
PyObject* PyDOM::replaceWith(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .resize()
PyObject* PyDOM::resize(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .scroll()
PyObject* PyDOM::scroll(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .scrollLeft()
PyObject* PyDOM::scrollLeft(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .scrollTop()
PyObject* PyDOM::scrollTop(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .select()
PyObject* PyDOM::select(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .serialize()
PyObject* PyDOM::serialize(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .serializeArray()
PyObject* PyDOM::serializeArray(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .show()
PyObject* PyDOM::show(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .siblings()
PyObject* PyDOM::siblings(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .slice()
PyObject* PyDOM::slice(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .slideDown()
PyObject* PyDOM::slideDown(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .slideToggle()
PyObject* PyDOM::slideToggle(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .slideUp()
PyObject* PyDOM::slideUp(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .stop()
PyObject* PyDOM::stop(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .submit()
PyObject* PyDOM::submit(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .text()
PyObject* PyDOM::text(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .toArray()
PyObject* PyDOM::toArray(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .toggle()
PyObject* PyDOM::toggle(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .toggleClass()
PyObject* PyDOM::toggleClass(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .trigger()
PyObject* PyDOM::trigger(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .triggerHandler()
PyObject* PyDOM::triggerHandler(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .unbind()
PyObject* PyDOM::unbind(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .undelegate()
PyObject* PyDOM::undelegate(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .unwrap()
PyObject* PyDOM::unwrap(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .val()
PyObject* PyDOM::val(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .width()
PyObject* PyDOM::width(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .wrap()
PyObject* PyDOM::wrap(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .wrapAll()
PyObject* PyDOM::wrapAll(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}

// .wrapInner()
PyObject* PyDOM::wrapInner(DOM* self, PyObject* args)
{
  return PyLong_FromLong(0);
}
