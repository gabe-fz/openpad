// Arduino with load cell

// Put two known loads on the sensor and take readings. Put those values
// here.
float leftInit, downInit, upInit, rightInit;
float leftVal, downVal, upVal, rightVal;

void setup() {
  Serial.begin(9600);
}

void loop() {
  	leftVal = analogRead(0);
	downVal = analogRead(1);
	upVal = analogRead(2);
	rightVal = analogRead(3);

    Serial.print(leftVal,1);
	Serial.print("\t");
    Serial.print(downVal,1);
	Serial.print("\t");
    Serial.print(upVal,1);
	Serial.print("\t");
    Serial.print(rightVal,1);
	Serial.print("\n");
}
