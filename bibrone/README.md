Bibrone - Parrot 2.0 Drivers Library
====================================

How to build?
===============

To build the drivers, you need a ARM cross compiler and a make utility (MinGW make works well for Windows). To build the drivers, just run:

```
make -f Makefile.unix
```

Replace `Makefile.unix` with `Makefile.win` if you're compiling under Windows.

Once you've built the library, you should find two folders `include` and `lib` in the `bibrone` directory. The include contains a `bibrone` subfolders with all header files, and the lib folder contains the static library.

How to use?
===========

Just add the path to the include folder and the library and run:

```
arm-none-linux-gnueabi-g++ -IPATH_TO_BIBRONE/include -LPATH_TO_BIBRONE/lib main.c -o main -lbibrone
```

Example of file:

```
#include <bibrone/SysTime.h>

#include <unistd.h>
#include <iostream>

void printCallBack (uint8_t a) {
    std::cout << "Call !" << std::endl ;
}

int main () {

    SysTime *systime = SysTime::getSysTime () ;
    
    tid_t mainID = systime->registerTimer (0.5, printCallBack);
    tid_t stopID = systime->registerTimer (10, 0) ;
    
    while (!systime->checkAndAckTimer(stopID)) {
        usleep(10) ;
    }
    
    return 0 ;
    
}
```
