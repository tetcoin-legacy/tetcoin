#### **Tetcoin (TET)**

The Currency for Change.

* Scrypt Algorithm
* 4 minute block targets
* subsidy halves in 544k blocks (~4 years)
* ~128 million total coins
* 128 coins per block
* 2016 blocks to retarget difficulty

##### **Install**

###### Ubuntu 14.04

Install Dependencies:

sudo apt-get update

Without Qt:

sudo apt-get install git autoconf autogen automake build-essential libboost-all-dev libcurl4-openssl-dev libdb-dev libdb++-dev libgmp3-dev libminiupnpc-dev libmpfr-dev libssl-dev libcurl4-openssl-dev libjansson-dev pax-utils

With Qt:

sudo apt-get install libqt4-dev qt4-qmake

cd ~/

git clone https://github.com/kediacorp/Tetcoin.git

cd Tetcoin/tetcoind/src

make -f makefile.unix

sudo cp ./tetcoind /usr/bin

###### Mac OSX

Without Qt:

brew install boost miniupnpc openssl berkeley-db4

With Qt:

brew install qt protobuf

cd Tetcoin/tetcoind/src

make -f makefile.osx

Build Qt:

cd Tetcoin

qmake tetcoin-qt.pro

nano Makefile

in LIBS change -L/opt/X11/bin to -L/usr/X11/bin, add -L/usr/local/opt/openssl/lib, or make other other changes

make -f Makefile RELEASE=1

##### **License**

Tetcoin Software is released under terms of the MIT License.  Refer to COPYING for further details.

