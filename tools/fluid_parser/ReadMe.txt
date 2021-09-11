Hey folks, to build the fluid to lua converter simply cd (changedir) to the fluid_parser folder and do this:

On Windows:

gcc lex.yy.c -o fluidtolua.exe

On Unix/Mac OS X:

gcc lex.yy.c -o fluidtolua



To convert a fluid file to a lua script simply run the fluidtolua binary with two parameters: the path to the input fluid file and the path to the output lua file. The resulting .lua file should run in MurgaLua. Keep in mind that you need a code block that tells the window to show as seen in test.fl to actually show the window ;)

Example:

./fluidtolua test.fl test.lua