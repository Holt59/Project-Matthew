.PHONY : clean

CC=arm-none-linux-gnueabi-gcc
AR=arm-none-linux-gnueabi-ar
INCLUDES=
DRONEFLAGS= -march=armv7-a
CXXFLAGS=-W -Wall -Wextra $(DRONEFLAGS)

LIBNAME=paparazzi

SRC= $(wildcard *.c) $(wildcard **/*.c) $(wildcard **/**/*.c)
OBJ_STATIC= $(SRC:.c=_static.o)
OBJ_SHARED= $(SRC:.c=_shared.o)
HEADERS= $(wildcard *.h) $(wildcard **/*.h) $(wildcard **/**/*.h)

all: setup-lib setup-includes

lib$(LIBNAME).so.1.0: $(OBJ_SHARED)
	$(CC) -shared -Wl,-soname,lib$(LIBNAME).so.1 -o lib$(LIBNAME).so.1.0 $(OBJ_SHARED)

lib$(LIBNAME).a: $(OBJ_STATIC)
	$(AR) rcs lib$(LIBNAME).a $(OBJ_STATIC)

%_shared.o: %.c
	$(CC) $(CXXFLAGS) -fPIC -o $@ -c $<

%_static.o: %.c
	$(CC) $(CXXFLAGS) -o $@ -c $<

setup-lib: lib$(LIBNAME).so.1.0 lib$(LIBNAME).a
	mkdir -p ../lib
	mv lib$(LIBNAME)* ../lib
	cd ../lib && ln -sf lib$(LIBNAME).so.1.0 lib$(LIBNAME).so.1 && ln -sf lib$(LIBNAME).so.1.0 lib$(LIBNAME).so

setup-includes:
	mkdir -p ../include/$(LIBNAME) 
	for FILE in $(HEADERS); do \
    	mkdir -p ../include/$(LIBNAME)/$$(dirname $$FILE); \
    	cp $$FILE ../include/$(LIBNAME)/$$(dirname $$FILE); \
	done

clean:
	rm -rf *.o *~
	rm -rf **/*.o **/*~
	rm -rf **/**/*.o **/**/*~
	rm -rf ../lib
	rm -rf ../include
