#include "tttransformation.h"


TTTransformation::TTTransformation(const glm::vec3 &pos, const glm::vec3 &rot, const glm::vec3 &scale) :
    m_position(pos),
    m_rotation(rot),
    m_scale(scale)
{

}

glm::mat4 TTTransformation::getModel()
{
    glm::mat4 posMatrix = glm::translate(m_position);
    glm::mat4 rotMatrixX = glm::rotate(m_rotation.x, glm::vec3(1, 0, 0));
    glm::mat4 rotMatrixY = glm::rotate(m_rotation.y, glm::vec3(0, 1, 0));
    glm::mat4 rotMatrixZ = glm::rotate(m_rotation.z, glm::vec3(0, 0, 1));
    glm::mat4 scaleMatrix = glm::scale(m_scale);

    glm::mat4 rotMatrix = rotMatrixZ * rotMatrixY * rotMatrixX;

    return posMatrix * rotMatrix * scaleMatrix;
}

glm::vec3 TTTransformation::position()
{
    return m_position;
}

glm::vec3 TTTransformation::rotation()
{
    return m_rotation;
}

glm::vec3 TTTransformation::scale()
{
    return m_scale;
}

void TTTransformation::setPosition(const glm::vec3 &pos)
{
    m_position = pos;
}

void TTTransformation::setRotation(const glm::vec3 &rot)
{
    m_rotation = rot;
}

void TTTransformation::setScale(const glm::vec3 &scale)
{
    m_scale = scale;
}
