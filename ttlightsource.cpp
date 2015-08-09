#include "ttlightsource.h"


TTLightSource::TTLightSource(glm::vec3 position, TTLightSource::TT_LIGHT_TYPE type, glm::vec4 color) :
    m_position(position),
    m_type(type),
    m_color(color)
{

}

TTLightSource::~TTLightSource()
{

}

void TTLightSource::setPosition(glm::vec3 position)
{
    m_position = position;
}

glm::vec3 TTLightSource::getPosition()
{
    return m_position;
}

void TTLightSource::setColor(glm::vec4 color)
{
    m_color = color;
}

glm::vec4 TTLightSource::getColor()
{
    return m_color;
}

TTLightSource::TT_LIGHT_TYPE TTLightSource::getType()
{
    return m_type;
}

void TTLightSource::updateLightSources()
{

}
