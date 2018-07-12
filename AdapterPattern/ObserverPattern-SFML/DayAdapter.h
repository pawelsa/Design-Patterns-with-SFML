#pragma once
//
//
//class DayAdapter {
//
//};
//#pragma once
//#include "ListAdapter.h"
//#include "RectangularWithTextView.h"
//#include "Year.h"
//#include "AdapterListener.h"
//
//
//class CalendarAdapter : public ListAdapter {
//
//	AdapterListener *listener;
//
//	std::list<Year*> *objectList;
//	const int MAX_ITEMS_ON_SCREEN;
//
//	void notifyDataSetHasChanged() {
//
//		if (objectList->size() > viewList.size()) {
//			clearViewList();
//			createViewList_PushBack();
//		}
//	}
//
//	void clearViewList() {
//
//		for (View *view : viewList) {
//			dynamic_cast<RectangularWithTextView*>(view)->removeListener();
//		}
//		viewList.clear();
//	}
//
//	void createViewList_PushBack() {
//
//		std::list<Year*>::iterator objIt = getYearIteratorAtStartWith();
//
//		pushBackNewView(createNewView(Position(1, 1), "Previous", -2));
//
//		for (int i = startWith, j = 1; i < objectList->size() && viewList.size() <= MAX_ITEMS_ON_SCREEN - 2; i++, objIt++, j++) {
//			pushBackNewView(createNewView(Position(j + 1, 1), (*objIt)->getText(), (*objIt)->getYear()));
//		}
//
//		pushBackNewView(createNewView(Position(MAX_ITEMS_ON_SCREEN, 1), "Next", -1));
//	}
//
//	std::list<Year*>::iterator getYearIteratorAtStartWith() {
//
//		std::list<Year*>::iterator objIt = objectList->begin();
//
//		for (int i = 0; i < startWith - 1; i++) {
//			objIt++;
//		}
//		return objIt;
//	}
//
//	RectangularWithTextView *createNewView(Position position, String text, int ID) {
//
//		RectangularWithTextView *view = new RectangularWithTextView(&mouse, position, text, ID);
//		view->attachListener(this);
//		mouse.attach(view);
//		return view;
//	}
//
//	void pushBackNewView(RectangularWithTextView *view) {
//		viewList.push_back(view);
//	}
//
//	bool update(int ID) {
//		std::cout << "Clicked on : " << ID << std::endl;
//
//		if (hasNext(ID)) {
//			startWith++;
//			dynamic_cast<RectangularWithTextView*>(*(++viewList.begin()))->removeListener();
//			viewList.remove(*(++viewList.begin()));
//			notifyDataSetHasChanged();
//			return true;
//		}
//		else if (hasPrevious(ID)) {
//			startWith--;
//			dynamic_cast<RectangularWithTextView*>(*(----viewList.end()))->removeListener();
//			viewList.remove(*(----viewList.end()));
//			notifyDataSetHasChanged();
//			return true;
//		}
//
//		listener->update(ID);
//
//		return false;
//	}
//
//	bool hasNext(int ID) {
//
//		std::list<View*>::iterator vIt = ----viewList.end();
//
//		std::list<Year*>::iterator objIt = --objectList->end();
//
//		return ID == -1 && (*vIt)->getID() != (*objIt)->getYear() - 1;
//	}
//
//	bool hasPrevious(int ID) {
//		std::list<View*>::iterator vIt = viewList.begin();
//
//		std::list<Year*>::iterator objIt = objectList->begin();
//
//		return ID == -2 && (*vIt)->getID() != (*objIt)->getYear() && startWith > 1;
//	}
//
//public:
//
//	CalendarAdapter(AdapterListener *listener, MouseSubject &mouse, sf::RenderWindow *window, std::list<Year*> *objectList = new std::list<Year*>()) :
//		ListAdapter(mouse, window), MAX_ITEMS_ON_SCREEN(DIM::WindowSize.x / DIM::SizeOfItem_Year.x) {
//
//		this->listener = listener;
//		this->objectList = objectList;
//		notifyDataSetHasChanged();
//	}
//
//	void addToList(Year *obj) {
//		this->objectList->push_back(obj);
//		notifyDataSetHasChanged();
//	}
//
//	Year getItem(int position) {
//		std::list<Year*>::iterator it = objectList->begin();
//		for (int i = 0; i <= position; i++) {
//			it++;
//		}
//		return (**it);
//	}
//
//	int getCount() {
//		return objectList->size();
//	}
//
//	bool isEmpty() {
//		return objectList->empty();
//	}
//
//	void mousePressed() {
//		mouse.mousePressed();
//	}
//};
