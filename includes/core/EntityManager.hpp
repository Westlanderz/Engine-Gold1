#ifndef ENTITYMANAGER_HPP
#define ENTITYMANAGER_HPP

#include "Types.hpp"
#include <array>
#include <queue>
#include <cassert>

class EntityManager {
	private:
		std::queue<Entity> freeEntities;
		std::array<Signature, MAX_ENTITIES> signatures;
		uint32_t entityCount;

	public:
		EntityManager() {
			entityCount = 0;
			for(Entity entity = 0; entity < MAX_ENTITIES; entity++) {
				freeEntities.push(entity);
			}
		}
		~EntityManager() = default;

		Entity createEntity() {
			assert(entityCount < MAX_ENTITIES && "Maximum number of entities reached.");

			Entity entity = freeEntities.front();
			freeEntities.pop();
			entityCount++;

			return entity;
		}

		void destroyEntity(Entity entity) {
			assert(entity < MAX_ENTITIES && "Entity out of range.");

			signatures[entity].reset();
			freeEntities.push(entity);
			entityCount--;
		}

		void setSignature(Entity entity, Signature signature) {
			assert(entity < MAX_ENTITIES && "Entity out of range.");

			signatures[entity] = signature;
		}

		Signature getSignature(Entity entity) {
			assert(entity < MAX_ENTITIES && "Entity out of range.");

			return signatures[entity];
		}

		uint32_t getEntityCount() {
			return entityCount;
		}
};

#endif // ENTITYMANAGER_HPP
