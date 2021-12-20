#include "../../includes/core/EntityManager.hpp"
#include <cassert>

EntityManager::EntityManager() {
	entityCount = 0;
	for(Entity entity = 0; entity < MAX_ENTITIES; entity++) {
		freeEntities.push(entity);
	}
}

Entity EntityManager::createEntity() {
	assert(entityCount < MAX_ENTITIES && "Maximum number of entities reached.");

	Entity entity = freeEntities.front();
	freeEntities.pop();
	entityCount++;

	return entity;
}

void EntityManager::destroyEntity(Entity entity) {
	assert(entity < MAX_ENTITIES && "Entity out of range.");

	signatures[entity].reset();
	freeEntities.push(entity);
	entityCount--;
}

void EntityManager::setSignature(Entity entity, Signature signature) {
	assert(entity < MAX_ENTITIES && "Entity out of range.");

	signatures[entity] = signature;
}

Signature EntityManager::getSignature(Entity entity) {
	assert(entity < MAX_ENTITIES && "Entity out of range.");

	return signatures[entity];
}

uint32_t EntityManager::getEntityCount() {
	return entityCount;
}
