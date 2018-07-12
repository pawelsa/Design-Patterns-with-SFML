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

	virtual bool update() = 0;

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

	void mousePressed() {
		mousePos = sf::Mouse::getPosition(window);
		notifyObservers();
	}

	sf::Vector2f getMousePos() {
		return (sf::Vector2f) mousePos;
	}

	void notifyObservers() {

		for (int i = 0; i < observers.size(); i++) {
			if (observers.at(i)->update()) {
				return;
			}
		}
	}

};