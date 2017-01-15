
float press[5] = {60.0, 60.0, 60.0, 60.0, 60.0};
float releaseAmt = 3.0;
float min[5], release[5];
//float diff[4], last[4];
//float threshold = 10.0;
float current;
int i;

//z, q, s, e, c
uint8_t bindings[5] = { 0x1D, 0x14, 0x16, 0x08, 0x06 };
//USB HID
uint8_t keyBuffer[8] = { 0, 0, 0, 0, 0, 0, 0 };

void setup() {
	Serial.begin(9600);
	for (i = 0; i < 5; i++) {
		min[i] = analogRead(i);
		release[i] = press[i] - releaseAmt;
		//last[i] = min[i];
	}
}

void loop() {

	for (i = 0; i < 5; i++) {

		current = analogRead(i);
		//diff[i] = current - last[i];

		//if ( (-1*threshold)<diff[i]<threshold){

			//last[i] = current;

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

		//}

	}

	Serial.write(keyBuffer, 8);
}