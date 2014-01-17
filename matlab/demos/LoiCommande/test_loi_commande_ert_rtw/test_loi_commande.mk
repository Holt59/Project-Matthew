# Copyright 1994-2012 The MathWorks, Inc.
#
# File    : ert_unix.tmf   
#
# Abstract:
#       Template makefile for building a UNIX-based stand-alone embedded 
#       real-time version of Simulink model using generated C code.
#
#       This makefile attempts to conform to the guidelines specified in the
#       IEEE Std 1003.2-1992 (POSIX) standard. It is designed to be used
#       with GNU Make which is located in matlabroot/rtw/bin.
#
#       Note that this template is automatically customized by the build 
#       procedure to create "<model>.mk"
#
#       The following defines can be used to modify the behavior of the
#       build:
#         OPT_OPTS       - Optimization options. Default is -O.
#         CPP_OPTS       - C++ compiler options.	
#         OPTS           - User specific compile options.
#         USER_SRCS      - Additional user sources, such as files needed by
#                          S-functions.
#         USER_INCLUDES  - Additional include paths
#                          (i.e. USER_INCLUDES="-Iwhere-ever -Iwhere-ever2")
#
#       To enable debugging:
#         set DEBUG_BUILD = 1 below, which will trigger OPTS=-g and
#          LDFLAGS += -g (may vary with compiler version, see compiler doc) 
#
#       This template makefile is designed to be used with a system target
#       file that contains 'rtwgensettings.BuildDirSuffix' see ert.tlc


#------------------------ Macros read by make_rtw ------------------------------
#
# The following macros are read by the build procedure:
#
#  MAKECMD         - This is the command used to invoke the make utility
#  HOST            - What platform this template makefile is targeted for
#                    (i.e. PC or UNIX)
#  BUILD           - Invoke make from the build procedure (yes/no)?
#  SYS_TARGET_FILE - Name of system target file.

MAKECMD         = make
HOST            = ANY
BUILD           = yes
SYS_TARGET_FILE = ardrone.tlc
COMPILER_TOOL_CHAIN = default

#---------------------- Tokens expanded by make_rtw ----------------------------
#
# The following tokens, when wrapped with "|>" and "<|" are expanded by the
# build procedure.
#
#  MODEL_NAME          - Name of the Simulink block diagram
#  MODEL_MODULES       - Any additional generated source modules
#  MAKEFILE_NAME       - Name of makefile created from template makefile <model>.mk
#  MATLAB_ROOT         - Path to where MATLAB is installed.
#  S_FUNCTIONS         - List of additional S-function modules.
#  S_FUNCTIONS_LIB     - List of S-functions libraries to link. 
#  NUMST               - Number of sample times
#  NCSTATES            - Number of continuous states
#  COMPUTER            - Computer type. See the MATLAB computer command.
#  BUILDARGS           - Options passed in at the command line.
#  MULTITASKING        - yes (1) or no (0): Is solver mode multitasking
#  INTEGER_CODE        - yes (1) or no (0): Is generated code purely integer
#  MAT_FILE            - yes (1) or no (0): Should mat file logging be done,
#                        if 0, the generated code runs indefinitely
#  EXT_MODE            - yes (1) or no (0): Build for external mode
#  TMW_EXTMODE_TESTING - yes (1) or no (0): Build ext_test.c for external mode
#                        testing.
#  EXTMODE_TRANSPORT   - Index of transport mechanism (e.g. tcpip, serial) for extmode
#  MULTI_INSTANCE_CODE - Is the generated code multi instantiable (1/0)?
#  GEN_MDLREF_SFCN     - (1/0): are we generating model reference wrapper s-function
#  MODELREFS           - List of referenced models
#  EXTMODE_STATIC      - yes (1) or no (0): Use static instead of dynamic mem alloc.
#  EXTMODE_STATIC_SIZE - Size of static memory allocation buffer.
#  TGT_FCN_LIB         - Target Funtion library to use
#  PORTABLE_WORDSIZES  - Is this build intented for SIL simulation with portable word sizes (1/0)?
#  SHRLIBTARGET        - Is this build intended for generation of a shared library instead 
#                        of executable (1/0)?
#  MAKEFILEBUILDER_TGT - Is this build performed by the MakefileBuilder class
#                        e.g. to create a PIL executable?
#  STANDALONE_SUPPRESS_EXE - Build the standalone target but only create object code modules 
#                            and do not build an executable

