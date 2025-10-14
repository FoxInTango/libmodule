DEPEND_TARGETS += libmodel.recursive
ECHO_TARGETS += libmodel.echo
libmodel.recursive:
	@echo SUPER_MAKE_DIR=/Users/lidali/alpine/libraries/libmodule/               >> /Users/lidali/alpine/libraries/libmodel/.make/super
	@echo SUPER_MAKE_CONFIG_DIR=/Users/lidali/alpine/libraries/libmodule/.make >> /Users/lidali/alpine/libraries/libmodel/.make/super
	cd /Users/lidali/alpine/libraries/libmodel/ && /Applications/Xcode.app/Contents/Developer/usr/bin/make recursive && /Applications/Xcode.app/Contents/Developer/usr/bin/make install
	-rm /Users/lidali/alpine/libraries/libmodel/.make/super
libmodel.echo:
	@echo SUPER_MAKE_DIR=/Users/lidali/alpine/libraries/libmodule/               >> /Users/lidali/alpine/libraries/libmodel/.make/super
	@echo SUPER_MAKE_CONFIG_DIR=/Users/lidali/alpine/libraries/libmodule/.make >> /Users/lidali/alpine/libraries/libmodel/.make/super
	cd /Users/lidali/alpine/libraries/libmodel/ && /Applications/Xcode.app/Contents/Developer/usr/bin/make echo
	-rm /Users/lidali/alpine/libraries/libmodel/.make/super
