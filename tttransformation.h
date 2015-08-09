#ifndef TTTRANSFORMATION_H
#define TTTRANSFORMATION_H

#include "glm/glm.hpp"
#include "glm/gtx/transform.hpp"

class TTTransformation
{
public:
    TTTransformation(const glm::vec3& pos = glm::vec3(0.0, 0.0, 0.0),
                     const glm::vec3& rot = glm::vec3(0.0, 0.0, 0.0),
                     const glm::vec3& scale = glm::vec3(1.0, 1.0, 1.0));

    glm::mat4 getModel();

    glm::vec3 position();
    glm::vec3 rotation();
    glm::vec3 scale();

    void setPosition(const glm::vec3& pos);
    void setRotation(const glm::vec3& rot);
    void setScale(const glm::vec3& scale);

private:
    glm::vec3 m_position;
    glm::vec3 m_rotation;
    glm::vec3 m_scale;
};

#endif // TTTRANSFORMATION_H
