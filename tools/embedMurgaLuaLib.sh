gcc ../tools/file2c.c -o ../bin/file2c

# Temp HACK
cp ../src/murgaLuaLib.lua ../src/murgaLuaLib-temp.lua
echo "function getHostOsName () return \"$1\" end" >> murgaLuaLib-temp.lua

echo "const char murgaLuaLib_lua[] = { " > ../src/murgaLuaLib-temp.c
cat ../src/murgaLuaLib-temp.lua | ../bin/file2c >> ../src/murgaLuaLib-temp.c
echo -n ",00" >> ../src/murgaLuaLib-temp.c
echo " }; " >> ../src/murgaLuaLib-temp.c

echo "const char murgaLuaLib_copas[] = { " >> ../src/murgaLuaLib-temp.c
cat ../3rd-party/copas-1.1.1/src/copas/copas.lua | ../bin/file2c >> ../src/murgaLuaLib-temp.c
echo -n ",00" >> ../src/murgaLuaLib-temp.c
echo " }; " >> ../src/murgaLuaLib-temp.c

echo "const char murgaLuaLib_md5[] = { " >> ../src/murgaLuaLib-temp.c
sed "s/require\"md5.core\"/require\"md5\"/g" ../3rd-party/md5-1.1.1/src/md5.lua | ../bin/file2c >> ../src/murgaLuaLib-temp.c
echo -n ",00" >> ../src/murgaLuaLib-temp.c
echo " }; " >> ../src/murgaLuaLib-temp.c

rm ../src/murgaLuaLib-temp.lua
