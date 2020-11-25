# Gateway - ChirpStack
Instructions to Build a Dual Channel LoRa Gateway with ChirpStack

## What do you need?
### Hardware

> Raspberry Pi 4 Modell B

<img src="raspberryPi_4.jpg" alt="Raspberry Pi 4 Modell B" width="100" >

> Dragino LoRa/GPS HAT

<img src="LoRaHAT_RaspberryPi.jpg" alt="Dragino LoRa/GPS HAT" width="100" >

> 16 GB SD-Card

<img src="SD-Card-16.jpg" alt="16 GB SD-Card" width="50" >
 

### Software
- Raspberry Pi Operation System [link and instruction below]
- Dual Channel Package Forwarder [link and instruction below]


## Installation RaspberryPi OS
>You can find all Informations here:
> https://www.raspberrypi.org/software/

#### Linux
```bash
sudo apt install rpi-imager
```

#### Windows
> Download it from this Page:
https://www.raspberrypi.org/downloads/

or use Chocolatey [[Whats this?](https://chocolatey.org/why-chocolatey)]

```bash
choco install rpi-imager
```
## Setup Raspberry

#### Remote access:

```bash
sudo raspi-config
```

- Select 5 Interfacing Options:
- Select P2 [SSH] and P4 [SPI]:
- Select *Yes*

```bash
sudo apt-get install xrdp
```
```bash
sudo shutdown -r now
```

### Setup - Dual Channel Package Forwarder

1) Login to Raspberry Pi as the Pi user
2) Clone the repo [in root folder]

```bash
git clone https://github.com/dragino/dual_chan_pkt_fwd.git
```
3) Install wiringPi:

```bash
sudo apt-get install wiringpi
```
### Config - Dual Channel Package Forwarder
1) go to the dual channel forwarder folder:

```bash
cd ~/dual_chan_pkt_fwd
```

2) open global_conf.json to configurate the Package Forwarder
```bash
nano global_conf.json
```

3) Change the Server to the ChirpStack Address

```json
{
  "SX127x_conf":
  {
    "freq": 868100000,
    "freq_2": 868100000,
    "spread_factor": 7,
    "pin_nss": 6,
    "pin_dio0": 7,
    "pin_nss_2": 6,
    "pin_dio0_2": 7,
    "pin_rst": 3,
    "pin_led1":4,
    "pin_NetworkLED": 22,
    "pin_InternetLED": 23,
    "pin_ActivityLED_0": 21,
    "pin_ActivityLED_1": 29
  },
  "gateway_conf":
  {
    "ref_latitude": 0.0,
    "ref_longitude": 0.0,
    "ref_altitude": 10,

    "name": "your name",
    "email": "a@b.c",
    "desc": "Dual channel pkt forwarder",

    "interface": "eth0",

    "servers":
    [
      {
        "address": "TYPE_IN_YOUR_CHIRPSTACK_SERVER_ADDRESS",
        "port": 1700,
        "enabled": true
      },
      {
        "address": "router.eu.thethings.network",
        "port": 1700,
        "enabled": false
      }
    ]
  }
}
```


```json
"address": "TYPE_IN_YOUR_CHIRPSTACK_SERVER_ADDRESS",
```
> the adress should be something like: 
> router.eu.thethings.network
> or
> myserver.com

4) Compile the dual channel forwarder code:
> get shure, that you are in the main directory [dual_chan_pkt_fwd]

```bash
make
```
5) run the Gateway
```bash
sudo ./ dual_chan_pkt_fwd
```
> - in some cases the "sudo" option generates a failure. If you get an “Unrecognized transreciver”, try the command without “sudo”
> - you can Stop the Gateway with Crtl + C

6) Copy the Gateway ID from the Console in your clipboard

## Gateway on Chirp Stack 

go to Gateways
+ CREATE
enter a Gateway Name and Description
Generate a Gateway ID in MSB
select a networkl server
> mybe you need to Create this TODO
set the altitude and the location of the gateway
click on create Gateway
<!--stackedit_data:
eyJoaXN0b3J5IjpbLTI2MTQ0NDI0Nyw0NzE1MTExMCwyOTU1Nz
U4MjYsLTIwOTcyMjc3MTQsLTI3OTA5NDQzMl19
-->