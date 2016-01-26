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
		robotDrive.TankDrive(0.3,0.3);
		Wait(1);
		robotDrive.TankDrive(-0.3,-0.3);
		Wait(1);
		robotDrive.TankDrive(0, 0.2);
		Wait(2);
	}
}

START_ROBOT_CLASS(Robot);
