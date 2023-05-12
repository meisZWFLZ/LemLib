// SquareLine LVGL GENERATED FILE
// EDITOR VERSION: SquareLine Studio 1.2.1
// LVGL VERSION: 8.3.3
// PROJECT: LemLib UI v0.1.0

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////
lv_obj_t * ui_Screen1;
lv_obj_t * ui_Image2;
lv_obj_t * ui_Label2;
lv_obj_t * ui_Label1;
lv_obj_t * ui_Label3;
lv_obj_t * ui_Label4;
lv_obj_t * ui_Label5;
lv_obj_t * ui_Label6;
lv_obj_t * ui_Label7;
lv_obj_t * ui_Label9;
lv_obj_t * ui_Image1;
lv_obj_t * ui_Image3;
lv_obj_t * ui_Image4;

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 32
    #error "LV_COLOR_DEPTH should be 32bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=0
    #error "LV_COLOR_16_SWAP should be 0 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////

///////////////////// FUNCTIONS ////////////////////

///////////////////// SCREENS ////////////////////
void ui_Screen1_screen_init(void)
{
    ui_Screen1 = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_Screen1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_Screen1, lv_color_hex(0x262626), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Screen1, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Image2 = lv_img_create(ui_Screen1);
    // lv_img_set_src(ui_Image2, &ui_img_field_240x240_png);
    // lv_obj_set_width(ui_Image2, 240);
    // lv_obj_set_height(ui_Image2, 240);
    // lv_obj_set_x(ui_Image2, -120);
    // lv_obj_set_y(ui_Image2, 0);
    // lv_obj_set_align(ui_Image2, LV_ALIGN_CENTER);
    // lv_obj_add_flag(ui_Image2, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    // lv_obj_clear_flag(ui_Image2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    // ui_Label2 = lv_label_create(ui_Screen1);
    // lv_obj_set_width(ui_Label2, LV_SIZE_CONTENT);   /// 1
    // lv_obj_set_height(ui_Label2, LV_SIZE_CONTENT);    /// 1
    // lv_obj_set_x(ui_Label2, 119);
    // lv_obj_set_y(ui_Label2, -84);
    // lv_obj_set_align(ui_Label2, LV_ALIGN_CENTER);
    // lv_label_set_text(ui_Label2, "Odometry");
    // lv_obj_set_style_text_font(ui_Label2, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Label1 = lv_label_create(ui_Screen1);
    // lv_obj_set_width(ui_Label1, LV_SIZE_CONTENT);   /// 1
    // lv_obj_set_height(ui_Label1, LV_SIZE_CONTENT);    /// 1
    // lv_obj_set_x(ui_Label1, 43);
    // lv_obj_set_y(ui_Label1, -37);
    // lv_obj_set_align(ui_Label1, LV_ALIGN_CENTER);
    // lv_label_set_text(ui_Label1, "X");

    // ui_Label3 = lv_label_create(ui_Screen1);
    // lv_obj_set_width(ui_Label3, LV_SIZE_CONTENT);   /// 1
    // lv_obj_set_height(ui_Label3, LV_SIZE_CONTENT);    /// 1
    // lv_obj_set_x(ui_Label3, 43);
    // lv_obj_set_y(ui_Label3, 9);
    // lv_obj_set_align(ui_Label3, LV_ALIGN_CENTER);
    // lv_label_set_text(ui_Label3, "T");

    // ui_Label4 = lv_label_create(ui_Screen1);
    // lv_obj_set_width(ui_Label4, LV_SIZE_CONTENT);   /// 1
    // lv_obj_set_height(ui_Label4, LV_SIZE_CONTENT);    /// 1
    // lv_obj_set_x(ui_Label4, 43);
    // lv_obj_set_y(ui_Label4, -14);
    // lv_obj_set_align(ui_Label4, LV_ALIGN_CENTER);
    // lv_label_set_text(ui_Label4, "Y");

    // ui_Label5 = lv_label_create(ui_Screen1);
    // lv_obj_set_width(ui_Label5, LV_SIZE_CONTENT);   /// 1
    // lv_obj_set_height(ui_Label5, LV_SIZE_CONTENT);    /// 1
    // lv_obj_set_x(ui_Label5, 73);
    // lv_obj_set_y(ui_Label5, -37);
    // lv_obj_set_align(ui_Label5, LV_ALIGN_CENTER);
    // lv_label_set_text(ui_Label5, "24.0");
    // lv_obj_set_style_text_color(ui_Label5, lv_color_hex(0xA5A5A5), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_opa(ui_Label5, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_font(ui_Label5, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Label6 = lv_label_create(ui_Screen1);
    // lv_obj_set_width(ui_Label6, LV_SIZE_CONTENT);   /// 1
    // lv_obj_set_height(ui_Label6, LV_SIZE_CONTENT);    /// 1
    // lv_obj_set_x(ui_Label6, 74);
    // lv_obj_set_y(ui_Label6, -14);
    // lv_obj_set_align(ui_Label6, LV_ALIGN_CENTER);
    // lv_label_set_text(ui_Label6, "-36.0");
    // lv_obj_set_style_text_color(ui_Label6, lv_color_hex(0xA5A5A5), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_opa(ui_Label6, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_font(ui_Label6, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Label7 = lv_label_create(ui_Screen1);
    // lv_obj_set_width(ui_Label7, LV_SIZE_CONTENT);   /// 1
    // lv_obj_set_height(ui_Label7, LV_SIZE_CONTENT);    /// 1
    // lv_obj_set_x(ui_Label7, 75);
    // lv_obj_set_y(ui_Label7, 9);
    // lv_obj_set_align(ui_Label7, LV_ALIGN_CENTER);
    // lv_label_set_text(ui_Label7, "93.6°");
    // lv_obj_set_style_text_color(ui_Label7, lv_color_hex(0xA5A5A5), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_opa(ui_Label7, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_font(ui_Label7, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);

    // ui_Label9 = lv_label_create(ui_Screen1);
    // lv_obj_set_width(ui_Label9, LV_SIZE_CONTENT);   /// 1
    // lv_obj_set_height(ui_Label9, LV_SIZE_CONTENT);    /// 1
    // lv_obj_set_x(ui_Label9, 23);
    // lv_obj_set_y(ui_Label9, 102);
    // lv_obj_set_align(ui_Label9, LV_ALIGN_CENTER);
    // lv_label_set_text(ui_Label9, "00:06");

    // ui_Image1 = lv_img_create(ui_Screen1);
    // lv_img_set_src(ui_Image1, &ui_img_compass_png);
    // lv_obj_set_width(ui_Image1, LV_SIZE_CONTENT);   /// 1
    // lv_obj_set_height(ui_Image1, LV_SIZE_CONTENT);    /// 1
    // lv_obj_set_x(ui_Image1, 208);
    // lv_obj_set_y(ui_Image1, 93);
    // lv_obj_set_align(ui_Image1, LV_ALIGN_CENTER);
    // lv_obj_add_flag(ui_Image1, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    // lv_obj_clear_flag(ui_Image1, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_img_set_zoom(ui_Image1, 64);

    // ui_Image3 = lv_img_create(ui_Screen1);
    // lv_img_set_src(ui_Image3, &ui_img_hamburger_png);
    // lv_obj_set_width(ui_Image3, LV_SIZE_CONTENT);   /// 1
    // lv_obj_set_height(ui_Image3, LV_SIZE_CONTENT);    /// 1
    // lv_obj_set_x(ui_Image3, 212);
    // lv_obj_set_y(ui_Image3, -93);
    // lv_obj_set_align(ui_Image3, LV_ALIGN_CENTER);
    // lv_obj_add_flag(ui_Image3, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    // lv_obj_clear_flag(ui_Image3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    // ui_Image4 = lv_img_create(ui_Screen1);
    // lv_img_set_src(ui_Image4, &ui_img_arrow_png);
    // lv_obj_set_width(ui_Image4, LV_SIZE_CONTENT);   /// 1
    // lv_obj_set_height(ui_Image4, LV_SIZE_CONTENT);    /// 1
    // lv_obj_set_x(ui_Image4, -82);
    // lv_obj_set_y(ui_Image4, 58);
    // lv_obj_set_align(ui_Image4, LV_ALIGN_CENTER);
    // lv_obj_add_flag(ui_Image4, LV_OBJ_FLAG_ADV_HITTEST);     /// Flags
    // lv_obj_clear_flag(ui_Image4, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    // lv_img_set_angle(ui_Image4, 936);
    // lv_img_set_zoom(ui_Image4, 8);

}

void ui_init(void)
{
    lv_disp_t * dispp = lv_disp_get_default();
    lv_theme_t * theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED),
                                               true, LV_FONT_DEFAULT);
    lv_disp_set_theme(dispp, theme);
    ui_Screen1_screen_init();
    lv_disp_load_scr(ui_Screen1);
}
