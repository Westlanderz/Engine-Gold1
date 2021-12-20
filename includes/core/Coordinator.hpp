#ifndef COORDINATOR_HPP
#define COORDINATOR_HPP

#include "Types.hpp"
#include "ComponentManager.hpp"
#include "EntityManager.hpp"
#include "SystemManager.hpp"
#include <memory>

class Coordinator {
	private:
		std::unique_ptr<ComponentManager> componentManager;
		std::unique_ptr<EntityManager> entityManager;
		std::unique_ptr<SystemManager> systemManager;

	public:
		Coordinator() {}
		
		void Init() {
			entityManager = std::make_unique<EntityManager>();
			componentManager = std::make_unique<ComponentManager>();
			systemManager = std::make_unique<SystemManager>();
		}

		Entity createEntity() {
			return entityManager->createEntity();
		}

		void destroyEntity(Entity entity) {
			entityManager->destroyEntity(entity);
			componentManager->entityDestroyed(entity);
			systemManager->entityDestroyed(entity);
		}

		template<typename T>
		void registerComponent() {
			componentManager->registerComponent<T>();
		}

		template<typename T>
		void addComponent(Entity entity, T component) {
			componentManager->addComponent<T>(entity, component);

			Signature signature = entityManager->getSignature(entity);
			signature.set(componentManager->getComponentType<T>(), true);
			entityManager->setSignature(entity, signature);

			systemManager->entitySignatureChanged(entity, signature);
		}

		template<typename T>
		void removeComponent(Entity entity) {
			componentManager->removeComponent<T>(entity);

			Signature signature = entityManager->getSignature(entity);
			signature.set(componentManager->getComponentType<T>(), false);
			entityManager->setSignature(entity, signature);

			systemManager->entitySignatureChanged(entity, signature);
		}

		template<typename T>
		T& getComponent(Entity entity) {
			return componentManager->getComponent<T>(entity);
		}

		template<typename T>
		ComponentType getComponentType() {
			return componentManager->getComponentType<T>();
		}

		template<typename T>
		std::shared_ptr<T> registerSystem() {
			return systemManager->registerSystem<T>();
		}

		template<typename T>
		void setSystemSignature(Signature signature) {
			systemManager->setSystemSignature<T>(signature);
		}
};

#endif // COORDINATOR_HPP
