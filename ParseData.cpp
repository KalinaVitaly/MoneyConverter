#include "ParseData.h"

QMap<QString, QPair<QString, double>> ParseData::parseString(const QString & str) {
    QStringList dataList;
    QString updateString = str;
    QString key;
    QMap<QString, QPair<QString, double>> dataMap;
    QPair<QString, qreal> value;
    qint32 lastIndex = 0;
    qreal coefficient = 0;

    //
    // Удаляем лишнии символы
    //
    updateString.remove(0, updateString.indexOf("<td>036</td>\r\n"));
    lastIndex = updateString.indexOf("</tbody>");
    updateString.remove(lastIndex, updateString.length() - lastIndex);

    while (updateString.contains(QRegExp("\\r\\n\\s*"))) { updateString.remove(QRegExp("\\r\\n\\s*")); }
    while (updateString.contains(QRegExp("<tr>"))) { updateString.remove(QRegExp("<tr>")); }
    while (updateString.contains(QRegExp("</tr>"))) { updateString.remove(QRegExp("</tr>")); }

    updateString.remove(QRegExp("<td>"));
    updateString.replace(QRegExp(","), ".");
    dataList = updateString.split("</td>", Qt::SkipEmptyParts);

    //
    //  Создаем пары ключ-значение
    //
    qint32 elem = 0;
    for (qint32 i = 1; i < dataList.length(); ++i) {
        elem = i % 5;
        if (elem >= 1 && elem <= 4) {
            if (elem == 1) {
                key = dataList[i];
            } else if (elem == 2) {
                coefficient = dataList[i].toDouble();
            } else if (elem == 3) {
                value.first = dataList[i];
            } else if (elem == 4) {
                value.second = dataList[i].toDouble() / coefficient;
            }
        } else {
            dataMap.insert(key, value);
            continue;
        }
    }

    //qDebug() << dataMap;
    //qDebug() << dataList;
    return dataMap;
}
