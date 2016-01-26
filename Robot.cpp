#include "Robot.h"

Robot::Robot() :
	robotDrive(Constants::driveFrontLeftPin, Constants::driveRearLeftPin, Constants::driveFrontRightPin, Constants::driveRearRightPin),
	driveStick(Constants::driveStickChannel)
{
	robotDrive.SetExpiration(0.1); // safety feature
}
	
void Robot::OperatorControl() //teleop code
{
	robotDrive.SetSafetyEnabled(false);

	robotDrive.TankDrive(1,1);
	Wait(0.5);
	robotDrive.TankDrive(-1,-1);
	Wait(1);
	robotDrive.TankDrive(0, 1);
	Wait(2);
}

START_ROBOT_CLASS(Robot);
