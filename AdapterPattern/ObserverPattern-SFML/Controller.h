#pragma once
#include "Calendar.h"

class Controller {

	sf::RenderWindow *window;
	Calendar *calendar;

public:

	Controller(sf::RenderWindow *window) : window(window) {

		calendar = new Calendar(this->window, 10, 2017);
	}

	void display() {
		calendar->display();
	}

	void mousePressed() {
		calendar->mousePressed();
	}

	void escapePressed() {
		calendar->escapePressed();
	}

};
