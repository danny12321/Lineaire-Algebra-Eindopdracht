//
// Created by Thierry on 18-12-2020.
//

#ifndef LINAL_OBJECT3D_HPP
#define LINAL_OBJECT3D_HPP

#include "../Line.hpp"
#include <vector>
#include "../Matrix.hpp"

class EventSystem;
class Object3D {
public:
    Object3D();
    explicit Object3D(const std::string &filename);

    [[nodiscard]] std::vector<Line*> getLines() const { return lines; }
    [[nodiscard]] std::vector<Line*> getXyzAxisLines() const { return localXyzLines; }
    [[nodiscard]] std::vector<Line*> getBoundingBox() const { return boundingBoxLines; }
    void addLine(Line* line) { lines.push_back(line); }

    void translate(float x, float y, float z);

    void translateLocalX(float distance);
    void translateLocalY(float distance);
    void translateLocalZ(float distance);

    void rotateAroundOriginX(float deg);
    void rotateAroundOriginY(float deg);
    void rotateAroundOriginZ(float deg);

    void rotateLocalAxis(float x, float y, float z);

    void rotateToOrigin();

    void rotateX(float deg);
    void rotateY(float deg);
    void rotateZ(float deg);

    void rotateLocalX(float deg);
    void rotateLocalY(float deg);
    void rotateLocalZ(float deg);

    void rotateAxis(const Vector3D& v, float deg);

    void scale(float scaleX, float scaleY, float scaleZ);

    void setColor(int r, int g, int b) {
        this->r = r;
        this->g = g;
        this->b = b;
    }

    [[nodiscard]] int getRedColor() const {return r;};
    [[nodiscard]] int getGreenColor() const {return g;};
    [[nodiscard]] int getBlueColor() const {return b;};

    virtual void update(const EventSystem &system) {};
    virtual void collide(Object3D& collider) {};

    void toOrigin();

    Vector3D getNormalVector(const Vector3D& origin, const Vector3D& v1, const Vector3D& v2);

    Vector3D getMiddle();

    void resetXyzAxis();
    void resetBouningBox();

    [[nodiscard]] float getPositiveX() const { return positiveX; }
    [[nodiscard]] float getPositiveY() const { return positiveY; }
    [[nodiscard]] float getPositiveZ() const { return positiveZ; }
    [[nodiscard]] float getNegativeX() const { return negativeX; }
    [[nodiscard]] float getNegativeY() const { return negativeY; }
    [[nodiscard]] float getNegativeZ() const { return negativeZ; }
protected:
    std::vector<Line*> lines;
    std::vector<Vector3D*> points;
    std::vector<Line*> localXyzLines;
    std::vector<Vector3D*> localXyzPoints;
    std::vector<Line*> boundingBoxLines;
    std::vector<Vector3D*> boundingBox;
private:
    float rotationX = 0;
    float rotationY = 0;
    float rotationZ = 0;

    float positiveX = 0;
    float negativeX = 0;
    float positiveY = 0;
    float negativeY = 0;
    float positiveZ = 0;
    float negativeZ = 0;

    Matrix vectorToMatrix(const Vector3D& v);
    void updatePoints(const Matrix& m);
    int r = 255;
    int g = 255;
    int b = 255;
};


#endif //LINAL_OBJECT3D_HPP
