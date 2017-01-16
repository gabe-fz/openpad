const int SENSORNUM = 4;
int i;
float val[SENSORNUM];

void setup() {
	Serial.begin(9600);
}

void loop() {
	for (i = 0; i < SENSORNUM; i++) {
		val[i] = analogRead(i);
		Serial.print(val[i],1);
		Serial.print("\t");
		if (i == SENSORNUM - 1)
			Serial.print("\n");
	}
}
