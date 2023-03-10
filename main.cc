#include "s21_matrix_oop.h"

#include <iostream>

int main() {
  S21Matrix a(9, 12);
  a(9, 13) = 9;
  a.PrintMatrix();
  return 0;
}
