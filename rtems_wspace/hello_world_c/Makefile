#
#  $Id$
#

#
#  RTEMS_MAKEFILE_PATH is typically set in an environment variable
#

PGM=${ARCH}/hello.exe

# optional managers required
MANAGERS=all

# C source names
CSRCS = test.c
COBJS = $(CSRCS:%.c=${ARCH}/%.o)

CAS = $(wildcard ${PROJECT_ROOT}/i386-rtems4.11/${RTEMS_BSP}/lib/*.a)	#FIXME "i386-rtems411" cannot be hardcoded
AOUTPUT = rtemslibsall.a

include $(RTEMS_MAKEFILE_PATH)/Makefile.inc
include $(RTEMS_CUSTOM)
include $(PROJECT_ROOT)/make/leaf.cfg

OBJS= $(COBJS) $(CXXOBJS) $(ASOBJS)

all:    ${ARCH} $(PGM)

$(PGM): $(OBJS)
	$(make-exe)
	$(ECHO) $(make-exe)
	${AR} -cvq $(AOUTPUT) ${CAS} ${OBJS}

.PHONY: clean
clean:
	rm $(AOUTPUT)

.PHONY: printvars
printvars:
	@$(foreach V, \
		$(sort $(.VARIABLES)), \
		$(if \
			$(filter-out environment% default automatic, \
				$(origin $V)), \
			$(warning $V=$($V) ($(value $V))) \
		) \
	)
