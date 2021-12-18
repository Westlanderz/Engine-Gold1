#ifndef ENTITYMANAGER_HPP
#define ENTITYMANAGER_HPP

#include "Types.hpp"
#include <array>
#include <queue>

class EntityManager {
	private:
		std::queue<Entity> freeEntities;
		std::array<Signature, MAX_ENTITIES> signatures;
		uint32_t entityCount;

	public:
		EntityManager();
		~EntityManager();

		Entity createEntity();
		void destroyEntity(Entity entity);

		void setSignature(Entity entity, Signature signature);
		Signature getSignature(Entity entity);

		uint32_t getEntityCount();
};

#endif // ENTITYMANAGER_HPP
