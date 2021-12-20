#include "../../includes/core/SystemManager.hpp"
#include <cassert>

template<typename T>
std::shared_ptr<T> SystemManager::registerSystem() {
	const char* systemName = typeid(T).name();

	assert(systems.find(systemName) == systems.end() && "System already registered");
	
	auto system = std::make_shared<T>();
	systems.insert({ systemName, system });
	return system;
}

template<typename T>
void SystemManager::setSignature(Signature signature) {
	const char* systemName = typeid(T).name();

	assert(systems.find(systemName) != systems.end() && "System not registered");
	
	signatures.insert({ systemName, signature });
}

void SystemManager::entityDestroyed(Entity entity) {
	for (auto const& pair : systems) {
		auto const& system = pair.second;
		system->entities.erase(entity);
	}
}

void SystemManager::entitySignatureChanged(Entity entity, Signature signature) {
	for (auto const& pair : systems) {
		auto const& systemName = pair.first;
		auto const& system = pair.second;
		auto const& systemSignature = signatures.at(systemName);

		if((signature & systemSignature) == systemSignature) {
			system->entities.insert(entity);
		} else {
			system->entities.erase(entity);
		}
	}
}
