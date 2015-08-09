#ifndef VERTEX_H
#define VERTEX_H

#include <QVector3D>
#include <QVector2D>
#include "glm/glm.hpp"


class Vertex
{
public:
    Vertex();
    Vertex(glm::vec3 pos, glm::vec3 norm = glm::vec3(0.0, 0.0, 1.0), glm::vec2 texCoord = glm::vec2(0, 0));
    ~Vertex();

    void setPosition(glm::vec3 pos);
    glm::vec3 getPosition() const;

    void setNormal(glm::vec3 norm);
    glm::vec3 getNormal() const;

    void setTexCoord(glm::vec2 tex);
    glm::vec2 getTexCoord() const;

private:
    glm::vec3 m_position;
    glm::vec3 m_normal;
    glm::vec2 m_texCoord;
};

#endif // VERTEX_H
