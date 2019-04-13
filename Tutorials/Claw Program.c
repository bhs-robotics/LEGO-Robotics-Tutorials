#pragma config(Motor,  motorA,          clawMotor,     tmotorEV3_Medium, PIDControl, encoder)
#pragma config(Motor,  motorB,          leftMotor,     tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorC,          rightMotor,    tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorD,          liftMotor,     tmotorEV3_Medium, PIDControl, encoder)

const int driveSpeed = 50;
const int motorStop = 0;
const int reverseSpeed = -50;
const int turnSpeed = 40;

const float clawTime = 2;
const float liftTime = 3;

void moveDriveMotor(int degrees, int speed) {
	nMotorEncoder[leftMotor] = 0;
	nMotorEncoder[rightMotor] = 0;

	const float waitTime = (degrees + speed) / 0.8;
	setMotorSyncTime(leftMotor, rightMotor, 0, degrees, speed);
	delay(waitTime);
}

void moveMotorLeft(int degrees, int speed) {
	nMotorEncoder[leftMotor] = 0;
	nMotorEncoder[rightMotor] = 0;

	const float waitTime = (degrees + speed) / 0.8;
	setMotorSyncTime(leftMotor, rightMotor, 100, degrees, speed);
	delay(waitTime);
}

void moveMotorRight(int degrees, int speed) {
	nMotorEncoder[leftMotor] = 0;
	nMotorEncoder[rightMotor] = 0;

	const float waitTime = (degrees + speed) / 0.8;
	setMotorSyncTime(leftMotor, rightMotor, -100, degrees, speed);
	delay(waitTime);
}

void moveClawMotor(int speed, float time) {
	const int clawStopSpeed = 0;
	const float waitTime = time * 1000;

	motor[clawMotor] = speed;
	delay(waitTime);
	motor[clawMotor] = clawStopSpeed;
}

void moveLiftMotor(int speed, float time) {
	const int liftStopSpeed = 0;
	const float waitTime = time * 1000;

	motor[liftMotor] = speed;
	delay(waitTime);
	motor[liftMotor] = liftStopSpeed;
}


void moveClaw(int liftCode, int clawCode, float time) {
	const int openClawSpeed = 25;
	const int closeClawSpeed = -25;
	const int liftUpSpeed = -20;
	const int liftDownSpeed = 20;

	if (liftCode == 0) {
		} else if (liftCode == 1) {
		moveLiftMotor(liftUpSpeed, liftTime);
		} else if (liftCode == 2) {
		moveLiftMotor(liftDownSpeed, liftTime);
	}

	if (clawCode == 1) {
		moveClawMotor(closeClawSpeed, time);
		} else if (clawCode == 2) {
		moveClawMotor(openClawSpeed, time);
	}
}

task main()	{

	moveDriveMotor(3600, driveSpeed);
	//moveClaw(0, 2, clawTime);//
	moveMotorRight(70, turnSpeed);
	moveDriveMotor(2600,driveSpeed);
}
