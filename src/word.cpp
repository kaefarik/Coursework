#include "prototypes.h"

bool Word::operator>(const Word &other) const
{
    return frequency > other.frequency;
}

void Word::calculateSize()
{
    QFontMetrics metrics(font);
    QRect rect = metrics.boundingRect(QString::fromStdString(text));
    const int PADDING = 4;
    width = rect.width() + PADDING;
    height = rect.height() + PADDING;
}
