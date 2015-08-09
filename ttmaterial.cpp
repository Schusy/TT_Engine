#include "ttmaterial.h"
#include <QGLWidget>

#include <QDebug>

TTMaterial::TTMaterial()
{
    initializeOpenGLFunctions();
}

TTMaterial::~TTMaterial()
{

}


void TTMaterial::initWithTexture(QImage *tex)
{
    m_texture = tex;

    QImage glImage = QGLWidget::convertToGLFormat(*tex);
    int width = glImage.width();
    int height = glImage.height();

    unsigned char *imageData = glImage.bits();

    if (imageData == NULL) {
        qDebug() << "Error: Image data is null";
    }

    glGenTextures(1, &m_glTexture);
    glBindTexture(GL_TEXTURE_2D, m_glTexture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imageData);

    m_useTexture = true;
}

void TTMaterial::initWithColor(const QColor& col)
{
    QImage *img = new QImage(128, 128, QImage::Format_RGB32);
    img->fill(col);
    //m_texture = img;

    initWithTexture(img);

    // need this?
    m_useTexture = false;
}

void TTMaterial::bind(unsigned int unit)
{
    glActiveTexture(GL_TEXTURE0 + unit);
    glBindTexture(GL_TEXTURE_2D, m_glTexture);
}
