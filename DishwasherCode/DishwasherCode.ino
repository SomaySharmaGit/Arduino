int pin1 = 4;
int pin2 = 3;
int pin4 = 2;
int greenLed = 9;

int buzzerPin = 12;


int switchPin = 5;

int currentSwitchState = LOW;
int previousSwitchState = LOW;

long int debounceTimer = 0;
long int debounceDelay = 10;

long int timer = 0;
boolean startCycle;

void setup() {
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(switchPin, INPUT);

  digitalWrite(pin1,LOW);
  digitalWrite(pin2,LOW);
  digitalWrite(pin4,LOW);

  Serial.begin(9600);

}

void loop() {

  int reading = digitalRead(switchPin);

  if(reading != previousSwitchState){
    debounceTimer = millis();
  }

  if(millis() - debounceTimer > debounceDelay){
    if(currentSwitchState == HIGH && reading == LOW){
      timer = millis();
      startCycle = true;
    }
    currentSwitchState = reading;
  }

  previousSwitchState = reading;

  if(startCycle){
    execute();
  } else{
    analogWrite(greenLed, 0);
  }
}

void execute(){

  long int timeDiff = millis()-timer;

  if(timeDiff < 4000){
    digitalWrite(pin1,HIGH);
    digitalWrite(pin2,LOW);
    digitalWrite(pin4,LOW);

    //function 1

    Serial.println("Function 1");
  }

  
  if(timeDiff > 4000 && timeDiff < 10000){
    digitalWrite(pin1,HIGH);
    digitalWrite(pin2,HIGH);
    digitalWrite(pin4,LOW);

    //function 3

    Serial.println("Function 3");
  }
  

  
  if(timeDiff > 10000 && timeDiff < 12000){
    digitalWrite(pin1,HIGH);
    digitalWrite(pin2,LOW);
    digitalWrite(pin4,LOW);

    //function 1
    Serial.println("Function 1");
  }

  if(timeDiff > 12000 && timeDiff < 13000){
    digitalWrite(pin1,HIGH);
    digitalWrite(pin2,HIGH);
    digitalWrite(pin4,HIGH);

    //function 7
    Serial.println("Function 7");
  }

  if(timeDiff > 13000 && timeDiff < 15000){
    digitalWrite(pin1,LOW);
    digitalWrite(pin2,LOW);
    digitalWrite(pin4,LOW);

    digitalWrite(greenLed, 0);
    

    Serial.println("Function 0");
    alert();
  } 

  if(timeDiff > 15000){
    startCycle = false;
    noTone(buzzerPin);
    analogWrite(greenLed, 0);
  }

  if(timeDiff < 13000){
    blinkLed();
  }



}

void alert(){
  tone(buzzerPin, 1440);
}



void blinkLed(){
  int fraction = millis() % 2000;
  int PWM = map(fraction, 0, 2000, 0, 255);
  analogWrite(greenLed, 255 - PWM);
}
