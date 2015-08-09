#ifndef TTLIGHTSOURCE_H
#define TTLIGHTSOURCE_H

#include "glm/glm.hpp"

class TTLightSource
{
public:
    enum TT_LIGHT_TYPE {
        TT_DIRECTIONAL_LIGHT,
        TT_POINT_LIGHT
    };
    TTLightSource(glm::vec3 position, TT_LIGHT_TYPE type, glm::vec4 color);
    ~TTLightSource();

    void setPosition(glm::vec3 position);
    glm::vec3 getPosition();
    void setColor(glm::vec4 color);
    glm::vec4 getColor();
    TT_LIGHT_TYPE getType();

private:
    glm::vec3 m_position;
    TT_LIGHT_TYPE m_type;
    glm::vec4 m_color;

    void updateLightSources();
};

#endif // TTLIGHTSOURCE_H
