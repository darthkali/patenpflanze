#define MINHUMIDITY         200      // Breakpoint on which humidity the system will react [0.65] Rage: [595 - 919]
#define WAIT_TIME           3600    // how long the system will stay in the WAIT State [1800 - every 30 minutes]
#define PUMP_TIME           2       // how long the system will stay in the PUMP State [2]

#define TX_INTERVAL         30      //Schedule TX every this many seconds (might become longer due to duty cycle limitations).

// Pin mapping
const lmic_pinmap lmic_pins = {
    .nss = 10,
    .rxtx = LMIC_UNUSED_PIN,
    .rst = 9,
    .dio = {2, 6, 7},
};


