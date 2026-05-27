#include "utils.h"
#include <string>
#include <ctime>

std::string getCurrentDate() {
    time_t now = time(nullptr);
    tm* ltm = localtime(&now);
    char buffer[16];
    strftime(buffer, sizeof(buffer), "%d-%m-%Y", ltm);
    return std::string(buffer);
}