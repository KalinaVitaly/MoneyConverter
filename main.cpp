#include "Downloader.h"
#include <QApplication>
#include "MainWidget.h"


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    DownLoader obj;
    MainWidget mw(obj);

    obj.getData();

    mw.show();

    app.exec();
}
