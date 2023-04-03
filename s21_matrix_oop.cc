#include "s21_matrix_oop.h"
#define TOL 1e-06

/* Constructors and destructors */
S21Matrix::S21Matrix() : matrix_(nullptr), rows_(0), cols_(0) {}

S21Matrix::S21Matrix(const int dimension) : rows_(dimension), cols_(dimension) {
  S21Matrix::CreateMatrix();
}

S21Matrix::S21Matrix(const int rows, const int cols)
    : rows_(rows), cols_(cols) {
  S21Matrix::CreateMatrix();
}

S21Matrix::S21Matrix(const S21Matrix& other)
    : rows_(other.rows_), cols_(other.cols_) {
  CopyMatrix(other);
}

S21Matrix::S21Matrix(S21Matrix&& other) noexcept
    : matrix_(other.matrix_), rows_(other.rows_), cols_(other.cols_) {
  other.rows_ = 0;
  other.cols_ = 0;
  other.matrix_ = nullptr;
}

S21Matrix::~S21Matrix() { DeleteMatrix(); }

/* Methods */
bool S21Matrix::EqMatrix(const S21Matrix& other) noexcept {
  bool result = CheckMatrixDimension(other);
  for (int i = 0; i < rows_ * cols_ && result; i++) {
    if (std::fabs(matrix_[i] - other.matrix_[i]) >= TOL) result = false;
  }

  return result;
}

void S21Matrix::SumMatrix(const S21Matrix& other) {
  if (CheckMatrixDimension(other))
    SimpleMath(other, kSum);
  else
    throw std::invalid_argument(
        "No mathematical operations on matrices with different sizes");
}

void S21Matrix::SubMatrix(const S21Matrix& other) {
  if (CheckMatrixDimension(other))
    SimpleMath(other, kSub);
  else
    throw std::invalid_argument(
        "No mathematical operations on matrices with different sizes");
}

void S21Matrix::MulNumber(const double num) {
  if (!matrix_)
    throw std::invalid_argument("Empty matrix cannot be multiplied");
  for (int i = 0; i < rows_ * cols_; i++) {
    matrix_[i] *= num;
  }
}

void S21Matrix::MulMatrix(const S21Matrix& other) {
  if (cols_ != other.rows_ || !matrix_ || !other.matrix_)
    throw std::invalid_argument("Incompatible sizes of matrices");
  S21Matrix temp(rows_, other.cols_);
  for (int rows = 0; rows < temp.rows_; rows++) {
    for (int cols = 0; cols < temp.cols_; cols++) {
      for (int i = 0; i < cols_; i++) {
        temp.matrix_[cols + rows * temp.cols_] +=
            matrix_[i + rows * cols_] * other.matrix_[cols + i * other.cols_];
      }
    }
  }
  *this = std::move(temp);
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

S21Matrix S21Matrix::CalcComplements() {
  if (!CheckSquareMatrix())
    throw std::invalid_argument(
        "The matrix size is not compatible with CalcCompelements");
  S21Matrix result(cols_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      int sign = (i + j) % 2 ? -1 : 1;
      result.matrix_[j + i * cols_] = sign * Minor(i, j).Determinant();
    }
  }
  return result;
}

double S21Matrix::Determinant() {
  if (!CheckSquareMatrix())
    throw std::invalid_argument(
        "The matrix size is not compatible with Determinant");
  double result = 1.0;

  S21Matrix triangular_matrix = Triangular();
  for (int i = 0; i < cols_; i++) {
    result *= triangular_matrix.matrix_[i + i * cols_];
  }
  return result;
}

S21Matrix S21Matrix::InverseMatrix() {
  double det = Determinant();
  if (!det)
    throw std::invalid_argument(
        "The determinant is 0, the matrix is not invertible");
  S21Matrix result = CalcComplements().Transpose();
  for (int i = 0; i < cols_ * rows_; i++) {
    result.matrix_[i] /= det;
  }
  return result;
}

/* Operators */
S21Matrix S21Matrix::operator+(const S21Matrix& other) {
  S21Matrix result(*this);
  result.SumMatrix(other);
  return result;
}

