int pin1 = 4;
int pin2 = 3;
int pin4 = 2;
int greenLed = 9;
int redLed = 10;

int buzzerPin = 12;
int switchPin1 = 5;
int switchPin2 = 6;
int switchPin3 = 7;
int switchPin4 = 8;

int currentSwitch1State = LOW;
int previousSwitch1State = LOW;
long int debounceTimer1 = 0;

int currentSwitch2State = LOW;
int previousSwitch2State = LOW;
long int debounceTimer2 = 0;

int currentSwitch3State = LOW;
int previousSwitch3State = LOW;
long int debounceTimer3 = 0;

int currentSwitch4State = LOW;
int previousSwitch4State = LOW;
long int debounceTimer4 = 0;


long int debounceDelay = 10;

long int timer1 = 0;
long int timer2 = 0;
long int timer3 = 0;
long int timer4 = 0;

boolean startCycle;
boolean function1;
boolean function2;
boolean function3;


void setup() {
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin4, OUTPUT);
  pinMode(switchPin1, INPUT);

  digitalWrite(pin1,LOW);
  digitalWrite(pin2,LOW);
  digitalWrite(pin4,LOW);

  Serial.begin(9600);

}

void loop() {

  checkSwitch1();

  if(startCycle){
    cycle1();
  } 

  if(function1){
    check1();
  } 
  if(function2){
    check2();
  } 
  if(function3){
    check3();
  } 
  
}

