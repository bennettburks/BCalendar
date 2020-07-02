#include <fstream>
#include <iostream>

void createFile(std::string filename)
{
    std::ofstream file("resources/" + filename);

    if(!file)
    {
        std::cerr << "Error: file \"" << filename << "\" not created!\n";
        return;
    } 

    file.close();
}

void addToFile(std::string filename)
{
    std::ofstream file("resources/" + filename);

    if(!file)
    {
        std::cerr << "Error: file \"" << filename << "\" not created!\n";
        return;
    } 

    std::string input = "";
    std::cout << "<< What would you like to add?\n";
    std::cin.ignore(); //pressing enter in main function registers as cin, this ignores it
    std::getline(std::cin, input);
    file << input;

    while(1)
    {
        std::cout << "<< Anything else? (If not, type \"no\")\n";
        std::getline(std::cin, input);
        if(input == "no") {
            break;
        } else {
            file << "\n" << input;
        }
    }

    file.close();
}

void readFile(std::string filename)
{
    std::ifstream file("resources/" + filename);

    if(!file)
    {
        std::cerr << "Error: file \"" << filename << "\" doesn't exist!\n";
        return;
    }

    std::string output;
    std::cout << "---------------------------------\n";
    while(getline(file, output)) //while the file still has lines to output
    {
        std::cout << output << std::endl;
    }
    std::cout << "---------------------------------\n";

    file.close();
}
