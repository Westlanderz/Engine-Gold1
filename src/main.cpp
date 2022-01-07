#include "../includes/systems/PhysicsSystem.hpp"
#include "../includes/systems/RenderSystem.hpp"
#include "../includes/components/Rigidbody.hpp"
#include "../includes/components/Transform.hpp"
#include "../includes/components/Gravity.hpp"
#include "../includes/components/Renderable.hpp"
#include "../includes/components/Camera.hpp"
#include "../includes/core/Coordinator.hpp"
#include "../includes/WindowManager.hpp"
#include <chrono>
#include <random>

static bool quit = false;
Coordinator coordinator = Coordinator();

void QuitHandler(Event&);

void QuitHandler(Event&) {
	quit = true;
}

int main() {
	coordinator.Init();

	WindowManager windowManager;
	windowManager.Init("ECS, Noah Knegt, 19066066", 1920, 1080, 0, 0);

	coordinator.addEventListener(FUNCTION_LISTENER(Events::Window::QUIT, QuitHandler));

	auto physicsSystem = coordinator.registerSystem<PhysicsSystem>();
	physicsSystem->Init();

	auto renderSystem = coordinator.registerSystem<RenderSystem>();
	renderSystem->Init();

	std::vector<Entity> entities(MAX_ENTITIES - 1);

	std::default_random_engine generator;
	std::uniform_real_distribution<float> randPosition(-100.0f, 100.0f);
	std::uniform_real_distribution<float> randRotation(0.0f, 3.0f);
	std::uniform_real_distribution<float> randScale(3.0f, 5.0f);
	std::uniform_real_distribution<float> randColor(0.0f, 1.0f);
	std::uniform_real_distribution<float> randGravity(-10.0f, -1.0f);

	float scale = randScale(generator);

	for(auto& entity : entities) {
		entity = coordinator.createEntity();
		coordinator.addComponent<Transform>(entity, {
			.position = Vector3(randPosition(generator), randPosition(generator), randPosition(generator)),
			.rotation = Vector3(randRotation(generator), randRotation(generator), randRotation(generator)),
			.scale = Vector3(scale, scale, scale)
		});

		coordinator.addComponent<Gravity>(entity, {
			.force = Vector3(0, randGravity(generator), 0)
		});

		coordinator.addComponent<Rigidbody>(entity, {
			.velocity = Vector3(0.0f, 0.0f, 0.0f),
			.acceleration = Vector3(0.0f, 0.0f, 0.0f)
		});

		coordinator.addComponent<Renderable>(entity, {
			.color = Vector3(0.0f, 0.0f, 0.0f)
		});
	}

	float dt = 0.0f;

	while(!quit) {
		auto startTime = std::chrono::high_resolution_clock::now();

		windowManager.ProcessEvents();
		
		physicsSystem->Update(dt);
		renderSystem->Update(dt);

		windowManager.Update();
		
		auto stopTime = std::chrono::high_resolution_clock::now();
		dt = std::chrono::duration<float, std::chrono::seconds::period>(stopTime - startTime).count();
	}

	windowManager.Shutdown();

	return 0;
}
