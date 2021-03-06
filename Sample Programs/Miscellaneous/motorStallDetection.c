#pragma config(Motor,  motorA,          motL,          tmotorEV3_Large, PIDControl, encoder)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

// Motor stall detection example

const int threshold = 50;		// An RPM below 50% the expected RPM value at a specific
														// speed will be considered a stall
const int rpm_large = 175;	// This is the official RPM an unloaded large EV3/NXT motor has
const int rpm_medium = 260; // This is the official RPM an unloaded medium EV3 motor has

task stallDetect()
{
	long required_rpm = 0;
	while (true)
	{
		// If the motor's RPM falls below this
		for (int i = 0; i < kNumbOfRealMotors; i++)
		{
			//writeDebugStreamLine("Processing motor %d", i);
			switch (motorType[i])
			{
				case tmotorEV3_Large:
				case tmotorNXT:
					//writeDebugStreamLine("motor %d is a large motor", i);
					required_rpm = (motor[i] * rpm_large * threshold) / 10000;
					break;
				case tmotorEV3_Medium:
					required_rpm = (motor[i] * rpm_medium * threshold) / 10000;
					break;
				default:
					continue;
			}

			if (getMotorRPM(i) < required_rpm)
				writeDebugStreamLine("motor %d is stalled", i);
		}
		// No need to sample more frequently than that as the RPM value is not
		// updated more frequently than this.
		sleep(100);
	}
}

task main()
{
	// Start the stallDetect task
	startTask(stallDetect);

	motor[motL] = 80;
	while(true)
	{
		sleep(100);
	}

}
