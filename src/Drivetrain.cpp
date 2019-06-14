#include "../include/Drivetrain.h"

Drivetrain::Drivetrain(){
    // reset encoders
    motorFL.set_zero_position(0);
    motorRL.set_zero_position(0);
    motorFR.set_zero_position(0);
    motorRR.set_zero_position(0);
}

Drivetrain::~Drivetrain(){}

void Drivetrain::drive(double fwd, double rot, double str){
    double V, W; // foward and turn speeds
    double L, R; // left and right speeds

    V = (127 - abs(fwd)) * (rot/127) + rot;
    W = (127 - abs(rot)) * (fwd/127) + fwd;
    L = (V+W)/2;
    R = (V-W)/2;

    // set motor speeds
    motorFL.move(L);
    motorRL.move(L);

    motorFR.move(R);
    motorRR.move(R);

    motorMM.move(str);
}

void Drivetrain::moveDistance(double inches, double speed){
    int ticks = inches * ticksPerInch; // get ticks from distance

    motorFL.move_relative(ticks, speed);
    motorRL.move_relative(ticks, speed);
    motorFR.move_relative(ticks, speed);
    motorRR.move_relative(ticks, speed);
}