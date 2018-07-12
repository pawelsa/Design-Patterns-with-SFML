#pragma once
#include "Dimensions.h"
#include "View.h"
#include "MouseSubject.h"
#include "ViewListener.h"

class RectangularWithTextView : public View, public Listener {


	Rectangle object;
	TextView text;
	ViewListener *listener;

	void setupObject(Position pos, Size size) {

		object.setSize(size);
		object.setFillColor(sf::Color::Transparent);
		object.setPosition(pos);
		object.setOutlineColor(sf::Color::Magenta);
		object.setOutlineThickness(DIM::OutlineThickness_Month);
	}

	void setupText(Position pos, Size size, String text) {

		Position textPos = pos + size - Position(15, 15);

		String textToSet = text;

		this->text.setFont(DIM::font);
		this->text.setFillColor(sf::Color::White);
		this->text.setCharacterSize(DIM::TextSize_Month);

		do {
			this->text.setString(textToSet);
			textPos -= Position(this->text.getLocalBounds().width, this->text.getLocalBounds().height);
			this->text.setPosition(textPos);
			textToSet.resize(textToSet.length() - 1);
		} while (this->text.getLocalBounds().width > size.x);
	}

	bool update() {
		
		Position mousePos = getMouse()->getMousePos();
		if (contains(mousePos)) {
			if (listener != NULL)
				if (listener->update(ID)) {
					return true;
				}
		}
		return false;
	}

	bool contains(Position mousePos) {
		return object.getGlobalBounds().contains(mousePos);
	}

public:

	RectangularWithTextView(MouseSubject *mouse, Position position, String text, int ID,  Size size = DIM::SizeOfItem_Month, TextSize textSize = DIM::TextSize_Month ) : Listener(mouse), View(ID) {

		Position pos = (Size) position * DIM::OffestBetweenItems_Month;

		setupObject(pos, size);

		setupText(pos, size, text);
	}

	void attachListener(ViewListener *listener) {
		this->listener = listener;
	}

	void removeListener() {
		listener = NULL;
	}

	void display(sf::RenderWindow *window) {
		window->draw(object);
		window->draw(text);
	}

	~RectangularWithTextView() {
		delete listener;
	}
};