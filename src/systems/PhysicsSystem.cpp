#include "../../includes/systems/PhysicsSystem.hpp"
#include "../../includes/components/Transform.hpp"
#include "../../includes/components/Rigidbody.hpp"
#include "../../includes/core/Coordinator.hpp"

extern Coordinator coordinator;

std::shared_ptr<PhysicsSystem> PhysicsSystem::Init() {
	auto ptr = coordinator.registerSystem<PhysicsSystem>();
	coordinator.registerComponent<Transform>();
	coordinator.registerComponent<Rigidbody>();

	Signature signature;
	signature.set(coordinator.getComponentType<Transform>());
	signature.set(coordinator.getComponentType<Rigidbody>());
	coordinator.setSystemSignature<PhysicsSystem>(signature);

	return ptr;
}

void PhysicsSystem::Update(float dt) {
	for (auto const& entity : entities) {
		auto& rigidBody = coordinator.getComponent<Rigidbody>(entity);
		auto& transform = coordinator.getComponent<Transform>(entity);

		// This formula is obviously wrong, but it's just a test.
		transform.position += (rigidBody.mass * 9.81) * dt * dt;	
	}
}