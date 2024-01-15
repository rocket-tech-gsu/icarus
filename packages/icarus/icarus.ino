#include "include/icarus.h"

void setup()
{
	setup_components();
}

void loop()
{
	File sd_card_log_file = SD.open("sd_card.csv", FILE_WRITE);

	// mpu
	Wire.beginTransmission(MPU_ADDR);
	Wire.write(0x3B);						 // starting with register 0x3B (ACCEL_XOUT_H) [MPU-6000 and MPU-6050 Register Map and Descriptions Revision 4.2, p.40]
	Wire.endTransmission(false);			 // the parameter indicates that the Arduino will send a restart. As a result, the connection is kept active.
	Wire.requestFrom(MPU_ADDR, 7 * 2, TRUE); // request a total of 7*2=14 registers

	float accelerometer_x = READ_WIRE(Wire); // reading registers: 0x3B (ACCEL_XOUT_H) and 0x3C (ACCEL_XOUT_L)
	float accelerometer_y = READ_WIRE(Wire); // reading registers: 0x3D (ACCEL_YOUT_H) and 0x3E (ACCEL_YOUT_L)
	float accelerometer_z = READ_WIRE(Wire); // reading registers: 0x3F (ACCEL_ZOUT_H) and 0x40 (ACCEL_ZOUT_L)
}