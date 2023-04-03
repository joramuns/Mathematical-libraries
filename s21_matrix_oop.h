#ifndef SRC_S21_MATRIX_OOP_H_
#define SRC_S21_MATRIX_OOP_H_

#include <cmath>
#include <cstring>
#include <iostream>
#include <limits>

class S21Matrix {
 public:
  /* Constructors and destructors */
  S21Matrix();                               // basic constructor
  explicit S21Matrix(const int dimension);  // constructor for square matrices
  S21Matrix(const int rows, const int cols);  // parametrized constructor
  S21Matrix(const S21Matrix& other);            // copy constructor
  S21Matrix(S21Matrix&& other) noexcept;        // move constructor
  ~S21Matrix();                                 // destructor

  /* Methods */
  bool EqMatrix(const S21Matrix& other) noexcept;
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);
  S21Matrix Transpose();
  S21Matrix CalcComplements();
  double Determinant();
  S21Matrix InverseMatrix();

  /* Operators */
  S21Matrix operator+(const S21Matrix& other);
  S21Matrix operator-(const S21Matrix& other);
  S21Matrix operator*(const double num);
  friend S21Matrix operator*(const double number, const S21Matrix& other);
  S21Matrix operator*(const S21Matrix& other);
  bool operator==(const S21Matrix& other) noexcept;
  void operator=(const S21Matrix& other);
  S21Matrix operator+=(const S21Matrix& other);
  S21Matrix operator-=(const S21Matrix& other);
  S21Matrix operator*=(const double num);
  S21Matrix operator*=(const S21Matrix& other);
  double& operator()(const int i, const int j);
  double operator()(const int i, const int j) const;

  /* Accessors and mutators */
  int getRows() const;
  int getCols() const;
  void setRows(const int n);
  void setCols(const int n);

  /* Extra methods */
  void PrintMatrix();
  void PrintMatrix() const;

 private:
  enum { SUM, SUB };
  double* matrix_;
  int rows_, cols_;
  void create_matrix();
  void fill_content(const S21Matrix& other);
  void copy_matrix(const S21Matrix& other);
  bool check_matrix_dimension(const S21Matrix& other);
  bool check_square_matrix();
  void simple_math(const S21Matrix& other, const int option);
  void delete_matrix();
  void swap_rows(const int source, const int dest);
  S21Matrix triangular();
  S21Matrix minor(const int x_i, const int x_j);
};

#endif  // SRC_S21_MATRIX_OOP_H_
