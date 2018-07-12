#pragma once
#include "CalendarAdapter.h"
#include <ctime>

class Calendar : public AdapterListener {

	CalendarAdapter *adapter;
	sf::RenderWindow *window;
	std::list<Year*> *yearList;

	Adapter *currentAdapter;
	Year *currentYear;

public:

	Calendar(sf::RenderWindow *window, int howManyYears, int startYear) : window(window) {

		yearList = new std::list<Year*>();

		for (int i = startYear; i < startYear + howManyYears; i++) {
			yearList->push_back(new Year(window, i));
		}
		MouseSubject mouse(*window);
		adapter = new CalendarAdapter(this, mouse, window, yearList);
		currentAdapter = adapter;
		currentYear = NULL;
	}

	void mousePressed() {
		currentAdapter->mousePressed();
	}

	void display() {
		if (currentYear != NULL)
			currentYear->display();

		currentAdapter->display();
	}

	void escapePressed() {

		if (adapter != currentAdapter) {
			if (currentYear->escapePressed()) {
				currentAdapter = adapter;
				currentYear = NULL;
			}
		}
	}

	void update(int data) {

		if ((*yearList->begin())->getYear() <= data && (*--yearList->end())->getYear() >= data) {
			std::cout << "Returned year : " << data << std::endl;

			std::list<Year*>::iterator it;
			for (it = yearList->begin(); (*it)->getYear() != data; it++);

			currentYear = (*it);
			currentAdapter = (*it)->getAdapter();
		}
	}

	void updateAdapter(Adapter *adapter) {
		std::cout << "updateAdapter Cal";
		currentAdapter = adapter;
	}

};
