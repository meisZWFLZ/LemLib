#include "lemlib/chassis/chassis.hpp"
#include "liblvgl/core/lv_obj.h"
#include "liblvgl/lvgl.h"
#include <string>

namespace lemlib {
namespace ui {
class Page {
    public:
        Page(lemlib::Chassis* chassis, std::string name) {
            this->chassis = chassis;
            this->name = name;
        }

        virtual void render() = 0;
        virtual void initialize() = 0;
        virtual void destroy() = 0;

        virtual std::string getName() = 0;
    protected:
        lemlib::Chassis* chassis;
        std::string name;

        lv_obj_t* createLabel(std::string text, lv_obj_t* parent, int x, int y) {
            lv_obj_t* label = lv_label_create(parent);
            
            lv_obj_set_width(label, LV_SIZE_CONTENT);
            lv_obj_set_height(label, LV_SIZE_CONTENT);
            lv_obj_set_x(label, x);
            lv_obj_set_y(label, y);
            lv_obj_set_align(label, LV_ALIGN_CENTER);
            lv_label_set_text(label, text.c_str());

            return label;
        }
};
} // namespace ui
} // namespace lemlib