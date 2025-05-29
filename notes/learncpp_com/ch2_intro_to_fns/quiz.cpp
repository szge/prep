#include "io.h"

int main() {
    const int num1 { readNumber() };
    const int num2 { readNumber() };
    writeAnswer(num1 + num2);
    return 0;
}