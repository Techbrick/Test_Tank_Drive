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
		float moveValue = Joystick.GetRawAxis(Constants::PS4MoveJoystick);
		float rotateValue = Joystick.GetRawAxis(Constants::PS4RotateJoystick);
		robotDrive.TankDrive(moveValue, rotateValue);
	}
}

START_ROBOT_CLASS(Robot);
