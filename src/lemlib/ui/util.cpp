#include "lemlib/ui/util.hpp"

lv_obj_t* lemlib::ui::util::createLabel(std::string text, lv_obj_t* parent, int x, int y) {
    lv_obj_t* label = lv_label_create(parent);

    lv_obj_set_width(label, LV_SIZE_CONTENT);
    lv_obj_set_height(label, LV_SIZE_CONTENT);
    lv_obj_set_x(label, x);
    lv_obj_set_y(label, y);
    lv_obj_set_align(label, LV_ALIGN_CENTER);
    lv_label_set_text(label, text.c_str());

    return label;
}

lv_obj_t* lemlib::ui::util::createImage(const lv_img_dsc_t* image, lv_obj_t* parent, int width, int height, int x, int y) {
    lv_obj_t* img = lv_img_create(parent);

    lv_img_set_src(img, image);
    lv_obj_set_width(img, width);
    lv_obj_set_height(img, height);
    lv_obj_set_x(img, x);
    lv_obj_set_y(img, y);

    return img;
}