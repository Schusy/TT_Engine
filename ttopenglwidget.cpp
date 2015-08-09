#include "ttopenglwidget.h"
#include "ttshader.h"
#include "vertex.h"
#include "ttmaterial.h"
#include "ttgameobject.h"

#include "sphere.h"
#include "cube.h"

#include <QVector3D>
#include <QColor>
#include <QTimer>
#include <QTime>

#include <QDebug>

static int frameCounter = 0;
static int lastFrameCounter = 0;

TTOpenGLWidget::TTOpenGLWidget(QWidget *parent) : QOpenGLWidget(parent)
{
    startFPSCounter();
    startUpdater(INT_MAX);
}

void TTOpenGLWidget::calcFPS()
{
    fps = frameCounter - lastFrameCounter;
    lastFrameCounter = frameCounter;
    emit didCalcFPS(fps);
}

void TTOpenGLWidget::initializeGL()
{
    initializeOpenGLFunctions();

    m_scene = TTScene::instance();
    m_scene->m_lightPos = glm::vec3(3.0, 3.0, 3.0);

    QVector<Vertex> vertices;
    Vertex v1(glm::vec3(-1, -1, 0), glm::vec3(0, 0, 1), glm::vec2(0, 0));
    Vertex v2(glm::vec3( 1, -1, 0), glm::vec3(0, 0, 1), glm::vec2(1, 0));
    Vertex v3(glm::vec3( 0,  1, 0), glm::vec3(0, 0, 1), glm::vec2(0.5, 1));
    vertices.push_back(v1);
    vertices.push_back(v2);
    vertices.push_back(v3);

    //qDebug() << vertices.count();

    QVector<unsigned int> indices;
    indices.push_back(0);
    indices.push_back(1);
    indices.push_back(2);

    TTStaticMesh *mesh = new TTStaticMesh(vertices, indices);

    TTMaterial *material = new TTMaterial();
    QImage *texture = new QImage(":/res/textures/sp-studio2.jpg");
    //material->initWithTexture(texture);
    material->initWithColor(QColor(Qt::gray));

    TTShader *shader = new TTShader(":/shaders/basicshader");
    //shader->update(new TTTransformation(), m_mainCamera);
    //TTGameObject *object = new TTGameObject();
    //Cube *object = new Cube();
    Sphere *object = new Sphere(40); // 2365!
    object->setMaterial(material);
    //object->setMesh(mesh);
    object->setShader(shader);
    m_scene->addGameObject(object);

    m_mainCamera = new TTCamera(glm::vec3(0, 0, 5), 70.0f, (float)width()/height(), 0.1, 100.0);

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glClearColor(0.0, 0.3, 0.7, 1.0);

}

void TTOpenGLWidget::resizeGL(int width, int height)
{
    m_mainCamera->setAspect((float)width/height);
}

void TTOpenGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);

    for (int i = 0; i < m_scene->numberOfGameObjects(); i++) {
        m_scene->gameObjectAtIndex(i)->render(m_mainCamera);
    }

    frameCounter++;

    //glFlush();
}

void TTOpenGLWidget::startFPSCounter()
{
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(calcFPS()));
    timer->start(1000);
}

void TTOpenGLWidget::startUpdater(int maxFPS)
{
    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(update()));
    int updateTime = ceil((float)1000 / maxFPS);
    timer->start(updateTime);
}

