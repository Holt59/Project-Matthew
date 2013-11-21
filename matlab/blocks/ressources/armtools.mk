# Copyright 1994-2012 The MathWorks, Inc.
#
# File    : unixtools.mk   $Revision: 1.21.4.28 $
# Abstract:
#	Setup Unix tools for GNU make

ARCH := $(shell echo "$(COMPUTER)" | tr '[A-Z]' '[a-z]')
OS:=$(shell uname)

#
# Modify the following macros to reflect the tools you wish to use for
# compiling and linking your code.
#


DEFAULT_OPT_OPTS = -O0
ANSI_OPTS        =
CPP_ANSI_OPTS    = 
CPP              = arm-none-linux-gnueabi-c++
LD               = $(CC)
SYSLIBS          = 
LDFLAGS          = -L"/Volumes/HDData/Documents/INSA/5A/Drone/repo/paparazzi/lib/"
SHRLIBLDFLAGS    = 

# Override based on platform if needed

GCC_WALL_FLAG     := 
GCC_WALL_FLAG_MAX :=
CC  = arm-none-linux-gnueabi-gcc
CPP = arm-none-linux-gnueabi-g++
DEFAULT_OPT_OPTS = -O0
SHRLIBLDFLAGS = -shared -Wl,--no-undefined -Wl,--version-script,
# Allow ISO-C functions like fmin to be called

ANSI_OPTS     = -fPIC -W -Wall -Wextra -march=armv7-a 
CPP_ANSI_OPTS = -fPIC

# These definitions are used by targets that have the WARN_ON_GLNX option
GCC_WARN_OPTS     := -Wall -W -Wwrite-strings -Winline -Wstrict-prototypes \
	     -Wnested-externs -Wpointer-arith -Wcast-align

GCC_WARN_OPTS_MAX := $(GCC_WARN_OPTS) -Wcast-qual -Wshadow

ifeq ($(WARN_ON_GLNX), 1)
  GCC_WALL_FLAG     := $(GCC_WARN_OPTS)
  GCC_WALL_FLAG_MAX := $(GCC_WARN_OPTS_MAX)
endif

# To create a Quantify (from Rational) build,
# specify
#     QUANTIFY=1
# or
#     QUANTIFY=/path/to/quantify
#
# Note, may also need QUANTIFY_FLAGS=-cachedir=./q_cache
#
ifdef QUANTIFY
  ifeq ($(QUANTIFY),1)
    QUANTIFY_ROOT = /hub/$(ARCH)/apps/quantify
  else
    QUANTIFY_ROOT = $(QUANTIFY)
  endif

  INSTRUMENT_INCLUDES := -I$(QUANTIFY_ROOT)
  INSTRUMENT_LIBS     := $(QUANTIFY_ROOT)/quantify_stubs.a
  LD                  := quantify $(QUANTIFY_FLAGS) $(LD)
  OPT_OPTS            := -g
endif

# To create a Purify (from Rational) build, specify
#   PURIFY=1
#
ifeq ($(PURIFY),1)
  PURIFY_ROOT = /hub/$(ARCH)/apps/purify

  INSTRUMENT_INCLUDES := -I$(PURIFY_ROOT)

  INSTRUMENT_LIBS     := $(PURIFY_ROOT)/purify_stubs.a

  CC       := purify $(CC)
  OPT_OPTS := -g
endif

# [eof] unixtools.mk
