#!/bin/bash

echo ">>>>>>>>>>>>>>>>>> Mudir build configuration start <<<<<<<<<<<<<<<<<<"

echo ">>>>>>>>>>>>>>>>>> Updating apt..."
sudo apt update

# echo ">>>>>>>>>>>>>>>>>> Upgrading packages..."
# sudo apt upgrade

echo ">>>>>>>>>>>>>>>>>> Installing cross-compile libraries..."
sudo apt install gcc-arm-linux-gnueabihf g++-arm-linux-gnueabihf libtool autoconf automake shtool pkg-config

echo ">>>>>>>>>>>>>>>>>> Installing CUnit Unit Test Framework..."
sudo apt install libcunit1 libcunit1-doc libcunit1-dev

echo ">>>>>>>>>>>>>>>>>> Installing xsltproc..."
sudo apt install xsltproc

echo ">>>>>>>>>>>>>>>>>> Mudir build configuration end <<<<<<<<<<<<<<<<<<"
