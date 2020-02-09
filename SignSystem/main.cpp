#include "widget.h"
#include <QApplication>
#include "entersign.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Widget w;
    //w.show();
    EnterSign *Enter = new EnterSign;
    Enter->show();
    //QApplication a(argc, argv);

        //更改程序启动后任务栏图标

    //a.setWindowIcon(QIcon(":/new/tubiao/06 - 副本.ico"));

    Enter->setWindowIcon(QIcon(":/new/tubiao/06 - 副本.ico"));
    return a.exec();
}
