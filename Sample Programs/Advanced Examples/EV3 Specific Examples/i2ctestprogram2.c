#pragma config(Sensor, S2,     I2CSENSOR,      sensorEV3_GenericI2C)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

char pReplyMsg[32];


const int kI2CAddress    = 0xA4;    // You may want to make this a function parameter
const int kRegisterIndex = 0x08;    // You may want to make this a function parameter
const int kReplyLength = 16;

void pollSensor1()
{
	const ubyte nMsg[] =
	{
		2,               // This is length field for transmitted message.
		kI2CAddress,         // The I2C address of the device. Almost all devices use value '0x02'
		kRegisterIndex,      // The internal register index within the sensor to start writing at.
	};

	memset(pReplyMsg, 0, 32);
	writeDebugStreamLine("status sendI2CMsg: %d", sendI2CMsg(I2CSENSOR, &nMsg[0], kReplyLength));

	while ((nI2CStatus[I2CSENSOR] != i2cStatusNoError) && (nI2CStatus[I2CSENSOR] != i2cStatusStopped))
	{
		//writeDebugStreamLine("XX status: %d", nI2CStatus[I2CSENSOR]);
		wait1Msec(1);
	}
	writeDebugStreamLine("status readI2CReply: %d", readI2CReply(I2CSENSOR, pReplyMsg, kReplyLength));
	//nStatus = readI2CReply(I2CSENSOR, pReplyMsg, kReplyLength);
}

task main()
{
	for (int i = 0; i < 10; i++)
	{
		pollSensor1();
		//while ((nI2CStatus[I2CSENSOR] != i2cStatusNoError) && (nI2CStatus[I2CSENSOR] != i2cStatusStopped))
		//{
		//	writeDebugStreamLine("YY status: %d", nI2CStatus[I2CSENSOR]);
		//	wait1Msec(10);
		//}
	}
}
