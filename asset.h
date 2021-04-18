#pragma once

//Including the string to use the Library
#include<string>

class asset
{
public:
	//Constructor and Destructor
	
	asset(std::string id);
	~asset();

	//Storing a String Id for the Asset that can be used inside the whole system
	std::string id();

private:
	//Caching that id inside this variable
	std::string _id;

};

