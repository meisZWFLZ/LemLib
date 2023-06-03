#pragma once

#include "lemlib/ui/pages/terminal/terminalPage.hpp"
#include "lemlib/ui/sidebar/sidebar.hpp"

using namespace lemlib::ui::pages;

TerminalPage::TerminalPage(lemlib::Chassis* chassis) : Page(chassis, "Terminal", 211, 10) {

}

void TerminalPage::destroy() {

}

void TerminalPage::initialize(lv_obj_t* screen) {
    this->header = lemlib::ui::util::createLabel("Terminal", screen, 119, -84);
    lv_obj_set_style_text_font(this->header, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    lemlib::ui::sidebar::Sidebar sidebar(screen, NULL, true);
}

void TerminalPage::render() {

}