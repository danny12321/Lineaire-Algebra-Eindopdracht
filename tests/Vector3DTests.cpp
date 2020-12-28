//#include <gtest/gtest.h>
//#include "../src/Vector3D.cpp"
//
//TEST(Vector3D, DotProduct)
//{
//    // Arrange
//    Vector3D a {2,-1,0};
//
//    Vector3D b {3,1,4};
//
//    // Act
//    float result = a.dotProduct(b);
//
//    // Assert
//    ASSERT_EQ(result, 5);
//}
//
//TEST(Vector3D, DotProductZeros)
//{
//    // Arrange
//    Vector3D a {0,0,0};
//
//    Vector3D b {3,1,4};
//
//    // Act
//    float result = a.dotProduct(b);
//
//    // Assert
//    ASSERT_EQ(result, 0);
//}
//
//TEST(Vector3D, CrossProduct)
//{
//    // Arrange
//    Vector3D a {1,0,0};
//
//    Vector3D b {0,1,0};
//
//    // Act
//    Vector3D result = a.crossProduct(b);
//
//    // Assert
//    ASSERT_EQ(result.getX(), 0);
//    ASSERT_EQ(result.getY(), 0);
//    ASSERT_EQ(result.getZ(), 1);
//}
//
//TEST(Vector3D, CrossProductNogeen)
//{
//    // Arrange
//    Vector3D a { 1, 1, 0 };
//
//    Vector3D b { 0, 1, 0 };
//
//    // Act
//    Vector3D result = a.crossProduct(b);
//
//    // Assert
//    ASSERT_EQ(result.getX(), 0);
//    ASSERT_EQ(result.getY(), 0);
//    ASSERT_EQ(result.getZ(), 1);
//}
//
//TEST(Vector3D, IndependentOf)
//{
//    // Arrange
//    Vector3D a {1,-3,7};
//
//    Vector3D b {-3,9,-20};
//
//    // Act
//    bool result = a.independentOf(b);
//
//    // Assert
//    ASSERT_EQ(result, true);
//}
//
//TEST(Vector3D, IndependentOfZeros)
//{
//    // Arrange
//    Vector3D a {0,0,0};
//
//    Vector3D b {-3,9,-20};
//
//    // Act
//    bool result = a.independentOf(b);
//
//    // Assert
//    ASSERT_EQ(result, true);
//}
//
//
//TEST(Vector3D, IndependentOfDecimal)
//{
//    // Arrange
//    Vector3D a {3.5,4.9,-0.5};
//
//    Vector3D b {7,9.8,-0.25};
//
//    // Act
//    bool result = a.independentOf(b);
//
//    // Assert
//    ASSERT_EQ(result, true);
//}
//
//TEST(Vector3D, IndependentOfFalse)
//{
//    // Arrange
//    Vector3D a {2,1,-2};
//
//    Vector3D b {-4,-2,4};
//
//    // Act
//    bool result = a.independentOf(b);
//
//    // Assert
//    ASSERT_EQ(result, false);
//}
//
//TEST(Vector3D, GetLength)
//{
//    // Arrange
//    Vector3D a {1,2,3};
//
//    // Act
//    float result = a.getLength();
//
//    // Assert
//    EXPECT_TRUE((result >= 3.73) && (result <= 3.75));
//}
//
//TEST(Vector3D, AngleBetween)
//{
//    // Arrange
//    Vector3D a {2,-1,0};
//    Vector3D b {3,1,4};
//
//    // Act
//    float result = a.getAngleBetween(b);
//
//    // Assert
//    EXPECT_TRUE((result >= 63.8) && (result <= 64));
//}
//
//TEST(Vector3D, Eenheidsvector)
//{
//    // Arrange
//    Vector3D a {5,3,7};
//
//    // Act
//    Vector3D result = a.getEenheidsvector();
//
//    // Assert
//    ASSERT_EQ(result.getLength(), 1);
//}
//
//TEST(Vector3D, EenheidsvectorZero)
//{
//    // Arrange
//    Vector3D a {0,0,0};
//
//    // Act
//    Vector3D result = a.getEenheidsvector();
//    // Assert
//    ASSERT_EQ(result.getLength(), 0);
//}