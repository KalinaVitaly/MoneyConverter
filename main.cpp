#include <Downloader.h>
#include <QApplication>
#include <QDebug>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QIODevice>
#include <QUrl>
#include <QObject>


int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QNetworkAccessManager nam;
    DownLoader obj;

    obj.getData();

//    QNetworkReply * reply = nam.get(QNetworkRequest(QUrl("http://www.cbr.ru/currency_base/daily/")));
//    QObject::connect(reply, SIGNAL(finished()), &obj, SLOT(onFinished()));
    app.exec();
}
