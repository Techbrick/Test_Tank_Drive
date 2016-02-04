#ifndef SRC_CONSTANTS_H
#define SRC_CONSTANTS_H

namespace Constants {
	//PWM Out Pins
	static constexpr int driveLeftPin	= 1;
	static constexpr int driveRightPin	= 0;
	
	//static constexpr int shooterLeftPin = 99;
	//static constexpr int shooterRightPin = 99;
	
	static constexpr int driveStickChannel = 0;
	static constexpr int shooterStickChannel = 1;
	
	static constexpr int driveXAxis = 0;
	static constexpr int driveYAxis = 1;
	static constexpr int driveZAxis = 2;
	
	static constexpr int PS4MoveJoystick = 0;
	static constexpr int PS4RotateJoystick = 0;
	static constexpr int L2 = 0;
}

#endif
