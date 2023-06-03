#include "lemlib/ui/pages/settings/settingsPage.hpp"
#include "lemlib/ui/sidebar/sidebar.hpp"

using namespace lemlib::ui::pages;

SettingsPage::SettingsPage(lemlib::Chassis* chassis) : Page(chassis, "Settings", 212, 34) {

}

void SettingsPage::destroy() {

}

void SettingsPage::initialize(lv_obj_t* screen) {
    this->header = lemlib::ui::util::createLabel("Settings", screen, 119, -84);
    lv_obj_set_style_text_font(this->header, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    lemlib::ui::sidebar::Sidebar sidebar(screen, NULL, true);
}

void SettingsPage::render() {

}