#include <iostream>

int GetInput() {
  std::cout << "Enter numbre of units sold per week: ";
  int n;
  if (!(std::cin >> n)) {
    return -1;
  }
  return n;
}

// straight salary of $600 per week
void CalcMethod1(int weekly_sales) {
  std::cout << "You will earn $600/week\n"; 
}

// salary of $7/hour + 10% commission on sales
void CalcMethod2(int weekly_sales) {
  int weekly_salary = 7*40;
  int total_salary = 0.10*weekly_sales*225 + weekly_salary;
  std::cout << "You will earn " << total_salary << '\n';
}

// 20% commission and $20 for each shoe sold
void CalcMethod3(int weekly_sales, int nsold) {
  std::cout << "You will earn " << 0.20*weekly_sales*225 +20*nsold << '\n';
}

int main() {
  int weekly_sales;
  if ((weekly_sales = GetInput()) < 0) {
    std::cerr << "Bad input\n";
    return -1;
  }
  CalcMethod1(weekly_sales);
  CalcMethod2(weekly_sales);
  CalcMethod3(weekly_sales, 10);

  return 0;
}
