# 1 "imu.h"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "imu.h"
# 34 "imu.h"
# 1 "../math/pprz_algebra_int.h" 1
# 37 "../math/pprz_algebra_int.h"
# 1 "../math/../std.h" 1
# 33 "../math/../std.h"
# 1 "i:\\mingw\\bin\\../lib/gcc/mingw32/4.6.2/../../../../include/inttypes.h" 1 3





# 1 "i:\\mingw\\bin\\../lib/gcc/mingw32/4.6.2/../../../../include/_mingw.h" 1 3
# 32 "i:\\mingw\\bin\\../lib/gcc/mingw32/4.6.2/../../../../include/_mingw.h" 3
       
# 33 "i:\\mingw\\bin\\../lib/gcc/mingw32/4.6.2/../../../../include/_mingw.h" 3
# 7 "i:\\mingw\\bin\\../lib/gcc/mingw32/4.6.2/../../../../include/inttypes.h" 2 3
# 1 "i:\\mingw\\bin\\../lib/gcc/mingw32/4.6.2/include/stdint.h" 1 3 4


# 1 "i:\\mingw\\bin\\../lib/gcc/mingw32/4.6.2/../../../../include/stdint.h" 1 3 4
# 24 "i:\\mingw\\bin\\../lib/gcc/mingw32/4.6.2/../../../../include/stdint.h" 3 4
# 1 "i:\\mingw\\bin\\../lib/gcc/mingw32/4.6.2/include/stddef.h" 1 3 4
# 324 "i:\\mingw\\bin\\../lib/gcc/mingw32/4.6.2/include/stddef.h" 3 4
typedef short unsigned int wchar_t;
# 353 "i:\\mingw\\bin\\../lib/gcc/mingw32/4.6.2/include/stddef.h" 3 4
typedef short unsigned int wint_t;
# 25 "i:\\mingw\\bin\\../lib/gcc/mingw32/4.6.2/../../../../include/stdint.h" 2 3 4


typedef signed char int8_t;
typedef unsigned char uint8_t;
typedef short int16_t;
typedef unsigned short uint16_t;
typedef int int32_t;
typedef unsigned uint32_t;
typedef long long int64_t;
typedef unsigned long long uint64_t;


typedef signed char int_least8_t;
typedef unsigned char uint_least8_t;
typedef short int_least16_t;
typedef unsigned short uint_least16_t;
typedef int int_least32_t;
typedef unsigned uint_least32_t;
typedef long long int_least64_t;
typedef unsigned long long uint_least64_t;





typedef signed char int_fast8_t;
typedef unsigned char uint_fast8_t;
typedef short int_fast16_t;
typedef unsigned short uint_fast16_t;
typedef int int_fast32_t;
typedef unsigned int uint_fast32_t;
typedef long long int_fast64_t;
typedef unsigned long long uint_fast64_t;
# 66 "i:\\mingw\\bin\\../lib/gcc/mingw32/4.6.2/../../../../include/stdint.h" 3 4
  typedef int intptr_t;
# 75 "i:\\mingw\\bin\\../lib/gcc/mingw32/4.6.2/../../../../include/stdint.h" 3 4
  typedef unsigned int uintptr_t;




typedef long long intmax_t;
typedef unsigned long long uintmax_t;
# 4 "i:\\mingw\\bin\\../lib/gcc/mingw32/4.6.2/include/stdint.h" 2 3 4
# 8 "i:\\mingw\\bin\\../lib/gcc/mingw32/4.6.2/../../../../include/inttypes.h" 2 3

# 1 "i:\\mingw\\bin\\../lib/gcc/mingw32/4.6.2/include/stddef.h" 1 3 4
# 10 "i:\\mingw\\bin\\../lib/gcc/mingw32/4.6.2/../../../../include/inttypes.h" 2 3





typedef struct {
 intmax_t quot;
 intmax_t rem;
 } imaxdiv_t;
# 258 "i:\\mingw\\bin\\../lib/gcc/mingw32/4.6.2/../../../../include/inttypes.h" 3
intmax_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) imaxabs (intmax_t j);




imaxdiv_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) imaxdiv (intmax_t numer, intmax_t denom);



intmax_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strtoimax (const char* __restrict__ nptr,
                            char** __restrict__ endptr, int base);
uintmax_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strtoumax (const char* __restrict__ nptr,
        char** __restrict__ endptr, int base);

intmax_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcstoimax (const wchar_t* __restrict__ nptr,
                            wchar_t** __restrict__ endptr, int base);
uintmax_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcstoumax (const wchar_t* __restrict__ nptr,
        wchar_t** __restrict__ endptr, int base);
# 34 "../math/../std.h" 2

# 1 "i:\\mingw\\bin\\../lib/gcc/mingw32/4.6.2/../../../../include/math.h" 1 3
# 16 "i:\\mingw\\bin\\../lib/gcc/mingw32/4.6.2/../../../../include/math.h" 3
       
