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

**Download the code from git hub**

``` batch
git clone https://github.com/darthkali/patenpflanze
```
**You can find the Code in the following Folder:**
>/src/LoRaNode_Patenpflanze/

**LoRaNode_Patenpflanze.ino**
> - this is the main program which must be comiled to the Arduino
>  - it implements the header Files: *"**config**, **keys** and **sourceCode**"*

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
eyJoaXN0b3J5IjpbLTE1NDYyMjc5OTAsMjM1NTY4NzEzLC0zNT
AyMDQzOF19
-->