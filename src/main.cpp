#include "main.h"

Drivetrain drivetrain;

void initialize(){
    pros::lcd::initialize();
}

void disabled() {}

void competition_initialize() {}

void autonomous() {
	drivetrain.moveDistance(16, 50);
}

void opcontrol() {
	pros::Controller master(pros::E_CONTROLLER_MASTER);

	while (true) {
		// get joystick values
		int fwd = master.get_analog(ANALOG_RIGHT_X);
		int rot = master.get_analog(ANALOG_LEFT_Y);
		int str = master.get_analog(ANALOG_LEFT_X);

		// move drive base
		drivetrain.drive(fwd,rot,str);
		
		pros::delay(20);
	}
}
