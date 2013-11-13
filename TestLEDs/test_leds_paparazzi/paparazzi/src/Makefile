SUBDIRS=capteur capteur/ahrs generated math moteur stabilization
.PHONY: subdirs $(SUBDIRS)

CC=arm-none-linux-gnueabi-g++
INCLUDES=
DRONEFLAGS= -march=armv7-a
CXXFLAGS=-W -Wall -Wextra -fPIC $(DRONEFLAGS)

LIBNAME=paparazzi

SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)

all: setup-lib setup-includes

lib$(LIBNAME).so.1.0: $(OBJ) subdirs
	$(CC) -shared -Wl,-soname,lib$(LIBNAME).so.1 -o lib$(LIBNAME).so.1.0 capteur/*.o capteur/ahrs/*.o math/*.o moteur/*.o stabilization/*.o *.o

subdirs: $(SUBDIRS)

$(SUBDIRS):
	$(MAKE) -C $@

%.o: %.c
	$(CC) $(CXXFLAGS) -o $@ -c $<

.PHONY : clean

setup-lib: lib$(LIBNAME).so.1.0
	mkdir -p ../lib
	mv lib$(LIBNAME).so.1.0 ../lib
	cd ../lib && ln -sf lib$(LIBNAME).so.1.0 lib$(LIBNAME).so.1 && ln -sf lib$(LIBNAME).so.1.0 lib$(LIBNAME).so

setup-includes: lib$(LIBNAME).so.1.0
	mkdir -p ../includes/paparazzi ../includes/paparazzi/capteur ../includes/paparazzi/capteur/ahrs ../includes/paparazzi/math ../includes/paparazzi/moteur ../includes/paparazzi/stabilization ../includes/paparazzi/generated/
	cp *.h ../includes/paparazzi/
	cp capteur/ahrs/*.h ../includes/paparazzi/capteur/ahrs/
	cp capteur/*.h ../includes/paparazzi/capteur/
	cp generated/*.h ../includes/paparazzi/generated/
	cp math/*.h ../includes/paparazzi/math/
	cp moteur/*.h ../includes/paparazzi/moteur/
	cp stabilization/*.h ../includes/paparazzi/stabilization/

open:
	emacs *.c *.h &

clean:
	for dir in $(SUBDIRS); do \
		$(MAKE) clean -C $$dir; \
        done
	rm -f *.o *~
