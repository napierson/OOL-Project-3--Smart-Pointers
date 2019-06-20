#pragma once
#include<string>
#include<vector>
class Appliance
{
public:
	enum Type
	{
		LAUNDRY_MACHINE = 0,
		DISH_WASHER = 1,
		DRYER = 2
	};

	Appliance();
	Appliance(int i, int t, const std::string& m, int p);
	~Appliance();

	int ID();
	int appType();
	std::string& manufacturer();
	int price(); 
	std::vector<std::string>& pictures(); 

	void setPrice(int p);
	void addPicture(const std::string& p);

	std::string displayString();

protected:
	int ID_;
	Type appType_;
	std::string manufacturer_;
	int price_;
	std::vector<std::string> pictures_;
};

