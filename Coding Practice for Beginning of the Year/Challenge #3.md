# Challenge #3
## Advanced If Statements

For the third challenge, we are building mainly on the 2nd challenge! SO much fun!

You are going to use a WHILE and IF statement together to make a 'motor debugging' program.
  - The UP button (buttonUp) is for making the robot move forward.
  - The DOWN button (buttonDown) is for making the robot move backward.
  - The LEFT button (buttonLeft) is for making the robot move left.
  - The RIGHT button (buttonRight) is for making the robot move right.

Good luck!

## How to Branch IF Statements

It is very easy to make multiple cases, or branchs, in IF statements.

Some sample code of this is below.

```
if (getButtonPress(buttonUp)) {
    moveMotor(100);
} else if (getButtonPress(buttonDown)) {
    moveMotor(-100);
} else if (getButtonPress(buttonLeft)) {
    moveLeft(100);
} else if (getButtonPress(buttonRight)) {
    moveRight(100);
} else {
    moveMotor(0);
}
```

## Steps

### #1) Setup Motors

You can setup your motors by clicking the "Motors and Sensors Setup" button on the top toolbar.

```
#pragma config(Motor,  motorB,          leftMotor,     tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorC,          rightMotor,    tmotorEV3_Large, PIDControl, encoder)
```

### #2) Add Global Variables for Default Motor Speeds

```
const int driveSpeed = 50;
const int motorStop = 0;
const int reverseSpeed = -50;
const int turnSpeed = 40;
```

### #3) Add VOIDs for Robot Movement

- The moveMotor VOID is self explanatory.
- The moveLeft VOID holds, or stops, the left and turns the right motor, causing the robot to move in the left direction.
- The moveRight VOID holds, or stops, the right and turns the left motor, causing the robot to move in the right direction.

```
void moveMotor(int speed) {
	motor[leftMotor] = speed;
	motor[rightMotor] = speed;
}

void moveLeft(int speed) {
	motor[leftMotor] = 0;
	motor[rightMotor] = speed;
}

void moveRight(int speed) {
	motor[leftMotor] = speed;
	motor[rightMotor] = 0;
}
```

### #4) Make the WHILE Statement in the task main()

By the way, "// TODO:" is generally a comment that you make when you are not quite finished with something. This makes it easy to find the spots where things need to be done in your code.

```
task main() {

  // Use the while(true) statement to keep this code running forever
  while (true) {
     
     // TODO: Create a Branching IF Statement
     
     // Pause the execution for a short period of time to prevent over running the CPU
     sleep(20);
  }

}
```

### #5) Make the Branching IF Statement

By the way, "// TODO:" is generally a comment that you make when you are not quite finished with something. This makes it easy to find the spots where things need to be done in your code.

```
task main() {

  // Use the while(true) statement to keep this code running forever
  while (true) {
     
     // Check to see what buttons are pressed
     if (getButtonPress(buttonUp)) {
    	// TODO: Add Motor Motion
     } else if (getButtonPress(buttonDown)) {
        // TODO: Add Motor Motion
     } else if (getButtonPress(buttonLeft)) {
        // TODO: Add Motor Motion
     } else if (getButtonPress(buttonRight)) {
        // TODO: Add Motor Motion
     } else {
        // TODO: Add Motor Motion
     }
     
     // Pause the execution for a short period of time to prevent over running the CPU
     sleep(20);
  }

}
```

### #6) Add the Motor Motion

```
task main() {

  // Use the while(true) statement to keep this code running forever
  while (true) {
     
     // Check to see what buttons are pressed
     if (getButtonPress(buttonUp)) {
    	moveMotor(driveSpeed);
     } else if (getButtonPress(buttonDown)) {
        moveMotor(reverseSpeed);
     } else if (getButtonPress(buttonLeft)) {
        moveLeft(turnSpeed);
     } else if (getButtonPress(buttonRight)) {
        moveRight(turnSpeed);
     } else {
        moveMotor(motorStop);
     }
     
     // Pause the execution for a short period of time to prevent over running the CPU
     sleep(20);
  }

}
```

## Complete Sample Code

The complete code is below!

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

void moveLeft(int speed) {
	motor[leftMotor] = 0;
	motor[rightMotor] = speed;
}

void moveRight(int speed) {
	motor[leftMotor] = speed;
	motor[rightMotor] = 0;
}

task main() {

  // Use the while(true) statement to keep this code running forever
  while (true) {
     
     // Check to see what buttons are pressed
     if (getButtonPress(buttonUp)) {
    	moveMotor(driveSpeed);
     } else if (getButtonPress(buttonDown)) {
        moveMotor(reverseSpeed);
     } else if (getButtonPress(buttonLeft)) {
        moveLeft(turnSpeed);
     } else if (getButtonPress(buttonRight)) {
        moveRight(turnSpeed);
     } else {
        moveMotor(motorStop);
     }
     
     // Pause the execution for a short period of time to prevent over running the CPU
     sleep(20);
  }

}
```

Due to some of the syntax, this sample code might not work as expected. If this happens, please ask me for help!

## Think About

1. What would happen if you clicked multiple buttons at the same time?
2. What would happen if you did not add the following code to the end of the branching IF statement?

```
} else {
    moveMotor(motorStop);
}
```

3. What would happen if you modified the variables for default speeds? Would the robot's speed change when you clicked different buttons?
4. What would happen if you said "while (false)" instead of "while (true)?"

## Super FUN Challenge

Try to make the default speeds change when you click the center button.

1. Remove the constant declaration from the global variables for default speeds.
2. Add a case to the branching IF statement for the "buttonEnter." (Remember that the "else" statement must be last. Therefore, put the case for "buttonEnter" in between the case for "buttonRight" and the "else" statement.)
3. Create another variable (int) for "speedCase" and set the default value to 1.
4. Inside the case for "buttonEnter" add a IF statement for if the "speedCase" variable is 1 or 2.
5. Inside each IF statement, change the variable to the opposite.
6. Set up the new speeds, replacing the global variables values, inside each IF statement.
7. Add a WHILE to prevent a very quick FALLTHROUGH! (Doesn't that even sound FUN! Ask me what this means.)
8. Celebrate your first SUPER AWESOME program!

I added some quick reference to show what I mean below! (This is what would go inside the case for "buttonEnter.")

```
if (speedCase == 1) {
    speedCase = 2;
    
    // Code for Speed Case 2
    driveSpeed = 100;
    motorStop = 0;
    reverseSpeed = -75;
    turnSpeed = 80;
    
    // This is necessary to prevent fallthrough
    while (getButtonPress(buttonEnter)) { }
} else if (speedCase == 2) {
    speedCase = 1;
    
    // Code for Speed Case 1
    driveSpeed = 50;
    motorStop = 0;
    reverseSpeed = -50;
    turnSpeed = 40;
    
    // This is necessary to prevent fallthrough
    while (getButtonPress(buttonEnter)) { }
}
```
