#ifndef TTMATERIAL_H
#define TTMATERIAL_H

#include <QColor>
#include <QImage>
#include <QOpenGLFunctions_4_3_Core>

class TTMaterial : protected QOpenGLFunctions_4_3_Core
{
public:
    TTMaterial();
    ~TTMaterial();

    void initWithTexture(QImage *tex);
    void initWithColor(const QColor& col);

    void bind(unsigned int unit);

private:
    QImage *m_texture;
    GLuint m_glTexture;

    // need this?
    bool m_useTexture;
};

#endif // TTMATERIAL_H
