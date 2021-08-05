# Install Quartus Prime Programmer Version 20.1.1
* *Step 1:* Go to this link [Quartus Prime Programmer Version 20.1.1](https://fpgasoftware.intel.com/?edition=lite)(linux) and download lite edition, the instalation is easy, unzip folder and run the instalation .sh file. 
* *Step 2:* Add quartus_pgm to your path which it will be in a folder like this one. 
```bash
sudo nano /home/tonix/.bashrc
#Add this line at the end of file
export PATH="~/intelFPGA_lite/20.1/quartus/bin:$PATH"
#exit, save file, and reload .bashrc 
source ~/.bashrc
```
* *Step 3:*  Generate USB blaster rule file, create this file /etc/udev/rules.d/51-usbblaster.rules
https://rocketboards.org/foswiki/Documentation/UsingUSBBlasterUnderLinux

```bash
sudo nano /etc/udev/rules.d/51-usbblaster.rules
#write this in file without enter 
# USB Blaster
SUBSYSTEM=="usb", ENV{DEVTYPE}=="usb_device", ATTR{idVendor}=="09fb", ATTR{idProduct}=="6001", MODE="0666", NAME="bus/usb/$env{BUSNUM}/$env{DEVNUM}", RUN+="/bin/chmod 0666 %c"
SUBSYSTEM=="usb", ENV{DEVTYPE}=="usb_device", ATTR{idVendor}=="09fb", ATTR{idProduct}=="6002", MODE="0666", NAME="bus/usb/$env{BUSNUM}/$env{DEVNUM}", RUN+="/bin/chmod 0666 %c"
SUBSYSTEM=="usb", ENV{DEVTYPE}=="usb_device", ATTR{idVendor}=="09fb", ATTR{idProduct}=="6003", MODE="0666", NAME="bus/usb/$env{BUSNUM}/$env{DEVNUM}", RUN+="/bin/chmod 0666 %c"

# USB Blaster II
SUBSYSTEM=="usb", ENV{DEVTYPE}=="usb_device", ATTR{idVendor}=="09fb", ATTR{idProduct}=="6010", MODE="0666", NAME="bus/usb/$env{BUSNUM}/$env{DEVNUM}", RUN+="/bin/chmod 0666 %c"
SUBSYSTEM=="usb", ENV{DEVTYPE}=="usb_device", ATTR{idVendor}=="09fb", ATTR{idProduct}=="6810", MODE="0666", NAME="bus/usb/$env{BUSNUM}/$env{DEVNUM}", RUN+="/bin/chmod 0666 %c"
```
Save the changes 

Now do something similar with this /etc/udev/rules.d/37-usbblaster.rules
https://mil.ufl.edu/3701/docs/quartus/linux/Programmer_linux.pdf

```bash
sudo nano /etc/udev/rules.d/37-usbblaster.rules
SUBSYSTEM=="usb", ATTRS{idVendor}=="09fb", ATTRS{idProduct}=="6001", GROUP="plugdev", MODE="0666", SYMLINK+="usbblaster" 
```
Save the changes 

* *Step 4:*
```bash
sudo service udev restart
```

* *Step 5:*
Unplug and replug your USB blaster

* *Step 6:* go to  FPGA_FW folder and run the script ./framework.sh -bistream
### Download Bitstream
We will use a bash script **FPGA_FW/framwork.sh** to simplify using some commands.
Inside this file check that **SOFT_DIR** is correct. 

```sh
#! /bin/bash
BASEDIR=${PWD}
#Bitstream PATH
#SOFT_DIR=/dupinSoC/hdl/dupin-cenzontle2.sof
SOFT_DIR=/dupinSoC/hdl/dupinCoprocessor-CNZTL2.sof
```

Download the bistream.
```console
cd FPGA_FW
foo@bar:~$ ./framework.sh -bitstream
```

<img src="https://www.wowza.com/uploads/blog/icon-advanced-controls.png" alt="drawing" width="40"/>
Troubleshooting

**Error code 89** It is related with step 3

**Error code 84** JTAG is not connected correctly or FPGA is power off

# Install openOCD

* *Step 1:* Unzip OpenOCD in place
* *Step 2:* Dependencies
```bash
sudo apt-get install libtool automake libusb-1.0.0-dev texinfo libusb-dev libyaml-dev pkg-config
```
* *Step 3:* build
```bash
./bootstrap
./configure --enable-ftdi --enable-dummy
make
sudo make install
```
<img src="https://www.wowza.com/uploads/blog/icon-advanced-controls.png" alt="drawing" width="40"/> Troubleshooting

If build fails intall a gcc version lower than 8
https://github.com/intel/gvt-linux/issues/167#issuecomment-676082889

How to manage with multiple gcc versions
https://linuxconfig.org/how-to-switch-between-multiple-gcc-and-g-compiler-versions-on-ubuntu-20-04-lts-focal-fossa

Delete -werror flag in the compiler for an easier solution

# Install RISC-V for platformio
Please follow this steps carefully:

* *Step 1:* Install [platformio](https://platformio.org/install) with the [VScode](https://platformio.org/install/ide?install=vscode) plugin.

<img src="https://www.wowza.com/uploads/blog/icon-advanced-controls.png" alt="drawing" width="40"/>
Troubleshooting

*Known Issue if platformio instalation fail*
https://github.com/platformio/platformio-core-installer/issues/85

* *Step 2:* Unzip and put  `./platform-dupinrv32.zip` in `~/.platformio/platforms/platform-dupinrv32`

```console
foo@bar: unzip platform-dupinrv32.zip
foo@bar: mv platform-dupinrv32 /home/tonix/.platformio/platforms/
```
Once this is done platformio should be able to find the riscV compiler
