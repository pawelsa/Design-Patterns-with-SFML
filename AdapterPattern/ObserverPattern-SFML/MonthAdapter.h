#pragma once
#include "TableAdapter.h"
#include "RectangularWithTextView.h"
#include "Month.h"
#include "AdapterListener.h"


class MonthAdapter : public TableAdapter {

	AdapterListener *listener;
	std::list<Day*> *objectList;

	void notifyDataSetHasChanged() {

		if (objectList->size() > viewList.size()) {
			clearViewList();
			createViewList_PushBack();
		}
	}

	void createViewList_PushBack() {

		std::list<Day*>::iterator mIt = objectList->begin();

		int startDay = (*mIt)->returnDayNumber();
		
		for (int countDays = 1, newLine = 1; countDays <= objectList->size(); newLine++) {
			for (int weekDay = 1; weekDay <= 7 && countDays <= objectList->size(); weekDay++, countDays++, mIt++) {
				pushBackNewView(createNewView(Position(weekDay, newLine), std::to_string(countDays), countDays));
			}
		}
	}

	bool update(int ID) {
		std::cout << "Clicked on : " << ID << std::endl;


		listener->update(ID);
/*
		std::list<Day*>::iterator it = objectList->begin();
		for (it; (*it)->returnDayNumber() != ID; it++);
		listener->updateAdapter((*it)->getAdapter());*/

		return false;
	}

public:

	MonthAdapter(AdapterListener *listener, MouseSubject &mouse, sf::RenderWindow *window, std::list<Day*> *objectList = new std::list<Day*>()) :
		TableAdapter(mouse, window, 7) {

		this->listener = listener;
		this->objectList = objectList;
		notifyDataSetHasChanged();
	}

	void addToList(Day *obj) {
		this->objectList->push_back(obj);
		notifyDataSetHasChanged();
	}

	Day getItem(int position) {
		std::list<Day*>::iterator it = objectList->begin();
		for (int i = 0; i <= position; i++) {
			it++;
		}
		return (**it);
	}

	int getCount() {
		return objectList->size();
	}

	bool isEmpty() {
		return objectList->empty();
	}

	void mousePressed() {
		mouse.mousePressed();
	}
};
