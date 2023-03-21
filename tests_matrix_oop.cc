#include <gtest/gtest.h>
#include <cmath>
#include "Eigen/Dense"
#include "s21_matrix_oop.h"

#define TOL 1e-06

class MyTestSuite : public testing::TestWithParam<int> {};

TEST_P(MyTestSuite, MyTest)
{
  std::cout << "Test number: " << GetParam() << std::endl;
  int dimension = GetParam();
  S21Matrix s21_matrix(dimension, dimension);
  Eigen::MatrixXd eigen_matrix(dimension, dimension);
  srand((unsigned) time(NULL));
  for (int i = 0; i < dimension; i++) {
    for (int j = 0; j < dimension; j++) {
      int random = std::rand() % 2;
      s21_matrix(i, j) = random; 
      eigen_matrix(i, j) = random; 
    }
  }
  std::cout << "\033[0;34m" << std::endl;
  s21_matrix.PrintMatrix();
  std::cout << "\033[0m" << std::endl;
  double result = s21_matrix.Determinant();
  double expected = eigen_matrix.determinant();
  double diff = fabs(result - expected);
  std::cout << "\033[0;34mEigen determinant: " << expected << std::endl;
  std::cout << "S21_matrix determinant: " << result << std::endl;
  std::cout << "Difference: " << diff << "\033[0m" << std::endl;
  ASSERT_TRUE(diff < TOL);
}

INSTANTIATE_TEST_SUITE_P(MyGroup, MyTestSuite, testing::Range(1, 50),
                         testing::PrintToStringParamName());

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
