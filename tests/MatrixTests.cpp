#include <gtest/gtest.h>
#include "../src/Matrix.cpp"

TEST(MatrixTest, AddMatrices)
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
    ASSERT_EQ(result.getNumber(0, 1), 5);
    ASSERT_EQ(result.getNumber(1, 0), 5);
    ASSERT_EQ(result.getNumber(1, 1), 5);
}

TEST(MatrixTest, SubtractMatrices)
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
    Matrix result = a - b;

    // Assert
    ASSERT_EQ(result.getNumber(0, 0), 3);
    ASSERT_EQ(result.getNumber(0, 1), 3);
    ASSERT_EQ(result.getNumber(1, 0), 3);
    ASSERT_EQ(result.getNumber(1, 1), 3);
}


TEST(MatrixTest, MultiplyMatrices2With2)
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

TEST(MatrixTest, MultiplyMatrices3x2With2x3)
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

TEST(MatrixTest, MultiplyMatrices3x3With3x3)
{
    // Arrange
    Matrix a {{
                      {1, 2, 1},
                      {2, 0, 2},
                      {3, 4, 0}
              }};

    Matrix b {{
                      {1, 2, 1},
                      {2, 0, 2},
                      {3, 4, 0}
              }};

    // Act
    Matrix result = a * b;

    // Assert
    ASSERT_EQ(result.getNumber(0, 0), 8);
    ASSERT_EQ(result.getNumber(0, 1), 6);
    ASSERT_EQ(result.getNumber(0, 2), 5);
    ASSERT_EQ(result.getNumber(1, 0), 8);
    ASSERT_EQ(result.getNumber(1, 1), 12);
    ASSERT_EQ(result.getNumber(1, 2), 2);
    ASSERT_EQ(result.getNumber(2, 0), 11);
    ASSERT_EQ(result.getNumber(2, 1), 6);
    ASSERT_EQ(result.getNumber(2, 2), 11);
}

TEST(MatrixTest, MultiplyMatricesWithDifferentRowAndColumnsThrowsError)
{
    // Arrange
    Matrix a {{
                      {1, 2},
                      {2, 0},
                      {3, 4}
              }};

    Matrix b {{
                      {1, 2, 1},
                      {2, 0, 2},
                      {3, 4, 0}
              }};

    // Assert
    try {
        Matrix result = a * b;
        FAIL() << "Expected: Matrix size is not correct for multiplying";
    } catch(std::string& str) {
        EXPECT_EQ(str,std::string("Matrix size is not correct for multiplying"));
    } catch(...) {
        FAIL() << "Expected: Matrix size is not correct for multiplying";
    }
}

TEST(MatrixTest, Translation)
{
    // Arrange
    Matrix a {{
              {1},
              {3},
              {5},
              {1}
      }};

    // Act
    Matrix result = Matrix::getTranslationMatrix(2, 1, 3) * a;

    // Assert
    ASSERT_EQ(result.getNumber(0, 0), 3);
    ASSERT_EQ(result.getNumber(1, 0), 4);
    ASSERT_EQ(result.getNumber(2, 0), 8);

}

//TEST(MatrixTest, TranslationTwo)
//{
//    // Arrange
//    Matrix a {{
//                      {1},
//                      {1},
//                      {1},
//                      {1}
//              }};
//
//    // Act
//    Matrix result = Matrix::getTranslationMatrix(0.1, 0, 0) * a;
//
//    // Assert
//    ASSERT_EQ(result.getNumber(0, 0), 2);
//    ASSERT_EQ(result.getNumber(1, 0), 1);
//    ASSERT_EQ(result.getNumber(2, 0), 1);
//}