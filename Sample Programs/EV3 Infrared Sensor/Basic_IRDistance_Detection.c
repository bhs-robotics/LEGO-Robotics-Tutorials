#pragma config(Sensor, S2,     IRDistance1,    sensorEV3_IRSensor, modeEV3IR_Proximity)
#pragma config(Motor,  motorB,          motorLeft,     tmotorEV3_Large, PIDControl, encoder)
#pragma config(Motor,  motorC,          motorRight,    tmotorEV3_Large, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
IR Seeker Modes
0 - modeEV3IR_Proximity
1 - modeEV3IR_Seeker
2 - modeEV3IR_Remote
3 - modeEV3IR_Remote_Advanced
5 - modeEV3IR_Calibration
*/

task main()
{
	// Distance to maintain to the target.
  // This a percentage value of 0-100 and is not an actual distance
  // The value returns depends heavily on the type of material you are
  // measuring the distance to.  For example, cloth will absorb a lot of
  // the IR light and give a very high reading (big distance).
  // A while wall will reflect much more light, resulting in a lower
  // reading for the same distance.
	int distanceToMaintain = 30;

	int currentDistance = 0;

	while(true)
	{
		// Read the sensor
		currentDistance = SensorValue[IRDistance1];

		displayCenteredBigTextLine(4, "Dist: %d", currentDistance);

		// We're too far away, move forward
		if ((distanceToMaintain - currentDistance) < -2)
		{
			motor[motorLeft] = 30;
			motor[motorRight] = 30;
		}
		// We're too close, move backwards
		else if ((distanceToMaintain - currentDistance) > 2)
		{
			motor[motorLeft] = -30;
			motor[motorRight] = -30;
		}
		// We're good, don't go anywhere
		else
		{
			motor[motorLeft] = 0;
			motor[motorRight] = 0;
		}

		//Loop to monitor value in Sensor debugger window
		sleep(50);
	}
}
