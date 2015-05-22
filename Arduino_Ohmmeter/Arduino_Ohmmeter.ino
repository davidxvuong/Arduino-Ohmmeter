const double CONVERSION_RATIO = 204.6d;
const double V_SOURCE = 5.0d;
const double R1 = 1000.0d;
double V1 = 0;
double R2 = 0.0d;

void setup() {
  // put your setup code here, to run once:
  pinMode(A0, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly
  V1 = analogRead(A0)/CONVERSION_RATIO;
  R2 = V1*R1;
  R2 = R2/(V_SOURCE - V1);
  Serial.print("V1: ");
  Serial.println(V1);
  Serial.print("R2: ");
  Serial.println(R2);
  delay(1000);
}
