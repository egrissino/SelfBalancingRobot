// Evan Grissino
// David Jeong
// Alex Claire
//
// 04/13/2017
// Self Balancing Robot
//

/* 
 *  ==============================================================================
 *  
 *  Copyright (c) 2017 Evan Grissino, Hyenjin Jeong, Alex Claire
 *  
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *  
 *  The above copyright notice and this permission notice shall be included in all
 *  copies or substantial portions of the Software. 
 *  
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 *  SOFTWARE.
 *  
 *  ============================================================================
 */ 

 
//======================================================================
// Equipment List and notes
//======================================================================
/* 
 *  - MPU6050 : Motion procoessor !Must be connect to 3.3 Volts!
 *  - 
 */

//======================================================================
// Pre-Processing
//======================================================================
#include <PID.h>
#include <Wire.h>
#include <I2Cdev.h>
#include "MPU_6050.h"

// Pre-Processing Definition - All are type const
#define NOT_AN_INTERRUPT -1
#define INTERRUPT_PIN 2
#define BAUD 9600

//======================================================================
// Variables and Objects
//======================================================================

// Global Namespace Declaration
float angle;
bool DMPready;

// Global Object Instantiation
MPU_6050 mpu(0x68);     // Defult adress for MPU6050
PID pid(0 , 0);         // current position and set point

//======================================================================
// Functions
//======================================================================
void dmpDataReady( void ) {
  interrupts();
  mpu.getRawData();
  mpu.resetFIFO();
  noInterrupts();
};

void initPID( void ) {
  pid.set_P(1);
  pid.set_I(0.2);
  pid.set_D(3);
  
  pid.set_gain(0.1);
  pid.begin(millis());
};


//======================================================================
// Setup - Runs once
//======================================================================
void setup( void ) {
  Serial.begin(BAUD);

  Wire.begin();
  mpu.initialize(true, false);
  
  attachInterrupt(digitalPinToInterrupt(INTERRUPT_PIN), dmpDataReady, RISING);
  DMPready = true;
};


//======================================================================
// loop - Runs forever
//======================================================================
void loop( void ) {
  
  mpu.processData();
  
  Serial.println(mpu.Angle.x);
  
  delay(10);
};





