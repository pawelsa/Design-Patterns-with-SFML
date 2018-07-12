#pragma once
#include "MouseSubject.h"
#include "Dimensions.h"
#include "Day.h"
#include "MonthAdapter.h"
#include <string>

extern sf::RenderWindow window;

class Month : public AdapterListener {

	const std::string Name;
	const int Number;
	const int NumberOfDaysInMonth;
	const int FirstDayOfMonth;
	int year;

	MonthAdapter *adapter;
	std::list<Day*> *daysList;
	sf::RenderWindow *window;

	Adapter *currentAdapter;
	Day *currentDay;

	static int getNumberOfDaysIn(int monthNumber, int year)
	{
		if (monthNumber == 0 || monthNumber == 2 || monthNumber == 4 || monthNumber == 6 || monthNumber == 7 || monthNumber == 9 || monthNumber == 11)
			return 31;
		else if (monthNumber == 1)
		{
			bool leapyear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

			if (leapyear)
				return 29;
			else
				return 28;
		}
		else
			return 30;
	}

	static int getDayNumber(int day, int month, int year)
	{

		static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1,
			4, 6, 2, 4 };
		year -= month < 3;
		return (year + year / 4 - year / 100 +
			year / 400 + t[month - 1] + day) % 7;
	}

public:


	Month(sf::RenderWindow *window, int monthNumber, int year) :Name(DIM::MonthNames.at(monthNumber)), Number(monthNumber), // monthNumber+1??
		NumberOfDaysInMonth(getNumberOfDaysIn(monthNumber, year)), FirstDayOfMonth(getDayNumber(1, monthNumber + 1, year))
	{
		this->year = year;
		int dayOfWeek = FirstDayOfMonth;

		daysList = new std::list<Day*>();

		for (int i = 0; i < NumberOfDaysInMonth; i++, dayOfWeek++)
		{
			if (dayOfWeek == 7) {
				dayOfWeek = 0;
			}
			daysList->push_back(new Day(dayOfWeek));
		}

		MouseSubject mouse(*window);
		adapter = new MonthAdapter(this, mouse, window, daysList);

		currentAdapter = adapter;
	}

	String getMonthName() {
		return Name;
	}

	int getMonthNumber() {
		return Number;
	}

	bool escapePressed() {
		return true;
	}

	int getNumberOfDaysInPreviousMonth() {
		
		if (Number == 0) {
			return getNumberOfDaysIn(11, year-1);
		}
		return getNumberOfDaysIn(Number - 1, year);
	}
	
	void display() {
		currentAdapter->display();
	}

	MonthAdapter *getAdapter() {
		return adapter;
	}

	void update(int data) {

		if ((*daysList->begin())->returnDayNumber() <= data && (*--daysList->end())->returnDayNumber() >= data) {
			std::cout << "Returned day : " << data << std::endl;

			std::list<Day*>::iterator it;
			for (it = daysList->begin(); (*it)->returnDayNumber() != data; it++);

			//currentAdapter = (*it)->getAdapter();
			//currentMonth = (*it);
		}
	}

	void updateAdapter(Adapter *adapter) {
		std::cout << "updateAdapter M";
		currentAdapter = adapter;
	}

