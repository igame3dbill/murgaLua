# For windows
export CFLAGS="-Os -fexpensive-optimizations"

echo ""
echo "Starting FULL build!"
echo ""

cd ..
cd lua-5.*/
mv src/Makefile src/Makefile.old
sed "s/CFLAGS= -O2/CFLAGS= -Os -fexpensive-optimizations/g" src/Makefile.old > src/Makefile
make clean
make macosx
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
./configure --disable-threads --disable-gl --enable-localjpeg --enable-localzlib --enable-localpng --with-optim="-Os -fexpensive-optimizations"
sleep 4
make clean
make
sleep 4
make install
cp fluid/fluid ../murgaLua/bin/MacOs-Intel
cp fltk-config /sbin
cd ..
cd murgaLua/
strip bin/MacOs-Intel/fluid
tools/upx --lzma --best bin/MacOs-Intel/fluid
sleep 4
make clean
make macos
cd bin
mv murgaLua MacOs-Intel
rm file2c
cd ..
make clean

echo ""
echo "All done!"
echo ""
