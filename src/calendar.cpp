#include <iostream>
#include <string>
#include <vector>

#include "files.hpp"

std::string getInput();
std::string parseDate();

std::vector<std::string> addEvent() {
    std::vector<std::string> event;
    std::string output;

    std::cout << "<< What would you like to add?\n";
    output = getInput();
    event.push_back(output);

    //date information
    output = parseDate();
    event.push_back(output);

    while (true) {
        std::cout << "<< Anything else? (If not, type \"no\")\n";
        output = getInput();

        if (output == "no") {
            break;
        } else {
            event.push_back(output);
            output = parseDate();
            event.push_back(output);
        }
    }
    return event;
}

void readEvents(std::string filename) {
    std::vector<std::string> event = readFile(filename);

    std::cout << "---------------------------------\n";
    for (auto i = event.cbegin(); i != event.cend(); i++) {
        std::string body = *i;
        i++;
        std::string date = *i;
        std::cout << body << " - " << date << "\n";

    }
    std::cout << "---------------------------------\n";
}

int listEvents(std::string filename) {
    std::vector<std::string> event = readFile(filename);

    std::cout << "---------------------------------\n";
    int counter = 0;
    for (auto i = event.cbegin(); i != event.cend(); i++) {
        std::string body = *i;
        i++;
        std::string date = *i;
        counter++;
        std::cout << "(" << counter << "): " << body << " - " << date << "\n";
    }
    std::cout << "---------------------------------\n";
    return counter;
}

std::string parseDate() {
    int date;
    std::string output;

    //gets data
    while (true) {
        std::cout << "<< What date? (mmdd)\n"; //TODO: when Qt is implemented, make this part user intuitive
        std::cin >> output;
        try {
            date = std::stoi(output);
        } catch (std::invalid_argument) {
            date = 0; //null number
        }
        if (date <= 1231 && date >= 0101 && (date % 100) >= 1 && (date % 100) <= 31) {
            break;
        } else {
            std::cout << "Invalid date. Please try again. " << date << "\n";
        }
    }

    //converts date
    //TODO: check current year
    int month = date/100;
    int day = date%100;
    output = std::to_string(month) + "-" + std::to_string(day) + "-" + "2020";
    return output;
}

std::string getInput() {
    std::string output;
    std::cin.clear();
    std::cin.ignore(9999, '\n');
    std::getline(std::cin, output);
    return output;
}




