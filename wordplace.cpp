#include "prototypes.h"

QPoint wordPlace(const int &width, const int &height, const std::vector<QRect> &placedRects)
{
    const int IMAGE_WIDTH = 1280;
    const int IMAGE_HEIGHT = 720;

    int centerX = IMAGE_WIDTH / 2;
    int centerY = IMAGE_HEIGHT / 2;

    float angle = 0;
    float radius = 0;
    const float ANGLESTEP = 0.1;  // шаг по углу (рад)
    const float RADIUSSTEP = 1.0; // шаг по радиусу

    while (true) {
        int x = centerX + std::cos(angle) * radius;
        int y = centerY + std::sin(angle) * radius;

        QRect rect(x, y, width, height);

        // Проверка границ
        if (x < 0 || y < 0 || x + width > IMAGE_WIDTH || y + height > IMAGE_HEIGHT) {
            // Выходим за границы — продолжаем по спирали
            angle += ANGLESTEP;
            radius += RADIUSSTEP;
            continue;
        }

        // Проверка пересечений
        bool ok = true;
        for (const auto &it : placedRects) {
            if (rect.intersects(it)) {
                ok = false;
                break;
            }
        }

        //нашли свободное место
        if (ok) {
            return QPoint(x, y);
        }

        // Переходим дальше по спирали
        angle += ANGLESTEP;
        radius += RADIUSSTEP;
    }
}
