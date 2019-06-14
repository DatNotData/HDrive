#pragma once
#include "main.h"

class Drivetrain {
private:
    // declare motors
    pros::Motor motorFL = pros::Motor(1);
    pros::Motor motorFR = pros::Motor(10, true);
    pros::Motor motorRL = pros::Motor(11);
    pros::Motor motorRR = pros::Motor(20, true);
    pros::Motor motorMM = pros::Motor(9, true);

    // settings for encoders
    const double errorFactor = 1.05208333; // set error factor
    const double ticksPerInch = 900/(2 * 3.14159265 * 4 / 2) * errorFactor; // get number of tics per inch
    const double ticksPerDegree = 3650 / 360; // robot turning

public:
    Drivetrain();
    ~Drivetrain();
    void drive(double fwd, double rot, double str); // drive with joystick 
    void moveDistance(double inches, double speed); // move forward a certain number of inches
};
