#pragma once
#include <list>
#include <SFML/Graphics.hpp>
#include "Adapter.h"
#include "View.h"
#include "ViewListener.h"


class ListAdapter : public Adapter, public ViewListener {

protected:

	sf::RenderWindow *window;
	std::list<View*> viewList;
	int startWith = 1;

public:

	ListAdapter(MouseSubject &mouse, sf::RenderWindow *window) : Adapter(mouse) {
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