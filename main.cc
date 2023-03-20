#include <iostream>

#include "s21_matrix_oop.h"

int main() {
  S21Matrix c(9);
  /* double content = 9; */
  /* for (int i = 1; i <= 3; i++) { */
  /*   for (int j = 1; j <= 3; j++) { */
  /*     c(i, j) = content++; */
  /*   } */
  /* } */
  c(0, 0) = 9;
  c(1, 0) = 7;
  c(2, 0) = 9;
  c(3, 0) = 4;
  c(4, 0) = 1;
  c(5, 0) = 0;
  c(6, 0) = 2;
  c(7, 0) = 5;
  c(8, 0) = 8;
  c(0, 1) = 8;
  c(1, 1) = 7;
  c(2, 1) = 2;
  c(3, 1) = 3;
  c(4, 1) = 3;
  c(5, 1) = 1;
  c(6, 1) = 7;
  c(7, 1) = 8;
  c(8, 1) = 9;
  c(0, 2) = 7;
  c(1, 2) = 7;
  c(2, 2) = 6;
  c(3, 2) = 0;
  c(4, 2) = 5;
  c(5, 2) = 8;
  c(6, 2) = 1;
  c(7, 2) = 0;
  c(8, 2) = 9;
  c(0, 3) = 9;
  c(1, 3) = 3;
  c(2, 3) = 9;
  c(3, 3) = 0;
  c(4, 3) = 9;
  c(5, 3) = 6;
  c(6, 3) = 9;
  c(7, 3) = 5;
  c(8, 3) = 1;
  c(0, 4) = 9;
  c(1, 4) = 2;
  c(2, 4) = 5;
  c(3, 4) = 7;
  c(4, 4) = 0;
  c(5, 4) = 3;
  c(6, 4) = 7;
  c(7, 4) = 4;
  c(8, 4) = 5;
  c(0, 5) = 5;
  c(1, 5) = 6;
  c(2, 5) = 0;
  c(3, 5) = 0;
  c(4, 5) = 1;
  c(5, 5) = 6;
  c(6, 5) = 4;
  c(7, 5) = 7;
  c(8, 5) = 7;
  c(0, 6) = 7;
  c(1, 6) = 2;
  c(2, 6) = 8;
  c(3, 6) = 3;
  c(4, 6) = 2;
  c(5, 6) = 8;
  c(6, 6) = 6;
  c(7, 6) = 8;
  c(8, 6) = 3;
  c(0, 7) = 2;
  c(1, 7) = 9;
  c(2, 7) = 9;
  c(3, 7) = 5;
  c(4, 7) = 4;
  c(5, 7) = 8;
  c(6, 7) = 6;
  c(7, 7) = 2;
  c(8, 7) = 6;
  c(0, 8) = 7;
  c(1, 8) = 1;
  c(2, 8) = 2;
  c(3, 8) = 8;
  c(4, 8) = 3;
  c(5, 8) = 2;
  c(6, 8) = 3;
  c(7, 8) = 6;
  c(8, 8) = 9;
  /* S21Matrix a(3, 5); */
  /* a(3, 5) = 3; */
  /* a(1, 3) = 8; */
  /* S21Matrix b(a); */
  /* b(3, 1) = 4; */
  /* a.SubMatrix(b); */
  /* b.MulNumber(9); */
  /* c.SumMatrix(a); */
  /* std::cout << "Matrix A:" << std::endl; */
  /* a.PrintMatrix(); */
  /* std::cout << std::endl << "Matrix B:" << std::endl; */
  /* b.PrintMatrix(); */
  std::cout << std::endl << "Matrix C:" << std::endl;
  c.PrintMatrix();
  std::cout << std::endl << c.null_det();
  /* c.MulMatrix(b); */
  /* std::cout << std::endl << "Matrix C*B:" << std::endl; */
  /* c.PrintMatrix(); */
  /* S21Matrix d = b.Transpose(); */
  /* std::cout << std::endl << "Matrix D, B transposed:" << std::endl; */
  /* d.PrintMatrix(); */
  /* S21Matrix e = d.Transpose(); */
  /* std::cout << std::endl << "Matrix E, D transposed:" << std::endl; */
  /* e.PrintMatrix(); */
  double edet = c.Determinant();
  std::cout << std::endl << " Determinant matrix C test: " << edet << std::endl;
  /* c.PrintMatrix(); */
  /* std::cout << std::endl; */
  /* std::cout << std::endl << "Method check: " << a.EqMatrix(b) << std::endl; */
  /* std::cout << std::endl << "Operator check: " << (a == b) << std::endl; */
  return 0;
}

/* 9 7 9 4 1 0 2 5 8 */
/* 8 7 2 3 3 1 7 8 9 */
/* 7 7 6 0 5 8 1 0 9 */
/* 9 3 9 0 9 6 9 5 1 */
/* 9 2 5 7 0 3 7 4 5 */
/* 5 6 0 0 1 6 4 7 7 */
/* 7 2 8 3 2 8 6 8 3 */
/* 2 9 9 5 4 8 6 2 6 */
/* 7 1 2 8 3 2 3 6 9 */
