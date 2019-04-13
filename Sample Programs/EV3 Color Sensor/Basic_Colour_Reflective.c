#pragma config(Sensor, S3,     Colour,         sensorEV3_Color, modeEV3Color_Reflected)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

/*
Colour sensor modes
0 - modeEV3Color_Reflected
1 - modeEV3Color_Ambient
2 - modeEV3Color_Color
3 - modeEV3Color_Reflected_Raw
4 - modeEV3Color_RGB_Raw
5 - modeEV3Color_Calibration - Not utilized
*/

task main()
{
	while (true)
	{
		// Write the amount of reflected light to the screen
	  // This is a value between 0 and 100, where 0 means no reflected
	  // light and 100 means all light is being reflected
		displayBigTextLine(4, "Reflected: %d", SensorValue[Colour]);

		// Wait 20 ms to get 50 readings per second
		sleep(20);
	}
}
