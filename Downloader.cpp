#include "Downloader.h"

DownLoader::DownLoader(QObject * parent)
    :QObject(parent) {
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
    } else {
        ParseData::parseString(reply->readAll());
    }
}
