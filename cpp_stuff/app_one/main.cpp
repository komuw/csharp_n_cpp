#include <iostream>
#include "add.h"

/* run;
windows:
  msbuild app_one.vcxproj -p:Platform=x64 -p:Configuration=Debug -warnAsError && ./x64/Debug/app_one.exe

linux:
  cd build && cmake .. && make && cd .. && ./build/app_one
    or
  g++ -std=c++14 -g3 -O0 -Wall main.cpp add.cpp -o ./build/app_one && ./build/app_one

to create dll:
  # https://nullprogram.com/blog/2021/05/31/
  # Use `w64devkit` terminal to run the commands.
  g++ -std=c++14 -g3 -O0 -Wall -shared -s add.cpp -o add.dll # you don't need to specify `add.h`
  g++ -std=c++14 -g3 -O0 -Wall -s main.cpp add.dll -o app_one.exe # use the dll.
  peports -i -e add.dll # to inspect the dll exports/imports. Also see `dumpbin /EXPORTS /IMPORTS /DEPENDENTS add.dll` in vs2019 dev cmd.

to debug:
  # Use `w64devkit` terminal to run the commands.
  # Also see: https://nullprogram.com/blog/2022/06/26/ for better assertion.
  g++ -std=c++14 -g3 -O0 -Wall main.cpp add.cpp -o ./x64/Debug/app_one.exe && ./x64/Debug/app_one.exe
  gdb --batch --ex 'b main' --ex run --ex bt --ex q ./x64/Debug/app_one.exe
*/


int main() {
  std::cout << add(2, 3);
  return 0;
}
