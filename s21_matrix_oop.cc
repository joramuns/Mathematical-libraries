#include "s21_matrix_oop.h"

S21Matrix::S21Matrix() {
  rows_ = 0;
  cols_ = 0;
  matrix_ = nullptr;
}

S21Matrix::S21Matrix(int dimension) : rows_(dimension), cols_(dimension) {
  matrix_ = new double*[rows_*cols_];
}

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {

}
