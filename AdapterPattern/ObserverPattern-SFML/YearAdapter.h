#pragma once
#include "TableAdapter.h"
#include "AdapterListener.h"

class YearAdapter : public TableAdapter {

	AdapterListener *listener;
	std::list<Month*> *objectList;

	void notifyDataSetHasChanged() {

		if (objectList->size() > viewList.size()) {
			clearViewList();
			createViewList_PushBack();
		}
	}

	void createViewList_PushBack() {

		std::list<Month*>::iterator mIt = objectList->begin();

		for (int y = 1, number=1; y <= 3; y++) {
			for (int x = 1; x <= width && x*y <= 12; x++, number++, mIt++) {
				pushBackNewView(createNewView(Position(x,y), (*mIt)->getMonthName(), number));
			}
		}
	}

	bool update(int ID) {
		std::cout << "YearAdapter - Clicked on : " << ID << std::endl;

		if (ID > 0 && ID < 12) {
			listener->update(ID);

			std::list<Month*>::iterator it = objectList->begin();
			for (it; (*it)->getMonthNumber() != ID; it++);
			listener->updateAdapter((*it)->getAdapter());
			return true;
		}

		return false;
	}



public:

	YearAdapter(sf::RenderWindow *window, MouseSubject mouse, AdapterListener *listener, int width, std::list<Month*> *objectList = new std::list<Month*>()) :
		TableAdapter(mouse, window, width) {
		
		this->listener = listener;
		this->objectList = objectList;
		notifyDataSetHasChanged();
	}

	void addToList(Month *obj) {
		this->objectList->push_back(obj);
		notifyDataSetHasChanged();
	}

	Month getItem(int position) {
		std::list<Month*>::iterator it = objectList->begin();
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