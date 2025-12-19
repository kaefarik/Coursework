#pragma once
#include <QFont>
#include <QFontDatabase>
#include <QFontMetrics>
#include <QGuiApplication>
#include <QImage>
#include <QPainter>
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
#include <random>
#include <string>
#include <vector>

//парсит аргументы коммандной строки
bool commandLineParse(int argc,
                      char *argv[],
                      std::string &outputFile,
                      std::vector<std::string> &input_words);

//хранит текст слова, размер, позицию, его количество, размер шрифта, цвет

class Word
{
public:
    std::string text;
    int frequency;
    int fontSize;
    QPoint position;
    QColor color;
    QFont font;

    int width;
    int height;

    bool operator>(const Word &other) const;
    void calculateSize();
};

//инициализирует все поля Word
void wordStats(const std::vector<std::string> &input_words,
               std::vector<Word> &words,
               int &IMAGE_WIDTH,
               int &IMAGE_HEIGHT);

//расскрашивает слова
QColor coloring(const int &i, const int &size);

//определяет позиции слов
QPoint wordPlace(const int &width,
                 const int &height,
                 const std::vector<QRect> &placedRects,
                 const int &IMAGE_WIDTH,
                 const int &IMAGE_HEIGHT);

//использует Qt (QImage, QPainter) для рисования слов
void imageRenderer(const std::vector<Word> &words,
                   const std::string &outputFile,
                   const int &IMAGE_WIDTH,
                   const int &IMAGE_HEIGHT);

//Готовая функция, которая объединяет всё
void wordCloudGenerator(int argc, char *argv[]);
