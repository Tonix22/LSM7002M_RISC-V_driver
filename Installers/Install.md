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
