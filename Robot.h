#ifndef SRC_ROBOT_H_
#define SRC_ROBOT_H_

#include "WPILib.h"
//#include "Buttons/JoystickButton.h"

class Robot : public SampleRobot {
	RobotDrive robotDrive;
	Joystick driveStick;
public:
	Robot();
	
	void OperatorControl();
	void Autonomous();
	void Test();
};

#endif /* SRC_ROBOT_H_ */
