const int SENSORNUM = 6;
//(skip)[2]
float press[SENSORNUM] = {40.0, 36.0, 0.0, 40.0, 36.0, 40.0};
//{35.0, 40.0, 3.0, 50.0, 20.0, 20.0}
float releaseAmt = 6.0;
float min[SENSORNUM], release[SENSORNUM];
float current;
int i, tmp;

//z, q, (skip), s, e, c
uint8_t bindings[SENSORNUM] = { 0x1D, 0x14, 0x00, 0x16, 0x08, 0x06 };
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

		//center left reading
		if (i == 2){
			tmp = current;
			i++;
		}

		//center right adjustment
		if (i == 3){
			current = (analogRead(i) - min[i]) + tmp;
		}

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
