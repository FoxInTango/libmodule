DEPEND_TARGETS += libmodel.recursive
ECHO_TARGETS += libmodel.echo
libmodel.recursive:
	@echo SUPER_MAKE_DIR=/volumes/llama/home/alpine/libraries/libmodule/               >> /volumes/llama/home/alpine/libraries/libmodel/.make/super
	@echo SUPER_MAKE_CONFIG_DIR=/volumes/llama/home/alpine/libraries/libmodule/.make >> /volumes/llama/home/alpine/libraries/libmodel/.make/super
	cd /volumes/llama/home/alpine/libraries/libmodel/ && make recursive && make install
	-rm /volumes/llama/home/alpine/libraries/libmodel/.make/super
libmodel.echo:
	@echo SUPER_MAKE_DIR=/volumes/llama/home/alpine/libraries/libmodule/               >> /volumes/llama/home/alpine/libraries/libmodel/.make/super
	@echo SUPER_MAKE_CONFIG_DIR=/volumes/llama/home/alpine/libraries/libmodule/.make >> /volumes/llama/home/alpine/libraries/libmodel/.make/super
	cd /volumes/llama/home/alpine/libraries/libmodel/ && make echo
	-rm /volumes/llama/home/alpine/libraries/libmodel/.make/super