MODEL                   = test_loi_commande
MODULES                 = accelero.cpp motor.cpp test_loi_commande_data.cpp 
MAKEFILE                = test_loi_commande.mk
MATLAB_ROOT             = /Applications/MATLAB_R2013a.app
ALT_MATLAB_ROOT         = /Applications/MATLAB_R2013a.app
MASTER_ANCHOR_DIR       = 
START_DIR               = /Volumes/HDData/Documents/INSA/5A/Drone/repo/matlab/demos/LoiCommande
S_FUNCTIONS             = 
S_FUNCTIONS_LIB         = 
NUMST                   = 1
NCSTATES                = 0
COMPUTER                = MACI64
BUILDARGS               =  GENERATE_ERT_S_FUNCTION=0 GENERATE_ASAP2=0
MULTITASKING            = 0
INTEGER_CODE            = 0
MAT_FILE                = 0
ONESTEPFCN              = 1
TERMFCN                 = 1
MEXEXT                  = mexmaci64
EXT_MODE                = 0
TMW_EXTMODE_TESTING     = 0
EXTMODE_TRANSPORT       = 0
EXTMODE_STATIC          = 0
EXTMODE_STATIC_SIZE     = 1000000
MULTI_INSTANCE_CODE     = 0
CLASSIC_INTERFACE       = 0
TGT_FCN_LIB             = C89/C90 (ANSI)
MODELREFS               = 
SHARED_SRC              = 
SHARED_SRC_DIR          = 
SHARED_BIN_DIR          = 
SHARED_LIB              = 
GEN_SAMPLE_MAIN         = 1
TARGET_LANG_EXT         = cpp
PORTABLE_WORDSIZES      = 0
SHRLIBTARGET            = 0
MAKEFILEBUILDER_TGT     = 0
STANDALONE_SUPPRESS_EXE = 0
OPTIMIZATION_FLAGS      = 
ADDITIONAL_LDFLAGS      = 

# To enable debugging:
# set DEBUG_BUILD = 1
DEBUG_BUILD             = 0

#--------------------------- Model and reference models -----------------------
MODELLIB                  = test_loi_commandelib.a
MODELREF_LINK_LIBS        = 
MODELREF_INC_PATH         = 
RELATIVE_PATH_TO_ANCHOR   = ..
# NONE: standalone, SIM: modelref sim, RTW: modelref coder target
MODELREF_TARGET_TYPE       = NONE

#-- In the case when directory name contains space ---
ifneq ($(MATLAB_ROOT),$(ALT_MATLAB_ROOT))
MATLAB_ROOT := $(ALT_MATLAB_ROOT)
endif

#----------------------------- External mode -----------------------------------
# Uncomment -DVERBOSE to have information printed to stdout
# To add a new transport layer, see the comments in
#   <matlabroot>/toolbox/simulink/simulink/extmode_transports.m
ifeq ($(EXT_MODE),1)
  EXT_CC_OPTS = -DEXT_MODE -D$(COMPUTER) #-DVERBOSE
  EXT_LIB     =
  EXT_SRC     = ext_svr.c updown.c ext_work.c
  LINT_EXT_COMMON_SRC =
  LINT_EXT_TCPIP_SRC  =
  ifeq ($(EXTMODE_TRANSPORT),0) #tcpip
    EXT_SRC +=  rtiostream_interface.c rtiostream_tcpip.c
    LINT_EXT_COMMON_SRC = ext_svr.c updown.c ext_work.c
    LINT_EXT_TCPIP_SRC  = rtiostream_interface.c rtiostream_tcpip.c
  endif
  ifeq ($(EXTMODE_TRANSPORT),1) #serial
    EXT_SRC += ext_svr_serial_transport.c ext_serial_pkt.c
    EXT_SRC += rtiostream_serial_interface.c rtiostream_serial.c
  endif
  ifeq ($(TMW_EXTMODE_TESTING),1)
    EXT_SRC     += ext_test.c
    EXT_CC_OPTS += -DTMW_EXTMODE_TESTING
  endif
  ifeq ($(EXTMODE_STATIC),1)
    EXT_SRC             += mem_mgr.c
    LINT_EXT_COMMON_SRC += mem_mgr.c
    EXT_CC_OPTS         += -DEXTMODE_STATIC -DEXTMODE_STATIC_SIZE=$(EXTMODE_STATIC_SIZE)
  endif
  ifeq ($(COMPUTER),SOL64)
    EXT_LIB = -lsocket -lnsl
  endif
