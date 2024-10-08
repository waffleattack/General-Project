/*////////////////////////////////////////////////////
 Name:    simple_helper_functions.h
 Created: 3/25/2019
 Author:  Petras Swissler

 Purpose: Define simple helper functions

 Limitations: Assumes 8 bits per byte
*/////////////////////////////////////////////////////
// Boilerplate ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#ifndef _SIMPLE_HELPER_FUNCTIONS_h
#define _SIMPLE_HELPER_FUNCTIONS_h

#if defined(ARDUINO) && ARDUINO >= 100
  #include "arduino.h"
#else
  #include "WProgram.h"
#endif

// Include Simple Definitions ~~~~~~~~~~~~~~~~~~~~~~~~
#ifdef __DEF_COMPUTER_G7__
  #include "C:\Users\Petra\OneDrive\NorthWestern\Lab\FA3D_2\Code\RobotCode\shared_definitions\def_friendly_names.h"
#endif // __DEF_COMPUTER_G7__
#ifdef __DEF_COMPUTER_GIGABYTE__
  #include "D:\petras\Onedrive\OneDrive\Onedrive\NorthWestern\Lab\FA3D_2\Code\RobotCode\shared_definitions\def_friendly_names.h"
#endif
// This library is intended to stand alone
// Define several useful terms ~~~~~~~~~~~~~~~~~~~~~~~
#define MS_PER_S      1000
#define BYTES_PER_FLOAT   sizeof(float)
#define BITS_PER_BYTE   8
// Low-Level Functions ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// None: All functions intended to stand alone
// Main Functions ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
// Simple Math Functions
void  normalizedNumber0to1(float* x, float* x_max, float* x_min);
void normalizedNumberNeg1to1(float* x, float* x_max, float* x_min);
void  adjustMaxMin(float* measurement, float* max_meas, float* min_meas);
float bound(float input, float minimum, float maximum);
float getFloatSign(float);
int   getIntSign(int);
float getMidof3(float, float, float);
float getSlope(float x1, float y1, float x2, float y2);
float getYIntercept(float x1, float y1, float slope);
int   isqrt(int);
uint8_t getAbsentByte(uint8_t A, uint8_t B, uint8_t option1, uint8_t option2, uint8_t option3);
float wrapToPi(float);
int   getNthPrime(int);

// Vector and Matrix Math Functions
void  vectorAdd_f(float* target_vec3, float vx, float vy, float vz, float scale);
float getVectorMagnitude(float x, float y, float z);
float vectorDotProduct(float* x0, float* y0, float* z0, float* x1, float* y1, float* z1);
void normalizeVector(float* x, float* y, float* z);
float getAngleBetweenVectors(float* x0, float* y0, float* z0, float* x1, float* y1, float* z1);

// Timing Functions
bool  checkTime(unsigned long startTime, unsigned long nowTime, float targetDuration_seconds);

// Measurement Functions
float getAvgReading(int, uint8_t);
int   getAvgReading_int(int pin, uint8_t numMeas);
int   getMaxofN(int pin, uint8_t numMeas);
int   getAvgReading_int_notHiOrLo(int pin, uint8_t numMeas);

// Filtering functions
float susdFilter(float meas, float last, float stepsize);
float expFilter(float newVal, float oldVal, float alpha);

// Value and type manipulation
void  floatToFourChars(float, uint8_t*);
float fourCharsToFloat(uint8_t*);
void  int16ToTwoChars(uint16_t inInt, uint8_t* outChar);
uint16_t twoCharsToInt16(uint8_t* inChar);
uint8_t s2u_int8(int8_t inbyte);
int8_t  u2s_int8(uint8_t inbyte);
uint8_t floatToEncodedByte(float inValue, float conversionFactor);
float encodedByteToFloat(uint8_t inValue, float conversionFactor);

// Serial Functions
char waitForKeypress(void);
void printArray(uint8_t* msgArray, uint8_t numBytes, bool use_send);

// Memory Management Functions
int getFreeMemory(void);
void clearArray(uint8_t* msgArray, uint8_t len);
// RGB Translation Function
void translation_function(float red_now, float green_now, float blue_now, float red_white, float green_white, float blue_white, float red_black, float green_black, float blue_black, float R_norm, float G_norm, float B_norm);

// Boilerplate ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
#endif
