##
## $Id$
##

ACLOCAL_AMFLAGS = -I ../../../../aclocal

include $(top_srcdir)/../../../../automake/compile.am
include $(top_srcdir)/../../bsp.am

include_bspdir = $(includedir)/bsp

dist_project_lib_DATA = bsp_specs

include_HEADERS = include/bsp.h
include_HEADERS += ../../shared/include/tm27.h

nodist_include_HEADERS = include/bspopts.h
nodist_include_bsp_HEADERS = ../../shared/include/bootcard.h
DISTCLEANFILES = include/bspopts.h
noinst_PROGRAMS =

nodist_include_HEADERS += ../../shared/include/coverhd.h

dist_project_lib_DATA += startup/linkcmds

noinst_LIBRARIES = libbsp.a
libbsp_a_SOURCES =

# startup
libbsp_a_SOURCES += ../../shared/bspclean.c ../../shared/bsplibc.c \
    ../../shared/bsppretaskinghook.c ../../shared/bsppredriverhook.c \
    start/bspgetworkarea.c ../../shared/bsppost.c \
    startup/bspstart.c ../../shared/bootcard.c ../../shared/sbrk.c \
    startup/setvec.c ../../shared/gnatinstallhandler.c ../../shared/bspreset.c \
		start/start.c
# clock
libbsp_a_SOURCES += clock/ckinit.c
# console
libbsp_a_SOURCES += console/console.c
# timer
libbsp_a_SOURCES += timer/timer.c timer/timerisr.c
#score
libbsp_a_SOURCES += score/cpu.c score/cpu_asm2.S score/cpu_asm.c
#irq
libbsp_a_SOURCES += irq/irq_pok.c

EXTRA_DIST = times

include $(srcdir)/preinstall.am
include $(top_srcdir)/../../../../automake/local.am

nodist_include_bsp_HEADERS += irq/irq.h \
															irq/irq_pok.h
# score
nodist_include_bsp_HEADERS += score/cpu.h \
	score/interrupts.h \
	score/registers.h \
	score/types.h \
	score/idtr.h \
	score/i386.h

# start
nodist_include_bsp_HEADERS += start/poksyscalls.h
