#ifndef COMPONENTARRAY_HPP
#define COMPONENTARRAY_HPP

#include "Types.hpp"
#include <array>
#include <unordered_map>
#include <cassert>

class IComponentArray {
	public:
		virtual ~IComponentArray() = default;
		virtual void entityDestroyed(Entity entity) = 0;
};

template<typename T>
class ComponentArray : public IComponentArray {
	private: 
		std::array<T, MAX_ENTITIES> components;
		std::unordered_map<Entity, size_t> entityToIndex;
		std::unordered_map<size_t, Entity> indexToEntity;
		size_t size;

	public:
		void insertData(Entity entity, T component) {
			assert(entityToIndex.find(entity) == entityToIndex.end() && "Entity already has component.");

			size_t newIndex = size;
			entityToIndex[entity] = newIndex;
			indexToEntity[newIndex] = entity;
			components[newIndex] = component;
			size++;
		}

		void removeData(Entity entity) {
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

		T& getData(Entity entity) {
			assert(entityToIndex.find(entity) != entityToIndex.end() && "Entity does not have component.");

			return components[entityToIndex[entity]];
		}

		void entityDestroyed(Entity entity) override {
			if(entityToIndex.find(entity) != entityToIndex.end()) {
				removeData(entity);
			}
		}
};

#endif // COMPONENTARRAY_HPP
