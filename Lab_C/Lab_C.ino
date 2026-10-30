// C++ code
//

int switchPin = 2;
int redLed = 4;
int yellowLed = 5;
int greenLed = 6;
int buzzer = 8;

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

int redTime = 22000;
int beepCounter = 0;
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
  
  pinMode(buzzer, OUTPUT);
}

void loop()
{
 
  currentSwitchState = digitalRead(switchPin);
  
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
    noTone(buzzer);
  }
 
  int timer = millis() - redLedTime;
  if(isRedOn && (timer > 50 && timer < 150)){
    digitalWrite(counterPin1, HIGH);
  	digitalWrite(counterPin2, LOW);
  	digitalWrite(counterPin3, LOW);
  	digitalWrite(counterPin4, HIGH);
    
    Serial.println("9");
    
	tone(buzzer, 1000);
    
  }
 
  if(isRedOn && (timer > 950 && timer < 1050)){
    digitalWrite(counterPin1, LOW);
  	digitalWrite(counterPin2, LOW);
  	digitalWrite(counterPin3, LOW);
  	digitalWrite(counterPin4, HIGH);
    
    Serial.println("8");
    tone(buzzer, 1000);

  }
  
  if(isRedOn && (timer > 1950 && timer < 2050)){
    digitalWrite(counterPin1, HIGH);
  	digitalWrite(counterPin2, HIGH);
  	digitalWrite(counterPin3, HIGH);
  	digitalWrite(counterPin4, LOW);
    
    Serial.println("7");  
    tone(buzzer, 1000);
  }
  
  if(isRedOn && (timer > 2950 && timer < 3050)){
    digitalWrite(counterPin1, LOW);
  	digitalWrite(counterPin2, HIGH);
  	digitalWrite(counterPin3, HIGH);
  	digitalWrite(counterPin4, LOW);
    
    Serial.println("6");
    tone(buzzer, 1000);
    
   
  }
  
  if(isRedOn && (timer > 3950 && timer < 4050)){
    digitalWrite(counterPin1, HIGH);
  	digitalWrite(counterPin2, LOW);
  	digitalWrite(counterPin3, HIGH);
  	digitalWrite(counterPin4, LOW);
    
    Serial.println("5");
    tone(buzzer, 1000);
  }
  
  if(isRedOn && (timer > 4950 && timer < 5050)){
    digitalWrite(counterPin1, LOW);
  	digitalWrite(counterPin2, LOW);
  	digitalWrite(counterPin3, HIGH);
  	digitalWrite(counterPin4, LOW);
    
    Serial.println("4");
    tone(buzzer, 1000);
    
   
  }
  
  if(isRedOn && (timer > 5950 && timer < 6050)){
    digitalWrite(counterPin1, HIGH);
  	digitalWrite(counterPin2, HIGH);
  	digitalWrite(counterPin3, LOW);
  	digitalWrite(counterPin4, LOW);
    
    Serial.println("3");
    tone(buzzer, 1000);
    
  }
  
  if(isRedOn && (timer > 6950 && timer < 7050)){
    digitalWrite(counterPin1, LOW);
  	digitalWrite(counterPin2, HIGH);
  	digitalWrite(counterPin3, LOW);
  	digitalWrite(counterPin4, LOW);
    
    Serial.println("2");
    tone(buzzer, 1000);
    
  }
  
  if(isRedOn && (timer > 7950 && timer < 8050)){
    digitalWrite(counterPin1, HIGH);
  	digitalWrite(counterPin2, LOW);
  	digitalWrite(counterPin3, LOW);
  	digitalWrite(counterPin4, LOW);
   
    Serial.println("1");
    tone(buzzer, 1000);
    
  }
  
  if(isRedOn && (timer > 8950 && timer < 9050)){
    digitalWrite(counterPin1, LOW);
  	digitalWrite(counterPin2, LOW);
  	digitalWrite(counterPin3, LOW);
  	digitalWrite(counterPin4, LOW);
    
    Serial.println("0");
    tone(buzzer, 1000);
    
  }
  
