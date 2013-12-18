DEBUG=no
STATIC=yes

CC=/usr/local/carlson-minot/crosscompilers/bin/arm-none-linux-gnueabi-gcc

PAPARAZZI_PATH=".."

INCLUDES=-I$(PAPARAZZI_PATH)/include/
DRONEFLAGS= -march=armv7-a
CFLAGS =-W -Wall -Wextra $(DRONEFLAGS) $(INCLUDES)
LDFLAGS =-L$(PAPARAZZI_PATH)/lib -lpaparazzi -lm

SRC=  $(wildcard *.c)
EXEC= $(SRC:.c=.elf)
OBJ=  $(SRC:.c=.o)

all: $(EXEC)

%.o: %.c
ifeq ($(DEBUG),yes)
	$(CC) -g $(CFLAGS) -o $@ -c $<
else
	$(CC) $(CFLAGS) -o $@ -c $<
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