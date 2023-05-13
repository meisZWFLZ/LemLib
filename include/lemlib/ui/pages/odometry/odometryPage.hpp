#include "lemlib/chassis/chassis.hpp"
#include "lemlib/pose.hpp"
#include "lemlib/ui/page.hpp"
#include "liblvgl/lvgl.h"

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
        OdometryPage(lemlib::Chassis* chassis) : Page(chassis, "Odometry") {}

        void destroy() { std::cout << "Odometry Page Destroyed" << std::endl; }
        
        void initialize() {
            std::cout << "Odometry Page Initialized" << std::endl;

            lemlib::Pose pose = this->chassis->getPose(false);

            std::string xValueString = getStringFromFloat(pose.x) + "in";
            std::string yValueString = getStringFromFloat(pose.y) + "in";
            std::string tValueString = getStringFromFloat(pose.theta) + "°";

            lv_disp_t* display = lv_disp_get_default();
            lv_theme_t* theme = lv_theme_default_init(display, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), true, LV_FONT_DEFAULT);
            lv_disp_set_theme(display, theme);

            // screen
            this->screen = lv_obj_create(NULL);
            lv_obj_clear_flag(this->screen, LV_OBJ_FLAG_SCROLLABLE);
            lv_obj_set_style_bg_color(this->screen, lv_color_hex(0x262626), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_bg_opa(this->screen, 255, LV_PART_MAIN | LV_STATE_DEFAULT);    

            this->header = this->createLabel("Odometry", this->screen, 119, -84);
            lv_obj_set_style_text_font(this->header, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

            this->xLabel = this->createLabel("X", this->screen, 43, -37);
            this->yLabel = this->createLabel("Y", this->screen, 43, -14);
            this->tLabel = this->createLabel("T", this->screen, 43, 9);
    
            this->xValue = this->createLabel(xValueString, this->screen, 73, -37);
            lv_obj_set_style_text_color(this->xValue, lv_color_hex(0xA5A5A5), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(this->xValue, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(this->xValue, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);            

            this->yValue = this->createLabel(yValueString, this->screen, 73, -14);
            lv_obj_set_style_text_color(this->yValue, lv_color_hex(0xA5A5A5), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(this->yValue, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(this->yValue, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);    

            this->tValue = this->createLabel(tValueString, this->screen, 73, 9);
            lv_obj_set_style_text_color(this->tValue, lv_color_hex(0xA5A5A5), LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_opa(this->tValue, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
            lv_obj_set_style_text_font(this->tValue, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);

            this->timer = this->createLabel(this->fancyTime(this->chassis->getTime()), this->screen, 23, 102);

            // field image
            this->field = lv_img_create(this->screen);
            lv_img_set_src(this->field, &fieldImage);
            lv_obj_set_width(this->field, 240);
            lv_obj_set_height(this->field, 240);
            lv_obj_set_x(this->field, 0);
            lv_obj_set_y(this->field, 0);

            // compass image
            this->compass = lv_img_create(this->screen);
            lv_img_set_src(this->compass, &compassImage);
            lv_obj_set_width(this->compass, LV_SIZE_CONTENT);
            lv_obj_set_height(this->compass, LV_SIZE_CONTENT);
            lv_obj_set_x(this->compass, 208);
            lv_obj_set_y(this->compass, 93);
            lv_obj_set_align(this->compass, LV_ALIGN_CENTER);
            lv_obj_add_flag(this->compass, LV_OBJ_FLAG_ADV_HITTEST);
            lv_obj_clear_flag(this->compass, LV_OBJ_FLAG_SCROLLABLE);
            lv_img_set_zoom(this->compass, 64);

            // hamburger image
            this->hamburger = lv_img_create(this->screen);
            lv_img_set_src(this->hamburger, &hamburgerImage);
            lv_obj_set_width(this->hamburger, LV_SIZE_CONTENT);
            lv_obj_set_height(this->hamburger, LV_SIZE_CONTENT);
            lv_obj_set_x(this->hamburger, 212);
            lv_obj_set_y(this->hamburger, -93);
            lv_obj_set_align(this->hamburger, LV_ALIGN_CENTER);
            lv_obj_add_flag(this->hamburger, LV_OBJ_FLAG_ADV_HITTEST);
            lv_obj_clear_flag(this->hamburger, LV_OBJ_FLAG_SCROLLABLE);

            // robot indicator image
            this->robotIndicator = lv_img_create(this->screen);
            lv_img_set_src(this->robotIndicator, &robotIndicatorImage);
            lv_obj_set_width(this->robotIndicator, LV_SIZE_CONTENT);
            lv_obj_set_height(this->robotIndicator, LV_SIZE_CONTENT);
            lv_obj_set_x(this->robotIndicator, -120 + translateIndicatorToPosition(pose.x));
            lv_obj_set_y(this->robotIndicator, 0 + translateIndicatorToPosition(pose.y));
            lv_obj_set_align(this->robotIndicator, LV_ALIGN_CENTER);
            lv_obj_add_flag(this->robotIndicator, LV_OBJ_FLAG_ADV_HITTEST);
            lv_obj_clear_flag(this->robotIndicator, LV_OBJ_FLAG_SCROLLABLE);
            lv_img_set_angle(this->robotIndicator, translateIndicatorToAngle(pose.theta));
            lv_img_set_zoom(this->robotIndicator, 8);

            lv_disp_load_scr(this->screen);
        }

        void render() {
            this->updateTimer();

            this->updateXValue();
            this->updateYValue();
            this->updateTValue();

            this->updateIndicator();
        }

        std::string getName() { return this->name; }
    private:
        std::string getStringFromFloat(float value) {
            std::ostringstream stream;
            stream << std::setprecision(5) << std::noshowpoint << (double) value;
            return stream.str();
        }

        std::string fancyTime(double ms) {
            // convert ms to mm:ss, e.g. 1234 ms -> 00:01
            int seconds = (int) std::round(ms / 1000);
            int minutes = seconds / 60;
            seconds %= 60;
            
            std::ostringstream stream;
            stream << std::setfill('0') << std::setw(2) << minutes << ":" << std::setw(2) << seconds;
            return stream.str();
        }

        void updateTimer() {
            double ms = this->chassis->getTime();

            lv_label_set_text(this->timer, fancyTime(ms).c_str());
        }

        void updateXValue() {
            lemlib::Pose pose = this->chassis->getPose(false);

            std::string xValueString = getStringFromFloat(pose.x) + "in";

            lv_label_set_text(this->xValue, xValueString.c_str());
        }

        void updateYValue() {
            lemlib::Pose pose = this->chassis->getPose(false);

            std::string yValueString = getStringFromFloat(pose.y) + "in";

            lv_label_set_text(this->yValue, yValueString.c_str());
        }

        void updateTValue() {
            lemlib::Pose pose = this->chassis->getPose(false);

            std::string tValueString = getStringFromFloat(pose.theta) + "°";

            lv_label_set_text(this->tValue, tValueString.c_str());
        }

        double translateIndicatorToPosition(double position) { return (120.0f / 72.0f) * position; }

        double translateIndicatorToAngle(double angle) { return angle * 10; }

        void updateIndicator() {
            lemlib::Pose pose = this->chassis->getPose(false);

            lv_obj_set_x(this->robotIndicator, -120 + translateIndicatorToPosition(pose.x));
            lv_obj_set_y(this->robotIndicator, 0 + translateIndicatorToPosition(pose.y));
            lv_img_set_angle(this->robotIndicator, translateIndicatorToAngle(pose.theta));
        }

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