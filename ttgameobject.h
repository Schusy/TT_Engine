#ifndef TTGAMEOBJECT_H
#define TTGAMEOBJECT_H

#include <QVector>
#include "ttstaticmesh.h"
#include "ttmaterial.h"
#include "tttransformation.h"
#include "ttshader.h"
#include "ttcamera.h"

class TTGameObject
{
public:
    TTGameObject();
    ~TTGameObject();

    void setMesh(TTStaticMesh *mesh);
    void setMaterial(TTMaterial *mat);
    void setShader(TTShader *shader);

    void setVisible(bool vis);

    void render(TTCamera *cam);

    void setPosition(float x, float y, float z);
    void setRotation(float x, float y, float z);
    void setScale(float x, float y, float z);
    void setTransformation(TTTransformation *transformation);

    int numVertices();
    int numTriangles();

private:
    bool m_isVisible;
    TTStaticMesh *m_staticMesh;
    TTMaterial *m_material;
    TTShader *m_shader;

    TTTransformation *m_transformation;
};

#endif // TTGAMEOBJECT_H
