#pragma once

#include <iostream>
#include <vector>
#include <map>
#include <cassert>

#include "Entity.hpp";

typedef std::vector<std::shared_ptr<Entity>> EntityVec;
typedef std::map<std::string, EntityVec> EntityMap;

class EntityManager {
	EntityVec m_entities;
	EntityMap m_entitiesByTag;
	EntityVec m_toAddEntities;
	EntityVec m_toRemoveEntities;
	size_t m_totalEntities = 0;

public:
	EntityManager() {}

	std::shared_ptr<Entity> addEntity(const std::string& tag) {
		auto entity = std::shared_ptr<Entity>(new Entity(m_totalEntities++, tag));
		m_toAddEntities.push_back(entity);
		return entity;
	}

	void removeEntity(const std::shared_ptr<Entity> e) {
		e->destroy();
		m_toRemoveEntities.push_back(e);
	}

	void update() {
		for (auto& e : m_toAddEntities) {
			m_entities.push_back(e);
			if (m_entitiesByTag.find(e->tag()) != m_entitiesByTag.end()) {
				m_entitiesByTag[e->tag()].push_back(e);
			}
			else {
				EntityVec newEntityVec;
				newEntityVec.push_back(e);
				m_entitiesByTag.insert({e->tag(), std::move(newEntityVec)});
			}
		}

		for (auto& e : m_toRemoveEntities) {
			auto it = std::find(m_entities.begin(), m_entities.end(), e);
			if (it != m_entities.end()) {
				m_entities.erase(it);
			}

			auto mapIt = m_entitiesByTag.find(e->tag());
			if (mapIt != m_entitiesByTag.end()) {
				auto entityVec = m_entitiesByTag[e->tag()];
				auto entityIt = std::find(entityVec.begin(), entityVec.end(), e);
				if (entityIt != entityVec.end()) {
					entityVec.erase(entityIt);
				}
			}
		}

		m_toAddEntities.clear();
		m_toRemoveEntities.clear();
	}

	EntityVec& getEntities() {
		return m_entities;
	}

	EntityVec& getEntities(const std::string& tag) {
		assert(m_entitiesByTag.find(tag) != m_entitiesByTag.end());
		return m_entitiesByTag[tag];
	}
};