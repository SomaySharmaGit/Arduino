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
int switchPin5 = 11;
int switchPin6 = 12; 


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

int currentSwitch5State = LOW;
int previousSwitch5State = LOW;
long int debounceTimer5 = 0;

int currentSwitch6State = LOW;
int previousSwitch6State = LOW;
long int debounceTimer6 = 0;


long int debounceDelay = 10;

long int timer1 = 0;
long int timer2 = 0;
long int timer3 = 0;
long int timer4 = 0;
long int timer5 = 0;
long int timer6 = 0;

boolean startCycle1;
boolean startCycle2;
boolean startCycle3;
boolean function1;
boolean function2;
boolean function3;


void setup() {
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT);
  pinMode(pin4, OUTPUT);

  digitalWrite(pin1,LOW);
  digitalWrite(pin2,LOW);
  digitalWrite(pin4,LOW);

  pinMode(switchPin1, INPUT);
  pinMode(switchPin2, INPUT);
  pinMode(switchPin3, INPUT);
  pinMode(switchPin4, INPUT);
  


  Serial.begin(9600);

}

void loop() {

  checkSwitch1();
  checkSwitch2();
  checkSwitch3();
  checkSwitch4();
  checkSwitch5();
  checkSwitch6();

  if(startCycle1){
    cycle1();
  } 
  if(startCycle2){
    cycle2();
  } 
  if(startCycle3){
    cycle3();
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
    mode(1);
  }
  if(timeDiff > 4000 && timeDiff < 10000){
    mode(3);
  }
  if(timeDiff > 10000 && timeDiff < 12000){
    mode(1);
  }
  if(timeDiff > 12000 && timeDiff < 13000){
    mode(7);
  }
  if(timeDiff > 13000 && timeDiff < 15000){
    mode(0);
    alert();
    analogWrite(greenLed, 0);
  } 
  if(timeDiff > 15000){
    startCycle1 = false;
    noTone(buzzerPin);
  }
  if(timeDiff < 13000){
    blinkLed();
  }
}


void cycle2(){
  long int timeDiff = millis()-timer5;

  if(timeDiff < 3000){
    mode(1);
  }
  if(timeDiff > 3000 && timeDiff < 8000){
    mode(4);
  }
  if(timeDiff > 8000 && timeDiff < 11000){
    mode(1);
  }
  if(timeDiff > 11000 && timeDiff < 14000){
    mode(7);
  }
  if(timeDiff < 14000){
    mode(0);
  }
}

