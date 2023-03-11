#include <iostream>

#include "s21_matrix_oop.h"

int main() {
  S21Matrix a(9, 12);
  S21Matrix b(9, 12);
  a(9, 11) = 9;
  b(9, 11) = 8;
  std::cout << "First matrix:" << std::endl;
  a.PrintMatrix();
  std::cout << std::endl << "Second matrix:" << std::endl;
  b.PrintMatrix();
  std::cout << std::endl << "Method check: " << a.EqMatrix(b) << std::endl;
  std::cout << std::endl << "Operator check: " << (a == b) << std::endl;
  return 0;
}
