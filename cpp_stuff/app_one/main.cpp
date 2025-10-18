#include <iostream>

/* run;
msbuild app_one.vcxproj -p:Platform=x64 -p:Configuration=Debug -warnAsError
./x64/Debug/app_one.exe
*/

int main() {
  std::cout << "Hello";
  return 0;
}
