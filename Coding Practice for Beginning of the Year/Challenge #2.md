# Challenge #2
## Basic If Statements

For the second challenge, we are building on what you already know! Fun!

You are going to use a WHILE and IF statement to get your robot to move only while you are clicking the center button.

Good luck!

```
#pragma config(Motor,  motorB,          leftMotor,     tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorC,          rightMotor,    tmotorEV3_Large, PIDControl, encoder)

const int driveSpeed = 50;
const int motorStop = 0;
const int reverseSpeed = -50;
const int turnSpeed = 40;

void moveMotor(int speed) {
	motor[leftMotor] = speed;
	motor[rightMotor] = speed;
}

task main() {

  // Use the while(true) statement to keep this code running forever
  while (true) {
     
     // Check if the Enter button is clicked
     if (getButtonPress(buttonEnter)) {
     
        // If it is clicked, move the robot forward
        moveMotor(100);
     } else {
     
        // If it is not clicked, do not move the robot forward
        moveMotor(0);
     }
     
     // Pause the execution for a short period of time to prevent over running the CPU
     sleep(20);
  }

}
```

