// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "OI.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "SmartDashboard/SmartDashboard.h"
#include "Commands/AutoBackOut.h"
#include "Commands/AutoForward.h"
#include "Commands/AutoGearPlacement.h"
#include "Commands/AutoSonar.h"
#include "Commands/AutoTurn.h"
#include "Commands/AutonomousCommand.h"
#include "Commands/Center.h"
#include "Commands/DecreaseRPM.h"
#include "Commands/EmergGearCmd.h"
#include "Commands/GearGrp.h"
#include "Commands/GearRelease.h"
#include "Commands/GearVision.h"
#include "Commands/IncreaseRPM.h"
#include "Commands/IntakeCmd.h"
#include "Commands/IntakeTog.h"
#include "Commands/Move.h"
#include "Commands/ReturnOriginalRPM.h"
#include "Commands/ShooterCommand.h"
#include "Commands/UnjamCommand.h"


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

OI::OI() {
    // Process operator interface input here.
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    gamePad.reset(new Joystick(2));
    
    returnOriginalRPM.reset(new JoystickButton(gamePad.get(), 2));
    returnOriginalRPM->WhenPressed(new ReturnOriginalRPM());
    decreaseRPMButton.reset(new JoystickButton(gamePad.get(), 5));
    decreaseRPMButton->WhenPressed(new DecreaseRPM());
    increaseRPMButton.reset(new JoystickButton(gamePad.get(), 6));
    increaseRPMButton->WhenPressed(new IncreaseRPM());
    unjamButton.reset(new JoystickButton(gamePad.get(), 3));
    unjamButton->WhileHeld(new UnjamCommand());
    shootbutton.reset(new JoystickButton(gamePad.get(), 8));
    shootbutton->WhileHeld(new ShooterCommand());
    rightJoystick.reset(new Joystick(1));
    
    inSwitch.reset(new JoystickButton(rightJoystick.get(), 3));
    inSwitch->WhenPressed(new IntakeTog());
    leftJoystick.reset(new Joystick(0));
    
    emergGearBtn.reset(new JoystickButton(leftJoystick.get(), 10));
    emergGearBtn->WhenPressed(new EmergGearCmd());
    bumpIntBtn.reset(new JoystickButton(leftJoystick.get(), 3));
    bumpIntBtn->WhenPressed(new IntakeCmd());
    gearBtn.reset(new JoystickButton(leftJoystick.get(), 2));
    gearBtn->WhenPressed(new GearRelease());

    // SmartDashboard Buttons
    SmartDashboard::PutData("EmergGearCmd", new EmergGearCmd());
    SmartDashboard::PutData("IntakeCmd", new IntakeCmd());
    SmartDashboard::PutData("GearGrp", new GearGrp());
    SmartDashboard::PutData("ReturnOriginalRPM", new ReturnOriginalRPM());
    SmartDashboard::PutData("DecreaseRPM", new DecreaseRPM());
    SmartDashboard::PutData("IncreaseRPM", new IncreaseRPM());
    SmartDashboard::PutData("UnjamCommand", new UnjamCommand());
    SmartDashboard::PutData("ShooterCommand", new ShooterCommand());
    SmartDashboard::PutData("IntakeTog", new IntakeTog());
    SmartDashboard::PutData("AutoBackOut", new AutoBackOut(0,0));
    SmartDashboard::PutData("AutoSonar", new AutoSonar());
    SmartDashboard::PutData("Center", new Center());
    SmartDashboard::PutData("GearVision", new GearVision());
    SmartDashboard::PutData("AutoGearPlacement", new AutoGearPlacement(0));
    SmartDashboard::PutData("AutoTurn", new AutoTurn(0,0));
    SmartDashboard::PutData("AutoForward", new AutoForward(0,0));
    SmartDashboard::PutData("GearRelease", new GearRelease());
    SmartDashboard::PutData("Autonomous Command", new AutonomousCommand());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS

    gearVisionBtn.reset(new JoystickButton(rightJoystick.get(), 2));
    gearVisionBtn->WhenPressed(new GearGrp());
}

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS

std::shared_ptr<Joystick> OI::getLeftJoystick() {
   return leftJoystick;
}

std::shared_ptr<Joystick> OI::getRightJoystick() {
   return rightJoystick;
}

std::shared_ptr<Joystick> OI::getGamePad() {
   return gamePad;
}


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=FUNCTIONS
