#include "ttmainwindow.h"
#include "ui_ttmainwindow.h"

#include "ttscene.h"

TTMainWindow::TTMainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::TTMainWindow)
{
    ui->setupUi(this);
    connect(ui->openGLWidget, SIGNAL(didCalcFPS(int)), this, SLOT(showFPS(int)));
}

TTMainWindow::~TTMainWindow()
{
    delete ui;
}

void TTMainWindow::showFPS(int fps)
{
    TTScene *scene = TTScene::instance();
    int vertices = 0;
    int triangles = 0;
    for (int i = 0; i < scene->numberOfGameObjects(); i++) {
        vertices += scene->gameObjectAtIndex(i)->numVertices();
        triangles += scene->gameObjectAtIndex(i)->numTriangles();
    }

    QString message("");
    message.append(QString::number(fps));
    message.append(" FPS;   ");
    message.append(QString::number(vertices));
    message.append(" vertices;   ");
    message.append(QString::number(triangles));
    message.append(" triangles;");

    ui->statusBar->showMessage(message);
}
