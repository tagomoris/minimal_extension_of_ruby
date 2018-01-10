#include "minimal_extension_of_ruby.h"

VALUE cMinimalExtensionOfRuby;

struct minimalext_internal_t {
  VALUE hash;
};
typedef struct minimalext_internal_t minimalext_internal_t;

struct minimalext_t {
  minimalext_internal_t internal;
  bool a;
};
typedef struct minimalext_t minimalext_t;

#define MINIMALEXT(from, name) \
  minimalext_t *name = NULL; \
  Data_Get_Struct(from, minimalext_t, name); \
  if(name == NULL) { \
    rb_raise(rb_eArgError, "NULL found for " # name " when shouldn't be."); \
  }

static void MinimalExtensionOfRuby_free(minimalext_t* m)
{
  if (m == NULL) {
    return;
  }
  xfree(m);
}

void MinimalExtensionOfRuby_mark(minimalext_t* m)
{
  rb_gc_mark(m->internal.hash);
}

static VALUE MinimalExtensionOfRuby_alloc(VALUE klass)
{
  minimalext_t* m = ZALLOC_N(minimalext_t, 1);
  m->internal.hash = rb_hash_new();
  VALUE self = Data_Wrap_Struct(klass, MinimalExtensionOfRuby_mark, MinimalExtensionOfRuby_free, m);
  return self;
}

static VALUE MinimalExtensionOfRuby_initialize(int argc, VALUE* argv, VALUE self)
{
  MINIMALEXT(self, m);

  rb_hash_aset(m->internal.hash, rb_str_new2("yay"), rb_str_new2("boo"));
  m->a = false;

  return Qnil;
}

VALUE MinimalExtensionOfRuby_foo(int argc, VALUE* argv, VALUE self)
{
  MINIMALEXT(self, m);

  return rb_hash_aref(m->internal.hash, rb_str_new2("yay"));
}

void MinimalExtensionOfRuby_class_init(VALUE cMinimalExtensionOfRuby)
{
  rb_define_alloc_func(cMinimalExtensionOfRuby, MinimalExtensionOfRuby_alloc);

  rb_define_method(cMinimalExtensionOfRuby, "initialize", MinimalExtensionOfRuby_initialize, -1);

  rb_define_method(cMinimalExtensionOfRuby, "foo", MinimalExtensionOfRuby_foo, -1);
}

