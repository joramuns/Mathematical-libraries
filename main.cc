#include <iostream>

#include "s21_matrix_oop.h"

int main() {
  S21Matrix c(4);
  /* double content = 9; */
  /* for (int i = 1; i <= 3; i++) { */
  /*   for (int j = 1; j <= 3; j++) { */
  /*     c(i, j) = content++; */
  /*   } */
  /* } */
  c(0, 0) = 1;
  c(1, 0) = 1;
  c(2, 0) = 1;
  c(3, 0) = 0;
  c(0, 1) = 1;
  c(1, 1) = 0;
  c(2, 1) = 0;
  c(3, 1) = 0;
  c(0, 2) = 1;
  c(1, 2) = 0;
  c(2, 2) = 0;
  c(3, 2) = 1;
  c(0, 3) = 1;
  c(1, 3) = 0;
  c(2, 3) = 1;
  c(3, 3) = 0;
  /* c(0, 0) = 9; */
  /* c(1, 0) = 8; */
  /* c(2, 0) = 7; */
  /* c(0, 1) = 7; */
  /* c(1, 1) = 7; */
  /* c(2, 1) = 7; */
  /* c(0, 2) = 9; */
  /* c(1, 2) = 2; */
  /* c(2, 2) = 6; */
  /* c(0, 0) = 2; */
  /* c(1, 0) = 1; */
  /* c(2, 0) = 1; */
  /* c(0, 1) = 2; */
  /* c(1, 1) = 1; */
  /* c(2, 1) = 1; */
  /* c(0, 2) = 7; */
  /* c(1, 2) = 7; */
  /* c(2, 2) = 6; */
  /* c(0, 0) = 1; */
  /* c(1, 0) = 3; */
  /* c(2, 0) = 2; */
  /* c(0, 1) = 2; */
  /* c(1, 1) = 2; */
  /* c(2, 1) = 4; */
  /* c(0, 2) = 3; */
  /* c(1, 2) = 8; */
  /* c(2, 2) = 9; */
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
// LOOP
/* 0 0 9 2 8 3 */
/* 1 8 6 7 9 0 */
/* 1 8 7 4 0 1 */
/* 4 8 6 3 0 6 */
/* 4 8 2 0 0 9 */
/* 1 2 5 7 5 9 */
// LOOP
/* 1 0 1 0 0 1 0 0 */
/* 1 0 0 0 0 1 1 1 */
/* 0 1 1 1 0 0 0 0 */
/* 1 1 0 0 0 0 1 0 */
/* 1 0 0 0 0 0 0 1 */
/* 1 1 1 0 0 1 0 1 */
/* 1 0 0 0 1 0 0 0 */
/* 1 0 0 1 1 1 0 1 */
// LOOP
/* 1 1 0 */
/* 0 0 0 */
/* 0 0 1 */
// LOOP
/* 0 0 0 */
/* 1 1 1 */
/* 1 1 0 */
// LOOP
/* 1 1 1 */
/* 1 1 1 */
/* 1 1 1 */
// zaLOOP
/* 2 2 7 */
/* 1 1 7 */
/* 1 1 6 */
/* Wrong */
/* 1 1 1 1 0 1 0 1 */
/* 1 1 0 0 1 1 0 0 */
/* 1 1 1 0 0 1 1 0 */
/* 1 1 0 0 1 0 1 1 */
/* 1 1 0 1 0 0 1 0 */
/* 1 1 1 1 1 0 1 0 */
/* 0 1 0 1 0 1 1 1 */
/* 0 1 0 0 0 1 1 0 */
/* Zero */
/* 1 1 1 1 */
/* 1 0 0 0 */
/* 1 0 0 1 */
/* 0 0 1 0 */
