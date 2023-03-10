#include "s21_matrix_oop.h"

#include <iostream>

S21Matrix::S21Matrix() {
  rows_ = 3;
  cols_ = 3;
  matrix_ = nullptr;
  S21Matrix::create_matrix();
}

S21Matrix::S21Matrix(int dimension) : rows_(dimension), cols_(dimension) {
  S21Matrix::create_matrix();
}

S21Matrix::S21Matrix(int rows, int cols) : rows_(rows), cols_(cols) {
  S21Matrix::create_matrix();
}

S21Matrix::S21Matrix(const S21Matrix& other) {
  rows_ = other.rows_;
  cols_ = other.cols_;
  create_matrix();
  for (int i = 0; i < rows_ * cols_; i++) {
    matrix_[i] = other.matrix_[i];
  }
}

S21Matrix::S21Matrix(S21Matrix&& other) {
  std::swap(rows_, other.rows_);
  std::swap(cols_, other.cols_);
  std::swap(matrix_, other.matrix_);
}

S21Matrix::~S21Matrix() {
  delete matrix_;
  rows_ = 0;
  cols_ = 0;
}

/* Operators */
double& S21Matrix::operator()(int i, int j) {
  if (matrix_) {  // Perhaps unnecessary check due to exception in constructor
    if (i > rows_ || j > cols_ || i < 0 || j < 0) {
      throw std::out_of_range("Wrong matrix index");
    }
    return matrix_[(j - 1) + (i - 1) * cols_];
  } else {
    throw std::invalid_argument("Uninitialized matrix");
  }
}

/* Extra methods */

void S21Matrix::PrintMatrix() {
  for (int rows = 0; rows < rows_; rows++) {
    for (int cols = 0; cols < cols_; cols++) {
      std::cout << matrix_[cols + rows * cols_]; 
      if (cols < cols_ - 1) { std::cout << " "; }
    }
    if (rows < rows_ - 1) { std::cout << std::endl; } 
  }
}

/* Private methods */

void S21Matrix::create_matrix() {
  if (rows_ <= 0 || cols_ <= 0) {
    throw std::bad_array_new_length();
  }
  matrix_ = new double[rows_ * cols_]();
  if (!matrix_) {
    throw std::bad_alloc();
  }
}
