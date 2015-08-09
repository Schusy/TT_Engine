#ifndef TTSTATICMESH_H
#define TTSTATICMESH_H

#include <QVector>
#include <QOpenGLFunctions_4_3_Core>

#include "vertex.h"
#include "ttmaterial.h"
#include "ttshader.h"
#include "ttcamera.h"
#include "tttransformation.h"

class TTStaticMesh : protected QOpenGLFunctions_4_3_Core
{
public:
    TTStaticMesh(QVector<Vertex> verts, QVector<unsigned int> inds);
    TTStaticMesh(Vertex *verts, unsigned int numVertices, unsigned int *inds, unsigned int numInds);
    ~TTStaticMesh();

    void render(TTMaterial *material, TTShader *shader, TTCamera *cam, TTTransformation *transformation);

    int numVertices();
    int numTriangles();

private:
    QVector<glm::vec3> m_positions;
    QVector<glm::vec3> m_normals;
    QVector<glm::vec2> m_texCoords;
    QVector<unsigned int> m_indices;

    void initMesh();

    enum {
        TT_POSITION_VAB,
        TT_NORMAL_VAB,
        TT_TEXCOORD_VAB,

        TT_INDEX_VAB,

        NUM_BUFFERS
    };

    GLuint m_vertexArrayObject;
    GLuint m_vertexArrayBuffers[NUM_BUFFERS];
    unsigned int m_drawCount;
};

#endif // TTSTATICMESH_H
