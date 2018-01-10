#include <stdbool.h>
#include "ruby.h"
#include "ruby/st.h"
#include "ruby/encoding.h"

#ifndef MINIMALEXT_CLASSH_H__
#define MINIMALEXT_CLASSH_H__

extern VALUE cMinimalExtensionOfRuby;

extern VALUE MinimalExtensionOfRuby_foo(int argc, VALUE* argv, VALUE self);

void MinimalExtensionOfRuby_class_init(VALUE cMinimalExtensionOfRuby);

#endif
