#pragma once
#include <QSize>
#include <Qpoint>
#include <QtGui/QColor>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

struct Word;          //хранит текст слова, размер, позицию
struct WordStats;     //считает частоты слов и вычисляет размеры шрифта
struct LayoutManager; //расставляет слова по координатам, проверяет пересечения
struct ImageRenderer; //использует Qt (QImage, QPainter) для рисования слов
class CommandLineParser //парсит аргументы командной строки
{
public:
    bool parse(int argc, char *argv[], std::string &outputFile, std::vector<std::string> &words);
};
struct WordCloudGenerator; //объединяет всё: парсинг → генерация → сохранение изображения
