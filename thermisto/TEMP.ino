
int sensorPin = A0;    // select the input pin for the potentiometer

int sensorValue = 0;  // variable to store the value coming from the sensor

double T,Temp;
double T0 = 303.15;
double lnR;
int16_t R;
int16_t R0 = 8805;
int16_t B = 3905;
int16_t Pullup = 9000;

void setup() {
   Serial.begin(115200);
}

void loop() {
    sensorValue = analogRead(sensorPin);
  R =(Pullup * sensorValue)/(4096-sensorValue);
  T = 1/(1/T0+(log(R)-log(R0))/B);
  Temp = T - 273.15;
  Serial.print("Temp = ");
  Serial.println(Temp); 
}

