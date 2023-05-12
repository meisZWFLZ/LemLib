#include "lemlib/chassis/chassis.hpp"
#include "lemlib/ui/page.hpp"
#include "liblvgl/lvgl.h"

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

        void render() { std::cout << "Odometry Page Rendered" << std::endl; }

        void initialize() { std::cout << "Odometry Page Initialized" << std::endl; }

        void destroy() { std::cout << "Odometry Page Destroyed" << std::endl; }

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