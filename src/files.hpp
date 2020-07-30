#ifndef FILES_HPP
#define FILES_HPP

#include <string>
#include <vector>

// Creates a blank file of any type
void createFile(std::string filename);

// Adds user input to specified file
void addToFile(std::string filename);

// Returns file in vector
std::vector<std::string> readFile(std::string filename);

// Removes a specified line from a file
void removeFromFile(std::string filename);

#endif