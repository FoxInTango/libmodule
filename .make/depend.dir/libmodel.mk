DEPEND_TARGETS += libmodel.build
ECHO_TARGETS += libmodel.echo
libmodel.build:
	@echo SUPER_MAKE_DIR=/mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libmodule/               >> /mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libmodel/.make/super
	@echo SUPER_MAKE_CONFIG_DIR=/mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libmodule/.make >> /mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libmodel/.make/super
	cd /mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libmodel/ && make && make install
	-rm /mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libmodel/.make/super
libmodel.echo:
	@echo SUPER_MAKE_DIR=/mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libmodule/               >> /mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libmodel/.make/super
	@echo SUPER_MAKE_CONFIG_DIR=/mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libmodule/.make >> /mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libmodel/.make/super
	cd /mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libmodel/ && make echo
	-rm /mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libmodel/.make/super