# 17 "i:\\mingw\\bin\\../lib/gcc/mingw32/4.6.2/../../../../include/math.h" 3
# 134 "i:\\mingw\\bin\\../lib/gcc/mingw32/4.6.2/../../../../include/math.h" 3
struct _exception
{
 int type;
 char *name;
 double arg1;
 double arg2;
 double retval;
};

 double __attribute__((__cdecl__)) sin (double);
 double __attribute__((__cdecl__)) cos (double);
 double __attribute__((__cdecl__)) tan (double);
 double __attribute__((__cdecl__)) sinh (double);
 double __attribute__((__cdecl__)) cosh (double);
 double __attribute__((__cdecl__)) tanh (double);
 double __attribute__((__cdecl__)) asin (double);
 double __attribute__((__cdecl__)) acos (double);
 double __attribute__((__cdecl__)) atan (double);
 double __attribute__((__cdecl__)) atan2 (double, double);
 double __attribute__((__cdecl__)) exp (double);
 double __attribute__((__cdecl__)) log (double);
 double __attribute__((__cdecl__)) log10 (double);
 double __attribute__((__cdecl__)) pow (double, double);
 double __attribute__((__cdecl__)) sqrt (double);
 double __attribute__((__cdecl__)) ceil (double);
 double __attribute__((__cdecl__)) floor (double);
 double __attribute__((__cdecl__)) fabs (double);
 double __attribute__((__cdecl__)) ldexp (double, int);
 double __attribute__((__cdecl__)) frexp (double, int*);
 double __attribute__((__cdecl__)) modf (double, double*);
 double __attribute__((__cdecl__)) fmod (double, double);
# 210 "i:\\mingw\\bin\\../lib/gcc/mingw32/4.6.2/../../../../include/math.h" 3
struct _complex
{
 double x;
 double y;
};

 double __attribute__((__cdecl__)) _cabs (struct _complex);

 double __attribute__((__cdecl__)) _hypot (double, double);
 double __attribute__((__cdecl__)) _j0 (double);
 double __attribute__((__cdecl__)) _j1 (double);
 double __attribute__((__cdecl__)) _jn (int, double);
 double __attribute__((__cdecl__)) _y0 (double);
 double __attribute__((__cdecl__)) _y1 (double);
 double __attribute__((__cdecl__)) _yn (int, double);
 int __attribute__((__cdecl__)) _matherr (struct _exception *);
# 234 "i:\\mingw\\bin\\../lib/gcc/mingw32/4.6.2/../../../../include/math.h" 3
 double __attribute__((__cdecl__)) _chgsign (double);
 double __attribute__((__cdecl__)) _copysign (double, double);
 double __attribute__((__cdecl__)) _logb (double);
 double __attribute__((__cdecl__)) _nextafter (double, double);
 double __attribute__((__cdecl__)) _scalb (double, long);

 int __attribute__((__cdecl__)) _finite (double);
 int __attribute__((__cdecl__)) _fpclass (double);
 int __attribute__((__cdecl__)) _isnan (double);
# 254 "i:\\mingw\\bin\\../lib/gcc/mingw32/4.6.2/../../../../include/math.h" 3
 double __attribute__((__cdecl__)) j0 (double);
 double __attribute__((__cdecl__)) j1 (double);
 double __attribute__((__cdecl__)) jn (int, double);
 double __attribute__((__cdecl__)) y0 (double);
 double __attribute__((__cdecl__)) y1 (double);
 double __attribute__((__cdecl__)) yn (int, double);

 double __attribute__((__cdecl__)) chgsign (double);
# 270 "i:\\mingw\\bin\\../lib/gcc/mingw32/4.6.2/../../../../include/math.h" 3
 int __attribute__((__cdecl__)) finite (double);
 int __attribute__((__cdecl__)) fpclass (double);
# 324 "i:\\mingw\\bin\\../lib/gcc/mingw32/4.6.2/../../../../include/math.h" 3
typedef long double float_t;
typedef long double double_t;
# 354 "i:\\mingw\\bin\\../lib/gcc/mingw32/4.6.2/../../../../include/math.h" 3
extern int __attribute__((__cdecl__)) __fpclassifyf (float);
extern int __attribute__((__cdecl__)) __fpclassify (double);
extern int __attribute__((__cdecl__)) __fpclassifyl (long double);
# 379 "i:\\mingw\\bin\\../lib/gcc/mingw32/4.6.2/../../../../include/math.h" 3
extern int __attribute__((__cdecl__)) __isnan (double);
extern int __attribute__((__cdecl__)) __isnanf (float);
extern int __attribute__((__cdecl__)) __isnanl (long double);
# 419 "i:\\mingw\\bin\\../lib/gcc/mingw32/4.6.2/../../../../include/math.h" 3
extern int __attribute__((__cdecl__)) __signbit (double);
extern int __attribute__((__cdecl__)) __signbitf (float);
extern int __attribute__((__cdecl__)) __signbitl (long double);
# 447 "i:\\mingw\\bin\\../lib/gcc/mingw32/4.6.2/../../../../include/math.h" 3
extern float __attribute__((__cdecl__)) sinf (float);
extern long double __attribute__((__cdecl__)) sinl (long double);

extern float __attribute__((__cdecl__)) cosf (float);
extern long double __attribute__((__cdecl__)) cosl (long double);

extern float __attribute__((__cdecl__)) tanf (float);
extern long double __attribute__((__cdecl__)) tanl (long double);

extern float __attribute__((__cdecl__)) asinf (float);
extern long double __attribute__((__cdecl__)) asinl (long double);

extern float __attribute__((__cdecl__)) acosf (float);
extern long double __attribute__((__cdecl__)) acosl (long double);

extern float __attribute__((__cdecl__)) atanf (float);
extern long double __attribute__((__cdecl__)) atanl (long double);

extern float __attribute__((__cdecl__)) atan2f (float, float);
extern long double __attribute__((__cdecl__)) atan2l (long double, long double);


extern float __attribute__((__cdecl__)) sinhf (float);




extern long double __attribute__((__cdecl__)) sinhl (long double);

extern float __attribute__((__cdecl__)) coshf (float);




extern long double __attribute__((__cdecl__)) coshl (long double);

