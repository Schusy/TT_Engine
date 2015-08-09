#include "ttshader.h"

#include <QFile>

#include <QDebug>


TTShader::TTShader(const std::string &fileName)
{
    initializeOpenGLFunctions();

    m_program = glCreateProgram();

    m_shaders[0] = createShader(loadShader(fileName + ".vert"), GL_VERTEX_SHADER);
    m_shaders[1] = createShader(loadShader(fileName + ".fsh"), GL_FRAGMENT_SHADER);

    for (unsigned int i = 0; i < NUM_SHADERS; i++) {
        glAttachShader(m_program, m_shaders[i]);
    }

    glLinkProgram(m_program);
    checkShaderError(m_program, GL_LINK_STATUS, true, "Linking failed:");

    glValidateProgram(m_program);
    checkShaderError(m_program, GL_VALIDATE_STATUS, true, "Program is invalid:");

    m_uniforms[TT_TRANSFORM_U] = glGetUniformLocation(m_program, "transformation");
}

TTShader::~TTShader()
{
    for (int i = 0; i < NUM_SHADERS; ++i) {
        glDetachShader(m_program, m_shaders[i]);
        glDeleteShader(m_shaders[i]);
    }
    glDeleteProgram(m_program);
}

void TTShader::update(TTTransformation *transformation, TTCamera *camera)
{
    glm::mat4 mvp = camera->getViewProjection() * transformation->getModel();
    glUniformMatrix4fv(m_uniforms[TT_TRANSFORM_U], 1, GL_FALSE, &mvp[0][0]);
}

void TTShader::bind(TTMaterial *material, TTCamera *camera, TTTransformation *transformation)
{
    //qDebug() << "shader bound";
    glUseProgram(m_program);
    glm::mat4 mvp = camera->getViewProjection() * transformation->getModel();
    glUniformMatrix4fv(m_uniforms[TT_TRANSFORM_U], 1, GL_FALSE, &mvp[0][0]);
}

GLuint TTShader::createShader(const std::string &text, GLenum type)
{
    GLuint shader = glCreateShader(type);

    if (shader == 0)
        qDebug() << "Shader creation failed!";

    const GLchar* shaderSourceStrings[1];
    shaderSourceStrings[0] = text.c_str();
    GLint shaderSourceStringLengths[1];
    shaderSourceStringLengths[0] = text.length();

    glShaderSource(shader, 1, shaderSourceStrings, shaderSourceStringLengths);
    glCompileShader(shader);
    checkShaderError(shader, GL_COMPILE_STATUS, false, "Shader did not compile:");

    return shader;
}

// TODO: Create Util class to handle all I/O
std::string TTShader::loadShader(const std::string &fileName)
{
    std::string result = "";
        QFile file(QString::fromStdString(fileName));
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            qDebug() << "Could not open Shader file";
            return result;
        }

        QString shaderString;

        QTextStream in(&file);
        while (!in.atEnd()) {
            QString line = in.readLine();
            shaderString.append(line + "\n");
        }

        result = shaderString.toStdString();

        return result;
}

void TTShader::checkShaderError(GLuint shader, GLuint flag, bool isProgram, const std::string& errorMessage)
{
    GLint success = 0;
    GLchar error[1024] = { 0 };

    if (isProgram)
        glGetProgramiv(shader, flag, &success);
    else
        glGetShaderiv(shader, flag, &success);

    if (success == GL_FALSE) {
        if (isProgram)
            glGetProgramInfoLog(shader, sizeof(error), NULL, error);
        else
            glGetShaderInfoLog(shader, sizeof(error), NULL, error);

        qDebug() << QString::fromStdString(errorMessage) << " " << QString::fromUtf8(error);
    }
}
