const double k = 5.0/1024;
const double luxFactor = 500000;
const double R2 = 10000;
const double LowLightLimit = 200; 
const double B = 1.3*pow(10.0,7);
const double m = -1.4;
const int LED = 7; 
 
double light_intensity (int RawADC0) {  
    double V2 = k*RawADC0;
    double R1 = (5.0/V2 - 1)*R2;
    double lux = B*pow(R1,m);
    return lux;} 
void setup() {
    Serial.begin(9600);
    pinMode(LED, OUTPUT);
  } 
void loop() {
    double intensity = light_intensity(analogRead(0));
    Serial.println(intensity);
    if (intensity < LowLightLimit) {
            digitalWrite(LED, HIGH);
        } else {
            digitalWrite(LED, LOW);
        }
    Serial.println(intensity);
    delay(1000);
  }