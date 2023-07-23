#!/bin/bash
gcc $(pkg-config --cflags weechat) \
  -shared -fPIC -Wall -Wextra src/essai.c src/essai-command.c -o lib/essai.so \
  $(pkg-config --libs weechat) && \
mv -v lib/essai.so ${XDG_DATA_HOME}/weechat/plugins/
