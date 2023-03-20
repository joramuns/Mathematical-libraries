#include <gtest/gtest.h>
#include <cmath>
#include "Eigen/Dense"
#include "s21_matrix_oop.h"

#define TOL 1e-01

TEST(Fixture, FirstTest) {
  int dimension = 2;
  S21Matrix s21_matrix(dimension, dimension);
  Eigen::MatrixXd eigen_matrix(dimension, dimension);
  srand((unsigned) time(NULL));
  for (int i = 0; i < dimension; i++) {
    for (int j = 0; j < dimension; j++) {
      int random = std::rand() % 10;
      s21_matrix(i, j) = random; 
      eigen_matrix(i, j) = random; 
    }
  }
  s21_matrix.PrintMatrix();
  std::cout << std::endl;
  std::cout << "Eigen determinant: " << eigen_matrix.determinant() << std::endl;
  std::cout << "S21_matrix determinant: " << s21_matrix.Determinant() << std::endl;
  ASSERT_TRUE(fabs(s21_matrix.Determinant() - eigen_matrix.determinant()) < TOL);
}

class MyTestSuite : public testing::TestWithParam<int> {};

TEST_P(MyTestSuite, MyTest)
{
  std::cout << "Example Test Param: " << GetParam() << std::endl;
  int dimension = GetParam();
  S21Matrix s21_matrix(dimension, dimension);
  Eigen::MatrixXd eigen_matrix(dimension, dimension);
  srand((unsigned) time(NULL));
  for (int i = 0; i < dimension; i++) {
    for (int j = 0; j < dimension; j++) {
      int random = std::rand() % 10;
      s21_matrix(i, j) = random; 
      eigen_matrix(i, j) = random; 
    }
  }
  s21_matrix.PrintMatrix();
  std::cout << std::endl;
  double result = s21_matrix.Determinant();
  double expected = eigen_matrix.determinant();
  double diff = fabs(result - expected);
  std::cout << "Eigen determinant: " << expected << std::endl;
  std::cout << "S21_matrix determinant: " << result << std::endl;
  std::cout << diff << std::endl;
  ASSERT_TRUE(diff < TOL);
}

INSTANTIATE_TEST_SUITE_P(MyGroup, MyTestSuite, testing::Range(1, 10),
                         testing::PrintToStringParamName());

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
