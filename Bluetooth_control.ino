//Initialize Motor 1
int motor1Pin1 = 4;
int motor1Pin2 = 7;
int enable1Pin = 5;
 
//Initialize Motor 2
int motor2Pin1 = 12; 
int motor2Pin2 = 13; 
int enable2Pin = 6;

int led=8;
int led1=9;
int led2=10;
int led3=11;

 
int state;
void setup() {
    // sets the pins as outputs:
    
    pinMode(motor1Pin1, OUTPUT);
    pinMode(motor1Pin2, OUTPUT);
    pinMode(enable1Pin, OUTPUT);
    pinMode(motor2Pin1, OUTPUT);
    pinMode(motor2Pin2, OUTPUT);
    pinMode(enable2Pin, OUTPUT);
    pinMode(led,OUTPUT);
    pinMode(led1,OUTPUT);
    pinMode(led2,OUTPUT);
    pinMode(led3,OUTPUT);
    digitalWrite(led,LOW);
    digitalWrite(led1,LOW);
    digitalWrite(led2,LOW);
    digitalWrite(led3,LOW);
    
    // initialize serial communication at 9600 bits per second:
    Serial.begin(9600);
}
 
void loop() {
    //if some date is sent, reads it and saves in state
    if(Serial.available())
    {     
      state = Serial.read();
    }
    delay(100);
    // if the state is '1' the DC motor will go forward 
     
      if (state == 1) // forward
    {        
      digitalWrite(motor1Pin1, HIGH); 
      digitalWrite(motor1Pin2, LOW);
      digitalWrite(motor2Pin1, HIGH);
      digitalWrite(motor2Pin2, LOW);
      analogWrite(enable1Pin, 180);
      analogWrite(enable2Pin, 180);
      Serial.println("Forward");
    }
   
    else if (state == 2)  // left
    {
      //turn left
        digitalWrite(motor1Pin1, HIGH); 
        digitalWrite(motor1Pin2, LOW); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, HIGH);
        analogWrite(enable1Pin, 250);
        analogWrite(enable2Pin, 250);
        
        delay(150);
        
        state = 5;
        Serial.println("left");
    }
    
    else if (state == 5) //  Stop
    {
        digitalWrite(enable1Pin, 0);
        digitalWrite(enable2Pin, 0);
        digitalWrite(led,LOW);
        digitalWrite(led1,LOW);
        digitalWrite(led2,LOW);
        digitalWrite(led3,LOW);
        delay(300);
        Serial.println("stop");
    }
 
    else if (state == 3) // right
    {
      //TURN RIGHT
        digitalWrite(motor1Pin1, LOW); 
        digitalWrite(motor1Pin2, HIGH); 
        digitalWrite(motor2Pin1, HIGH);
        digitalWrite(motor2Pin2, LOW);
        analogWrite(enable1Pin, 250);
        analogWrite(enable2Pin, 250);
        
        delay(150);
        
        state = 5;
        
        Serial.println("right");
      
    }
    
    else if (state == 4) //reverse
    {
        
        digitalWrite(motor1Pin1, LOW); 
        digitalWrite(motor1Pin2, HIGH); 
        digitalWrite(motor2Pin1, LOW);
        digitalWrite(motor2Pin2, HIGH);
        analogWrite(enable1Pin, 180);
        analogWrite(enable2Pin, 180);
        delay(300);
        Serial.println("reverse");
    }

    else if(state==6)
    {
      digitalWrite(led,HIGH);
      digitalWrite(led1,HIGH);
      digitalWrite(led2,LOW);
      digitalWrite(led3,LOW);
      delay(300);
      Serial.println("Lights Onn");
      
    }

    else if(state==7)
    {
      digitalWrite(led2,HIGH);
      digitalWrite(led3,HIGH);
      digitalWrite(led1,LOW);
      digitalWrite(led,LOW);
      delay(300);
      Serial.println("Lights Off");
    }    
}
