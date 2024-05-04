#include <SFML/Graphics.hpp>


int main() {
	sf::RenderWindow window(sf::VideoMode(800, 600), "2d Game Engine Template");

	while (window.isOpen()) {
		window.clear();

		// render everything

		window.display();
	}
}