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



## Installation
> First we need to Install the RaspberryPi OS

https://www.raspberrypi.org/documentation/installation/installing-images/

> Linux
```bash
sudo apt install rpi-imager
```

> Windows
Download it from this Page:
https://www.raspberrypi.org/downloads/

or use Chocolatey [[Whats this?](https://chocolatey.org/why-chocolatey)]

```bash
choco install rpi-imager
```
####Setup Raspberry

Use raspi-config to enable SPI:


```bash
sudo raspi-config
```

- Select 5 Interfacing Options:
- Select P2 [SSH] and P4 [SPI]:
- Select *Yes*

- reboot

```bash
sudo shutdown -r now
```

### Setup the Raspberry Pi Software



1) Login to Raspberry Pi as the Pi user
2) Clone the repo [in root folder]
```bash
git clone https://github.com/dragino/dual_chan_pkt_fwd.git
```
3) Install wiringPi:

```bash
sudo apt-get install wiringpi
```


## Config
1) go to the dual channel forwarder folder:

```bash
cd ~/dual_chan_pkt_fwd
```

2) open global_conf.json to configurate the Package Forwarder
```bash
nano global_conf.json
```

3) Change the Server to the ChirpStack Address

```bash
"address": "CHIRPSTACK-ADDRESS",
```



4) Compile the dual channel forwarder code:
> get shure, that you are in the main directory [dual_chan_pkt_fwd]

```bash
make
```
5) run the Gateway
```bash
sudo ./ dual_chan_pkt_fwd
```
In some cases the sudo option generates a failure. If you get an “Unrecognized transreciver”, try the command without “sudo”
> you can Stop the Gateway with Crtl + C

6) Copy the Gateway ID from the Console in your clipboard

## TODO: Add ChirpStack Install Guide here


