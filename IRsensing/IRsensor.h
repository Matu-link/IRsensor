#ifndef _IRSENSOR_H_
#define _IRSENSOR_H_

#include "Arduino.h"
#define IR_NUM 8

// ハードウェア依存の変数
const uint8_t   SensorPins[IR_NUM]  = {11,13,15,17,33,35,37,39};
const float     unitVectorX[IR_NUM] = { 0.000, 0.500,  1.000,  0.500, 0.000, -0.500, -1.000,  -0.500 };
const float     unitVectorY[IR_NUM] = { 1.000,  0.500, 0.000, -0.500,  -1.000,  -0.500, 0.000, 0.500 };
const float     deltaPulseWidth     = 2.0;

typedef struct {
    int activeSensors;      // 反応したセンサの個数
    int maxPulseWidth;      // 最大のセンサ値
    int maxSensorNumber;    // 最大の値を観測したセンサの番号
} sensorInfo_t;

typedef struct {
    float x;
    float y;
} vectorXY_t;

typedef struct {
    float radius;
    float theta;
} vectorRT_t;

void setAllSensorPinsInput(void);
bool getSensorPin(uint8_t pin);
sensorInfo_t getAllSensorPulseWidth(float pulseWidth[IR_NUM], uint16_t timeLimit);
vectorXY_t calcVectorXYFromPulseWidth(float *pulseWidth);
vectorRT_t calcRTfromXY(vectorXY_t *vectorXY_p);

#endif // _IRSENSOR_H_
