#ifndef SRC_S21_MATRIX_OOP_H_
#define SRC_S21_MATRIX_OOP_H_

class S21Matrix {
 public:
  S21Matrix();                        // basic constructor
  explicit S21Matrix(int dimension);  // constructor for square matrices
  S21Matrix(int rows, int cols);      // parametrized constructor
  S21Matrix(const S21Matrix& other);  // copy constructor
  S21Matrix(S21Matrix&& other);       // move constructor
  ~S21Matrix();                       // destructor

  // Operators
  double& operator()(int i, int j);

  // Extra methods
  void PrintMatrix();
 private:
  double* matrix_;
  int rows_, cols_;
  bool create_matrix();
  /* void swap(S21Matrix &other); */
};
#endif  // SRC_S21_MATRIX_OOP_H_
