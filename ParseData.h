#ifndef PARSEDATA_H
#define PARSEDATA_H

#include <QDebug>

class ParseData
{
public:
    explicit ParseData();

    static QMap<QString, QPair<QString, double>> parseString(const QString &);
};

#endif // PARSEDATA_H
