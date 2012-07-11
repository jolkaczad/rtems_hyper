-include misc/mk/config.mk

.SILENT:
.PHONY: doc

SUBDIRS = examples kernel libpok doc

all:
	@echo "Nothing to do here; browse through examples.";

configure:
	./misc/conf-env.pl $(ARCH)

configure-xcov:
	./misc/conf-env.pl --with-xcov $(ARCH)

configure-instrumentation:
	./misc/conf-env.pl --with-instrumentation $(ARCH)

clean:
	for dir	in $(SUBDIRS);			\
	do					\
		$(MAKE) -C $$dir $@ || exit 1;	\
        done

distclean:
	for dir	in $(SUBDIRS);			\
	do					\
		$(MAKE) -C $$dir $@ || exit 1;	\
        done
	$(RM) misc/mk/config.mk pok-[0-9]*.tgz

test:
	$(MAKE) -C examples test


-include $(POK_PATH)/misc/mk/rules-common.mk
