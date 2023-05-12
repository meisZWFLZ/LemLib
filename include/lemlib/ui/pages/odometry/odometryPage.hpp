#include "lemlib/chassis/chassis.hpp"
#include "lemlib/ui/page.hpp"
#include "liblvgl/core/lv_obj.h"
#include "liblvgl/lv_conf_internal.h"
#include "liblvgl/lvgl.h"
#include "liblvgl/misc/lv_color.h"

extern const lv_img_dsc_t robotIndicatorImage;
extern const lv_img_dsc_t hamburgerImage;
extern const lv_img_dsc_t compassImage;
extern const lv_img_dsc_t fieldImage;

LV_IMG_DECLARE(robotIndicatorImage);
LV_IMG_DECLARE(hamburgerImage);
LV_IMG_DECLARE(compassImage);
LV_IMG_DECLARE(fieldImage);

namespace lemlib {
namespace ui {
namespace pages {
class OdometryPage : public Page {
    public:
        OdometryPage(lemlib::Chassis* chassis) : Page(chassis, "Odometry") {}

        void destroy() { std::cout << "Odometry Page Destroyed" << std::endl; }
        
        void initialize() {
            std::cout << "Odometry Page Initialized" << std::endl;

            lv_disp_t* display = lv_disp_get_default();
            lv_theme_t* theme = lv_theme_default_init(display, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), true, LV_FONT_DEFAULT);
            lv_disp_set_theme(display, theme);

            // screen
            this->screen = lv_obj_create(NULL);
            lv_obj_clear_flag(this->screen, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_color(this->screen, lv_color_hex(0x262626), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(this->screen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);    

            // header
            this->header = lv_label_create(this->screen);
            lv_obj_set_width(this->header, LV_SIZE_CONTENT);
            lv_obj_set_height(this->header, LV_SIZE_CONTENT);
            lv_obj_set_x(this->header, 119);
            lv_obj_set_y(this->header, -84);
            lv_obj_set_align(this->header, LV_ALIGN_CENTER);
            lv_label_set_text(this->header, "Odometry");
            lv_obj_set_style_text_font(this->header, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

            // xLabel
            this->xLabel = lv_label_create(this->screen);
            lv_obj_set_width(this->xLabel, LV_SIZE_CONTENT);
            lv_obj_set_height(this->xLabel, LV_SIZE_CONTENT);
            lv_obj_set_x(this->xLabel, 43);
            lv_obj_set_y(this->xLabel, -37);
            lv_obj_set_align(this->xLabel, LV_ALIGN_CENTER);
            lv_label_set_text(this->xLabel, "X");

            // yLabel
            this->yLabel = lv_label_create(this->screen);
            lv_obj_set_width(this->yLabel, LV_SIZE_CONTENT);
            lv_obj_set_height(this->yLabel, LV_SIZE_CONTENT);
            lv_obj_set_x(this->yLabel, 43);
            lv_obj_set_y(this->yLabel, 9);
            lv_obj_set_align(this->yLabel, LV_ALIGN_CENTER);
            lv_label_set_text(this->yLabel, "Y");

            // tLabel
            this->tLabel = lv_label_create(this->screen);
            lv_obj_set_width(this->tLabel, LV_SIZE_CONTENT);
            lv_obj_set_height(this->tLabel, LV_SIZE_CONTENT);
            lv_obj_set_x(this->tLabel, 43);
            lv_obj_set_y(this->tLabel, -14);
            lv_obj_set_align(this->tLabel, LV_ALIGN_CENTER);
            lv_label_set_text(this->tLabel, "T");

            // field image
            this->field = lv_img_create(this->screen);
            lv_img_set_src(this->field, &fieldImage);
            lv_obj_set_width(this->field, 240);
            lv_obj_set_height(this->field, 240);
            lv_obj_set_x(this->field, -120);
            lv_obj_set_y(this->field, 0);

            lv_disp_load_scr(this->screen);
        }

        void render() {
            std::cout << "Odometry Page Rendered" << std::endl;
        }

        std::string getName() { return this->name; }
    private:
        lv_obj_t* screen;

        lv_obj_t* header;

        lv_obj_t* xLabel;
        lv_obj_t* yLabel;
        lv_obj_t* tLabel;

        lv_obj_t* xValue;
        lv_obj_t* yValue;
        lv_obj_t* tValue;

        lv_obj_t* timer;

        lv_obj_t* robotIndicator;
        lv_obj_t* hamburger;
        lv_obj_t* compass;
        lv_obj_t* field;
};
} // namespace pages
} // namespace ui
} // namespace lemlib