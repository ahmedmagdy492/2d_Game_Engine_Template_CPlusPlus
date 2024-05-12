#pragma once

#include <iostream>

#include "../Components/CName.h";
#include "../Components/CBBox.h";
#include "../Components/CShape.h";
#include "../Components/CTransform.h";

class Entity {
	friend class EntityManager;

	const size_t m_id = 0;
	const std::string m_tag = "Default";
	bool m_alive = true;
	Entity(const size_t id, const std::string& tag) : m_id(id), m_tag(tag) {}

public:

	std::shared_ptr<CName> cName = nullptr;
	std::shared_ptr<CTransform> cTransform = nullptr;
	std::shared_ptr<CShape> cShape = nullptr;
	std::shared_ptr<CBBox> cBBOX = nullptr;
	
	void destroy() {
		m_alive = false;
	}

	const std::string& tag() {
		return m_tag;
	}
};