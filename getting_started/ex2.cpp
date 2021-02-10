#include <iostream>

int main() {
  int input_val=0;
  do {
    std::cout << "Enter a number (-1 == quit): ";
    if (!(std::cin>>input_val)) {
     
      // break out of the loop if eof was seen or while 
      // discarding characters via ignore() 
      if (std::cin.eof()) { 
	std::cout << "EOF reached\n";
	break;
      }
      // recover from error 
      std::cout << "not a digit\n";
      std::cin.clear();
      std::cin.ignore(10000, '\n');
    } else if (input_val!=-1) {
      std::cout << "you entered: " << input_val << '\n';
    }
  } while (input_val!=-1);
  std::cout << "All done.\n";
  return 0;
}
