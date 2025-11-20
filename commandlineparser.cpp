#include "prototypes.h"

//https://stackoverflow.com/questions/51949/how-to-get-file-extension-from-string-in-c
bool CommandLineParser::parse(int argc,
                              char *argv[],
                              std::string &outputFile,
                              std::vector<std::string> &words)
{
    // argc
    if (argc < 3) {
        std::cerr << "Error: expected at least 2 arguments: output.jpg words..." << std::endl;
        return false;
    }

    // check extention
    std::filesystem::path outputFilePath = argv[1];
    if (outputFilePath.extension() != ".jpg" && outputFilePath.extension() != ".jpeg") {
        std::cerr << "Error: invalid output extension, expected .jpg or .jpeg." << std::endl;
        return false;
    }
    outputFile = argv[1];
    int startIndex = 2;
    //добавляем слова из txt в вектор words, если такой есть
    std::filesystem::path txtFilePath = argv[2];
    if (txtFilePath.extension() == ".txt") {
        std::ifstream file(txtFilePath);
        if (!file.is_open()) {
            std::cerr << "Error opening file for reading!" << std::endl;
            return false;
        }

        std::string line;
        while (file >> line) {
            words.push_back(line);
        }
        startIndex = 3;
    }
    //добавляем слова из командной строки в вектор words
    for (int i = startIndex; i < argc; i++) {
        words.push_back(argv[i]);
    }

    return true;
}
