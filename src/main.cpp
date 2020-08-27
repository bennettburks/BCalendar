#include <iostream>
#include <stdlib.h>
#include "files.hpp"
#include "calendar.hpp"

static bool running = true;

//cycles through user input
void checkInput(std::string input) {
    if (input == "add") {
        addToFile("calendar.dat");
    } else if (input == "list") {
        readEvents("calendar.dat");
    } else if (input == "remove") {
        removeFromFile("calendar.dat");
    } else if (input == "exit") {
        running = false;
    } else {
        std::cout << "<< Invalid input.\n";
    }
}

int main() {
    std::cout << "---------------------------------\n";
    std::cout << "| BCalendar - By: Bennett Burks |\n";
    std::cout << "---------------------------------\n";

    createFile("calendar.dat");

    std::cout << "<< Commands: add, list, remove, exit.\n";

    std::string input;
    while (running) {
        std::cin >> input;
        checkInput(input);
    }
}
