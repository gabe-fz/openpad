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
HX711 leftSensor(10, 11);
HX711 downSensor(8, 9);

float threshold = -70.0;
float leftVal = 0.0;
float downVal = 0.0;

uint8_t keyBuffer[8] = { 0, 0, 0, 0, 0, 0, 0 };

void setup() {

	Serial.begin(9600); //orig: 38400
	delay(200);

	leftSensor.set_scale(2280.f);
	leftSensor.tare();
	downSensor.set_scale(2280.f);
	downSensor.tare();
}

void loop() {


	leftVal = leftSensor.get_units();
	downVal = downSensor.get_units();

	switch (keyBuffer[POINTER_LEFT]){
		case 0:
			if (leftVal <= threshold)
				keyBuffer[POINTER_LEFT] = KEY_LEFT;
			break;
		case KEY_LEFT:
			if (leftVal > threshold)
				keyBuffer[POINTER_LEFT] = 0;
			break;
	}

	switch (keyBuffer[POINTER_DOWN]){
		case 0:
			if (downVal <= threshold)
				keyBuffer[POINTER_DOWN] = KEY_DOWN;
			break;
		case KEY_DOWN:
			if (downVal > threshold)
				keyBuffer[POINTER_DOWN] = 0;
			break;
	}

	Serial.write(keyBuffer, 8);


}
