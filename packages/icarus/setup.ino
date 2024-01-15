#include "include/setup.h"

void setup_components()
{
	Serial.begin(9600);
	while (!Serial)
	{
	} // wait for serial port to connect

	// setup sd card
	while (digitalRead(BUTTON_ONE) == LOW)
	{
		;
	}

	if (!SD.begin(SD_CARD_CSPIN))
	{
		Serial.println("[-] SD Card Setup – card either failed or not present.");
		exit(EXIT_FAILURE);
	}
	else
	{
		Serial.println("[+] SD Card Setup – card setup successfully.");
	}

	// setup mpu6050
	Wire.begin();
	Wire.beginTransmission(MPU_ADDR);
	Wire.write(0x6B); // PWR_MGMT_1 register
	Wire.write(0);	  // set to zero (wakes up the MPU-6050)
	if (Wire.endTransmission(true) != 0)
	{
		Serial.println("[-] BMP180 setup – BMP180 either failed or not present.");
		exit(EXIT_FAILURE);
	}

	TinyGPSPlus gps;
	SoftwareSerial ss(4, 3);
	ss.begin(9600);
	if (ss.available())
	{
		gps.encode(ss.read());
		if (gps.location.isUpdated())
		{
			Serial.print("Latitude = ");
			Serial.print(gps.location.lat(), 6);
			Serial.print(" Longitude= ");
			Serial.println(gps.location.lng(), 6);
		}
	}
	else
	{
		Serial.println("GPS failed, or not present");
		exit(2);
	}
}