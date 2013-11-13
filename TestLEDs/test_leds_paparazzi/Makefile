DEBUG=yes

#CC=arm-none-linux-gnueabi-gcc
CC=arm-none-linux-gnueabi-gcc
INCLUDES=-I./paparazzi/includes/
DRONEFLAGS= -march=armv7-a
CXXFLAGS =-W -Wall -Wextra -g $(DRONEFLAGS) $(INCLUDES)
LDFLAGS =-lm -L./paparazzi/lib -lpaparazzi
#-lpthread

EXEC = test_capteur
EXEC2 = test_leds
SRC= $(wildcard *.c) $(wildcard *.c)
OBJ= $(SRC:.c=.o)

all: $(EXEC) $(EXEC2)

$(EXEC): test_capteur.o
	$(CC) $(LDFLAGS) $^ -o $@
	
$(EXEC2): test_leds.o
	$(CC) $(LDFLAGS) $^ -o $@

test_capteur.o: test_capteur.c
	$(CC) $(CXXFLAGS) -o $@ -c $<

test_leds.o: test_leds.c
	$(CC) $(CXXFLAGS) -o $@ -c $<

.PHONY: depend clean realclean all tests

depend:
	makedepend -Y -r *.c

clean:
	$(RM) *.elf
	-$(RM) *~
	-$(RM) *.o
	-$(RM) *.bak core Makefile.bak
	-$(RM) $(EXEC)
	-$(RM) $(EXEC2)