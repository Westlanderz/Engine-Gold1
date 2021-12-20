#include "../../includes/core/ComponentArray.hpp"
#include <cassert>

template<typename T>
void ComponentArray<T>::insertData(Entity entity, T component) {
	assert(entityToIndex.find(entity) == entityToIndex.end() && "Entity already has component.");

	size_t newIndex = size;
	entityToIndex[entity] = newIndex;
	indexToEntity[newIndex] = entity;
	components[newIndex] = component;
	size++;
}

template<typename T>
void ComponentArray<T>::removeData(Entity entity) {
	assert(entityToIndex.find(entity) != entityToIndex.end() && "Entity does not have component.");

	size_t indexOfRemovedEntity = entityToIndex[entity];
	size_t lastIndex = size - 1;
	components[indexOfRemovedEntity] = components[lastIndex];

	Entity lastEntity = indexToEntity[lastIndex];
	entityToIndex[lastEntity] = indexOfRemovedEntity;
	indexToEntity[indexOfRemovedEntity] = lastEntity;

	entityToIndex.erase(entity);
	indexToEntity.erase(lastIndex);

	size--;
}

template<typename T>
T& ComponentArray<T>::getData(Entity entity) {
	assert(entityToIndex.find(entity) != entityToIndex.end() && "Entity does not have component.");

	return components[entityToIndex[entity]];
}

template<typename T>
void ComponentArray<T>::entityDestroyed(Entity entity) {
	if(entityToIndex.find(entity) != entityToIndex.end()) {
		removeData(entity);
	}
}
