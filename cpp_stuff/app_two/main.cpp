#include <iostream>

/*
Show that newer versions of c++ prefer sized deletes.

g++ -std=c++11 -g3 -O0 -Wall main.cpp -o ./x64/Debug/app_two.exe && ./x64/Debug/app_two.exe
  objdump -d -C  ./x64/Debug/app_two.exe | grep "<main>:" -A 30 | grep "call"
g++ -std=c++17 -g3 -O0 -Wall main.cpp -o ./x64/Debug/app_two.exe && ./x64/Debug/app_two.exe
  objdump -d -C  ./x64/Debug/app_two.exe | grep "<main>:" -A 30 | grep "call"
*/

struct Ball {
  int value;
  ~Ball() {}
};

void* operator new[](size_t size) {
  std::cout << "Custom allocator: new: \n";
  void* p = std::malloc(size);
  if (!p) throw std::bad_alloc();
  return p;
}

void operator delete[](void* p) noexcept {
  std::cout << "Custom allocator: delete: \n";
  std::free(p);
}

int main() {
  Ball* myArr = new Ball[5];
  delete[] myArr;
  return 0;
}

