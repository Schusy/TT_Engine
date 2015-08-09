#ifndef TTMAINWINDOW_H
#define TTMAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class TTMainWindow;
}

class TTMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit TTMainWindow(QWidget *parent = 0);
    ~TTMainWindow();

public slots:
    void showFPS(int fps);

private:
    Ui::TTMainWindow *ui;
};

#endif // TTMAINWINDOW_H