endif

#--------------------------- Tool Specifications -------------------------------

DEFAULT_OPT_OPTS = -O0
ANSI_OPTS        =
CPP_ANSI_OPTS    = 
LD               = $(CC)
LDFLAGS          = -static -L"/usr/local/paparazzi/lib"
USER_INCLUDES     = -I"/usr/local/paparazzi/include"

GCC_WALL_FLAG     := 
GCC_WALL_FLAG_MAX :=

DEFAULT_OPT_OPTS = -O0
SHRLIBLDFLAGS    = -shared -Wl,--no-undefined -Wl,--version-script,

EXE_FILE_EXT     = .elf

# Override based on platform if needed

GCC_WALL_FLAG     := 
GCC_WALL_FLAG_MAX :=
CC  = /usr/local/carlson-minot/crosscompilers/bin/arm-none-linux-gnueabi-gcc
CPP = /usr/local/carlson-minot/crosscompilers/bin/arm-none-linux-gnueabi-g++
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

#------------------------------ Include Path -----------------------------------

MATLAB_INCLUDES = \
	-I$(MATLAB_ROOT)/extern/include \
	-I$(MATLAB_ROOT)/simulink/include \
	-I$(MATLAB_ROOT)/rtw/c/src \
	-I$(MATLAB_ROOT)/rtw/c/src/ext_mode/common

# Additional includes 
ADD_INCLUDES = \
	-I$(START_DIR)/test_loi_commande_ert_rtw \
	-I$(START_DIR) \
	-I/Volumes/HDData/Documents/INSA/5A/Drone/repo/matlab/targets/ardrone/blocks/accelero/. \
	-I/Volumes/HDData/Documents/INSA/5A/Drone/repo/matlab/targets/ardrone/blocks/accelero \
	-I/Volumes/HDData/Documents/INSA/5A/Drone/repo/matlab/targets/ardrone/blocks/motor/. \
	-I/Volumes/HDData/Documents/INSA/5A/Drone/repo/matlab/targets/ardrone/blocks/motor \


SHARED_INCLUDES =
ifneq ($(SHARED_SRC_DIR),)
SHARED_INCLUDES = -I$(SHARED_SRC_DIR) 
endif

INCLUDES = -I. -I$(RELATIVE_PATH_TO_ANCHOR) $(MATLAB_INCLUDES) $(ADD_INCLUDES) $(USER_INCLUDES) \
	$(INSTRUMENT_INCLUDES) $(MODELREF_INC_PATH) $(SHARED_INCLUDES)


#-------------------------------- C Flags --------------------------------------

# Optimization Options
ifndef OPT_OPTS
OPT_OPTS = $(DEFAULT_OPT_OPTS)
endif

# General User Options
ifeq ($(DEBUG_BUILD),0)
DBG_FLAG =
else
#   Set OPTS=-g and any additional flags for debugging
DBG_FLAG = -g
LDFLAGS += -g
endif



# Compiler options, etc: 
CPP_REQ_DEFINES1 = -DMODEL=$(MODEL) -DNUMST=$(NUMST) -DNCSTATES=$(NCSTATES) \
		  -DUNIX -DMAT_FILE=$(MAT_FILE) -DINTEGER_CODE=$(INTEGER_CODE) \
		  -DONESTEPFCN=$(ONESTEPFCN) -DTERMFCN=$(TERMFCN) \
		  -DHAVESTDIO -DMULTI_INSTANCE_CODE=$(MULTI_INSTANCE_CODE) \
		  -DCLASSIC_INTERFACE=$(CLASSIC_INTERFACE)

