echo "*** Compilatiion of model $1 ***"

PAPARAZZI_INCLUDE="/Volumes/HDData/Documents/INSA/5A/Drone/repo/paparazzi/include/"
CFLAGS="-W -Wall -Wextra -march=armv7-a"

cd $1_grt_rtw

cp $1.mk Makefile
make clean

cd ../../src/real

arm-none-linux-gnueabi-gcc -I$PAPARAZZI_INCLUDE $CFLAGS -o $1.o -c $1.c
cp led.o ../../simulink_test/$1_grt_rtw/
cp led.h ../../simulink_test/$2_grt_rtw/

cd ../../simulink_test/$1_grt_rtw

sed -e "s/\$(MATLAB_ROOT)\/rtw\/c\/tools\/unixtools.mk/..\/..\/..\/ressources\/armtools.mk/" Makefile > Makefile.tmp
mv Makefile.tmp Makefile

sed -e "s/SYSLIBS = \$(EXT_LIB) -lm/SYSLIBS = \$(EXT_LIB) -lm -lpaparazzi/" Makefile > Makefile.tmp
mv Makefile.tmp Makefile

make

