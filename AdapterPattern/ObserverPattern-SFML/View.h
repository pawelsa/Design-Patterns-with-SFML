#pragma once
#include <SFML/Graphics.hpp>

typedef sf::Vector2f Size;
typedef sf::Vector2f Position;
typedef int TextSize;
typedef std::string String;
typedef sf::RectangleShape Rectangle;
typedef sf::Text TextView;

class View {

protected:

	int ID;

public:

	View(int ID) : ID(ID){}

	virtual void display(sf::RenderWindow *window) {}

	virtual int getID() {
		return ID;
	}

};