void cycle3(){
  long int timeDiff = millis()-timer6;

  if(timeDiff < 3000){
    mode(2);
  }
  if(timeDiff > 3000 && timeDiff < 10000){
    mode(5);
  }
  if(timeDiff > 10000 && timeDiff < 15000){
    mode(2);
  }
  if(timeDiff > 15000 && timeDiff < 18000){
    mode(6);
  }
  if(timeDiff > 18000){
    mode(0);
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
      startCycle1 = true;
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
      Serial.println("This works");
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
void checkSwitch5(){
  int reading = digitalRead(switchPin5);

  if(reading != previousSwitch5State){
    debounceTimer5 = millis();
  }

  if(millis() - debounceTimer5 > debounceDelay){
    if(currentSwitch5State == HIGH && reading == LOW){
      timer5 = millis();
      startCycle2 = true;
    }
    currentSwitch5State = reading;
  }

  previousSwitch5State = reading;
}
void checkSwitch6(){
  int reading = digitalRead(switchPin6);

  if(reading != previousSwitch6State){
    debounceTimer6 = millis();
  }

  if(millis() - debounceTimer6 > debounceDelay){
    if(currentSwitch6State == HIGH && reading == LOW){
      timer6 = millis();
      startCycle3 = true;
    }
    currentSwitch6State = reading;
  }

  previousSwitch6State = reading;
}


void check1(){
    long int timeDiff = millis()-timer2;
    
    if(timeDiff > 0 && timeDiff < 1000){
    mode(0);
    }
    if(timeDiff > 1000 && timeDiff < 2000){
    mode(1);
    }
    if(timeDiff > 2000 && timeDiff < 3000){
    mode(2);
    }
    if(timeDiff > 3000 && timeDiff < 4000){
    mode(3);
    }
    if(timeDiff > 4000 && timeDiff < 5000){
    mode(4)
    }
    if(timeDiff > 5000 && timeDiff < 6000){
    mode(5);
    }
    if(timeDiff > 6000 && timeDiff < 7000){
    mode(6);
    }
    if(timeDiff > 7000 && timeDiff < 8000){
    mode(7);
    }
    if(timeDiff > 8000 && timeDiff < 9000){
    mode(6);
    }
    if(timeDiff > 9000 && timeDiff < 10000){
    mode(5);
    }
    if(timeDiff > 10000 && timeDiff < 11000){
    mode(4);
    }
    if(timeDiff > 11000 && timeDiff < 12000){
    mode(3);
    }
    if(timeDiff > 12000 && timeDiff < 13000){
    mode(2);
    }
    if(timeDiff > 13000 && timeDiff < 14000){
    mode(1);
    }
    if(timeDiff > 14000 && timeDiff < 15000){
    mode(0);
    }
    if(timeDiff > 15000){
      function1 = false;
    }


}
void check2(){
  long int timeDiff = millis()-timer3;

  if(timeDiff > 0 && timeDiff < 3000){
    mode(1);
    }

  if(timeDiff > 3000 && timeDiff < 6000){
    mode(5);
    }

  if(timeDiff > 6000){
    mode(0);
    function2 = false;
    }

  
}
void check3(){
  long int timeDiff = millis() - timer4;

  int fraction = timeDiff % 1500;
  int PWM = map(fraction, 0, 1500, 0, 255);
  

  //Red LED

  if(timeDiff > 0 && timeDiff < 1500){
    analogWrite(redLed, PWM);
  }

  if(timeDiff > 1500 && timeDiff < 3000){
    analogWrite(redLed, 255 - PWM);
  }

  if(timeDiff > 3000 && timeDiff < 4500){
    analogWrite(redLed, 0);
    analogWrite(greenLed, PWM);
  }

  if(timeDiff > 4500 && timeDiff < 6000){
    analogWrite(greenLed, 255 - PWM);
  }

  if(timeDiff > 6000 && timeDiff < 7500){
    analogWrite(redLed, (int)PWM/15);
    analogWrite(greenLed, PWM);
  }
  
  if(timeDiff > 7500 && timeDiff < 9000){
    analogWrite(redLed, (int)(255 - PWM)/15);
    analogWrite(greenLed, 255 - PWM);
  }

  //Green Led


  if(timeDiff > 9000 && timeDiff < 10000){
    analogWrite(redLed, 0);
    analogWrite(greenLed, 0);
    alert();
  }

  if(timeDiff > 10000 && timeDiff < 10500){
    noTone(buzzerPin);
  }

  if(timeDiff > 10500 && timeDiff < 11500){
    alert();
  }

  if(timeDiff > 11500 && timeDiff < 12000){
    noTone(buzzerPin);
  }

  if(timeDiff > 12000 && timeDiff < 13000){
    alert();
  }

  if(timeDiff > 13000){
    noTone(buzzerPin);
      function3 = false;
  }




}

void mode(int number){
  switch(number){
    case 0:
      digitalWrite(pin1,LOW);
      digitalWrite(pin2,LOW);
      digitalWrite(pin4,LOW);
    break;
    case 1:
      digitalWrite(pin1,HIGH);
      digitalWrite(pin2,LOW);
      digitalWrite(pin4,LOW);
    break;

    case 2:
      digitalWrite(pin1,LOW);
      digitalWrite(pin2,HIGH);
      digitalWrite(pin4,LOW);
    break;

    case 3:
      digitalWrite(pin1,HIGH);
      digitalWrite(pin2,HIGH);
      digitalWrite(pin4,LOW);
    break;

    case 4:
      digitalWrite(pin1,LOW);
      digitalWrite(pin2,LOW);
      digitalWrite(pin4,HIGH);
    break;

    case 5:
      digitalWrite(pin1,HIGH);
      digitalWrite(pin2,LOW);
      digitalWrite(pin4,HIGH);
    break;

    case 6:
      digitalWrite(pin1,LOW);
      digitalWrite(pin2,HIGH);
      digitalWrite(pin4,HIGH);
    break;

    case 7:
      digitalWrite(pin1,HIGH);
      digitalWrite(pin2,HIGH);
      digitalWrite(pin4,HIGH);
    break;

    default:
      digitalWrite(pin1,LOW);
      digitalWrite(pin2,LOW);
      digitalWrite(pin4,LOW);
  }
}





