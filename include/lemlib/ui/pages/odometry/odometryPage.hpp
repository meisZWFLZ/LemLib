#pragma once

#include "lemlib/chassis/chassis.hpp"
#include "lemlib/ui/util.hpp"
#include "lemlib/ui/page.hpp"
#include "lemlib/pose.hpp"
#include "liblvgl/lvgl.h"
#include "asset.h"

#include <iomanip>
#include <sstream>
#include <cmath>

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
        OdometryPage(lemlib::Chassis* chassis);

        void destroy();

        void initialize(lv_obj_t* screen);

        void render();
        
        std::string getName() { return this->name; }
    private:
        std::string getStringFromFloat(float value);

        std::string fancyTime(double ms);

        void updateTimer();

        void updateXValue();

        void updateYValue();

        void updateTValue();

        double translateIndicatorToPosition(double position);

        double translateIndicatorToAngle(double angle);

        void updateIndicator();

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