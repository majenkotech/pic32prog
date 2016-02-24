#                                               -*- Autoconf -*-
# Process this file with autoconf to produce a configure script.

AC_PREREQ([2.68])
AC_INIT([pic32prog], [2.0], [serge@vak.ru])
AC_CONFIG_SRCDIR([pickit2.h])
AC_CONFIG_HEADERS([config.h])
AC_CONFIG_FILES([Makefile hidapi/Makefile])
AM_INIT_AUTOMAKE([1.9 foreign])

need_usb0=0
need_usb1=0
need_uart=0
ADAPTER_OBJECTS=""
HIDAPI_OBJECTS=""

# Checks for programs.
AC_PROG_CXX
AC_PROG_CC
AC_PROG_RANLIB

AC_C_CROSS

AC_CANONICAL_HOST

AC_DEFUN([AC_GIT_REPO],[
    AC_MSG_CHECKING([git revision])
    git_revision=`git rev-list HEAD --count`
    if test ! -z "$git_revision"; then
        git_compiling=1
        AC_DEFINE_UNQUOTED([GITREV],$git_revision, [Git repository revision number])
        AC_MSG_RESULT($git_revision)
    else
        git_compiling=0
        AC_DEFINE([GITREV],[0])
        AC_MSG_RESULT([not compiling git repostory], [Git repository revision number])
    fi
])
AC_GIT_REPO

# Checks for libraries.

# Checks for header files.
AC_CHECK_HEADERS([fcntl.h libintl.h locale.h malloc.h stdlib.h string.h sys/ioctl.h sys/time.h termios.h unistd.h wchar.h])

# Checks for typedefs, structures, and compiler characteristics.
AC_C_INLINE
AC_TYPE_INT32_T
AC_TYPE_SIZE_T
AC_TYPE_SSIZE_T
AC_CHECK_MEMBERS([struct stat.st_rdev])
AC_TYPE_UINT16_T
AC_TYPE_UINT32_T
AC_TYPE_UINT8_T

# Checks for library functions.
AC_FUNC_ALLOCA
AC_FUNC_MALLOC
AC_FUNC_REALLOC
AC_CHECK_FUNCS([atexit clock_gettime gettimeofday memmove memset select setlocale strcasecmp strchr strdup strerror strncasecmp strrchr strtol strtoul uname])

AC_ARG_ENABLE([an1388], [AS_HELP_STRING([--enable-an1388],[AN1388 HID Bootloader])], [
    AC_DEFINE([USE_AN1388], [1], [Enable the AN1388 HID Adapter]) 
    adapters="${adapters}AN1388 "
    have_adapter=1
    need_usb1=1
    ADAPTER_OBJECTS+='adapter-an1388.$(OBJEXT) '
], [])

AC_ARG_ENABLE([an1388_uart], [AS_HELP_STRING([--enable-an1388-uart],[AN1388 UART Bootloader])], [
    AC_DEFINE([USE_AN1388_UART], [1], [Enable the AN1388 UART Adapter]) 
    adapters="${adapters}AN1388-UART "
    ADAPTER_OBJECTS+='adapter-an1388-uart.$(OBJEXT) '
    have_adapter=1
    need_uart=1
], [])

AC_ARG_ENABLE([bitbang], [AS_HELP_STRING([--enable-bitbang],[Bitbang (UART ASCII) Adapter])], [
    AC_DEFINE([USE_BITBANG_UART], [1], [Enable the BitBang UART Adapter]) 
    adapters="${adapters}BitBang-UART "
    ADAPTER_OBJECTS+='adapter-bitbang.$(OBJEXT) '
    have_adapter=1
    need_uart=1
], [])

AC_ARG_ENABLE([hidboot], [AS_HELP_STRING([--enable-hidboot],[HIDBoot Adapter])], [
    AC_DEFINE([USE_HIDBOOT], [1], [Enable the HIDBOOT Adapter]) 
    adapters="${adapters}HIDBoot "
    need_usb1=1
    have_adapter=1
    ADAPTER_OBJECTS+='adapter-hidboot.$(OBJEXT) '
], [])

AC_ARG_ENABLE([mpsse], [AS_HELP_STRING([--enable-mpsse],[MPSSE Adapter])], [
    AC_DEFINE([UE_MPSSE], [1], [Enable the MPSSE Adapter]) 
    adapters="${adapters}MPSSE "
    need_usb0=1
    have_adapter=1
    ADAPTER_OBJECTS+='adapter-mpsse.$(OBJEXT) '
], [])

