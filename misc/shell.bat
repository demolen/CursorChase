:set VSINSTALLDIR=C:\Program Files\Microsoft Visual Studio\2022-17-16\Community\
:set VCINSTALLDIR=C:\Program Files\Microsoft Visual Studio\2022-17-16\Community\VC\
call "C:\Program Files (x86)\Microsoft GDK\Command Prompts\GamingDesktopVars.cmd" GamingDesktopVS2022 250401
:call "C:\Program Files\Microsoft Visual Studio\2022-17-16\Community\VC\Auxiliary\Build\vcvarsall.bat" x64
C:
cd c:\ChaseTheCursor\code
call "c:\ChaseTheCursor\misc\4coder\4ed.exe"
set path=c:\ChaseTheCursor\misc;%path%
