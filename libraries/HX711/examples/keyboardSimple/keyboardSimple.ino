#include "HX711.h"

#define KEY_LEFT_ARROW  0x50
#define KEY_DOWN_ARROW  0x51
#define KEY_UP_ARROW    0x52
#define KEY_RIGHT_ARROW 0x4F

#define KEY_LEFT  		0x04	//a
#define KEY_DOWN  		0x16	//s
#define KEY_UP   		0x1A	//w
#define KEY_RIGHT 		0x07	//d

#define POINTER_LEFT	2
#define POINTER_DOWN	3
#define POINTER_UP		4
#define POINTER_RIGHT	5

// (data, clock)
HX711 leftSensor(2, 3);
HX711 downSensor(4, 5);
HX711 upSensor(6, 7);
HX711 rightSensor(8, 9);

float threshold = 33.0;

float left = 0.0;
float down = 0.0;
float up = 0.0;
float right = 0.0;

uint8_t keyBuffer[8] = { 0, 0, 0, 0, 0, 0, 0 };

void setup() {

	Serial.begin(9600);
	delay(200);

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


	left = leftSensor.get_units();
	down = downSensor.get_units();
	up = upSensor.get_units();
	right = rightSensor.get_units();

	if (left >= threshold)
		keyBuffer[POINTER_LEFT] = KEY_LEFT;
	else
		keyBuffer[POINTER_LEFT] = 0;

	if (down >= threshold)
		keyBuffer[POINTER_DOWN] = KEY_DOWN;
	else
		keyBuffer[POINTER_DOWN] = 0;

	if (up >= threshold)
		keyBuffer[POINTER_UP] = KEY_UP;
	else
		keyBuffer[POINTER_UP] = 0;

	if (right >= threshold)
		keyBuffer[POINTER_RIGHT] = KEY_RIGHT;
	else
		keyBuffer[POINTER_RIGHT] = 0;

	Serial.write(keyBuffer, 8);
}
