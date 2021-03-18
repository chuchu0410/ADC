int sensorPin = A0;
  int sensorValue = 0;
  
  
  double T, Temp;
  double Q = 301.15;  // 273.15 + 28 (room temperature) 室溫換成絕對溫度
  double lnR;
  int16_t R;          // Thermistor resistence
  int16_t R0 = 8805;  // calibrated by reading R at room temperature (=28 degree Celsius )
  int16_t B  = 3950;
  int16_t Pullup = 9930; // 10K ohm



void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(115200);
}

void loop()
{
  sensorValue = analogRead(sensorPin);
  // R / (Pullup + R)   = adc / 4096
  R = (Pullup * sensorValue) / (4096 -sensorValue);
  // B = (log(R) -log(R0)) / (1/T -1/T0) 
  T = 1 / (1/Q + (log(R)-log(R0)) / B );
  Temp = T -273.15;
  //Serial.println(Temp);
  Serial.printf("ADC:%4d, R=%d, Temp.=%f\n", sensorValue, R, Temp);
  delay(1000);
}
