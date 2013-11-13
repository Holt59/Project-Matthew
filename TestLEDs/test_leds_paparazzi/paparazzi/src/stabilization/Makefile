CC=arm-none-linux-gnueabi-g++

DRONEFLAGS=-march=armv7-a
CXXFLAGS=-W -Wall -Wextra -fPIC $(DRONEFLAGS)

SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)

all: $(OBJ)

%.o: %.c
	$(CC) $(CXXFLAGS) -o $@ -c $<

.PHONY : clean

clean:
	rm -f *.o *~

open:
	emacs *.c *.h &
