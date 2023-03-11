#include "s21_matrix_oop.h"

#include <iostream>

/* Constructors and destructors */
S21Matrix::S21Matrix() {
  rows_ = 0;
  cols_ = 0;
  matrix_ = nullptr;
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
  copy_matrix(other);
}

S21Matrix::S21Matrix(S21Matrix&& other) {
  std::swap(rows_, other.rows_);
  std::swap(cols_, other.cols_);
  std::swap(matrix_, other.matrix_);
}

S21Matrix::~S21Matrix() { delete_matrix(); }

/* Methods */
bool S21Matrix::EqMatrix(const S21Matrix& other) {
  bool result = check_matrix_dimension(other);
  if (result) {
    for (int i = 0; i < rows_ * cols_; i++) {
      if (matrix_[i] != other.matrix_[i]) result = false;
    }
  }

  return result;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (check_matrix_dimension(other)) {
    for (int i = 0; i < rows_ * cols_; i++) {
      matrix_[i] += other.matrix_[i];
    }
  }
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (check_matrix_dimension(other)) {
    for (int i = 0; i < rows_ * cols_; i++) {
      matrix_[i] -= other.matrix_[i];
    }
  }
}

void S21Matrix::MulNumber(const double num) {
  if (matrix_) {
    for (int i = 0; i < rows_ * cols_; i++) {
      matrix_[i] *= num;
    }
  }
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (cols_ == other.rows_ && matrix_ && other.matrix_) {
    S21Matrix temp(rows_, other.cols_);
    for (int rows = 0; rows < temp.rows_; rows++) {
      for (int cols = 0; cols < temp.cols_; cols++) {
        for (int i = 0; i < cols_; i++) {
          temp.matrix_[cols + rows * temp.cols_] +=
              matrix_[cols + i * cols_] * other.matrix_[cols + i * other.cols_];
        }
      }
    }
    *this = temp;
  }
}

S21Matrix S21Matrix::Transpose() {
  S21Matrix result(cols_, rows_);
  for (int rows = 0; rows < result.rows_; rows++) {
    for (int cols = 0; cols < result.cols_; cols++) {
      result.matrix_[cols + rows * result.cols_] = matrix_[rows + cols * cols_];
    }
  }
  return result;
}

/* S21Matrix S21Matrix::CalcComplements() {} */

double S21Matrix::Determinant() {
  double result = 1.0;
  for (int dimension = 1; dimension < cols_; dimension++) {
    for (int rows = dimension; rows < rows_; rows++) {
      double temp_el = matrix_[(dimension - 1) + rows * cols_] / matrix_[(dimension - 1) + (dimension - 1) * cols_];
      for (int cols = (dimension - 1); cols < cols_; cols++) {
        matrix_[cols + rows * cols_] -= matrix_[cols + (dimension - 1) * cols_] * temp_el;
      }
    }
  }
  /* for (int rows = 2; rows < cols_; rows++) { */
  /*   double temp_el = matrix_[1 + rows * cols_] / matrix_[1 + 1 * cols_]; */
  /*   for (int cols = 1; cols < cols_; cols++) { */
  /*     matrix_[cols + rows * cols_] -= matrix_[cols + 1 * cols_] * temp_el; */
  /*   } */
  /* } */
  for (int i = 0; i < cols_; i++) {
    result *= matrix_[i + i * cols_];
  }
  return result;
}

/* S21Matrix S21Matrix::InverseMatrix() {} */

/* Operators */
/* S21Matrix S21Matrix::operator+(S21Matrix& other) {} */

/* S21Matrix S21Matrix::operator-(S21Matrix& other) {} */

/* S21Matrix S21Matrix::operator*(S21Matrix& other) {} */

bool S21Matrix::operator==(const S21Matrix& other) { return EqMatrix(other); }

void S21Matrix::operator=(const S21Matrix& other) {
  if (matrix_) {
    delete_matrix();
  }
  rows_ = other.rows_;
  cols_ = other.cols_;
  copy_matrix(other);
}

/* S21Matrix S21Matrix::operator+=(S21Matrix& other) {} */

/* S21Matrix S21Matrix::operator-=(S21Matrix& other) {} */

/* S21Matrix S21Matrix::operator*=(S21Matrix& other) {} */

/* friend S21Matrix S21Matrix::operator*(S21Matrix& other, double& number) {} */

/* friend S21Matrix S21Matrix::operator*(double& number, S21Matrix& other) {} */

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
      if (cols < cols_ - 1) {
        std::cout << " ";
      }
    }
    if (rows < rows_ - 1) {
      std::cout << std::endl;
    }
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

void S21Matrix::copy_matrix(const S21Matrix& other) {
  create_matrix();
  for (int i = 0; i < rows_ * cols_; i++) {
    matrix_[i] = other.matrix_[i];
  }
}

bool S21Matrix::check_matrix_dimension(const S21Matrix& other) {
  return (rows_ == other.rows_ && cols_ == other.cols_ && matrix_ &&
          other.matrix_)
             ? true
             : false;
}

void S21Matrix::delete_matrix() {
  if (matrix_) {
    delete[] matrix_;
    rows_ = 0;
    cols_ = 0;
  }
}
