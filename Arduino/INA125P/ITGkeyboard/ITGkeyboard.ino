const int SENSORNUM = 4;
float press[SENSORNUM] = {50.0, 63.0, 45.0, 46.0};
float releaseAmt = 5.0;
float min[SENSORNUM], release[SENSORNUM];
float current;
int i;

//a, s, w, d
uint8_t bindings[4] = { 0x04, 0x16, 0x1A, 0x07};
//USB HID
uint8_t keyBuffer[8] = { 0, 0, 0, 0, 0, 0, 0 };

void setup() {
	Serial.begin(9600);
	for (i = 0; i < SENSORNUM; i++) {
		min[i] = analogRead(i);
		release[i] = press[i] - releaseAmt;
	}
}

void loop() {

	for (i = 0; i < SENSORNUM; i++) {

		current = analogRead(i) - min[i];

			switch (keyBuffer[2+i]){
				case 0:
					if (current > press[i]){
						keyBuffer[2+i] = bindings[i];
					}
					break;
				default:
					if (current < release[i]){
						keyBuffer[2+i] = 0;
					}
					break;
			}

	}

	Serial.write(keyBuffer, 8);
}
