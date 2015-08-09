#ifndef TTOPENGLWIDGET_H
#define TTOPENGLWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions_4_3_Core>

#include "ttcamera.h"
#include "ttscene.h"

class TTOpenGLWidget : public QOpenGLWidget, protected QOpenGLFunctions_4_3_Core
{
    Q_OBJECT
public:
    explicit TTOpenGLWidget(QWidget *parent = 0);

signals:
    void didCalcFPS(int fps);

public slots:
    void calcFPS();

protected:
    void initializeGL();
    void resizeGL(int width, int height);
    void paintGL();

private:
    TTCamera *m_mainCamera;
    TTScene *m_scene;

    int fps;
    void startFPSCounter();

    void startUpdater(int maxFPS);
};

#endif // TTOPENGLWIDGET_H
