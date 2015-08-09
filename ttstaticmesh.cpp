#include "ttstaticmesh.h"

#include <QDebug>

TTStaticMesh::TTStaticMesh(QVector<Vertex> verts, QVector<unsigned int> inds) :
    m_indices(inds)
{
    for (int i = 0; i < verts.count(); i++) {
        m_positions.push_back(verts.at(i).getPosition());
        m_normals.push_back(verts.at(i).getNormal());
        m_texCoords.push_back(verts.at(i).getTexCoord());
    }
    initMesh();
}

TTStaticMesh::TTStaticMesh(Vertex *verts, unsigned int numVertices, unsigned int *inds, unsigned int numIndices)
{
    for (unsigned int i = 0; i < numVertices; i++) {
        m_positions.push_back(verts[i].getPosition());
        m_normals.push_back(verts[i].getNormal());
        m_texCoords.push_back(verts[i].getTexCoord());
    }
    for (unsigned int j = 0; j < numIndices; j++) {
        m_indices.push_back(inds[j]);
    }
    initMesh();
}


TTStaticMesh::~TTStaticMesh()
{

}

void TTStaticMesh::render(TTMaterial *material, TTShader *shader, TTCamera *cam, TTTransformation *transformation)
{
    shader->bind(material, cam, transformation);

    //qDebug() << "drawing...";
    glBindVertexArray(m_vertexArrayObject);
    glDrawElements(GL_TRIANGLES, m_drawCount, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
}

int TTStaticMesh::numVertices()
{
    return m_positions.count();
}

int TTStaticMesh::numTriangles()
{
    return m_indices.count() / 3;
}

void TTStaticMesh::initMesh()
{
    initializeOpenGLFunctions();

    m_drawCount = m_indices.count();

    glGenVertexArrays(1, &m_vertexArrayObject);
    glBindVertexArray(m_vertexArrayObject);

    glGenBuffers(NUM_BUFFERS, m_vertexArrayBuffers);

    glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[TT_POSITION_VAB]);
    glBufferData(GL_ARRAY_BUFFER, m_positions.count() * sizeof(m_positions.at(0)), &m_positions.at(0), GL_STATIC_DRAW);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[TT_NORMAL_VAB]);
    glBufferData(GL_ARRAY_BUFFER, m_normals.count() * sizeof(m_normals.at(0)), &m_normals.at(0), GL_STATIC_DRAW);

    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);

    glBindBuffer(GL_ARRAY_BUFFER, m_vertexArrayBuffers[TT_TEXCOORD_VAB]);
    glBufferData(GL_ARRAY_BUFFER, m_texCoords.count() * sizeof(m_texCoords.at(0)), &m_texCoords.at(0), GL_STATIC_DRAW);

    glEnableVertexAttribArray(2);
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, 0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_vertexArrayBuffers[TT_INDEX_VAB]);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, m_indices.count() * sizeof(m_indices.at(0)), &m_indices.at(0), GL_STATIC_DRAW);

    glBindVertexArray(0);
}
