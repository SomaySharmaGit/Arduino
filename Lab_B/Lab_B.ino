// C++ code
//

int switchPin = 2;
int redLed = 4;
int yellowLed = 5;
int greenLed = 6;

int currentSwitchState = 0;
int prevSwitchState = 0;

long int greenLedTime = -10000;
long int yellowLedTime = 0;
long int redLedTime = 0;

boolean isGreenOn = false;
boolean isYellowOn = false;
boolean isRedOn = false;

boolean counterOn1 = true;
boolean counterOn2 = true;
boolean counterOn3 = true;
boolean counterOn4 = true;


int counterPin1 = 9;
int counterPin2 = 10;
int counterPin3 = 11;
int counterPin4 = 12;

int redTime = 5000;

void setup()
{
  pinMode(switchPin, INPUT);
  pinMode(redLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(counterPin1, OUTPUT);
  pinMode(counterPin2, OUTPUT);
  pinMode(counterPin3, OUTPUT);
  pinMode(counterPin4, OUTPUT);
  
  prevSwitchState = digitalRead(switchPin);
  
  digitalWrite(greenLed, HIGH);
  digitalWrite(counterPin1, HIGH);
  digitalWrite(counterPin2, HIGH);
  digitalWrite(counterPin3, HIGH);
  digitalWrite(counterPin4, HIGH);
  
  Serial.begin(9600);
}

void loop()
{
 
  currentSwitchState = digitalRead(switchPin);
  
  Serial.println(millis()-greenLedTime);

  if(currentSwitchState == LOW && prevSwitchState == HIGH && (millis() - greenLedTime) > 6000){
    digitalWrite(yellowLed, HIGH);
    digitalWrite(greenLed, LOW);
    yellowLedTime = millis();
    isGreenOn = false;
    isYellowOn = true;
  }
  
  if(isYellowOn && ((millis() - yellowLedTime) > 3000)){
    digitalWrite(redLed, HIGH);
    digitalWrite(yellowLed, LOW);
    redLedTime = millis();
    isYellowOn = false;
    isRedOn = true;
  }
  
  if(isRedOn && (millis() - redLedTime) > redTime){
   	digitalWrite(greenLed, HIGH);
    digitalWrite(redLed, LOW);
    greenLedTime = millis();
	isRedOn = false;
    isGreenOn = true;
  }
 
  
  prevSwitchState = currentSwitchState;
  
}