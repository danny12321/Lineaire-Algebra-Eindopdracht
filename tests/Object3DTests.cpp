#include <gtest/gtest.h>
#include "../src/Vector3D.cpp"
#include "../src/3DObjects/Object3D.cpp"

TEST(Object3D, getNormalVector)
{
    Object3D obj{};
//     Arrange
    Vector3D origin {-2,-2,-2};
    Vector3D a {-1,-2,-2};

    Vector3D b {-2,-1,-2};

//     Act
    Vector3D result = obj.getNormalVector(origin, a, b);

    // Assert
    ASSERT_EQ(result.getX(), -2);
    ASSERT_EQ(result.getY(), -2);
    ASSERT_EQ(result.getZ(), -1);
}

TEST(Object3D, getNormalVectorTwo)
{
    Object3D obj{};
//     Arrange
    Vector3D origin {0,1,1};
    Vector3D a {0,1,2};

    Vector3D b {1,1,1};

//     Act
    Vector3D result = obj.getNormalVector(origin, a, b);

    // Assert
    ASSERT_EQ(result.getX(), 3);
    ASSERT_EQ(result.getY(), 3);
    ASSERT_EQ(result.getZ(), 4);
}