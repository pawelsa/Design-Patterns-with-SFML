#pragma once
#include <list>
#include <SFML/Graphics.hpp>
#include "Adapter.h"
#include "View.h"
#include "ViewListener.h"

class TableAdapter :public Adapter, public ViewListener {

protected:

	sf::RenderWindow *window;
	std::list<View*> viewList;
	//int startWith = 1;
	const int width;



	void clearViewList() {

		for (View *view : viewList) {
			dynamic_cast<RectangularWithTextView*>(view)->removeListener();
		}
		viewList.clear();
	}

	RectangularWithTextView *createNewView(Position position, String text, int ID) {

		RectangularWithTextView *view = new RectangularWithTextView(&mouse, position, text, ID);
		view->attachListener(this);
		mouse.attach(view);
		return view;
	}

	void pushBackNewView(RectangularWithTextView *view) {
		viewList.push_back(view);
	}

public:

	TableAdapter(MouseSubject mouse, sf::RenderWindow *window, int width) : Adapter(mouse), width(width) {
		this->window = window;
	}

	virtual void display() {
		if (!viewList.empty())
			for (View *view : viewList) {
				view->display(window);
			}
	}

	virtual void notifyDataSetHasChanged() = 0;

};