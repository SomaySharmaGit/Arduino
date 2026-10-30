#define LED 6
#define BUZZER 5

	
int light_sensor = A3; 
int sound_sensor = A2; //assign to pin A2
 

int sum = 0;
int lightSum = 0;
int threshold;

int lightVal = 0;
//----------------------------------------------------------------------
int sensorValue;
// variable to calibrate low value
int sensorLow = 1023;
// variable to calibrate high value
int sensorHigh = 0;
// LED pin
const int ledPin = 13;


void setup(){
  pinMode(LED,OUTPUT);    //Sets the pinMode to Output 
  pinMode(BUZZER, OUTPUT);
  Serial.begin(9600);

  digitalWrite(LED,HIGH);


  // calibrate for the first five seconds after program runs
  while (millis() < 5000) {
    // record the maximum sensor value
    sensorValue = analogRead(light_sensor);
    if (sensorValue > sensorHigh) {
      sensorHigh = sensorValue;
    }
    // record the minimum sensor value
    if (sensorValue < sensorLow) {
      sensorLow = sensorValue;
    }
    Serial.println(sensorHigh);
  }
  // turn the LED off, signaling the end of the calibration period
  digitalWrite(ledPin, LOW);

}

void loop(){
  int lightVal = analogRead(light_sensor);

  if(millis() % 300 < 50){
    if(lightVal < (sensorHigh - 15)){
      tone(BUZZER, 85);
    } else {
      noTone(BUZZER);
    }
  }

  Serial.print(" Light level: "); 
  Serial.print(lightVal); // print the light value in Serial Monitor

    int soundValue = 0; //create variable to store many different readings
  for (int i = 0; i < 32; i++) //create a for loop to read 
  { soundValue += analogRead(sound_sensor);  } //read the sound sensor
 
  soundValue >>= 5; //bitshift operation 
  Serial.print(" Sound Level: ");
  Serial.println(soundValue); //print the value of sound sensor 

}
