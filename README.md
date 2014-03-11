#### **Tetcoin (TET)**

Open source peer to peer currency.
* Scrypt Algorithm
* 4 minute block targets
* subsidy halves in 544k blocks (~4 years)
* ~128 million total coins
* 128 coins per block
* 2016 blocks to retarget difficulty

##### **Status**

03.10.14
* Successful build of codebase
* Genesis Block creation successful
* Live Tetcoin Server at tetcoin.com
* DNS seed server in development
* Mining Pools in development
* CPU + GPU Mining tests successful
* Blockchain replication successful

##### **Install**

Ubuntu 12.04 and 13.10

sudo apt-get update

Without Qt:

sudo apt-get install autoconf autogen automake build-essential git libdb++-dev libboost-dev libboost-system-dev libboost-filesystem-dev libboost-program-options-dev libboost-thread-dev libgmp3-dev libminiupnpc-dev libmpfr-dev libssl-dev libcurl4-openssl-dev libjansson-dev pax-utils

With Qt:

sudo apt-get install autoconf autogen automake build-essential git libdb++-dev libboost-dev libboost-system-dev libboost-filesystem-dev libboost-program-options-dev libboost-thread-dev libgmp3-dev libminiupnpc-dev libmpfr-dev libssl-dev libcurl4-openssl-dev libjansson-dev pax-utils libqt4-dev qt4-qmake

cd ~/
git clone https://github.com/kediacorp/Tetcoin.git
cd Tetcoin/tetcoind/src

make -f makefile.unix
sudo cp ./tetcoind /usr/bin

##### **License**

Tetcoin Software is released under terms of the MIT License.  Refer to COPYING for further details.
