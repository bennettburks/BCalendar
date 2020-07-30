#ifndef CALENDAR_HPP
#define CALENDAR_HPP

#include <string>
#include <vector>

// Handles user input for adding events
std::vector<std::string> addEvent();

// Prints entire file's contents in console
void readEvents(std::string filename);

// Prints entire file's contents with line numbers in console
// Returns number of lines in file
int listEvents(std::string filename);

#endif