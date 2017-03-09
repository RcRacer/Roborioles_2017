// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "RobotMap.h"
#include "LiveWindow/LiveWindow.h"
#include "WPILib.h"
#include "I2C.h"

I2C* RobotMap::pixyi2c = NULL;


// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION
std::shared_ptr<CANTalon> RobotMap::driveBaseLeft1;
std::shared_ptr<CANTalon> RobotMap::driveBaseLeft2;
std::shared_ptr<CANTalon> RobotMap::driveBaseRight1;
std::shared_ptr<CANTalon> RobotMap::driveBaseRight2;
std::shared_ptr<RobotDrive> RobotMap::driveBaseRobotDrive41;
std::shared_ptr<Ultrasonic> RobotMap::driveBaseSonar;
std::shared_ptr<Ultrasonic> RobotMap::driveBaseShootsensor;
std::shared_ptr<Solenoid> RobotMap::gearPneumaticsGearSolen;
std::shared_ptr<Compressor> RobotMap::gearPneumaticsCompressor;
std::shared_ptr<SpeedController> RobotMap::intakeMotIntakeM1;
std::shared_ptr<SpeedController> RobotMap::intakeMotIntakeM2;
std::shared_ptr<CANTalon> RobotMap::shooterSubsystemtalonController;
std::shared_ptr<CANTalon> RobotMap::shooterSubsystemtalonController2;
std::shared_ptr<SpeedController> RobotMap::shooterSubsystemfeederMotor;
std::shared_ptr<SpeedController> RobotMap::shooterSubsystemaugerMotor;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=ALLOCATION

std::shared_ptr<Ultrasonic> RobotMap::driveBaseShootSensor;
std::shared_ptr<Solenoid> RobotMap::driveBaseTargetLight;
std::shared_ptr<Solenoid> RobotMap::driveBaseWarningLight;
std::shared_ptr<Solenoid> RobotMap::driveBaseShooterLight;

#include "CANTalon.h"

void RobotMap::init() {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    LiveWindow *lw = LiveWindow::GetInstance();

    driveBaseLeft1.reset(new CANTalon(3));
    lw->AddActuator("DriveBase", "Left1", driveBaseLeft1);
    
    driveBaseLeft2.reset(new CANTalon(4));
    lw->AddActuator("DriveBase", "Left2", driveBaseLeft2);
    
    driveBaseRight1.reset(new CANTalon(1));
    lw->AddActuator("DriveBase", "Right1", driveBaseRight1);
    
    driveBaseRight2.reset(new CANTalon(2));
    lw->AddActuator("DriveBase", "Right2", driveBaseRight2);
    
    driveBaseRobotDrive41.reset(new RobotDrive(driveBaseLeft1, driveBaseLeft2,
              driveBaseRight1, driveBaseRight2));
    
    driveBaseRobotDrive41->SetSafetyEnabled(true);
        driveBaseRobotDrive41->SetExpiration(0.1);
        driveBaseRobotDrive41->SetSensitivity(0.5);
        driveBaseRobotDrive41->SetMaxOutput(1.0);

    driveBaseSonar.reset(new Ultrasonic(0, 1));
    lw->AddSensor("DriveBase", "Sonar", driveBaseSonar);
    
    driveBaseShootsensor.reset(new Ultrasonic(2, 3));
    lw->AddSensor("DriveBase", "Shootsensor", driveBaseShootsensor);
    
    gearPneumaticsGearSolen.reset(new Solenoid(0, 1));
    lw->AddActuator("GearPneumatics", "GearSolen", gearPneumaticsGearSolen);
    
    gearPneumaticsCompressor.reset(new Compressor(0));
    
    
    intakeMotIntakeM1.reset(new Talon(2));
    lw->AddActuator("IntakeMot", "IntakeM1", std::static_pointer_cast<Talon>(intakeMotIntakeM1));
    
    intakeMotIntakeM2.reset(new Talon(3));
    lw->AddActuator("IntakeMot", "IntakeM2", std::static_pointer_cast<Talon>(intakeMotIntakeM2));
    
    shooterSubsystemtalonController.reset(new CANTalon(5));
    lw->AddActuator("ShooterSubsystem", "talonController", shooterSubsystemtalonController);
    
    shooterSubsystemtalonController2.reset(new CANTalon(6));
    lw->AddActuator("ShooterSubsystem", "talonController2", shooterSubsystemtalonController2);
    
    shooterSubsystemfeederMotor.reset(new Talon(1));
    lw->AddActuator("ShooterSubsystem", "feederMotor", std::static_pointer_cast<Talon>(shooterSubsystemfeederMotor));
    
    shooterSubsystemaugerMotor.reset(new Talon(0));
    lw->AddActuator("ShooterSubsystem", "augerMotor", std::static_pointer_cast<Talon>(shooterSubsystemaugerMotor));
    


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTORS
    pixyi2c = new I2C(I2C::kOnboard,0x54);
    driveBaseTargetLight.reset(new Solenoid(0, 2));
    driveBaseWarningLight.reset(new Solenoid(0, 3));

    driveBaseShootSensor.reset(new Ultrasonic(2,3));
    lw->AddSensor("DriveBase", "ShootSensor", driveBaseShootSensor);

    driveBaseShooterLight.reset(new Solenoid(0, 4));
}
