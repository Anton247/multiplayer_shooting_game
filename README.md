# Multiplayer shooter in C++ on its own game engine

<h4>About:</h4>

Source code of simple shooter on [GameEngine](https://github.com/Anton247/multiplayer_shooting_game)

<h4>Installation:</h4>

<h4>Playing with a source code:</h4>

1) [Download and install OpenAL library](https://openal.org/downloads/) for SFML sound support (in current version you can't setup this engine without OpenAL)

2) Clone this repository

3) Open project
   
   Using [CLion](https://www.jetbrains.com/clion/) with [MinGW (32-bit)](https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win32/Personal%20Builds/mingw-builds/7.3.0/threads-posix/dwarf/i686-7.3.0-release-posix-dwarf-rt_v5-rev0.7z/download) compiler: open <b>CMakeList.txt</b> as a project

4) Built project and run the game


5) Write <b>ip</b> and <b>port</b> of server in <b>connect.txt</b> file.


6) Write <b>port</b> of the server in <b>server.txt</b> file (only for computer where the server will be running).


7) Enjoy gaming!

<h4>Control:</h4>

<b>Mouse</b>, <b>Space</b>, <b>A</b>, <b>S</b>, <b>W</b>, <b>D</b> – player control.

<b>SHIFT</b> – slow motion (this ability is not infinite: its bar is next to hp)

<b>E & Q </b> or keys <b> <- -> </b> – change weapon

<b>R</b> – recharge

<b>O</b> – turn OpenGL on/off

<b>Tab</b> – turn debug mode on/off