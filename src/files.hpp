#ifndef FILES_HPP
#define FILES_HPP

#include <string>

// Creates a blank file of any type
void createFile(std::string filename);

// Adds user input to specified file
void addToFile(std::string filename);

// Prints entire file's contents in console
void readFile(std::string filename);

// Prints entire file's contents with line numbers in console
int listFile(std::string filename);

// Removes a specified line from a file
void removeFromFile(std::string filename);

#endif