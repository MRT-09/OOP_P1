#include "utils.h"
#include <string>
#include <ctime>
using namespace std;

string getCurrentDate() {
    time_t now = time(nullptr);
    tm* ltm = localtime(&now);
    char buffer[16];
    strftime(buffer, sizeof(buffer), "%d-%m-%Y", ltm);
    return string(buffer);
}

string getCurrentDateTime() {
    time_t now = time(nullptr);
    tm* ltm = localtime(&now);
    char buffer[32];
    strftime(buffer, sizeof(buffer), "%d-%m-%Y_%H-%M-%S", ltm);
    return string(buffer);
}