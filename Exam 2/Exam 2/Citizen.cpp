//I affirm that all code given below was written solely by me, <give your name>, and that any help I received adhered to the rules stated for this exam.

#include "Citizen.h"
#include <string>
#include <vector>

using namespace std;

//Creates a new Citizen object with the passed in id, name, and favorite color
Citizen::Citizen(int id, string firstName, string lastName, string color)
{
	_id = id;
	_firstName = firstName;
	_lastName = lastName;
	_color = color;
}

//Creates a new Citizen object by copying data from the passed in citizen
Citizen::Citizen(Citizen* citizen)
{
	if (citizen != NULL)
	{
		_id = citizen->getId();
		_firstName = citizen->getFirstName();
		_lastName = citizen->getLastName();
		_color = citizen->getFavoriteColor();
	}
}

//Returns the first name of this citizen
string Citizen::getFirstName()
{
	return _firstName;
}

//Returns the last name of this citizen
string Citizen::getLastName()
{
	return _lastName;
}

//Returns the id for this citizen
int Citizen::getId()
{
	return _id;
}

//Returns the favorite color for this citizen
string Citizen::getFavoriteColor()
{
	return _color;
}

//Sets the favorite color for this citizen
void Citizen::setFavoriteColor(string color)
{
	_color = color;
}