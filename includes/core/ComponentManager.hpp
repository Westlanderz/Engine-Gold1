#ifndef COMPONENTMANAGER_HPP
#define COMPONENTMANAGER_HPP

#include "ComponentArray.hpp"
#include "Types.hpp"
#include <unordered_map>
#include <memory>
#include <cassert>

class ComponentManager {
	private:
		std::unordered_map<const char*, ComponentType> componentTypes;
		std::unordered_map<const char*, std::shared_ptr<IComponentArray>> componentArrays;
		ComponentType nextComponentType;

		template<typename T>
		std::shared_ptr<ComponentArray<T>> getComponentArray() {
			const char* componentName = typeid(T).name();

			assert(componentTypes.find(componentName) != componentTypes.end() && "Component not registered.");

			return std::static_pointer_cast<ComponentArray<T>>(componentArrays[componentName]);
		}

	public:
		template<typename T>
		void registerComponent() {
			const char* componentName = typeid(T).name();

			assert(componentTypes.find(componentName) == componentTypes.end() && "Component already registered.");

			componentTypes.insert({componentName, nextComponentType});
			componentArrays.insert({componentName, std::make_shared<ComponentArray<T>>()});
			
			nextComponentType++;
		}

		template<typename T>
		ComponentType getComponentType() {
			const char* componentName = typeid(T).name();

			assert(componentTypes.find(componentName) != componentTypes.end() && "Component not registered.");

			return componentTypes[componentName];
		}

		template<typename T>
		void addComponent(Entity entity, T component) {
			getComponentArray<T>()->insertData(entity, component);
		}

		template<typename T>
		void removeComponent(Entity entity) {
			getComponentArray<T>()->removeData(entity);
		}

		template<typename T>
		T& getComponent(Entity entity) {
			return getComponentArray<T>()->getData(entity);
		}

		void entityDestroyed(Entity entity) {
			for(auto const& pair : componentArrays) {
				pair.second->entityDestroyed(entity);
			}
		}
};

#endif // COMPONENTMANAGER_HPP