extern float __attribute__((__cdecl__)) tanhf (float);




extern long double __attribute__((__cdecl__)) tanhl (long double);



extern double __attribute__((__cdecl__)) acosh (double);
extern float __attribute__((__cdecl__)) acoshf (float);
extern long double __attribute__((__cdecl__)) acoshl (long double);


extern double __attribute__((__cdecl__)) asinh (double);
extern float __attribute__((__cdecl__)) asinhf (float);
extern long double __attribute__((__cdecl__)) asinhl (long double);


extern double __attribute__((__cdecl__)) atanh (double);
extern float __attribute__((__cdecl__)) atanhf (float);
extern long double __attribute__((__cdecl__)) atanhl (long double);



extern float __attribute__((__cdecl__)) expf (float);




extern long double __attribute__((__cdecl__)) expl (long double);


extern double __attribute__((__cdecl__)) exp2(double);
extern float __attribute__((__cdecl__)) exp2f(float);
extern long double __attribute__((__cdecl__)) exp2l(long double);



extern double __attribute__((__cdecl__)) expm1(double);
extern float __attribute__((__cdecl__)) expm1f(float);
extern long double __attribute__((__cdecl__)) expm1l(long double);


extern float __attribute__((__cdecl__)) frexpf (float, int*);




extern long double __attribute__((__cdecl__)) frexpl (long double, int*);




extern int __attribute__((__cdecl__)) ilogb (double);
extern int __attribute__((__cdecl__)) ilogbf (float);
extern int __attribute__((__cdecl__)) ilogbl (long double);


extern float __attribute__((__cdecl__)) ldexpf (float, int);




extern long double __attribute__((__cdecl__)) ldexpl (long double, int);


extern float __attribute__((__cdecl__)) logf (float);
extern long double __attribute__((__cdecl__)) logl (long double);


extern float __attribute__((__cdecl__)) log10f (float);
extern long double __attribute__((__cdecl__)) log10l (long double);


extern double __attribute__((__cdecl__)) log1p(double);
extern float __attribute__((__cdecl__)) log1pf(float);
extern long double __attribute__((__cdecl__)) log1pl(long double);


extern double __attribute__((__cdecl__)) log2 (double);
extern float __attribute__((__cdecl__)) log2f (float);
extern long double __attribute__((__cdecl__)) log2l (long double);


extern double __attribute__((__cdecl__)) logb (double);
extern float __attribute__((__cdecl__)) logbf (float);
extern long double __attribute__((__cdecl__)) logbl (long double);
# 603 "i:\\mingw\\bin\\../lib/gcc/mingw32/4.6.2/../../../../include/math.h" 3
extern float __attribute__((__cdecl__)) modff (float, float*);
extern long double __attribute__((__cdecl__)) modfl (long double, long double*);


extern double __attribute__((__cdecl__)) scalbn (double, int);
extern float __attribute__((__cdecl__)) scalbnf (float, int);
extern long double __attribute__((__cdecl__)) scalbnl (long double, int);

extern double __attribute__((__cdecl__)) scalbln (double, long);
extern float __attribute__((__cdecl__)) scalblnf (float, long);
extern long double __attribute__((__cdecl__)) scalblnl (long double, long);



extern double __attribute__((__cdecl__)) cbrt (double);
extern float __attribute__((__cdecl__)) cbrtf (float);
extern long double __attribute__((__cdecl__)) cbrtl (long double);


extern float __attribute__((__cdecl__)) fabsf (float x);
extern long double __attribute__((__cdecl__)) fabsl (long double x);


extern double __attribute__((__cdecl__)) hypot (double, double);
extern float __attribute__((__cdecl__)) hypotf (float, float);




extern long double __attribute__((__cdecl__)) hypotl (long double, long double);


extern float __attribute__((__cdecl__)) powf (float, float);




extern long double __attribute__((__cdecl__)) powl (long double, long double);


extern float __attribute__((__cdecl__)) sqrtf (float);
extern long double __attribute__((__cdecl__)) sqrtl (long double);


extern double __attribute__((__cdecl__)) erf (double);
extern float __attribute__((__cdecl__)) erff (float);
extern long double __attribute__((__cdecl__)) erfl (long double);


extern double __attribute__((__cdecl__)) erfc (double);
extern float __attribute__((__cdecl__)) erfcf (float);
extern long double __attribute__((__cdecl__)) erfcl (long double);


extern double __attribute__((__cdecl__)) lgamma (double);
extern float __attribute__((__cdecl__)) lgammaf (float);
extern long double __attribute__((__cdecl__)) lgammal (long double);


extern double __attribute__((__cdecl__)) tgamma (double);
extern float __attribute__((__cdecl__)) tgammaf (float);
extern long double __attribute__((__cdecl__)) tgammal (long double);


extern float __attribute__((__cdecl__)) ceilf (float);
extern long double __attribute__((__cdecl__)) ceill (long double);


extern float __attribute__((__cdecl__)) floorf (float);
extern long double __attribute__((__cdecl__)) floorl (long double);


extern double __attribute__((__cdecl__)) nearbyint ( double);
extern float __attribute__((__cdecl__)) nearbyintf (float);
extern long double __attribute__((__cdecl__)) nearbyintl (long double);



extern double __attribute__((__cdecl__)) rint (double);
extern float __attribute__((__cdecl__)) rintf (float);
extern long double __attribute__((__cdecl__)) rintl (long double);


extern long __attribute__((__cdecl__)) lrint (double);
extern long __attribute__((__cdecl__)) lrintf (float);
extern long __attribute__((__cdecl__)) lrintl (long double);

