#include "ParseData.h"

void ParseData::parseString(const QString & str) {
    QString updateString = str;
    QMap<QPair<QString, qreal>, QPair<QString, qreal>> data;
    qint32 firstIndex = updateString.indexOf("<td>036</td>\r\n");
    qint32 lastIndex = 0;
    updateString.remove(0, firstIndex);
    lastIndex = updateString.indexOf("</tbody>");
    updateString.remove(lastIndex, updateString.length() - lastIndex);

    //
    // Удаляем лишнии символы
    //
    while (updateString.contains(QRegExp("\\r\\n\\s*"))) { updateString.remove(QRegExp("\\r\\n\\s*")); }
    while (updateString.contains(QRegExp("<tr>"))) { updateString.remove(QRegExp("<tr>")); }
    while (updateString.contains(QRegExp("</tr>"))) { updateString.remove(QRegExp("</tr>")); }

//    <td>826</td>
//    <td>GBP</td>
//    <td>1</td>
//    <td>Фунт стерлингов Соединенного королевства</td>
//    <td>102,4401</td>
    QPair<QString, qreal> key;
    QPair<QString, qreal> value;
//    while (!updateString.isEmpty()) {
//        updateString.remove("<td>\\d+</td>");
//        updateString.remove("<td>");
//        updateString.remove("</td>");
//        key.first = updateString.leftJustified(updateString.lastIndexOf("<td>"));
//    }

//    updateString.remove("<td>\\d+</td>");
//    updateString.remove("<td>");
//    updateString.remove("</td>");
//    key.first = updateString.leftJustified(updateString.lastIndexOf("<td>"));
//    qDebug() << key.first;
    qDebug() << updateString;
}
