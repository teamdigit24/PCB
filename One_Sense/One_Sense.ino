/*
 * This program is to test the sensor connections of the PCB. an ADC reading of zero indicates the sensor is not 
 * connected, and an ADC reading of about 450-650 indicates a sensor is connected and reading at a flat angle
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


const int samplingRateUS = 1800;     //sampling rate of 256 Hz.
const float seriesResistor = 10000.0; //10k resistor from voltage dividing circuit
const float VCC = 5.0;
const float STRAIGHT_RESISTANCE = 10000.0; // resistance when straight
const float BEND_RESISTANCE = 14000.0;    // resistance at 90 deg
float COUNTS = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
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
}

void loop() {
  // put your main code here, to run repeatedly:
  static unsigned long samplingTimerUs = micros();
  
  if(micros() - samplingTimerUs >= samplingRateUS)
  { 
    Serial.println(analogRead(FLEX_11));
    samplingTimerUs = micros();
  }//timer loop
}//loop

float ReadResistance(float SENSOR)
{
  float voltage = analogRead(SENSOR) * VCC /1023.0;
  return (float)(seriesResistor * (VCC / voltage - 1.0));
}