S21Matrix S21Matrix::operator*(const double num) {
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

S21Matrix operator*(const double number, const S21Matrix& other) {
  S21Matrix result(other);
  result.MulNumber(number);
  return result;
}

bool S21Matrix::operator==(const S21Matrix& other) noexcept {
  return EqMatrix(other);
}

void S21Matrix::operator=(const S21Matrix& other) {
  if (matrix_ && matrix_ != other.matrix_) {
    DeleteMatrix();
    rows_ = other.rows_;
    cols_ = other.cols_;
    CopyMatrix(other);
  }
}

S21Matrix S21Matrix::operator+=(const S21Matrix& other) {
  SumMatrix(other);
  return *this;
}

S21Matrix S21Matrix::operator-=(const S21Matrix& other) {
  SubMatrix(other);
  return *this;
}

S21Matrix S21Matrix::operator*=(const double num) {
  MulNumber(num);
  return *this;
}

S21Matrix S21Matrix::operator*=(const S21Matrix& other) {
  MulMatrix(other);
  return *this;
}

double& S21Matrix::operator()(const int i, const int j) {
  if (i >= rows_ || j >= cols_ || i < 0 || j < 0) {
    throw std::out_of_range("Wrong matrix index");
  }
  return matrix_[j + i * cols_];
}

double S21Matrix::operator()(const int i, const int j) const {
  if (i >= rows_ || j >= cols_ || i < 0 || j < 0) {
    throw std::out_of_range("Wrong matrix index");
  }
  return matrix_[j + i * cols_];
}

/* Accessors and mutators */
int S21Matrix::get_rows() const { return rows_; }

int S21Matrix::get_cols() const { return cols_; }

void S21Matrix::set_rows(const int n) {
  S21Matrix new_matrix(n, cols_);
  FillContent(new_matrix);
  *this = new_matrix;
}

void S21Matrix::set_cols(const int n) {
  S21Matrix new_matrix(rows_, n);
  FillContent(new_matrix);
  *this = new_matrix;
}

void S21Matrix::CreateMatrix() {
  if (rows_ <= 0 || cols_ <= 0) {
    throw std::bad_array_new_length();
  }
  matrix_ = new double[rows_ * cols_]();
  if (!matrix_) {
    throw std::bad_alloc();
  }
}

void S21Matrix::FillContent(const S21Matrix& other) {
  for (int i = 0; i < cols_ && i < other.cols_; i++) {
    for (int j = 0; j < rows_ && j < other.rows_; j++) {
      other.matrix_[i + j * other.cols_] = matrix_[i + j * cols_];
    }
  }
}

void S21Matrix::CopyMatrix(const S21Matrix& other) {
  CreateMatrix();
  std::memcpy(matrix_, other.matrix_, sizeof(double) * rows_ * cols_);
}

bool S21Matrix::CheckMatrixDimension(const S21Matrix& other) {
  return (rows_ == other.rows_ && cols_ == other.cols_ && matrix_ &&
          other.matrix_)
             ? true
             : false;
}

bool S21Matrix::CheckSquareMatrix() {
  return (rows_ == cols_ && matrix_) ? true : false;
}

void S21Matrix::SimpleMath(const S21Matrix& other, const int option) {
  for (int i = 0; i < rows_ * cols_; i++) {
    if (option == kSum)
      matrix_[i] += other.matrix_[i];
    else if (option == kSub)
      matrix_[i] -= other.matrix_[i];
  }
}

void S21Matrix::DeleteMatrix() {
  if (matrix_) {
    delete[] matrix_;
    matrix_ = nullptr;
    rows_ = 0;
    cols_ = 0;
  }
}

void S21Matrix::SwapRows(const int source, const int dest) {
  if (source >= rows_ || source < 0 || dest >= rows_ || dest < 0) {
    throw std::out_of_range("Wrong matrix index");
  }
  double* temp = new double[cols_]();
  for (int i = 0; i < cols_; i++) {
    temp[i] = matrix_[i + dest * cols_];
    matrix_[i + dest * cols_] = matrix_[i + source * cols_];
    matrix_[i + source * cols_] = -temp[i];
  }
  delete[] temp;
}

S21Matrix S21Matrix::Triangular() {
  S21Matrix result(*this);
  int h = 0;                       /* Initialization of the pivot row */
  int k = 0;                       /* Initialization of the pivot column */
  while (h < rows_ && k < cols_) { /* Find the k-th pivot: */
    int i_max = 0;
    double elem_max = 0.0;
    for (int i = h; i < rows_; i++) {
      if (std::fabs(result.matrix_[k + i * cols_]) > std::fabs(elem_max)) {
        elem_max = result.matrix_[k + i * cols_];
        i_max = i;
      }
    }
    if (std::fabs(result.matrix_[k + i_max * cols_]) <
        TOL) { /* No pivot in this column, pass to next column */
      k++;
    } else {
      if (h != i_max)
        result.SwapRows(h, i_max); /* Do for all rows below pivot: */
      for (int i = h + 1; i < rows_; i++) {
        double temp_el =
            result.matrix_[k + i * cols_] / result.matrix_[k + h * cols_];
        if (std::fabs(temp_el) < TOL)
          temp_el = 0.0; /* Fill with zeros the lower part of pivot column: */
        result.matrix_[k + i * cols_] =
            0.0; /* Do for all remaining elements in current row: */
        for (int j = k + 1; j < cols_; j++) {
          result.matrix_[j + i * cols_] -=
              result.matrix_[j + h * cols_] * temp_el;
          if (std::fabs(result.matrix_[j + i * cols_]) < TOL)
            result.matrix_[j + i * cols_] =
                0.0; /* Increase pivot row and column */
        }
      }
      h++;
      k++;
    }
  }
  return result;
}

S21Matrix S21Matrix::Minor(const int x_i, const int x_j) {
  S21Matrix result(rows_ - 1, cols_ - 1);
  int new_i = 0;
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      if (i != x_i && j != x_j) {
        result.matrix_[new_i] = matrix_[j + i * cols_];
        new_i++;
      }
    }
  }
  return result;
}
