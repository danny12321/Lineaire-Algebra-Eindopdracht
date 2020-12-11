#include <iostream>
#include "Matrix.hpp"

int main() {
    std::cout << "Hello, World!" << std::endl;
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

    return 0;
}
