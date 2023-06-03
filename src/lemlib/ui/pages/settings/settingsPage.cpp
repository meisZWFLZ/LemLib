#include "lemlib/ui/pages/settings/settingsPage.hpp"

using namespace lemlib::ui::pages;

SettingsPage::SettingsPage(lemlib::Chassis* chassis) : Page(chassis, "Settings", 212, 34) {

}

void SettingsPage::destroy() {

}

void SettingsPage::initialize(lv_obj_t* screen) {
    this->header = lemlib::ui::util::createLabel("Settings", this->screen, 119, -84);
    lv_obj_set_style_text_font(this->header, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);
}

void SettingsPage::render() {

}