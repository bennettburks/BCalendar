#include <fstream>
#include <iostream>
#include <string>
#include <vector>

void createFile(std::string filename)
{
	std::ifstream dummyfile(filename); //checks if file exists
	if (!dummyfile)
	{
		std::ofstream file(filename);

		if (!file)
		{
			std::cerr << "Error: file \"" << filename << "\" not created!\n";
			return;
		}

		file.close();
	}
}

void addToFile(std::string filename)
{
	std::ofstream file(filename, std::ios::app);

	if (!file)
	{
		std::cerr << "Error: file \"" << filename << "\" doesn't exist!\n";
		return;
	}

	std::string input;
	std::cin.ignore(); //prevents last cin from skipping this next one
	std::cout << "<< What would you like to add?\n";
	std::getline(std::cin, input);
	file << input << '\n';

	while (1)
	{
		std::cout << "<< Anything else? (If not, type \"no\")\n";
		std::getline(std::cin, input);
		if (input == "no") {
			break;
		}
		else {
			file << input << '\n';
		}
	}

	file.close();
}

void readFile(std::string filename)
{
	std::ifstream file(filename);

	if (!file)
	{
		std::cerr << "Error: file \"" << filename << "\" doesn't exist!\n";
		return;
	}

	std::string output;
	std::cout << "---------------------------------\n";
	while (std::getline(file, output)) //cycles through all lines in file
	{
		std::cout << output << std::endl;
	}
	std::cout << "---------------------------------\n";

	file.close();
}

int listFile(std::string filename)
{
	std::ifstream file(filename);

	if (!file)
	{
		std::cerr << "Error: file \"" << filename << "\" doesn't exist!\n";
		return 0;
	}

	std::string output;
	std::cout << "---------------------------------\n";
	int i = 0;
	while (std::getline(file, output))
	{
		i++;
		std::cout << "(" << i << "): " << output << std::endl;
	}
	std::cout << "---------------------------------\n";

	file.close();
	return i;
}

void removeFromFile(std::string filename)
{
	const int max = listFile(filename);
	int input = 0;

	std::cout << "<< What would you like to remove? (int)\n";
	std::cin >> input;

	if (input > max || input == 0)
	{
		std::cout << "Error: Size is too big.\n";
	}
	else
	{
		//we must read the file to find out what line to delete
		std::ifstream readfile(filename);

		if (!readfile)
		{
			std::cerr << "Error: file \"" << filename << "\" doesn't exist!\n";
			return;
		}
		
		//adjustable vector of all file lines except the one we want to remove
		std::vector<std::string> data;

		std::string output;
		int currentValue = 1;
		while (std::getline(readfile, output))
		{
			if (currentValue != input)
			{
				data.push_back(output);
			}
			currentValue++;
		}
		readfile.close();

		//write the vector to the file
		std::ofstream writefile(filename);

		for (auto i = data.cbegin(); i != data.cend(); i++)
		{
			writefile << *i << '\n';
		}

		std::cout << "<< Object removed successfully!\n";
		writefile.close();
	}
}
