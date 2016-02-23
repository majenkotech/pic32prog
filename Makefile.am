# Indicate this is not a GNU project and that
# missing files should be automatically created
AUTOMAKE_OPTIONS=foreign
SUBDIRS=hidapi

# Instruct aclocal to check the cfg directory for
# extra macros
#ACLOCAL_AMFLAGS=-I cfg

#INCLUDES= -I@top_srcdir@ -I@top_srcdir@/hidapi

# Global C Flags
#AM_CFLAGS = 

#EXTRA_DIST=libwcl.pc

# Programs to build
bin_PROGRAMS = pic32prog

pic32prog_includedir=@top_srcdir@ -I@top_srcdir@/hidapi
pic32prog_LDADD=$(ADAPTER_OBJECTS)
pic32prog_SOURCES=pic32prog.c executive.c family-mx3.c family-mx1.c family-mz.c target.c configure.c 
pic32prog_DEPENDENCIES=$(ADAPTER_OBJECTS)
