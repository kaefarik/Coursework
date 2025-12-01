#include "prototypes.h"

void wordStats(const std::vector<std::string> &input_words, std::vector<Word> &words)
{
    std::unordered_map<std::string, int> wordsMap;

    for (const auto &it : input_words) {
        ++wordsMap[it];
    }

    if (wordsMap.empty()) {
        std::cerr << "Error: file is empry!" << std::endl;
        return;
    }

    int minFreq = wordsMap.begin()->second;
    int maxFreq = wordsMap.begin()->second;

    for (const auto &it : wordsMap) {
        int f = it.second;
        if (f < minFreq)
            minFreq = f;
        if (f > maxFreq)
            maxFreq = f;
    }

    //чтобы не было деления на 0
    if (minFreq == maxFreq) {
        ++maxFreq;
    }

    const int MINFONTSIZE = 10;
    const int MAXFONTSIZE = 50;

    words.reserve(wordsMap.size());

    for (const auto &it : wordsMap) {
        Word word;
        word.text = it.first;
        word.frequency = it.second;
        int fontSize = MINFONTSIZE
                       + (word.frequency - minFreq) * (MAXFONTSIZE - MINFONTSIZE)
                             / (maxFreq - minFreq);
        word.font.setPointSize(fontSize);
        word.calculateSize();
        word.box = QSize(word.width, word.height);

        words.push_back(word);
    }

    //сортируем по убыванию и определяем цвет слова
    std::sort(words.begin(), words.end(), std::greater<Word>());

    int size = words.size();
    for (int i = 0; i < size; ++i) {
        words[i].color = coloring(i, size);
    }

    //расставляем слова
    std::vector<QRect> placedRects;
    placedRects.reserve(size);

    for (auto &it : words) {
        it.position = wordPlace(it.width, it.height, placedRects);

        QRect rect(it.position, it.box);
        placedRects.push_back(rect);
    }

    for (const auto &it : words) {
        std::cout << it.position.x() << " " << it.position.y() << std::endl;
    }
}
