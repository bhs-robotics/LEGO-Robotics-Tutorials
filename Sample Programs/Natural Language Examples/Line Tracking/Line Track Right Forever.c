#pragma config(StandardModel, "EV3_REMBOT")
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	repeat (forever) {
		lineTrackRight(colorSensor, 50, 50, 0);
	}
}