AC_ARG_ENABLE([pickit2], [AS_HELP_STRING([--enable-pickit2],[picKIT2™ (or picKIT3™ with scripting firmware)])], [
    AC_DEFINE([USE_PICKIT2], [1], [Enable the picKIT2 Adapter]) 
    adapters="${adapters}picKIT2 "
    need_usb1=1
    have_adapter=1
    ADAPTER_OBJECTS+='adapter-pickit2.$(OBJEXT) '
], [])

AC_ARG_ENABLE([stk500v2], [AS_HELP_STRING([--enable-stk500v2],[STK500V2 (chipKIT) Bootloader])], [
    AC_DEFINE([USE_STK500V2], [1], [Enable the STK500V2 UART Adapter]) 
    adapters="${adapters}stk500V2 "
    have_adapter=1
    need_uart=1
    ADAPTER_OBJECTS+='adapter-stk500v2.$(OBJEXT) adapter-stk500v2-boards.$(OBJEXT) '
],[])

AC_ARG_ENABLE([uhb], [AS_HELP_STRING([--enable-uhb],[UHB Adapter])], [
    AC_DEFINE([USE_UHB], [1], [Enable the UHB Adapter]) 
    adapters="${adapters}UHB "
    need_usb1=1
    have_adapter=1
    ADAPTER_OBJECTS+='adapter-uhb.$(OBJEXT) '
], [])

AC_DEFUN([AC_CHECK_ADAPTERS], [
    AC_MSG_CHECKING([adapters])
    if test $have_adapter -eq 1; then
        AC_MSG_RESULT($adapters)
    else
        AC_MSG_ERROR([no

You have not selected any adapters to include. Use --enable-ADAPTER to
include the adapters you require:

    --enable-an1388
    --enable-an1388-uart    
    --enable-bitbang
    --enable-hidboot
    --enable-mpsse
    --enable-pickit2
    --enable-stk500v2
    --enable-uhb
])

    fi
])
AC_CHECK_ADAPTERS

AC_DEFUN([AC_CHECK_USB], [
    if test $need_usb0 -eq 1; then
        AC_CHECK_HEADER([usb.h],,[AC_MSG_ERROR([Required library libusb is not installed.])])
        AC_CHECK_LIB([usb],[usb_open],,[AC_MSG_ERROR([Required library libusb is not installed.])])
    fi
    if test $need_usb1 -eq 1; then
        AC_CHECK_HEADER([libusb-1.0/libusb.h],,[AC_MSG_ERROR([Required library libusb-1.0 is not installed.])])
        AC_CHECK_LIB([usb-1.0],[usb_open],,[AC_MSG_ERROR([Required library libusb-1.0 is not installed.])])
        CFLAGS+=' -Ihidapi'
        LIBS+=' -lhidapi'
        LDFLAGS+=' -Lhidapi'
    fi
])
AC_CHECK_USB

AC_DEFUN([AC_CONFIG_HOST], [
    case $host_os in
      darwin* )
            LIBS="${LIBS} -framework IOKit -framework CoreFoundation"
            univ_archs=`grep '^universal_archs' /opt/local/etc/macports/macports.conf`
            case "${univ_archs}" in
                *i386*)
                    CFLAGS="${CFLAGS} -arch i386"
                    ;;
            esac 
            case "${univ_archs}" in
                *x86_64*)
                    CFLAGS="${CFLAGS} -arch x86_64"
                    ;;
            esac

            if test ${need_usb1} -eq 1; then
                HIDAPI_OBJECTS='hid-mac.$(OBJEXT)'
            fi
            if test ${need_usb0} -eq 1; then
                    CFLAGS="${CFLAGS} -I/opt/local/include/libusb-legacy"
                    LIBS="${LIBS} /opt/local/lib/libusb-legacy/libusb-legacy.a"
            fi
            ;;
      linux*)
            if test ${need_usb1} -eq 1; then
                LIBS+=" -lusb-1.0 -lpthread -ludev"
                HIDAPI_OBJECTS='hid-libusb.$(OBJEXT)'
            fi
            if test ${need_usb0} -eq 1; then
                LIBS+=" -lusb"
            fi
            # Do something specific for linux
            ;;
       *BSD*)
            # Do something specific for BSD
            ;;
        *)
            #Default Case
            AC_MSG_ERROR([Your platform is not currently supported])
            ;;
    esac
])
AC_CONFIG_HOST

AC_DEFUN([AC_CHECK_UART], [
    if test ${need_uart} -eq 1; then
        AC_DEFINE([USING_UART], [1], [A selected adaptor uses UART code])
        ADAPTER_OBJECTS+='serial.$(OBJEXT) '
    fi
])
AC_CHECK_UART

AC_SUBST([ADAPTER_OBJECTS])
AC_SUBST([HIDAPI_OBJECTS])

AC_OUTPUT
