#include <gtest/gtest.h>
#include "../src/Matrix.cpp"

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
    Matrix result = a + b;

    // Assert
    ASSERT_EQ(result.getNumber(0, 0), 5);
    ASSERT_EQ(result.getNumber(1, 0), 5);
    ASSERT_EQ(result.getNumber(0, 1), 5);
    ASSERT_EQ(result.getNumber(1, 1), 5);
}

TEST(MatrixTest, SubtractTwoMatrices)
{
    // Arrange
    Matrix a {{
                      {4,5},
                      {6,7}
              }};

    Matrix b {{
                      {1,2},
                      {3,4}
              }};

    // Act
    Matrix result = a + b;

    // Assert
    ASSERT_EQ(result.getNumber(0, 0), 5);
    ASSERT_EQ(result.getNumber(1, 0), 5);
    ASSERT_EQ(result.getNumber(0, 1), 5);
    ASSERT_EQ(result.getNumber(1, 1), 5);
}


TEST(MatrixTest, MultiplyMatrices2By2)
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
    Matrix result = a * b;

    // Assert
    ASSERT_EQ(result.getNumber(0, 0), 8);
    ASSERT_EQ(result.getNumber(1, 0), 20);
    ASSERT_EQ(result.getNumber(0, 1), 5);
    ASSERT_EQ(result.getNumber(1, 1), 13);
}

TEST(MatrixTest, MultiplyMatrices3x2By2x3)
{
    // Arrange
    Matrix a {{
                      {1,2},
                      {3,4},
                      {5,6}
              }};

    Matrix b {{
                      {1,2,3},
                      {4,5,6}
              }};

    // Act
    Matrix result = a * b;

    // Assert
    ASSERT_EQ(result.getNumber(0, 0), 9);
    ASSERT_EQ(result.getNumber(0, 1), 12);
    ASSERT_EQ(result.getNumber(0, 2), 15);
    ASSERT_EQ(result.getNumber(1, 0), 19);
    ASSERT_EQ(result.getNumber(1, 1), 26);
    ASSERT_EQ(result.getNumber(1, 2), 33);
    ASSERT_EQ(result.getNumber(2, 0), 29);
    ASSERT_EQ(result.getNumber(2, 1), 40);
    ASSERT_EQ(result.getNumber(2, 2), 51);
}