void cycle1(){

  long int timeDiff = millis()-timer1;

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

    alert();
    analogWrite(greenLed, 0);

    Serial.println("Function 0");

  } 

  if(timeDiff > 15000){
    startCycle = false;
    noTone(buzzerPin);
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
void checkSwitch1(){
  int reading = digitalRead(switchPin1);

  if(reading != previousSwitch1State){
    debounceTimer1 = millis();
  }

  if(millis() - debounceTimer1 > debounceDelay){
    if(currentSwitch1State == HIGH && reading == LOW){
      timer1 = millis();
      startCycle = true;
    }
    currentSwitch1State = reading;
  }

  previousSwitch1State = reading;
}
void checkSwitch2(){
  int reading = digitalRead(switchPin2);

  if(reading != previousSwitch2State){
    debounceTimer2 = millis();
  }

  if(millis() - debounceTimer2 > debounceDelay){
    if(currentSwitch2State == HIGH && reading == LOW){
      timer2 = millis();
      function1 = true;
    }
    currentSwitch2State = reading;
  }

  previousSwitch2State = reading;
}
void checkSwitch3(){
  int reading = digitalRead(switchPin3);

  if(reading != previousSwitch3State){
    debounceTimer3 = millis();
  }

  if(millis() - debounceTimer3 > debounceDelay){
    if(currentSwitch3State == HIGH && reading == LOW){
      timer3 = millis();
      function2 = true;
    }
    currentSwitch3State = reading;
  }

  previousSwitch3State = reading;
}
void checkSwitch4(){
  int reading = digitalRead(switchPin4);

  if(reading != previousSwitch4State){
    debounceTimer4 = millis();
  }

  if(millis() - debounceTimer4 > debounceDelay){
    if(currentSwitch4State == HIGH && reading == LOW){
      timer4 = millis();
      function3 = true;
    }
    currentSwitch4State = reading;
  }

  previousSwitch4State = reading;
}
void check1(){
    long int timeDiff = millis()-timer2;
    
    if(timeDiff > 0 && timeDiff < 1000){
    digitalWrite(pin1,LOW);
    digitalWrite(pin2,LOW);
    digitalWrite(pin4,LOW);

    }
    if(timeDiff > 1000 && timeDiff < 2000){
    digitalWrite(pin1,HIGH);
    digitalWrite(pin2,LOW);
    digitalWrite(pin4,LOW);

    }
    if(timeDiff > 2000 && timeDiff < 3000){
    digitalWrite(pin1,LOW);
    digitalWrite(pin2,HIGH);
    digitalWrite(pin4,LOW);

    }
    if(timeDiff > 3000 && timeDiff < 4000){
    digitalWrite(pin1,HIGH);
    digitalWrite(pin2,HIGH);
    digitalWrite(pin4,LOW);

    }
    if(timeDiff > 4000 && timeDiff < 5000){
    digitalWrite(pin1,LOW);
    digitalWrite(pin2,LOW);
    digitalWrite(pin4,HIGH);

    }
    if(timeDiff > 5000 && timeDiff < 6000){
    digitalWrite(pin1,HIGH);
    digitalWrite(pin2,LOW);
    digitalWrite(pin4,HIGH);

    }
    if(timeDiff > 6000 && timeDiff < 7000){
    digitalWrite(pin1,LOW);
    digitalWrite(pin2,HIGH);
    digitalWrite(pin4,HIGH);

    }
    if(timeDiff > 7000 && timeDiff < 8000){
    digitalWrite(pin1,HIGH);
    digitalWrite(pin2,HIGH);
    digitalWrite(pin4,HIGH);

    }
    if(timeDiff > 8000 && timeDiff < 9000){
    digitalWrite(pin1,LOW);
    digitalWrite(pin2,HIGH);
    digitalWrite(pin4,HIGH);

    }
    if(timeDiff > 9000 && timeDiff < 10000){
    digitalWrite(pin1,HIGH);
    digitalWrite(pin2,LOW);
    digitalWrite(pin4,HIGH);

    }
    if(timeDiff > 10000 && timeDiff < 11000){
    digitalWrite(pin1,LOW);
    digitalWrite(pin2,LOW);
    digitalWrite(pin4,HIGH);

    }
    if(timeDiff > 11000 && timeDiff < 12000){
    digitalWrite(pin1,HIGH);
    digitalWrite(pin2,HIGH);
    digitalWrite(pin4,LOW);

    }
    if(timeDiff > 12000 && timeDiff < 13000){
    digitalWrite(pin1,LOW);
    digitalWrite(pin2,HIGH);
    digitalWrite(pin4,LOW);

    }
    if(timeDiff > 13000 && timeDiff < 14000){
    digitalWrite(pin1,HIGH);
    digitalWrite(pin2,LOW);
    digitalWrite(pin4,LOW);

    }
    if(timeDiff > 14000 && timeDiff < 15000){
    digitalWrite(pin1,LOW);
    digitalWrite(pin2,LOW);
    digitalWrite(pin4,LOW);

    }

    if(timeDiff > 15000){
      function1 = false;
    }


}
void check2(){
  long int timeDiff = millis()-timer3;

  if(timeDiff > 0 && timeDiff < 3000){
    digitalWrite(pin1,LOW);
    digitalWrite(pin2,LOW);
    digitalWrite(pin4,HIGH);

    }

  if(timeDiff > 3000 && timeDiff < 6000){
    digitalWrite(pin1,LOW);
    digitalWrite(pin2,HIGH);
    digitalWrite(pin4,HIGH);

    }

  if(timeDiff > 6000){
    digitalWrite(pin1,LOW);
    digitalWrite(pin2,LOW);
    digitalWrite(pin4,LOW);

    function2 = false;
    }

  
}
void check3(){
  long int timeDiff = millis() - timer4;


  int fraction = millis() % 1500;
  int PWM;

  //Red LED

  if(timeDiff > 0 && timeDiff < 1500){
    PWM = map(fraction, 0, 1500, 0, 255);
    analogWrite(redLed, PWM);
  }

  if(timeDiff > 1500 && timeDiff < 3000){
    PWM = map(fraction, 0, 1500, 0, 255);
    analogWrite(redLed, 255 - PWM);
  }

  //Green Led

  if(timeDiff > 3000 && timeDiff < 4500){
    PWM = map(fraction, 0, 1500, 0, 255);
    analogWrite(greenLed, PWM);
  }

  if(timeDiff > 4500 && timeDiff < 6000){
    PWM = map(fraction, 0, 1500, 0, 255);
    analogWrite(greenLed, 255 - PWM);
  }

  //Yellow LED

  if(timeDiff > 6000 && timeDiff < 7500){
    PWM = map(fraction, 0, 1500, 0, 255);
    analogWrite(greenLed, PWM);
    analogWrite(redLed, PWM);
  }

  if(timeDiff > 7500 && timeDiff < 9000){
    PWM = map(fraction, 0, 1500, 0, 255);
    analogWrite(greenLed, 255 - PWM);
    analogWrite(redLed, 255 - PWM);
  }

  if(timeDiff > 9000){
    function3 = false;
  }

}





