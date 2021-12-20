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
		void init();

		Entity createEntity();
		void destroyEntity(Entity entity);

		template<typename T>
		void registerComponent();

		template<typename T>
		void addComponent(Entity entity, T component);

		template<typename T>
		void removeComponent(Entity entity);

		template<typename T>
		T& getComponent(Entity entity);

		template<typename T>
		ComponentType getComponentType();

		template<typename T>
		std::shared_ptr<T> registerSystem();

		template<typename T>
		void setSystemSignature(Signature signature);
};

#endif // COORDINATOR_HPP
