#include "headers.h"
#include <iostream>
#include <cstdlib>
#include <chrono>
#include <cmath>

int main()
{
    int option = 1;
    int arr[N] = {};
    srand(std::chrono::time_point_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now()).time_since_epoch().count());

    printHeader();
    while (true) {
        bool shouldPrint = true;
        int length = 0;
        option = getOption();

        if (option == 1) {
            inputRandom(arr, length);
        } else if (option == 2) {
            shouldPrint = inputUser(arr, length);
        } else {
            break;
        }

        if (!shouldPrint) {
            continue;
        }

        std::cout << "\nArray:\n" << std::endl;
        printArray(arr, length);
        std::cout << std::endl;

        int number = 0;
        while (true) {
            std::cout << "Enter whole number for processing the array: ";
            if (std::cin >> number) {
                std::cin.sync();
                break;
            } else {
                std::cin.clear();
                std::cin.sync();
                std::cout << "Invalid input. Try again." << std::endl;
            }
        }

        try {
           processArray(arr, arr + length - 1, arr + N - 1, length, number);
        } catch (...) {
            std::cout << "RANGE CHECK ERROR" << std::endl;
        }

        std::cout << "\nProcessed array:\n" << std::endl;
        printArray(arr, length);
    }

    return 0;
}



int getOption() {
    std::cout << "\nOptions:\n1 -> Random input\n2 -> Keyboard input\nAny other number -> Exit\n\nEnter a number" << std::endl;
    int option = 0;
    while (true) {
            std::cout << "Input: ";
        if (std::cin >> option) {
            return option;
        } else {
            std::cout << "Error: not a number inputed, try again\n";
            std::cin.clear();
            std::cin.sync();
        }
    }
}
void printHeader() {
        std::cout << "Project: Array input" << std::endl;
        std::cout << "Vasylenko Zlata K-14" << std::endl;
}

bool isSimple(int n) {
    int edge = sqrt(n) + 1;
    for (int i = 2; i < edge; ++i) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}
