#include "Robot.h"

Robot::Robot() :
	robotDrive(Constants::driveLeftPin, Constants::driveRightPin),
	driveStick(Constants::driveStickChannel),
	shooter(Constants::shooterLeftPin, Constants::shooterRightPin)
{
	robotDrive.SetExpiration(0.1); // safety feature
}
	
void Robot::OperatorControl() //teleop code
{
	robotDrive.SetSafetyEnabled(false);

	while(IsOperatorControl() && IsEnabled())
	{
		robotDrive.ArcadeDrive(driveStick, Constants::driveXAxis, driveStick, Constants::driveZAxis);
	}
}

START_ROBOT_CLASS(Robot);
