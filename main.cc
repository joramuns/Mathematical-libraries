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
  a(1, 3) = 8;
  S21Matrix b(a);
  b(3, 1) = 4;
  /* a.SubMatrix(b); */
  /* b.MulNumber(9); */
  /* c.SumMatrix(a); */
  std::cout << "Matrix A:" << std::endl;
  a.PrintMatrix();
  std::cout << std::endl << "Matrix B:" << std::endl;
  b.PrintMatrix();
  std::cout << std::endl << "Matrix C:" << std::endl;
  c.PrintMatrix();
  c.MulMatrix(b);
  std::cout << std::endl << "Matrix C*B:" << std::endl;
  c.PrintMatrix();
  S21Matrix d = b.Transpose();
  std::cout << std::endl << "Matrix D, B transposed:" << std::endl;
  d.PrintMatrix();
  S21Matrix e = d.Transpose();
  std::cout << std::endl << "Matrix E, D transposed:" << std::endl;
  e.PrintMatrix();
  std::cout << std::endl << "Method check: " << a.EqMatrix(b) << std::endl;
  std::cout << std::endl << "Operator check: " << (a == b) << std::endl;
  return 0;
}
