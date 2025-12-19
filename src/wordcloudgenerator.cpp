#include "prototypes.h"

void wordCloudGenerator(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    std::string outputFile;
    std::vector<std::string> input_words;
    std::vector<Word> words;
    std::unordered_map<std::string, int> freq;
    int IMAGE_WIDTH = 2000;
    int IMAGE_HEIGHT = 1000;

    if (!commandLineParse(argc, argv, outputFile, input_words)) {
        return;
    }

    QFontDatabase::addApplicationFont("chrysuni.ttf");

    wordStats(input_words, words, IMAGE_WIDTH, IMAGE_HEIGHT);
    imageRenderer(words, outputFile, IMAGE_WIDTH, IMAGE_HEIGHT);
}
