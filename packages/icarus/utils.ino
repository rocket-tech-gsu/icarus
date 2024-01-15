#include "include/utils.h"

float last_altitude = 0;
float ground_altitude = 0;
float apogee_counter = 0;
float landing_counter = 0;

void handle_apogee(Adafruit_BMP085 bmp, Servo motor, float altitude)
{
	if (last_altitude > altitude && altitude > (ground_altitude + 10))
	{
		// apogee detected:
		apogee_counter++;
		if (apogee_counter > 5)
		{
			// apogee confirmed:
			motor.write(90);
		}
	}
	else if (altitude <= (ground_altitude + 3) && altitude >= (ground_altitude - 3))
	{
		// landing detected:
		landing_counter++;
		if (landing_counter > 30)
		{
			//////// landing confirmed: /////////
			Wire.endTransmission(true);	 // deactivate all I2C sensors
			delay(60 * 5 * 1000);		 // wait for the owner to reach
			tone(6, 200, 60 * 5 * 1000); // activate the buzzer
		}
	}
}