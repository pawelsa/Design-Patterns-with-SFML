#pragma once
#include "MouseSubject.h"


class Item : public Listener {

	sf::RectangleShape rectangular;
	static const sf::Vector2i size;
	sf::RenderWindow *window;

public:

	Item(MouseSubject *mouse, sf::Vector2i position_, sf::RenderWindow *window) : Listener(mouse) , window(window) {
		
		sf::Vector2f position = (sf::Vector2f) position_ * (sf::Vector2f)size + sf::Vector2f(10,10) * (sf::Vector2f) position_;
		rectangular.setSize((sf::Vector2f) size);
		rectangular.setPosition(position);
		rectangular.setOutlineColor(sf::Color::Red);
	}

	void update() {

		sf::Vector2f mousePos = getMouse()->getMousePos();
		if (contains(mousePos)) {
			rectangular.setOutlineThickness(5);
		}
		else {
			rectangular.setOutlineThickness(0);
		}

	}

	bool contains(sf::Vector2f mousePos) {
		return rectangular.getGlobalBounds().contains(mousePos);
	}

	void display() {
		window->draw(rectangular);
	}
};

const sf::Vector2i Item::size = sf::Vector2i(30, 30);
