#ifndef COMPONENTMANAGER_HPP
#define COMPONENTMANAGER_HPP

#include "ComponentArray.hpp"
#include "Types.hpp"
#include <unordered_map>
#include <memory>

class ComponentManager {
	private:
		std::unordered_map<const char*, ComponentType> componentTypes;
		std::unordered_map<const char*, std::shared_ptr<IComponentArray>> componentArrays;
		ComponentType nextComponentType;

		template<typename T>
		std::shared_ptr<ComponentArray<T>> getComponentArray();

	public:
		template<typename T>
		ComponentType registerComponent();

		template<typename T>
		ComponentType getComponentType();

		template<typename T>
		void addComponent(Entity entity, T component);

		template<typename T>
		void removeComponent(Entity entity);

		template<typename T>
		T& getComponent(Entity entity);

		void entityDestroyed(Entity entity);
};

#endif // COMPONENTMANAGER_HPP
