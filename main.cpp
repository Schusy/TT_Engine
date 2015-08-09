#include "ttmainwindow.h"
#include <QApplication>
#include <QSurfaceFormat>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSurfaceFormat format;

    format.setVersion(4,3);
    format.setProfile(QSurfaceFormat::CoreProfile);

    format.setAlphaBufferSize(8);
    format.setRedBufferSize(8);
    format.setGreenBufferSize(8);
    format.setBlueBufferSize(8);
    format.setDepthBufferSize(8);

    format.setSwapBehavior(QSurfaceFormat::DoubleBuffer);
    format.setSwapInterval(1);

    QSurfaceFormat::setDefaultFormat(format);

    TTMainWindow w;
    w.show();

    return a.exec();
}
