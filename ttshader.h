#ifndef TTSHADER_H
#define TTSHADER_H

#include <QOpenGLFunctions_4_3_Core>
#include "ttmaterial.h"
#include "ttcamera.h"
#include "tttransformation.h"

class TTShader : protected QOpenGLFunctions_4_3_Core
{
public:
    TTShader(const std::string& name);
    ~TTShader();

    void update(TTTransformation *trans, TTCamera *camera);
    void bind(TTMaterial *material, TTCamera *camera, TTTransformation *transformation);

private:
    GLuint createShader(const std::string &text, GLenum type);
    std::string loadShader(const std::string& fileName);
    void checkShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage);

    enum {
        TT_TRANSFORM_U,

        NUM_UNIFORMS
    };

    enum {
        TT_VERTEX_SHADER,
        TT_FRAGMENT_SHADER,

        NUM_SHADERS
    };

    GLuint m_program;
    GLuint m_shaders[NUM_SHADERS];
    GLint m_uniforms[NUM_UNIFORMS];
};

#endif // TTSHADER_H
