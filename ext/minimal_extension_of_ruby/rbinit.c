#include "ruby.h"

/*
 * #include "minimal_extension_of_ruby.h"
 */

void Init_minimal_extension_of_ruby(void)
{
  VALUE cMinimalExtensionOfRuby = rb_define_class("MinimalExtensionOfRuby", rb_cObject);

  MinimalExtensionOfRuby_class_init(cMinimalExtensionOfRuby);
}
