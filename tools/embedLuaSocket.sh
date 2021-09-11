gcc ../tools/file2c.c -o ../bin/file2c

echo "const char luaSocketCode_socket[] = { " > ../src/socketLua-temp.c
sed "s/require(\"socket.core\")/require(\"socket\")/g" ../3rd-party/luasocket-2.0.2-MOD/src/socket.lua | ../bin/file2c >> ../src/socketLua-temp.c
echo -n ",00" >> ../src/socketLua-temp.c
echo " }; " >> ../src/socketLua-temp.c

echo "const char luaSocketCode_mime[] = { " >> ../src/socketLua-temp.c
sed "s/require(\"mime.core\")/require(\"mime\")/g" ../3rd-party/luasocket-2.0.2-MOD/src/mime.lua | ../bin/file2c >> ../src/socketLua-temp.c
echo -n ",00" >> ../src/socketLua-temp.c
echo " }; " >> ../src/socketLua-temp.c

echo "const char luaSocketCode_ltn12[] = { " >> ../src/socketLua-temp.c
cat ../3rd-party/luasocket-2.0.2-MOD/src/ltn12.lua | ../bin/file2c >> ../src/socketLua-temp.c
echo -n ",00" >> ../src/socketLua-temp.c
echo " }; " >> ../src/socketLua-temp.c

echo "const char luaSocketCode_tp[] = { " >> ../src/socketLua-temp.c
cat ../3rd-party/luasocket-2.0.2-MOD/src/tp.lua | ../bin/file2c >> ../src/socketLua-temp.c
echo -n ",00" >> ../src/socketLua-temp.c
echo " }; " >> ../src/socketLua-temp.c

echo "const char luaSocketCode_url[] = { " >> ../src/socketLua-temp.c
cat ../3rd-party/luasocket-2.0.2-MOD/src/url.lua | ../bin/file2c >> ../src/socketLua-temp.c
echo -n ",00" >> ../src/socketLua-temp.c
echo " }; " >> ../src/socketLua-temp.c

echo "const char luaSocketCode_ftp[] = { " >> ../src/socketLua-temp.c
cat ../3rd-party/luasocket-2.0.2-MOD/src/ftp.lua | ../bin/file2c >> ../src/socketLua-temp.c
echo -n ",00" >> ../src/socketLua-temp.c
echo " }; " >> ../src/socketLua-temp.c

echo "const char luaSocketCode_http[] = { " >> ../src/socketLua-temp.c
cat ../3rd-party/luasocket-2.0.2-MOD/src/http.lua | ../bin/file2c >> ../src/socketLua-temp.c
echo -n ",00" >> ../src/socketLua-temp.c
echo " }; " >> ../src/socketLua-temp.c

echo "const char luaSocketCode_smtp[] = { " >> ../src/socketLua-temp.c
cat ../3rd-party/luasocket-2.0.2-MOD/src/smtp.lua | ../bin/file2c >> ../src/socketLua-temp.c
echo -n ",00" >> ../src/socketLua-temp.c
echo " }; " >> ../src/socketLua-temp.c
