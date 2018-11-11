CC=gcc
CFLAGS=-Wall -Wstrict-prototypes -Werror -fPIC

LD_SONAME=-Wl,-soname,libpam_debug.so.2
LIBRARY=libpam_debug.so.2
LINKS=libpam_debug.so.2 libpam_debug.so

DESTDIR=/
PREFIX=$(DESTDIR)/usr
LIBDIR=$(PREFIX)/lib
BUILD=./libs

default: build
build: pam_debug

pam_debug_build_dir:
	[ -d $(BUILD) ] || mkdir $(BUILD)

pam_debug_service:
	$(CC) $(CFLAGS) -c pam_debug.c -o $(BUILD)/pam_debug.o

pam_debug: pam_debug_build_dir pam_debug_service
	$(CC) -shared $(LD_SONAME) -o $(BUILD)/$(LIBRARY) \
		$(BUILD)/pam_debug.o

clean:
	rm -rf $(BUILD)

install:
	[ -d $(LIBDIR) ] || install -d $(LIBDIR)
	install $(BUILD)/$(LIBRARY) $(LIBDIR)
	cd $(LIBDIR); for link in $(LINKS); do ln -sf $(LIBRARY) $$link ; done

.PHONY: clean pam_debug