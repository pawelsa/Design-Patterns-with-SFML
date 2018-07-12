#pragma once
#include "Dimensions.h"
#include "Month.h"
#include "YearAdapter.h"


class Year : public AdapterListener {

	const std::string year;
	const int yearI;
	
	YearAdapter *adapter;
	sf::RenderWindow *window;
	std::list<Month*> *monthsList;

	Adapter *currentAdapter;
	Month *currentMonth;

public:

	Year(sf::RenderWindow *window, int year) : year(std::to_string(year)), yearI(year), window(window) {
		
		monthsList = new std::list<Month*>();

		for (int i = 0; i < 12; i++){

			Month *monthToAdd = new Month(window, i, yearI);
			monthsList->push_back(monthToAdd);
		}
		MouseSubject mouse(*window);
		adapter = new YearAdapter(window, mouse, this, 4, monthsList);

		currentAdapter = adapter;
	}

	std::string getText() {
		return year;
	}

	int getYear() {
		return yearI;
	}

	void mousePressed() {
		adapter->mousePressed();
	}

	void display() {
		if (currentMonth != NULL) {
			currentMonth->display();
		}
		else
			currentAdapter->display();
	}

	YearAdapter *getAdapter() {
		return adapter;
	}

	void update(int data) {

		if ((*monthsList->begin())->getMonthNumber() <= data && (*--monthsList->end())->getMonthNumber() >= data) {
			std::cout << "Returned month : " << data << std::endl;

			std::list<Month*>::iterator it;
			for (it = monthsList->begin(); (*it)->getMonthNumber()-1 != data; it++);

			currentAdapter = (*it)->getAdapter();
			currentMonth = (*it);
		}
	}

	void updateAdapter(Adapter *adapter) {
		std::cout << "updateAdapter Y";
		currentAdapter = adapter;
	}

	bool escapePressed() {
		if (adapter != currentAdapter) {
			if (currentMonth->escapePressed()) {
				currentAdapter = adapter;
				currentMonth = NULL;
			return false;
			}
		}
		return true;
	}
};

