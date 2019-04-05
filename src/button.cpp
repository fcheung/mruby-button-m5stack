#include <M5Stack.h>

#include "mruby.h"
#include "mruby/class.h"
#include "mruby/variable.h"

#ifdef __cplusplus
extern "C" {
#endif

/* Button objects */
static Button * _btn[] = {
  &M5.BtnA, // A: left 
  &M5.BtnB, // B: center
  &M5.BtnC  // C: right
};

static mrb_value
mrb_btn_init(mrb_state *mrb, mrb_value self)
{
  mrb_int btn_id;
  mrb_get_args(mrb, "i", &btn_id);
  if (btn_id < 0 || btn_id >= 3) {
    mrb_raisef(mrb, E_ARGUMENT_ERROR, "illegal button ID %S", mrb_fixnum_value(btn_id));
  }
  mrb_iv_set(mrb, self, mrb_intern_lit(mrb, "@id"), mrb_fixnum_value(btn_id));
  return self;
}

static mrb_value
mrb_btn_is_pressed(mrb_state *mrb, mrb_value self)
{
  mrb_value oid;
  uint8_t b;

  oid = mrb_iv_get(mrb, self, mrb_intern_lit(mrb, "@id"));
  M5.update();
  b = _btn[mrb_fixnum(oid)]->isPressed();
  return mrb_bool_value(b != 0);
}

static mrb_value
mrb_btn_is_released(mrb_state *mrb, mrb_value self)
{
  mrb_value oid;
  uint8_t b;

  oid = mrb_iv_get(mrb, self, mrb_intern_lit(mrb, "@id"));
  M5.update();
  b = _btn[mrb_fixnum(oid)]->isReleased();
  return mrb_bool_value(b != 0);
}

void
mrb_mruby_button_m5stack_gem_init(mrb_state *mrb)
{
  // Button class
  struct RClass *btn = mrb_define_class(mrb, "Button", mrb->object_class);

  // instance methods
  mrb_define_method(mrb, btn, "initialize", mrb_btn_init, MRB_ARGS_REQ(1));
  mrb_define_method(mrb, btn, "pressed?",   mrb_btn_is_pressed, MRB_ARGS_NONE());
  mrb_define_method(mrb, btn, "released?",  mrb_btn_is_released, MRB_ARGS_NONE());
}

void
mrb_mruby_button_m5stack_gem_final(mrb_state *mrb)
{
}

#ifdef __cplusplus
}
#endif
