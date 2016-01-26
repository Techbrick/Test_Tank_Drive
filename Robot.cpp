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

	while (IsOperatorControl() && IsEnabled())
	{
		robotDrive.ArcadeDrive(driveStick, Constants::driveXAxis, driveStick, Constants::driveZAxis);

		Wait(0.005); // wait 5ms to avoid hogging CPU cycles
	}
}

START_ROBOT_CLASS(Robot);
