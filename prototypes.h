#pragma once
#include <QFont>
#include <QFontMetrics>
#include <QGuiApplication>
#include <QSize>
#include <Qpoint>
#include <QtGui/QColor>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

//хранит текст слова, размер, позицию его количество, размер шрифта, цвет

class Word
{
public:
    std::string text;
    int frequency;
    QPoint position;
    QSize box;
    QColor color;
    QFont font;

    int width;
    int height;

    bool operator>(const Word &other) const;
    void calculateSize();
};

//инициализирует все поля Word
void wordStats(const std::vector<std::string> &input_words, std::vector<Word> &words);

//расскрашивает слова
QColor coloring(const int &i, const int &size);

//определяет позиции слов
QPoint wordPlace(const int &width, const int &height, const std::vector<QRect> &placedRects);

struct ImageRenderer; //использует Qt (QImage, QPainter) для рисования слов

//парсит аргументы коммандной строки
bool commandLineParse(int argc,
                      char *argv[],
                      std::string &outputFile,
                      std::vector<std::string> &input_words);

//Готовая функция, которая объединяет всё
void wordCloudGenerator(int argc, char *argv[]);
