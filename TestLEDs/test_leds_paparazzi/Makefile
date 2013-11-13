DEBUG=yes

CC=arm-none-linux-gnueabi-gcc
INCLUDES=-I./paparazzi/includes/
DRONEFLAGS= -march=armv7-a
CXXFLAGS =-W -Wall -Wextra -g $(DRONEFLAGS) $(INCLUDES)
LDFLAGS =-lm -L./paparazzi/lib -lpaparazzi

SRC= $(wildcard *.c)
EXE= $(SRC:.c=.elf)
OBJ= $(SRC:.c=.o)

all: $(EXE)

%.o: %.c
	$(CC) $(CXXFLAGS) -o $@ -c $<

%.elf: %.o
	$(CC) $(LDFLAGS) $^ -o $@

.PHONY: depend clean realclean all tests

depend:
	makedepend -Y -r *.c

clean:
	$(RM) *.elf
	-$(RM) *~
	-$(RM) *.o
	-$(RM) *.bak core Makefile.bak
	-$(RM) $(EXEC)
