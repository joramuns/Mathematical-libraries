#include <gtest/gtest.h>
#include <cmath>
#include "Eigen/Dense"
#include "s21_matrix_oop.h"

TEST(Determinant, FirstTest) {
  int dimension = 2;
  S21Matrix s21_matrix(dimension, dimension);
  Eigen::MatrixXd eigen_matrix(dimension, dimension);
  srand((unsigned) time(NULL));
  for (int i = 0; i < dimension; i++) {
    for (int j = 0; j < dimension; j++) {
      int random = rand() % 10;
      s21_matrix(i, j) = random; 
      eigen_matrix(i, j) = random; 
    }
  }
  s21_matrix.PrintMatrix();
  std::cout << std::endl;
  std::cout << "Eigen determinant: " << eigen_matrix.determinant() << std::endl;
  std::cout << "S21_matrix determinant: " << s21_matrix.Determinant() << std::endl;
  ASSERT_TRUE(fabs(s21_matrix.Determinant() - eigen_matrix.determinant()) < 1e-7);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
