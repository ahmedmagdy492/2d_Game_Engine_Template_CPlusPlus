#pragma once

#include <SFML/Graphics.hpp>

class CTransform {
public:
	sf::Vector2f position;
	sf::Vector2f velocity;
	float angle;

	CTransform(sf::Vector2f position, sf::Vector2f velocity, float angle) :
		position(position), velocity(velocity), angle(angle) {}
};