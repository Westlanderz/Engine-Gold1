#include "../../includes/systems/PhysicsSystem.hpp"
#include "../../includes/components/Transform.hpp"
#include "../../includes/components/Rigidbody.hpp"
#include "../../includes/components/Gravity.hpp"
#include <iostream>

extern Coordinator coordinator;

void PhysicsSystem::Init() {
	coordinator.registerComponent<Rigidbody>();
	coordinator.registerComponent<Gravity>();

	Signature signature;
	signature.set(coordinator.getComponentType<Transform>());
	signature.set(coordinator.getComponentType<Rigidbody>());
	signature.set(coordinator.getComponentType<Gravity>());
	coordinator.setSystemSignature<PhysicsSystem>(signature);
}

void PhysicsSystem::Update(float dt) {
	for(auto const& entity : entities) {
		auto& rigidBody = coordinator.getComponent<Rigidbody>(entity);
		auto& transform = coordinator.getComponent<Transform>(entity);

		// Forces
		auto& gravity = coordinator.getComponent<Gravity>(entity);

		transform.position += rigidBody.velocity * dt;

		rigidBody.velocity += gravity.force * dt;

		std::cout << "The new position of entity " << entity << " is " << transform.position.x << ", " << transform.position.y << ", " << transform.position.z << std::endl;
	}

}
