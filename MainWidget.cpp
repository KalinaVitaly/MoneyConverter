#include "MainWidget.h"

MainWidget::MainWidget(DownLoader &downloader, QWidget *parent)
    : QWidget(parent),
      moneyShortName(new QLabel),
      moneyFullName(new QLabel),
      value(new QLabel),
      mainLayout(new QHBoxLayout(this))
{
    mainLayout->addWidget(moneyShortName);
    mainLayout->addWidget(moneyFullName);
    mainLayout->addWidget(value);

    QObject::connect(&downloader, SIGNAL(sendData(const QMap<QString, QPair<QString, qreal>>&)),
                        this, SLOT(getMapData(const QMap<QString, QPair<QString, qreal>>&)));
}

void MainWidget::getMapData(const QMap<QString, QPair<QString, qreal>> & data) {
    dataMap = data;
    moneyShortName->setText("AMD");
    moneyFullName->setText(data["AMD"].first);
    value->setText(QString::number(data["AMD"].second));
    update();
}
