#pragma config(Motor,  motorA,          clawMotor,     tmotorEV3_Medium, PIDControl, encoder)
#pragma config(Motor,  motorB,          leftMotor,     tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorC,          rightMotor,    tmotorEV3_Large, PIDControl, encoder)

const int driveSpeed = 50;
const int motorStop = 0;
const int reverseSpeed = -50;
const int turnSpeed = 40;

const float clawTime = 5;

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

  //moveClaw(0, clawTime);
  moveMotor(-4, driveSpeed);
  moveMotor(5, driveSpeed);
  moveMotorLeft(2, turnSpeed);
  moveMotor(1, motorStop);
  //moveClaw(1, clawTime);

}
