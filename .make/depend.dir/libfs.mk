DEPEND_TARGETS += libfs.recursive
ECHO_TARGETS += libfs.echo
libfs.recursive:
	@echo SUPER_MAKE_DIR=/home/lidali/alpine/libraries/libmodule/               >> /home/lidali/alpine/libraries/libfs/.make/super
	@echo SUPER_MAKE_CONFIG_DIR=/home/lidali/alpine/libraries/libmodule/.make >> /home/lidali/alpine/libraries/libfs/.make/super
	cd /home/lidali/alpine/libraries/libfs/ && make recursive && make install
	-rm /home/lidali/alpine/libraries/libfs/.make/super
libfs.echo:
	@echo SUPER_MAKE_DIR=/home/lidali/alpine/libraries/libmodule/               >> /home/lidali/alpine/libraries/libfs/.make/super
	@echo SUPER_MAKE_CONFIG_DIR=/home/lidali/alpine/libraries/libmodule/.make >> /home/lidali/alpine/libraries/libfs/.make/super
	cd /home/lidali/alpine/libraries/libfs/ && make echo
	-rm /home/lidali/alpine/libraries/libfs/.make/super
