#include "../includes/systems/PhysicsSystem.hpp"
#include "../includes/components/Rigidbody.hpp"
#include "../includes/components/Transform.hpp"
#include "../includes/components/Gravity.hpp"
#include "../includes/core/Coordinator.hpp"
#include <chrono>
#include <vector>
#include <iostream>

static bool quit = false;
Coordinator coordinator = Coordinator();

int main() {
	coordinator.Init();

	auto physicsSystem = coordinator.registerSystem<PhysicsSystem>();
	physicsSystem->Init();

	std::vector<Entity> entities(MAX_ENTITIES - 1);

	for(auto& entity : entities) {
		entity = coordinator.createEntity();
		coordinator.addComponent<Transform>(entity, {
			.position = Vector3(),
			.rotation = Vector3(),
			.scale = Vector3(1, 1, 1)
		});

		coordinator.addComponent<Rigidbody>(entity, {
			.velocity = Vector3(),
			.acceleration = Vector3()
		});

		coordinator.addComponent<Gravity>(entity, {
			.force = Vector3(0, (float)-9.81, 0)
		});
	}

	float dt = 0.0f;

	while(!quit) {
		auto startTime = std::chrono::high_resolution_clock::now();
		
		physicsSystem->Update(dt);
		
		auto stopTime = std::chrono::high_resolution_clock::now();
		dt = std::chrono::duration<float, std::chrono::seconds::period>(stopTime - startTime).count();
	}
	return 0;
}
