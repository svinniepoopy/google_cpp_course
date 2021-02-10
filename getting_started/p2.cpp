#include <iostream>

namespace {
  const int kAss = 4;
  char* kOrder[kAss]  = {"first", "second", "third", "fourth"};
}

float computeFinalGrade(int* a_grade, int m, int f, int s) {

  int total_ass = 0;
  for (int i=0;i<kAss;++i) {
    total_ass += a_grade[i];
  }
  total_ass = ((total_ass)/kAss)*0.4;
  float mid = (float)m*0.15;
  float final_g = (float)f*0.35;
  float partc = 0.1;

  return total_ass + mid + final_g + partc;
}
	

int main() {
  int a_grades[4] = {0};

  int grade;
  for (int i=0;i<4;++i) {
    std::cout << "Enter the score for the " << kOrder[i] << " assignment: ";
    std::cin >> grade;
    a_grades[i] = grade;
  }

  int grade_midterm;
  std::cout << "Enter the score for the midterm: ";
  std::cin >> grade_midterm;


  int grade_final;
  std::cout << "Enter the grade for the final: ";
  std::cin >> grade_final;

  int section_grade;
  std::cout << "Enter the score for the section grade: ";
  std::cin >> section_grade;

  float final_g = computeFinalGrade(a_grades, grade_midterm, grade_final, section_grade);
  std::cout << "The final grade is: " << final_g << std::endl;

  return 0;
}
