#include <iostream>
#include <climits>

// find if num is sum of digits 1..n
int isSumOfDigits(int num) {
  for (int i=1;i<num;++i) {
    int sum = i*(i+1)/2;
    if (sum == num) {
      return i;
    }
  }
  return -1;
}


void psquare() {
  int i=1;
  int kMaxIterations = INT_MAX;
  while (i<kMaxIterations) {
    int sq = i*i; 
    int s;
    if ((s = isSumOfDigits(sq))>0) {
      std::cout << "Found: " << sq << " " << s << std::endl;
    }
    ++i;
  }
}

int main() {
  psquare();
  return 0;
}
