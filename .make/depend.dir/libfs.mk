DEPEND_TARGETS += libfs.build
ECHO_TARGETS += libfs.echo
libfs.build:
	@echo SUPER_MAKE_DIR=/mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libmodule/               >> /mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libfs/.make/super
	@echo SUPER_MAKE_CONFIG_DIR=/mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libmodule/.make >> /mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libfs/.make/super
	cd /mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libfs/ && make && make install
	-rm /mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libfs/.make/super
libfs.echo:
	@echo SUPER_MAKE_DIR=/mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libmodule/               >> /mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libfs/.make/super
	@echo SUPER_MAKE_CONFIG_DIR=/mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libmodule/.make >> /mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libfs/.make/super
	cd /mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libfs/ && make echo
	-rm /mnt/d/CORE_WEB_SYSTEM_WEB/alpine/libraries/libfs/.make/super
