#include "s21_matrix_oop.h"

#include <iostream>
#include <cmath>
#include <limits>
#include <cstring>

#define TOL std::numeric_limits<double>::epsilon()
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
  if (check_matrix_dimension(other)) simple_math(other, SUM);
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (check_matrix_dimension(other)) simple_math(other, SUB);
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
              matrix_[i + rows * cols_] * other.matrix_[cols + i * other.cols_];
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

  S21Matrix triangular_matrix(*this);
  triangular_matrix.triangular();
  for (int i = 0; i < cols_; i++) {
    result *= triangular_matrix.matrix_[i + i * cols_];
  }
  return result;
}

/* S21Matrix S21Matrix::InverseMatrix() {} */

/* Operators */
S21Matrix S21Matrix::operator+(const S21Matrix& other) {
  S21Matrix result(*this);
  result.SumMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator*(const double& num) {
  S21Matrix result(*this);
  result.MulNumber(num);
  return result;
}

S21Matrix S21Matrix::operator-(const S21Matrix& other) {
  S21Matrix result(*this);
  result.SubMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator*(const S21Matrix& other) {
  S21Matrix result(*this);
  result.MulMatrix(other);
  return result;
}

bool S21Matrix::operator==(const S21Matrix& other) { return EqMatrix(other); }

void S21Matrix::operator=(const S21Matrix& other) {
  if (matrix_) {
    delete_matrix();
  }
  rows_ = other.rows_;
  cols_ = other.cols_;
  copy_matrix(other);
}

S21Matrix S21Matrix::operator+=(const S21Matrix& other) {
  SumMatrix(other);
  return *this;
}

S21Matrix S21Matrix::operator-=(const S21Matrix& other) {
  SubMatrix(other);
  return *this;
}

S21Matrix S21Matrix::operator*=(const double& num) {
  MulNumber(num);
  return *this;
}

S21Matrix S21Matrix::operator*=(const S21Matrix& other) {
  MulMatrix(other);
  return *this;
}

/* friend S21Matrix S21Matrix::operator*(S21Matrix& other, double& number) {} */

/* friend S21Matrix S21Matrix::operator*(double& number, S21Matrix& other) {} */

double& S21Matrix::operator()(int i, int j) {
  if (matrix_) {  // Perhaps unnecessary check due to exception in constructor
    if (i >= rows_ || j >= cols_ || i < 0 || j < 0) {
      throw std::out_of_range("Wrong matrix index");
    }
    return matrix_[j + i * cols_];
  } else {
    throw std::invalid_argument("Uninitialized matrix");
  }
}

/* Accessors and mutators */
int S21Matrix::getRows() { return rows_; }

int S21Matrix::getCols() { return cols_; }

void S21Matrix::setRows(int n) {
  S21Matrix new_matrix(n, cols_);
  new_matrix.fill_content(*this);
  
  *this = new_matrix;
}

void S21Matrix::setCols(int n) {
  S21Matrix new_matrix(rows_, n);
  new_matrix.fill_content(*this);
  
  *this = new_matrix;
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
    std::cout << std::endl;
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

void S21Matrix::fill_content(const S21Matrix& other) {
  for (int i = 0; i < cols_ && i < other.cols_; i++) {
     for (int j = 0; j < rows_ && j < other.rows_; j++) {
       matrix_[i + j * cols_] = other.matrix_[i + j * other.cols_];
     }
  }
}

void S21Matrix::copy_matrix(const S21Matrix& other) {
  create_matrix();
  std::memcpy(matrix_, other.matrix_, sizeof (double) * rows_ * cols_);
  /* for (int i = 0; i < rows_ * cols_; i++) { */
  /*   matrix_[i] = other.matrix_[i]; */
  /* } */
}

bool S21Matrix::check_matrix_dimension(const S21Matrix& other) {
  return (rows_ == other.rows_ && cols_ == other.cols_ && matrix_ &&
          other.matrix_)
             ? true
             : false;
}

void S21Matrix::simple_math(const S21Matrix& other, int option) {
  for (int i = 0; i < rows_ * cols_; i++) {
    if (option == SUM) matrix_[i] += other.matrix_[i];
    else if (option == SUB) matrix_[i] -= other.matrix_[i];
  }
}

void S21Matrix::delete_matrix() {
  if (matrix_) {
    delete[] matrix_;
    rows_ = 0;
    cols_ = 0;
  }
}

void S21Matrix::swap_rows(int source, int dest) {
  if (source >= rows_ || source < 0 || dest >= rows_ || dest < 0) {
    throw std::out_of_range("Wrong matrix index");
  }
  double temp[cols_];
  for (int i = 0; i < cols_; i++) {
    temp[i] = matrix_[i + dest * cols_];
    matrix_[i + dest * cols_] = matrix_[i + source * cols_];
    matrix_[i + source * cols_] = -temp[i];
  }
}

S21Matrix S21Matrix::triangular() {
  S21Matrix result(rows_);
  int h = 0; /* Initialization of the pivot row */
  int k = 0; /* Initialization of the pivot column */
  while (h < rows_ && k < cols_) {
    /* Find the k-th pivot: */ 
    int i_max = 0;
    double elem_max = 0.0;
    for (int i = h; i < rows_; i++) {
      if (std::fabs(matrix_[k + i * cols_]) > std::fabs(elem_max)) {
        elem_max = matrix_[k + i * cols_];
        i_max = i;
      }
    }
    if (std::fabs(matrix_[k + i_max * cols_]) < TOL) {
      /* No pivot in this column, pass to next column */
      k++;
    } else {
      if (h != i_max) swap_rows(h, i_max);
           /* Do for all rows below pivot: */
      for (int i = h + 1; i < rows_; i++) {
        double temp_el = matrix_[k + i * cols_] / matrix_[k + h * cols_];
        if (std::fabs(temp_el) < TOL) temp_el = 0.0;
               /* Fill with zeros the lower part of pivot column: */
        matrix_[k + i * cols_] = 0.0;
               /* Do for all remaining elements in current row: */
        for (int j = k + 1; j < cols_; j++) {
          matrix_[j + i * cols_] -= matrix_[j + h * cols_] * temp_el;
          if (std::fabs(matrix_[j + i * cols_]) < TOL) matrix_[j + i * cols_] = 0.0;
           /* Increase pivot row and column */
        }
      }
      h++;
      k++;
    }
  }
  return result;
}
