#include "prototypes.h"
#include <gtest/gtest.h>

class WordCloudGeneratorTest : public ::testing::Test
{
public:
    int IMAGE_WIDTH = 2000;
    int IMAGE_HEIGHT = 1000;

    // Папка для сохранения тестовых изображений
    std::string outputDir = "./test_images/";

    void SetUp() override
    {
        // Создаём папку для изображений, если её нет
        std::filesystem::create_directories(outputDir);
    }

    std::string getOutputPath(const std::string &testName)
    {
        std::string path = outputDir + testName + ".jpg";
        return path;
    }

    // Генерация облака слов
    void generateWordCloud(const std::vector<std::string> &input_words,
                           const std::string &outputFile)
    {
        std::vector<Word> words;
        wordStats(input_words, words, IMAGE_WIDTH, IMAGE_HEIGHT);
        imageRenderer(words, outputFile, IMAGE_WIDTH, IMAGE_HEIGHT);
    }

    // Генерирует N уникальных слов
    std::vector<std::string> generateUniqueWords(int count)
    {
        std::vector<std::string> words;
        words.reserve(count);
        for (int i = 0; i < count; ++i) {
            words.push_back("word" + std::to_string(i));
        }
        return words;
    }

    // Генерирует слова с разной частотой (некоторые повторяются)
    std::vector<std::string> generateWordsWithFrequency(int uniqueCount, int maxFrequency)
    {
        std::vector<std::string> words;
        for (int i = 0; i < uniqueCount; ++i) {
            int freq = (i % maxFrequency) + 1;
            for (int j = 0; j < freq; ++j) {
                words.push_back("word" + std::to_string(i));
            }
        }
        return words;
    }
};

//тесты количества слов

TEST_F(WordCloudGeneratorTest, 0_Words)
{
    std::string outputPath = getOutputPath("0_Words");
    std::vector<std::string> words;

    generateWordCloud(words, outputPath);
}

TEST_F(WordCloudGeneratorTest, 1_Word)
{
    std::string outputPath = getOutputPath("1_Word");
    std::vector<std::string> words = {"hello"};

    generateWordCloud(words, outputPath);
}

TEST_F(WordCloudGeneratorTest, 2_Words)
{
    std::string outputPath = getOutputPath("2_Words");
    std::vector<std::string> words = {"hello", "world"};

    generateWordCloud(words, outputPath);
}

TEST_F(WordCloudGeneratorTest, 3_Words)
{
    std::string outputPath = getOutputPath("3_Words");
    std::vector<std::string> words = {"apple", "banana", "cherry"};

    generateWordCloud(words, outputPath);
}

TEST_F(WordCloudGeneratorTest, 5_Words)
{
    std::string outputPath = getOutputPath("5_Words");
    std::vector<std::string> words = {"one", "two", "three", "four", "five"};

    generateWordCloud(words, outputPath);
}

TEST_F(WordCloudGeneratorTest, 10_Words)
{
    std::string outputPath = getOutputPath("10_Words");
    std::vector<std::string> words = generateUniqueWords(10);

    generateWordCloud(words, outputPath);
}

TEST_F(WordCloudGeneratorTest, 20_Words)
{
    std::string outputPath = getOutputPath("20_Words");
    std::vector<std::string> words = generateUniqueWords(20);

    generateWordCloud(words, outputPath);
}

TEST_F(WordCloudGeneratorTest, 30_Words)
{
    std::string outputPath = getOutputPath("30_Words");
    std::vector<std::string> words = generateUniqueWords(30);

    generateWordCloud(words, outputPath);
}

TEST_F(WordCloudGeneratorTest, 50_Words)
{
    std::string outputPath = getOutputPath("50_Words");
    std::vector<std::string> words = generateUniqueWords(50);

    generateWordCloud(words, outputPath);
}

TEST_F(WordCloudGeneratorTest, 75_Words)
{
    std::string outputPath = getOutputPath("75_Words");
    std::vector<std::string> words = generateUniqueWords(75);

    generateWordCloud(words, outputPath);
}

TEST_F(WordCloudGeneratorTest, 100_Words)
{
    std::string outputPath = getOutputPath("100_Words");
    std::vector<std::string> words = generateUniqueWords(100);

    generateWordCloud(words, outputPath);
}

TEST_F(WordCloudGeneratorTest, 150_Words_max)
{
    std::string outputPath = getOutputPath("150_Words_max");
    std::vector<std::string> words = generateUniqueWords(150);

    generateWordCloud(words, outputPath);
}

TEST_F(WordCloudGeneratorTest, 200_Words_Exceeds_Max)
{
    std::string outputPath = getOutputPath("200_Words_Exceeds_Max");
    std::vector<std::string> words = generateUniqueWords(200);

    generateWordCloud(words, outputPath);
}

TEST_F(WordCloudGeneratorTest, 300_Words_Exceeds_Max)
{
    std::string outputPath = getOutputPath("300_Words_Exceeds_Max");
    std::vector<std::string> words = generateUniqueWords(300);

    generateWordCloud(words, outputPath);
}

TEST_F(WordCloudGeneratorTest, 1000_Words_Exceeds_Max)
{
    std::string outputPath = getOutputPath("1000_Words_Exceeds_Max");
    std::vector<std::string> words = generateUniqueWords(1000);

    generateWordCloud(words, outputPath);
}
//долго выполняется
// TEST_F(WordCloudGeneratorTest, 9500_Words_Exceeds_Max)
// {
//     std::string outputPath = getOutputPath("9500_Words_Exceeds_Max");
//     std::vector<std::string> words = generateUniqueWords(9500);

//     generateWordCloud(words, outputPath);
// }
TEST_F(WordCloudGeneratorTest, 9501_Words_Exceeds_Max)
{
    std::string outputPath = getOutputPath("9501_Words_Exceeds_Max");
    std::vector<std::string> words = generateUniqueWords(9501);

    generateWordCloud(words, outputPath);
}

TEST_F(WordCloudGeneratorTest, 10_Words_With_Freq)
{
    std::string outputPath = getOutputPath("10_Words_With_Freq");
    std::vector<std::string> words = generateWordsWithFrequency(10, 5);

    generateWordCloud(words, outputPath);
}

TEST_F(WordCloudGeneratorTest, 50_Words_With_Freq)
{
    std::string outputPath = getOutputPath("50_Words_With_Freq");
    std::vector<std::string> words = generateWordsWithFrequency(50, 10);

    generateWordCloud(words, outputPath);
}

TEST_F(WordCloudGeneratorTest, 100_Words_With_Freq)
{
    std::string outputPath = getOutputPath("100_Words_With_Freq");
    std::vector<std::string> words = generateWordsWithFrequency(100, 20);

    generateWordCloud(words, outputPath);
}

int main(int argc, char **argv)
{
    QGuiApplication app(argc, argv);
    QFontDatabase::addApplicationFont("chrysuni.ttf");

    ::testing::InitGoogleTest(&argc, argv);
    int result = RUN_ALL_TESTS();

    std::cout << "Откройте папку ./test_images/ для просмотра тестовых изображений" << std::endl;

    return result;
}
