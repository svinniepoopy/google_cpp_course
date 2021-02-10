#include <iostream>

void displayTime(int seconds) {
  int h = seconds/3600;
  if (h>0) {
    seconds = seconds-h*3600;
  }
  int m = seconds/60;
  if (m>0) {
    seconds = seconds-m*60;
  }
  std::cout << "Hours: " << h << '\n';
  std::cout << "Minutes: " << m << '\n';
  std::cout << "Seconds: " << seconds << '\n';
}

int main() {
  displayTime(100000);
  return 0;
}
