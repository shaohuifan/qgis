#############################################################################
# Makefile for building: qgis
# Generated by qmake (1.06c) (Qt 3.2.0) on: Fri Aug 22 10:17:43 2003
# Project:  qgis.pro
# Template: subdirs
# Command: $(QMAKE) -o Makefile qgis.pro
#############################################################################

MAKEFILE =	Makefile
QMAKE    =	qmake
DEL_FILE =    rm -f
CHK_DIR_EXISTS= test -d
MKDIR    = mkdir -p
SUBTARGETS =	 \
		sub-src \
		sub-plugins

first: all

all: Makefile $(SUBTARGETS)

src/$(MAKEFILE): 
	@$(CHK_DIR_EXISTS) "src" || $(MKDIR) "src"
	cd src && $(QMAKE) src.pro -o $(MAKEFILE)
sub-src: src/$(MAKEFILE) FORCE
	cd src && $(MAKE) -f $(MAKEFILE)

plugins/$(MAKEFILE): 
	@$(CHK_DIR_EXISTS) "plugins" || $(MKDIR) "plugins"
	cd plugins && $(QMAKE) plugins.pro -o $(MAKEFILE)
sub-plugins: plugins/$(MAKEFILE) FORCE
	cd plugins && $(MAKE) -f $(MAKEFILE)

Makefile: qgis.pro  /usr/local/qt-x11-free-3.2.0/mkspecs/default/qmake.conf 
	$(QMAKE) -o Makefile qgis.pro
qmake: qmake_all
	@$(QMAKE) -o Makefile qgis.pro

all: $(SUBTARGETS)
qmake_all: src/$(MAKEFILE) plugins/$(MAKEFILE)
	 ( [ -d src ] && cd src ; grep "^qmake_all:" $(MAKEFILE) && $(MAKE) -f $(MAKEFILE) qmake_all; ) || true
	 ( [ -d plugins ] && cd plugins ; grep "^qmake_all:" $(MAKEFILE) && $(MAKE) -f $(MAKEFILE) qmake_all; ) || true
clean uninstall uicables mocables install uiclean mocclean lexclean yaccclean: qmake_all FORCE
	 ( [ -d src ] && cd src ; $(MAKE) -f $(MAKEFILE) $@; ) || true
	 ( [ -d plugins ] && cd plugins ; $(MAKE) -f $(MAKEFILE) $@; ) || true
distclean: qmake_all FORCE
	 ( [ -d src ] && cd src ; $(MAKE) -f $(MAKEFILE) $@; $(DEL_FILE) $(MAKEFILE); ) || true
	 ( [ -d plugins ] && cd plugins ; $(MAKE) -f $(MAKEFILE) $@; $(DEL_FILE) $(MAKEFILE); ) || true

FORCE:

