#include "Appliance.h"



Appliance::Appliance() : ID_(0), appType_(Type(0)), price_(0)
{
}

Appliance::Appliance(int i, int t, const std::string& m, int p) : ID_(i), appType_(Type(t)), manufacturer_(m), price_(p), pictures_()
{
}

Appliance::~Appliance()
{
}

int Appliance::ID(){return ID_; }
int Appliance::appType() { return (int)appType_;  }
std::string& Appliance::manufacturer() { return manufacturer_; }
int Appliance::price() { return price_; }
std::vector<std::string>& Appliance::pictures() { return pictures_; }

void Appliance::setPrice(int p) { price_ = p; }

void Appliance::addPicture(const std::string & p)
{
	pictures_.push_back(p);
}

std::string Appliance::displayString()
{
	std::string output = "ID: ";
	output = output + std::to_string(ID_) + "\n";
	output = output + "Type: ";
	switch (appType_)
	{
	case LAUNDRY_MACHINE:
		output = output + "Laundry machine\n";
		break;
	case DISH_WASHER:
		output = output + "Dish washer\n";
		break;
	case DRYER:
		output = output + "Dryer\n";
		break;
	}
	output = output + "Manufacturer: " + manufacturer_ + "\n";
	int priceDollars = price_ / 100;
	int priceCents = price_ % 100;
	output = output + "Price: " + std::to_string(priceDollars) + " dollars and " + std::to_string(priceCents) + " cents\n";
	output = output + "Pictures:\n";
	for (int i = 0; i < pictures_.size(); i++)
	{
		output = output + pictures_.at(i) + "\n";
	}
	return output;
}
