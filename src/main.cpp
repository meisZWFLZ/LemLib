#include "main.h"
#include "lemlib/api.hpp"
#include "pros/abstract_motor.hpp"

// motor groups
pros::v5::MotorGroup leftMotors({-3, -14, -12}, pros::v5::MotorGears::rpm_600); // left motor group
pros::v5::MotorGroup rightMotors({19, 20, 1}, pros::v5::MotorGears::rpm_600); // right motor group

// Inertial Sensor on port 6
pros::v5::Imu imu(6);

// tracking wheels
pros::adi::Encoder verticalEnc('A', 'B', false);
// vertical tracking wheel. 2.75" diameter, 2.2" offset
lemlib::TrackingWheel vertical(&verticalEnc, 2.75, 0);

// drivetrain
lemlib::Drivetrain_t drivetrain {
    &leftMotors, &rightMotors, 10, 3.25, 360,
};

// lateral motion controller
lemlib::ChassisController_t lateralController {10, 30, 1, 100, 3, 500, 20};

// angular motion controller
lemlib::ChassisController_t angularController {2, 10, 1, 100, 3, 500, 3};

// sensors for odometry
lemlib::OdomSensors_t sensors {nullptr, nullptr, nullptr, nullptr, &imu};

lemlib::Chassis chassis(drivetrain, lateralController, angularController, sensors);

void initialize() {
    lemlib::ui::Page* odometryPage = new lemlib::ui::pages::OdometryPage(&chassis);

    lemlib::ui::registerPage(odometryPage);
    lemlib::ui::setCurrentPage("Odometry");

    lemlib::ui::initialize();

    // comment out for testing UI
    // pros::lcd::initialize();
    // // calibrate sensors
    // chassis.calibrate();
    // while (true) {
    //     pros::lcd::print(0, "X: %f", chassis.getPose().x);
    //     pros::lcd::print(1, "Y: %f", chassis.getPose().y);
    //     pros::lcd::print(2, "Theta: %f", chassis.getPose().theta);
    //     pros::delay(10);
    // }
}

void disabled() {}

void competition_initialize() {}

void autonomous() { chassis.moveTo(20, 0, 4000); }

void opcontrol() {}