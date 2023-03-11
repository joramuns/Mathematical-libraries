#include <iostream>

#include "s21_matrix_oop.h"

int main() {
  S21Matrix c(12, 9);
  S21Matrix a(9, 12);
  a(9, 11) = 3;
  S21Matrix b(a);
  b(9, 11) = 18;
  a.SubMatrix(b);
  b.MulNumber(9);
  c.SumMatrix(a);
  c.MulMatrix(a);
  std::cout << "First matrix:" << std::endl;
  a.PrintMatrix();
  std::cout << std::endl << "Second matrix:" << std::endl;
  b.PrintMatrix();
  std::cout << std::endl << "Third matrix:" << std::endl;
  c.PrintMatrix();
  std::cout << std::endl << "Method check: " << a.EqMatrix(b) << std::endl;
  std::cout << std::endl << "Operator check: " << (a == b) << std::endl;
  return 0;
}
