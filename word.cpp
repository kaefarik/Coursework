#include "prototypes.h"

bool Word::operator>(const Word &other) const
{
    return frequency > other.frequency;
}

void Word::calculateSize()
{
    QFontMetrics metrics(font);
    width = metrics.horizontalAdvance(QString::fromStdString(text));
    height = metrics.height();
}
