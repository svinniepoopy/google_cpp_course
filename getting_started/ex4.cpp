#include <iostream>
#include <cstdlib>

int main() {

  int input_val;
  bool reset = false;
  srand(time(NULL));	
  const int secret_num = rand()%100+1;
  do {
    std::cout << "Guess the secret number (-1 to quit): ";
    if (!(std::cin>>input_val)) {
      if (std::cin.eof()) {
	std::cout << "EOF reached\n";
	break;
      }
      std::cout << "Enter a valid number between 0-100:\n";
      std::cin.clear();
      std::cin.ignore(1000, '\n');
    } else {
      if (input_val == -1) {
	break;
      }
      if (input_val==secret_num) {
	std::cout << "GUESS CORRECT!\n";
	break;
      }
      if (input_val > secret_num) {
	std::cout << "Too high!\n";
      } else {
	std::cout << "Too low\n";
      }
    }
  } while (input_val != -1);
  std::cout << "Secret number: " << secret_num << '\n';
  return 0;
}
