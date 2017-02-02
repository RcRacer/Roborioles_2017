// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.




#include "DriveBase.h"
#include "../RobotMap.h"
// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
#include "../Commands/Move.h"
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

DriveBase::DriveBase() : Subsystem("DriveBase") {
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    left1 = RobotMap::driveBaseLeft1;
    left2 = RobotMap::driveBaseLeft2;
    right1 = RobotMap::driveBaseRight1;
    right2 = RobotMap::driveBaseRight2;
    robotDrive41 = RobotMap::driveBaseRobotDrive41;

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
    sonar = RobotMap::driveBaseSonar;
	g = new ADXRS450_Gyro(SPI::Port::kOnboardCS0);
}

void DriveBase::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND

        SetDefaultCommand(new Move());

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}


// Put methods for controlling this subsystem
// here. Call these from Commands.

void DriveBase::DriveWithJoysticks() {
	float left= (Robot::oi->getLeftJoystick()->GetY());
	float right= (Robot::oi->getRightJoystick()->GetY());

	if(Robot::oi->getLeftJoystick()->GetRawButton(1) && Robot::oi->getRightJoystick()->GetRawButton(1))
	{
		left  = left * -0.5;
		right = right * -0.5;
		robotDrive41->TankDrive(-right,left);
	}

	else
	{
		robotDrive41->TankDrive(-left,right);
	}
}

void DriveBase::DriveWithGamepad() {
	float left= (Robot::oi->getGamePad()->GetY());
	float right= (Robot::oi->getGamePad()->GetThrottle());

	robotDrive41->TankDrive(-left,right);
}

void DriveBase::driveMethod(float left, float right) {
	robotDrive41->TankDrive(-left,right);
}

double DriveBase::getGAngle() {
	return Robot::driveBase->g->GetAngle();
}

void DriveBase::ResetGyro() {
	 Robot::driveBase->g->Reset();
}

void DriveBase::SetExp() {
	left1->SetExpiration(5000);
	left1->SetSafetyEnabled(false);
	left2->SetExpiration(5000);
	left2->SetSafetyEnabled(false);
	right1->SetExpiration(5000);
	right1->SetSafetyEnabled(false);
	right2->SetExpiration(5000);
	right2->SetSafetyEnabled(false);
	robotDrive41->SetExpiration(5000);
	robotDrive41->SetSafetyEnabled(false);
}

void DriveBase::ResetEncoders() {
		Robot::driveBase->left1->SetEncPosition(0);
		Robot::driveBase->right1->SetEncPosition(0);
}

bool DriveBase::CompareEncoders(double distance) {
	if ((distance > 0 && Robot::driveBase->left1->GetEncPosition() >= distance && Robot::driveBase->right1->GetEncPosition() >= distance) || (distance < 0 && Robot::driveBase->left1->GetEncPosition() <= distance && Robot::driveBase->right1->GetEncPosition() <= distance)) {
		return true;
	}
	return false;
}

double DriveBase::getLeftEncPos() {
	return Robot::driveBase->left1->GetEncPosition();
}

double DriveBase::getRightEncPos() {
	return Robot::driveBase->right1->GetEncPosition();
}

void DriveBase::straightAutonMethod(double speed, double distance) {
	if (Robot::driveBase->getLeftEncPos() > distance && Robot::driveBase->getLeftEncPos() > distance){
		if (Robot::driveBase->getGAngle() > -1) {
			//veering right
			Robot::driveBase->left1->Set((speed-(getGAngle()*0.01)));
			Robot::driveBase->right1->Set((speed+(getGAngle()*0.01)));
			Robot::driveBase->left2->Set((speed-(getGAngle()*0.01)));
			Robot::driveBase->right2->Set((speed+(getGAngle()*0.01)));
		} else if (Robot::driveBase->getGAngle() < 1) {
			//veering left
			Robot::driveBase->left1->Set((speed-(getGAngle()*0.01)));
			Robot::driveBase->right1->Set((speed+(getGAngle()*0.01)));
			Robot::driveBase->left2->Set((speed-(getGAngle()*0.01)));
			Robot::driveBase->right2->Set((speed+(getGAngle()*0.01)));
		} else {
			Robot::driveBase->left1->Set(speed);
			Robot::driveBase->right1->Set(speed);
			Robot::driveBase->left2->Set(speed);
			Robot::driveBase->right2->Set(speed);
		}
	} else {
		Robot::driveBase->driveMethod(0,0);
	}
}

void DriveBase::AutoDriveFeet(){
	left1->Set(-0.95);
	left2->Set(-0.95);
	right1->Set(1);
	right2->Set(1);
	Wait(1);
	left1->Set(0);
	left2->Set(0);
	right1->Set(0);
	right2->Set(0);

}