CPP_REQ_DEFINES = $(CPP_REQ_DEFINES1)
ifeq ($(MODELREF_TARGET_TYPE),SIM)
CPP_REQ_DEFINES += -DMDL_REF_SIM_TGT=1
else
CPP_REQ_DEFINES += -DMT=$(MULTITASKING)
endif

ifeq ($(PORTABLE_WORDSIZES),1)
CPP_REQ_DEFINES += -DPORTABLE_WORDSIZES
endif


ifneq ($(OPTIMIZATION_FLAGS),)
CC_OPTS = $(OPTS) $(EXT_CC_OPTS) $(OPTIMIZATION_FLAGS)
else
CC_OPTS = $(OPT_OPTS) $(OPTS) $(EXT_CC_OPTS)
endif

CFLAGS = $(ANSI_OPTS) $(DBG_FLAG) $(CC_OPTS) $(CPP_REQ_DEFINES) $(INCLUDES)
CPPFLAGS = $(CPP_ANSI_OPTS) $(DBG_FLAG) $(CPP_OPTS) $(CC_OPTS) $(CPP_REQ_DEFINES) $(INCLUDES)

#-------------------------- Additional Libraries ------------------------------

SYSLIBS += $(EXT_LIB) -lpaparazzi -lm

LIBS =
 
LIBS += $(S_FUNCTIONS_LIB) $(INSTRUMENT_LIBS)

LIBFIXPT = 

ifeq ($(MODELREF_TARGET_TYPE),SIM)
LIBMWMATHUTIL = -L$(MATLAB_ROOT)/bin/$(ARCH) -lmwmathutil
else
LIBMWMATHUTIL = 
endif

ifeq ($(MODELREF_TARGET_TYPE),SIM)
LIBMWIPP = -L$(MATLAB_ROOT)/bin/$(ARCH) -lippmwipt
else
LIBMWIPP = 
endif

ifeq ($(MODELREF_TARGET_TYPE),SIM)
LIBMWSL_FILEIO = -L$(MATLAB_ROOT)/bin/$(ARCH) -lmwsl_fileio
else
LIBMWSL_FILEIO = 
endif

#----------------------------- Source Files ------------------------------------
ADD_SRCS =

ifneq ($(ADDITIONAL_LDFLAGS),)
MEX_LDFLAGS = CLIBS='$$CLIBS $(ADDITIONAL_LDFLAGS)' 
else
MEX_LDFLAGS =
endif

SRCS  = $(ADD_SRCS) $(S_FUNCTIONS)
SRC_DEP =
ifeq ($(MODELREF_TARGET_TYPE), NONE)
ifeq ($(SHRLIBTARGET), 1)
  # Shared object/dynamic library
  PRODUCT            = $(MODEL).so
  BIN_SETTING        = $(LD) $(SHRLIBLDFLAGS)$(MODEL).def -o $(PRODUCT)
  BUILD_PRODUCT_TYPE = "shared object"
  SRCS               += $(MODULES) $(MODEL).$(TARGET_LANG_EXT) $(EXT_SRC)
else
  ifeq ($(MAKEFILEBUILDER_TGT), 1)
    # Standalone executable (e.g. for PIL)
    PREBUILT_SRCS      = $(MODULES)
    PREBUILT_OBJS      = $(addsuffix .o, $(basename $(PREBUILT_SRCS)))
    PRODUCT            = $(MODEL)$(EXE_FILE_EXT)
    BIN_SETTING        = $(LD) $(LDFLAGS) $(ADDITIONAL_LDFLAGS) -o $(PRODUCT)
    BUILD_PRODUCT_TYPE = "executable"
  else
    SRCS               += $(MODULES) $(MODEL).$(TARGET_LANG_EXT) $(EXT_SRC)
    ifeq ($(STANDALONE_SUPPRESS_EXE), 1)
      # Build object code only for top level model
      PRODUCT            = "ObjectModulesOnly"
      BUILD_PRODUCT_TYPE = "object modules"
    else
      # ERT standalone
      PRODUCT            = $(RELATIVE_PATH_TO_ANCHOR)/$(MODEL)$(EXE_FILE_EXT)
      BIN_SETTING        = $(LD) $(LDFLAGS) $(ADDITIONAL_LDFLAGS) -o $(PRODUCT)
      BUILD_PRODUCT_TYPE = "executable"
      ifeq ($(GEN_SAMPLE_MAIN),0)
         ifeq ($(MULTI_INSTANCE_CODE), 1)
            SRCS += rt_malloc_main.c
         else
            SRCS += rt_main.c
         endif
      else
        SRCS += ert_main.$(TARGET_LANG_EXT)
      endif
    endif
  endif
