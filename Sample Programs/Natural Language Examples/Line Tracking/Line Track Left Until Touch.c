#pragma config(StandardModel, "EV3_REMBOT")
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

task main()
{
	repeatUntil (getTouchValue(touchSensor) == 1) {
		lineTrackLeft(colorSensor, 40, 60, 20);
	}
}
