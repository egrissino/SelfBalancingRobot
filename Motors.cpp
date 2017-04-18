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

#ifndef MOTORS
#define MOTORS
#endif

#include "Arduino.h"


//// ========== ASSUMES INCLUSION OF ARDUINO HEADERS ========= ////

class Motor {
    public:
    // All public variables and methods go here...      !NOTE: please use private state variables and public access methods
   
    // =============   Constructors   ============== //
    Motor( int pin ) {
        pinMode(OUTPUT, pin);
        
    }
    
    // ===============   Variables   =============== //
    
    
    // ===============   Functions   =============== //
    
    private:
    // All private variables and methods go here...
    // ===============   Variables   =============== //
    
    
    // ===============   Functions   =============== //
    
};
