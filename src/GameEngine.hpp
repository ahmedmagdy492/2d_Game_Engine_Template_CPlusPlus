#pragma once

#include <SFML/Graphics.hpp>

#include "Entity/EntityManager.hpp";

class GameEngine {
	EntityManager m_entityManager;
	size_t m_currentFrame = 0;
	sf::RenderWindow* m_window;

	void spwanPlayer() {
		if (!m_entityManager.containsTag("player")) {
			auto e = m_entityManager.addEntity("player");
			e->cShape = std::make_shared<CShape>();
			e->cShape->shape = std::make_shared<sf::RectangleShape>(sf::Vector2f{ 50, 50 });
			e->cTransform = std::make_shared<CTransform>(
				sf::Vector2f{ 12, 12 },
				sf::Vector2f{ 0.5, 0.5 },
				45
			);
			e->cShape->shape->setPosition(e->cTransform->position);
		}
	}

	void sUserInput() {
		sf::Event event;
		while (m_window->pollEvent(event)) {
			if (event.type == sf::Event::EventType::Closed)
				m_window->close();
		}
	}

	void sSpwanEntities() {
		spwanPlayer();
	}

	void sMovement() {
		auto entities = m_entityManager.getEntities();

		for (auto& e : entities) {
			if (e->cTransform != nullptr) {
				
			}
		}
	}

	void sCollision() {

	}

	void sRender() {
		m_window->clear();

		auto entities = m_entityManager.getEntities();

		for (auto& entity : entities) {
			if (entity->cShape != nullptr) {
				sf::Shape* shape = entity->cShape->shape.get();
				m_window->draw(*shape);
			}
		}

		m_window->display();
	}

public:
	GameEngine() {
		m_window = new sf::RenderWindow(sf::VideoMode(800, 600), "2d Game Engine Template");
	}

	~GameEngine() {
		delete m_window;
	}

	void mainLoop() {
		while (m_window->isOpen()) {
			m_entityManager.update();
			sUserInput();
			sSpwanEntities();
			sMovement();
			sCollision();
			sRender();
			m_currentFrame++;
		}
	}
};