extern long long __attribute__((__cdecl__)) llrint (double);
extern long long __attribute__((__cdecl__)) llrintf (float);
extern long long __attribute__((__cdecl__)) llrintl (long double);
# 771 "i:\\mingw\\bin\\../lib/gcc/mingw32/4.6.2/../../../../include/math.h" 3
extern double __attribute__((__cdecl__)) round (double);
extern float __attribute__((__cdecl__)) roundf (float);
extern long double __attribute__((__cdecl__)) roundl (long double);


extern long __attribute__((__cdecl__)) lround (double);
extern long __attribute__((__cdecl__)) lroundf (float);
extern long __attribute__((__cdecl__)) lroundl (long double);

extern long long __attribute__((__cdecl__)) llround (double);
extern long long __attribute__((__cdecl__)) llroundf (float);
extern long long __attribute__((__cdecl__)) llroundl (long double);



extern double __attribute__((__cdecl__)) trunc (double);
extern float __attribute__((__cdecl__)) truncf (float);
extern long double __attribute__((__cdecl__)) truncl (long double);


extern float __attribute__((__cdecl__)) fmodf (float, float);
extern long double __attribute__((__cdecl__)) fmodl (long double, long double);


extern double __attribute__((__cdecl__)) remainder (double, double);
extern float __attribute__((__cdecl__)) remainderf (float, float);
extern long double __attribute__((__cdecl__)) remainderl (long double, long double);


extern double __attribute__((__cdecl__)) remquo(double, double, int *);
extern float __attribute__((__cdecl__)) remquof(float, float, int *);
extern long double __attribute__((__cdecl__)) remquol(long double, long double, int *);


extern double __attribute__((__cdecl__)) copysign (double, double);
extern float __attribute__((__cdecl__)) copysignf (float, float);
extern long double __attribute__((__cdecl__)) copysignl (long double, long double);


extern double __attribute__((__cdecl__)) nan(const char *tagp);
extern float __attribute__((__cdecl__)) nanf(const char *tagp);
extern long double __attribute__((__cdecl__)) nanl(const char *tagp);
# 821 "i:\\mingw\\bin\\../lib/gcc/mingw32/4.6.2/../../../../include/math.h" 3
extern double __attribute__((__cdecl__)) nextafter (double, double);
extern float __attribute__((__cdecl__)) nextafterf (float, float);
extern long double __attribute__((__cdecl__)) nextafterl (long double, long double);


extern double __attribute__((__cdecl__)) nexttoward (double, long double);
extern float __attribute__((__cdecl__)) nexttowardf (float, long double);
extern long double __attribute__((__cdecl__)) nexttowardl (long double, long double);



extern double __attribute__((__cdecl__)) fdim (double x, double y);
extern float __attribute__((__cdecl__)) fdimf (float x, float y);
extern long double __attribute__((__cdecl__)) fdiml (long double x, long double y);







extern double __attribute__((__cdecl__)) fmax (double, double);
extern float __attribute__((__cdecl__)) fmaxf (float, float);
extern long double __attribute__((__cdecl__)) fmaxl (long double, long double);


extern double __attribute__((__cdecl__)) fmin (double, double);
extern float __attribute__((__cdecl__)) fminf (float, float);
extern long double __attribute__((__cdecl__)) fminl (long double, long double);



extern double __attribute__((__cdecl__)) fma (double, double, double);
extern float __attribute__((__cdecl__)) fmaf (float, float, float);
extern long double __attribute__((__cdecl__)) fmal (long double, long double, long double);
# 36 "../math/../std.h" 2
# 77 "../math/../std.h"
typedef uint8_t bool_t;


typedef uint8_t unit_t;
# 38 "../math/pprz_algebra_int.h" 2
# 1 "../math/pprz_algebra.h" 1
# 30 "../math/pprz_algebra.h"
# 1 "i:\\mingw\\bin\\../lib/gcc/mingw32/4.6.2/include/float.h" 1 3 4
# 31 "../math/pprz_algebra.h" 2
# 1 "i:\\mingw\\bin\\../lib/gcc/mingw32/4.6.2/../../../../include/string.h" 1 3
# 24 "i:\\mingw\\bin\\../lib/gcc/mingw32/4.6.2/../../../../include/string.h" 3
# 1 "i:\\mingw\\bin\\../lib/gcc/mingw32/4.6.2/include/stddef.h" 1 3 4
# 212 "i:\\mingw\\bin\\../lib/gcc/mingw32/4.6.2/include/stddef.h" 3 4
typedef unsigned int size_t;
# 25 "i:\\mingw\\bin\\../lib/gcc/mingw32/4.6.2/../../../../include/string.h" 2 3
# 36 "i:\\mingw\\bin\\../lib/gcc/mingw32/4.6.2/../../../../include/string.h" 3
 void* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) memchr (const void*, int, size_t) __attribute__ ((__pure__));
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) memcmp (const void*, const void*, size_t) __attribute__ ((__pure__));
 void* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) memcpy (void*, const void*, size_t);
 void* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) memmove (void*, const void*, size_t);
 void* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) memset (void*, int, size_t);
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strcat (char*, const char*);
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strchr (const char*, int) __attribute__ ((__pure__));
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strcmp (const char*, const char*) __attribute__ ((__pure__));
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strcoll (const char*, const char*);
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strcpy (char*, const char*);
 size_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strcspn (const char*, const char*) __attribute__ ((__pure__));
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strerror (int);

 size_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strlen (const char*) __attribute__ ((__pure__));
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strncat (char*, const char*, size_t);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strncmp (const char*, const char*, size_t) __attribute__ ((__pure__));
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strncpy (char*, const char*, size_t);
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strpbrk (const char*, const char*) __attribute__ ((__pure__));
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strrchr (const char*, int) __attribute__ ((__pure__));
 size_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strspn (const char*, const char*) __attribute__ ((__pure__));
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strstr (const char*, const char*) __attribute__ ((__pure__));
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strtok (char*, const char*);
 size_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strxfrm (char*, const char*, size_t);





 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _strerror (const char *);
 void* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _memccpy (void*, const void*, int, size_t);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _memicmp (const void*, const void*, size_t);
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _strdup (const char*) __attribute__ ((__malloc__));
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _strcmpi (const char*, const char*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _stricmp (const char*, const char*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _stricoll (const char*, const char*);
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _strlwr (char*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _strnicmp (const char*, const char*, size_t);
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _strnset (char*, int, size_t);
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _strrev (char*);
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _strset (char*, int);
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _strupr (char*);
 void __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _swab (const char*, char*, size_t);


 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _strncoll(const char*, const char*, size_t);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _strnicoll(const char*, const char*, size_t);
# 90 "i:\\mingw\\bin\\../lib/gcc/mingw32/4.6.2/../../../../include/string.h" 3
 void* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) memccpy (void*, const void*, int, size_t);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) memicmp (const void*, const void*, size_t);
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strdup (const char*) __attribute__ ((__malloc__));
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strcmpi (const char*, const char*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) stricmp (const char*, const char*);
int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strcasecmp (const char*, const char *);





 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) stricoll (const char*, const char*);
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strlwr (char*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strnicmp (const char*, const char*, size_t);
int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strncasecmp (const char *, const char *, size_t);





 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strnset (char*, int, size_t);
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strrev (char*);
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strset (char*, int);
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strupr (char*);

 void __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) swab (const char*, char*, size_t);
