/*
 * This program was written to test the sensor connections of the PCB. An ADC reading of zero indicates the sensor is not 
 * connected, and an ADC reading of about 450-650 indicates a sensor is connected and reading at a flat angle. A resistance measurement of 
 * infinite indicates that the sensor is disconnected. A resistance measurement of anything for 8k ohms indicates the sensors are connected.
 */

const int FLEX_1 = A2;
const int FLEX_2 = A3;
const int FLEX_3 = A4;
const int FLEX_4 = A5;
const int FLEX_5 = A0;
const int FLEX_6 = A1;
const int FLEX_7 = A10;
const int FLEX_8 = A8;
const int FLEX_9 = A7;
const int FLEX_10 = A11;
const int FLEX_11 = A6;

/*
 
A0 = D18 
A1 = D19
A2 = D20
A3 = D21
A4 = D22
A5 = D23
A6 = D4 = PD4
A7 = D6 = PD7
A8 = D8 = PB4 
A9 = D9 = PB5
A10 = D10 = PB6
A11 = D12 = PD6

*/


const int samplingRateMs = 1000;     //sampling rate of 1s.
const float seriesResistor = 10000.0; //10k resistor from voltage dividing circuit
const float VCC = 5.0;
const float STRAIGHT_RESISTANCE = 10000.0; // resistance when straight
const float BEND_RESISTANCE = 14000.0;    // resistance at 90 deg
float COUNTS = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  analogReference(DEFAULT);
  pinMode(FLEX_1,INPUT);
  pinMode(FLEX_2,INPUT);
  pinMode(FLEX_3,INPUT);
  pinMode(FLEX_4,INPUT);
  pinMode(FLEX_5,INPUT);
  pinMode(FLEX_6,INPUT);
  pinMode(FLEX_7,INPUT);
  pinMode(FLEX_8,INPUT);
  pinMode(FLEX_9,INPUT);
  pinMode(FLEX_10,INPUT);
  pinMode(FLEX_11,INPUT);
  Serial.println("Hit any key to receive a new reading");
}

void loop() {
  // put your main code here, to run repeatedly:
  static unsigned long samplingTimerMs = millis();
  if(millis() - samplingTimerMs >= samplingRateMs)
  { 
    //Serial.println(analogRead(FLEX_11));
    samplingTimerMs = millis();
    
    Serial.println ("Reading all flex sensors...");     // signal initalization done
    Serial.println(" ");
    Serial.print("Flex Sensor 1:  "); Serial.println((float)(seriesResistor * (VCC / (analogRead(FLEX_1) * VCC /1023.0) - 1.0)));
    Serial.print("Flex Sensor 2:  "); Serial.println((float)(seriesResistor * (VCC / (analogRead(FLEX_2) * VCC /1023.0) - 1.0)));
    Serial.print("Flex Sensor 3:  "); Serial.println((float)(seriesResistor * (VCC / (analogRead(FLEX_3) * VCC /1023.0) - 1.0)));
    Serial.print("Flex Sensor 4:  "); Serial.println((float)(seriesResistor * (VCC / (analogRead(FLEX_4) * VCC /1023.0) - 1.0)));
    Serial.print("Flex Sensor 5:  "); Serial.println((float)(seriesResistor * (VCC / (analogRead(FLEX_5) * VCC /1023.0) - 1.0)));
    Serial.print("Flex Sensor 6:  "); Serial.println((float)(seriesResistor * (VCC / (analogRead(FLEX_6) * VCC /1023.0) - 1.0)));
    Serial.print("Flex Sensor 7:  "); Serial.println((float)(seriesResistor * (VCC / (analogRead(FLEX_7) * VCC /1023.0) - 1.0)));
    Serial.print("Flex Sensor 8:  "); Serial.println((float)(seriesResistor * (VCC / (analogRead(FLEX_8) * VCC /1023.0) - 1.0)));
    Serial.print("Flex Sensor 9:  "); Serial.println((float)(seriesResistor * (VCC / (analogRead(FLEX_9) * VCC /1023.0) - 1.0)));
    Serial.print("Flex Sensor 10: "); Serial.println((float)(seriesResistor * (VCC / (analogRead(FLEX_10) * VCC /1023.0) - 1.0)));
    Serial.print("Flex Sensor 11: "); Serial.println((float)(seriesResistor * (VCC / (analogRead(FLEX_11) * VCC /1023.0) - 1.0)));
    Serial.println("Hit any key to receive a new reading");
    Serial.println(" ");
    while(Serial.available() == 0){}
    char input = Serial.read();
    //Serial.println(input);
    //char dump = Serial.read();
    
  }//timer loop
}//loop

/*
 * This function gives the user the option to read the resistance
 */
float ReadResistance(float SENSOR)
{
  float voltage = analogRead(SENSOR) * VCC /1023.0;
  return (float)(seriesResistor * (VCC / (analogRead(SENSOR) * VCC /1023.0) - 1.0));
}
