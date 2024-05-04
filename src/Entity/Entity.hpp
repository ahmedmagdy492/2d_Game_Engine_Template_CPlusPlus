#pragma once

#include <iostream>

class Entity {
	friend class EntityManager;

	const size_t m_id = 0;
	const std::string m_tag = "Default";
	bool m_alive = true;
	Entity(const size_t id, const std::string& tag) : m_id(id), m_tag(tag) {}

public:
	
	void destroy() {
		m_alive = false;
	}

	const std::string& tag() {
		return m_tag;
	}
};