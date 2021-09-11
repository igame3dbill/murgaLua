#
# Makefile - murgaLua Makefile
#
# Copyright (C) 2006-2008 John Murga
# 
# This program is free software; you can redistribute it and/or
# modify it under the terms of the GNU General Public License
# as published by the Free Software Foundation; either version 2
# of the License, or (at your option) any later version.
# 
# This program is distributed in the hope that it will be useful,
# but WITHOUT ANY WARRANTY; without even the implied warranty of
# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
# GNU General Public License for more details.
# 
# You should have received a copy of the GNU General Public License
# along with this program; if not, write to the :
# 
#   Free Software Foundation, Inc.
#   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
#

PLAT    = none
PLATS   = linux linuxStatic windows macos

linux_LINK_OPT       = -l sqlite3 -lreadline -lhistory -lncurses
linuxStatic_LINK_OPT = -static-libgcc -L.. /usr/local/lib/libsqlite3.a
windows_LINK_OPT     = /usr/local/lib/libsqlite3.a -mconsole
macos_LINK_OPT       = /usr/local/lib/libsqlite3.a

linux_CXX_OPT        = -Dlinux -DLUA_USE_LINUX
linuxStatic_CXX_OPT  = -Dlinux
windows_CXX_OPT      = -Dwindows
macos_CXX_OPT        = -Dmacos 

linuxOBJ        = ../3rd-party/luasocket-2.0.2-MOD/src/usocket.o
linuxStaticOBJ  = ../3rd-party/luasocket-2.0.2-MOD/src/usocket.o
windowsOBJ      = ../3rd-party/luasocket-2.0.2-MOD/src/wsocket.o
macosOBJ        = ../3rd-party/luasocket-2.0.2-MOD/src/usocket.o

linuxEXT        = 
linuxStaticEXT  = 
windowsEXT      = .exe
macosEXT        = 

linuxPACK       = ../tools/upx --lzma --best
linuxStaticPACK = ../tools/upx --lzma --best
windowsPACK     = ../tools/upx.exe --lzma --best
macosPACK       = echo "Pack with UPX on Windows or Linux"

AR     = ar
RANLIB = ranlib
CC     = gcc
CXX    = g++

TARGET       = ../bin/murgaLua
LIB          = murgaLua.a
LUA_CXXFLAGS = -DLUA

CXXFLAGS	= -Os -fexpensive-optimizations -g `fltk-config --use-images --use-forms --cxxflags` $(LUA_CXXFLAGS) $($(PLAT)_CXX_OPT)

LDFLAGS		= -Os -fexpensive-optimizations -g `fltk-config --use-images --use-forms --ldstaticflags --libs` /usr/local/lib/liblua.a $($(PLAT)_LINK_OPT)

CPP_FLAGS	= -Os -fexpensive-optimizations "-Dasm(...)=" "-D__asm__(...)=" \
	-D__extension__="" -D__const=const "-D__attribute__(...)=" \
	-D__size="unsigned int" -Dptrdiff_t=int -D__restrict="" \
	-D__inline="" -D__mode__="" -Dexplicit=""


LOBJS		= bind-fltk-ext.o

OBJS		= murgaLua.o \
			  ../3rd-party/tinyxml/tinyxml.o ../3rd-party/tinyxml/tinyxmlparser.o \
			  ../3rd-party/tinyxml/tinyxmlerror.o ../3rd-party/tinyxml/tinystr.o \
			  ../3rd-party/luaLZO/minilzo.o \
			  ../3rd-party/luasocket-2.0.2-MOD/src/auxiliar.o ../3rd-party/luasocket-2.0.2-MOD/src/except.o \
			  ../3rd-party/luasocket-2.0.2-MOD/src/io.o ../3rd-party/luasocket-2.0.2-MOD/src/mime.o \
			  ../3rd-party/luasocket-2.0.2-MOD/src/select.o ../3rd-party/luasocket-2.0.2-MOD/src/timeout.o \
			  ../3rd-party/luasocket-2.0.2-MOD/src/udp.o ../3rd-party/luasocket-2.0.2-MOD/src/buffer.o \
			  ../3rd-party/luasocket-2.0.2-MOD/src/inet.o ../3rd-party/luasocket-2.0.2-MOD/src/luasocket.o \
			  ../3rd-party/luasocket-2.0.2-MOD/src/options.o ../3rd-party/luasocket-2.0.2-MOD/src/tcp.o \
			  ../3rd-party/md5-1.1.1/src/md5.o ../3rd-party/md5-1.1.1/src/md5lib.o


BINDFILE	= bind-fltk.cxx

none:
	@echo ""
	@echo "Please do"
	@echo "   make PLATFORM"
	@echo "where PLATFORM is one of these:"
	@echo "   $(PLATS)"
	@echo ""

$(PLATS) :
	$(MAKE) clean
	sh ../tools/embedLuaSocket.sh
	sh ../tools/embedMurgaLuaLib.sh $@
	$(MAKE) $(TARGET) PLAT=$@
	strip $(TARGET)$($@EXT)
	$($@PACK) $(TARGET)$($@EXT)
	
	
all : $(PLAT)

bind-fltk-ext.o : $(BINDFILE)

$(TARGET): $(LIB) $(OBJS) $($(PLAT)OBJ)
	$(CXX) $(OBJS) $($(PLAT)OBJ) $(LIB) $(LDFLAGS) -o $@

$(LIB) : $(LOBJS)
	@echo [building library $@]
	rm -f $@
	$(AR) crs $@ $^ 
	$(RANLIB) $@

.PHONY : clean
clean :
	@echo CLEANING - Just in case
	rm -f $(LOBJS) $(OBJS) $(linuxOBJ) $(windowsOBJ) $(LIB) socketLua-temp.c murgaLuaLib-temp.c *.o ../bin/file2c.*

.SUFFIXES : .cxx .c .o

.cxx.o:
	@echo [compiling $<]
	$(CXX) $(CXXFLAGS) -c $< -o $@

