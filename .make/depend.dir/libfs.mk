DEPEND_TARGETS += libfs.recursive
ECHO_TARGETS += libfs.echo
libfs.recursive:
	@echo SUPER_MAKE_DIR=/Users/lidali/alpine/libraries/libmodule/               >> /Users/lidali/alpine/libraries/libfs/.make/super
	@echo SUPER_MAKE_CONFIG_DIR=/Users/lidali/alpine/libraries/libmodule/.make >> /Users/lidali/alpine/libraries/libfs/.make/super
	cd /Users/lidali/alpine/libraries/libfs/ && /Applications/Xcode.app/Contents/Developer/usr/bin/make recursive && /Applications/Xcode.app/Contents/Developer/usr/bin/make install
	-rm /Users/lidali/alpine/libraries/libfs/.make/super
libfs.echo:
	@echo SUPER_MAKE_DIR=/Users/lidali/alpine/libraries/libmodule/               >> /Users/lidali/alpine/libraries/libfs/.make/super
	@echo SUPER_MAKE_CONFIG_DIR=/Users/lidali/alpine/libraries/libmodule/.make >> /Users/lidali/alpine/libraries/libfs/.make/super
	cd /Users/lidali/alpine/libraries/libfs/ && /Applications/Xcode.app/Contents/Developer/usr/bin/make echo
	-rm /Users/lidali/alpine/libraries/libfs/.make/super
