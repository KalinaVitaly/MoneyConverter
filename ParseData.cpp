#include "ParseData.h"

void ParseData::parseString(const QString & str) {
    qint32 firstIndex = str.indexOf("<tbody>");
    qint32 lastIndex = str.indexOf("</tbody>");
    qDebug() << str.mid(firstIndex, lastIndex - firstIndex);
}
