//I affirm that all code given below was written solely by me, <give your name>, and that any help I received adhered to the rules stated for this exam.

#include "City.h"
#include "Citizen.h"
#include <string>
#include <vector>
#include <fstream>

using namespace std;

//creates a new city
City::City(string cityName)
{
	_cityName = cityName;
	fstream infile(cityName + ".txt", ios::in);
	int id;
	string firstName, lastName, color;
	if (infile.is_open())
	{
		while (infile >> id >> firstName >> lastName >> color)
		{
			Citizen* c = new Citizen(id, firstName, lastName, color);
			nameOfCitizen.push_back(c);
		}
	}
}

//destructor for the city
//saves the population of the city

//The file is open for output during the destructor and for each citizen
//output the citizen's data to a line of the file and delete the citizen from the vector
City::~City()
{
	fstream outfile(_cityName, ios::out);
	if (outfile.is_open())
	{
		for (int i = 0; i < nameOfCitizen.size(); i++)
		{
			outfile << nameOfCitizen[i]->getId() << " "
					<< nameOfCitizen[i]->getFirstName() << " "
					<< nameOfCitizen[i]->getLastName() << " "
					<< nameOfCitizen[i]->getFavoriteColor() << endl;
			delete nameOfCitizen[i];
		}
	}
	else
	{
		for (int i = 0; i < nameOfCitizen.size(); i++)
		{
			delete nameOfCitizen[i];
		}
	}
}

//Returns the city name
string City::getCityName()
{
	return _cityName;
}

//Returns the number of citizens in this city
int City::populationSize()
{
	return _population;
}

//Returns the citizen at the given index.
Citizen* City::getCitizenAtIndex(int index)
{
	if (index >= 0 && index < nameOfCitizen.size())
	{
		return nameOfCitizen[index];
	}
	return NULL;
}

//Adds a citizen to this city.
void City::addCitizen(Citizen* citizen)
{
	Citizen* citizen = new Citizen(citizen);
	nameOfCitizen.push_back(citizen);
}

//Returns the citizen with the given id.
Citizen* City::getCitizenWithId(int id)
{
	for (int i = 0; i < nameOfCitizen.size(); i++)
	{
		if (nameOfCitizen[i]->getId() == id)
		{
			return nameOfCitizen[i];
		}
	}
	return NULL;
}

//Returns a vector of citizens that all have the given color as their favorite color.
vector<Citizen*>City::getCitizensForFavoriteColor(string color)
{
	for (int i = 0; i < nameOfCitizen.size(); i++)
	{
		nameOfCitizen[i]->getFavoriteColor() = color;
		return vector<Citizen*>();
	}
}
