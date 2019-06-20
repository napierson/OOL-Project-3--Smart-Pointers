#pragma once
#include "Appliance.h"
#include <fstream>

class AppliancePtr
{
public:

	AppliancePtr(int i);
	~AppliancePtr();

	Appliance* operator->();
	Appliance& operator*();

	void writeToFile();
	void newAppliance(int t, const std::string& m, int p);

	bool hasFile();

protected:
	
	int ID_;
	Appliance* myApp_;

	static AppliancePtr* inMemory_;
	static void releaseMemory();

	Appliance* loadFromFile();
	std::string myFilepath();

	AppliancePtr(const AppliancePtr& ap);
	AppliancePtr& operator=(const AppliancePtr& ap);
};

