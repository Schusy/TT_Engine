#include "ttcamera.h"

TTCamera::TTCamera()
{

}

TTCamera::TTCamera(const glm::vec3 &pos, float fov, float aspect, float zNear, float zFar) :
    m_position(pos),
    m_fov(fov),
    m_near(zNear),
    m_far(zFar)
{
    m_forward = glm::vec3(0, 0, -1);
    m_up = glm::vec3(0, 1, 0);
    setAspect(aspect);
}

void TTCamera::setAspect(float aspect)
{
    m_aspect = aspect;
    m_perspective = glm::perspective(m_fov, m_aspect, m_near, m_far);
}

glm::mat4 TTCamera::getViewProjection()
{
    return m_perspective * glm::lookAt(m_position, m_position + m_forward, m_up);
}

