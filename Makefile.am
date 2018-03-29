SUBDIRS = .
## Place generated object files (.o) into the same directory as their source
## files, in order to avoid collisions when non-recursive make is used.
AUTOMAKE_OPTIONS = subdir-objects

ACLOCAL_AMFLAGS = ${ACLOCAL_FLAGS} -I m4

pkglib_LTLIBRARIES = libpslib.la


libpslib_la_SOURCES = common.c \
		      pslib_linux.c \
		      common.h \
		      pslib.h

libpslib_includedir = $(includedir)
libpslib_include_HEADERS = pslib.h

libpslib_la_LDFLAGS = -version-info $(CPSLIB_SO_VERSION)
