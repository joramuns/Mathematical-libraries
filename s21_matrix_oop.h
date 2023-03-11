#ifndef SRC_S21_MATRIX_OOP_H_
#define SRC_S21_MATRIX_OOP_H_

class S21Matrix {
 public:
  /* Constructors and destructors */
  S21Matrix();                        // basic constructor
  explicit S21Matrix(int dimension);  // constructor for square matrices
  S21Matrix(int rows, int cols);      // parametrized constructor
  S21Matrix(const S21Matrix& other);  // copy constructor
  S21Matrix(S21Matrix&& other);       // move constructor
  ~S21Matrix();                       // destructor

  /* Methods */
  bool EqMatrix(const S21Matrix& other);
  void SumMatrix(const S21Matrix& other);
  void SubMatrix(const S21Matrix& other);
  void MulNumber(const double num);
  void MulMatrix(const S21Matrix& other);
  /* S21Matrix Transpose(); */
  /* S21Matrix CalcComplements(); */
  /* double Determinant(); */
  /* S21Matrix InverseMatrix(); */

  /* Operators */
  /* S21Matrix operator+(S21Matrix& other); */
  /* S21Matrix operator-(S21Matrix& other); */
  /* S21Matrix operator*(S21Matrix& other); */
  bool operator==(const S21Matrix& other);
  void operator=(const S21Matrix& other);
  /* S21Matrix operator+=(S21Matrix& other); */
  /* S21Matrix operator-=(S21Matrix& other); */
  /* S21Matrix operator*=(S21Matrix& other); */
  /* friend S21Matrix operator*(S21Matrix& other, double& number); */
  /* friend S21Matrix operator*(double& number, S21Matrix& other); */
  double& operator()(int i, int j);

  /* Extra methods */
  void PrintMatrix();

 private:
  double* matrix_;
  int rows_, cols_;
  void create_matrix();
  void copy_matrix(const S21Matrix& other);
  bool check_matrix_dimension(const S21Matrix& other);
  void delete_matrix();
};

/* S21Matrix operator*(S21Matrix& other, double& number); */
/* S21Matrix operator*(double& number, S21Matrix& other); */
#endif  // SRC_S21_MATRIX_OOP_H_
