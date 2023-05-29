#pragma once

#include "lemlib/chassis/chassis.hpp"
#include "lemlib/ui/util.hpp"
#include "lemlib/ui/page.hpp"

namespace lemlib {
namespace ui {
namespace pages {
class AutonSelectorPage : public Page {
    public:
        AutonSelectorPage(lemlib::Chassis* chassis);

        void destroy();

        void initialize();

        void render();

        std::string getName() { return this->name; }
    private:
        lv_obj_t* screen;

        lv_obj_t* header;

        std::string name = "Auton Selector";
};
} // namespace pages
} // namespace ui
} // namespace lemlib