// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef OI_H
#define OI_H

#include "WPILib.h"

class OI {
private:
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	std::shared_ptr<Joystick> gamePad;
	std::shared_ptr<JoystickButton> returnOriginalRPM;
	std::shared_ptr<JoystickButton> decreaseRPMButton;
	std::shared_ptr<JoystickButton> increaseRPMButton;
	std::shared_ptr<JoystickButton> unjamButton;
	std::shared_ptr<JoystickButton> shootbutton;
	std::shared_ptr<JoystickButton> inSwitch;
	std::shared_ptr<JoystickButton> emergGearBtn;
	std::shared_ptr<Joystick> rightJoystick;
	std::shared_ptr<JoystickButton> gearBackBtn;
	std::shared_ptr<JoystickButton> intrptGGBtn;
	std::shared_ptr<Joystick> leftJoystick;
	std::shared_ptr<JoystickButton> bumpIntBtn;
	std::shared_ptr<JoystickButton> gearBtn;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	std::shared_ptr<JoystickButton> gearVisionBtn;
public:
	OI();

	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PROTOTYPES

	std::shared_ptr<Joystick> getLeftJoystick();
	std::shared_ptr<Joystick> getRightJoystick();
	std::shared_ptr<Joystick> getGamePad();

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=PROTOTYPES
};

#endif
