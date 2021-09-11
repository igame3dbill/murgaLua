# For windows
export CFLAGS="-Os -fexpensive-optimizations"
export C_INCLUDE_PATH=/usr/local/include

# Fixes for bad make "install"
echo > /usr/local/bin/lua
echo > /usr/local/bin/luac
echo > /usr/local/bin/sqlite3

echo ""
echo "Starting FULL build!"
echo ""

cd ..
cd lua-5.*/
mv src/Makefile src/Makefile.old
sed "s/CFLAGS= -O2/CFLAGS= -Os -fexpensive-optimizations/g" src/Makefile.old > src/Makefile
make clean
make mingw
sleep 4
make install
sleep 4
cd ..
cd sqlite-3.*/
./configure --disable-threadsafe
sleep 4
make clean
make
sleep 4
make install
sleep 4
cd ..
cd fltk-1.1*
# --enable-xft (For linux)
./configure --disable-threads --disable-gl --enable-localjpeg --enable-localzlib --enable-localpng --with-optim="-Os -fexpensive-optimizations"
sleep 4
make clean
make
sleep 4
make install
cp fluid/fluid.exe ../murgaLua/bin/Windows
cd ..
cd murgaLua/
strip bin/Windows/fluid.exe
tools/upx.exe --lzma --best bin/Windows/fluid.exe
sleep 4
make clean
make windows
cd bin
mv murgaLua.exe Windows
rm file2c.exe
cd ..
make clean

echo ""
echo "All done!"
echo ""
