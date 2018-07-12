#pragma once
#include "Dimensions.h"
#include <string>
#include <list>

extern sf::RenderWindow window;

class Day
{
private:

	//std::vector<Event*> EventList;
	const std::string NameOfDay;
	const int DayNumber;

public:

	Day(int dayNumber) : NameOfDay(DIM::DayNames.at(dayNumber)), DayNumber(dayNumber) { };

	int returnDayNumber() {

		return DayNumber;
	}

	bool escapePressed() {
		return true;
	}

	//bool isAddNewEventPressed(sf::Vector2f mPosition) {

	//	sf::RectangleShape Item;

	//	Item.setSize(DIM::SizeOfButton);
	//	Item.setPosition(DIM::ButtonOffset);

	//	if (Item.getGlobalBounds().contains(mPosition)) {

	//		return true;
	//	}

	//	return false;
	//}
};