#include "ttgameobject.h"

TTGameObject::TTGameObject() :
    m_isVisible(true)
{
    m_transformation = new TTTransformation();
}

TTGameObject::~TTGameObject()
{
    delete m_transformation;
}

void TTGameObject::setMesh(TTStaticMesh *mesh)
{
    m_staticMesh = mesh;
    m_isVisible = true;
}

void TTGameObject::setMaterial(TTMaterial *mat)
{
    m_material = mat;
}

void TTGameObject::setShader(TTShader *shader)
{
    m_shader = shader;
}

void TTGameObject::setVisible(bool vis)
{
    m_isVisible = vis;
}

void TTGameObject::render(TTCamera *camera)
{
    if (m_isVisible) {
        m_material->bind(0);
        m_staticMesh->render(m_material, m_shader, camera, m_transformation);
    }
}

void TTGameObject::setPosition(float x, float y, float z)
{
    m_transformation->setPosition(glm::vec3(x, y, z));
}

void TTGameObject::setRotation(float x, float y, float z)
{
    m_transformation->setRotation(glm::vec3(x, y, z));
}

void TTGameObject::setScale(float x, float y, float z)
{
    m_transformation->setScale(glm::vec3(x, y, z));
}

void TTGameObject::setTransformation(TTTransformation *transformation)
{
    m_transformation = transformation;
}

int TTGameObject::numVertices()
{
    return m_staticMesh->numVertices();
}

int TTGameObject::numTriangles()
{
    return m_staticMesh->numTriangles();
}
