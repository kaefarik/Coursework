# Word Cloud Generator

Кроссплатформенное приложение для генерации облаков слов с использованием Qt и CMake.

Требования:

Установите CMake 3.19 или выше https://cmake.org/download/

Установите Qt 6 или выше https://www.qt.io/development/download

C++17 компилятор

# Сборка для Windows
# Вариант 1
# Clang (LLVM-MinGW)

*cmd*

**Создайте папку сборки**

`mkdir build
cd build`

**Конфигурация с явным указанием путей**

`cmake -G "MinGW Makefiles" ^
    -DCMAKE_PREFIX_PATH="C:/Qt/6.9.3/llvm-mingw_64" ^
    -DCMAKE_C_COMPILER="clang" ^
    -DCMAKE_CXX_COMPILER="clang++" ^
    -DCMAKE_MAKE_PROGRAM="C:/msys64/mingw64/bin/mingw32-make.exe" ^
    ..`

**Сборка проекта**

`cmake --build .`


# Вариант 2
# MinGW (MSYS2)

*cmd*

**Создайте папку сборки**

`mkdir build
cd build`

**Конфигурация с явным указанием путей**

`cmake -G "MinGW Makefiles" ^
    -DCMAKE_PREFIX_PATH="C:/Qt/6.9.3/mingw_64" ^
    -DCMAKE_C_COMPILER="gcc" ^
    -DCMAKE_CXX_COMPILER="g++" ^
    -DCMAKE_MAKE_PROGRAM="C:/msys64/mingw64/bin/mingw32-make.exe" ^
    ..`

**Сборка проекта**

`cmake --build .`


# Сборка для Linux

*bash*

**Установите зависимости (Ubuntu/Debian)**

`sudo apt-get update`

`sudo apt-get install -y build-essential cmake qt6-base-dev qt6-tools-dev libgl1-mesa-dev clang`

**Скопируйте репозиторий**

`git clone https://github.com/kaefarik/Coursework`

`cd Coursework`

**Сборка**

`mkdir build && cd build`

`cmake ..`

`cmake --build .`

# Запуск проекта через терминал

**Текстовый файл words.txt должен находиться в папке build**

**Синтаксис команды запуска**

Coursework.exe(если Windows)/Coursework(Linux)

`Coursework.exe <out.jpg> <words.txt> <слово1> [слово2] [слово3] ...`

**или**

`Coursework.exe <out.jpg> <слово1> [слово2] [слово3] ...`

# Примеры использования

**Вариант 1: С текстовым файлом**

`Coursework.exe output.jpg words.txt`

**Вариант 2: С текстовым файлом и дополнительными словами**

`Coursework.exe cloud.jpg words.txt c++ c++ lol word`

**Вариант 3: Без текстового файла**

`Coursework.exe cloud.jpg example c++ c++ lol java word`

# Формат текстового файла

**Текстовый файл должен содержать слова, разделенные пробелами или переносами строк**

**Пример words.txt:**

hello wordls word1 word2 word3

cloud word art c++ hello c++ 

image c++ cloud word

# Требования к аргументам

**Первый аргумент: Выходной файл**

**Обязательно должен иметь расширение .jpg**

**Второй аргумент:**

**Либо текстовый файл с расширением .txt**

**Либо первое слово для облака**

**Остальные аргументы (опционально):**

**Дополнительные слова для включения в облако**

**Каждое слово должно быть отдельным аргументом**

# Полный процесс работы

**Создайте файл words.txt с вашими словами.**

**Шаг 1: Сборка проекта**

**Следуйте инструкциям в README.md для сборки проекта.**

**Шаг 2: Подготовка текстового файла (если нужно)**

**Шаг 3: Запуск программы**

# Если хотите увидеть примеры — в директории build введите в консоль:

`CourseworkTests.exe`

или

`./CourseworkTest`

затем откройте папку build/test_images