endif
else
# Model reference coder target
SRCS               += $(MODULES)
PRODUCT            = $(MODELLIB)
BUILD_PRODUCT_TYPE = "library"
endif


USER_SRCS =

USER_OBJS       = $(addsuffix .o, $(basename $(USER_SRCS)))
LOCAL_USER_OBJS = $(notdir $(USER_OBJS))

OBJS      = $(addsuffix .o, $(basename $(SRCS))) $(USER_OBJS)
LINK_OBJS = $(addsuffix .o, $(basename $(SRCS))) $(LOCAL_USER_OBJS)

SHARED_SRC := $(wildcard $(SHARED_SRC))
SHARED_OBJS_NO_PATH = $(addsuffix .o, $(basename $(notdir $(SHARED_SRC))))
SHARED_OBJS = $(addprefix $(join $(SHARED_BIN_DIR), /), $(SHARED_OBJS_NO_PATH))

ifneq ($(findstring .cpp,$(suffix $(SRCS), $(USER_SRCS), $(PREBUILT_SRCS))),)
  LD = $(CPP)
endif
#----------------------------- Lint (sol2 only) --------------------------------

LINT_SRCS = $(MATLAB_ROOT)/rtw/c/src/common/rt_main.c
LINT_SRCS += $(MODEL).$(TARGET_LANG_EXT) $(MODULES) $(USER_SRCS) $(S_FUNCTIONS)
LINTOPTSFILE = $(MODEL).lintopts

ifneq ($(LINT_EXT_COMMON_SRC), )
  LINT_SRCS += $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/$(LINT_EXT_COMMON_SRC)
endif
ifneq ($(LINT_EXT_TCPIP_SRC), )
  LINT_SRCS += $(MATLAB_ROOT)/rtw/c/src/rtiostream/rtiostreamtcpip/$(LINT_EXT_TCPIP_SRC)
endif

LINT_ERROFF1 = E_NAME_DEF_NOT_USED2,E_NAME_DECL_NOT_USED_DEF2
LINT_ERROFF2 = $(LINT_ERROFF1),E_FUNC_ARG_UNUSED
LINT_ERROFF  = $(LINT_ERROFF2),E_INDISTING_FROM_TRUNC2,E_NAME_USED_NOT_DEF2

#--------------------------------- Rules ---------------------------------------
ifeq ($(MODELREF_TARGET_TYPE),NONE)
  ifeq ($(SHRLIBTARGET), 1)
    ifeq ($(GEN_SAMPLE_MAIN), 1)
$(MODEL) : $(PRODUCT) ert_main.o
	$(LD) $(LDFLAGS) $(ADDITIONAL_LDFLAGS) -o $(MODEL) ert_main.o $(PRODUCT) $(SYSLIBS)
	@mv $(PRODUCT) $(RELATIVE_PATH_TO_ANCHOR)/
	@echo "### Created $(BUILD_PRODUCT_TYPE): $(PRODUCT)"
	@mv $(MODEL) $(RELATIVE_PATH_TO_ANCHOR)/
	@echo "### Created executable: $@"
    else
mvshrlib: $(PRODUCT)
	@mv $(PRODUCT) $(RELATIVE_PATH_TO_ANCHOR)/
    endif
  endif
  ifeq ($(MAKEFILEBUILDER_TGT), 1)
