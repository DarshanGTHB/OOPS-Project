// GenTid.cpp

#include "GenTid.h"
#include <cstdlib>
#include <ctime>

std::string GenTid(int length) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    const int charsetSize = sizeof(charset) - 1;
    std::string randomString;

    srand(static_cast<unsigned int>(time(nullptr)));

    for (int i = 0; i < length; ++i) {
        int randomIndex = rand() % charsetSize;
        randomString += charset[randomIndex];
    }

    return randomString;
}
