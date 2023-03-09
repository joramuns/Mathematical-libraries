#ifndef SRC_S21_MATRIX_OOP_H_
#define SRC_S21_MATRIX_OOP_H_

class S21Matrix {
  public:
    S21Matrix(); // basic constructor
    explicit S21Matrix(int dimension); // constructor for square matrixes
    S21Matrix(int rows, int cols); // parametrized constructor
    S21Matrix(const S21Matrix& other); // copy constructor
    S21Matrix(S21Matrix&& other); // move constructor
    ~S21Matrix(); // destructor
  private:
    double **matrix_;
    int rows_;
    int cols_;
};
#endif  // SRC_S21_MATRIX_OOP_H_
