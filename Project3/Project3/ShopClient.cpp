#include "PtrList.h"
#include <iostream>
#include <sstream>


const int MAX_APPS = 10;
PtrList myApps(MAX_APPS);
int currentApp = 0;



void displayApps() 
{
	for (int i = 0; i < MAX_APPS; i++)
	{
		if (myApps.at(i).hasFile())
		{
			std::cout << "\n" << myApps.at(i)->displayString() << "\n";
		}
		else
		{
			std::cout << "There is no appliance with ID " << i << ".\n";
		}
	}
}

void createApp()
{
	int i, t, p;
	std::string m;
	std::cout << "Please provide the following fields:\n";
	std::cout << "ID (0-9): ";
	std::cin >> i; // We don't check the validity of user input for ID, type, etc.
	std::cout << "Type (0 = Laundry machine, 1 = Dish washer, 2 = Dryer): ";
	std::cin >> t;
	std::cout << "Manufacturer: ";
	getline(std::cin, m);
	getline(std::cin, m);
	std::cout << "Price (in cents): ";
	std::cin >> p;
	
	myApps.at(i).newAppliance(t, m, p); // The pointer creates a new Appliance instance with the appropriate values

	std::string fp;
	std::cout << "Enter an image filepath, or 'done' (case-sensitive) to finish data entry:\n";
	getline(std::cin, fp);
	getline(std::cin, fp);
	while (fp != "done")
	{
		myApps.at(i)->addPicture(fp);
		std::cout << "Enter an image filepath, or 'done' (case-sensitive) to finish data entry:\n";
		getline(std::cin, fp);
	}
	
}

int main() 
{
	std::string cmd;
	const std::string QUIT("q");
	const std::string INTS("0123456789");
	while (cmd != QUIT)
	{
		std::cout << "Enter a command: ";
		std::cin >> cmd;
		if (INTS.find(cmd) != std::string::npos)
		{
			std::stringstream(cmd) >> currentApp;
			std::cout << "You're now editing appliance " << currentApp << "\n";
		}
		else if (cmd == "l")
		{
			displayApps();
		}
		else if (cmd == "c")
		{
			createApp();
		}
		else if (cmd == "s")
		{
			for (int i = 0; i < MAX_APPS; i++)
			{
				myApps.at(i).writeToFile();
			}

			std::cout << "Your files were saved.\n";
		}
		else if (cmd == "p")
		{
		
			if (myApps.at(currentApp).hasFile())
			{
				int newPrice;
				std::cout << "Enter the new price: ";
				std::cin >> newPrice;
				myApps.at(currentApp)->setPrice(newPrice);
			}
			else
			{
				std::cout << "No appliance exists with ID " << currentApp << ". Initialize it before editing it.\n";
			}
			
		}
		else if (cmd != QUIT)
		{
			std::cout << "That command is not recognized.\n";
		}
	}
	return 0;
}

