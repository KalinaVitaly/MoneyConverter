#include "ParseData.h"

void ParseData::parseString(const QString & str) {
    QStringList dataList;
    QString updateString = str;
    QMap<QPair<QString, double>, QPair<QString, double>> dataMap;
    qint32 lastIndex = 0;
    QPair<QString, double> key;
    QPair<QString, double> value;

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
                key.first = dataList[i];
            } else if (elem == 2) {
                key.second = dataList[i].toDouble();
            } else if (elem == 3) {
                value.first = dataList[i];
            } else if (elem == 4) {
                value.second = dataList[i].toDouble();
            }
        } else {
            dataMap.insert(key, value);
            continue;
        }
    }

    qDebug() << dataMap;
    //qDebug() << dataList;
}
