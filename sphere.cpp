#include "sphere.h"

Sphere::Sphere(int resolution)
{
    // Add one column of vertices twice for texture coordinates
    double omega, phi;
    int numVerts = 0;
    //QVector<glm::vec3> positions;
    //QVector<glm::vec3> normals;
    //QVector<glm::vec2> texCoords;
    QVector<Vertex> vertices;
    for (int i = 0; i < resolution + 1; i++) {
        omega = 2 * M_PI * i / resolution;
        for (int j = 0; j < resolution; j++) {
            phi = M_PI * j / (resolution - 1) - M_PI / 2;
            glm::vec3 v(sin(phi), sin(omega) * cos(phi), -cos(omega) * cos(phi));
//            positions.push_back(v);
//            normals.push_back(v / v.length());
//            texCoords.push_back(texCoord(omega, phi));
            vertices.push_back(Vertex(v, glm::normalize(v), texCoords(omega, phi)));
            numVerts++;
        }
    }

    QVector<unsigned int> triangles;
    int size2 = numVerts;
    int size = numVerts - resolution;
    for (int i = 0; i < resolution + 1; i++) {
        for (int j = 0; j < resolution - 1; j++) {
            if (i != resolution - 1) {
                if (j != resolution - 2) {
                    triangles.push_back((i * resolution + j) % size);
                    triangles.push_back((i * resolution + j + 1) % size);
                    triangles.push_back(((i + 1) * resolution + j + 1) % size);
                }
                if (j != 0) {
                    triangles.push_back(((i + 1) * resolution + j + 1) % size);
                    triangles.push_back(((i + 1) * resolution + j) % size);
                    triangles.push_back((i * resolution + j) % size);
                }
            } else {
                triangles.push_back((i * resolution + j) % size2);
                triangles.push_back((i * resolution + j + 1) % size2);
                triangles.push_back(((i + 1) * resolution + j + 1) % size2);

                triangles.push_back(((i + 1) * resolution + j + 1) % size2);
                triangles.push_back(((i + 1) * resolution + j) % size2);
                triangles.push_back((i * resolution + j) % size2);
            }
        }
    }
//    for (int i = 0; i < resolution + 1; i++) {
//        for (int j = 0; j < resolution - 1; j++) {
//            // First and last batch only render one triangle per face;
//            // cases: j = 0 and j = resY - 2;
//            if (j != 0) {
//                triangles.push_back((i * resY + j + 1) % numVerts);
//                triangles.push_back((i * resY + j) % numVerts);
//                triangles.push_back(((i + 1) * resY + j) % numVerts);
//            }
//            if (j != resY-2) {
//                triangles.push_back((i * resY + j + 1) % numVerts);
//                triangles.push_back(((i + 1) * resY + j) % numVerts);
//                triangles.push_back(((i + 1) * resY + j + 1) % numVerts);
//            }
//        }
//    }
    TTStaticMesh *m = new TTStaticMesh(&vertices[0], numVerts, &triangles[0], triangles.size());
    setMesh(m);
}

Sphere::~Sphere()
{

}

glm::vec2 Sphere::texCoords(double omega, double phi)
{
    return glm::vec2(omega / (2 * M_PI), -0.5 * (1 - sin(phi)));
}

