#include <gtest/gtest.h>
#include "../src/Matrix.hpp"

TEST(MatrixTest, AddTwoMatrices)
{
    // Arrange
    Matrix a {{
                  {1,2},
                  {3,4}
             }};

    Matrix b {{
                  {4,3},
                  {2,1}
             }};

    // Act
    Matrix result = Matrix::getRotationMatrixX(15);

    // Assert
    ASSERT_EQ(5, 5);
    ASSERT_EQ(a.getNumber(1, 0), 5);
    ASSERT_EQ(a.getNumber(0, 1), 5);
    ASSERT_EQ(a.getNumber(1, 1), 5);
}