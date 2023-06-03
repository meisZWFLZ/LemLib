#include "lemlib/ui/pages/odometry/odometryPage.hpp"

#include "lemlib/ui/sidebar/sidebar.hpp"

using namespace lemlib::ui::pages;

OdometryPage::OdometryPage(lemlib::Chassis* chassis) : Page(chassis, "Odometry", 205, -14) {

}

void OdometryPage::destroy() {
    std::cout << "Odometry Page Destroyed" << std::endl;
}

void OdometryPage::initialize(lv_obj_t* screen) {
    std::cout << "Odometry Page Initialized" << std::endl;

    lemlib::Pose pose = this->chassis->getPose(false);

    std::string xValueString = getStringFromFloat(pose.x) + "in";
    std::string yValueString = getStringFromFloat(pose.y) + "in";
    std::string tValueString = getStringFromFloat(pose.theta) + "°";

    this->header = lemlib::ui::util::createLabel("Odometry", screen, 119, -84);
    lv_obj_set_style_text_font(this->header, &lv_font_montserrat_20, LV_PART_MAIN | LV_STATE_DEFAULT);

    this->xLabel = lemlib::ui::util::createLabel("X", screen, 43, -37);
    this->yLabel = lemlib::ui::util::createLabel("Y", screen, 43, -14);
    this->tLabel = lemlib::ui::util::createLabel("T", screen, 43, 9);

    this->xValue = lemlib::ui::util::createLabel(xValueString, screen, 73, -37);
    lv_obj_set_style_text_color(this->xValue, lv_color_hex(0xA5A5A5), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(this->xValue, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(this->xValue, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);

    this->yValue = lemlib::ui::util::createLabel(yValueString, screen, 73, -14);
    lv_obj_set_style_text_color(this->yValue, lv_color_hex(0xA5A5A5), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(this->yValue, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(this->yValue, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);

    this->tValue = lemlib::ui::util::createLabel(tValueString, screen, 73, 9);
    lv_obj_set_style_text_color(this->tValue, lv_color_hex(0xA5A5A5), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_opa(this->tValue, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(this->tValue, &lv_font_montserrat_10, LV_PART_MAIN | LV_STATE_DEFAULT);

    this->timer = lemlib::ui::util::createLabel(this->fancyTime(this->chassis->getTime()), screen, 23, 102);

    this->field = lemlib::ui::util::createImage(&fieldImage, screen, 240, 240, 0, 0);

    this->compass = lemlib::ui::util::createImage(&compassImage, screen, LV_SIZE_CONTENT, LV_SIZE_CONTENT, 208, 93);
    lv_obj_set_align(this->compass, LV_ALIGN_CENTER);
    lv_obj_add_flag(this->compass, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(this->compass, LV_OBJ_FLAG_SCROLLABLE);
    lv_img_set_zoom(this->compass, 64);

    this->hamburger =
        lemlib::ui::util::createImage(&hamburgerImage, screen, LV_SIZE_CONTENT, LV_SIZE_CONTENT, 212, -93);
    lv_obj_set_align(this->hamburger, LV_ALIGN_CENTER);
    lv_obj_add_flag(this->hamburger, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(this->hamburger, LV_OBJ_FLAG_SCROLLABLE);

    this->robotIndicator = lemlib::ui::util::createImage(&robotIndicatorImage, screen, LV_SIZE_CONTENT,
                                                LV_SIZE_CONTENT, -120 + translateIndicatorToPosition(pose.x),
                                                0 + translateIndicatorToPosition(pose.y));
    lv_obj_set_align(this->robotIndicator, LV_ALIGN_CENTER);
    lv_obj_add_flag(this->robotIndicator, LV_OBJ_FLAG_ADV_HITTEST);
    lv_obj_clear_flag(this->robotIndicator, LV_OBJ_FLAG_SCROLLABLE);
    lv_img_set_angle(this->robotIndicator, translateIndicatorToAngle(pose.theta));
    lv_img_set_zoom(this->robotIndicator, 8);

    lemlib::ui::sidebar::Sidebar sidebar(screen, this->hamburger, true);
}

void OdometryPage::render() {
    this->updateTimer();

    this->updateXValue();
    this->updateYValue();
    this->updateTValue();

    this->updateIndicator();
}