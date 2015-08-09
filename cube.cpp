#include "cube.h"

QVector<glm::vec3> Cube::positions()
{
    glm::vec3 pos0(-1, 1, 1); //    left    top     front
    glm::vec3 pos1(1, 1, 1); //     right
    glm::vec3 pos2(-1, -1, 1); //   left    bottom
    glm::vec3 pos3(1, -1, 1); //    right
    glm::vec3 pos4(-1, 1, -1); //   left    top     back
    glm::vec3 pos5(1, 1, -1); //    right
    glm::vec3 pos6(-1, -1, -1); //  left    bottom
    glm::vec3 pos7(1, -1, -1); //   right
    QVector<glm::vec3> positions;
    positions.push_back(pos0);  // Add every corner 3 times
    positions.push_back(pos0);
    positions.push_back(pos0);
    positions.push_back(pos1);
    positions.push_back(pos1);
    positions.push_back(pos1);
    positions.push_back(pos2);
    positions.push_back(pos2);
    positions.push_back(pos2);
    positions.push_back(pos3);
    positions.push_back(pos3);
    positions.push_back(pos3);
    positions.push_back(pos4);
    positions.push_back(pos4);
    positions.push_back(pos4);
    positions.push_back(pos5);
    positions.push_back(pos5);
    positions.push_back(pos5);
    positions.push_back(pos6);
    positions.push_back(pos6);
    positions.push_back(pos6);
    positions.push_back(pos7);
    positions.push_back(pos7);
    positions.push_back(pos7);
    return positions;
}

QVector<glm::vec3> Cube::normals()
{
    glm::vec3 norm0(1, 0, 0);
    glm::vec3 norm1(-1, 0, 0);
    glm::vec3 norm2(0, 1, 0);
    glm::vec3 norm3(0, -1, 0);
    glm::vec3 norm4(0, 0, 1);
    glm::vec3 norm5(0, 0, -1);
    QVector<glm::vec3> normals;
    normals.push_back(norm1);   // Add normal for every corner in order: X, Y, Z
    normals.push_back(norm2);
    normals.push_back(norm5);
    normals.push_back(norm0);
    normals.push_back(norm2);
    normals.push_back(norm5);
    normals.push_back(norm1);
    normals.push_back(norm3);
    normals.push_back(norm5);
    normals.push_back(norm0);
    normals.push_back(norm3);
    normals.push_back(norm5);
    normals.push_back(norm1);
    normals.push_back(norm2);
    normals.push_back(norm4);
    normals.push_back(norm0);
    normals.push_back(norm2);
    normals.push_back(norm4);
    normals.push_back(norm1);
    normals.push_back(norm3);
    normals.push_back(norm4);
    normals.push_back(norm0);
    normals.push_back(norm3);
    normals.push_back(norm4);
    return normals;
}

QVector<glm::vec2> Cube::texCoords()
{
    glm::vec2 tex0(0,0);
    glm::vec2 tex1(0,1);
    glm::vec2 tex2(1,0);
    glm::vec2 tex3(1,1);
    QVector<glm::vec2> texCoords;
    texCoords.push_back(tex3);
    texCoords.push_back(tex0);
    texCoords.push_back(tex1);
    texCoords.push_back(tex1);
    texCoords.push_back(tex2);
    texCoords.push_back(tex3);
    texCoords.push_back(tex2);
    texCoords.push_back(tex2);
    texCoords.push_back(tex0);
    texCoords.push_back(tex0);
    texCoords.push_back(tex0);
    texCoords.push_back(tex2);
    texCoords.push_back(tex1);
    texCoords.push_back(tex1);
    texCoords.push_back(tex3);
    texCoords.push_back(tex3);
    texCoords.push_back(tex3);
    texCoords.push_back(tex1);
    texCoords.push_back(tex0);
    texCoords.push_back(tex3);
    texCoords.push_back(tex2);
    texCoords.push_back(tex2);
    texCoords.push_back(tex1);
    texCoords.push_back(tex0);
    return texCoords;
}

QVector<unsigned int> Cube::triangles()
{
    QVector<unsigned int> tris;
    // multiply all indices by 3 due to normals
    tris.push_back(0 * 3 + 2); // front; plane perpendicular to z-axis -> increase index by 2
    tris.push_back(2 * 3 + 2);
    tris.push_back(1 * 3 + 2);
    tris.push_back(2 * 3 + 2);
    tris.push_back(3 * 3 + 2);
    tris.push_back(1 * 3 + 2);
    tris.push_back(4 * 3 + 2); // back
    tris.push_back(5 * 3 + 2);
    tris.push_back(6 * 3 + 2);
    tris.push_back(5 * 3 + 2);
    tris.push_back(7 * 3 + 2);
    tris.push_back(6 * 3 + 2);
    tris.push_back(4 * 3 + 1); // top; plane perpendicular to y-axis -> increase index by 1
    tris.push_back(0 * 3 + 1);
    tris.push_back(1 * 3 + 1);
    tris.push_back(1 * 3 + 1);
    tris.push_back(5 * 3 + 1);
    tris.push_back(4 * 3 + 1);
    tris.push_back(6 * 3 + 1); // bottom
    tris.push_back(3 * 3 + 1);
    tris.push_back(2 * 3 + 1);
    tris.push_back(7 * 3 + 1);
    tris.push_back(3 * 3 + 1);
    tris.push_back(6 * 3 + 1);
    tris.push_back(0 * 3); // left; plane perpendicular to x-axis -> no need to increase index
    tris.push_back(6 * 3);
    tris.push_back(2 * 3);
    tris.push_back(0 * 3);
    tris.push_back(4 * 3);
    tris.push_back(6 * 3);
    tris.push_back(1 * 3); // right
    tris.push_back(3 * 3);
    tris.push_back(7 * 3);
    tris.push_back(1 * 3);
    tris.push_back(7 * 3);
    tris.push_back(5 * 3);
    return tris;
}

Cube::Cube()
{
    // Creates a Cube from (-1, -1, -1) to (1, 1, 1);
    QVector<glm::vec3> pos = positions();
    QVector<glm::vec3> norm = normals();
    QVector<glm::vec2> tex = texCoords();
    QVector<unsigned int> tri = triangles();
    unsigned int numVertices = pos.count();
    unsigned int numIndices = tri.count();
    Vertex vertices[numVertices];
    unsigned int indices[numIndices];

    for (int i = 0; i < numVertices; i++) {
        vertices[i] = Vertex(pos.at(i), norm.at(i), tex.at(i));
    }
    for (int j = 0; j < numIndices; j++) {
        indices[j] = tri.at(j);
    }
    TTStaticMesh *m = new TTStaticMesh(&vertices[0], numVertices, &indices[0], numIndices);
    setMesh(m);
}

Cube::~Cube()
{

}

