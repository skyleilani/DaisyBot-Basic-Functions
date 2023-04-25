/*
 * Daisy Bot Basic Wiring Script
 * Author: Sky Leilani
 *
 * This script provides basic wiring and motor control for Dr. Carlotta Berry's Daisy Bot.
 * It defines pin configurations for the Arduino Mega and TB6612 motor driver, sets motor directions and speed, 
 *  and includes utility functions for pivoting and stopping the robot. 
 *
 * GitHub Repository: https://github.com/skyleilani/DaisyBot-Basic-Functions
 */

// Offsets are used to adjust speed of each motor in the case of speed differences between wheels 
const int offsetA = 0; 
const int offsetB = 0; 

// Pins for inputs, PWM defines must be on PWM pins 
#define AIN1 2
#define BIN1 6
#define AIN2 4
#define BIN2 7
#define PWMA 3
#define PWMB 5

// Motor directions 
#define FORWARD 1 
#define BACKWARD 2 
#define LEFT 3 
#define RIGHT 4 
#define STOP 5 

// Set motor direction and speed functionality for each motor individually
void setMotor(int motor, int direction, int speed) { 
   
  // Motor A functionality (left motor)
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
    if (speed >= 0 && speed <= 255){
       analogWrite(PWMA, speed+offsetA);  
    } else {
      Serial.println("Err: Please choose a speed value between 0 and 255.");  
    }      
  }

  // motor B functionality (right motor) 
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
    if (speed >= 0 && speed <= 255){
       analogWrite(PWMB, speed+offsetB);  
    } else {
      Serial.println("Err: Please choose a speed value between 0 and 255.");    
    }
  }
}

// Stop both motors 
void stopRobot() {
  setMotor(1, STOP, 0);
  setMotor(2, STOP, 0);
}

// Pivot right by running the left motor and not the right 
void pivotRight(int speed) {
  setMotor(1, FORWARD, speed);
  setMotor(2, STOP, 0);
}

// Pivot left by running right motor and not the left 
void pivotLeft(int speed) {
  setMotor(1, STOP, 0);
  setMotor(2, FORWARD, speed);
}

// Run both motors forward 
void forward(int speed) {
  setMotor(1, FORWARD, speed);
  setMotor(2, FORWARD, speed);
}

// Run both motors backward 
void backward(int speed) {
  setMotor(1, BACKWARD, speed);
  setMotor(2, BACKWARD, speed);
}

// Initialize motor control pins as outputs 
void setup() {
  // motor A 
  pinMode(AIN1, OUTPUT); 
  pinMode(AIN2, OUTPUT); 

  // motor B 
  pinMode(BIN1, OUTPUT); 
  pinMode(BIN2, OUTPUT); 

  // speed for motor A & motor B 
  pinMode(PWMA, OUTPUT); 
  pinMode(PWMB, OUTPUT);  
}

// Repeat function testing 
void loop() {
  
  forward(128);
  delay(2000); 
  stopRobot();
  delay(2000);
  
  pivotLeft(128); 
  delay(2000); 
  stopRobot();
  delay(2000); 
  
  pivotRight(128); 
  delay(2000); 
  stopRobot();
  delay(2000); 
   
}
