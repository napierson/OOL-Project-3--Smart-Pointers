#include "AppliancePtr.h"
#include <string>
#include <iostream>

AppliancePtr* AppliancePtr::inMemory_ = nullptr;

AppliancePtr::AppliancePtr(int i) : ID_(i), myApp_(nullptr)
{
}

AppliancePtr::~AppliancePtr()
{
	writeToFile();
	delete myApp_;
}

Appliance * AppliancePtr::operator->()
{
	if (myApp_ == nullptr)
	{
		releaseMemory();
		myApp_ = loadFromFile();
		inMemory_ = this;
	}

	return myApp_;
}

Appliance & AppliancePtr::operator*()
{
	if (myApp_ == nullptr)
	{
		releaseMemory();
		myApp_ = loadFromFile();
		inMemory_ = this;
	}

	return *myApp_;
}

void AppliancePtr::releaseMemory()
{
	if (inMemory_ != nullptr)
	{
		inMemory_->writeToFile();
		delete inMemory_->myApp_;
		inMemory_->myApp_ = nullptr;
	}
}

Appliance* AppliancePtr::loadFromFile()
{
	releaseMemory();
	inMemory_ = this;

	std::ifstream myFile(myFilepath());
	Appliance* newApp = nullptr;
	
	if (hasFile())  // If the file exists, assume it is complete and read in the values
	{
		int t, p;
		std::string m;
		myFile >> t;
		getline(myFile, m);
		getline(myFile, m);
		myFile >> p;

		newApp = new Appliance(ID_, t, m, p);

		std::string picture;
		getline(myFile, picture);
		while (getline(myFile, picture))
		{
			newApp->addPicture(picture);
		}
	}
	else

	myFile.close();
	return newApp;
}

std::string AppliancePtr::myFilepath()
{
	std::string filepath(".\\appliances\\");
	filepath = filepath + std::to_string(ID_) + ".txt";
	return filepath;
}

void AppliancePtr::writeToFile()
{
	if (myApp_ != nullptr)
	{
		std::remove(myFilepath().c_str());
		std::ofstream myFile(myFilepath());

		if (myFile.is_open())
		{
			myFile << myApp_->appType() << "\n";
			myFile << myApp_->manufacturer() << "\n";
			myFile << myApp_->price() << "\n";
			for (int i = 0; i < myApp_->pictures().size(); i++)
			{
				myFile << myApp_->pictures().at(i) << "\n";
			}
		}

		myFile.close();
	}
}

void AppliancePtr::newAppliance(int t, const std::string & m, int p)
{
	std::remove(myFilepath().c_str());
	delete myApp_;
	releaseMemory();
	myApp_ = new Appliance(ID_, t, m, p);
	writeToFile();
}

bool AppliancePtr::hasFile()
{
	std::ifstream myFile(myFilepath());
	return (myFile.peek() != std::ifstream::traits_type::eof());
}
