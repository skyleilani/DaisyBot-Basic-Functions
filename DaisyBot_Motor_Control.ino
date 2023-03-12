
// pins for inputs, PWM defines must be on PWM pins 
#define AIN1 2
#define BIN1 6
#define AIN2 4
#define BIN2 7
#define PWMA 3
#define PWMB 5

// define motor directions 
#define FORWARD 1 
#define BACKWARD 2 
#define LEFT 3 
#define RIGHT 4 
#define STOP 5 

/* 
standby which is optional you can run this for errors program it later maybee  
#define STBY 9 
*/

// Safeguard against wiring differences or future changes
const int offsetA = 1; 
const int offsetB = 1; 

// Set motor direction and speed 
void setMotor(int motor, int direction, int speed) { 
  // set motor direction pins based on the input direction 

  if(motor == 1) { 
    if (direction == FORWARD){ 
      digitalWrite(AIN1, LOW); 
      digitalWrite(AIN2, HIGH); 
    } 
    
    else if (direction == BACKWARD) { 
      digitalWrite(AIN1, HIGH); 
      digitalWrite(AIN2, LOW); 
    }

    else if (direction == STOP) { 
      digitalWrite(AIN1, LOW); 
      digitalWrite(AIN2, LOW); 
    }

    analogWrite(PWMA, speed+offsetA);  
  }

   else if(motor == 2) { 
    if (direction == FORWARD) { 
      digitalWrite(BIN1, LOW); 
      digitalWrite(BIN2, HIGH); 
    }

    else if (direction == BACKWARD) { 
      digitalWrite(BIN1, HIGH); 
      digitalWrite(BIN2, LOW);  
    }

    else if (direction == STOP) { 
      digitalWrite(BIN1, LOW); 
      digitalWrite(BIN2, LOW); 
    }

    analogWrite(PWMB, speed+offsetB); 
   }
}


void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}
