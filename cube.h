#ifndef CUBE_H
#define CUBE_H

#include "ttgameobject.h"

class Cube : public TTGameObject
{
public:
    Cube();
    ~Cube();

private:
    QVector<glm::vec3> positions();
    QVector<glm::vec3> normals();
    QVector<glm::vec2> texCoords();
    QVector<unsigned int> triangles();
};

#endif // CUBE_H
