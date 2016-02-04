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
		float throttle = driveStick.GetRawAxis(Constants::L2);
		float moveValue = throttle * driveStick.GetRawAxis(Constants::PS4MoveJoystick);
		float rotateValue = throttle * driveStick.GetRawAxis(Constants::PS4RotateJoystick);
		robotDrive.TankDrive(moveValue, rotateValue, true);
	}
}

START_ROBOT_CLASS(Robot);