# 126 "i:\\mingw\\bin\\../lib/gcc/mingw32/4.6.2/../../../../include/string.h" 3
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcscat (wchar_t*, const wchar_t*);
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcschr (const wchar_t*, wchar_t);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcscmp (const wchar_t*, const wchar_t*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcscoll (const wchar_t*, const wchar_t*);
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcscpy (wchar_t*, const wchar_t*);
 size_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcscspn (const wchar_t*, const wchar_t*);

 size_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcslen (const wchar_t*);
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcsncat (wchar_t*, const wchar_t*, size_t);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcsncmp(const wchar_t*, const wchar_t*, size_t);
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcsncpy(wchar_t*, const wchar_t*, size_t);
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcspbrk(const wchar_t*, const wchar_t*);
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcsrchr(const wchar_t*, wchar_t);
 size_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcsspn(const wchar_t*, const wchar_t*);
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcsstr(const wchar_t*, const wchar_t*);
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcstok(wchar_t*, const wchar_t*);
 size_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcsxfrm(wchar_t*, const wchar_t*, size_t);
# 152 "i:\\mingw\\bin\\../lib/gcc/mingw32/4.6.2/../../../../include/string.h" 3
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wcsdup (const wchar_t*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wcsicmp (const wchar_t*, const wchar_t*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wcsicoll (const wchar_t*, const wchar_t*);
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wcslwr (wchar_t*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wcsnicmp (const wchar_t*, const wchar_t*, size_t);
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wcsnset (wchar_t*, wchar_t, size_t);
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wcsrev (wchar_t*);
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wcsset (wchar_t*, wchar_t);
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wcsupr (wchar_t*);


 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wcsncoll(const wchar_t*, const wchar_t*, size_t);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wcsnicoll(const wchar_t*, const wchar_t*, size_t);
# 173 "i:\\mingw\\bin\\../lib/gcc/mingw32/4.6.2/../../../../include/string.h" 3
int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcscmpi (const wchar_t * __ws1, const wchar_t * __ws2);





 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcsdup (const wchar_t*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcsicmp (const wchar_t*, const wchar_t*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcsicoll (const wchar_t*, const wchar_t*);
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcslwr (wchar_t*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcsnicmp (const wchar_t*, const wchar_t*, size_t);
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcsnset (wchar_t*, wchar_t, size_t);
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcsrev (wchar_t*);
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcsset (wchar_t*, wchar_t);
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcsupr (wchar_t*);
# 32 "../math/pprz_algebra.h" 2
# 39 "../math/pprz_algebra_int.h" 2
# 1 "../math/pprz_trig_int.h" 1
# 30 "../math/pprz_trig_int.h"
# 1 "../math/pprz_algebra_int.h" 1
# 31 "../math/pprz_trig_int.h" 2
# 40 "../math/pprz_trig_int.h"
  extern int16_t pprz_trig_int[];
# 40 "../math/pprz_algebra_int.h" 2
# 1 "i:\\mingw\\bin\\../lib/gcc/mingw32/4.6.2/../../../../include/stdlib.h" 1 3
# 21 "i:\\mingw\\bin\\../lib/gcc/mingw32/4.6.2/../../../../include/stdlib.h" 3
# 1 "i:\\mingw\\bin\\../lib/gcc/mingw32/4.6.2/include/stddef.h" 1 3 4
# 22 "i:\\mingw\\bin\\../lib/gcc/mingw32/4.6.2/../../../../include/stdlib.h" 2 3
# 71 "i:\\mingw\\bin\\../lib/gcc/mingw32/4.6.2/../../../../include/stdlib.h" 3
extern int _argc;
extern char** _argv;




extern int* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) __p___argc(void);
extern char*** __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) __p___argv(void);
extern wchar_t*** __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) __p___wargv(void);
# 112 "i:\\mingw\\bin\\../lib/gcc/mingw32/4.6.2/../../../../include/stdlib.h" 3
   extern __attribute__ ((__dllimport__)) int __mb_cur_max;
# 137 "i:\\mingw\\bin\\../lib/gcc/mingw32/4.6.2/../../../../include/stdlib.h" 3
 int* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _errno(void);


 int* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) __doserrno(void);
# 149 "i:\\mingw\\bin\\../lib/gcc/mingw32/4.6.2/../../../../include/stdlib.h" 3
  extern char *** __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) __p__environ(void);
  extern wchar_t *** __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) __p__wenviron(void);
# 172 "i:\\mingw\\bin\\../lib/gcc/mingw32/4.6.2/../../../../include/stdlib.h" 3
  extern __attribute__ ((__dllimport__)) int _sys_nerr;
# 196 "i:\\mingw\\bin\\../lib/gcc/mingw32/4.6.2/../../../../include/stdlib.h" 3
extern __attribute__ ((__dllimport__)) char* _sys_errlist[];
# 209 "i:\\mingw\\bin\\../lib/gcc/mingw32/4.6.2/../../../../include/stdlib.h" 3
extern unsigned __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) int* __p__osver(void);
extern unsigned __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) int* __p__winver(void);
extern unsigned __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) int* __p__winmajor(void);
extern unsigned __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) int* __p__winminor(void);







