#include "liblvgl/lvgl.h"

#include <string>

namespace lemlib {
namespace ui {
namespace util {
lv_obj_t* createLabel(std::string text, lv_obj_t* parent, int x, int y);

lv_obj_t* createImage(const lv_img_dsc_t* image, lv_obj_t* parent, int width, int height, int x, int y);
} // namespace util
} // namespace ui
} // namespace lemlib
