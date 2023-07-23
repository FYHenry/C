# essai Makefile v4.3

WEECHAT_HEADER := /usr/include/weechat/weechat-plugin.h
PLUGIN =: ${XDG_DATA_HOME}/weechat/plugins/
GCCFLAGS := $(pkg-config --cflags weechat) -fPIC -Wall -Wextra
LIBFLAGS := -shared
GCCLIBS := $(pkg-config --libs weechat)

help :
	@echo 'Pas d’aide.'

build : essai.o essai-command.o
	if [ ! -d lib ] ; then mkdir lib ; fi
	gcc $(LIBFLAGS) $(GCCFLAGS) obj/essai.o obj/essai-command.o \
	-o lib/essai.so $(GCCLIBS)

essai.o : essai.c essai.h essai-command.h $(WEECHAT_HEADER)
	if [ ! -d obj ] ; then mkdir obj ; fi
	gcc $(GCCFLAGS) -c essai.c -o obj/essai.o $(GCCLIBS)

essai-command.o : essai-command.c essai.h essai-command.h $(WEECHAT_HEADER)
	if [ ! -d obj ] ; then mkdir obj ; fi
	gcc $(GCCFLAGS) -c essai-command.c -o obj/essai-command.o $(GCCLIBS)

clean :
	rm -r obj
	rm -r lib
