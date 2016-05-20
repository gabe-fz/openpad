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

float press = 30.0;
float release = 15.0;
float min = 5.0;

float leftNow = 0.0;
float leftLast = 0.0;
float leftDiff = 0.0;
float downNow = 0.0;
float downLast = 0.0;
float downDiff = 0.0;
float upNow = 0.0;
float upLast = 0.0;
float upDiff = 0.0;
float rightNow = 0.0;
float rightLast = 0.0;
float rightDiff = 0.0;

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


	leftNow = leftSensor.get_units();
	leftDiff = leftNow - leftLast;
	leftLast = leftNow;

	downNow = downSensor.get_units();
	downDiff = downNow - downLast;
	downLast = downNow;

	upNow = upSensor.get_units();
	upDiff = upNow - upLast;
	upLast = upNow;

	rightNow = rightSensor.get_units();
	rightDiff = rightNow - rightLast;
	rightLast = rightNow;

	switch (keyBuffer[POINTER_LEFT]){
		case 0:
			if (leftDiff >= press)
				keyBuffer[POINTER_LEFT] = KEY_LEFT;
			break;
		case KEY_LEFT:
			if (leftDiff <= (0-press))
				keyBuffer[POINTER_LEFT] = 0;
			else if (leftNow <= min)
				keyBuffer[POINTER_LEFT] = 0;
			break;
	}

	switch (keyBuffer[POINTER_DOWN]){
		case 0:
			if (downDiff >= press)
				keyBuffer[POINTER_DOWN] = KEY_DOWN;
			break;
		case KEY_DOWN:
			if (downDiff <= (0-release))
				keyBuffer[POINTER_DOWN] = 0;
			else if (downNow <= min)
				keyBuffer[POINTER_DOWN] = 0;
			break;
	}

	switch (keyBuffer[POINTER_UP]){
		case 0:
			if (upDiff >= press)
				keyBuffer[POINTER_UP] = KEY_UP;
			break;
		case KEY_UP:
			if (upDiff <= (0-release))
				keyBuffer[POINTER_UP] = 0;
			else if (upNow <= min)
				keyBuffer[POINTER_UP] = 0;
			break;
	}

	switch (keyBuffer[POINTER_RIGHT]){
		case 0:
			if (rightDiff >= press)
				keyBuffer[POINTER_RIGHT] = KEY_RIGHT;
			break;
		case KEY_RIGHT:
			if (rightDiff <= (0-release))
				keyBuffer[POINTER_RIGHT] = 0;
			else if (rightNow <= min)
				keyBuffer[POINTER_RIGHT] = 0;
			break;
	}

	Serial.write(keyBuffer, 8);
}
