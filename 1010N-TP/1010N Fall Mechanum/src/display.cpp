#include "main.h"
#include "display.h"
using namespace pros;


void disableTask_fn(void*param)
{

  /*Create a Tab view object*/
  lv_obj_t *tabview;
  tabview = lv_tabview_create(lv_scr_act(), NULL);

  /*Add 3 tabs (the tabs are page (lv_page) and can be scrolled*/
  lv_obj_t *tab1 = lv_tabview_add_tab(tabview, "Autos");
  lv_obj_t *tab2 = lv_tabview_add_tab(tabview, "Sensors");
  lv_obj_t *tab3 = lv_tabview_add_tab(tabview, "Motors");

  /*Create styles for the switch*/
  static lv_style_t bg_style;
  static lv_style_t indic_style;
  static lv_style_t knob_on_style;
  static lv_style_t knob_off_style;
  lv_style_copy(&bg_style, &lv_style_pretty);
  bg_style.body.radius = LV_RADIUS_CIRCLE;

  lv_style_copy(&indic_style, &lv_style_pretty_color);
  indic_style.body.radius = LV_RADIUS_CIRCLE;
  indic_style.body.main_color = LV_COLOR_HEX(0x9fc8ef);
  indic_style.body.grad_color = LV_COLOR_HEX(0x9fc8ef);
  indic_style.body.padding.hor = 0;
  indic_style.body.padding.ver = 0;

  lv_style_copy(&knob_off_style, &lv_style_pretty);
  knob_off_style.body.radius = LV_RADIUS_CIRCLE;
  knob_off_style.body.shadow.width = 4;
  knob_off_style.body.shadow.type = LV_SHADOW_BOTTOM;

  lv_style_copy(&knob_on_style, &lv_style_pretty_color);
  knob_on_style.body.radius = LV_RADIUS_CIRCLE;
  knob_on_style.body.shadow.width = 4;
  knob_on_style.body.shadow.type = LV_SHADOW_BOTTOM;

  /*Create a switch and apply the styles*/
  lv_obj_t *sw1 = lv_sw_create(tab3, NULL);
  lv_sw_set_style(sw1, LV_SW_STYLE_BG, &bg_style);
  lv_sw_set_style(sw1, LV_SW_STYLE_INDIC, &indic_style);
  lv_sw_set_style(sw1, LV_SW_STYLE_KNOB_ON, &knob_on_style);
  lv_sw_set_style(sw1, LV_SW_STYLE_KNOB_OFF, &knob_off_style);
  lv_obj_set_size(sw1, 75, 35);						/*Button size*/
  lv_obj_align(sw1, NULL, LV_ALIGN_IN_TOP_RIGHT, -150, 0);

  /*Copy the first switch and turn it ON*/
  lv_obj_t *sw2 = lv_sw_create(tab3 , sw1);
  lv_obj_align(sw2, NULL, LV_ALIGN_IN_TOP_RIGHT, -150, -45);

  /*Copy the first switch and turn it ON*/
  lv_obj_t *sw3 = lv_sw_create(tab3, sw2);
  lv_obj_align(sw3, NULL, LV_ALIGN_IN_TOP_RIGHT, -150, -45);


  /*
    lcd::initialize();

    int btn_time = 100;
    int myauto = 0;
    lcd::clear();

    while(true)
    {

    lcd::print(1, "Auto %d", myauto);

      if(lcd::read_buttons() == LCD_BTN_CENTER)
      {

      } //END if(lcd::read_buttons == CENTER)

      if(lcd::read_buttons() == LCD_BTN_LEFT)
      {
        lcd::clear();
        lcd::set_text(1, "Please Wait...");
        delay(btn_time);
        myauto = myauto - 1;
      } //END if(lcd::read_buttons == LEFT)

      if(lcd::read_buttons() == LCD_BTN_RIGHT)
      {
        lcd::clear();
        lcd::set_text(1, "Please Wait...");
        delay(btn_time);
        myauto = myauto + 1;
      } //END if(lcd::read_buttons == RIGHT)

    } //END while(true)
  */

} //END void disableTask_fn
