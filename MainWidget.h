#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QMap>
#include "Downloader.h"

class MainWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MainWidget(DownLoader &downloader, QWidget *parent = nullptr);

private:
    QMap<QString, QPair<QString, qreal>> dataMap;

    QLabel *moneyShortName;
    QLabel *moneyFullName;
    QLabel *value;
    QHBoxLayout *mainLayout;

protected slots:
    void getMapData(const QMap<QString, QPair<QString, qreal>> &);
};

#endif // MAINWIDGET_H
