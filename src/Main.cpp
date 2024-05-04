#include <SFML/Graphics.hpp>

#include "Entity/EntityManager.hpp";

int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "2d Game Engine Template");

	while (window.isOpen()) {

		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::EventType::Closed)
				window.close();
		}

		window.clear();

		// render everything

		window.display();
	}
}