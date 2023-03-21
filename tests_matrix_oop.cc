#include <gtest/gtest.h>
#include <cmath>
#include "Eigen/Dense"
#include "s21_matrix_oop.h"

#define TOL 1e-06

class MyTestSuite : public testing::TestWithParam<int> {};

TEST_P(MyTestSuite, OneAndZero)
{
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
  double result = s21_matrix.Determinant();
  double expected = eigen_matrix.determinant();
  /* ASSERT_TRUE(diff < TOL); */
  EXPECT_DOUBLE_EQ(expected, result);
  /* ASSERT_NEAR(result, expected, TOL); */
}

TEST_P(MyTestSuite, OneToTen)
{
  int dimension = GetParam();
  S21Matrix s21_matrix(dimension, dimension);
  Eigen::MatrixXd eigen_matrix(dimension, dimension);
  srand((unsigned) time(NULL));
  for (int i = 0; i < dimension; i++) {
    for (int j = 0; j < dimension; j++) {
      int random = 1 + std::rand() % 9;
      s21_matrix(i, j) = random; 
      eigen_matrix(i, j) = random; 
    }
  }
  double result = s21_matrix.Determinant();
  double expected = eigen_matrix.determinant();
  /* ASSERT_TRUE(diff < TOL); */
  EXPECT_DOUBLE_EQ(expected, result);
  /* ASSERT_NEAR(result, expected, TOL); */
}

INSTANTIATE_TEST_SUITE_P(MyGroup, MyTestSuite, testing::Range(1, 20),
                         testing::PrintToStringParamName());

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
