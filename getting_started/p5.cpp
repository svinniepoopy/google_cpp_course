
#include <iostream>

int reverse(int n) {
  if (n<9) {
     return n;
  }
  int rev_n = 0;
  while (n) {
    int last = n%10;
    rev_n = rev_n*10 + last;
    n = n/10;
  }
  return rev_n;
}

int magicNumber(int n) {
  int rev_n = reverse(n);
  int sub = n - rev_n;
  int rev_sub = reverse(sub);
  return rev_sub + sub;
}

int main() {
  std::cout << magicNumber(901) << std::endl;

  return 0;
}
