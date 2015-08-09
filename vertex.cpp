#include "vertex.h"

Vertex::Vertex()
{

}

Vertex::Vertex(glm::vec3 pos, glm::vec3 norm, glm::vec2 texCoord) :
    m_position(pos),
    m_normal(norm),
    m_texCoord(texCoord)
{

}

Vertex::~Vertex()
{

}

void Vertex::setPosition(glm::vec3 pos)
{
    m_position = pos;
}

glm::vec3 Vertex::getPosition() const
{
    return m_position;
}

void Vertex::setNormal(glm::vec3 norm)
{
    m_normal = norm;
}

glm::vec3 Vertex::getNormal() const
{
    return m_normal;
}

void Vertex::setTexCoord(glm::vec2 tex)
{
    m_texCoord = tex;
}

glm::vec2 Vertex::getTexCoord() const
{
    return m_texCoord;
}
