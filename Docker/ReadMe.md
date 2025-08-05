## Packet Instalation
sudo apt update
sudo apt install iverilog 
sudo apt-get install gtkwave
sudo apt-get install autoconf automake autotools-dev curl python3 python3-pip python3-tomli libmpc-dev libmpfr-dev libgmp-dev gawk build-essential bison flex texinfo gperf libtool patchutils bc zlib1g-dev libexpat-dev ninja-build git cmake libglib2.0-dev libslirp-dev

## Github repo

Seguir los pasos del siguiente repositorio:
$ git clone https://github.com/riscv/riscv-gnu-toolchain

La seccion de “Installation (Linux)” del repositorio reemplazar por:
 cd riscv-gnu-toolchain/
 ./configure --prefix=/opt/riscv --with-arch=rv32imc
 make -j$(nproc)
 make
 sudo linux