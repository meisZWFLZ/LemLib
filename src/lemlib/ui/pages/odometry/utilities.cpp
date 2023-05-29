#include "lemlib/ui/pages/odometry/odometryPage.hpp"

using namespace lemlib::ui::pages;

std::string OdometryPage::getStringFromFloat(float value) {
    std::ostringstream stream;
    stream << std::setprecision(5) << std::noshowpoint << (double)value;
    return stream.str();
}

std::string OdometryPage::fancyTime(double ms) {
    int seconds = (int)std::round(ms / 1000);
    int minutes = seconds / 60;
    seconds %= 60;

    std::ostringstream stream;
    stream << std::setfill('0') << std::setw(2) << minutes << ":" << std::setw(2) << seconds;
    return stream.str();
}

void OdometryPage::updateTimer() {
    double ms = this->chassis->getTime();

    lv_label_set_text(this->timer, fancyTime(ms).c_str());
}

void OdometryPage::updateXValue() {
    lemlib::Pose pose = this->chassis->getPose(false);

    std::string xValueString = getStringFromFloat(pose.x) + "in";

    lv_label_set_text(this->xValue, xValueString.c_str());
}

void OdometryPage::updateYValue() {
    lemlib::Pose pose = this->chassis->getPose(false);

    std::string yValueString = getStringFromFloat(pose.y) + "in";

    lv_label_set_text(this->yValue, yValueString.c_str());
}

void OdometryPage::updateTValue() {
    lemlib::Pose pose = this->chassis->getPose(false);

    std::string tValueString = getStringFromFloat(pose.theta) + "°";

    lv_label_set_text(this->tValue, tValueString.c_str());
}

double OdometryPage::translateIndicatorToPosition(double position) { return (120.0f / 72.0f) * position; }

double OdometryPage::translateIndicatorToAngle(double angle) { return angle * 10; }

void OdometryPage::updateIndicator() {
    lemlib::Pose pose = this->chassis->getPose(false);

    lv_obj_set_x(this->robotIndicator, -120 + translateIndicatorToPosition(pose.x));
    lv_obj_set_y(this->robotIndicator, 0 + translateIndicatorToPosition(pose.y));
    lv_img_set_angle(this->robotIndicator, translateIndicatorToAngle(pose.theta));
}