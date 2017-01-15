
float val1, val2, val3, val4, val5, val6;

void setup() {
  Serial.begin(9600);
}

void loop() {
  	val1 = analogRead(0);
	val2 = analogRead(1);
	val3 = analogRead(2);
	val4 = analogRead(3);
	val5 = analogRead(4);
	val6 = analogRead(5);

    Serial.print(val1,1);
	Serial.print("\t");
    Serial.print(val2,1);
	Serial.print("\t");
    Serial.print(val3,1);
	Serial.print("\t");
    Serial.print(val4,1);
	Serial.print("\t");
    Serial.print(val5,1);
	Serial.print("\t");
	Serial.print(val6,1);
	Serial.print("\n");
}
