#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> addEvent()
{
	std::vector<std::string> event;
	std::string data, date, output = "";

	std::cin.ignore(); //prevents last cin from skipping this next one
	std::cout << "<< What would you like to add?\n";
	std::getline(std::cin, data);
	std::cout << "<< What date?\n"; //TODO: when Qt is implemented, make this part user intuitive
	std::getline(std::cin, date);

	output = data + "<date>" + date;
	event.push_back(output);

	while (1)
	{
		std::cout << "<< Anything else? (If not, type \"no\")\n";
		std::getline(std::cin, data);

		if (data == "no") 
		{
			break;
		}
		else 
		{
			std::cout << "<< What date?\n";
			std::getline(std::cin, date);

			output = data + "<date>" + date;
			event.push_back(output);
		}
	}
	return event;
}