$(PRODUCT) : $(PREBUILT_OBJS) $(OBJS) $(SHARED_LIB) $(LIBS) $(SRC_DEP) $(MODELLIB) $(MODELREF_LINK_LIBS)
	$(BIN_SETTING) $(LINK_OBJS) $(PREBUILT_OBJS) $(MODELLIB) $(MODELREF_LINK_LIBS) $(SHARED_LIB) $(LIBFIXPT) $(LIBS)  $(SYSLIBS)
	@echo "### Created $(BUILD_PRODUCT_TYPE): $@"
  else
    ifeq ($(STANDALONE_SUPPRESS_EXE), 1)
.PHONY: $(PRODUCT)
$(PRODUCT) : $(OBJS) $(SHARED_LIB) $(LIBS) $(SRC_DEP) $(MODELREF_LINK_LIBS)
	@echo "### Created $(BUILD_PRODUCT_TYPE): $@"
    else
$(PRODUCT) : $(OBJS) $(SHARED_LIB) $(LIBS) $(SRC_DEP) $(MODELREF_LINK_LIBS)
	$(BIN_SETTING) $(LINK_OBJS) $(MODELREF_LINK_LIBS) $(SHARED_LIB) $(LIBFIXPT) $(LIBS)  $(SYSLIBS)
	@echo "### Created $(BUILD_PRODUCT_TYPE): $@"
    endif
  endif
else
 ifeq ($(MODELREF_TARGET_TYPE),SIM)
  $(PRODUCT) : $(OBJS) $(SHARED_LIB) $(LIBS) $(SRC_DEP)
	@rm -f $(MODELLIB)
	ar ruvs $(MODELLIB) $(LINK_OBJS)
	@echo "### Created $(MODELLIB)"
	$(BIN_SETTING) $(MODELLIB) $(MODELREF_LINK_LIBS) $(SHARED_LIB) $(LIBFIXPT) $(LIBS) $(LIBMWMATHUTIL) $(LIBMWIPP) $(LIBMWSL_FILEIO)
	@echo "### Created $(BUILD_PRODUCT_TYPE): $@"	
 else
  $(PRODUCT) : $(OBJS) $(SHARED_LIB) $(SRC_DEP)
	@rm -f $(MODELLIB)
	ar ruvs $(MODELLIB) $(LINK_OBJS)
	@echo "### Created $(MODELLIB)"
	@echo "### Created $(BUILD_PRODUCT_TYPE): $@"	
 endif
endif


#--------------- Support for building referenced models -----------------------


#-------------------------- Support for building modules ----------------------

ifneq ($(SHARED_SRC_DIR),)
$(SHARED_BIN_DIR)/%.o : $(SHARED_SRC_DIR)/%.c
	$(CC) -c -o $@ $(CFLAGS) $(GCC_WALL_FLAG_MAX) "$<"

$(SHARED_BIN_DIR)/%.o : $(SHARED_SRC_DIR)/%.cpp
	$(CPP) -c -o $@ $(CPPFLAGS) $(GCC_WALL_FLAG_MAX) "$<"
endif

%.o : %.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG) "$<"

%.o : %.cpp
	$(CPP) -c $(CPPFLAGS) $(GCC_WALL_FLAG) "$<"

%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG) "$<"

%.o : $(RELATIVE_PATH_TO_ANCHOR)/%.cpp
	$(CPP) -c $(CPPFLAGS) $(GCC_WALL_FLAG) "$<"

ifeq ($(GEN_SAMPLE_MAIN),0)
ifeq ($(TARGET_LANG_EXT),cpp)
%.o : $(MATLAB_ROOT)/rtw/c/src/common/%.c
	$(CPP) -c $(CPPFLAGS) $(GCC_WALL_FLAG_MAX) "$<"
else
%.o : $(MATLAB_ROOT)/rtw/c/src/common/%.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) "$<"
endif
endif

%.o : $(MATLAB_ROOT)/rtw/c/src/%.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) "$<"

%.o : $(MATLAB_ROOT)/rtw/c/src/ext_mode/common/%.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) "$<"

%.o : $(MATLAB_ROOT)/rtw/c/src/rtiostream/rtiostreamtcpip/%.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) "$<"