extern __attribute__ ((__dllimport__)) unsigned int _osver;
extern __attribute__ ((__dllimport__)) unsigned int _winver;
extern __attribute__ ((__dllimport__)) unsigned int _winmajor;
extern __attribute__ ((__dllimport__)) unsigned int _winminor;
# 260 "i:\\mingw\\bin\\../lib/gcc/mingw32/4.6.2/../../../../include/stdlib.h" 3
 char** __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) __p__pgmptr(void);

 wchar_t** __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) __p__wpgmptr(void);
# 293 "i:\\mingw\\bin\\../lib/gcc/mingw32/4.6.2/../../../../include/stdlib.h" 3
extern __attribute__ ((__dllimport__)) int _fmode;
# 303 "i:\\mingw\\bin\\../lib/gcc/mingw32/4.6.2/../../../../include/stdlib.h" 3
 double __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) atof (const char*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) atoi (const char*);
 long __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) atol (const char*);

 double __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wtof (const wchar_t *);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wtoi (const wchar_t *);
 long __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wtol (const wchar_t *);


double __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) __strtod (const char*, char**);
extern double __attribute__((__cdecl__)) __attribute__ ((__nothrow__))
strtod (const char* __restrict__ __nptr, char** __restrict__ __endptr);
float __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strtof (const char * __restrict__, char ** __restrict__);
long double __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strtold (const char * __restrict__, char ** __restrict__);




 long __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strtol (const char*, char**, int);
 unsigned long __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strtoul (const char*, char**, int);



 long __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcstol (const wchar_t*, wchar_t**, int);
 unsigned long __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcstoul (const wchar_t*, wchar_t**, int);
 double __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcstod (const wchar_t*, wchar_t**);

float __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcstof( const wchar_t * __restrict__, wchar_t ** __restrict__);
long double __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcstold (const wchar_t * __restrict__, wchar_t ** __restrict__);


 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wgetenv(const wchar_t*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wputenv(const wchar_t*);
 void __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wsearchenv(const wchar_t*, const wchar_t*, wchar_t*);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wsystem(const wchar_t*);
 void __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wmakepath(wchar_t*, const wchar_t*, const wchar_t*, const wchar_t*, const wchar_t*);
 void __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wsplitpath (const wchar_t*, wchar_t*, wchar_t*, wchar_t*, wchar_t*);
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wfullpath (wchar_t*, const wchar_t*, size_t);




 size_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wcstombs (char*, const wchar_t*, size_t);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wctomb (char*, wchar_t);

 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) mblen (const char*, size_t);
 size_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) mbstowcs (wchar_t*, const char*, size_t);
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) mbtowc (wchar_t*, const char*, size_t);

 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) rand (void);
 void __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) srand (unsigned int);

 void* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) calloc (size_t, size_t) __attribute__ ((__malloc__));
 void* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) malloc (size_t) __attribute__ ((__malloc__));
 void* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) realloc (void*, size_t);
 void __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) free (void*);
 void __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) abort (void) __attribute__ ((__noreturn__));
 void __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) exit (int) __attribute__ ((__noreturn__));


int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) atexit (void (*)(void));

 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) system (const char*);
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) getenv (const char*);


 void* __attribute__((__cdecl__)) bsearch (const void*, const void*, size_t, size_t,
          int (*)(const void*, const void*));
 void __attribute__((__cdecl__)) qsort(void*, size_t, size_t,
      int (*)(const void*, const void*));

 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) abs (int) __attribute__ ((__const__));
 long __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) labs (long) __attribute__ ((__const__));
# 385 "i:\\mingw\\bin\\../lib/gcc/mingw32/4.6.2/../../../../include/stdlib.h" 3
typedef struct { int quot, rem; } div_t;
typedef struct { long quot, rem; } ldiv_t;

 div_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) div (int, int) __attribute__ ((__const__));
 ldiv_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) ldiv (long, long) __attribute__ ((__const__));







 void __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _beep (unsigned int, unsigned int) __attribute__ ((__deprecated__));

 void __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _seterrormode (int) __attribute__ ((__deprecated__));
 void __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _sleep (unsigned long) __attribute__ ((__deprecated__));

 void __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _exit (int) __attribute__ ((__noreturn__));



