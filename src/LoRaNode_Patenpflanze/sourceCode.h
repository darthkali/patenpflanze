#include "Ticker.h"

#define MINHUMIDITY      480  // Breakpoint on which humidity the system will react [0.65]
#define WAIT_TIME        1800   // how long the system will stay in the WAIT State [1800 - every 30 minutes]
#define PUMP_TIME        2      // how long the system will stay in the PUMP State [2]
#define DATA_RESOLUTION  10     // Resolution for the Serial Data which will be printed to the Terminal [10]


const int pump = 4;
//Timer       stopWatchTimer;


// --- Variables ---
float testPeak = 0;
float adinRaw = 0;
int nStateChanged = 0;
int nPrintChanged = 0;
int stateFlag = 1;
int nTime = 0;

// StopWatch
int nTimer = 0;
int nHour = 0;
int nMin = 0;
int nSek = 0;
int nMill = 0;

// --- Types ---
enum STATE { stINIT, stCHECK, stPUMP, stWAIT };
enum PUMPSTATUS{ stON, stOFF };

STATE enState = stINIT;

int analogInput() {
        static int  analog =  1000 - analogRead(A0);
        int adin = 1000 - analogRead(A0)  ;
        
        analog = (analog * 49 + adin) /50;
        return analog;
}


void setNextStateAndTheWaitTime(STATE state, int time) {
    nStateChanged = nTime + time;
    enState = state;
}

 void StateMachine() {
    // calcTime();
   
     switch (enState) {
         case stINIT:
             digitalWrite(pump,LOW);   //pump Off
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
                 Serial.print("Pump\n");
                 digitalWrite(pump,HIGH);   //pump On
                 stateFlag = 0;
             }

             if (nStateChanged - nTime <= 0) {
                 digitalWrite(pump,LOW);   //pump Off
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
