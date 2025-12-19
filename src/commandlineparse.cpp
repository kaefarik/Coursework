#include "prototypes.h"

//https://stackoverflow.com/questions/51949/how-to-get-file-extension-from-string-in-c
bool commandLineParse(int argc,
                      char *argv[],
                      std::string &outputFile,
                      std::vector<std::string> &input_words)
{
    // argc
    if (argc < 3) {
        std::cerr << "Error: expected at least 2 arguments: output.jpg words..." << std::endl;
        return false;
    }

    // check extention
    std::filesystem::path outputFilePath = argv[1];
    if (outputFilePath.extension() != ".jpg") {
        std::cerr << "Error: invalid output extension, expected .jpg" << std::endl;
        return false;
    }
    outputFile = argv[1];
    int startIndex = 2;
    //добавляем слова из txt в вектор input_words, если такой есть
    std::filesystem::path txtFilePath = argv[2];
    if (txtFilePath.extension() == ".txt") {
        std::ifstream file(txtFilePath);
        if (!file.is_open()) {
            std::cerr << "Error opening file for reading!" << std::endl;
            return false;
        }

        std::string line;
        while (file >> line) {
            input_words.push_back(line);
        }
        startIndex = 3;
        file.close();
    }
    //добавляем слова из командной строки в вектор words
    for (int i = startIndex; i < argc; i++) {
        input_words.push_back(argv[i]);
    }

    return true;
}
