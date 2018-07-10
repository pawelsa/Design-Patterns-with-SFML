#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>

class MouseSubject;

class Listener {

	MouseSubject *mouse;

public:

	Listener(MouseSubject *_mouse) {
		mouse = _mouse;
	}

	virtual void update() = 0;

protected:

	MouseSubject * getMouse() {
		return mouse;
	}

};

class MouseSubject {

	std::vector<Listener*> observers;
	sf::Vector2i mousePos;
	const sf::RenderWindow &window;

public:

	MouseSubject(const sf::RenderWindow &window_) : window(window_) {}

	void attach(Listener* obs)  {
		observers.push_back(obs);
	}

	void mouseMoved() {
		mousePos = sf::Mouse::getPosition(window);
		notify();
	}

	sf::Vector2f getMousePos() {
		return (sf::Vector2f) mousePos;
	}

	void notify() {

		for (int i = 0; i < observers.size(); i++) {
			observers.at(i)->update();
		}
	}
};