#include "prototypes.h"

int main(int argc, char *argv[])
{
    CommandLineParser parser;
    std::string outputFile;
    std::vector<std::string> words;
    if (!parser.parse(argc, argv, outputFile, words)) {
        return 0;
    }

    return 0;
}
