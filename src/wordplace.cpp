#include "prototypes.h"

QPoint wordPlace(const int &width,
                 const int &height,
                 const std::vector<QRect> &placedRects,
                 const int &IMAGE_WIDTH,
                 const int &IMAGE_HEIGHT)
{
    const int centerX = IMAGE_WIDTH / 2;
    const int centerY = IMAGE_HEIGHT / 2;

    // Лямбда для проверки возможности размещения (стандартная)
    auto canPlace = [&](int x, int y) -> bool {
        if (x < 0 || y < 0 || x + width > IMAGE_WIDTH || y + height > IMAGE_HEIGHT) {
            return false;
        }
        QRect candidate(x, y, width, height);
        for (const auto &rect : placedRects) {
            if (candidate.intersects(rect)) {
                return false;
            }
        }
        return true;
    };

    int wordIndex = placedRects.size();

    //первые три слова

    if (wordIndex == 0) {
        // 1. Самое большое слово по центру
        int x = centerX - width / 2;
        int y = centerY - height / 2;
        if (canPlace(x, y)) {
            return QPoint(x, y);
        }
    } else if (wordIndex == 1 && !placedRects.empty()) {
        // 2. Второе слово над центральным
        const QRect &centerRect = placedRects[0];

        // РАССЧИТЫВАЕМ НАЛОЖЕНИЕ
        // Смещаем слово вниз на 25% его высоты, чтобы убрать пустой отступ шрифта
        int overlap = height / 4;

        int x = centerRect.center().x() - width / 2;
        // top - height + overlap (сдвигаем ниже, внутрь центрального)
        int y = centerRect.top() - height + overlap;

        return QPoint(x, y);

    } else if (wordIndex == 2 && !placedRects.empty()) {
        // 3. Третье слово под центральным
        const QRect &centerRect = placedRects[0];

        // РАССЧИТЫВАЕМ НАЛОЖЕНИЕ
        int overlap = height / 4;

        int x = centerRect.center().x() - width / 2;
        // bottom - overlap (сдвигаем выше, внутрь центрального)
        int y = centerRect.bottom() - overlap;

        return QPoint(x, y);
    }

    // Спирально размещаем остальные слова

    const double ellipseA = (IMAGE_WIDTH / 2.0) * 0.9;
    const double ellipseB = (IMAGE_HEIGHT / 2.0) * 0.9;

    double angle = 0.0;
    double radius = 0.0;

    if (wordIndex > 2) {
        angle = (wordIndex * 7) % 360;
    }

    const double angleStep = 0.1;
    const double radiusGrowth = 0.002;

    while (true) {
        int x = centerX + radius * ellipseA * std::cos(angle) - width / 2;
        int y = centerY + radius * ellipseB * std::sin(angle) - height / 2;

        if (canPlace(x, y)) {
            return QPoint(x, y);
        }

        angle += angleStep;
        radius += radiusGrowth;
    }
    //return QPoint(-1, -1);
}
