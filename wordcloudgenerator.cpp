#include "prototypes.h"

void wordCloudGenerator(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);
    std::string outputFile;
    std::vector<std::string> input_words;
    std::vector<Word> words;
    std::unordered_map<std::string, int> freq;

    if (!commandLineParse(argc, argv, outputFile, input_words)) {
        return;
    }

    wordStats(input_words, words);
}
