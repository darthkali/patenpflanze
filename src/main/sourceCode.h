#include "Ticker.h"
const int pump = 4;

// --- Variables ---
int nStateChanged = 0;
int stateFlag = 1;
int nTime = 0;

// --- Types ---
enum SWITCH { OFF, ON };
enum STATE { stINIT, stCHECK, stPUMP, stWAIT };

STATE enState = stINIT;

double analogInput() { return analogRead(A0); }

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
             if(analogInput() > MINHUMIDITY){
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
