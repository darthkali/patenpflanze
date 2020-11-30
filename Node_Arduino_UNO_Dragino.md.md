# Node
Instructions to Build a LoRa Node

## What do you need?
### Hardware

- Arduino UNO
- LORA SHIELD (Dragino) v1.4 - 868MHZ

### Software
- Arduino IDE (optional)
- LMIC Library

## Setup Code
Download the code from git hub
You can find the Code in the following Folder:
/src/LoRaNode_Patenpflanze/
LoRaNode_Patenpflanze.ino

**config.h**
> - here you have the PIN-Configuration


**keys _example.h**
> - here you can set the Applications Keys (from ChirpStack)
> - please rename ist to **keys.h**
> - this fill will not be uploadet to a repository, when you let the **.gitignore** in your Project.


**sourceCode.h**
> - this ist your Source Code
> - here you can implement the logic from your Sensor
<!--stackedit_data:
eyJoaXN0b3J5IjpbMjM1NTY4NzEzLC0zNTAyMDQzOF19
-->