#include <iostream>
#include <ctime>

#include "headers.h"

void printArray(int *a, int length) {
    int printed = 0;
    int emptyCnt = (5 - length % 5) % 5;
    std::cout << "+----------------+----------------+----------------+----------------+----------------+" << std::endl;
    while (printed < length) {
        for (int i = 0; i < 5 && printed < length; ++i) {
            std::cout << "|";
            std::cout.width(15);
            std::cout << a[printed] << " ";
            ++printed;
        }
        if (printed != length) {
            std::cout << "|\n+----------------+----------------+----------------+----------------+----------------+" << std::endl;
        }
    }
    for (int i = 0; i < emptyCnt; ++i) {
        std::cout << "|                ";
    }
    std::cout << "|\n+----------------+----------------+----------------+----------------+----------------+" << std::endl;
}

bool inputUser(int (&a)[N], int &cnt) {
    cnt = 0;

    std::cout << "Enter natural number for each element of array, one per row.\nIf you want to stop, enter not a number.\nLast element has index " << N - 1 << std::endl;
    while (cnt < N) {
        std::cout << "[" << cnt << "]: ";
        bool success = bool(std::cin >> a[cnt]);
        std::cin.clear();
        std::cin.sync();
        if (!success) {
            break;
        }

        if (a[cnt] > 0) {
            ++cnt;
        } else {
            std::cout << "Error: non-natural number was inputed. Try again" << std::endl;
        }
    }

    return cnt;
}

void inputRandom(int (&a)[N], int &length) {
    length = 1 + rand() % N;

    for (int i = 0; i < length; ++i) {
        a[i] = rand();
    }
}

void processArray(int *cur, int *last, int *edge, int &length, int n) {
    int* toInsert = cur;
    while (cur <= last) {
        if (isSimple(*cur)) {
            if (last == edge) {
                throw "Out of range";
            }
            for (int i = -1; i < last - cur; ++i) {
                *(last - i) = *(last - i - 1);
            }
            ++cur;
            *cur = n;
            ++last;
            ++length;
        } else {
            toInsert = cur;
        }
        ++cur;
    }
    if (last == edge) {
        throw "Out of range";
    }
    for (int i = -1; i < last - toInsert; ++i) {
        *(last - i) = *(last - i - 1);
    }
    *toInsert = n;
    ++length;
}
