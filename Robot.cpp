#include "Robot.h"

#include <math.h>
#include <iostream>

Robot::Robot() :
	robotDrive(Constants::driveLeftPin,Constants::driveRightPin),
	driveStick(Constants::driveStickChannel)
	//shooter(Constants::shooterLeftPin, Constants::shooterRightPin)
{
	robotDrive.SetExpiration(0.1); // safety feature
}
	
void Robot::OperatorControl() //teleop code
{
	CameraServer::GetInstance()->SetQuality(50);
	CameraServer::GetInstance()->StartAutomaticCapture("cam0");

	while(IsOperatorControl() && IsEnabled())
	{
		float throttle = (((-driveStick.GetRawAxis(Constants::driveL2)) + 1.0)/2.0); //[0, 1]
		float moveValue = throttle * driveStick.GetY();
		float rotateValue = -driveStick.GetX();
		
		SmartDashboard::PutNumber("Throttle Value", throttle);
		SmartDashboard::PutNumber("Move Value", moveValue);
		SmartDashboard::PutNumber("Rotate Value", rotateValue);
		
		robotDrive.ArcadeDrive(moveValue, rotateValue, true);
	}
	
	 robotDrive.SetSafetyEnabled(true);
}

START_ROBOT_CLASS(Robot);