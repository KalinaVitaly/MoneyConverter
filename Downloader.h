#ifndef WIDGET_H
#define WIDGET_H

#include <QDebug>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include "ParseData.h"

class DownLoader : public QObject{

    Q_OBJECT

public:
    explicit DownLoader(QObject * parent = nullptr);

    void getData();

private:
    QNetworkAccessManager *networkManager;

signals:
    void onReady();

public slots:
    void onResult(QNetworkReply *);
};

#endif // WIDGET_H
