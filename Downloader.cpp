#include "Downloader.h"

DownLoader::DownLoader(QObject * parent)
    : QObject(parent),
      dataFromWebsite("")
{
    networkManager = new QNetworkAccessManager(this);

    connect(networkManager, SIGNAL(finished(QNetworkReply *)),
                this, SLOT(onResult(QNetworkReply *)));
}

void DownLoader::getData() {
    QUrl url("http://www.cbr.ru/currency_base/daily/");
    QNetworkRequest request;
    request.setUrl(url);
    networkManager->get(request);
}

void DownLoader::onResult(QNetworkReply *reply) {
    if (reply->error()) {
        qDebug() << reply->errorString();
        exit(1);
    } else {
        dataFromWebsite = QString(reply->readAll());
        dataMap = ParseData::parseString(dataFromWebsite);
        qDebug() << dataMap;
        emit sendData(dataMap);
    }
}