typedef int (* _onexit_t)(void);
_onexit_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _onexit( _onexit_t );

 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _putenv (const char*);
 void __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _searchenv (const char*, const char*, char*);

 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _ecvt (double, int, int*, int*);
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _fcvt (double, int, int*, int*);
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _gcvt (double, int, char*);

 void __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _makepath (char*, const char*, const char*, const char*, const char*);
 void __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _splitpath (const char*, char*, char*, char*, char*);
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _fullpath (char*, const char*, size_t);

 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _itoa (int, char*, int);
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _ltoa (long, char*, int);
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _ultoa(unsigned long, char*, int);
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _itow (int, wchar_t*, int);
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _ltow (long, wchar_t*, int);
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _ultow (unsigned long, wchar_t*, int);


 long long __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _atoi64(const char *);
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _i64toa(long long, char *, int);
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _ui64toa(unsigned long long, char *, int);
 long long __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _wtoi64(const wchar_t *);
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _i64tow(long long, wchar_t *, int);
 wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _ui64tow(unsigned long long, wchar_t *, int);

 unsigned int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) (_rotl)(unsigned int, int) __attribute__ ((__const__));
 unsigned int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) (_rotr)(unsigned int, int) __attribute__ ((__const__));
 unsigned long __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) (_lrotl)(unsigned long, int) __attribute__ ((__const__));
 unsigned long __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) (_lrotr)(unsigned long, int) __attribute__ ((__const__));

 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _set_error_mode (int);
# 477 "i:\\mingw\\bin\\../lib/gcc/mingw32/4.6.2/../../../../include/stdlib.h" 3
 int __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) putenv (const char*);
 void __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) searchenv (const char*, const char*, char*);

 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) itoa (int, char*, int);
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) ltoa (long, char*, int);


 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) ecvt (double, int, int*, int*);
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) fcvt (double, int, int*, int*);
 char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) gcvt (double, int, char*);
# 497 "i:\\mingw\\bin\\../lib/gcc/mingw32/4.6.2/../../../../include/stdlib.h" 3
void __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) _Exit(int) __attribute__ ((__noreturn__));





typedef struct { long long quot, rem; } lldiv_t;

lldiv_t __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) lldiv (long long, long long) __attribute__ ((__const__));

long long __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) llabs(long long);





long long __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strtoll (const char* __restrict__, char** __restrict, int);
unsigned long long __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) strtoull (const char* __restrict__, char** __restrict__, int);


long long __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) atoll (const char *);


long long __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) wtoll (const wchar_t *);
char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) lltoa (long long, char *, int);
char* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) ulltoa (unsigned long long , char *, int);
wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) lltow (long long, wchar_t *, int);
wchar_t* __attribute__((__cdecl__)) __attribute__ ((__nothrow__)) ulltow (unsigned long long, wchar_t *, int);
# 41 "../math/pprz_algebra_int.h" 2

struct Uint16Vect3 {
  uint16_t x;
  uint16_t y;
  uint16_t z;
};

struct Int16Vect3 {
  int16_t x;
  int16_t y;
  int16_t z;
};
# 69 "../math/pprz_algebra_int.h"
struct Int32Vect2 {
  int32_t x;
  int32_t y;
};

struct Int32Vect3 {
  int32_t x;
  int32_t y;
  int32_t z;
};






struct Int32Quat {
  int32_t qi;
  int32_t qx;
  int32_t qy;
  int32_t qz;
};


struct Int64Quat {
  int32_t qi;
  int32_t qx;
  int32_t qy;
  int32_t qz;
};
# 123 "../math/pprz_algebra_int.h"
struct Int16Eulers {
  int16_t phi;
  int16_t theta;
  int16_t psi;
};




struct Int32Eulers {
  int32_t phi;
  int32_t theta;
  int32_t psi;
};
# 145 "../math/pprz_algebra_int.h"
struct Int32RMat {
  int32_t m[3*3];
};


struct Int32Mat33 {
  int32_t m[3*3];
};


struct Int16Rates {
  int16_t p;
  int16_t q;
  int16_t r;
};





struct Int32Rates {
  int32_t p;
  int32_t q;
  int32_t r;
};

struct Int64Rates {
  int64_t p;
  int64_t q;
  int64_t r;
};


struct Int64Vect2 {
  int64_t x;
  int64_t y;
};

struct Int64Vect3 {
  int64_t x;
  int64_t y;
  int64_t z;
};
# 35 "imu.h" 2
# 1 "../math/pprz_algebra_float.h" 1
# 47 "../math/pprz_algebra_float.h"
struct FloatVect2 {
  float x;
  float y;
};

struct FloatVect3 {
  float x;
  float y;
  float z;
};




struct FloatQuat {
  float qi;
  float qx;
  float qy;
  float qz;
};

struct FloatMat33 {
  float m[3*3];
};




struct FloatRMat {
  float m[3*3];
};




struct FloatEulers {
  float phi;
  float theta;
  float psi;
};




struct FloatRates {
  float p;
  float q;
  float r;
};
# 455 "../math/pprz_algebra_float.h"
static inline float renorm_factor(float n) {
  if (n < 1.5625f && n > 0.64f)
    return .5 * (3-n);
  else if (n < 100.0f && n > 0.01f)
    return 1. / sqrtf(n);
  else
    return 0.;
}

