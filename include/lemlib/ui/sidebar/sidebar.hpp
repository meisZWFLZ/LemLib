#pragma once

#include "lemlib/ui/page.hpp"
#include "lemlib/ui/util.hpp"
#include "lemlib/ui/ui.hpp"
#include "liblvgl/lvgl.h"

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include <cmath>

namespace lemlib {
namespace ui {
namespace sidebar {

static std::map<lv_obj_t*, lv_obj_t*> buttonLabels = {};

static double SCREEN_WIDTH = 480;
static double SCREEN_HEIGHT = 240;

/**
 * @brief A pullout sidebar to list all pages, and allow for switching between them.
 * 
 * Toggling the sidebar animates it to swing out from the right side of the screen.
 */
class Sidebar {
    public:
        Sidebar(lv_obj_t* screen, lv_obj_t* toggleButton, bool active = false);

        void toggle(bool change = true);

        void render();

    private:
        lv_obj_t* createPageButton(std::string name, lv_obj_t* screen, int x, int y, lv_event_cb_t callback, bool active = false);

        lv_obj_t* screen;
        lv_obj_t* toggleButton;
        bool active;

        lv_obj_t* sidebar;
        std::vector<lv_obj_t*> elements;

};
} // namespace sidebar
} // namespace ui
} // namespace lemlib