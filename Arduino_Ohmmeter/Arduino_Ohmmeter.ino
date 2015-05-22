//CONSTANT DECLARATIONS
const double R1 = 1000.0d;    //Constant 1 kOhm resistor

//VARIABLE DECLARATIONS
double Vs = 0.0d;            //Voltage Source from Arduino
double V1 = 0.0d;            //Voltage between R1 and R2
double R2 = 0.0d;            //Unknown resistor (to be measured)

//Set up I/O analog pins and Serial communication
void setup() {
  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  Serial.begin(9600);
}

void loop() {
  //Read source voltage, then map it to a range 0 to 5V
  Vs = analogRead(A1);
  Vs = _map(Vs, 0.0d, 1023.0d, 0.0d, 5.0d);
  
  //Read voltage between resistors R1 and R2, then map it to a range 0 to 5V
  V1 = analogRead(A0);
  V1 = _map(V1, 0.0d, 1023.0d, 0.0d, 5.0d);
  
  //Apply derived voltage division formula
  R2 = V1*R1/(Vs - V1);
  
  Serial.print("V1: ");
  Serial.println(V1);
  Serial.print("R2: ");
  Serial.println(R2);
  Serial.println();
  delay(1000);
}

//This function maps the value x within [in_min, in_max] and maps it to the range [out_min, out_max]
double _map(double x, double in_min, double in_max, double out_min, double out_max)
{
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
