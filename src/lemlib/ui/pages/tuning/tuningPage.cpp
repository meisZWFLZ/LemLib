#pragma once

#include "lemlib/ui/pages/tuning/tuningPage.hpp"

using namespace lemlib::ui::pages;

TuningPage::TuningPage(lemlib::Chassis* chassis): Page(chassis, "Tuning", 216, 58) {

}

void TuningPage::destroy() {

}

void TuningPage::initialize(lv_obj_t* screen) {
    this->header = lemlib::ui::util::createLabel("Tuning", this->screen, 119, -84);
    lv_obj_set_style_text_font(this->header, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
}

void TuningPage::render() {
    
}