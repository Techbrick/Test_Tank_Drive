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

	while(IsOperatorControl() && IsEnabled())
	{
		robotDrive.TankDrive(0.5, 0.5);
		Wait(3);
		robotDrive.TankDrive(0.5 , -0.5);
		Wait(3);
	}
}

START_ROBOT_CLASS(Robot);
