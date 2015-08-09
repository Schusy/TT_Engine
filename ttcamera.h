#ifndef TTCAMERA_H
#define TTCAMERA_H

#include "glm/glm.hpp"
#include "glm/gtx/transform.hpp"

class TTCamera
{
public:
    TTCamera();
    TTCamera(const glm::vec3& pos, float fov, float aspect, float zNear, float zFar);

    void setAspect(float aspect);

    glm::mat4 getViewProjection();

private:
    glm::mat4 m_perspective;
    glm::vec3 m_position;
    glm::vec3 m_forward;
    glm::vec3 m_up;
    float m_aspect;
    float m_fov;
    float m_near;
    float m_far;
};

#endif // TTCAMERA_H