/*
	void displayMonth() {


		if (Week != -1) {

			displayWeek();
			return;
		}

		sf::RectangleShape Item;

		Item.setSize(DIM::SizeOfItem_Month);
		Item.setFillColor(sf::Color::Transparent);
		Item.setOutlineThickness(DIM::OutlineThickness_Month);


		sf::Text Text;

		Text.setFont(DIM::font);
		Text.setFillColor(sf::Color::White);
		Text.setCharacterSize(DIM::TextSize_Month);


		for (int i = 0; i < 7; i++) {

			Text.setPosition(DIM::DayNamesOffset + sf::Vector2f(i*DIM::OffestBetweenItems_Month.x, 0));
			Text.setString(DIM::DayNames.at(i));

			window.draw(Text);
		}


		int CountNumberOfDays = 1;

		for (int Y = 0; Y * 7 <= NumberOfDaysInMonth; Y++) {

			for (int X = 0; (X < 7 && CountNumberOfDays <= NumberOfDaysInMonth); X++) {

				Item.setSize(DIM::SizeOfItem_Month);

				if ((X >= FirstDayOfMonth && Y == 0) || Y > 0) {


					if (Days.at(CountNumberOfDays - 1)->HaveAnyEvent()) {

						Item.setFillColor(sf::Color(130, 0, 0));
					}
					else {

						Item.setFillColor(sf::Color::Transparent);
					}


					sf::Vector2f position = sf::Vector2f(DIM::ItemOffset_Month.x + X * (DIM::OffestBetweenItems_Month.x),
						DIM::ItemOffset_Month.y + Y * (DIM::OffestBetweenItems_Month.y));

					Item.setPosition(position);
					Text.setPosition(position + DIM::TextOffset_Month);

					Text.setString(std::to_string(CountNumberOfDays));
					CountNumberOfDays++;

					window.draw(Item);
					Item.setFillColor(sf::Color::Transparent);
					window.draw(Text);
				}
			}

			Item.setSize(sf::Vector2f(DIM::SizeOfItem_Month.x / 2, DIM::SizeOfItem_Month.y));
			Item.setPosition(sf::Vector2f(DIM::ItemOffset_Month.x - DIM::OffestBetweenItems_Month.x / 2, DIM::ItemOffset_Month.y + Y * (DIM::OffestBetweenItems_Month.y)));

			window.draw(Item);

		}


		Item.setSize(DIM::SizeOfButton);
		Item.setOutlineThickness(DIM::OutlineThickness_Button);
		Item.setPosition(DIM::ButtonOffset);
		Item.setFillColor(sf::Color::Transparent);
		Item.setOutlineColor(sf::Color::White);

		Text.setPosition(DIM::ButtonOffset + DIM::TextOffset_Button);
		Text.setFillColor(sf::Color::White);
		Text.setCharacterSize(DIM::TextSize_Calendar);
		Text.setString("Add Event");

		window.draw(Item);
		window.draw(Text);


	}


	Day* doTheyIntersect_Month(sf::Vector2f mPosition) {

		if (Week != -1) {

			return doTheyIntersect_Week(mPosition);
		}

		sf::RectangleShape Item;

		Item.setSize(DIM::SizeOfItem_Month);

		int CountNumberOfDays = 1;


		for (int Y = 0; Y * 7 <= NumberOfDaysInMonth; Y++) {

			for (int X = 0; (X < 7 && CountNumberOfDays <= NumberOfDaysInMonth); X++) {

				if ((X >= FirstDayOfMonth && Y == 0) || Y > 0) {

					Item.setSize(DIM::SizeOfItem_Month);

					sf::Vector2f position = sf::Vector2f(DIM::ItemOffset_Month.x + X * (DIM::OffestBetweenItems_Month.x),
						DIM::ItemOffset_Month.y + Y * (DIM::OffestBetweenItems_Month.y));

					Item.setPosition(position);

					if (Item.getGlobalBounds().contains(mPosition)) {

						return Days.at(CountNumberOfDays - 1);
					}

					CountNumberOfDays++;
				}
			}

			Item.setSize(sf::Vector2f(DIM::SizeOfItem_Month.x / 2, DIM::SizeOfItem_Month.y));
			Item.setPosition(sf::Vector2f(DIM::ItemOffset_Month.x - DIM::OffestBetweenItems_Month.x / 2, DIM::ItemOffset_Month.y + Y * (DIM::OffestBetweenItems_Month.y)));

			if (Item.getGlobalBounds().contains(mPosition)) {

				Week = Y;
				return NULL;
			}
		}

		return NULL;
	}*/


	/*bool isAddNewEventPressed(sf::Vector2f mPosition) {

		sf::RectangleShape Item;

		Item.setSize(DIM::SizeOfButton);
		Item.setPosition(DIM::ButtonOffset);

		if (Item.getGlobalBounds().contains(mPosition)) {

			return true;
		}

		return false;
	}

	bool moveBack() {

		if (Week == -1) {

			return true;
		}
		else {

			Week = -1;
			return false;
		}
	}*/

	~Month() {};

};