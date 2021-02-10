
#include <iomanip> // setw
#include <iostream> // cout 
#include <string> 

int main() {
  std::string s{"hello world"};
  for (int i=0;i<6;++i) {
    for (int j=0;j<4;++j) {
      std::cout << std::left << std::setw(17) << s << " ";
    }
    std::cout << std::endl;
  }
  return 0;
}

