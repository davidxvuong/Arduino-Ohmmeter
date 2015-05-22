//CONSTANT DECLARATIONS
const double R1 = 1000.0d;    //Constant 1 kOhm resistor

//VARIABLE DECLARATIONS
double Vs = 0.0d;            //
double V1 = 0.0d;
double R2 = 0.0d;

//Set up I/O analog pins
void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  Serial.begin(9600);
}

void loop() {
  Vs = analogRead(A1);
  Vs = _map(Vs, 0.0d, 1023.0d, 0.0d, 5.0d);
  
  V1 = analogRead(A0);
  V1 = _map(V1, 0.0d, 1023.0d, 0.0d, 5.0d);
  R2 = V1*R1/(Vs - V1);
  
  Serial.print("V1: ");
  Serial.println(V1);
  Serial.print("R2: ");
  Serial.println(R2);
  delay(1000);
}

double _map(double x, double in_min, double in_max, double out_min, double out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
