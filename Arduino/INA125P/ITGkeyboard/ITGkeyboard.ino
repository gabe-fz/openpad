
int SENSORNUM = 4;
float press[SENSORNUM] = {45.0, 55.0, 42.0, 45.0};
//float press[4] = {50.0, 60.0, 46.0, 50.0};
float releaseAmt = 3.0;
float min[SENSORNUM], release[SENSORNUM];
float current;
int i;

//a, s, w, d
uint8_t bindings[SENSORNUM] = { 0x04, 0x16, 0x1A, 0x07};
//USB HID
uint8_t keyBuffer[8] = { 0, 0, 0, 0, 0, 0, 0 };

void setup() {
	Serial.begin(9600);
	for (i = 0; i < SENSORNUM; i++) {
		min[i] = analogRead(i);
		release[i] = press[i] - releaseAmt;
		//last[i] = min[i];
	}
}

void loop() {

	for (i = 0; i < SENSORNUM; i++) {

		current = analogRead(i);

			switch (keyBuffer[2+i]){
				case 0:
					if (current < min[i])
						min[i] = current;
					else if (current >= min[i] + press[i]){
						keyBuffer[2+i] = bindings[i];
					}
					break;
				default:
					if (current < min[i] + release[i]){
						keyBuffer[2+i] = 0;
						min[i] = current;
					}
					break;
			}

	}

	Serial.write(keyBuffer, 8);
}
