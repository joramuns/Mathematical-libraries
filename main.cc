#include <iostream>

#include "s21_matrix_oop.h"

int main() {
  S21Matrix c(5, 3);
  for (int i = 1; i <= 5; i++) {
    for (int j = 1; j <= 3; j++) {
      c(i, j) = 1;
    }
  }
  S21Matrix a(3, 5);
  a(3, 5) = 3;
  S21Matrix b(a);
  b(3, 1) = 18;
  a.SubMatrix(b);
  b.MulNumber(9);
  c.SumMatrix(a);
  std::cout << "First matrix:" << std::endl;
  a.PrintMatrix();
  std::cout << std::endl << "Second matrix:" << std::endl;
  b.PrintMatrix();
  std::cout << std::endl << "Third matrix:" << std::endl;
  c.PrintMatrix();
  c.MulMatrix(a);
  std::cout << std::endl << "Third matrix:" << std::endl;
  c.PrintMatrix();
  std::cout << std::endl << "Method check: " << a.EqMatrix(b) << std::endl;
  std::cout << std::endl << "Operator check: " << (a == b) << std::endl;
  return 0;
}
