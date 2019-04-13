#pragma config(Motor,  motorB,          leftMotor,     tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorC,          rightMotor,    tmotorEV3_Large, PIDControl, encoder)

const int driveSpeed = 50;
const int motorStop = 0;
const int reverseSpeed = -50;
const int turnSpeed = 40;

void moveMotor(int degrees, int speed) {

	nMotorEncoder[leftMotor] = 0;
	nMotorEncoder[rightMotor] = 0;

	setMotorSyncEncoder(leftMotor, rightMotor, 0, degrees, speed);

	while (getMotorEncoder(leftMotor) != degrees) {
		motor[leftMotor] = speed;
		motor[rightMotor] = speed;
	}

	motor[leftMotor] = 0;
	motor[rightMotor] = 0;
}

void moveMotorLeft(int degrees, int speed) {
	nMotorEncoder[leftMotor] = 0;

	while (getMotorEncoder(leftMotor) != degrees) {
		motor[leftMotor] = speed;
	}

	motor[leftMotor] = motorStop;
}

void moveMotorRight(int degrees, int speed) {
	nMotorEncoder[rightMotor] = 0;

	while (getMotorEncoder(rightMotor) != degrees) {
		motor[rightMotor] = speed;
	}

	motor[rightMotor] = motorStop;
}

task main() {

	moveMotor(360, driveSpeed);
	moveMotorLeft(90, turnSpeed);

}
