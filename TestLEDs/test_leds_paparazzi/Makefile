DEBUG=no
STATIC=yes

CC=arm-none-linux-gnueabi-gcc
INCLUDES=-I../../paparazzi/include/
DRONEFLAGS= -march=armv7-a
CXXFLAGS =-W -Wall -Wextra $(DRONEFLAGS) $(INCLUDES)
LDFLAGS =-L../../paparazzi/lib -lpaparazzi -lm

SRC=  $(wildcard *.c)
EXEC= $(SRC:.c=.elf)
OBJ=  $(SRC:.c=.o)

all: $(EXEC)

%.o: %.c
ifeq ($(DEBUG),yes)
	$(CC) -g $(CXXFLAGS) -o $@ -c $<
else
	$(CC) $(CXXFLAGS) -o $@ -c $<
endif

%.elf: %.o
ifeq ($(STATIC),yes)
	$(CC) -static $^ -o $@ $(LDFLAGS)
else
	$(CC) $^ -o $@ $(LDFLAGS)
endif

.PHONY: clean all

clean:
	$(RM) *.elf
	-$(RM) *~
	-$(RM) *.o
	-$(RM) *.bak core Makefile.bak
	-$(RM) $(EXEC)