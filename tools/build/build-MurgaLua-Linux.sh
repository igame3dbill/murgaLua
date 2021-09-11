# For linux
export CFLAGS="-Os -fexpensive-optimizations"

echo ""
echo "Starting FULL build!"
echo ""

chmod +x tools/upx

ln -s `gcc --print-file-name libstdc++.a`

cd ..

cd lua-5.*/
mv src/Makefile src/Makefile.old
sed "s/CFLAGS= -O2/CFLAGS= -Os -fexpensive-optimizations/g" src/Makefile.old > src/Makefile
make clean
make linux
sleep 4
make install
make clean
sleep 4
cd ..

cd sqlite-3.*/
chmod +x configure
./configure --disable-threadsafe
sleep 4
make clean
make
sleep 4
make install
make clean
sleep 4
cd ..

echo ""
echo "Building nonXft version"
echo ""

cd fltk-1.1*
chmod +x configure
./configure --disable-threads --disable-xft --disable-gl --enable-localjpeg --enable-localzlib --enable-localpng --with-optim="-Os -fexpensive-optimizations"
sleep 4
make clean
make
sleep 4
make install
cp fluid/fluid ../murgaLua/bin/Linux/otherBuilds/fluid_nonXft
make clean
cd ..

cd murgaLua/
strip bin/Linux/fluid_nonXft
tools/upx --lzma --best bin/Linux/otherBuilds/fluid_nonXft
sleep 4
make clean
make linux
cd bin
mv murgaLua Linux/otherBuilds/murgaLua_Dynamic_nonXft
cd ../..

cd murgaLua/
sleep 4
make clean
make linuxStatic
cd bin
mv murgaLua Linux/otherBuilds/murgaLua_nonXft
cd ../..

cd fltk-1.1*
./configure --disable-threads --enable-xft --disable-gl --enable-localjpeg --enable-localzlib --enable-localpng --with-optim="-Os -fexpensive-optimizations"
sleep 4
make clean
make
sleep 4
make install
cp fluid/fluid ../murgaLua/bin/Linux
make clean
cd ..

cd murgaLua/
sleep 4
make clean
make linux
cd bin
mv murgaLua Linux/otherBuilds/murgaLua_Dynamic
cd ../..

cd murgaLua/
strip bin/Linux/fluid
tools/upx --lzma --best bin/Linux/fluid
sleep 4
make clean
make linuxStatic
cd bin
mv murgaLua Linux
rm file2c
cd ..
make clean
rm libstdc++.a

chmod +x tools/upx*
chmod +x tools/*.sh

chmod +x bin/Windows/*
chmod +x bin/Linux/*
chmod +x bin/MacOs-Intel/*

cd ..
tar -zcvf murgaLua-0.X.tar.gz murgaLua

echo ""
echo "All done!"
echo ""

