#ifndef SRC_S21_MATRIX_OOP_H_
#define SRC_S21_MATRIX_OOP_H_

#include <cmath>
#include <cstring>
#include <iostream>

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

 private:
  double* matrix_;
  int rows_, cols_;
  /* Helpers */
  enum { kSum, kSub };
  void CreateMatrix();
  void CopyMatrix(const S21Matrix& other);
  void DeleteMatrix();
  /**
   * @brief Fills matrix with content after changing its size. In case of
   * increasing size - additional elements are filled with zeros, otherwise
   * extra elements are discarded
   *
   * @param other Original matrix
   */
  void FillContent(const S21Matrix& other);
  /**
   * @brief Checks if two matrices have common row and column sizes
   *
   * @param other Matrix for comparison
   *
   * @return True or false
   */
  bool CheckMatrixDimension(const S21Matrix& other);
  /**
   * @brief Checks if given matrix is square dimensional
   *
   * @return True or false
   */
  bool CheckSquareMatrix();
  /**
   * @brief Common function for computation the result of addition or
   * subtraction of two matrices
   *
   * @param other Matrix for operation
   * @param option Uses enum for recognition of operation type
   */
  void SimpleMath(const S21Matrix& other, const int option);
  /**
   * @brief Helper of Determinant method, computes a triangular matrix from
   * original in order to multiply main diagonal as a determinant of original
   * matrix
   *
   * @return New triangular matrix based on original matrix
   */
  S21Matrix Triangular();
  /**
   * @brief Finds an index of maximum element in upper half of triangular matrix
   * based on pivot coordinate
   *
   * @param h Pivot row
   * @param k Pivot column
   *
   * @return Index of max element
   */
  int FindMaxElem(const int h, const int k);
  /**
   * @brief Swaps two given rows in the matrix
   *
   * @param source A row to swap from
   * @param dest A row to swap to
   */
  void SwapRows(const int source, const int dest);
  /**
   * @brief Main converter of matrix after swapping rows, fills elements down to
   * pivot with zeros and elements right to pivot with relevant values based on
   * Gauss-Jordan elemination method
   *
   * @param h Pivot row
   * @param k Pivot column
   */
  void BalanceRow(const int h, const int k);
  /**
   * @brief Helper of CalcComplements method, deleting a row and column from
   * original matrix
   *
   * @param x_i Row to delete
   * @param x_j Column to delete
   *
   * @return New minor matrix based on original matrix
   */
  S21Matrix Minor(const int x_i, const int x_j);
};

#endif  // SRC_S21_MATRIX_OOP_H_