//Counter ends above this comment
  
  if(isRedOn && (timer > 9950 && timer < 10050)){
    digitalWrite(counterPin1, HIGH);
  	digitalWrite(counterPin2, LOW);
  	digitalWrite(counterPin3, HIGH);
  	digitalWrite(counterPin4, LOW);
   	tone(buzzer, 1000); 
    
  }
  
  if(isRedOn && (timer > 10950 && timer < 11050)){
    digitalWrite(counterPin1, LOW);
  	digitalWrite(counterPin2, HIGH);
  	digitalWrite(counterPin3, LOW);
  	digitalWrite(counterPin4, HIGH);
    
  }
  
  if(isRedOn && (timer > 11950 && timer < 12050)){
    digitalWrite(counterPin1, HIGH);
  	digitalWrite(counterPin2, LOW);
  	digitalWrite(counterPin3, HIGH);
  	digitalWrite(counterPin4, LOW);
    
    
  }
  
  if(isRedOn && (timer > 12950 && timer < 13050)){
    digitalWrite(counterPin1, LOW);
  	digitalWrite(counterPin2, HIGH);
  	digitalWrite(counterPin3, LOW);
  	digitalWrite(counterPin4, HIGH);
    
  }
  
  if(isRedOn && (timer > 13950 && timer < 14050)){
    digitalWrite(counterPin1, HIGH);
  	digitalWrite(counterPin2, LOW);
  	digitalWrite(counterPin3, HIGH);
  	digitalWrite(counterPin4, LOW);
    
    
  }
    
  if(isRedOn && (timer > 14950 && timer < 15050)){
    digitalWrite(counterPin1, LOW);
  	digitalWrite(counterPin2, HIGH);
  	digitalWrite(counterPin3, LOW);
  	digitalWrite(counterPin4, HIGH);
    
  }

 //end of switching 
  
  
  if(isRedOn && (timer > 15950 && timer < 16050)){
    digitalWrite(counterPin1, HIGH);
  	digitalWrite(counterPin2, HIGH);
  	digitalWrite(counterPin3, HIGH);
  	digitalWrite(counterPin4, HIGH);
    noTone(buzzer);
    
  }
  
  if(isRedOn && (timer > 16950 && timer < 17050)){
    digitalWrite(counterPin1, HIGH);
  	digitalWrite(counterPin2, HIGH);
  	digitalWrite(counterPin3, HIGH);
  	digitalWrite(counterPin4, HIGH);
    
    
  }
  
  if(isRedOn && (timer > 17950 && timer < 18050)){
    digitalWrite(counterPin1, HIGH);
  	digitalWrite(counterPin2, HIGH);
  	digitalWrite(counterPin3, HIGH);
  	digitalWrite(counterPin4, HIGH);
    
    
  }
  
  if(isRedOn && (timer > 18950 && timer < 19050)){
    digitalWrite(counterPin1, HIGH);
  	digitalWrite(counterPin2, HIGH);
  	digitalWrite(counterPin3, HIGH);
  	digitalWrite(counterPin4, HIGH);
    
  }
  
  if(isRedOn && (timer > 19950 && timer < 20050)){
    digitalWrite(counterPin1, HIGH);
  	digitalWrite(counterPin2, HIGH);
  	digitalWrite(counterPin3, HIGH);
  	digitalWrite(counterPin4, HIGH);
    
    
  }
  
  if(isRedOn && (timer > 20950 && timer < 21050)){
    digitalWrite(counterPin1, HIGH);
  	digitalWrite(counterPin2, HIGH);
  	digitalWrite(counterPin3, HIGH);
  	digitalWrite(counterPin4, HIGH);
    
    
  }
  
   if(isRedOn && (timer > 21950 && timer < 22050)){
   digitalWrite(counterPin1, HIGH);
   digitalWrite(counterPin2, HIGH);
   digitalWrite(counterPin3, HIGH);
   digitalWrite(counterPin4, HIGH);
    
  }
  
  if(timer < 10000 && isRedOn && ((timer % 1000) > 250)){
    noTone(buzzer);
    Serial.print("Turn off");
  }
  
  if(timer > 16000 && isRedOn){
    if((timer%1000)%125 > 75){
    	tone(buzzer, 1000);  
    } else {
    	noTone(buzzer);
    }
  
  }
  
  

  
  
  

  
  prevSwitchState = currentSwitchState;
  
}