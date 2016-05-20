#include "HX711.h"


// (data, clock)
HX711 leftSensor(8, 9);

float leftVal = 0.0;

void setup() {

	Serial.begin(9600); //orig: 38400
	leftSensor.set_scale(2280.f);
	leftSensor.tare();
}

void loop() {


	leftVal = leftSensor.get_units(1);

	Serial.print(leftVal, 1);
	Serial.print("\n");

}
