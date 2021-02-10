
#include <iostream>

int main() {
  for (int h=0;h<100;++h) {
    for (int p=0;p<100;++p) {
      for (int r=0;r<100;++r) {
	if ((h*10 + r*3 + p*0.5) == 100) {
	  std::cout << "Found: " << h << ' ' << r << ' ' << p << std::endl; 
	}
      }
    }
  }
  return 0;
}
