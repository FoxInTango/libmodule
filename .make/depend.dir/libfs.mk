DEPEND_TARGETS += libfs.recursive
ECHO_TARGETS += libfs.echo
libfs.recursive:
	@echo SUPER_MAKE_DIR=/volumes/llama/home/alpine/libraries/libmodule/               >> /volumes/llama/home/alpine/libraries/libfs/.make/super
	@echo SUPER_MAKE_CONFIG_DIR=/volumes/llama/home/alpine/libraries/libmodule/.make >> /volumes/llama/home/alpine/libraries/libfs/.make/super
	cd /volumes/llama/home/alpine/libraries/libfs/ && make recursive && make install
	-rm /volumes/llama/home/alpine/libraries/libfs/.make/super
libfs.echo:
	@echo SUPER_MAKE_DIR=/volumes/llama/home/alpine/libraries/libmodule/               >> /volumes/llama/home/alpine/libraries/libfs/.make/super
	@echo SUPER_MAKE_CONFIG_DIR=/volumes/llama/home/alpine/libraries/libmodule/.make >> /volumes/llama/home/alpine/libraries/libfs/.make/super
	cd /volumes/llama/home/alpine/libraries/libfs/ && make echo
	-rm /volumes/llama/home/alpine/libraries/libfs/.make/super
