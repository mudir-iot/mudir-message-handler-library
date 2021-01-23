# mudir-message-handler-library

![Mudir CI](https://github.com/mudir-iot/mudir-message-handler-library/workflows/Mudir%20CI/badge.svg) [![codecov](https://codecov.io/gh/mudir-iot/mudir-message-handler-library/branch/main/graph/badge.svg?token=2KW3F1BVJN)](https://codecov.io/gh/mudir-iot/mudir-message-handler-library)

## Introduction

The library to handle messages between Mudir manager and devices (Sensors and Actuators).

## Installation Instructions for Developers

The following listing lists the commands to install components needed to run and build the components on Ubuntu (or Debian distros).

```shell
sudo apt install libcunit1 libcunit1-doc libcunit1-dev
sudo apt install gcc-arm-linux-gnueabihf g++-arm-linux-gnueabihf
sudo apt install xsltproc
```

Common components such as `gcc`, `gcov`, `make` and `libtool` are assumed to be installed on the developer machine. If not, then these must also be installed. 