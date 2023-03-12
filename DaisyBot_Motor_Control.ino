
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
const int offsetB = -1; 

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

// Initialize motor control pinss as outputs !
void setup() {
  pinMode(AIN1, OUTPUT); 
  pinMode(AIN2, OUTPUT); 
  
  pinMode(BIN1, OUTPUT); 
  pinMode(BIN2, OUTPUT); 

  pinMode(PWMA, OUTPUT); 
  pinMode(PWMB, OUTPUT);  
}

// tests basic functionality repeatedly
void loop() {
  // move robot forward at half speed for 2 seconds 
  setMotor(1, FORWARD, 128);
  setMotor(2, FORWARD, 128); 
  delay(2000); 

  //stop robot for 1 second
  setMotor(1, STOP, 0); 
  setMotor(2, STOP, 0); 
  delay(1000); 

  // pivot the robot left at half speed for 2 seconds 
  setMotor(1, FORWARD, 128); 
  setMotor(2, BACKWARD, 128); 
  delay(2000);
   
  // stop the robot for 1 second
  setMotor(1, STOP, 0);
  setMotor(2, STOP, 0);
  delay(1000);
  
  // move the robot backward at half speed for 2 seconds
  setMotor(1, BACKWARD, 128);
  setMotor(2, BACKWARD, 128);
  delay(2000);
  
  // stop the robot for 1 second
  setMotor(1, STOP, 0);
  setMotor(2, STOP, 0);
  delay(1000);
  
  // pivot the robot right at half speed for 2 seconds
  setMotor(1, BACKWARD, 128);
  setMotor(2, FORWARD, 128);
  delay(2000);

  // stop the robot for 1 second
  setMotor(1, STOP, 0);
  setMotor(2, STOP, 0);
  delay(1000);
}