%.o : $(MATLAB_ROOT)/rtw/c/src/ext_mode/custom/%.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) "$<"

%.o : $(MATLAB_ROOT)/rtw/c/src/%.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) "$<"

%.o : $(MATLAB_ROOT)/simulink/src/%.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) "$<"

%.o : /Volumes/HDData/Documents/INSA/5A/Drone/repo/matlab/targets/ardrone/blocks/accelero/%.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) "$<"

%.o : /Volumes/HDData/Documents/INSA/5A/Drone/repo/matlab/targets/ardrone/blocks/motor/%.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) "$<"



%.o : $(MATLAB_ROOT)/rtw/c/src/%.cpp
	$(CPP) -c $(CPPFLAGS) $(GCC_WALL_FLAG_MAX) "$<"

%.o : $(MATLAB_ROOT)/simulink/src/%.cpp
	$(CPP) -c $(CPPFLAGS) $(GCC_WALL_FLAG_MAX) "$<"

%.o : /Volumes/HDData/Documents/INSA/5A/Drone/repo/matlab/targets/ardrone/blocks/accelero/%.cpp
	$(CPP) -c $(CPPFLAGS) $(GCC_WALL_FLAG_MAX) "$<"

%.o : /Volumes/HDData/Documents/INSA/5A/Drone/repo/matlab/targets/ardrone/blocks/motor/%.cpp
	$(CPP) -c $(CPPFLAGS) $(GCC_WALL_FLAG_MAX) "$<"



%.o : $(MATLAB_ROOT)/simulink/src/%.cpp
	$(CPP) -c $(CPPFLAGS) $(GCC_WALL_FLAG_MAX) "$<"

%.o : $(MATLAB_ROOT)/simulink/src/%.c
	$(CC) -c $(CFLAGS) $(GCC_WALL_FLAG_MAX) "$<"

#------------------------------- Libraries -------------------------------------





#----------------------------- Dependencies ------------------------------------

$(OBJS) : $(MAKEFILE) rtw_proj.tmw

$(SHARED_LIB) : $(SHARED_OBJS)
	@echo "### Creating $@ "
	ar ruvs $@ $(SHARED_OBJS)
	@echo "### $@ Created "


#--------- Miscellaneous rules to purge, clean and lint (sol2 only) ------------

purge : clean
	@echo "### Deleting the generated source code for $(MODEL)"
	@\rm -f $(MODEL).c $(MODEL).h $(MODEL)_types.h $(MODEL)_data.c \
	        $(MODEL)_private.h $(MODEL).rtw $(MODULES) rtw_proj.tmw $(MAKEFILE)

clean :
	@echo "### Deleting the objects, $(PRODUCT)"
	@\rm -f $(LINK_OBJS) $(PRODUCT) 

lint  : rtwlib.ln
	@lint -errchk -errhdr=%user -errtags=yes -F -L. -lrtwlib -x -Xc \
	      -erroff=$(LINT_ERROFF) \
	      -D_POSIX_C_SOURCE $(CFLAGS) $(LINT_SRCS)
	@\rm -f $(LINTOPTSFILE)
	@echo
	@echo "### Created lint output only, no executable"
	@echo

rtwlib.ln : $(MAKEFILE) rtw_proj.tmw
	@echo
	@echo "### Linting ..."
	@echo
	@\rm -f llib-lrtwlib.ln $(LINTOPTSFILE)
	@echo "-dirout=. -errchk -errhdr=%user " >> $(LINTOPTSFILE)
	@echo "-errtags -F -ortwlib -x -Xc " >> $(LINTOPTSFILE)
	@echo "-erroff=$(LINT_ERROFF) " >> $(LINTOPTSFILE)
	@echo "-D_POSIX_C_SOURCE $(CFLAGS) " >> $(LINTOPTSFILE)
	@for file in $(MATLAB_ROOT)/rtw/c/libsrc/*.c; do \
	  echo "$$file " >> $(LINTOPTSFILE); \
	done
	lint -flagsrc=$(LINTOPTSFILE)


# EOF: ert_unix.tmf
