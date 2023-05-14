#include "lemlib/ui/util.hpp"
#include "liblvgl/lvgl.h"

#include <iostream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <cmath>

extern const lv_img_dsc_t hamburgerImage;
LV_IMG_DECLARE(hamburgerImage);

namespace lemlib {
namespace ui {
namespace sidebar {

static double SCREEN_WIDTH = 480;
static double SCREEN_HEIGHT = 240;

/**
 * @brief A pullout sidebar to list all pages, and allow for switching between them.
 * 
 * Toggling the sidebar animates it to swing out from the right side of the screen.
 */
class Sidebar {
    public:
        Sidebar(lv_obj_t* screen, lv_obj_t* toggleButton, bool active = false) {
            this->screen = screen;
            this->toggleButton = toggleButton;
            this->active = active;
            this->elements = std::vector<lv_obj_t*>();

            this->render();
            // this->toggle(false);
        }

        void toggle(bool change = true) {
            for (lv_obj_t* element : this->elements) {
                if (this->active) {
                    lv_obj_add_flag(element, LV_OBJ_FLAG_HIDDEN);
                } else {
                    lv_obj_clear_flag(element, LV_OBJ_FLAG_HIDDEN);
                }
            }

            if (change) this->active = !this->active;

            std::cout << "Sidebar toggled, active: " << this->active << std::endl;
        }

        void render() {
            this->sidebar = lv_obj_create(this->screen);
            lv_obj_set_width(this->sidebar, 120);
            lv_obj_set_height(this->sidebar, 240);
            lv_obj_set_x(this->sidebar, 180);
            lv_obj_set_y(this->sidebar, 0);
            lv_obj_set_align(this->sidebar, LV_ALIGN_CENTER);
            lv_obj_clear_flag(this->sidebar, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_radius(this->sidebar, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_color(this->sidebar, lv_color_hex(0x2E2E2E), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(this->sidebar, 245, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_color(this->sidebar, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_border_opa(this->sidebar, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
        
            lv_obj_t* hamburger = lemlib::ui::util::createImage(&hamburgerImage, this->screen, LV_SIZE_CONTENT, LV_SIZE_CONTENT, 212, -93);
            lv_obj_add_flag(hamburger, LV_OBJ_FLAG_ADV_HITTEST);
            lv_obj_clear_flag(hamburger, LV_OBJ_FLAG_SCROLLABLE);

            this->elements.push_back(this->sidebar);
            this->elements.push_back(hamburger);

            std::cout << "Sidebar rendered, " << this->elements.size() << " elements" << std::endl;
        }

    private:
        lv_obj_t* screen;
        lv_obj_t* toggleButton;
        bool active;

        lv_obj_t* sidebar;
        std::vector<lv_obj_t*> elements;
};
} // namespace sidebar
} // namespace ui
} // namespace lemlib