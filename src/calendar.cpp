#include <iostream>
#include <string>
#include <vector>
#include <sstream>

#include "files.hpp"

std::string getInput();
std::string parseDate();
std::string formatDate(int date);

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
        int date = std::stoi(*i);
        std::string dateOutput = formatDate(date);
        std::cout << body << " - " << dateOutput << "\n";

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
        int date = std::stoi(*i);
        std::string dateOutput = formatDate(date);
        counter++;
        std::cout << "(" << counter << "): " << body << " - " << dateOutput << "\n";
    }
    std::cout << "---------------------------------\n";
    return counter;
}

std::string parseDate() {
    int date;
    std::string output; //TODO: allow for user to put "today" and other keywords to shorten date

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
    int year = 2020;
    date = (year*10000) + date;

    output = std::to_string(date);
    std::cout << output << '\n';
    return output;
}

std::string formatDate(int date) {
    int year = date / 10000;
    int month = (date % 10000) / 100;
    int day = date % 100;

    std::ostringstream output;
    output << month << "/" << day << "/" << year;

    return output.str();
}

std::string getInput() {
    std::string output;
    std::cin.clear();
    std::cin.ignore(9999, '\n');
    std::getline(std::cin, output);
    return output;
}




