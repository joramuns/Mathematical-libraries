#ifndef SRC_S21_MATRIX_OOP_H_
#define SRC_S21_MATRIX_OOP_H_

#include <cmath>
#include <cstring>
#include <iostream>
#include <limits>

class S21Matrix {
 public:
  /* Constructors and destructors */
  S21Matrix();                                // basic constructor
  explicit S21Matrix(const int dimension);    // constructor for square matrices
  S21Matrix(const int rows, const int cols);  // parametrized constructor
  S21Matrix(const S21Matrix& other);          // copy constructor
  S21Matrix(S21Matrix&& other) noexcept;      // move constructor
  ~S21Matrix();                               // destructor

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
  int get_rows() const;
  int get_cols() const;
  void set_rows(const int n);
  void set_cols(const int n);

  /* Extra methods */
  void PrintMatrix();
  void PrintMatrix() const;

 private:
  enum { kSum, kSub };
  double* matrix_;
  int rows_, cols_;
  void CreateMatrix();
  void FillContent(const S21Matrix& other);
  void CopyMatrix(const S21Matrix& other);
  bool CheckMatrixDimension(const S21Matrix& other);
  bool CheckSquareMatrix();
  void SimpleMath(const S21Matrix& other, const int option);
  void DeleteMatrix();
  S21Matrix Triangular();
  int FindMaxElem(const int h, const int k);
  void SwapRows(const int source, const int dest);
  void BalanceRow(const int h, const int k);
  S21Matrix Minor(const int x_i, const int x_j);
};

#endif  // SRC_S21_MATRIX_OOP_H_
