#include <iostream>

int chirpsToTemp(int chirp) {
  return (chirp+40)/4;
}

int main() {
  std::cout << "Temp is " << chirpsToTemp(120) << '\n';

  return 0;
}
