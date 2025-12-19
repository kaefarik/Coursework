#include "prototypes.h"

void imageRenderer(const std::vector<Word> &words,
                   const std::string &outputFile,
                   const int &IMAGE_WIDTH,
                   const int &IMAGE_HEIGHT)
{
    QString filePath = QString::fromStdString(outputFile);
    QImage image(IMAGE_WIDTH, IMAGE_HEIGHT, QImage::Format_RGB32);
    image.fill(Qt::white);

    QPainter painter(&image);

    for (const auto &it : words) {
        //QFont font("Chrysanthi Unicode", it.fontSize);
        painter.setFont(it.font);
        painter.setPen(it.color);

        QRect rect(it.position.x(), it.position.y(), it.width, it.height);

        painter.drawText(rect, Qt::AlignCenter, QString::fromStdString(it.text));
    }

    image.save(filePath);
}
