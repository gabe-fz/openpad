#include "HX711.h"


// (data, clock)
HX711 leftSensor(2, 3);
HX711 downSensor(4, 5);
HX711 upSensor(6, 7);
HX711 rightSensor(8, 9);

float leftVal = 0.0;
float downVal = 0.0;
float upVal = 0.0;
float rightVal = 0.0;

int count = 0;

void setup() {

	Serial.begin(9600);

	leftSensor.set_scale(2280.f);
	leftSensor.tare();
	downSensor.set_scale(2280.f);
	downSensor.tare();
	upSensor.set_scale(2280.f);
	upSensor.tare();
	rightSensor.set_scale(2280.f);
	rightSensor.tare();
}

void loop() {


	leftVal = leftSensor.get_units(1);
	downVal = downSensor.get_units(1);
	upVal = upSensor.get_units(1);
	rightVal = rightSensor.get_units(1);

/*
	switch (count%4) {
		case 0:
			Serial.print("Left: \t");
			Serial.println(leftVal, 1);
			count++;
			break;
		case 1:
			Serial.print("Down: \t");
			Serial.println(downVal, 1);
			count++;
			break;
		case 2:
			Serial.print("Up: \t");
			Serial.println(upVal, 1);
			count++;
			break;
		case 3:
			Serial.print("Right: \t");
			Serial.println(rightVal, 1);
			count++;
			break;
	}
*/

	Serial.print("Left: \t");
	Serial.print(leftVal, 1);
	Serial.print("\tDown: \t");
	Serial.print(downVal, 1);
	Serial.print("\tUp: \t");
	Serial.print(upVal, 1);
	Serial.print("\tRight: \t");
	Serial.print(rightVal, 1);
	Serial.print("\n");


}
