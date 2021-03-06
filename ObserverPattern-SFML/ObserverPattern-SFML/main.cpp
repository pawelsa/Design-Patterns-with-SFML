#include "stdafx.h"
#include "Item.h"


int main()
{
	sf::RenderWindow window(sf::VideoMode(400, 400), "SFML works!");

	MouseSubject mouse(window);
	Item *item[5][5];

	for (int y = 0; y < 5; y++) {
		for (int x = 0; x < 5; x++) {
			item[y][x] = new Item(&mouse, sf::Vector2i(y, x), &window);
			mouse.attach(item[y][x]);
		}
	}

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::MouseMoved) {
				mouse.mouseMoved();
			}
		}

		window.clear();

		for (int y = 0; y < 5; y++) {
			for (int x = 0; x < 5; x++) {
				item[y][x]->display();
			}
		}

		window.display();
	}


    return 0;
}

