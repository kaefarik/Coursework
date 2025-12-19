#include "prototypes.h"

void wordStats(const std::vector<std::string> &input_words,
               std::vector<Word> &words,
               int &IMAGE_WIDTH,
               int &IMAGE_HEIGHT)

{
    //Добавляем слова в вектор words
    std::unordered_map<std::string, int> wordsMap;

    for (const auto &it : input_words) {
        ++wordsMap[it];
    }

    if (wordsMap.empty()) {
        std::cerr << "Error: file is empry! Image will be empty" << std::endl;
        return;
    }

    words.reserve(wordsMap.size());

    for (const auto &it : wordsMap) {
        Word word;
        word.text = it.first;
        word.frequency = it.second;
        words.push_back(word);
    }

    //Сортируем по убыванию
    std::sort(words.begin(), words.end(), std::greater<Word>());

    const int MINFONTSIZE = 10;
    const int MAXFONTSIZE = 120;

    //определяем цвет слова, размер шрифта, размер слова
    std::vector<std::string> colors
        = {"#A87B5E", "#3E58EF", "#12B526", "#0CA07A", "#AD0D2D", "#B45E83", "#5454E8"};
    std::random_device rd;
    std::mt19937 g(rd());
    std::shuffle(colors.begin(), colors.end(), g);

    int colorIndex = 0;

    for (int i = 0; i < words.size(); ++i) {
        // если много слов
        if (words.size() > 9500) {
            std::cerr << "Error: too many words! Limit is 9500" << std::endl;
            return;
        }
        if (i > 0 && i % 500 == 0) {
            IMAGE_WIDTH = IMAGE_WIDTH * 6 / 5;
            IMAGE_HEIGHT = IMAGE_HEIGHT * 6 / 5;
        }

        //цвет
        if (colorIndex >= colors.size()) {
            std::shuffle(colors.begin(), colors.end(), g);
            colorIndex = 0;
        }
        words[i].color = QColor::fromString(colors[colorIndex]);
        colorIndex++;

        //размер шрифта
        if (i == 0) {
            words[i].fontSize = MAXFONTSIZE;
        } else if (i <= 2) {
            words[i].fontSize = MAXFONTSIZE - 20;
        } else if (i <= 5) {
            words[i].fontSize = MAXFONTSIZE - 70;
        } else if (i <= 10) {
            words[i].fontSize = MAXFONTSIZE - 80;
        } else if (i <= 20) {
            words[i].fontSize = MAXFONTSIZE - 85;
        } else if (i <= 75) {
            words[i].fontSize = MAXFONTSIZE - 90;
        } else {
            words[i].fontSize = MINFONTSIZE;
        }

        //шрифт, ширина и высота слова
        words[i].font = QFont("Chrysanthi Unicode", words[i].fontSize);
        words[i].calculateSize();
    }

    //расставляем слова
    std::vector<QRect> placedRects;
    placedRects.reserve(words.size());

    for (auto &it : words) {
        it.position = wordPlace(it.width, it.height, placedRects, IMAGE_WIDTH, IMAGE_HEIGHT);
        QRect rect(it.position.x(), it.position.y(), it.width, it.height);
        placedRects.push_back(rect);
    }
}
