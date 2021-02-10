// file processing
// in a file name, insert a list of names (first and last)
// when done, display file data
#include <fstream> // basic_ifstream, basic_ofstream
#include <iostream> // cout, cerr
#include <string> // string, getline

int main() {
  std::cout << "Enter filename: ";
  std::string file_name;
  if (!(std::cin>>file_name)) {
    std::cerr << "Invalid file name" << std::endl;
    return -1;
  }

  std::ofstream ofs{file_name, std::ios::out};
  if (!ofs.is_open()) {
    std::cerr << "Error opening file for output\n";
    return -1;
  }

  std::string first_name, last_name;
  do {
    std::cout << "Enter first name and last name separated by a space (' '): ";
    if (!(std::cin >> first_name) || !(std::cin >> last_name)) {
      if (std::cin.eof()) {
	break;
      }
      std::cin.clear();
      std::cin.ignore(1000, '\n');
    } else {
      std::string out_data = first_name + "," + last_name + "\n";
      ofs.write(out_data.c_str(), out_data.size());
   }
  } while (!std::cin.eof());

  ofs.close();

  std::ifstream ifs{file_name, std::ios::in};
  if (!ifs.is_open()) {
    std::cerr << "Error opening file " << file_name << " for reading\n";
    return -1;
  }

  std::string data; 
  while (!ifs.eof()) {
    std::getline(ifs, data);
    std::cout << data; 
  }

  return 0;

}
