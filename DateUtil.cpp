// DateUtil.cpp
#include "DateUtil.h"
#include <chrono>
#include <ctime>
#include <string>

std::string todayDate() {
    auto now = std::chrono::system_clock::now();
    std::time_t time = std::chrono::system_clock::to_time_t(now);
    std::tm* date = std::localtime(&time);

    int year = date->tm_year + 1900;
    int month = date->tm_mon + 1;
    int day = date->tm_mday;

    std::string today = std::to_string(year) + "-" + std::to_string(month) + "-" + std::to_string(day);
    return today;
}
