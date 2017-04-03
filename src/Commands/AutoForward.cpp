// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "AutoForward.h"

#include "../Subsystems/DriveBase.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

AutoForward::AutoForward(double speed, double distance): Command() {
    m_speed = speed;
    m_distance = distance;
        // Use requires() here to declare subsystem dependencies
    // eg. requires(Robot::chassis.get());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
}

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void AutoForward::Initialize() {
	SetTimeout(4);
	m_distance = m_distance * 1330;
	Robot::driveBase->ResetGyro();
	Robot::driveBase->SetExp();
	Robot::driveBase->ResetEncoders();
}

// Called repeatedly when this Command is scheduled to run
void AutoForward::Execute() {
	SmartDashboard::PutNumber("Gyro Position", Robot::driveBase->getGAngle());
	SmartDashboard::PutNumber("Left Motor 1 enc pos", Robot::driveBase->getLeftEncPos());
	SmartDashboard::PutNumber("Right Motor 1 enc pos", Robot::driveBase->getRightEncPos());
	SmartDashboard::PutNumber("Left Motor .3 shoved left", -m_speed-(Robot::driveBase->getGAngle()*0.01));
	SmartDashboard::PutNumber("Right Motor Speed shoved left", m_speed+(Robot::driveBase->getGAngle()*0.01));
	SmartDashboard::PutNumber("Left Motor Speed shoved right", -m_speed+(Robot::driveBase->getGAngle()*0.01));
	SmartDashboard::PutNumber("Right Motor Speed shoved right", m_speed-(Robot::driveBase->getGAngle()*0.01));
	Robot::driveBase->straightAutonMethod(m_speed, m_distance);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoForward::IsFinished() {
	// Finished if at distance and no longer moving based on accelerometer, or ran out of time
	if (IsTimedOut() || (Robot::driveBase->CompareEncoders(m_distance)&& abs(Robot::driveBase->GetMomentum())<=0.1)) { //
		return true;
	} else
		return false;
}

// Called once after isFinished returns true
void AutoForward::End() {
	Robot::driveBase->driveMethod(0,0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoForward::Interrupted() {
	Robot::driveBase->driveMethod(0,0);
}
