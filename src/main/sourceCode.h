#include "Ticker.h"

#define MAP_RANGE_MIN       0.0     //minimum point, where the original_range_min will be mapped to
#define MAP_RANGE_MAX       100.0   //maximum point, where the original_range_max will be mapped to

#define RESULT_MAPPING(m,x,n) m * x + n

const int pump = 4;

// --- Variables ---
int nStateChanged = 0;
int stateFlag = 1;
int nTime = 0;
double m = 0.0; //value for the Mapping
double n = 0.0; //value for the Mapping

// --- Types ---
enum SWITCH { OFF, ON };
enum STATE { stINIT, stCHECK, stPUMP, stWAIT };

STATE enState = stINIT;

double mapAnalogInput(int analog){

    m = MAP_RANGE_MAX / (SENSOR_VALUE_MAX - SENSOR_VALUE_MIN);
    n = MAP_RANGE_MIN - m * SENSOR_VALUE_MIN;

    return RESULT_MAPPING(m, analog, n);
}

double analogInput() {
        static double  analog = 1000 - analogRead(A0);
        double adin =  1000 - analogRead(A0)  ;

        analog = (analog * 19 + adin) / 20;

        return mapAnalogInput(analog);
}

void setPump(bool state){
    if(state){
        digitalWrite(pump,LOW);   //pump Off
    }else{
        digitalWrite(pump,HIGH);   //pump On
    }
}

void setNextStateAndTheWaitTime(STATE state, int time) {
    nStateChanged = nTime + time;
    enState = state;
}

 void StateMachine() {

     switch (enState) {
         case stINIT:
             setPump(OFF);
             enState = stCHECK;
             break;

         case stCHECK:
             if(analogInput() < MINHUMIDITY){
                 setNextStateAndTheWaitTime(stPUMP, PUMP_TIME); //pump for x second
                 break;
             }

             setNextStateAndTheWaitTime(stWAIT, WAIT_TIME);    //wait y minutes
             break;

         case stPUMP:

             if(stateFlag == 1) {
                 setPump(ON);
                 stateFlag = 0;
             }

             if (nStateChanged - nTime <= 0) {
                 setPump(OFF);
                 stateFlag = 1;
                 setNextStateAndTheWaitTime(stWAIT, WAIT_TIME);    //wait y minutes
             }
             break;

         case stWAIT:
             if(stateFlag == 1) {
                 stateFlag = 0;
             }

             if (nStateChanged - nTime <= 0) {
                 stateFlag = 1;
                 enState = stCHECK;                  //check Status
             }
             break;
     }
 }
