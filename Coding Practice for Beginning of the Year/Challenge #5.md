# Challenge #5
## Robot Coding Challenge: Advanced IF and WHILE Statements

For this challenge, you are using what you know from the previous challenges to make the robot use sensors to move around the mat.

Your robot is going to start in the starting box, drive North at 50 power, then wait for the touch sensor to be clicked by the upper wall. Once it is clicked, the robot must stop, back up, turn around, then drive forward towards the South wall. Once the sensor is clicked, then for the last time, stop the robot.

Good luck and happy coding!

## Reference

To access the value of a touch sensor, use the following command.

```
getTouchValueSensorName]
```

## Sample Code

```
task main() {
    moveMotor(50);
    while (!getTouchValue[name]) { }
    moveMotor(0);
    moveMotor(-50);
    // Turn
    moveMotor(50);
    while (!getTouchValue[name]) { }
    moveMotor(0);
}
```
