//#include <gtest/gtest.h>
//#include "../src/Camera.cpp"
//
//TEST(Camera, GetDirection)
//{
//    // Arrange
//
//    Vector3D eye{1, 1, 1};
//    Vector3D lookat{0, 0, 1};
//    Camera camera {eye, lookat};
//    // Act
//    Vector3D result = camera.getDirection();
//
//    // Assert
//    EXPECT_TRUE((result.getLength() >= 0.998) && (result.getLength() <= 1.002));
//}
//
//TEST(Camera, GetRight)
//{
////    Under construction
//    // Arrange
//    Vector3D eye{1, 1, 1};
//    Vector3D lookat{0, 0, 1};
//    Camera camera {eye, lookat};
//
//    // Act
//    Vector3D result = camera.getRight();
//
//    // Assert
//    EXPECT_TRUE((result.getLength() >= 0.998) && (result.getLength() <= 1.002));
//}