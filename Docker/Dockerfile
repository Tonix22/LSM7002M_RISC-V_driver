FROM ubuntu:22.04

ENV DEBIAN_FRONTEND=noninteractive

# Actualizar e instalar paquetes necesarios
RUN apt-get update && apt-get install -y \
    iverilog \
    gtkwave \
    autoconf \
    automake \
    autotools-dev \
    curl \
    python3 \
    python3-pip \
    python3-tomli \
    libmpc-dev \
    libmpfr-dev \
    libgmp-dev \
    gawk \
    build-essential \
    bison \
    flex \
    texinfo \
    gperf \
    libtool \
    patchutils \
    bc \
    zlib1g-dev \
    libexpat-dev \
    ninja-build \
    git \
    cmake \
    libglib2.0-dev \
    libslirp-dev \
    sudo

# Clonar el repositorio riscv-gnu-toolchain
WORKDIR /opt
RUN git clone https://github.com/riscv/riscv-gnu-toolchain

# Compilar e instalar riscv-gnu-toolchain para rv32imc
WORKDIR /opt/riscv-gnu-toolchain
RUN ./configure --prefix=/opt/riscv --with-arch=rv32imc && \
    make -j$(nproc)

# Agregar /opt/riscv/bin al PATH
ENV PATH="/opt/riscv/bin:${PATH}"

# Descargar quartus

https://cdrdv2.intel.com/v1/dl/getContent/757261/757273?filename=Quartus-lite-22.1std.0.915-linux.tar

# Usuario por defecto
WORKDIR /workspace