static inline float float_rmat_reorthogonalize(struct FloatRMat* rm) {

  const struct FloatVect3 r0 = {((*rm).m[(0)*3+(0)]),
                                ((*rm).m[(0)*3+(1)]),
                                ((*rm).m[(0)*3+(2)])};
  const struct FloatVect3 r1 = {((*rm).m[(1)*3+(0)]),
                                ((*rm).m[(1)*3+(1)]),
                                ((*rm).m[(1)*3+(2)])};
  float _err = -0.5*((r0).x*(r1).x + (r0).y*(r1).y + (r0).z*(r1).z);
  struct FloatVect3 r0_t;
  { (r0_t).x = (r0).x + (_err)*(r1).x; (r0_t).y = (r0).y + (_err)*(r1).y; (r0_t).z = (r0).z + (_err)*(r1).z; };
  struct FloatVect3 r1_t;
  { (r1_t).x = (r1).x + (_err)*(r0).x; (r1_t).y = (r1).y + (_err)*(r0).y; (r1_t).z = (r1).z + (_err)*(r0).z; };
  struct FloatVect3 r2_t;
  { (r2_t).x = (r0_t).y*(r1_t).z - (r0_t).z*(r1_t).y; (r2_t).y = (r0_t).z*(r1_t).x - (r0_t).x*(r1_t).z; (r2_t).z = (r0_t).x*(r1_t).y - (r0_t).y*(r1_t).x; };
  float s = renorm_factor(((r0_t).x*(r0_t).x + (r0_t).y*(r0_t).y + (r0_t).z*(r0_t).z));
  { (((*rm)).m[(0)*3+(0)]) = (r0_t).x * (s); (((*rm)).m[(0)*3+(1)]) = (r0_t).y * (s); (((*rm)).m[(0)*3+(2)]) = (r0_t).z * (s); };
  s = renorm_factor(((r1_t).x*(r1_t).x + (r1_t).y*(r1_t).y + (r1_t).z*(r1_t).z));
  { (((*rm)).m[(1)*3+(0)]) = (r1_t).x * (s); (((*rm)).m[(1)*3+(1)]) = (r1_t).y * (s); (((*rm)).m[(1)*3+(2)]) = (r1_t).z * (s); };
  s = renorm_factor(((r2_t).x*(r2_t).x + (r2_t).y*(r2_t).y + (r2_t).z*(r2_t).z));
  { (((*rm)).m[(2)*3+(0)]) = (r2_t).x * (s); (((*rm)).m[(2)*3+(1)]) = (r2_t).y * (s); (((*rm)).m[(2)*3+(2)]) = (r2_t).z * (s); };

  return _err;

}
# 36 "imu.h" 2
# 1 "conf_capteur.h" 1
# 37 "imu.h" 2
# 1 "navdata.h" 1
# 43 "navdata.h"
typedef struct {
 uint8_t isInitialized;
 uint8_t isOpen;
 uint16_t bytesRead;
 uint32_t totalBytesRead;
 uint32_t packetsRead;
 uint8_t buffer[80];
} navdata_port;

typedef struct
{
  uint16_t taille;
  uint16_t nu_trame;

  uint16_t ax;
  uint16_t ay;
  uint16_t az;

  int16_t vx;
  int16_t vy;
  int16_t vz;
  uint16_t temperature_acc;
  uint16_t temperature_gyro;

  uint16_t ultrasound;

  uint16_t us_debut_echo;
  uint16_t us_fin_echo;
  uint16_t us_association_echo;
  uint16_t us_distance_echo;

  uint16_t us_curve_time;
  uint16_t us_curve_value;
  uint16_t us_curve_ref;

  uint16_t nb_echo;

  uint32_t sum_echo;
  int16_t gradient;

  uint16_t flag_echo_ini;

  int32_t pressure;
  int16_t temperature_pressure;

  int16_t mx;
  int16_t my;
  int16_t mz;

  uint16_t chksum;

} __attribute__ ((packed)) measures_t;

extern measures_t* navdata;
extern navdata_port* port;
extern uint16_t navdata_cks;
extern uint8_t navdata_imu_available;
extern uint8_t navdata_baro_available;
extern int16_t previousUltrasoundHeight;

int navdata_init(void);
void navdata_close(void);

void navdata_read(void);
void navdata_update(void);
void navdata_CropBuffer(int cropsize);

uint16_t navdata_checksum(void);
int16_t navdata_getHeight(void);
# 38 "imu.h" 2


struct Imu {
  struct Int32Rates gyro;
  struct Int32Vect3 accel;
  struct Int32Vect3 mag;
  struct Int32Rates gyro_prev;
  struct Int32Vect3 accel_prev;
  struct Int32Rates gyro_neutral;
  struct Int32Vect3 accel_neutral;
  struct Int32Vect3 mag_neutral;
  struct Int32Rates gyro_unscaled;
  struct Int32Vect3 accel_unscaled;
  struct Int32Vect3 mag_unscaled;
  struct Int32Quat body_to_imu_quat;
  struct Int32RMat body_to_imu_rmat;
};


struct ImuFloat {
  struct FloatRates gyro;
  struct FloatVect3 accel;
  struct FloatVect3 mag;
  struct FloatRates gyro_prev;
  struct FloatEulers body_to_imu_eulers;
  struct FloatQuat body_to_imu_quat;
  struct FloatRMat body_to_imu_rmat;
  uint32_t sample_count;
};


extern struct Imu imu;
extern int imu_data_available;

extern void imu_init(void);
extern void imu_periodic(void);

static inline void imu_event ( void (* _gyro_handler)(void), void (* _accel_handler)(void), void (* _mag_handler)(void))
{
  if (imu_data_available) {
    imu_data_available = 0;
    _gyro_handler();
    _accel_handler();
    _mag_handler();
  }
}