void DriveBase::setCoastBreak(bool type) {
	//if bool is true, set it to coast. if bool is false, set it to brake
	if(type) {
		left1->ConfigNeutralMode(CANSpeedController::NeutralMode::kNeutralMode_Coast);
		left2->ConfigNeutralMode(CANSpeedController::NeutralMode::kNeutralMode_Coast);
		right1->ConfigNeutralMode(CANSpeedController::NeutralMode::kNeutralMode_Coast);
		right2->ConfigNeutralMode(CANSpeedController::NeutralMode::kNeutralMode_Coast);
	} else {
		left1->ConfigNeutralMode(CANSpeedController::NeutralMode::kNeutralMode_Brake);
		left2->ConfigNeutralMode(CANSpeedController::NeutralMode::kNeutralMode_Brake);
		right1->ConfigNeutralMode(CANSpeedController::NeutralMode::kNeutralMode_Brake);
		right2->ConfigNeutralMode(CANSpeedController::NeutralMode::kNeutralMode_Brake);
	}


}

bool DriveBase::CenterRobot(int t) {
	uint16_t xPosition1 = 0;
	uint16_t yPosition1 = 0;
	uint16_t width1 = 0;
	uint16_t height1 = 0;
	uint16_t xPosition2 = 0;
	uint16_t yPosition2 = 0;
	uint16_t width2 = 0;
	uint16_t height2 = 0;
	int center = 0;
	bool finished= false;

	uint8_t* pixyValues = new uint8_t[64];
	pixyValues[0] = (uint8_t) 0b01010101;
	pixyValues[1] = (uint8_t) 0b10101010;

	// Only check the camera once every 50 times this method is called
	if (t%50 == 0) {

		RobotMap::pixyi2c->ReadOnly(64,pixyValues);

		if (pixyValues != NULL) {
			int i = 0;

			/* for (int j=0;j<64;j++) {
				printf("%2i %#x",j,pixyValues[j]);
				if((j+1)%16==0) { printf("\n"); }
			} */

			// find first sync word
			while (!(((pixyValues[i] & 0xff) == 0x55) && ((pixyValues[i + 1] & 0xff) == 0xaa)) && i < 50) {
				i++;
			}
			i++;

			// check if the index is getting so high that you can�t align and see an entire frame.  Ensure it isn�t
			if (i > 50) { i = 49; }

			// find second sync word, which is the start of a frame
			while (!(((pixyValues[i] & 0xff) == 0x55) && ((pixyValues[i + 1] & 0xff) == 0xaa)) && i < 50) {
				i++;
			}

			xPosition1 = (uint16_t) (((pixyValues[i + 7] & 0xff) << 8) | (pixyValues[i + 6] & 0xff));
			yPosition1 = (uint16_t) (((pixyValues[i + 9] & 0xff) << 8) | (pixyValues[i + 8] & 0xff));
			width1 = (uint16_t) (((pixyValues[i + 11] & 0xff) << 8) | (pixyValues[i + 10] & 0xff));
			height1 = (uint16_t) (((pixyValues[i + 13] & 0xff) << 8) | (pixyValues[i + 12] & 0xff));

			// print results, including index within byte array, signature number, and coordinates
			printf("target 1 i: %i (%i,%i) w: %i,h: %i\n",i,xPosition1,yPosition1,width1,height1);

			// Find second target
			i++;
			// find sync word, which is the start of the next target
			while (!(((pixyValues[i] & 0xff) == 0x55) && ((pixyValues[i + 1] & 0xff) == 0xaa)) && i < 50) {
				i++;
			}

			xPosition2 = (uint16_t) (((pixyValues[i + 7] & 0xff) << 8) | (pixyValues[i + 6] & 0xff));
			yPosition2 = (uint16_t) (((pixyValues[i + 9] & 0xff) << 8) | (pixyValues[i + 8] & 0xff));
			width2 = (uint16_t) (((pixyValues[i + 11] & 0xff) << 8) | (pixyValues[i + 10] & 0xff));
			height2 = (uint16_t) (((pixyValues[i + 13] & 0xff) << 8) | (pixyValues[i + 12] & 0xff));

			// print results, including index within byte array, signature number, and coordinates
			//printf("target 2 i: %i (%i,%i) w: %i,h: %i\n",i,xPosition2,yPosition2,width2,height2);

			center = (xPosition1+xPosition2)/2;

			// +/- 5% (152 - 168) of center (160)
			if ((xPosition1==0)|(xPosition2==0)) {
			//	printf("No target");
				right1->Set(0);
				right2->Set(0);
				left1->Set(0);
				left2->Set(0);
				finished= false;
			} else if(center<152) {
				//printf("\nTurning left\n");
				// Actually turning right, because we are facing backwards
				right1->Set(0.2);
				right2->Set(0.2);
				left1->Set(-0.2);
				left2->Set(-0.2);
				finished= false;
			} else if ((center > 152) & (center < 168)) {
				//printf("\nMove forward\n");
				right1->Set(0);
				right2->Set(0);
				left1->Set(0);
				left2->Set(0);
				finished= true;
			} else {
				//printf("\nTurn right\n");
				right1->Set(-0.2);
				right2->Set(-0.2);
				left1->Set(0.2);
				left2->Set(0.2);
				finished= false;
			}

		}
	}
	return finished;
}

void DriveBase::setSonar() {
	sonar->SetAutomaticMode(true);
}

double DriveBase::SonarInches() {
	return sonar->GetRangeInches();
}
