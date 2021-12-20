#ifndef SYSTEMMANAGER_HPP
#define SYSTEMMANAGER_HPP

#include "System.hpp"
#include "Types.hpp"
#include <unordered_map>
#include <memory>
#include <cassert>

class SystemManager {
	private:
		std::unordered_map<const char*, Signature> signatures;
		std::unordered_map<const char*, std::shared_ptr<System>> systems;

	public:
		template<typename T>
		std::shared_ptr<T> registerSystem() {
			const char* systemName = typeid(T).name();

			assert(systems.find(systemName) == systems.end() && "System already registered");
			
			auto system = std::make_shared<T>();
			systems.insert({ systemName, system });
			return system;
		}

		template<typename T>
		void setSystemSignature(Signature signature) {
			const char* systemName = typeid(T).name();

			assert(systems.find(systemName) != systems.end() && "System not registered");
			
			signatures.insert({ systemName, signature });
		}
		
		void entityDestroyed(Entity entity) {
			for (auto const& pair : systems) {
				auto const& system = pair.second;
				system->entities.erase(entity);
			}
		}

		void entitySignatureChanged(Entity entity, Signature signature) {
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
};

#endif // SYSTEMMANAGER_HPP
