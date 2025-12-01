#include "prototypes.h"

QColor coloring(const int &i, const int &size)
{
    srand(time(0));
    // 1. Равномерно распределяем оттенки по кругу
    double baseHue = (i * 360.0) / size;

    // 2. Добавляем небольшой шум ±10°
    double hue = baseHue + (rand() % 21 - 10);

    // Нормализуем hue в диапазон 0–360
    if (hue < 0)
        hue += 360;
    if (hue >= 360)
        hue -= 360;

    // 3. Генерируем мягкие, приятные цвета через HSL
    double saturation = 0.55 + (rand() % 20) / 100.0; // от 0.55 до 0.75
    double lightness = 0.45 + (rand() % 20) / 100.0;  // от 0.45 до 0.65

    return QColor::fromHslF(hue / 360.0, saturation, lightness);
}
