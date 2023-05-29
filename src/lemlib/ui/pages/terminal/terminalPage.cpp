#pragma once

#include "lemlib/ui/pages/terminal/terminalPage.hpp"

using namespace lemlib::ui::pages;

TerminalPage::TerminalPage(lemlib::Chassis* chassis) : Page(chassis, "Terminal", 211, 10) {

}

void TerminalPage::destroy() {

}

void TerminalPage::initialize() {
    lv_disp_t* display = lv_disp_get_default();
    lv_theme_t* theme = lv_theme_default_init(display, lv_palette_main(LV_PALETTE_BLUE),
                                                lv_palette_main(LV_PALETTE_RED), true, LV_FONT_DEFAULT);
    lv_disp_set_theme(display, theme);

    this->screen = lv_obj_create(NULL);
    lv_obj_clear_flag(this->screen, LV_OBJ_FLAG_SCROLLABLE);
    lv_obj_set_style_bg_color(this->screen, lv_color_hex(0x262626), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(this->screen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    this->header = lemlib::ui::util::createLabel("Terminal", this->screen, 119, -84);
    lv_obj_set_style_text_font(this->header, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_disp_load_scr(this->screen);
}

void TerminalPage::render() {

}