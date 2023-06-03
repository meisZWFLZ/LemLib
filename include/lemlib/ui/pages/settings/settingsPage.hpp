#pragma once

#include "lemlib/chassis/chassis.hpp"
#include "lemlib/ui/util.hpp"
#include "lemlib/ui/page.hpp"

namespace lemlib {
namespace ui {
namespace pages {
class SettingsPage : public Page {
    public:
        SettingsPage(lemlib::Chassis* chassis);

        void destroy();

        void initialize(lv_obj_t* screen);

        void render();

        std::string getName() { return this->name; }
    private:
        lv_obj_t* screen;

        lv_obj_t* header;

        std::string name = "Settings";
};
} // namespace pages
} // namespace ui
} // namespace lemlib