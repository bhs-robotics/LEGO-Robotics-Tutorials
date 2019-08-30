# Challenge #1
## Basic Void Movements

For the first challenge, your goal is to code your robot to move from the starting square to the square in the upper left corner of the mat. I could care less how you drive there, however, you must code your robots using voids. For your reference, I have attached some sample code to the bottom of the file.

Good luck!

```
#pragma config(Motor,  motorB,          leftMotor,     tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorC,          rightMotor,    tmotorEV3_Large, PIDControl, encoder)

const int driveSpeed = 50;
const int motorStop = 0;
const int reverseSpeed = -50;
const int turnSpeed = 40;

void moveMotor(int time, int speed) {
	motor[leftMotor] = speed;
	motor[rightMotor] = speed;
	
	sleep(time * 1000);
	
	motor[leftMotor] = 0;
	motor[rightMotor] = 0;
}

void moveMotorLeft(int time, int speed) {
	motor[leftMotor] = speed;
	
	sleep(time * 1000);
	
	motor[leftMotor] = 0;
}

void moveMotorRight(int time, int speed) {
	motor[rightMotor] = speed;
	
	sleep(time * 1000);
	
	motor[rightMotor] = 0;
}

task main() {

	moveMotor(3, driveSpeed);
	moveMotorLeft(9, turnSpeed);

}
```
