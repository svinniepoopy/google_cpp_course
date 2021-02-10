#include <iostream>

int gcd(int a, int b) {
  if (a<=0) {
    return b;
  }
  if (a>b) {
    return gcd(a-b, b);
  }
  return gcd(b-a, a);
}

int main() {
  std::cout << gcd(5,9) << '\n';
  return 0;
}
