#ifndef COORDINATOR_HPP
#define COORDINATOR_HPP

class Coordinator {
	private:
		std::unique_ptr<ComponentManager> componentManager;
		std::unique_ptr<EntityManager> entityManager;
		std::unique_ptr<SystemManager> systemManager;

	public:
		void init();
		void update();
		void destroy();

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
