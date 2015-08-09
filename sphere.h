#ifndef SPHERE_H
#define SPHERE_H

#include "ttgameobject.h"

#include <QVector2D>

class Sphere : public TTGameObject
{
public:
    Sphere(int resolution);
    ~Sphere();

private:
    glm::vec2 texCoords(double omega, double phi);
};

#endif // SPHERE_H
