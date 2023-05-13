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
    chassis.setPose(0, 0, 0, false);

    lemlib::ui::Page* odometryPage = new lemlib::ui::pages::OdometryPage(&chassis);

    lemlib::ui::registerPage(odometryPage);
    lemlib::ui::setCurrentPage("Odometry");

    lemlib::ui::initialize();

    // testing code to see movement of odom screen

    double x = 0;
    double y = 0;
    double theta = 0;

    double xDirection = 1;
    double yDirection = 1;
    double thetaDirection = 1;

    while (true) {
        if (xDirection == 1 ? x < 72 : x > -72) x += 0.96 * xDirection;
        else {
            x = 71 * xDirection;
            xDirection *= -1;
        }

        if (yDirection == 1 ? y < 72 : y > -72) y += 0.96 * yDirection;
        else {
            y = 71 * yDirection;
            yDirection *= -1;
        }

        if (thetaDirection == 1 ? theta < 360 : theta > -360) theta += 5 * thetaDirection;
        else {
            theta = 359 * thetaDirection;
            thetaDirection *= -1;
        }

        chassis.setPose(x, y, theta, false);

        pros::delay(25);
    }

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
