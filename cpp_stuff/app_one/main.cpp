#include <iostream>

/* run;
windows:
  msbuild app_one.vcxproj -p:Platform=x64 -p:Configuration=Debug -warnAsError
  ./x64/Debug/app_one.exe

linux:
  cd build && cmake .. && make && cd ..
  ./build/app_one
*/

int add(int x, int y);

int main() {
  std::cout << add(2, 3);
  return 0;
}
