DEPEND_TARGETS += libmodel.recursive
ECHO_TARGETS += libmodel.echo
libmodel.recursive:
	@echo SUPER_MAKE_DIR=/home/lidali/alpine/libraries/libmodule/               >> /home/lidali/alpine/libraries/libmodel/.make/super
	@echo SUPER_MAKE_CONFIG_DIR=/home/lidali/alpine/libraries/libmodule/.make >> /home/lidali/alpine/libraries/libmodel/.make/super
	cd /home/lidali/alpine/libraries/libmodel/ && make recursive && make install
	-rm /home/lidali/alpine/libraries/libmodel/.make/super
libmodel.echo:
	@echo SUPER_MAKE_DIR=/home/lidali/alpine/libraries/libmodule/               >> /home/lidali/alpine/libraries/libmodel/.make/super
	@echo SUPER_MAKE_CONFIG_DIR=/home/lidali/alpine/libraries/libmodule/.make >> /home/lidali/alpine/libraries/libmodel/.make/super
	cd /home/lidali/alpine/libraries/libmodel/ && make echo
	-rm /home/lidali/alpine/libraries/libmodel/.make/super
