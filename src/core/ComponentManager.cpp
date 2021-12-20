#include "../../includes/core/ComponentManager.hpp"
#include <cassert>

template<typename T>
void ComponentManager::registerComponent() {
	const char* componentName = typeid(T).name();

	assert(componentTypes.find(componentName) == componentTypes.end() && "Component already registered.");

	componentTypes.insert({componentName, nextComponentType});
	componentArrays.insert({componentName, std::make_shared<ComponentArray<T>>()});
	
	nextComponentType++;
}

template<typename T>
ComponentType ComponentManager::getComponentType() {
	const char* componentName = typeid(T).name();

	assert(componentTypes.find(componentName) != componentTypes.end() && "Component not registered.");

	return componentTypes[componentName];
}

template<typename T>
void ComponentManager::addComponent(Entity entity, T component) {
	getComponentArray<T>()->insertData(entity, component);
}

template<typename T>
void ComponentManager::removeComponent(Entity entity) {
	getComponentArray<T>()->removeData(entity);
}

template<typename T>
T& ComponentManager::getComponent(Entity entity) {
	return getComponentArray<T>()->getData(entity);
}

void ComponentManager::entityDestroyed(Entity entity) {
	for(auto const& pair : componentArrays) {
		pair.second->entityDestroyed(entity);
	}
}

template<typename T>
std::shared_ptr<ComponentArray<T>> ComponentManager::getComponentArray() {
	const char* componentName = typeid(T).name();

	assert(componentTypes.find(componentName) != componentTypes.end() && "Component not registered.");

	return std::static_pointer_cast<ComponentArray<T>>(componentArrays[componentName]);
}
