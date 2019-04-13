#pragma config(Motor,  motorA,          clawMotor,     tmotorEV3_Medium, PIDControl, encoder)
#pragma config(Motor,  motorB,          leftMotor,     tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorC,          rightMotor,    tmotorEV3_Large, PIDControl, encoder)

const int driveSpeed = 50;
const int motorStop = 0;
const int reverseSpeed = -50;
const int turnSpeed = 40;

const float clawTime = 5;

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

void moveClaw(int statusCode, float time) {
  const int openClawSpeed = 25;
  const int closeClawSpeed = -25;

  if (statusCode == 0) {
    moveClawMotor(closeClawSpeed, time);
  } else if (statusCode == 1) {
    moveClawMotor(openClawSpeed, time);
  }
}

task main() {

  moveDriveMotor(1000, driveSpeed);
  moveMotorLeft(360, driveSpeed);
  moveMotorRight(1000, driveSpeed);
  moveDriveMotor(360, reverseSpeed);

}
