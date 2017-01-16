const int SENSORNUM = 6;
int i;
float val[SENSORNUM], zero[SENSORNUM];

void setup() {
	Serial.begin(9600);
	for (i = 0; i < SENSORNUM; i++) {
		zero[i] = analogRead(i);
	}
}

void loop() {
	for (i = 0; i < SENSORNUM; i++) {
		val[i] = (analogRead(i) - zero[i]);
		Serial.print(val[i],1);
		Serial.print("\t");
		if (i == SENSORNUM - 1)
			Serial.print("\n");
	}
}
