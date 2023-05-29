#pragma once

#include "lemlib/chassis/chassis.hpp"
#include "liblvgl/lvgl.h"
#include <string>

namespace lemlib {
namespace ui {
class Page {
    public:
        Page(lemlib::Chassis* chassis, std::string name, int sidebarX, int sidebarY) {
            this->chassis = chassis;
            this->name = name;

            this->sidebarX = sidebarX;
            this->sidebarY = sidebarY;
        }

        virtual void render() = 0;
        virtual void initialize() = 0;
        virtual void destroy() = 0;

        virtual std::string getName() = 0;

        int getSidebarX() {
            return this->sidebarX;
        }

        int getSidebarY() {
            return this->sidebarY;
        }
    protected:
        lemlib::Chassis* chassis;
        std::string name;

        int sidebarX;
        int sidebarY;
};
} // namespace ui
} // namespace lemlib